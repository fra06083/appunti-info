- - -
caratteristiche in comune dei vari problemi inerenti il machine learning
* bassa conoscenza (meta-teorica) sul problema
	* <small>(pensa banalmente al problema di dover generare un volto da zero)</small>
* altissimo numero di input features <small>(features = informazioni che noi diamo sui dati)</small>
* grosso volume di dati di training (usati anche per capire la distribuzione generale)


#### Approccio tipico del machine learning
- - -
Tre passi principali:
1. definizione di una **classe di funzioni** (o modello nel nostro caso), dentro la quale si presume di trovare la soluzione, così da poter trovare dei confini, trattando i dati in base alla posizione tra i confini.

2. definizione di una **metrica di performance**. Quindi serve un qualche tipo di errore per misurare l'errore del modello

3. trovare la configurazione ottimale per **minimizzare l'errore** sul training set

![[esempioProblemaRegression.png]]
In questo caso la soluzione preferibile, dato un determinato modo di decidere quale delle due rette sia la migliore, la retta blu è quella che vince (questo perché si usa mse).

Alla fine dei conti nel machine learning si parla di problemi di ottimizzazione.
Quindi si usano tecniche iterative per approssimare al meglio il risultato e questo può essere visto come "apprendimento" 

---
###### Diversi tipi di apprendimento
![[variTipiApprendimento.png]]
Si parla di dati che hanno informazioni aggiuntive e di dati grezzi
Nel reinforcement invece idk

---
#### Features
Sono le informazioni che descrivono le **proprietà rilevanti**, relative ai dati. Esse sono l'input del processo di apprendimento 

Nell'approccio **tradizionale**: durante il pre-processing si determinano delle buone features, applicando un metodo robusto di apprendimento

Nell'approccio del **deep learning** moderno si danno, in pasto al calcolatore, i dati raw col compito di trovare le features nuove e buone. Questo approccio viene sviluppato tramite l'utilizzo delle reti neurali profnde.
![[esempioLayerNeuroni.png]]
ogni livello nascosto computa nuove features rispetto al livello precedente.