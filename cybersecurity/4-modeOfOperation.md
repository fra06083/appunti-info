- - -
introduzione su ECB ...

### definizione di sicurezza
- - -
###### semantic-eavsdropping security. CA attack
la definizione è quanto il cipher è sicuro o meno
la definizione formale è la differenza fra due probabilità (anche definita come advantage dell'avversario A data una coppia Q di algoritmo per cifrare e decifrare.)$$\large Adv_{ss} := |Pr[Exp(0)=1] - Pr[Exp(1)=1]|$$dove Exp(0) è l'esperimento nel caso in cui il bit b scelto dal challenger (charlie nelle slide) è 0.
Mentre l'uno posto a destra dell'uguale dell'esperimento è il guess fatto dall'adversary

Definition:
Q is semantically secure if for all “efficient” A,
Adv SS [A,Q] is “negligible”
ECB non è semanticamente sicuro.. zio pera


###### Semantic security nel caso di CPA
qua si scopre il perché ECB non è semanticamente corretto
La prima soluzione consiste nell'avere un algoritmo di cifraggio che randomizza 

la seconda soluzione si basa sul nonce. Il nonce deve essere una delle due seguenti:
- un valore scelto con tot bit (nello specifico security_strength/2) di entropia 
- un valore che ci si aspetta che non venga ripetuto per più di tot volte 
il nonce può essere composto da vari componenti {..}

in generale si applica quando si cifra un messaggio tramite un algoritmo di cifraggio, ricorda, il nonce non viene utilizzato molteplici volte!! 


### CBC Cipher Block Chaining
- - -
un meccanismo di chaining che permette di essere utilizzato
"c1 fa da nonce in un certo punto" parole sue :0
la fase di cifraggio consiste nel ...


C'è un problema di possibile attacco,
immagina di avere un determinato c dato dal cifraggio del messaggio m attraverso l'algoritmo E e la chiave k

zio pera qua un disastro

fino ora abbiamo visto delle operation mode in cui andiamo a lavorare con l'intero blocco il prossimo lavorerà su tot segmenti di n bit

è possibile convertire un cipher block in uno stream cipher utilizzando:
- CFB
- OFB
- CTR

prendendo per esempio CFB, guardando affondo lo schema di cifraggio e decifrazione la cosa che salta più all'occhio rispetto agli altri mode, è che nella sezione di decifrazione si continua ad utilizzare la funzione di cifraggio 

per cifrare, alla funzione passo initialization vector e la chiave, questa mi restituirà un insieme di bit. Di questi ne terrò solo una parte e li metto in xor con il plain text, ottenendo così un nuovo initialization vector per la prossima iterazione. Da capire sto cappero di shift register zio pera 