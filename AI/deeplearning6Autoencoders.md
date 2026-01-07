- - -
Un autoencoder è una rete allenata per ricostruire dati in input da una rappresentazione interna imparata 

l'idea è quella di far processare un dato in input alla rete neurale, con l'obiettivo di estrarre tutta l'informazione possibile, allenando una rete dall'altra parte 

permette di fare delle proiezioni in spazi più piccoli

##### Compressione
- - -
Se il layer interno ha meno unità rispetto all'input, cosa che accade spesso, è possibile vedere gli autoencoder come una sorta di compressione dei dati, nello specifico la compressione:
- "**data specific**"
	- funziona bene solo con dati che hanno una forte correlazione fra di loro, cosa che distingue rispetto ai normali algoritmi di compressione dei dati
- "**lossy**"
	- l'output sarà ovviamente più "rumoroso" e non perfettamente uguale all'input
- **direttamente trainati**
	- su campioni di dati non etichettati (cosa significa? Idk :3). Si parla quindi di self-supervising training

gli encoders sono usualmente utilizzati per:
- anomaly detection
- data denoising
- generative models
- feature extraction


