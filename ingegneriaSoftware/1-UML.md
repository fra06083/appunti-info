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