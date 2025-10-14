Data Manipulation Language, utilizziamo le QUERY per manipolare i dati.
Si dividono in 
- Query instructions: estraiamo i dati
```
SELECT * FROM table
```
- UPDATE aggiorniamo i dati nel database
```
UPDATE table SET campo=....
```
- QBE (Query by example) dichiarativo, fare una query tramite un esempio
### Algebra Relazionale
linguaggio procedurale
Lavora su relazioni e possono essere **composte** tra loro 
- Union, intersection, difference
- rename
- select
- project
- join
	-  natural join
	-  cartesian product
	-  theta join
Come funziona operatore unione?



| id   | Cognome | Age |
| ---- | ------- | --- |
| 7274 | Rossi   | 42  |
| 2839 | Neri    | 54  |
| 2901 | Verdi   | 44  |
$\LARGE \cup$

| id   | Cognome | Age |
| ---- | ------- | --- |
| 7274 | Neri    | 33  |
| 2839 | Neri    | 54  |
| 2901 | Verdi   | 44  |

=


| id   | Cognome | Age |
| ---- | ------- | --- |
| 2839 | Neri    | 54  |
| 2901 | Verdi   | 44  |
Operatore di rinominazione

---
**Renaming**  $\Large \rho$
* operatore unitario
* produce un risultato che "cambia lo schema" ma che non altera il contenuto dei dati cambia il nome dell'attributo da `oldName` a `newName`. Guarda esempio mamma, papà
---
**Selection** $\LARGE \sigma$     
In sostanza (selfie) , quando si fa un operazione select, controlla i campi e prende solamente le righe che hanno quei campi impostati
```
SELECT campo1, campo2 FROM table
WHERE campo1=ciao AND campo2=2
```

Un sotto insieme della relazione che soddisfano un determinato predicato 

---
**Projection**
Sintassi: $$\large \pi_{AttributeList} (RELATION)$$Il risultato contiene tutte le tuple in `RELATION`, ma solo gli attributi in `AttributeList`

---
* ***si possono mescolare le due tecniche precedenti. Prima applichi la selection e poi la projection!!!***
---
### *Join*
operatore veramente gasante, permette di "fare il join" di due tabelle diverse, "collegando" gli attributi tramite per esempio un id
##### Natural join 
Operatore binario $\large \Join$  
la tupla, ristretta all'insieme finale corrisponde alla tupla 1

#### Full join 
Ogni tupla contribuisce al risultato finale

Poi ci sono anche i "not full" join e "empty join" (il risultato è una tabella vuota)

#### Outer join
* left
* right
* full

---
#### View
diversa rappresentazione per lo stesso dato:
* **tabelle di derivazione** 
* **tabelle di base**
Un esempio di view: 
$\large SUPERVISOR := \pi_{Employee,Chief} (AFFILIATION \Join MANAGEMENT)$

due campi di utilizzo per le view..
#### materialized view
una tabella permanente o temporanea viene salvata nel database **fisicamente**
* pro:
* contro:
#### virtual relations

il nome della view viene sostituito con la sua query associata
	



---
#### Relation Calculi
**Sintassi**
$\large { A_1: x_1, …, A_k: x_k | 𝑓 }$  
dove f è una formula logica con eventuali operatori booleani e quantificatori
$\large A_1:x_1 ... A_k:x_k$ è la target list con $\large A_1:x_1$ che indica attributo e variabile

**Semantica**
il risultato è una relazione su $\large A_1, ..., A_k$ contenente tuple di valori per x1 ... xk soddisfacendo la formula f