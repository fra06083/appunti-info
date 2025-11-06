tracer: strumento che cattura le system call fatte dagli utenti

provare, se funzione con le altre architetture, il mitico test fatto dal prof. 

ricorda che "gli angeli custodi" come li chiama il prof, si occupano di aiutare con la gestione delle system call fatte dai processi utente.

---

### 2 Famiglie di sistemi di tracciamento
- **Hypervisor**: Elemento organizzato da processo X viene gestito da processo y
- **Sistemi di auto virtualizzazione**: quando avviene una system call, viene chiamata una funzione dello stesso processo
la libreria C ha tre tipi di funzioni:
1. funzione di **pura utilità** (e.g. `strlen`)
2. funzioni che fanno da **interfaccia** per le system call (e.g. `open(), read(), write()`)
3. funzioni che **richiamano SYSCALL** (e.g printf fa l'elaborazione della stringa e poi chiama la DOIO)
<small>la pure-lib-c da solo funzioni di "comodità", o di supporto per le system call</small>

> [!Warning] La libreria C NON permette di cambiare la direzione alle funzioni per le syscall, quindi questo spiega la creazione di una libreria per farlo.

```c
fun _pure_start(sfun pure_syscall,int flags);
```

una volta chiamata questa funzione, tutte le syscall verranno indirizzate ad essa


libreria di overlay: concetto simile al funzionamento dell'overriding. 

libreria pura: 
* data una certa api (si ha un certo linguaggio), si crea un'api di livello superiore


ESEMPIO uso purelibc:

```c
/* This is educational code.
	 If you use it, please attribute it to:
		 Virtual Square wiki.virtualsquare.org */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <purelibc.h>

char *hostname = "/etc/hostname";

static sfun _native_syscall;

//static char buf[128];
static long int mysc(long int sysno, ...){
	va_list ap;
	long int a1,a2,a3,a4,a5,a6; // lunghi una parola, 6 registri.
	va_start (ap, sysno);
	//snprintf(buf,128,"SC=%d\n",sysno);
	//_native_syscall(__NR_write,2,buf,strlen(buf));
	a1=va_arg(ap,long int);
	a2=va_arg(ap,long int);
	a3=va_arg(ap,long int);
	a4=va_arg(ap,long int);
	a5=va_arg(ap,long int);
	a6=va_arg(ap,long int);
	va_end(ap);
	if (sysno == __NR_openat &&
			strcmp((char *) a2, "/etc/passwd") == 0) // è virtualizzazione, fai diventare hostname
		a2 = (uintptr_t) hostname;
	if (sysno == __NR_open &&
			strcmp((char *) a1, "/etc/passwd") == 0)
		/* Se è open fallo diventare hostname */
		a1 = (uintptr_t) hostname;
	return _native_syscall(sysno,a1,a2,a3,a4,a5,a6);
}

void mycat(char *path) {
  int fd = open(path, O_RDONLY);
  char buf[1024];
  int n;
  while ((n = read(fd, buf, 1024)) > 0)
    write(STDOUT_FILENO, buf, n);
  close(fd);
}

int main(int argc, char*argv[]) {
	int c;
	_native_syscall=_pure_start(mysc,PUREFLAG_STDALL); // apro virtualizzazione
	mycat(argv[1]);
	return 0;
}
```
Come posso chiamare quella vera? `_pure_start` ha un valore di ritorno all'indirizzo del kernel.
domanda, noccapito. Quindi le syscall della funzione mycat vengono catturate da mysc? idk

###### Ogni volta che (?my)cat viene chiamato è una SYSCALL ed hanno alta priorità ma viene sostituita da una virtuale tutte le volte. quindi catturi le syscall.


quando parte la cat, siccome c'è una determinata variabile di enviroment. Cat ha pre lnkato la purelibc e la xchange 

```c
/* This is educational code.
	 If you use it, please attribute it to:
	 Virtual Square wiki.virtualsquare.org */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <purelibc.h>
#include <dlfcn.h>
static sfun _native_syscall;
static char hosts[]="/etc/hostname";
static char buf[128];
static long int mysc(long int sysno, ...){
	va_list ap;
	long int a1,a2,a3,a4,a5,a6;
	va_start (ap, sysno);
	a1=va_arg(ap,long int);
	a2=va_arg(ap,long int);
	a3=va_arg(ap,long int);
	a4=va_arg(ap,long int);
	a5=va_arg(ap,long int);
	a6=va_arg(ap,long int);
	va_end(ap);
	if (sysno == __NR_open) {
		char *path=(char *)a1;
		if (a1 && strcmp(path,"/etc/passwd")==0)
			a1=(long int) hosts;
	}
	return _native_syscall(sysno,a1,a2,a3,a4,a5,a6);
}
	void
	__attribute ((constructor))
init_test (void)
{
	_native_syscall=_pure_start(mysc,0);
}

```

- - -
```c
sfun _pure_start(sfun pure_syscall, int flags)
{
	int fdtmp;
	if (__builtin_expect(_pure_native_syscall == syscall,0))
		init();
	if (flags & PUREFLAG_STDIN) {
		fdtmp=dup(fileno(stdin));
		dup2(fdtmp,STDIN_FILENO);
		stdin=fdopen(STDIN_FILENO,"r");
		if (isatty(STDIN_FILENO))
			setlinebuf(stdin);
		close(fdtmp);
	}

	if (flags & PUREFLAG_STDOUT) {
		fdtmp=dup(fileno(stdout));
		dup2(fdtmp,STDOUT_FILENO);
		stdout=fdopen(STDOUT_FILENO,"w");
		if (isatty(STDOUT_FILENO))
			setlinebuf(stdout);
		close(fdtmp);
	}

	if (flags & PUREFLAG_STDERR) {
		fdtmp=dup(fileno(stderr));
		dup2(fdtmp,STDERR_FILENO);
		stderr=fdopen(STDERR_FILENO,"a");
		if (isatty(STDERR_FILENO))
			setlinebuf(stderr);
		close(fdtmp);
	}
	_pure_syscall=pure_syscall; // cuore della funzione
	return _pure_native_syscall; // cuore della funzione
}
```

"`fopencoockie` permette di creare un file della libreria c, aprendo il file in questo modo, quando, facendo delle operazioni su questo file, sia necessario fare, una read, una write, ecc. Invece di chiamare le system call chiama queste funzioni"


parametro opaco: TODO, da guardare che chezzo è



