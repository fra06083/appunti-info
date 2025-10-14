invece di calcolare:$$\large f : X \rightarrow Y$$possiamo calcolare $$\large p:P(Y|X)$$

Ripasso di probabilità (non seguita :] )
Una variabile aleatoria X denota **l'esito di un fenomeno** riguardo al quale c'è **incertezza**. 

L'insieme $\large \Omega$ dei possibili esiti di un esperimento casuale è detto <span style="color:orange">spazio campionario</span> 

**variabile aleatoria** una funzione misurabile su $\large \Omega$ è discreta se $\large \Omega \rightarrow \{m, f\}$ o continua $\large \Omega \rightarrow \mathbb{R}$

Un **evento** è un qualche sottoinsieme di $\large \Omega$ 
La scelta dello spazio campionario va fatta con cautela, dato che di norma si pensa che gli eventi elementari accadano con la stessa probabilità anche se, non sempre vale ciò

---
##### **Variabili aleatorie multivalore**
A è detta variabile aleatoria discreta a k-valori se può assumere uno dei valori {v_1, v_2, ..., v_3}

---
##### Probabilità condizionata
![[Pasted image 20251002145025.png]]
<small>probabilità di A che dipende da B</small>
La probabilità condizionata dell'evento A, dato l'evento B è definita come la quantità: $$\large P(A|B) = \frac{P(A ∧ B)}{P(B)}$$ **Chain rule**: $$\large P(A ∧ B) = P(B) \cdot P(A|B) = P(A) \cdot P(B|A)$$![[Pasted image 20251002150017.png|615x548]]
La probabilità condizionata dell'evento A dato l'evento B è definita come la quantità: $$\large P(A|B) = P(A ∧ B)$$ **Chain rule**: $$\large P(A ∧ B) = P(B) \cdot P(A|B) = P(A) \cdot P(B|A)$$![[Pasted image 20251002150017.png]]

---
#### Bayes' rule
$$\large P(A|B) = \frac{P(A)\cdot P(B|A)}{P(B)}$$  
- - -
![[image.png]] (img. slide 78) marginalizzazione in senso di integrazione

---
#### Distribuzione congiunta
considerare tutte le possibili combinazioni di valori possibili
per ognuna delle possibili combinazioni si vuole stabilire la probabilità

gender, working hours, health; ognuna di queste è una variabile aleatoria ($\large X_1, X_2$ ecc)![[image-1.png|357x271]]

1. si costruisce una tabella con le possibili combinazioni dei valori delle features
2. stimare la probabilità per ogni combinazione di valori
all'aumentare del numero delle features, la distribuzione congiunta è un po' un miraggio dati i possibili valori raggiungibili 

$\large P(M|poor) = \frac{P(M, poor)}{P(poor)}$
probabilità di essere maschio sapendo sapendo che una persona è povera (i guess)
skippata un pochetto di robina qua 

---
##### Naive Bayes
Si suppone che le variabili siano **indipendenti** fra di loro dato Y. Allora la probabilità si può riscrivere come: $$\large P(X_1, X_2, ..., X_n| Y) = \prod_i P(X_i|Y)$$calcolo una approssimazione della mia distribuzione disgiunta.
Nel caso booleano serviva calcolare $\large 2^n -1$, con la distribuzione congiunta. Usando la naive Bayes si passa a calcolare $\large 2 \cdot n$ 
(img. nive bayes riassunto)
![[image-2.png|482x335]]

per quanto riguarda la classificazione. per quale valore $\large y_i$ di questa quantità corrisponde al valore massimo. In questo caso diventa più semplice dato che non c'è il denominatore
- - -
#### Tecnica di apprendimento
Stima dei parametri
siano $\large X_i \text{ e } Y$ variabili aleatorie discrete
$\large \pi$ credo sia la priorità a priori (sis, lo è)
$\large \theta$ è il subset, nell'immagine sotto, si prende una possibile istanza di outlook, temp, humidity e wind 
![[image-4.png|423x247]] (slide pagina 98)

i valori ottenuti alla fine (.0053 e .0205 per capirci, slide 99) non sono delle probabilità. Per trasformarli in probabilità vanno divisi singolarmente per la loro somma. (i guess)
- - -
In un approccio generativo si è interessati a capire le distribuzioni congiunte dei pixel in funzioni delle classi (nel caso di una classificazione di un'immagine)
in generale in questa tecnica si è interessati sul come i nostri dati si distribuiscono nel loro spazio, per ognuna delle label (nell'esempio della ricostruzione delle immagini dei numeri, le label sono appunto i numeri, 0, 1, 2, ..., 9) si cerca di capire la distribuzione dei vari dati nello spazio.
- - -
#### Stima dei parametri con MLE
perché si usa?
esempio della moneta:
due possibili esiti, 0 o 1 con probabilità $\large \theta \text{ e } \theta - 1$ 
sia $\large X^n$ il numero di 0 in una sequenza di n lanci.
$\large X^n$ segue una **distribuzione polinomiale**
$$\large P(X^n = \alpha_0 | \theta) = \binom{n}{\alpha_0} \cdot \theta^{\alpha_0} \cdot (1 - \theta)^{\alpha_1}$$
alpha zero è il numero di volte che 0 compare nella sequenza
Supponiamo tuttavia che esistano solo due possibilità: 
*  la moneta è regolare, dunque P(H) = .5 e P(T) = .5 
*  la moneta è falsa, con probabilità P(H) = .7 and P(T) = .3
![[image-7.png|431x282]] (slide pagina 113)
