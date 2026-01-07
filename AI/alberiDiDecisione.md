- - -
Sia il **train set** un insieme di **esempi di allenamento**: $$\LARGE \langle x^{(i)}, y^{(i)} \rangle$$dove 
* $\large x^{(i)} \in X$ (insieme degli **input**)
* $\large y^{(i)} \in Y$ (insieme degli **output**, ground truth) 
* $\large i$ **indice** dell'**istanza** dell'esempio di training

Il problema che si pone è quello di "apprendere" la funzione che mappi $\large x^{(i)}$ a $\large y^{(i)}$.
L'insieme degli output $\large Y$ può essere:
- **discreto**, il problema è di **classificazione** (predizione di una classe)
- **continuo**, il problema è di **regressione** (predizione di un valore)

È necessario partire uno **spazio di funzioni** $\large H$ all'interno della quale si cerca la funzione che meglio approssima il problema. 

#### Esempio
![[esempioAlberoDecisionale.png]]

Ogni **nodo**, testa una feature $\large X$, mentre ogni **arco** uscente da un nodo corrisponde ad uno dei possibili valori **discreti** di $\large X$.
Ogni **foglia** predice la risposta $\large Y$ (oppure una probabilità condizionata $\large P(X|Y)$)
In questo esempio l'insieme di input $\large X$:
- ogni istanza $\large x \in X$ è un vettore di features del tipo: 
	- Humidity = high, Wind = weak, Outlook = rain, Temp = hot
- La funzione di target è $f: X \to Y$ dove l'insieme $\large Y$ assume valori discreti (booleani)


### Pro
- - -
- facili da capire, utili perché possono essere visualizzati
- Può essere utilizzato sia con feature **continue** che **discrete**

### Contro
- - -
- Rischio elevato di overfitting
- Facile che gli alberi siano sbilanciati con classe dominanti