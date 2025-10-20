Guarderemo esempi di codifica, ci interessa come funziona e ci concentriamo su java nel discorso di late-binding e overriding
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
Il più semplice, la prima definisco una classe all'interno di una classe, se volessi far vedere quella classe solo al suo interno utilizzo questo metodo. Il nome della classe è **LOCALE**

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
```



| Caratteristica           | Classe Annidata Statica (`static class`)             | Classe Interna (`inner class`)                                 |
| :----------------------- | :--------------------------------------------------- | :------------------------------------------------------------- |
| **Parola Chiave**        | `static`                                             | (Nessuna, è non-statica)                                       |
| **Tuo Scopo**            | "Raggruppare le classi"                              | "Esistere in dipendenza"                                       |
| **Legame Istanza**       | **NO.** È indipendente.                              | **SÌ.** È legata a un'istanza esterna.                         |
| **Accesso Membri**       | Solo membri `static` della classe esterna.           | **Tutti** i membri (statici e non) dell'istanza esterna.       |
| **Creazione (da fuori)** | `Outer.StaticNested obj = new Outer.StaticNested();` | `Outer o = new Outer();`<br>`Outer.Inner obj = o.new Inner();` |
  

---





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
            // Questo codice non compilerebbe.
            // y++; // <-- NON SI PUÒ FARE!
            // W è 'static' e non sa a quale 'y' di quale 
            // istanza 'X' ti riferisci.
        }
        
        // Se W avesse bisogno di 'y', dovresti passarglielo
        void g(X istanzaEsterna) {
            istanzaEsterna.y++; // Questo è valido
        }
    }

    // Metodo d'istanza di X
    void h() {
        // Per creare Z, serve un'istanza di X (questa, 'this')
        Z unoZ = new Z(); // Sintassi breve (dentro X)
        // Equivalente a: Z unoZ = this.new Z();
        
        unoZ.f(); // Modifica la 'y' di *questa* istanza di X
        
        // Per creare W, non serve un'istanza di X
        W unW = new W(); // Sintassi breve (dentro X)
        // Equivalente a: W unW = new X.W();
        
        unW.g(this); // Passiamo l'istanza 'this' se serve
    }
}
```

---

Classi Locali:
Strumenti per rafforzare incapsulamento classi, ha le stesse regole di accesso di ogni elemento presente


Interfaccia:
Un interfaccia introduce un tipo che può essere successivamente elementi classi, costanti e metodi.
Le interfacce non possono essere instanziate (new) ma solamente implementate o istanziate da altre interfacce

```c
public interface Bicycle {
void changeCadence(int newValue);
void changeGear(int newValue);
void speedUp(int increment);
void applyBrakes(int decrement);
}
```

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


non ci sto capendo un pipo, ti giuro di sta parte

Se sono allo stesso livello devo fare un overriding specifico.
me lo sto distruggendo in una maniera che neanche puoi immaginarti

