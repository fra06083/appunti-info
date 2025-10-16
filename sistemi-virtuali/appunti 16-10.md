[fonte principale di questa lezione](https://en.wikipedia.org/wiki/Berkeley_sockets)
### Berkeley socket
**key points**
è generale e utilizza i file descriptor

E' un interfaccia per comunicazione generale (non tcp/ip o udp ma qualsiasi tipo di comunicazione, viene usata anche tecnologie bluetooth)
come facciamo a scrivere programmi che usano la rete?
cose in comune fra le varie comunicazioni?
* Occorre descrittore per determinare il singolo flusso di determinazione.

l'oggetto che verrà creato per gestire una comunicazione sarà dello stesso tipo di un oggetto aperto tramite una open (si parla quindi di file descriptor!)

idea di sock-albero (indirizzo di albero) abbiamo qualsiasi tipo di indirizzo.


```
socket()
```
serve per creare un nuovo tipo di socket.


servizio di tipo stream: fornisce l'astrazione di un "tubo", inserisci da un lato un flusso di caratteri e questi usciranno dall'altra parte del tubo.
Se tutto va bene arriva l'intera sequenza inviata, o una sotto stringa di essa!

datagram: comunicazione a pacchetti, non c'è certezza che vengano recapitati in ordine e che non tutti recapitati

problema di tcp: se dovesse prendere la trama, perderebbe tempo, udp è più frammentato viene usato ad esempio per lo streaming video

http gas utilizza tcp!
casi gasanti di utilizzo di udp: il dns!!!! Viene richiesta la risoluzione per un determinato indirizzo e viene inviato un pacchetto, contenente la risposta. 



RAW ci serve per accedere in maniera grezza, ingresso a livello più basso, se lo usassimo in un caso specifico, possiamo scrivere gli indirizzi ip a mano senza header (la particella del livello superiore si intende).


(immagina l'utilizzo di un device come la tastiera, utilizzando la flag SOCK_NONBLOCK {man 2 socket (sul mio pc non va :()}, se non si stanno inviando caratteri viene ritornato zero)


facendo bind abbiamo creato questo descrittore, ma dobbiamo identificare chi si deve parlare -> diamo un nome al socket, in sostanza prendiamo il socket e gli associamo un indirizzo


Comunicazione fra pari (peer-to-peer): usiamo un protocollo che lo deve supportare (per esempio udp), usiamo bind per farli comunicare tra loro, SI USA SENDTO e RECEIVEFROM

flag: **MSG_OOB** (message out of band): è una flag che viene accesa se si supera il limite del buffer.

send message e receive message, sono le chiamate più complesse
- - -
Comunicazione **client-server**: entrano in gioco più funzioni 
**server**:
- Listen() e la set(\[N Richieste in sospeso tollerabili]) vengono chiamate per il server
socket, bind, listen (in teoria, essendo dei demoni, entrano in un ciclo infinito finché non si passa al prossimo step), accept
- Accept(): socket in attesa, crea un altro file descriptor per la connessione attuale viene ritornato il file descriptor che permette di comunicare con quel determinato host
```rust
// STRUTTURA TIPICA SERVER
comm = accept(S ...)
if (fork() == 0) // figlio, può essere un processo o un thread fork
	close(s)
else
	close(comm) // chiude il paxxre
```
gestisce la connessione con quello!


**client**:
- Connect(): ti connetti al server,

Reminder http:
richiesta get (e non solo per la get anche post ad esempio), singola richiesta viene completata quando c'è riga bianca.


uso di Internet of Threads in questo corso: Un processo deve accedere a più implementazioni di rete,

