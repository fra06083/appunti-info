Guarderemo esempi di codifica, ci interessa come funziona e ci concentriamo su java nel discorso di late-binding e overriding
## 1. Classi Annidate (Nested, Inner, Local)

In Java, è possibile definire una classe all'interno di un'altra. Questo concetto è più profondo rispetto a C++ (dove è solo questione di visibilità).

### Tipi di Classi Annidate in Java

1.  **Nested Class (Classe Annidata Statica)**
    * **Definizione:** È una classe definita con la keyword `static` dentro un'altra classe.
    * **Scopo:** Usata per raggruppamento logico e packaging.
    * **Regola Chiave:** **Non** è legata a un'istanza della classe esterna.
    * **Accesso:** Può accedere **solo** ai membri `static` della classe esterna.

2.  **Inner Class (Classe Interna)**
    * **Definizione:** È una classe non-`static` definita dentro un'altra (è il default).
    * **Scopo:** Creare un oggetto la cui esistenza *dipende* da un oggetto della classe esterna.
    * **Regola Chiave:** È legata a un'istanza della classe esterna ("enclosing instance").
    * **Accesso:** Può accedere a **tutti** i membri (statici e non-statici) dell'istanza esterna.
    * **Limiti:** Non può avere membri `static`.

3.  **Local Class (Classe Locale)**
    * **Definizione:** Dichiarata localmente *all'interno di un blocco di codice* (es. un metodo).
    * **Scopo:** Encapsulamento spinto a livello di funzione; utile per data-structure o task specifici di un metodo.
    * **Regola Chiave:** In Java, è un tipo di Inner Class. Ha accesso ai membri della classe esterna e alle variabili `final` (o *effectively final*) del blocco locale.

### Esempio Codice: Nested vs Inner

```smalltalk
testScope
| t |
t := 42.
self testBlock: [Transcript show: printString]

testBlock: aBlock
| t |
t := nil.
aBlock value
```
definisco variabile t a cui associo 42, chiamo testBlock con due parametri, testBlock richiede un blocco, che avrà un valore.
M

Su C posso scrivere
```c
a = 1
b = 2 
a = b+1 = (a++) = (--a);
              //^ mi dà errore!!!
```
cosa faccio in C?
- Considero ogni pezzo di codice ed ho un valore, ho effetti collaterali, la prima espressione ha valore 0, prendo A la decremento e gli tolgo il valore, ha un side effect che mi rende b 
---

#### In Java e C++:
posso mettere una definizione di una classe dentro un'altra classe,
Java definisce però 3 tipi di classi:
- Classi innestate:
- Classi interne:
- Classi locali:
## 1. Classi Annidate (Nested Class)

- **Definizione** In Java, per essere una **Nested Class** (in senso tecnico), deve essere dichiarata usando la parola chiave `static`. 

```java
public class X {
	int instanceVar; // Belongs to an instance of class X
	static int staticVar; // Belongs to class X
	private class Inner {
		int y;
		Inner() { y = instanceVar + staticVar; }
	}
	private static class Nested { // static me lo rende nested
		int x;
		Nested() {
			x = staticVar;
			// x += instanceVar; Error!
		}
	}
}
```



| Caratteristica           | Classe Annidata Statica (`static class`)             | Classe Interna (`inner class`)                                 |
| :----------------------- | :--------------------------------------------------- | :------------------------------------------------------------- |
| **Parola Chiave**        | `static`                                             | (Nessuna, è non-statica)                                       |
| **Tuo Scopo**            | "Raggruppare le classi"                              | "Esistere in dipendenza"                                       |
| **Legame Istanza**       | **NO.** È indipendente.                              | **SÌ.** È legata a un'istanza esterna.                         |
| **Accesso Membri**       | Solo membri `static` della classe esterna.           | **Tutti** i membri (statici e non) dell'istanza esterna.       |
| **Creazione (da fuori)** | `Outer.StaticNested obj = new Outer.StaticNested();` | `Outer o = new Outer();`<br>`Outer.Inner obj = o.new Inner();` |
  

---

Esempio che include tutto:

```java
class X {
    // Membro d'istanza (non-statico)
    private int y; 
    // --- 1. Classe Interna (Inner Class) ---
    // È legata a un'istanza di X
    private class Z {
        int k;
        void f() {
            // CORRETTO: Può accedere a 'y' perché Z è legato
            // a un'istanza specifica di X e al suo 'y'.
            y++; 
        }
    }
    // --- 2. Classe Annidata Statica (Static Nested Class) ---
    // NON è legata a un'istanza di X
    private static class W {
        int k;   
        void f() {
            // y++; // <-- NON SI PUÒ FARE!
            // W è 'static' e non sa a quale 'y' di quale 
            // istanza 'X' si riferisce.
        }
        
        // Se W avesse bisogno di 'y', dovresti passarglielo
        void g(X istanzaEsterna) {
            istanzaEsterna.y++; // Questo è valido
        }
    }

    // Metodo d'istanza di X
    void h() {
        // Creazione istanza
        Z unoZ = new Z();
        
        unoZ.f(); // Modifica la 'y' di *questa* istanza di X
        
        // Per creare W, non serve un'istanza di X
        W unW = new W(); 
        
        unW.g(this); // passiamo istanza
    }
}
```

