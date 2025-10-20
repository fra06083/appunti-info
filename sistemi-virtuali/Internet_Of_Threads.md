[[demoIOTHserver]] 
Cazzeggio
- (selfie): [HERMES DATA SYSTEM](https://www.sba.unipi.it/sites/default/files/img147.pdf)
utilizzi:
* creare servizi con indirizzi ip dinamici
* sicurezza generale da tipi diversi di attacchi
- - -

[Internet of Threads (IoTh)](https://wiki.virtualsquare.org/#/ideas/ioth)
noi possiamo prendere questo layer che verso l'alto parla usando i socket.
Creiamo una libreria che si interfaccia con il kernel, se a qualche punto ci serve attacchiamo la rete reale a quella virtuale (ci serve password di root) 


- - -

si potrebe scrivere un server web, che funziona normalmente senza libioth. Cambiando una semplice stringa questa apllicazione funziona su altri ambienti


per creare uno stack (simil sintassi ad exec)
```c
struct ioth *ioth_newstack(const char *stack, const char *vnl);
struct ioth *ioth_newstackl(const char *stack, const char *vnl, ... /* (char  *) NULL */);
struct ioth *ioth_newstackv(const char *stack, const char *vnlv[]);
```

* nel caso di più reti: 
	* `struct ioth *ioth_newstackv(const char *stack, const char *vnlv[]);`

possiamo anche eliminare lo stack con `delstack`
`int ioth_delstack(struct ioth *iothstack);`


quando si ha uno stack unico nel kernel, la configurazione di esso avviene a monte.
In un caso normale si comandi del tipo ipaddr o ip link
non esiste una libreria per dire 'voglio camiare indirizzo ip'. Screzo l'hanno creata quelli di vde
Sintassi di oggi nlinline (solo macro)
(non togliere mai  "r e poi i" da lib~~r~~er~~i~~a)

```c
ioth_ipaddr_add(int family, void *addr, int prefixlen, unsigned int ifindex);
```
addr può essere un ipv4 o ipv6, quindi un array da 4 o da 16 byte
prefixlen è il /24 o barra /25 dell'indirizzo
chroot -> vediamo una cartella come root
  
    > _ <   $rm -rf --no-preserve-root / TRANQUILLO CHE E' SOLO SUL FILE SYSTEM VIRTUALE NON TE PREOCCUPA'
- - -
