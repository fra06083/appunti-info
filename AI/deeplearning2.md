### Image processing
- - -
**ImageNet** è un set contenente una vastissima quantità di immagini (~15 milioni), prese dal web e inserite all'interno di una classe di immagini.

### Object detection
- - -
Esiste il progetto YOLO, real-time object detection, all'interno di una "scatola" viene definita la classe dell'oggetto

informazione **latente**:
* è un'informazioni condensata ed implicita (un'analogia può essere di un file zippato)
* dato il noise come informazione latente da dare in input al generatore, a partire da questa informazione latente, tira fuori un qualcosa :0

### natural language processing
- - -
focus sull'interpretazione e significato di una sentenza
* Natural language understanding 
	* si occupa di interpretare e estrarre significato dal linguaggio umano, facendo sentiment analysis, question answering o named entity recognition
* Natural language modeling
	* si occupa della produzione di testo human-like, basato su un input strutturato o non strutturato
nel caso di Natural language understanding per compiere i vari compiti (capire il contesto, l'ambiguità o i sinonimi) è necessario una rappresentazione significativa delle parole, data dagli **embeddings**.
Gli embeddings sono sviluppati in modo da poter mappare parole/frasi in un spazio vettoriale a più dimensioni

**contrastive training**
duplice scopo
* cerco di avere la stessa rappresentazione di coppie coerenti
* allo stesso tempo, se ho immagini con caption diverse, gli dico di allontanarle il più possibile all'interno dello spazio latente

### language modelling
esempio: 
* data una sequenza di parole, qual è la probabilità che una parola del vocabolario completi quella sequenza 

utilizzando la chain rule si spezza la probabilità in varie sequenze, più nello specifico in probabilità condizionali.

**tecniche**:
* n-grams
	* si stimano le probabilità in una fixed window
	* non si possono catturare dipendenze di lungo raggio
* Deep neural networks approach
	* recursive neural network