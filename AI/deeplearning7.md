- - -
- variational autoencoders 
- generative adversarial networks GAN

### Modello generativo
- - -
Un modello generativo è modello che cerca di capire la distribuzione $\large p_{data}$ di dati reali (training set) con l'obiettivo di costruire una distribuzione di probabilità $\large p_{model}$ che si avvicina a $\large p_{data}$
Motivi per studiare i modelli generativi:
- aumentare la conoscenza sui dati e la loro distribuzione nello spazio visibile delle features
- approccio tipico per problemi che trattano output multi modali
- utile per produrre dei campioni realistici a partire da una distribuzione di probabilità

con i **modelli di variabili latenti** si cerca di esprimere la probabilità di un determinato dato, attraverso la marginalizzazione su un vettore di variabili latenti.

- Quindi si cerca di campionare X attraverso un vettore di valori z, dove z ha una distribuzione conosciuta. z è l'encoding latente di X
il generatore trasforma del rumore in un'immagine
trasformare una distribuzione nota di priorità, detta prior, nella distribuzione a cui sono interessato

Quattro tipi principali di modelli generativi:
- modelli di compressione
	- variational autoencoders (VAE)
	- generative adversarial networks (GANs)
- modelli che preservano la dimensione
	- normalizing flow
	- denoising diffusion models

### VAE (variational autoencoders)
- - -
Il generatore è in coppia con un encoder, viene così prodotto un encoding latente z, di X.
Cerca di fare in contemporanea il mapping da X a z (encoder) e il mapping da z a X 

la funzione di loss punta a 
- minimizzare l'errore di ricostruzione fra la X reale e quella generata
- portare la distribuzione Q(z) il più vicino possibile alla distribuzione a priori P(z)

### GAN (generative adversarial networks)
- - -
Il generatore rimane quello, partendo dal noise deve generare un'immagine, mentre il modo con la quale alleno il generatore è completamente diverso

Si associa al generatore un **discriminatore** che ha il compito riconoscere un'immagine generata dal generatore, dall'immagine reale, scoprire il falsario in altre parole. I due "giocano" l'uno  contro l'altro

quando si allena il generatore si "congelano" i pesi del discriminatore e viceversa

il generatore non ha mai una visione diretta dei dati che deve generare, l'unica informazione implicita è il feedback dato dal discriminatore. Che gli dice per esempio "questa cosa che hai generato penso sia falsa"  
Viene utilizzato quest feedback in fase di training per cambiare ciò che si sta generando.

nel min max game
si cerca di massimizzare la probabilità che il discriminatore su questi dati risponda 1


