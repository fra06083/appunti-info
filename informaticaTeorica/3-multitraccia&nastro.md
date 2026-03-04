- - -
Lezione 23/02

Aggiunta di optional alle macchine, memorizzare dati...
### Nozione di memoria nello stato:
- - -
Cos'è?
- Intuitivamente una macchina di memoria nello stato è una macchina che all'interno del proprio processore può utilizzare 1 o più simboli
	- $\large <q_1, ->$ il meno è la cella di memoria con **- non c'è nulla** 
>[!Warning]
>durante la definizione della macchina bisogna fissare la dimensione di memorizzazione della macchina, questa non potrà cambiare in seguito

$$\LARGE\text{L}\quad = \quad10^* | 01^*$$
$$\large <q_{0}, ->$$


(inserire fotina del prof)
Notazione: leggo alfa, inserisco nella memoria a segnato fa il contrario, quando troviamo blank va avanti


Le macchine di turing riescono ad identificare il tipo di il tipo del linguaggio? 
però occhio che questa sotto non implica quella sopra
- Sì perché: **La macchina standard può fare la stessa cosa di una macchina con memoria, ha solo bisogno di più stati quindi possono essere rappresentate in modo più compatto.**


## Macchina multitraccia
- - -
sono un'altra tipologia di macchina di turing, hanno solo un nastro ma ci sono più tracce (come un autostrada). Le tracce del nastro possono avere simboli diversi.
<img src="https://i.imgur.com/745PhR8.png">

#### Mega Testina:
- - -
permettere di scrivere e leggere tutto contemporaneamente (Avanza sul singolo nastro in blocco noooo way...) {è come se leggesse le colonne di una tabella}


Esempio di utilizzo: L = W # W | w $\in$ (a | b)$^+$
(Caricare file dal prof ti prego..... poi)

La marcatura ( * ) la mettiamo sotto
la cosa gasante della soluzione di questo esercizio rispetto alla vecchia soluzione è data dal fatto che non perdiamo la stringa di input




>[!Warning]
>una macchina multi-traccia non è più potente di una macchina a singola traccia.

Una strategia è: Siccome la testina non può fare cose strambe se le legge le stringhe per intero allora noi potremmo arricchire il nostro alfabeto con il prodotto cartesiano dei simboli che possono apparire sulle nostre tracce.

Una macchina a singola traccia può emulare una a multi traccia, utilizzando un alfabeto più ampio e facendo operazioni di scrittura e lettura su più simboli alla volta


### Macchine multinastro
- - -
- Una macchina con più nastri e più testine

Il mondo che introduciamo è quello che usiamo per tutto il corso!


fissiamo il numero di nastri all'inizio. (il numero di nastri va a pari passo con il numero di testine)
- le testine sono indipendenti fra di loro :0
- introduciamo la stabilità delle testine (queste possono rimanere ferme)
- posso scrivere e leggere in più celle simultaneamente
- l'input della macchina all'inizio sta nel primo nastro, mentre gli altri sono vuoti
- le operazioni possono o leggere o scrivere tutte. non possono avere azioni scrittura/lettura diverse


## **Notazione per le etichette:** `n° nastro: operazione`

Su tutti i nastri non menzionati non eseguiamo operazioni.

Separiamo le diverse etichette con delle graffe (come i sistemi).

> **Esempio:**
> $$\Large
\begin{cases} 
1 : 0/0, \to \\ 
2 : \not{b}/0, \to 
\end{cases}
$$
> _Sul primo nastro c'è 0, scrivo 0 e vado avanti, sul secondo c'è blank, scrivo 0 e vado avanti._



L = W | W $\in$ (0|1|2)$\Large^*$ 
	il numero di 0, 1 e 2 in w è lo stesso
(il prof lo fa con a, b, c quest'anno) ma si capisce meglio così)

quando non scriviamo in modo esplicito cosa accade ad un nastro, allora la testina di questo rimane ferma e non si cambia niente al suo interno

<img src="https://i.imgur.com/gbfvurl.png">

in $\large q_1$ sposto le testine in sincrono, accetto quando tutto è blank.

Una macchina di Turing multi-nastro può essere ricondotta ad una macchina multi-traccia 
una macchina multi-traccia costruita in un certo modo per simulare una macchina a multi-nastro è più lenta di una macchina a multi-nastro


running time di una macchina
numero di passi singoli che la macchina fa prima di arrestarsi

Ora facciamo notare il motivo per cui c'è discrepanza di running time tra macchina multi traccia (più lenta) e macchina multi nastro (più veloce).

Una definizione molto più precisa di quella data per la complessità
computazionale degli algoritmi. 


Possiamo dimostrare che il comportamento di una MT multi-nastro è simulabile da una MT multi-traccia, al costo di una certa perdita di tempo.

Calcoliamo il caso peggiore di una macchina multi traccia: 
quando è massima la distanza tra le testine.

Supponiamo di avere una MT M che ha k nastri
<img src="https://i.imgur.com/5IYLLRN.png">