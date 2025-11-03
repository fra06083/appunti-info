#### 💡 Design Pattern

### **Cos'è?**

> Descrizione di oggetti e classi che comunicano tra loro, organizzati per risolvere un problema generale in un contesto particolare.  
> Descrive un problema ricorrente e fornisce uno schema di soluzione riutilizzabile.

Non è una struttura base, ma un insieme di soluzioni, è uno scheletro, tanti scheletri di soluzioni.

**Differenza tra interfaccia e realizzazione
Divido il codice in due facce:
- Interfaccia: miriadi di significati, tipi di dati esatti
```
record interface Stack
	Begin
	Push(stack, ...)
	pop(...)
end 
```
```
record implementation Stack
	Begin
	Push(s, int p)
	Begin
		....
end 
```
è molto  
#### **Tre tipi principali:**

- **Creazionali**: pattern che gestiscono la creazione di oggetti.
    
- **Strutturali**: pattern che gestiscono la composizione di classi e oggetti.
    
- **Comportamentali**: pattern che gestiscono le interazioni tra oggetti e la condivisione delle responsabilità.
    

---

#### 🔗 Differenza tra composizione e aggregazione

>  Aggregazione → componente può vivere da solo.
>  Ho due possibilità: 
>  - vita a sé
>  - Durata vita solo all'interno della classe
   Composizione → componente muore insieme al contenitore.

Si parla di costruzione tramite aggregazione o eredità quindi 
> [!Reminder]
> Componente: Contenitori di classi e interfacce.

---

#### 🧾 Esempio: Accounting System

- Esiste un budget composto da diversi account.
    
- Il sistema deve essere in grado di ottenere informazioni aggregate da questi account.
    
- Ci concentriamo sulla **creazione e analisi della struttura**, non sulla sua modifica.
    
- Il budget deve essere **unico**.
    

Come garantire una sola istanza **(Singleton)**?

- Rendere il costruttore dell'oggetto privatuo.
    
- Impedire l'uso del `new` esterno all'interno della classe.
    
- Fornire un metodo statico per ottenere l'istanza unica.
    

```cpp
class Budget {
private:
    Budget() {} // costruttore privato
    static Budget* instance;
public:
    static Budget* getInstance() {
        if (!instance)
            instance = new Budget();
        return instance;
    }
};
Budget* Budget::instance = nullptr;
```

### Composite:
Utilizzo un approccio simile ad un sistema operativo, come una directory. Stile UNIX

> [!Esempio]
> Una directory su UNIX è in realtà un file che ha dei puntatori a dei file (funzionamento i-node)
> FIND  - exec grep % | se esce qualcosa print

Fai un operazione in Composite, mi fa un forall g in children ed esegue g.Operation() come algoritmo di visita; IL FORALL può essere deterministico o indeterministico, dipende se il linguaggio ha side effects

---

Come itero sugli account?
Operazione che lavora su un oggetto o classe concrea e fornisce elementi: First(), Next(), IsDone() e CurrentItem()

posso averli in forma randomica!

---

Un pattern ha 4 elementi
- Nome: descrivere un problema e le sue soluzioni
- Problema: This element describes a particular design problem and its context.
- Soluzione: This describes the design elements,
	their relationships, their responsibilities, and
	collaborations.
- Conseguenza: These elements are the results
	and trade-offs of applying design patterns
---

Builder Pattern:
Questo pattern è utilizzato per creare un oggetto complesso mentre separa i suoi processi dalla sua rappresentazione


---
Abstract Factory:
Se volessi creare un'interfaccia per un mio sistema, devo fare in modo che corrispondino a quella interfaccia dati, grazie al fattore astratto. Ho tante famiglie di componenti e devo gestirlo.


>Componente 1 può essere l'etichetta
 Componente 2 il bottone
 Componente 3 ....

Userò l'implementazione
```c
 
f = new FamilyAFactory(); // incapsulo un comportamento, fisso cl
cl = f.createComponent1();
```

implementazione nei dispositivi moduli, noi chiamiamo un operazione get___ e molto spesso facciamo operazioni Singleton

