- - -
[link pagina](https://github.com/virtualsquare/iothnamed)

Presentazione altri progetti:
```text
ioth toolset: test and fix
iothconf: tutorial
iothconf: background thread
iothnamed: tutorial
namedhcp: tutorial/update readme
```
RECAP settimana ha lavorato su ipconf in modo che l'interfaccia si crei in modo più semplice

un dns ha "due porte", una verso i client per rispondere alle richieste di risoluzione dei nomi, l'altra è per interfacciarsi con altri server dns per chiedere cose che non sas sos non penso sas sos comunque

-> Le richieste del client vanno fatte nell'altro stack
Possiamo definire lo stack o fstack se vogliamo fare quello che fanno gli altri `stack=kernel`.

il motivo per cui utilizza un macaddr fisso è per questioni di cache e velocità. 

`auth static` consente di leggere le definizioni statiche

per la risoluzione inversa dell'hash si può sfruttare la cache!

Esperimento hash + delegazione:

```bash
#terminale 1
iothnamed delegated-hash.rc
```

```bash
#terminale 2
ping mare.hash.v2.cs.unibo.it
```

```bash
#terminale 3
hashaddr ciao.hash.v2.cs.unibo.it -b 2001:760:2e00:ff00::(lo aveva settato lui)
vdens vde:///tmp/hub
ipconf eth.ip=`hashaddr ciao.hash.v2.cs.unibo.it -b 2001:760:2e00:ff00::`/64
```

gasante, usare hashing, per associare ip al nome (i guess è effettivamente gasante (non gaza...nte....... sennò 😪))

### [namedhcp](https://github.com/virtualsquare/namedhcp)
- - -

router advertisement demon
serve, quando una macchina si accende, che ci sia qualcuno possa rispondere "pronto?"
problemi, posticipato alla lezione di domani


### [otip](https://github.com/virtualsquare/namedhcp) (one tipe ip)
- - - 

proxy, servono per darvi...... non ha finito la frase >:3
si accede al proxy, invece che accedere al servizio vero

protezione da snooping
si fa ssh all'indirizzo che si sa che ora vale. Però in realtà stai parlando con rproxy, che chiamerà la macchina reale a porta 22
rproxy ogni volta definisce uno stack nuovo, per questo è adatto per fare questo tipo di cosa

per udp sti cazzi
per tcp panico?



"le vpn nascono per quelle persone, quei lavoratori che lavorano per una azienda e lavorano in modo remoto"