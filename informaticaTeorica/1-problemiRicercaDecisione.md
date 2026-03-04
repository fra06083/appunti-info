- - -
18/02
le varianti dei problemi di decisione, sono più semplici:
- il loro output sarà un booleano

i problemi di ricerca sono più strutturati:
- il loro output può essere vario (percorso, moltiplicazione di matrici ecc.)


decidere un linguaggio:
dato un linguaggio, è vero che una determinata parola appartiene al linguaggio?

**i linguaggi sono specifici problemi di decisione.** 
**Infatti tutti problemi di decisione sono riconducibili ad un linguaggio**

linguaggio del percorso, insieme di tutte le triple <g, s, t>, codificate con dei simboli.

$\large \text{<path>} = \{\text{<g, s, t>} | \text{ g è un grafo e s,t sono nodi del grafo g e esiste un percorso da s a t}\}$
problemi di ricerca -> problemi di decisione -> linguaggi
i linguaggi li studiamo con gli automi che semplificano la vita dal punto di vista degli algoritmi che risolvono i problemi


### problemi e linguaggi
- - -
$\large \Sigma = \{a, b, c ... \}$ il nostro alfabeto di simboli

$\large w$ è una parola o stringa su $\Sigma$ se è un concatenamento di 0 o più simboli provenienti da $\Sigma$

$\large \Sigma^*$ è l'insieme di tutte le stringhe o parole che si possono ottenere dalla concatenazione dell'insieme dei simboli di $\large \Sigma$

$\large L$ è un linguaggio su $\large \Sigma$ se $\large L \subseteq \Sigma*$ 


**Problema di decidere un linguaggio**
Dato un linguaggio L **FISSATO**, per una stringa w, decidere se $\large w \in L$. 
Rispondo si se la stringa fa parte di L, altrimenti no se non vi appartiene.
L è un linguaggio fissato, attenzione a questa clausola!



#### Automi
- - -
Un automa è uno strumento che mentre è in funzione, sta in un determinato stato.
In base agli stimoli esterni cambia il suo stato

sono in grado di risolvere il problema di decisione del linguaggio
per capire bene l'analogia, guarda l'automa del lettore cd a pagina 7

###### macchina di Turing:
è un automa (macchina) caratterizzata da un nastro con delle celle sulla quale è possibile scrivere dei simboli. Il nastro è **infinito** a destra e a sinistra

Ha una testina, spostabile, che è in grado di leggere un simbolo in una determinata posizione.
La testina può spostarsi a destra e a sinistra, in maniera tale da evitare di buttare, e quindi "memorizzare", i simboli, a differenza di altri automi che, letto un simbolo, devono decidere come usarlo sul momento.
La macchina può scrivere su una cella, facendo così sta sovrascrivendo il simbolo precedente.

La macchina di Turing è anche un algoritmo. Questa ha vari stati di funzionamento:
- legge da nastro il simbolo con la testina
- sovrascrive qualcosa
- sposta la testina avanti o indietro
- cambia eventualmente stato
tutto questo per stabilire se la stringa sul nastro appartiene ad un linguaggio

inizialmente la testina della macchina di Turing si trova nel primo carattere a sinistra. Dobbiamo decidere un modo tale per cui, data una stringa si riesca a capire se questa appartiene al linguaggio

###### formalizzazione di una macchina di Turing
- - -
(prima di questa formalizzazione c'è stata un esercizio sulla visualizzazione del funzionamento della macchina di turing)
$\large M = <Q, q_0, F, \Sigma, \Gamma, \delta>$

- Q, insieme di stati
- $\large q_0$, stato iniziale
- F, insieme degli stati finali
- $\large \Sigma$, alfabeto dei simboli di input
- $\large \Gamma$, sovrainsieme di sigma
- $\large \delta$, funzione (non completa) di transizione che mappa coppie <stato, simbolo> in triple <stato, simbolo, direzione>  
$\large \delta: Q x \Gamma \to  Q x \Gamma x \{\leftarrow, \to\}$
la funzione è fissata e non cambia a runtime

il programma della macchina di Turing è **fissato**, dove il programma è l'insieme di archi

abbiamo bisogno di più alfabeti perché la macchina potrebbe scrivere più simboli che non appartengo a $\large \Sigma$ 