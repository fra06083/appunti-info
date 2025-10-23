
# Appunti L04: Focus sul Java Strategy Pattern

Questo documento riassume i concetti della Lezione 04, focalizzandosi su come Java implementa costrutti fondamentali per il design pattern **Strategy**.

L'obiettivo è analizzare come il pattern Strategy viene realizzato in Java, specialmente attraverso il **polimorfismo via overriding** e il **late binding**. A differenza di altri linguaggi, Java non utilizza puntatori a funzioni per questo scopo.

---

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

```java
public class X {
    // Membro d'istanza (non-statico)
    int instanceVar; 
    // Membro di classe (statico)
    static int staticVar; 

    // 1. INNER CLASS (non-statica)
    private class Inner {
        int y;
        Inner() {
            // CORRETTO: Accede a entrambi
            y = instanceVar + staticVar; 
        }
    }

    // 2. NESTED CLASS (statica)
    private static class Nested {
        int x;
        Nested() {
            // CORRETTO: Accede solo allo statico
            x = staticVar;
            
            // ERRORE DI COMPILAZIONE!
            // Non può accedere a 'instanceVar' perché
            // non è legata a un'istanza di X.
            // x += instanceVar; // Error! 
        }
    }
}
````

---

## 2. Interfacce (`interface`)

L'interfaccia è un costrutto chiave per l'astrazione in Java.

- È un tipo riferimento.
    
- **Non può** essere istanziata.
    
- **Non** ha variabili d'istanza.
    
- Supporta l'**ereditarietà multipla** (una classe può implementare più interfacce, un'interfaccia può estenderne altre).
    

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








⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⢟⢟⢻⢹⢫⡛⡻⡻⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠿⣛⢍⠦⡱⡱⣑⠕⡕⡥⡱⡕⡕⣕⢢⢫⢹⢻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢍⢆⢣⢣⢢⢣⢣⢳⢸⢰⢕⢕⡪⡪⣪⢪⢪⢆⡇⡇⣇⢎⢪⢛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⡑⡌⡪⡰⡱⡱⡱⡳⣕⡯⣮⣗⣵⣳⢾⢽⣺⣞⣯⢷⢯⢷⢵⡳⣕⡕⡕⢝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⡿⡫⢊⠌⡆⡕⣕⣵⣳⢽⢽⣫⣷⣻⣳⣻⢾⡽⣽⢯⣷⣻⣞⡿⣽⢯⡯⣟⣮⡻⣎⢧⡊⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⡟⡑⢌⢢⢱⡸⣪⢗⣗⣗⢿⢽⣳⣻⣺⢽⡽⣯⣻⢽⡽⣞⣗⡯⣯⢯⣻⣺⡳⣳⢽⡺⣝⢮⡢⣻⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⡟⠔⢌⠢⡪⡪⡮⡳⣝⢮⢮⡫⣗⢗⣗⣝⢗⡽⣺⡪⡻⡺⡵⡳⡝⡮⣫⢺⢜⢮⢳⢣⢯⣪⡳⡵⡘⣿⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⠇⡑⠄⠕⡸⡱⡝⣝⢮⡳⡳⡝⣎⢧⢳⣸⡱⣱⡱⣕⢽⢜⢮⡺⡪⣞⣜⢮⢮⢮⢎⡧⣳⢕⢵⡹⡌⢾⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⠡⠨⡨⠊⡜⢜⢜⢎⢗⣝⢮⢯⡺⣝⣗⣗⡯⡷⡯⣗⡯⣯⡳⡽⣽⡺⡾⡽⣝⡷⣝⣞⢗⢝⡕⣇⢇⢽⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⡏⢌⠰⡐⡑⢌⢎⢪⢪⡳⡵⡽⣕⡯⣗⢗⢗⢯⢫⡫⡳⡝⡎⡏⡝⡎⡎⢯⠹⡪⡪⡳⢭⢳⡳⡽⣺⢜⠔⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⢂⢂⢂⠢⡊⡢⡱⡱⡵⡯⡯⠯⡳⡹⠸⡘⡘⡐⠅⢊⠂⠅⠕⡡⡑⢌⠨⠐⡁⡊⢐⠁⡊⠐⠅⢍⠪⠹⡨⣻⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⢀⠂⢄⠕⡌⡪⡸⢸⠘⢌⢂⢑⢐⢈⠐⡀⠄⠐⡈⠠⢈⠨⠐⡐⠄⠅⠂⡁⠄⠂⡀⠂⢄⢅⢕⢢⢊⢐⢐⢜⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⠠⠨⠐⡌⢎⢪⢊⠢⢁⢂⠢⠪⡒⢕⠱⡐⠅⡂⢐⠄⢂⠠⢁⢂⠅⡅⠅⡀⠂⡁⠄⠡⢑⢐⠡⠱⠐⢄⠢⡑⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⢳⢄⠊⡐⢜⢸⠰⡡⡑⡐⠄⡑⠡⠁⠅⠂⠂⢂⠐⢀⠐⠠⢐⢐⣕⣕⡕⡅⡐⠠⠄⡂⢁⠠⠄⡂⠡⡈⠄⡌⢎⢺⣿⣿⣿⣿⣿ ⣿⣿⣿⠄⢇⠧⡀⡣⡊⡎⡲⡨⡠⡡⡐⢄⠅⢊⠄⡁⡂⠅⡐⢠⢑⠔⣕⢵⣳⢽⣪⢌⢢⢁⢂⠂⢂⢂⢂⠣⡱⡱⣕⢕⢝⣿⣿⣿⣿⣿ ⣿⣿⡗⡰⡣⠡⠣⡊⢆⢣⢣⡳⣵⣣⡣⡑⠌⠂⢂⢂⢐⢰⢨⠪⡢⡫⡮⣻⣺⣻⡮⣇⢧⢱⢱⢨⢰⢀⣂⢪⢪⡺⣎⢧⠣⣿⣿⣿⣿⣿ ⣿⣿⡏⡐⠈⢨⢜⢌⢊⢎⢎⢞⡺⡪⢮⠫⡍⢎⢆⢖⢜⣔⡕⢕⡵⣝⣞⢷⣻⣽⣽⣳⣝⢮⣺⣊⢞⢼⢔⢵⡱⡹⡸⡸⡸⣸⣿⣿⣿⣿ ⣿⣿⣷⡐⢅⠪⡣⡑⠔⢌⢎⢎⢎⢎⢎⣪⡪⡮⣳⠽⢕⢕⣜⡷⣯⢷⣝⣯⢿⣳⢯⢷⢯⣻⢾⢽⡳⡑⠽⣕⢧⢳⢱⢱⢑⢼⣿⣿⣿⣿ ⣿⣿⣿⡌⢧⣊⢪⠨⡊⡢⡡⡃⡇⣏⢞⢜⣎⢯⡪⢍⠢⡘⡐⠍⠝⢝⠺⡺⠹⡪⡙⢍⢓⠝⢌⢑⢐⠌⠨⡘⡜⣕⢕⢕⠰⣹⣿⣿⣿⣿ ⣿⣿⣿⣯⠪⡪⡢⡕⠰⠨⡢⠪⡸⡰⡱⣣⢳⠱⡨⠢⣝⢵⡐⢄⠌⠄⠌⠠⠑⡐⢈⠂⠡⠨⡐⡔⡭⣣⠡⢐⠨⠪⡪⢢⠱⣸⣿⣿⣿⣿ ⣿⣿⣿⣿⣎⣪⣊⣌⠪⡨⢂⠣⠪⡘⡜⢜⢌⠪⡐⣝⢎⢧⢣⢣⢑⢅⠅⢅⠂⠄⢂⢈⠨⣈⡢⡡⢣⢳⢹⢔⠨⡨⠨⠢⡑⢼⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣗⠅⡊⢔⠡⡑⠌⠜⢌⢢⢑⢼⢸⢜⢕⢕⢕⢕⠥⠣⡓⡊⡚⠢⡃⠫⢨⠨⣊⢣⠣⡣⡣⡣⡘⢌⢂⢊⢾⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⡨⢂⠅⠪⢐⠡⡑⡑⢔⢸⢸⠸⠨⡨⠪⠊⢔⠡⢃⢂⠢⠈⠂⡊⠌⠄⠅⠂⠅⡊⠔⢈⠢⡊⢆⢂⠢⣻⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⡇⡂⡪⢈⢂⢂⠢⢡⠡⡃⠕⡈⠠⠈⠄⠑⠠⠈⠠⠄⠂⢁⠐⠄⠄⢁⢈⢠⢁⢄⡐⡐⠨⠨⠢⡡⠡⣻⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡐⠄⢅⠂⡂⠌⡂⠅⡂⠅⠂⠌⢌⢆⢇⡇⡯⡽⡽⡽⣳⡻⡝⡯⡯⡯⡳⡝⡎⢎⢜⠨⡈⠪⡐⠡⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠊⡐⡐⠄⠅⡂⠅⡐⠠⢁⢑⢑⢌⠢⠩⢊⢎⠪⡱⢑⠕⢕⢕⢑⡑⡅⠇⠣⡑⢅⠢⢈⠢⠨⢨⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠂⡐⡈⡐⠠⠡⠐⡈⢀⠢⠡⢂⠕⡈⠠⠄⡈⠄⠁⠌⠐⠄⢂⠠⠐⡈⠔⡨⠐⡈⠄⠌⢌⣾⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⢀⠂⠡⠈⠄⡀⠂⠨⠠⡁⡂⢂⠡⠄⠄⠐⡀⠂⢀⠁⢄⢐⢀⢂⠅⡂⠡⠐⡈⢐⢸⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡑⢅⠠⠐⠄⠁⠄⠐⠈⠠⢁⠢⠨⡂⠪⡨⢊⠌⡂⡑⠄⠕⡰⢐⠕⡐⢅⠊⠄⠁⠄⡂⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⣿⣿⠟⢉⠂⠄⠠⠈⡐⠅⢂⠈⠄⠂⠈⡀⢁⠐⢈⠂⠌⠌⡂⠅⢊⠐⠠⠁⠅⠂⡂⠅⢊⠐⢈⠄⠡⢁⠢⣿⣿⣿⣿⣿⣿⣿ ⣿⣿⣿⣿⡟⠡⠐⠄⡂⠈⠄⠂⠄⠄⢀⠄⠁⠄⠁⠄⡀⠄⠂⢀⠡⠐⠄⠂⠠⠈⠠⠈⠄⠂⠠⠈⢀⠈⠄⠄⢁⢢⠱⡹⣿⣿⣿⣿⣿⣿ ⣿⣿⠟⡉⠄⠡⠈⡀⠂⡐⠐⠈⠄⠂⠄⠄⠁⠠⠈⠄⠄⠄⠈⠄⠄⠄⠐⠈⠄⠄⠄⠂⠁⠈⠄⠄⠄⠄⠂⠌⢔⢢⢣⢃⠈⡉⢉⠙⡻⣿ ⣿⠏⢀⠄⡐⠈⠄⡀⠂⠠⠈⠄⢁⠈⠠⠐⠄⠄⠐⠄⠄⠂⠄⠠⠄⠂⠄⠠⠄⢀⠄⠄⠄⠠⠐⠄⠐⠨⡈⡊⡢⡱⡸⢰⠄⠄⠄⠂⠠⢉ ⠃⠨⠄⡂⢂⠈⠄⠠⠐⢀⠂⠈⠄⠄⠁⠠⠄⠠⠄⠐⠄⠄⠐⠄⠄⠄⠄⠄⢀⠄⢀⠈⠄⠄⠄⠂⠁⡁⢂⢅⢪⢰⢸⢨⠄⠠⠄⠐⠄⠄
Danilo Montesi 2026