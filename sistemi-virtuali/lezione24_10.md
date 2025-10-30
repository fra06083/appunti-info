```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	char buf[1024];
	int n = read(STDIN_FILENO, buf, 1024);
	
	char *myargv{
	"bin/bash",
	buf
	"-c"
	NULL
	}
	
	execv(myargv[0], myargv)
}
```


la system fa la fork e la exec, ma esegue una shell

execv() esegue solo una shell

strtok() non funziona nel caso di file con spazi, ci sono vari tipi di problemi.


un'altra funzione pericolosa è la popen() che può catturare o input o output a differenza di system
- - -
s2argv converte una stringa in un array di argomenti


fmemopen()

open_memstream()
* apre un file per scrivere in un buffer che inizialmente ha valore 0. Quando chiudete lo stream bisogna ricordarsi di fare free
* ammette solo ouput su una variabile di dimensione statica
* è solo output, non si può rileggere
- - -
voglio accedere a questo servizio internet, usa però una altro tipo di DNS

montare un file su un file, con userbindmoud




poll ha un vettore di strutture (su select() è necessario scrivere i vettori ogni volta, cosa molto scomoda) e un timeout

il processo virtualizzato quando deve fare una poll fa una vera poll, dove i descrittore dei file virtuali sono descrittori del tipo upoll. 

due implementazioni per avere tipi di file supportati come un caso di event fd.

- - -
serve per attaccare informazioni ad un file descriptor. Voglio che ad ogni file descriptor ci sia attaccato un record di dati. Questo si può fare grazie a liibfduserdata.

- - -

poniamo di voler fare autovirtualizzazione. Ovvero un processo che cattura le syscall generate da se stesso.


plugin ip add, ip link add


link spiegati oggi
https://github.com/rd235/libpam-net
https://github.com/rd235/libstropt
https://github.com/rd235/libvpoll-eventfd
https://github.com/virtualsquare/s2argv-execs
https://github.com/rd235/userbindmount
https://github.com/virtualsquare/purelibc