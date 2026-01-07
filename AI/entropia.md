 - - -
l'entropia $\large H(X)$ di una variabile aleatoria $\large X$ è: $$\large H(X) = - \sum_{i=1}^{n} P(X = i)\log_{2}P(X = i)$$
$\large P(X =i)$ è la probabilità che un elemento dello spazio campionario abbia valore $\large X = i$   

- dove n è il numero dei possibili valori di $\large X$.
- l'entropia misura il **grado di impurità** dell'informazione.
- L'entropia è la **quantità media di informazione** prodotta da una sorgente stocastica di dati. È la **misura** del **grado** di **disordine** della variabile aleatoria 
- l'obiettivo è quello di ottenere foglie dell'albero con entropia minima

È **massima** (quindi $\large log{n}$) quando $\large X$ è uniformemente **distribuita** tra tutti i suoi n valori
È **minima** (quindi $\large 0$) quando è concentrata su un **singolo valore** 

Più **l'entropia è** **bassa** più l'ordine aumenta, permettendo di capire meglio la probabilità che un certo avvenimento accada. Viceversa, più **l'entropia è alta**, maggiore sarà l'incertezza e la confusione

#### Teoria dell'informazione
- - -
L'informazione è associata alla probabilità di ogni dato.
- Per esempio un evento con probabilità 1, non trasmette alcun tipo di informazione $$\large I(1)=0$$
La probabilità congiunta di due eventi indipendenti è data da $\large p_1p_2$, mentre l'**informazione** è data dalla somma delle informazioni dei due eventi indipendenti $$\large I(p_1p_2) = I(p_1) + I(p2)$$
Inoltre l'informazione, dato che ci si aspetta che sia antimonotona rispetto alla probabilità, si può definire come $$\large I(p) = -log(p)$$
#### Guadagno informativo (information gain)
- - -
Il **guadagno informativo** viene usato per definire il migliore attributo durante la costruzione di alberi di decisione
- **Entropia Condizionale (dato uno specifico valore v)**
	- dato una sorta di "indizio", ovvero un'informazione dalla quale dipenderà $\large X$, {esempio della probabilità di giocare una partita di tennis, sapendo che piove}
$$\large H(X|Y=v) = - \sum_{i=1}^{n} P(X=i | Y=v) \log_2 P(X=i | Y=v)$$

* **Entropia Condizionale di $\large X$ dato $\large Y$ (media ponderata sugli m possibili valori di $\large Y$)**
	* stesso concetto del caso precedente, ma si considerano tutti i possibili valori di $\large Y$
$$\large H(X|Y) = \sum_{v=1}^{m} P(Y=v) H(X|Y=v)$$

- **Guadagno Informativo (Information Gain)**
	- La differenza tra l'incertezza prima e dopo aver osservato $\large Y$.
$$\large I(X, Y) = H(X) - H(X|Y)$$*Esempio con un po' di calcoli*

![[esempioCalcoliGuadagnoInformativo.png]]

N.B.
* per quanto riguarda gli attributi **continui**, le decisioni vengono prese in base a delle opportune soglie dette **thresholds**