---

Classi Locali:
Strumenti per rafforzare incapsulamento classi, ha le stesse regole di accesso di ogni elemento presente

## 2. Interfacce (`interface`)

L'interfaccia è un costrutto chiave per l'astrazione in Java.

- È un tipo riferimento.
    
- **Non può** essere istanziata.
    
- **Non** ha variabili d'istanza.
    
- Supporta l'**ereditarietà multipla** (una classe può implementare più interfacce, un'interfaccia può estenderne altre).
    
> [!Info]
>Spiegato da Succi
Interfaccia:
Un interfaccia introduce un tipo che può essere successivamente elementi classi, costanti e metodi.
Le interfacce non possono essere instanziate (new) ma solamente implementate o istanziate da altre interfacce
### Contenuto di un'Interfaccia

1. **Costanti:** Implicitamente `public static final`.
    
2. **Metodi Astratti:** Firme di metodi senza corpo (quelli tradizionali).
    
3. **Default Methods:** Metodi con un'implementazione di default (parola chiave `default`).
    
4. **Static Methods:** Metodi di utilità legati all'interfaccia (parola chiave `static`).
    
5. **Tipi Annidati:** Può contenere altre classi o interfacce.
    

### Default & Static Methods

- **Static Methods:** Sono metodi di utilità generici. Non possono accedere a dati non-statici né essere sovrascritti.
    
- **Default Methods:** Sono un meccanismo potente per permettere l'**evoluzione delle interfacce**.
    

**Problema:** Se ho un'interfaccia `DoIt` e voglio aggiungere un nuovo metodo `didItWork`, tutto il codice esistente che implementa `DoIt` si rompe perché non ha quel metodo.

**Soluzione:** Aggiungo il metodo come `default`, fornendo un'implementazione base. Il vecchio codice continua a compilare.
```java
// Esempio di evoluzione con 'default'
public interface DoIt {
    void doSomething(int i, double x);
    int doSomethingElse(String s);

    // Nuovo metodo aggiunto senza rompere il codice esistente
    default boolean didItWork(int i, double x, String s) {
        // Corpo del metodo di default
        return true; 
    }
}
```


```c
public interface Bicycle {
void changeCadence(int newValue);
void changeGear(int newValue);
void speedUp(int increment);
void applyBrakes(int decrement);
}
```

### Gestione Conflitti (Default Methods)

Cosa succede se una classe implementa più interfacce che definiscono lo stesso metodo `default`?

1. **Priorità alla Classe:** I metodi d'istanza della superclasse **vincono sempre** sui metodi `default` delle interfacce.
    
    - _Esempio:_ `Pegasus extends Horse implements Flyer, Mythical`. Se `Horse` (classe) e `Flyer` (interfaccia) hanno entrambi `identifyMyself()`, vince l'implementazione di `Horse`.
        
2. **Priorità alla Sotto-interfaccia:** Se un'interfaccia estende un'altra e fa override di un metodo `default`, la versione più specifica (quella della sotto-interfaccia) vince.
    
    - _Esempio:_ `Dragon implements EggLayer, FireBreather`. Se `EggLayer extends Animal` e `EggLayer` sovrascrive `identifyMyself` di `Animal`, vince la versione di `EggLayer`.
        
3. **Ambiguità (Errore):** Se una classe implementa due interfacce _indipendenti_ (es. `OperateCar`, `FlyCar`) che definiscono lo stesso metodo `default` (`startEngine`), il compilatore genera un **errore**.
    
    - **Soluzione:** La classe `FlyingCar` **deve** fare l'override del metodo. Può scegliere quale implementazione `default` chiamare (o entrambe) usando la sintassi `super`:
        
    
    Java
Ha un implementazione ed ho dei vincoli della $\exists$ almeno i metodi nelle classi.

```java
public class Horse {
	public String identifyMyself() { return "I am a horse."; }
}
public interface Flyer {
	default public String identifyMyself() {
		return "I am able to fly."; 
	}
}
public interface Mythical {
	default public String identifyMyself() {
		return "I am a mythical creature."; 
	}
}


public class Pegasus extends Horse implements Flyer,
	Mythical {
	public static void main(String... args) {
		Pegasus myApp = new Pegasus();
		System.out.println(myApp.identifyMyself());
	}
}
```


Se sono allo stesso livello devo fare un overriding specifico.

