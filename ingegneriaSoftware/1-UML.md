In un sistema object oriented i metodi per ottenere alta qualità sono:
- information hiding
- abstraction 
- modularization
- reuse
Si cerca di rappresentare il mondo in termini di **oggetti che interagiscono**
---
###### Concetti chiave
* Classi
	* attributi
	* metodi
	* inheritance
	* relazioni con altre classi
* oggetti: istanze di classi
	* attributi con valori assegnati
	* relazioni instantiate
#### Classi
è una collezione di oggetti simili. 
Una classe identifica **attributi** che appartengono a tutti gli oggetti della classe e **operazioni** di tutti gli oggetti della classe 

---
#### Polimorfismo 
È l'abilità di utilizzare lo stesso nome per metodi che fanno operazioni dello stesso tipo su oggetti diversi
* **polimorfismo ad-hoc** **(overloading)**: più funzioni che vengono definite con lo stesso nome ma con parametri diversi
* **polimorfismo generico**: un template generale definisce una struttura comune ad un insieme di funzioni/classi
* **inheritance polymorphism (overriding)**: ![[Pasted image 20250929122925.png]]
---
### UML
![[Pasted image 20250929123019.png]]

#### Use case diagram
Descrive un'interazione tra un attore ed un sistema. Cioè uno scenario d'uso, che deve avere una caratteristica. Deve dare un valore atomico all'utente finale. 

Sono delle storie di interazioni col sistema, che devono restituire un valore!!
![[Pasted image 20250929124346.png]]
Lo use case è la prima cosa da dover fare!!
![[Pasted image 20250929124742.png]]
Trader (attore) e Sales systems (sistema) con in mezzo use cases
Relazioni particolari:
`<<extends>>` definisce il fatto che io ottengo un particolare comportamento aggiuntivo
`<<includes>>` definisce una parte di funzionalità usata da use case diversi, zona in cui vado a condividere comportamenti fra due use case diversi
<small>i nomi devono essere necessariamente non ambigui</small>

---
### Object oriented analysis
**Generic view**
![[Pasted image 20250929152722.png]]
- tre prospettive:
	- OOA conceptual
	- OOD specification
		- struttura generale del sistema 
	- OOP implementation
--- 
#### Classi
* Insieme di oggetti
* Definisce 
	* nome
	* attributi
	* operazioni
Differenza fra tipo e classe
* tipo ...
* classe ...

**Associazioni**, ovvero una relazione di qualche tipo fra istanze di classi
* studente che segue un corso
* professore che insegna nel corso
![[Pasted image 20250929153950.png]]

Le associazioni hanno due ruoli.
Ruolo è la direzione sull'associazione e identifica una fine di una associazione fra oggetti della stessa classe.
![[Pasted image 20250929160400.png]]
##### Molteplicità
* Indica quanti oggetti possono partecipare alla relazione

Alcune associazioni, particolarmente complesse, possono essere rappresentate attraverso delle classi (**association classes**)

**Aggregazione**: identifica quando un dato oggetto fa parte di un altro oggetto (rappresentato dal diamantino vuoto nello schema)

* Operations: processi che la classe è in grado di portare a termine. Corrisponde ai messaggi della classe
* Attributes: tre visioni
	* conceptual
	* specification
	* implementation
---
###### Sintassi!
![[Pasted image 20250929161223.png]]
Tipi di operazioni:
* query
* modifier
---
##### Aggregazione e composizione

Composizione: <small>esempio del lievito con pane, il lievito fa parte del pane e morirà con esso</small> 
Aggregazione: <small>esempio tastiera del calcolatore rubato, la tastiera ha una "vita assestante" nonostante il calcolatore muoia</small> 

---
Particolare attenzione alle istanze (uh) e alle generalizzazioni (insieme)


#### Ereditarietà multipla
È un concetto alla quale porre particolarmente attenzione, dato che classi diverse potrebbero avere conflitti fra loro.
* In questo caso la classe eredità molteplici features da diverse superclassi
#### Ereditarietà virtuale
```
• Class ItemToSell { double price;}; 
• Class EducationalTool : public ItemToSell{ }; 
• Class Book : public ItemToSell{ }; 
• Class TextBook: public EducationalTool, public Book { };
```
ricorda l'esempio della classe cavallo (con un prezzo), la classe carro(con un prezzo) e la classe carro trainato dal cavallo con un prezzo ambiguo che erediterebbe da entrambe le superclassi. In questo caso si utilizza la key word virtual per risolvere il problema (in che modo? **idk chiedi a Cesco**)

---
Delegazione e aggregazione
tramite l'aggregazione posso aggiungere delle caratteristiche. **Il resto, da rivedere**.

----
Cosa assolutamente da evitare classi troppo grandi, complesse e pesanti