---

3 Modello: Prototipo

Il prototipo mi crea un oggetto copiando un altro già esistente.
A runtime posso non sapere la struttura che devo utilizzare, ma posso averne un altro che posso simulare.

> [!Example]
> [Applicazioni mobili]
> Es. Semplificare implementazione, creo un modo per creare un oggetto (un app) in maniera semplificata per creare applicazioni mobili usando XML, costruire il programma a **RUNTIME**, una finestra ad esempio la creerò copiando un oggetto finestra già definita e modificarla

Nei linguaggi di programmazione abbiamo la reflection, che ci dice il tipo di oggetto.

---

Pattern strutturali
Usano soprattutto eredità, ne vedremo solo alcuni.
Si dividono in:
- Pattern di classi
- Pattern di oggetti

### Adapter & Bridge:
separare l'interfaccia di una classe dalla sua implementazione.

The goal of the adapter is to resolve “naming”
mismatches

The goal of the bridge is to hide the
implementation from the “interface”


### Decorator Pattern:
Il decorator è formato sul concetto che un oggetto possa essere arricchito a piacere senza modificarne la struttura è un'alternativa migliore a fare sottoclassi di continuo.

posso aggiungere più decoratori al mio oggetto per "specializzarlo" e essere arricchito

```c
Window w;
w = new ElementaryWindow();
w = new TitledWindow(w, "Title")
w = new BorderedWindow()w;
```
---

Proxy Pattern:
simile al bridge ma permette l'accesso virtuale, può essere usato per accesso remoto e per protezione.
Può essere utilizzato sia a livello classe che a livello oggetto.

> [!Example]
> http è un esempio di proxy; Faccio una put (chiamata REST)
fa in modo che ci sia una sincronizzazione con il messaggio, in base che sia sincrona o asincrona, questo è il modo in cui viene approcciato il proxy; Per file lunghi uso JSON, trasformo informazioni ASCII in formato leggibile


Pattern comportamenti
Funzioni e responsabilità degli oggetti, permettono di bypassare i limiti del linguaggio ad oggetti

Visitor Pattern
Serve per aggiungere informazioni ad un oggetto senza cambiarne la struttura

Le operazioni posso essere in base alla tipologia di **visitor**.
Prendiamo ad esempio FIND -exe ... tipo: (&& cat $1) , quello che viene dopo questo comando è un visitor, VISITO una struttura dati complessaa, eseguo un comando sul suo output. 
MI FA VISITARE TUTTE LE CLASSI

---
Strategy pattern
Struttura simile, però mi dà proprio strategie in base al componente.
Supponiamo che io abbia:

```c
// 1. L'interfaccia (il contratto) 
Interface IStrategiaPulizia // Metodo che tutte le strategie concrete dovranno definire 
method pulisci()
End Interface
// 2. Le strategie concrete (gli algoritmi)

// Strategia A
Class PuliziaLavagnaStrategy implements IStrategiaPulizia
    method pulisci()
        Print "Pulisco la lavagna con cancellino e spray."
    End method
End Class

// Strategia B
Class PuliziaSchermoStrategy implements IStrategiaPulizia
    method pulisci()
        Print "Pulisco lo schermo con il panno in microfibra."
    End method
End Class

// Strategia C
Class PuliziaCattedraStrategy implements IStrategiaPulizia
    method pulisci()
        Print "Spolvero e igienizzo la cattedra."
    End method
End Class
```
---

#### Chain of Responsibility
esempio dns, abbiamo una richiesta soddisfatta da un oggetto ma non sappiamo chi lo farà
Incateniamo gli oggetti che risponderanno e finché nessuno lo soddisferà passa avanti

>[!Example]
>Controllo il tipo di file utilizzo l'app specifica per quell'app, se non specificato uso un app generica
#### Mediatore
Serve quando più oggetti complessi devono parlare tra loro


Passaggio tra diagramma e schema:
Metto la mia idea su diagramma, un diagramma può contenere 1 o più idee, sta a me quante informazioni inserire.

---
### DOMANDE per questa parte (studio teoria):
- 
