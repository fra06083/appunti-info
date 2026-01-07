## programmazione ad oggetti
<small>(visualizzazione del mondo come oggetti che possono comunicare fra di loro per ottenere un risultato)</small>
La presenza di classi/oggetti ha due significati:
* **struttura dati** che contiene
	* campi/dati
	* metodi 
* **programmazione con attori ed agenti**
	* è prevista la comunicazione fra i vari oggetti

Altri paradigmi oltre a quello ad oggetti sono:
* funzionale (dato un input mi aspetto un output)
* imperativo (posso descrivere le cose da fare per poter ottenere un risultato)
---
## Proprietà fondamentali
* **Ereditarietà**
* **polimorfismo** (stesso nome che può essere associato a comportamenti diversi), tre tipi
	* ad-hoc - overloading
	* parametrico - generic
	* di sotto tipo - (overriding) - virtual function
Late binding, permette più flessibilità. L'associazione tra codice e corpo della funzione, avviene durante l'esecuzione
---
## Funzioni virtuali
è un **metodo non statico** di una classe che può essere **ridefinito** in classi derivate
quando si invoca una funzione virtuale per un oggetto, la quale il tipo è conosciuto a tempo di compilazione

### Overriding
metodologia tramite la quale io sostituisco ad un corpo di un metodo, un altro corpo di un metodo a runtime
* il metodo overriding deve avere la stessa signature (stesso tipo dei parametri, stesso nome della funzione, numero di parametri) e stessi tipo di ritorno

caso di overloading
```
int f(int a, int b) {return a + b}
float f(float a, float b) {return a + b}
```


---
### Templates e generics in c++
il type checking non è completo con i templates, non lo è neanche per i generics, ma in particolare non lo è per i templates. Questo perché il check per i template avviene nelle ultime fasi della compilazione.

istanziazione di due tipi:
Esplicita 
```c++
template int somma<int>(int a, int b); template double somma<double>(double a, double b);
```
Implicita
```c++
int main () {
	z<int> zi;
}
```
##### Function templates
Posso definire delle funzioni generiche, la definizione avviene solo quando la funzione è chiamata.

##### Class templates
idk sono paxo

---
