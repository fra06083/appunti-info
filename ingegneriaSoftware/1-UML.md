- - -
😎 **UML** è l'acronimo di **Unified Modeling Language**

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
- - -
è una collezione di oggetti simili. 
Una classe identifica **attributi** che appartengono a tutti gli oggetti della classe e **operazioni** di tutti gli oggetti della classe 


#### Polimorfismo
- - -
In generale il polimorfismo è la capacità di un oggetto di poter assumere diversi comportamenti in base al contesto in cui viene utilizzato 

È l'abilità di utilizzare lo stesso nome per metodi che fanno operazioni dello stesso tipo su oggetti diversi
* **polimorfismo ad-hoc** **(overloading)**: la capacità di una funzione/metodo di avere lo stesso nome di un'altra funzione, avendo un comportamento diverso. Questo avviene grazie alla differenza nel tipo/numero di argomenti passati
* **polimorfismo di sottotipo** (overriding): la capacità di un oggetto, di una classe derivata, di essere trattato come un'istanza della sua classe base. <small>spesso fatto tramite <strong>l'overriding</strong> dei metodi</small>
- **polimorfismo parametrico**: quando una funzione/metodo è in grado di operare su tipi generici, permettendo così di poter riutilizzare il codice per vari tipi di dati

* **polimorfismo generico**: un template generale definisce una struttura comune ad un insieme di funzioni/classi
##### Overriding:
* è la tecnica con la quale si sostituisce il corpo di metodo con uno nuovo a **runtime**
* il metodo sovrascritto (**overridden**) deve essere una funzione virtuale
* la funzione derivata ha la stessa **signature** della funzione della classe base
	* **signature** di una funzione:
		* nome della funzione
		* parametri formali
		* numero di parametri formali
occhio ai metodi static, questi non possono essere overraidati, per ovvie ragioni

>Questo esempio mostra **overriding** e **funzioni virtuali**

 ![[Pasted image 20250929122925.png|441x272]]
```cpp
#include <iostream>

using namespace std;

class Graph {
public:
    virtual void draw() { // <-- con virtual rendo possibile overriding
        cout << "in base\n";
    }
};

class LineGraph : public Graph {
public:
    virtual void draw() {
        cout << "in LineGraph\n";
    }
};

class PieChart : public Graph {
public:
    virtual void draw() {
        cout << "in piechart\n";
    }
};


int main() { 
    LineGraph lg;
    PieChart pc;
    lg.draw();

    Graph *p = &lg;
    p->draw();
    // rimuovi virtual da draw di graph e vedi che 
    // l'Overriding non funziona più
}

/* output:
in LineGraph  
in LineGraph
*/
```

# UML, unified model language 
- - -
![[Pasted image 20250929123019.png]]

#### Use case diagram
- - -
Descrive un'interazione tra un attore ed un sistema. Cioè uno scenario d'uso, che deve avere una caratteristica. Deve dare un valore atomico all'utente finale. 

Sono delle storie di interazioni col sistema, che devono restituire un valore!!
![[Pasted image 20250929124346.png]]
Lo use case è la prima cosa da dover fare!!
![[Pasted image 20250929124742.png]]
Trader (attore) e Sales systems (sistema) con in mezzo use cases
Relazioni particolari:
`<<extends>>` definisce il fatto che io ottengo un particolare comportamento aggiuntivo
* ***La relazione extend per un use case definisce un'estensione atomica del mio use case.***
`<<includes>>` definisce una parte di funzionalità usata da use case diversi, zona in cui vado a condividere comportamenti fra due use case diversi
* ***La relazione include per un use case definisce una funzionalità coesa dello use case e quindi separata***
<small>i nomi devono essere necessariamente non ambigui</small>

### Modellazione concettuale object oriented (MCOO)
- - -
due obiettivi:
- analisi del contesto: comprendere il contesto operazionale del sistema
- analisi dei requisiti: capire i requisiti effettivi del sistema



### Object oriented analysis
---
**Generic view**
![[Pasted image 20250929152722.png]]
- tre prospettive:
	- OOA conceptual 
		- mostra i concetti del dominio
		- è indipendente dall'implementazione
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
* tipo 
	* protocollo capito da qualsiasi oggetto
	* definisce un insieme di operazioni che possono essere usate
* classe 
	* costrutto orientato all'implementazione
	* implementa uno o più tipi

**Associazioni**, ovvero una relazione di qualche tipo fra istanze di classi
* studente che **segue** un corso
* professore che **insegna** nel corso

*Un ordine arriva da un solo cliente, un cliente può fare numerosi ordini.*
![[Pasted image 20250929153950.png]]

Le associazioni hanno due ruoli.
Un ruolo identifica un estremo di un'associazione. Un'associazione può avere due ruoli, che possono essere etichettati in modo esplicito oppure implicito. Vicino alla classe metto il ruolo che essa assume nell'associazione e questo diventerà un attributo dell'a
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

### Relazioni tra classi
- associazioni (generico) ---
- generalizzazione (la freccia parte dal figlio e punta al padre rapporto forte) --▻
- realizzazione (relazione semantica in cui c'è una specifica e il cliente la realizza (implementazione+esecuzione)) INTERFACCIA + funzione --▻
- dipendenza -->
- aggregazione: classi indipendenti ma connesse ◊--
- composizione: classe dipendente dall'altra 🔷--

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