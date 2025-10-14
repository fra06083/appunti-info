#### Design issues
* ***decomposability***:
	* presuppone che un progetto possa essere scomposto, focalizzandosi su gli elementi richiesti dal cliente
* ***composability***
	* fare in modo che, durante l'aggiunta di un determinato componente, questo sia perfettamente integrabile
* ***understandability***
	* la facilità con la quale il componente di un programma può essere capita
* ***continuity*** 
	* l'abilità di fare piccoli cambiamenti in un programma. Questi cambiamenti si manifestano da soli in uno o pochi moduli
* ***protection*** 
	* una caratteristica architetturale che riduce la propagazione di effetti indesiderati nel caso di errori in un determinato modulo 

#### Statechart diagrams vs Interaction diagrams
Statechart diagrams:
* mostra il comportamento di un oggetto, in generale, come il suo stato cambia
Interaction diagrams:
* indica come gli oggetti interagiscono fra di loro

#### Stato degli oggetti
Ovvero quelle caratteristiche che univocamente permettono di definire in modo univoco il comportamento di un oggetto

**notazioni diagrammi di stato**
* activity
* action
* entry
* do
* on
* exit
esempio:
**PRENDERE IL CAPPUCCINO**
entry: ordino
do: bevo il cappuccino
on(event): telefonata
exit: pago 

un **evento** è qualcosa che può o non può avvenire
un'**azione** è qualcosa fatto dal mio oggetto, a volte a seguito di un evento

---
#### Diagramma di attività
usati per descrivere:
* workflow
* parallel processing
altra roba da fare (barra di sincronizzazione)
---

#### diagrammi di sequenza
dice come il manager aggiunge un oggetto professore alla descrizione della classe lezioni

sono diagrammi in cui metto gli oggetti attivi e gli attori in alto
definisco come gli oggetti si scambiano le informazioni in sequenze di tempo. Gli oggetti sono organizzati in **linee orizzontali**, mentre gli eventi in **linee di tempo verticali**

permetto di evidenziare meglio il flusso temporale.

### Diagrammi di collaborazione
E' un modo per semplificare i precedenti diagrammi è dato dai **diagrammi di collaborazione**;
- - - 
### system design
* packages: represent 
---
Come faccio ad utilizzare questo approccio per semplificarci la via?
<span style="color:tomato">PATTERN!</span>
### Pattern

Strategie di alto livello, conoscenza come antologia.
Design pattern viene dall'architettura.

Butto giù dei pezzi e creo in base ai commenti


il design patterm è una **struttura** che si è **vista nel passato**, funziona! Quindi ne **replico** il funzionamento, è la struttura che usiamo per costruire poi i vari programmi
ci portano ad un'astrazione del problema che ci permettono di capire meglio il problema

Ci basiamo su design pattern per capirne se un qualcosa è utile, è una parte di soluzione

ho organizzato il mio sistema in sottosistemi, come li usiamo? Diagramma componente

--- 
COMPONENTE
il componente contiene le interfacce, quindi è un contenitore e rappresentiamo le interfacce come chip e ci mettiamo
il nome 

![[image-10.png|499x258]]

la realizzazione (rappresentata dalla linea tratteggiata con il triangolino vuoto) è il rapporto tra la porta del componente e l'interfaccia.
***Realizzazione e implementazione sono cose diverse!*** L'implementazione descrive, tramite codice concreto, il funzionamento della parte implementativa astratta presente nell'interfaccia
All'interno di un componente posso avere più classi.

lo **stereotipo** è il modo con cui io dico al mondo che quella componente è una library
**Stereotipi** sono delle etichette e ne ho 5
- executable
- library
- table
- file
- Document
### Nodi 
Sono gli elementi (non componenti) fisici in cui avviene la computazione e sono rappresentati come dei cubi, possono essere date delle rappresentazioni grafiche, all'interno posso inserire componenti

---
Real Time UML
Cos'è? Un sistema che risponde in tempo finito per gli input successivi.
(Garbage collection rende Java non deterministico, quindi non real time, linux per il kernel mode)

UML real time supporta cambi eventi, e eventi tempo
2 keyword: WHEN dove posso inserire delle **guardie** posso dare condizioni,
timing posso usare startTime, stopTime e every.
Però non ci sono strumenti che lo possono supportare


ROOM: rendono più visibile gestione real time

---
Object Constraint Language (OCL)
linguaggio per aggiungere semantica (basato su logica del prim'ordine)
E' un linguaggio puro senza side effect (quando chiamo una funzione, il valore al di là del risultato del ritorno ad esempio IF(FOPEN(file)), il side effect è l'apertura del file)

OCL serve per definire in modo non ambiguo un comportamento tra classi ???? slide 111

Metodi di ocl sono i soliti metodi: somma, peso, nonVuoto... etc

### Refactoring:
Migliorare qualità del codice senza alterarne il funzionamento. (sta yappando sul suo corso magistrale)

Le tecniche divergono in base a quello che tocco, aggiungere, rimuovere, rinominare...




