@ = quelle su cui ero insicuro che ho fatto bene (rifalle)
?? = facci un check per sicurezza
??? = assolutamente da guardare

<div class = "domanda1">
1. Qual è lo scopo del metodo di <strong>Cross-Validation K-Fold</strong>?<br>
	- Selezionare automaticamente il miglior modello.<br>
	- Aumentare la dimensione del training set.<br>
	- <span class="evidenzia_risposta">Valutare il modello su più set di test, migliorando la generalizzazione. </span> <br>
	- Ridurre il numero di dati necessari per l'addestramento. <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Valutare il modello su più set di test, migliorando la generalizzazione. <br>

<strong>Spiegazione</strong>: viene diviso il dataset iniziale in una serie di porzioni uguali di dati (k-campi) e ne uso iterativamente un tot per il train e un tot per il test. DA RIGUARDARE

</details>
</div>

---

<div class = "domanda1">
2. Nel caso di un <strong>albero di decisione</strong> con features discrete, cosa si può dire della profondità dell'albero?<br>
	-<span class="evidenzia_risposta"> È minore o uguale al numero delle features.</span><br>
	- È sicuramente maggiore del logaritmo in base due del numero dei dati.<br>
	- È minore o uguale del numero delle classi. <br>
	- Non si può dire nulla. <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: È minore o uguale al numero delle features <br>

<strong>Spiegazione</strong>: La profondità massima è limitata dal numero di domande (features) uniche che puoi porre. Se hai N features, non puoi fare più di N passaggi prima di arrivare a una foglia.

</details>
</div>

---

<div class = "domanda1">
3. Che cosa si intende con <strong> apprendimento supervisionato </strong> ?<br>
	- Apprendimento che non fa uso di tecniche statistiche o probabilistiche<br>
	- Apprendimento che tende a imitare il comportamento di un esperto. <br>
	- Apprendimento sotto la supervisione diretta di un esperto. <br>
	- <span class="evidenzia_risposta">Apprendimento di funzioni basato su esempi di training composti da coppie input-output. </span> <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Apprendimento di funzioni basato su esempi di training composti da coppie input-output.<br>

<strong>Spiegazione</strong>: Apprendimento supervisionato: vengono forniti sia valori di input, sia i valori di output (soluzioni). Nell'apprendimento supervisionato addestriamo la macchina dandole le soluzioni (etichette), affinché impari a dividere i dati o a calcolare valori numerici. Due categorie principali di apprendimento supervisionato: classificazione (output è categoria o una classe) e regressione (output è un numero continuo)

</details>
</div>

---

<div class = "domanda1">
4. Selezionare la sentenza <strong> ERRATA </strong> relativa all'<strong>entropia </strong> per la distribuzione di probabilità di una variabile aleatoria discreta<br>
	- Il range del suo valore è tra 0 e log n dove n sono i possibili valori di X <br>
	- Il suo valore è minimo (e uguale a 0) quando la probabilità è tutta concentrata in una classe <br>
	- <span class="risposta_errata">Il suo valore è minimo (e uguale a 0) quando la probabilità è equamente distribuita tra tutte le classi</span> <br>
	- È una misura del grado di disordine della variabile aleatoria<br>
	
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Il suo valore è minimo (e uguale a 0) quando la probabilità è equamente distribuita tra tutte le classi <br>

<strong>Spiegazione</strong>: L’entropia è massimizzata quando la X è uniforme su tutti i valori (1) e minima (0) quando è concentrata su un singolo valore. 


</details>
</div>

$$H(X) = - \sum_{i=1}^{n} P(X=i)\log_2 P(X=i)$$
- - -

<div class = "domanda1">
5. Selezionare la sentenza <strong> ERRATA </strong> relativa alla <strong>distribuzione congiunta</strong> di probabilità per N variabili aleatorie discrete<br>
	- <span class="risposta_errata">Richiede il calcolo di un numero esponenziale di parametri. </span> <br>
	- È la distribuzione di probabilità di tutte le possibili tuple di valori per le variabili. <br>
	- Non permette il calcolo di probabilità condizionali tra le features. <br>
	- Consente il calcolo delle probabilità marginali delle singole features <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Richiede il calcolo di un numero esponenziale di parametri.<br>

<strong>Spiegazione</strong>: ?

</details>
</div>

---

<div class = "domanda1">
6. Selezionare la sentenza <strong> ERRATA </strong> relativa alla tecnica <strong>Naive Bayes</strong><br>
	- Fornisce un modo computazionalmente efficiente per approssimare la distribuzione congiunta di probabilità delle features <br>
	- Deriva dall'ipotesi teorica semplificativa che le features siano indipendenti tra loro, date le classi <br>
	- È una tecnica di tipo generativo in quanto cerca di determinare la distribuzione delle varie categorie dei dati <br>
	- <span class="risposta_errata"> Non può essere utilizzata se le features non sono tra loro indipendenti, date le classi </span> <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Non può essere utilizzata se le features non sono tra loro indipendenti, date le classi <br>

<strong>Spiegazione</strong>: L'indipendenza delle feature è un'ipotesi teorica semplificativa, non un requisito tecnico bloccante. Nella realtà i dati hanno quasi sempre dipendenze, ma l'algoritmo si usa lo stesso e spesso funziona sorprendentemente bene perché l'approssimazione è sufficiente per classificare correttamente.

</details>
</div>

---

<div class = "domanda1">
7. Quale distribuzione di probabilità si assume abitualmente per una variabile obiettivo continua nel caso della tecnica <strong>Naive Bayes</strong>?<br>
	-Una distribuzione binomiale<br>
	-<span class="evidenzia_risposta">Una distribuzione Normale, ovvero Gaussiana(0,1)</span><br>
	-Una distribuzione uniforme in [0,1]<br>
	-Una distribuzione esponenziale<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Una distribuzione Normale, ovvero Gaussiana(0,1)  <br>

<strong>Spiegazione</strong>: Che cosa fare quando le features Xi sono continue? Per utilizzare Naive Bayes dobbiamo calcolare P(Xi|Y), ma quando Xi è continua, le probabilità puntuali sono nulle, per cui si parla di densità delle distribuzioni. Un approccio tradizionale consiste nel supporre che P(Xi|Y) abbia una distribuzione Gaussiana (detta anche Normale).

</details>
</div>

---

<div class = "domanda1">
8. Ci sono due monete, una normale e una che restituisce testa con probabilità 3/4 e croce con probabilità 1/4. Faccio due lanci con la stessa moneta e osservo una testa e una croce. Che cosa posso concludere?<br>
	-Nulla<br>
	-La probabilità di usare uno o l'altra moneta è esattamente la stessa<br>
	-È più probabile che la moneta sia truccata<br>
	-<span class="evidenzia_risposta">È più probabile che la moneta sia normale</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: È più probabile che la moneta sia normale<br>

<strong>Spiegazione</strong>: Per capire il motivo si deve calcolare la probabilità di ottenere 1 testa e 1 croce con entrambe le monete e confrontare i risultati. <br>
1. <strong>Caso moneta normale</strong><br>
Probabilità Testa (T)=1/2<br>
Probabilità Croce (C)=1/2<br>
Scenario A: esce prima Testa e poi Croce: (1/2 * 1/2)<br>
Scenario B: esce prima Croce e poi Testa: (1/2 * 1/2)<br>
(1/2 * 1/2)+(1/2 * 1/2)=0.5<br>
2.<strong> Caso moneta truccata</strong><br>
Probabilità Testa (T)=3/4<br>
Probabilità Croce (C)=1/4<br>
(3/4 * 1/4)+(1/4 * 3/4)=6/16 (ovvero 0.375)<br>
Poiché 0.5 > 0.375 è più verosimile che i dati osservati provengano da una moneta normale

</details>
</div>

---

<div class = "domanda1">
9. Quale è l'obiettivo principale dell'algortimo di <strong>clustering K-means</strong>?<br>
	-Ridurre il numero dei clustersi al minimo<br>
	-Ottimizzare il numero dei clusters basandosi sulla distribuzione Gaussiana dei dati<br>
	-Trovare il punto medio del dataset<br>
	-<span class="evidenzia_risposta">Raggruppare i punti di un cluster attorno al loro centroide</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Raggruppare i punti di un cluster attorno al loro centroide<br>

<strong>Spiegazione</strong>: K-means è un algoritmo di clustering basato su centroidi iterativo che suddivide un set di dati in gruppi simili sulla base della distanza tra i loro centroidi. Il centroide, o centro del cluster, è la media o la mediana di tutti i punti all'interno del cluster a seconda delle caratteristiche dei dati.

</details>
</div>

---

<div class = "domanda1 riprendere">
10. Qual è il principale scopo della <strong>normalizzazione</strong> dei dati prima dell'addestramento di un modello di machine learning?<br>
	-Aumentare la precisione delle previsioni del modello.<br>
	-<span class="evidenzia_risposta">Garantire che tutte le feature abbiano la stessa scala, migliorando la convergenza dell'ottimizzazione.</span><br>
	-Evitare che i dati contengano valori mancanti.<br>
	-Ridurre il numero di parametri del modello.<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Garantire che tutte le feature abbiano la stessa scala, migliorando la convergenza dell'ottimizzazione.<br>

<strong>Spiegazione</strong>: a quanto pare i dati vengono pre-elaborati, scalando le feature in un intervallo comune per evitare che feature con scale diverse dominino il modello

<br>
la normalizzazione serve quando ci sono feature con valori molto eterogenei. Si scalano le feature in un range prefissato (solitamente tra 0 e 1) onde evitare che alcune feature sovrastino altre

</details>
</div>

---

<div class = "domanda1">
11. Quale delle seguenti opzioni <strong>NON</strong> aiuta a <strong>ridurre l'overfitting</strong> in un modello di deep learning?<br>
	-<span class="risposta_errata">Aumentare il numero di epoche di addestramento</span><br>
	-Ridurre la complessità del modello per evitare un adattamento eccessivo ai dati di training.<br>
	-Aumentare la quantità di dati disponibili per l'addestramento.<br>
	-Utilizzare tecniche di regolarizzazione come dropout o weight decay<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Aumentare il numero di epoche di addestramento.<br>

<strong>Spiegazione</strong>: Addestrare troppo a lungo causa l'overfitting! Le altre opzioni (b, c, d) sono errate nel contesto del quiz proprio perché sono metodi efficaci per combattere l'overfitting. <br>
<strong>RIDURRE LA COMPLESSITÀ DEL MODELLO</strong>: semplificare il modello (meno strati, meno neuroni) riduce la sua "capacità". Un modello più semplice è costretto a imparare solo le regole generali (i pattern principali) e non riesce a memorizzare il "rumore" o i dettagli inutili dei dati di training.<br>
<strong>AUMENTARE LA QUANTITÀ DEI DATI DISPONIBILI</strong>: simile a imparare a memoria dati per un test, se ne ho troppi è impossibile farlo. Più dati sono forniti al modello, più è difficile per lui impararli tutti.<br>
<strong>USO DI TECNICHE DI REGOLARIZZAZIONE</strong>: è come mettere dei freni/penalità al modello.<br>
-<strong>Weight Decay</strong>: penalizza pesi troppo grandi nella rete neurale. Pesi grandi indicano che modello reagisce in modo esagerato a piccoli cambiamenti (overfitting).<br> 
-<strong>Dropout</strong>: durante addestramento spegne casualmente alcuni neuroni. Impedisce al modello di basarsi su specifico percorso, crea così strategie più robuste.
<span style="color:Tomato">a quanto pare aumentare il tempo di allenamento non aiuta il modello a ridurre l'overfitting questo perché non si sta risolvendo il problema inerente all'apprendimento del rumore</span>
</details>
</div>

---

 <div class = "domanda1 riprendere">
12. Nella <strong>Principal Component Analysis</strong>, cosa indica la varianza spiegata da ciascuna componente?<br>
	-Indica la correlazione tra ciascuna componente e la variabile target<br>
	-<span class="evidenzia_risposta">Indica quanto una singola componente contribuisce alla varianza complessiva dei dati</span><br>
	-Indica la deviazione standard della componente rispetto alla media dei dati<br>
	-Misura la somma cumulativa delle differenze quadratiche tra le osservazioni e i valori predetti dalla componente<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Indica quanto una singola componente contribuisce alla varianza complessiva dei dati<br>

<strong>Spiegazione</strong>: <span style="color:Tomato">La PCA trasforma un dataset con un'altra dimensionalità, in uno spazio a dimensione inferiore. Nel fare questo cattura le strutture più significative cercando di mantenere la variabilità dei dati</span>
</details>
</div>

---

<div class = "domanda1">
13. Selezionare la sentenza <strong>ERRATA</strong> relativa alla <strong>probabilità condizionata</strong> P(A|B) tra due eventi A e B<br>
	-P(A|B) può essere maggiore di P(A)<br>
	-P(A|B) può essere inferiore a P(A)<br>
	-<span class="risposta_errata">P(A|B) è sicuramente minore o uguale di P(A and B)</span><br>
	-P(A|B) è sicuramente maggiore o uguale di P(A and B)<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Spiegazione</strong>:la terza è l'opzione corretta Essendo una probabilità, P(B) è un numero compreso tra 0 e 1. Cosa succede quando si divide un numero per qualcosa di più piccolo di 1? Il risultato diventa più grande.<br>
<strong>Esempio</strong>:<br>
Probabilità dell'intersezione P(A∩B) = 0,1 (10%).<br>
Probabilità di B P(B) = 0,5 (50%).<br>
P(A∣B)=0,1 / 0,5=0,2<br>
0,2 (il risultato) > 0,1 (l'intersezione).<br>
Opzione c afferma che P(A∣B)< P(A and B).<br>
Questo è matematicamente IMPOSSIBILE (a meno che P(A∣B) non sia zero). <br>
Dividendo l'intersezione per un numero decimale (P(B)), il risultato cresce, non diminuisce.
</details>
</div>

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}$$
---

 <div class = "domanda1">
14. Un dataset contiene 1/3 di positivi e 2/3 di negativi. La recall del modello è di 2/3. Che percentuale dei dati sono falsi negativi?<br>
	-Non può essere stabilito<br>
	-1/3<br>
	-<span class="evidenzia_risposta">1/9</span><br>
	-2/9<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 1/9<br>

<strong>Spiegazione</strong>:<br>
2/3 = (TP) / 1/3 <br>
TP = 2/3 * 1/3 = 2/9, così abbiamo trovato i <strong>TRUE POSITIVES</strong><br>
Positivi = TP + FN, quindi 1/3 = 2/9 + FN <br>
FN = 1/3 - 2/9 = 1/9

</details>
</div>

$$
\begin{aligned}
\text{Positivi Totali (P)} &= TP + FN \\
\text{Negativi Totali (N)} &= TN + FP \\
\text{Totale Dati (All)} &= TP + TN + FP + FN \\
\\[10pt]
\text{Accuratezza} &= \frac{TP + TN}{\text{All}} \\
\\[10pt]
\text{Precisione} &= \frac{TP}{TP + FP} \\
\\[10pt]
\text{Richiamo (Recall)} &= \frac{TP}{TP + FN} \\
\\[10pt]
\text{Specificità} &= \frac{TN}{TN + FP} \\
\\[10pt]
\text{F1 Score} &= 2 \cdot \frac{\text{Precisione} \cdot \text{Recall}}{\text{Precisione} + \text{Recall}}
\end{aligned}
$$

![[Screenshot 2025-12-01 alle 14.53.22.png]]


---
questa un po' sus
 <div class = "domanda1">
15. Selezionare la sentenza <strong>ERRATA</strong> relativa al learning rate<br>
	-Il learning rate può variare durante il training<br>
	-<span class="risposta_errata">È una metrica che misura la capacità di apprendimento del modello</span><br>
	-È un iper-parametro che definisce la lunghezza del passo durante la discesa del gradiente<br>
	-Un learning rate alto tipicamente velocizza il training ma potrebbe saltare sopra al minimo<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: È una metrica che misura la capacità di apprendimento del modello<br>

<strong>Spiegazione</strong>: The backpropagation algorithms only gives a direction in which gradients should be updated. The actual amount of the update is obtained by multiplication with a scalar hyper-parameter (fixed externally, not learned) called learning rate. Increasing the learning rate can make training faster, but it reduces the accuracy of the result. If we make large steps nearby the optimum, we can miss it. (Variare learning rate: learning rate scheduling)
<span style="color:Tomato">È quindi un iper parametro che va a definire di quanto aggiornare il gradiente, questo è scelto esternamente e non imparato dal modello!</span>
</details>
</div>

---
@ panico riguardala bene (qua stai attento)
<div class = "domanda1 riprendere">
16. Selezionare la sentenza corretta riguardo alla <strong>regressione logistica</strong><br>
	-La predizione non dipende dal bilanciamento dei dati di training rispetto alle classi<br>
	-<span class="evidenzia_risposta">I parametri del modello sono tipicamente calcolati mediante discesa del gradiente</span><br>
	-I parametri del modello possono essere tipicamente calcolati in forma chiusa, mediante una formula esplicita<br>
	-Il calcolo della predizione non si basa sulla loglikelihood dei dati di training, in quanto si tratta di una tecnica discriminativa<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: I parametri del modello sono tipicamente calcolati mediante discesa del gradiente<br>

<strong>Spiegazione</strong>: <br>
regressione logistica molto sensibile al bilanciamento delle classi(...)<br>
i parametri <strong>non</strong> possono essere calcolati in forma chiusa (si parlerebbe di regressione lineare)<br>
Calcolo non si basa su loglikelihood: Regressione logistica è un metodo discriminativo, ma la funzione standard per trovare parametri migliori è MLE (...)

</details>
</div>

---

<div class = "domanda1">
17. Selezionare la sentenza <strong>SCORRETTA</strong> relativa ai <strong>neuroni artificiali</strong><br>
	-<span class="risposta_errata">Un neurone artificiale può apprendere qualunque funzione dei suoi input</span><br>
	-Un neurone artificiale definisce un semplice modello matematico che simula il neurone biologico.<br>
	-Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dalla applicazione di una funzione di attivazione non lineare.<br>
	-Il numero dei parametri di un neurone artificiale è lineare nel numero dei suoi input.<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Un neurone artificiale può apprendere qualunque funzione dei suoi input.<br>

<strong>Spiegazione</strong>: 
<strong>Calcolo di combinazione lineare degli input...</strong>: corretto! Prima fa la somma pesata (z = w1​x1​ + w2​x2​ + ... + b) e poi applica una non-linearità (come la Sigmoide o la ReLU) al risultato.<br>
<strong>Numero dei parametri...</strong>: Se un neurone ha N input, avrà N pesi (uno per ogni input) più 1 bias. Quindi i parametri totali sono N+1...riguarda...Pesi collegati a input (?).<br>
<br>
Un singolo neurone artificiale è limitato. Matematicamente, un singolo neurone è un classificatore lineare: può risolvere solo problemi dove i dati possono essere separati da una linea retta (o un iperpiano). <strong>Esempio classico</strong>: Un singolo neurone non può imparare la funzione logica XOR, perché non è linearmente separabile. Per apprendere "qualunque funzione" serve una rete di neuroni (con almeno uno strato nascosto), non un neurone da solo.


</details>
</div>
![[Screenshot 2025-11-24 alle 15.44.48.png|321x113]]

$$ y = f\left( \sum_{i=1}^{n} w_i x_i + b \right) $$
---

<div class = "domanda1">
18. Cosa si intende con <strong>"deep" features</strong>?<br>
	-Features ottenute mediante utilizzo di sensori ottici di profondità<br>
	-<span class="evidenzia_risposta">Features sintetizzate in modo automatico a partire da altre features</span><br>
	-Features soggette a una approfondita supervisione da parte umana<br>
	-Features relative a dati in 2 o più dimensioni<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Features sintetizzate in modo automatico a partire da altre features<br>

<strong>Spiegazione</strong>: Deep Learning exploits deep features of data, that is features extracted from other features.

</details>
</div>

---

<div class = "domanda1 riprendere">
19. Selezionare la sentenza <strong>SCORRETTA</strong> relativa alla <strong>backpropagation</strong> per reti neurali<br>
	-E' l'algoritmo per il calcolo della derivata parziale della loss rispetto a ogni parametro della rete<br>
	-Si riduce a semplici calcoli algebrici facilmente parallelizzabili in strutture di calcolo tipo GPU<br>
	-L'algoritmo calcola il gradiente un layer alla volta, sfruttando la regola matematica per la derivazione di funzioni composte<br>
	-<span class="risposta_errata">Tipicamente, il gradiente viene artificialmente rinforzato ad ogni layer attraversato per contrastare il fenomeno della sua scomparsa (vanishing)</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Tipicamente, il gradiente viene artificialmente rinforzato ad ogni layer attraversato per contrastare il fenomeno della sua scomparsa (vanishing)<br>

<strong>Spiegazione</strong>: la backpropagation moltiplica tanti numeri piccoli tra loro (derivate minori di 1), il gradiente tende a diventare minuscolo e svanire (vanishing gradient). La backpropagation causa o rivela questo problema, non lo risolve.<br>
<br>
The purpose of backpropagation is to train a neural network to make better predictions through supervised learning. More fundamentally, the goal of backpropagation is to determine how model weights and biases should be adjusted to minimize error as measured by a loss function.<br>
Backpropagation è il meccanismo che permette alla rete neurale di imparare dai propri errori. Processo suddiviso in circa quattro parti:<br>
1. Forward Pass: la rete riceve un dato in input, fa i suoi calcoli attraverso tutti i vari layer e produce una previsione finale. Esempio: viene mostrata foto di un cane e rete afferma che invece è un gatto (poiché non è ancora allenata).<br>
2. Calcolo dell'Errore, si confronta la previsione con la realtà e si calcola errore. La funzione di costo o Loss Function calcola un numero che rappresenta questo errore.<br>
3. Backward Pass: qui avviene la backpropagation. L'algoritmo torna indietro, dall'output verso l'input, per capire di chi è la colpa dell'errore. Chiede all'ultimo strato: "Quanto hai contribuito a questo errore?" Poi va allo strato penultimo: "E tu, quanto hai influenzato lo strato successivo a sbagliare?". E così via fino all'inizio.<br>
4. Update: una volta capito quanto ogni singolo neurone (ogni peso) ha contribuito all'errore, usiamo un ottimizzatore (come Discesa del Gradiente) per "girare la manopola" di quel peso nella direzione opposta, così la prossima volta sbaglierà meno.

</details>
</div>

---

<div class = "domanda1">
20. Quale è l'effetto tipico della <strong>riduzione della dimensione del minibatch</strong> durante il training?<br>
	-La Backpropagation è effettuata meno frequentemente e l'aggiornamento dei parametri è meno accurato<br>
	-<span class="evidenzia_risposta">La Backpropagation è effettuata più frequentemente ma l'aggiornamento dei parametri è meno accurato</span><br>
	-La Backpropagation è effettuata meno frequentemente ma l'aggiornamento dei parametri è più accurato<br>
	-La Backpropagation è effettuata più frequentemente e l'aggiornamento dei parametri è più accurato<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: La Backpropagation è effettuata più frequentemente ma l'aggiornamento dei parametri è meno accurato<br>

<strong>Spiegazione</strong>: If we <strong>decrease</strong> the batchsize we <strong>update more frequently</strong> (that is good), but updates are <strong>less accurate</strong>, since we are backpropagating form a loss relative to very specific data. Conversely, if we increase the batchsize, updates grow in accuracy (the ideal would be to compute them on the whole training set- fullbatch) but training can be slow, since parameters are too rarely updated.

</details>
</div>

---

<div class = "domanda1">
21. Selezionare la sentenza <strong>SCORRETTA</strong> relativa <strong>all'overfitting</strong><br>
	-Può essere contrastata con tecniche di regolarizzazione<br>
	-<span class="risposta_errata">L'acquisizione di nuovi dati di training non può che peggiorare la situazione.</span><br>
	-Può essere particolarmente pericolosa per modelli altamenti espressivi<br>
	-Può essere contrastata con la tecnica di early stopping durante la fase di training<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: L'acquisizione di nuovi dati di training non può che peggiorare la situazione<br>

<strong>Spiegazione</strong>: <br>
<strong>Early stopping</strong>: L'arresto anticipato interrompe la fase di addestramento prima che il modello di machine learning riconosca il rumore nei dati. Tuttavia, è importante che i tempi siano corretti, altrimenti il modello non darà risultati accurati.<br>
<strong>Tecniche di regolarizzazione</strong>: pensa a dropout o weight decay. <br>
<strong>Pericolosa per modelli espressivi</strong>: maggiore è l'espressività del modello, maggiore è il rischio di overfitting. Un modello poco espressivo deve basarsi su regole generali per memorizzare i dati e ignora il rumore delle immagini, un modello molto espressivo no. 


</details>
</div>

---

<div class = "domanda1">
22. Il problema della scomparsa del gradiente (vanishing gradient) si riferisce a una progressiva diminuzione dell'intensità del gradiente, dovuta a: <br>
	-Training eccessivamente lungo<br>
	-Dati troppo rumorosi o malamente preprocessati<br>
	-Troppi pochi dati di training a disposizione<br>
	-<span class="evidenzia_risposta">Backpropagation in reti profonde</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Backpropagation in reti profonde<br>

<strong>Spiegazione 1</strong>: If you systematically use the sigmoid as activation function in all layers of a deep network, the gradient will contain a lot of factors below 0.25, resulting in a very small value. If the gradient is close to zero, learning is impossible. This is known as the vanishing gradient problem.<br>
<strong>Spiegazione 2</strong>: <br>
<strong>Backpropagation</strong>: algoritmo calcola i gradienti moltiplicando le derivate di ogni strato, partendo dalla fine verso l'inizio (Chain Rule)<br>
<strong>Limite della sigmoide</strong>: la derivata della sigmoide è sempre molto piccola<br>
<strong>Effetto della profondità</strong>: in una rete profonda, la backpropagation costringe a moltiplicare 0.25 (...)per se stesso moltissime volte, il quale diventa rapidamente quasi zero. Il segnale di errore si """spegne""" prima di arrivare ai primi strati, rendendo impossibile apprendimento(...)


</details>
</div>

---

<div class = "domanda1">
23. Quale è lo scopo dell'<strong>optimizer</strong> in <strong>Tensorflow/Keras?</strong> <br>
	-<span class="evidenzia_risposta">Definire l'algoritmo che calcola i gradienti della loss e aggiorna i pesi del modello</span><br>
	-Salvare i migliori pesi del modello durante il processo di training<br>
	-Aggiungere una penalità ai pesi del layer su cui viene istanziato<br>
	-Contrastare overfitting<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Definire l'algoritmo che calcola i gradienti della loss e aggiorna i pesi del modello<br>

<strong>Spiegazione</strong>: <br>
-<strong>Salvare migliori pesi del modelli...</strong>: compito dei Callbacks, il compito dell'optimizer è modificare i pesi, non salvarli o decidere quale sia il migliore.<br>
-<strong>Aggiungere penalità ai pesi...</strong>: questo si riferisce a regolarizzazione.<br>
-<strong>Contrastare overfitting</strong>: obiettivo optimizer è di minimizzare errore, non si preoccupa di generalizzazione/overfitting.<br>
<br>
<strong>Optimizer</strong>: The tool in charge of governing the gradient descent technique, possibly dynamically adapting the learning rate, is the so called optimizer.
</details>
</div>

---

<div class = "domanda1">
24. Quale delle seguenti <strong>NON</strong> è una applicazione tipica degli <strong>autoencoders</strong>?<br>
	-Rilevamento di anomalie (anomaly detection)<br>
	-Rimozione del rumore (denoising)<br>
	-<span class="risposta_errata">Segmentazione di immagini (semantic segmentation)</span><br>
	-Riduzione delle dimensioni (dimensionality reduction)<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Segmentazione di immagini (semantic segmentation<br>

<strong>Spiegazione</strong>: hanno applicazioni per la data denoising, anomaly detection, feature extraction e generative models
</details>
</div>

---
@ (le res net sono le residual networks)
<div class = "domanda1">
25. Qual è il principale vantaggio delle <strong>connessioni residue</strong> (skip connections) in una <strong>ResNet</strong>?<br>
	-Riducono il numero di parametri da ottimizzare nel modello<br>
	-<span class="evidenzia_risposta">Permettono una migliore gestione del problema del vanishing gradient.</span><br>
	-Permettono di evitare l’overffitting durante l'addestramento<br>
	-Migliorano la velocità di calcolo durante l'addestramento<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Permettono una migliore gestione del problema del vanishing gradient.<br>

<strong>Spiegazione</strong>: In order to solve the problem of the vanishing/exploding gradient, this architecture introduced the concept called <strong>Residual Blocks</strong>. In this network, we use a technique called <strong>skip connections</strong>. The skip connection connects activations of a layer to further layers by skipping some layers in between, this forms a residual block. Resnets are made by stacking these residual blocks together.<br>
<strong>Riducono il numero di parametri...</strong>: le skip connections non riducono i parametri. Il numero di parametri rimane identico (o aumenta leggermente), poiché si tratta semplicemente di una somma elemento per elemento dell'input con l'output dello strato.<br>
<strong>Evitare overfitting</strong>: Lo scopo delle skip connections non è la regolarizzazione ma l'abilitazione dell'addestramento in profondità.<br>
<strong>Miglioramento velocità di calcolo</strong>: non migliorano la velocità di calcolo, la rete è di solito più profonda e complessa.
</details>
</div>

---

<div class = "domanda1 riprendere">
26. Seleziona la sentenza corretta relativa alle <strong>Transposed Convolutions</strong>.<br>
	-Sono prevalentemente utilizzate in architetture per classificazione di immagini.<br>
	-Sono essenzialmente equivalenti all'applicazione di un livello di downsampling seguito da una convoluzione normale.<br>
	-<span class="evidenzia_risposta">Possono essere interpretate come convoluzioni normali con stride sub-unitario.</span><br>
	-Nessuna delle altre risposte è corretta.<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Possono essere interpretate come convoluzioni normali con stride sub-unitario.<br>

<strong>Spiegazione</strong>: Pensa al concetto di stride, in una convoluzione normale (stride >1) il filtro salta dei pixel e l'immagine di output diventa più piccola. Qui invece avviene il contrario, lo stride è <strong>SUB</strong>-unitario, l'algoritmo inserisce degli zeri tra i pixel dell'input e poi applica una convoluzione normale. Questo processo allarga l'immagine.<br>
<br>
A transposed convolutional layer is an upsampling layer that generates the output feature map greater than the input feature map. Transposed convolutional layers are used in a variety of tasks, including <strong>image generation, image super-resolution, and image segmentation</strong>. They are particularly useful for tasks that involve upsampling the input data, such as converting a low-resolution image to a high-resolution one or generating an image from a set of noise vectors.<br>
<br>
<strong>N.B.</strong>: Sono essenzialmente equivalenti all'applicazione di un livello di downsampling seguito da una convoluzione normale. <strong> PERCHÈ QUESTA FRASE È ERRATA?</strong> Una tecnica alternativa molto usata per sostituire le Transposed Convolutions è <strong>UPsampling</strong> + Convolution.
</details>
</div>

---

<div class = "domanda1">
27. Selezionare la sentenza <strong>SCORRETTA</strong> relativa alle <strong>Generative Adversarial Networks</strong><br>
	-Durante la fase di allenamento del Generatore i parametri del Discriminatore devono essere congelati, e viceversa<br>
	-Le GAN possono soffrire del fenomeno di "mode collapse", cioè la tendenza a focalizzare la generazione su un unico o pochi esempi<br>
	-<span class="risposta_errata">Le GANs sono utilizzate per generare attacchi ad una rete di classificazione prefissata</span><br>
	-Le GAN basano il loro training su un game tra il Generatore e il Discriminatore, dove ognuno cerca di prevalere sull'altro<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Le GANs sono utilizzate per generare attacchi ad una rete di classificazione prefissata<br>

<strong>Spiegazione</strong>: <br>
<strong>Mode collapse</strong>: In machine learning, mode collapse is a failure mode observed in generative models, originally noted in Generative Adversarial Networks (GANs). Mode collapse in Generative Adversarial Networks (GANs) can be likened to a talented artist who creates a popular artwork. After the work gains popularity, the artist may be afraid to take risks and start producing similar works. This can lead to a lack of artistic exploration and eventually bore the audience. Similarly, in GANs, mode collapse happens when the generator focuses on producing a limited set of data patterns that deceive the discriminator. It becomes fixated on a few dominant modes in the training data and fails to capture the full diversity of the data distribution.
<strong>Parametri congelati</strong>: You have to manually stop keras from training the discriminator when you train the generator - if we didn’t do this, the discriminator would learn to be more convinced by the generator every time the generator is trained, undoing anything useful it could have learned! La frase "the discriminator would learn to be more convinced by the generator" significa questo: Se tu permettessi a entrambi di imparare durante il turno del Generatore, il Discriminatore imparerebbe che per "vincere" (minimizzare l'errore in quel momento specifico) gli basta dire "Sì, è tutto vero!"<br>
<strong>Generare attacchi: perché è errata?</strong>: La frase descrive gli Adversarial Attacks, non le GANs. Il discriminatore non è prefissato, deve evolvere e imparare contemporaneamente al generatore.


</details>
</div>

---

<div class = "domanda1">
28. Selezionare la sentenza <strong>SCORRETTA</strong> relativa alla <strong>U-Net</strong><br>
	-Spesso impiegata per problemi di segmentazione semantica di immagini<br>
	-<span class="risposta_errata">Spesso utilizzata nell'ambito della classificazione dei generi musicali</span><br>
	-Usata per rimozione del rumore (denoising) di immagini<br>
	-Componente tipico dei modelli generativi a diffusione<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Spesso utilizzata nell'ambito della classificazione dei generi musicali.<br>

<strong>Spiegazione</strong>: <br>
<strong>Impiegata per segmentazione...</strong>: U-Net is a convolutional neural network that was developed for image segmentation. The network is based on a fully convolutional neural network.<br>
<strong>Denoising</strong>: The U-Net architecture has also been employed in diffusion models for iterative image denoising.<br>
<strong>Componente modelli generativi a diffusione</strong>: The U-Net architecture has also been employed in diffusion models for iterative image denoising.<br>
La U-Net è un'architettura progettata specificamente per la <strong>Segmentazione Semantica</strong> non per la <strong>Classificazione</strong>.


</details>
</div>

---

<div class = "domanda1">
29. Con <strong>modelli generativi</strong> si intende:<br>
	-L'uso di attacchi avversariali allo scopo di aumentare la robustezza dei modelli<br>
	-<span class="evidenzia_risposta">Modelli che cercano di apprendere la distribuzione di probabilità dei dati.</span><br>
	-L'applicazione di tecniche genetiche al deep learning<br>
	-Il processo di automatizzazione della generazione di reti neurali<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:Modelli che cercano di apprendere la distribuzione di probabilità dei dati.<br>

<strong>Spiegazione</strong>: A generative model is a model that tries to learn the actual distribution Pdata of real data from available samples (training set).
</details>
</div>

---

<div class = "domanda1">
30. Selezionare la sentenza <strong>SCORRETTA</strong> relativa ai <strong>modelli a diffusione</strong><br>
	-<span class="risposta_errata">Generano i risultati attraverso un processo di diffusione della informazione</span><br>
	-Tipicamente, lo spazio latente ha la stessa dimensione dello spazio visibile<br>
	-Il risultato è ottenuto attraverso passaggi multipli lungo una singola rete, tipicamente una U-net<br>
	-I modelli a diffusione iterano una operazione di denoising<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Nei modelli a diffusione ciò che viene diffuso non è l'informazione, ma il il rumore. Il modello distrugge l'informazione aggiungendo rumore (Forward Process) e poi impara a ricostruirla togliendo il rumore (Reverse/Denoising Process).<br>
<strong>Risultato ottenuto tramite U-net...</strong>: corretto, mostrato in ppt cartabinaria 07 modelli generativi ultima slide (...)<br>
<strong>Modelli a diffusione iterano operazione di denoising</strong>: as of 2024, diffusion models are mainly used for computer vision tasks, including image denoising, inpainting, super-resolution, image generation, and video generation.<br>
<strong>Spazio latente ha stessa dimensione spazio visibile</strong>: Il processo avviene trasformando progressivamente un'immagine in un'immagine di puro rumore <strong>della stessa dimensione</strong>. A differenza delle VAE, in cui si prende una immagina e la si comprime in un vettore molto piccolo.


</details>
</div>

---

<div class = "domanda1">
31. Selezionare la sentenza <strong>SCORRETTA</strong> relativa agli <strong>alberi di decisione</strong><br>
	-<span class="risposta_errata">Possono essere utilizzati solo con features discrete</span><br>
	-Costo computazionale molto basso<br>
	-Forte tendenza all'overfitting<br>
	-Possono esprimere qualunque funzione di classificazione<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Possono essere utilizzati solo con features discrete. <br>

<strong>Spiegazione</strong>: <br>
<strong>Possono esprimere qualunque funzione di classificazione</strong>: Decision Trees are a non-parametric supervised learning method used for classification and regression.


</details>
</div>

---

<div class = "domanda1">
32. Perché la tecnica <strong>Naive Bayes</strong> è detta naive?<br>
	-<span class="evidenzia_risposta">Suppone ingenuamente che le features siano indipendenti tra loro, date le classi</span><br>
	-Suppone che i dati di training rispecchino i dati reali<br>
	-Fornisce un modo semplice ma preciso di calcolare la distribuzione congiunta di probabilità delle features<br>
	-Suppone che la teoria possa avere applicazioni pratiche<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:Suppone ingenuamente che le features siano indipendenti tra loro, date le classi.<br>

<strong>Spiegazione</strong>: abbastanza straightforward
</details>
</div>

---

<div class = "domanda1">
33. Quali delle seguenti affermazioni relative alla <strong>backpropagation</strong> è corretta?<br>
	-<span class="evidenzia_risposta">Si effettua solo durante il training</span><br>
	-Viene fatta sia durante la fase di inference che quella di training<br>
	-Molto più costosa, in termini di tempo, del calcolo in avanti (inference) lungo la rete<br>
	-Effettuata unicamente lungo le skip connections delle reti residuali per evitare perdita gradiente<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:Si effettua solo durante il training<br>

<strong>Spiegazione</strong>: The backpropagation algorithm is a tool for improving the neural network during the training process.<br>
<strong>Sia durante fase di inference che training</strong>: backpropagation is only used during training. It's the mechanism that allows a neural network to learn from data. once training is done, the network switches to inference mode, where it simply makes predictions using the learned weights without adjusting them.<br>
<strong>Più costosa rispetto a inference</strong>: hanno la stessa complessità computazionale<br>
<strong>Effettuata unicamente lungo skip connection</strong>: backpropagation is a very general algorithm that can be applied <strong>ANYWHERE</strong> where there is a computation graph on which you can define gradients.
</details>
</div>

---

<div class = "domanda1">
34. Selezionare la sentenza corretta<br>
	-Numero dei parametri di un neurone artificiale è quadratico nella dimensione dei suoi inputs<br>
	-<span class="evidenzia_risposta">Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dall'applicazione di una funzione di attivazione non lineare</span><br>
	-Un neurone artificiale può apprendere qualunque funzione dei suoi input<br>
	-Un neurone può apprendere solo funzioni lineari<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dall'applicazione di una funzione di attivazione non lineare<br>

<strong>Spiegazione</strong>: <br>
<strong>Numero dei parametri quadratico...</strong>: Il numero di parametri di un singolo neurone cresce linearmente (O(n)) rispetto alla dimensione dell'input, non in modo quadratico (O(n2)). Se un neurone riceve in ingresso un vettore x di dimensione N (cioè ha N input), i suoi parametri sono: Pesi (w): un peso per ogni input. Quindi N pesi; Bias (b): un singolo valore di bias (costante) aggiunto alla somma ponderata. Totale parametri = N+1<br>
<strong>Può apprendere solo funzioni lineari</strong>: un neurone artificiale tipicamente calcola una <strong>combinazione LINEARE dei suoi input</strong>, seguita dall'<strong>applicazione di una funzione di attivazione NON LINEARE</strong>.<br><strong>N.B.</strong> un singolo neurone, anche con attivazione non lineare, può creare solo un confine di decisione lineare (una linea retta o un piano che taglia lo spazio in due). Per questo motivo, un singolo neurone non può risolvere il problema dello XOR (che non è separabile linearmente).
</details>
</div>

---

<div class = "domanda1">
35. Il problema della <strong>scomparsa del gradiente</strong> si riferisce a una progressiva diminuzione dell'intensità del gradiente, dovuta a:<br>
	-<span class="evidenzia_risposta">Backpropagation in reti profonde</span><br>
	-Dati troppo rumorosi o malamente preprocessati<br>
	-Troppi pochi dati di training a disposizione<br>
	-Training eccessivamente lungo<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Backpropagation in reti profonde<br>

<strong>Spiegazione</strong>: abbastanza straightforward
</details>
</div>

---

<div class = "domanda1">
36. Se un modello calcola una distribuzione di probabilità, aggiungere alla funzione obiettivo una <strong>componente tesa</strong> ad aumentarne l'<strong>entropia</strong> avrà effetto di:<br>
	-Contrastare fenomeno della perdita di gradiente<br>
	-Focalizzare le scelte sui casi più probabili<br>
	-Nessun effetto concreto<br>
	-<span class="evidenzia_risposta">Ridistribuire le probabilità in modo più bilanciato tra tutti i casi</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Ridistribuire le probabilità in modo più bilanciato tra tutti i casi<br>

<strong>Spiegazione</strong>: chiedere al modello di aumentare l'entropia equivale a dire: "Non essere troppo sicuro di te, considera tutte le opzioni". Massimizzare l'entropia spinge la distribuzione a diventare "piatta" (uniforme). Invece di avere un picco altissimo su una sola risposta, il modello abbassa quel picco e alza le probabilità delle altre opzioni, rendendo tutto più bilanciato. <br>
<strong>Focalizzare le scelte sui casi più probabili</strong>: è l'esatto opposto<br>
<strong>N.B.</strong> non c'entra nulla con la perdita del gradiente.
</details>
</div>

---

<div class = "domanda1">
37. La derivata della <strong>funzione logistica</strong> &sigma;(x) è:<br>
	- &sigma; (<i>x</i>) /  &sigma; (1 - <i>x</i>)<br>
	- <span class="evidenzia_risposta">&sigma; (<i>x</i>) * (1 - &sigma; (<i>x</i>))</span><br>
	- &sigma; (<i>x</i>) / (1 - &sigma;(<i> x</i>))<br>
	- &sigma; (<i>x</i>) * &sigma;(1- <i> x</i>)<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: &sigma;(x) * (1 - &sigma;(x))<br>

<strong>Spiegazione</strong>: abbastanza straightforward
</details>
</div>
$$\sigma(x) \cdot (1 - \sigma(x))$$
---

<div class = "domanda1 riprendere">
38. Selezionare la sentenza <strong>ERRONEA</strong> relativa alla <strong>crossentropy</strong> H(P,Q) tra P e Q:<br>
	-È uguale alla divergenza di Kullback-Leibler KL(P,Q) più l'entropia H(P) di P<br>
	-Misura la loglikelihood di Q data la distribuzione P<br>
	-Ha un valore minimo quando P = Q<br>
	-<span class="risposta_errata">È una funzione simmetrica H(P,Q) = H(Q,P)</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: È una funzione simmetrica H(P,Q) = H(Q,P)<br>

<strong>Spiegazione</strong>: P e Q hanno ruoli fissi e diversi: P è la distribuzione reale dei dati (il "Ground Truth"). Es: Questa immagine è un GATTO al 100%. Q è quello che pensa il modello. Es: Il modello pensa che sia un GATTO al 70% e un CANE al 30%.<br>

</details>
</div>

$$
\text{1. Definizione Generale Cross-Entropy} \\
H(P, Q) = - \sum_{x} P(x) \cdot \log(Q(x))
$$

$$
\text{2. Relazione con KL Divergence} \\
H(P, Q) = H(P) + KL(P||Q)
$$

$$
\text{3. Identità Completa (Entropia + KL)} \\
\mathcal{H}(P, Q) = - \sum_{i} P(i) \log Q(i) = \mathcal{H}(P) + D_{KL}(P||Q)
$$

$$
\text{4. Binary Cross-Entropy (Log Loss)} \\
L = - [ y \cdot \log(Q) + (1-y) \cdot \log(1-Q) ]
$$

---

<div class = "domanda1">
39. Selezionare la sentenza corretta relativa alla <strong>distribuzione congiunta</strong> di probabilità.<br>
	-Non permette calcolo di eventi condizionali<br>
	-Non permette di fare alcun tipo di predizione<br>
	-Non consente una visione distinta delle singole features<br>
	-<span class="evidenzia_risposta">Il suo calcolo presenta problemi di scalabilità all'aumentare delle features</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Il suo calcolo presenta problemi di scalabilità all'aumentare delle features<br>

<strong>Spiegazione</strong>: La distribuzione congiunta è una tabella che contiene le probabilità di tutte le possibili combinazioni di variabili. Il problema è che questa tabella cresce in modo esponenziale (<strong>curse of dimensionality</strong>).<br>
<strong>Non permette calcolo eventi condizionali</strong>: falso, <i>P(A|B)=(P(A,B)) / P(B)</i><br>
<strong>Non consente visione distinta delle singole features</strong>: falso, marginalizazzione.
</details>
</div>

---
@
<div class = "domanda1">
40. Ci sono due dadi, uno normale e uno truccato che restituisce un 6 con probabilità 0.5 e gli altri valori con probabilità 0.1. Faccio due lanci con lo stesso dado e osservo un 3 e un 6. Cosa posso concludere?<br>
	-È più probabile che il dado sia normale<br>
	-Nulla<br>
	-<span class="evidenzia_risposta">È più probabile che il dado sia truccato</span><br>
	-La probabilità di usare l'uno o l'altro dei dadi è la stessa<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: È più probabile che il dado sia truccato.<br>

<strong>Spiegazione</strong>: stesso ragionamento domanda 8
</details>
</div>

$$ P(\text{Scenario A}) + P(\text{Scenario B}) $$

---

<div class = "domanda1">
41. Il range dell'entropia per la distribuzione di una probabilità di una variabile aleatoria discreta è:<br>
	-Tra 0 e 1<br>
	-<span class="evidenzia_risposta">Tra 0 e log n dove n sono i possibili valori di X</span><br>
	-Tra 0 e infinito<br>
	-Tra -1 e 1<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Tra 0 e log n dove n sono i possibili valori di X<br>

<strong>Spiegazione</strong>: abbastanza straightforward
</details>
</div>

$$H(X) = - \sum_{i=1}^{n} P(X=i)\log_2 P(X=i)$$
---
@
<div class = "domanda1 riprendere">
42. Selezionare la sentenza <strong>SCORRETTA</strong> riguardo alla <strong>regressione logistica</strong><br>
	-Si basa su una combinazione lineare delle features di input<br>
	-Probabilità della predizione cresce se ci si allontana dalla superficie di confine tra le classi<br>
	-<span class="risposta_errata">Non dipende dal bilanciamento dei dati di training rispetto alle classi</span><br>
	-Nel caso di classificazione binaria la superficie di confine tra le classi è un iperpiano<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Non dipende dal bilanciamento dei dati di training rispetto alle classi. 
questo perché se tu dovessi addestrare il modello su dei dati molto sbilanciati (900 dati di una classe e 100 di un'altra), capisce che rispondendo sempre in un certo modo (rispondendo con un dato fra quei 900) avrà ragione e a quel punto sposterà il bias per favorire la classe con il maggior numero di dati
<br>

<strong>Spiegazione</strong>: La regressione logistica soffre moltissimo se i dati sono sbilanciati.<br>
<strong>Si basa su combinazione lineare</strong>: corretto, si basa su calcolo lineare a cui poi viene applicata la sigmoide. (...)<br>
<strong>Probabilità della predizione cresce</strong>...: corretto, sul confine la probabilità è 0.5 (massima incertezza). Più ci si allontana dal confine, più la sigmoide spinge la probabilità verso 1 o verso 0.<br>
<strong>Superficie tra le classi è iperpiano</strong>...: no curve complesse (...)


</details>
</div>

---

<div class = "domanda1">
43. In quale di questi casi la <strong>regressione logistica</strong> potrebbe essere in difficoltà<br>
	-Quando non tutte le features di input sono rilevanti ai fini della classificazione<br>
	-Quando esiste elevata correlazione tra le features<br>
	-<span class="evidenzia_risposta">Quando classificazione dipende da un confronto tra le features</span><br>
	-Quando le features sono indipendenti tra loro, data la classe<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Quando classificazione dipende da un confronto tra le features
Questo perché la regressione logistica valuta una determinata feature indipendentemente da un'altra. Qui si tratta di sommare le varie feature, moltiplicate per i loro rispettivi pesi
<br>

<strong>Spiegazione</strong>: La Regressione Logistica è un classificatore Lineare. La sua formula è una somma: w1​x1​+w2​x2​+... Questo significa che valuta ogni feature singolarmente e somma i punteggi. Se la soluzione del problema richiede di "confrontare" le feature tra loro (interazioni), la Regressione Logistica fallisce perché non è capace di capire le relazioni complesse senza aiuto. (...) <br>
<strong>Correlazione tra features</strong>: caso meno grave
</details>
</div>

---

<div class = "domanda1">
44. Riguardo alla  <strong>regressione multinomiale</strong> selezionare la sentenza <strong>SCORRETTA</strong> tra le seguenti:<br>
	-Il peso con cui è valutata ogni feature è tipicamente diverso per ogni classe<br>
	-Il peso delle features indica la loro importanza ai fini della classificazione<br>
	-Per <i>n</i> features di input e <i>m</i> classi, il numero dei parametri del modello è <i> n x m + m</i><br>
	-<span class="risposta_errata">Per ogni input esiste almeno una classe con probabilità >0.5</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Per ogni input esiste almeno una classe con probabilità >0.5<br>

<strong>Spiegazione</strong>: Pensa a una torta, se le classi sono due allora è possibile, altrimenti no.<br>
<strong>Peso diverso per ogni classe</strong>...: corretto, se si deve distinguere un "Gatto" da una "Auto", la caratteristica "ha il pelo" avrà un peso molto alto (positivo) per la classe Gatto, ma un peso basso o negativo per la classe Auto.<br>
<strong>Peso delle features indica la loro importanza</strong>...: Nelle regressioni lineari/logistiche, più un peso è alto (in valore assoluto), più quella feature influenza la decisione finale. È l'indice di quanto quella caratteristica conta.<br>
<strong>Per n features di input</strong>...: Ho m classi. Per ogni classe serve un set di pesi per le n feature (n×m). Per ogni classe serve anche un bias (l'intercetta)(m). Totale: <i>(n×m)+m</i>.

</details>
</div>

---

<div class = "domanda1">
45. Selezionare la sentenza <strong>SCORRETTA</strong> riguardo alla funzione <strong>softmax</strong><br>
	-<span class="risposta_errata">Produce valori compresi nell'intervallo[-1, 1]</span><br>
	-Generalizza la funzione logistica al caso multiclasse<br>
	-Per un dato input, la somma dei suoi valori su tutte le classi è sempre 1<br>
	-Permette di calcolare una distribuzione di probabilità sulle classi<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Produce valori compresi nell'intervallo[-1, 1]<br>

<strong>Spiegazione</strong>: Softmax produce probabilità, la probabilità non può mai essere negativa.<br>
<strong>Calcolare distribuzione di probabilità</strong>...: Softmax converts a vector of raw scores into a probability distribution<br>
<strong>Per dato input somma dei suoi valori</strong>...: Softmax prende punteggi grezzi, li rende positivi e li normalizza. (Pensa sempre a esempio torta, se metto insieme tutte le fette da capo, avrò nuovamente 1)

</details>
</div>

---

<div class = "domanda1 riprendere">
46. Cosa si intende per tecniche discriminative?<br>
	-Tecniche tipiche di unsupervised learning che tentano di separare i dati in clusters distinti<br>
	-<span class="evidenzia_risposta">Tecniche di classificazione che si focalizzano sulla definizione delle frontiere di decisione (decision boundaries)</span><br>
	-Tecniche che cercano di discriminare i dati in base alle diverse distribuzioni di probabilità delle varie classi<br>
	-Tecniche che cercando di identificare gli outliers all'interno del data set<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Tecniche di classificazione che si focalizzano sulla definizione delle frontiere di decisione (decision boundaries)<br>

<strong>Spiegazione</strong>: (...)
</details>
</div>

---

<div class = "domanda1">
47. AlexNet, la prima rete convoluzionale profonda vincitrice della ImageNet competition è stata realizzata in quale anno:<br>
	-<span class="evidenzia_risposta">2012</span><br>
	-1993<br>
	-1971<br>
	-2019<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 2012 <br>

<strong>Spiegazione</strong>: abbastanza straightforward
</details>
</div>

---

<div class = "domanda1">
48. Il campo ricettivo di un neurone di una CNN dipende da:<br>
	-<span class="evidenzia_risposta">Profondità del layer in cui si trova il neurone e le dimensioni e gli strides del kernel dei layers precedenti</span><br>
	-Profondità del layer in cui si trova il neurone e le dimensioni dei kernel dei layers precedenti, ma non dai loro strides<br>
	-La dimensione del kernel e il numero dei canali del layer in cui si trova il neurone<br>
	-Unicamente dalla profondità del layer a cui si trova il neurone<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Profondità del layer in cui si trova il neurone e le dimensioni e gli strides del kernel dei layers precedenti.<br>

<strong>Spiegazione</strong>: The receptive field of a (deep, hidden) neuron is the dimension of the input region influencing it.<br>
<strong>Come viene ampliato il campo?</strong> <br>
A neuron cannot see anything outside its receptive field! We may also rapidly enlarge the receptive fields by means of downsampling layers, e.g. pooling layers or convolutional layers with non-unitarian stride. Questo implica profondità, uso di kernel dai layers precedenti + stride
</details>
</div>

---

<div class = "domanda1">
49. Quale delle seguenti sentenze relative agli <strong>autoencoders</strong> è corretta?<br>
	-Richiedono l'uso di livelli densi<br>
	-Encoder e decoder devono essere strettamente simmetrici<br>
	-<span class="evidenzia_risposta">La rappresentazione interna prodotta dall'encoder abitualmente ha una dimensione ridotta rispetto a quella di partenza</span><br>
	-Rete neurale che codifica se stessa<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: La rappresentazione interna prodotta dall'encoder abitualmente ha una dimensione ridotta rispetto a quella di partenza <br>

<strong>Spiegazione</strong>: Un autoencoder è un tipo di architettura di rete neurale progettata per comprimere (codificare) in modo efficiente i dati di input fino alle caratteristiche essenziali, quindi ricostruire (decodificare) l'input originale a partire da questa rappresentazione compressa. <br>
Immagina di dover trasmettere un'immagine complessa a un amico, ma puoi usare solo 10 parole. Non puoi descrivere ogni singolo pixel. Devi per forza dire cose come "è un gatto rosso che dorme sul divano". Riducendo la dimensione (il bottleneck), costringi l'encoder a scartare i dettagli inutili (rumore) e a estrarre solo le caratteristiche (features) più importanti e significative.<br>
<br>
<strong>Encoder e decoder simmetrici</strong>...: (If your decoder is too powerful and you have a VAE the decoder might choose to ignore the latent codes entirely ... ). Se il decoder è enorme e potente, potrebbe memorizzare le mappature senza che l'encoder debba fare un buon lavoro di compressione. Altro problema presente nei Variational Autoencoder: Posterior Collapse.<br>
<strong>Uso di livelli densi</strong>...: Non richiedono solamente livelli densi. Simple autoencoders can be made using fully connected layers only, but you can also use other layers (convolution layers, for example, to make convolutional autoencoders).
</details>
</div>

---

<div class = "domanda1">
50. Quale è la tipica struttura di una <strong>rete neurale</strong> per la <strong>classificazione di immagini</strong>?<br>
	-Solo livelli densi<br>
	-Un encoder, seguito da un decoder<br>
	-<span class="evidenzia_risposta">Sequenza alternata di convoluzioni e downsampling, seguita da flattening e pochi livelli densi finali</span><br>
	-Sequenza di convoluzioni che preservano la dimensione spaziale dell'input<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Sequenza alternata di convoluzioni e downsampling, seguita da flattening e pochi livelli densi finali<br>

<strong>Spiegazione</strong>: A Neural Network for image processing has a structure of the
following kind: a long sequence of convolutional layers, possibly organized in suitable modules (e.g. inception modules) and a short (2 or 3) final sequence of dense layers.
</details>
</div>

![[Screenshot 2025-11-26 alle 13.55.49.png]]

---

<div class = "domanda1 riprendere">
51. Selezionare la sentenza corretta relativa alla tecnica a <strong>discesa del gradiente</strong><br>
	-Permette sempre di individuare il minimo globale, se questo esiste<br>
	-Risultato non dipende dall'inizializzazione dei parametri del modello<br>
	-Può essere applicata solo se la funzione da minimizzare ha una superficie concava<br>
	-<span class="evidenzia_risposta">Potrebbe convergere a un minimo locale</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Potrebbe convergere a un minimo locale<br>

<strong>Spiegazione</strong>: L’algoritmo può convergere a un minimo locale anziché a un minimo globale, soprattutto se la funzione di costo è non convessa. <br>
<br>
https://www.gironi.it/blog/lalgoritmo-di-discesa-del-gradiente-gradient-descent-spiegato-semplice/<br>
<br>
<strong>Permette sempre di individuare minimo globale</strong>...: scorretto, discesa del gradiente è algoritmo miope, per le reti neurali multistrato la superficie di errore può essere molto complicata e piena di minimi locali. Se l'algoritmo inizia la discesa vicino a un minimo locale, finirà lì dentro e non sarà in grado di risalire per trovare il minimo globale. <br>
(...)
</details>
</div>

---

<div class = "domanda1">
52. Qual è l'effetto di uno <strong>stride non unitario</strong> (>1) in un layer convolutivo?<br>
	-<span class="evidenzia_risposta">La dimensione spaziale diminuisce</span><br>
	-Nessun effetto spaziale, il numero dei canali decresce<br>
	-La dimensione spaziale aumenta<br>
	-Nessun effetto spaziale, il numero dei canali aumenta<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: La dimensione spaziale diminuisce <br>

<strong>Spiegazione</strong>:<br>
<strong>Stride</strong>: movement of the linear filter. With a <strong>low stride</strong> (e.g.unitary) receptive fields largely overlap. With a <strong>higher stride</strong>, we have less overlap and the dimension of the output get smaller (lower sampling rate).
</details>
</div>

![[Screenshot 2025-11-27 alle 15.16.33.png|352x267]]

---

<div class = "domanda1">
53. Selezionare la sentenza corretta<br>
	-Una GAN è una rete che permette di generare attacchi per un qualunque modello predittivo<br>
	-Le GAN hanno una struttura encoder-decoder, simile a quella di un autoencoder<br>
	-<span class="evidenzia_risposta">Le GAN possono soffrire del fenomeno di "mode-collapse", cioè la tendenza a focalizzare la generazione su un unico o pochi esempi</span><br>
	-Le GAN basano il loro training su una funzione di loglikelihood relativa ai dati generali<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Le GAN possono soffrire del fenomeno di "mode-collapse", cioè la tendenza a focalizzare la generazione su un unico o pochi esempi<br>

<strong>Spiegazione</strong>:<br>
<strong>Struttura encoder-decoder</strong>...: errato, le Variational Autoencoders hanno una struttura così<br>
<strong>Training basato su funzione di loglikelihood</strong>...: errato, il training delle GAN si basa su un discriminatore (che cerca di massimizzare capacità di distinguere vero dal falso) e generatore (che cerca di ingannare discriminatore e minimizzare capacità di distinzione tra vero e falso)<br>
<strong>Generare attacchi per qualunque modello predittivo</strong>...: errato, scopo GAN è modellazione generativa. Though originally proposed as a form of generative model for unsupervised learning, GANs have also proved useful for semi-supervised learning,[2] fully supervised learning, and reinforcement learning (...)

</details>
</div>

---
controlla la definizione
<div class = "domanda1">
54. I <strong>Long-Short Term Memory Models</strong> (LSTMs) sono modelli utilizzati prevalentemente per:<br>
	-Segmentazione immagini mediche<br>
	-<span class="evidenzia_risposta">Elaborazione di sequenze di dati</span><br>
	-Predire traiettorie per agenti a guida autonoma<br>
	-Elaborazione di immagini<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Elaborazione di sequenze di dati<br>

<strong>Spiegazione</strong>: una rete a lunga memoria a breve termine (Long Short-Term Memory o LSTM) è un tipo di rete neurale ricorrente (RNN). Le LSTM sono prevalentemente usate per apprendere, elaborare e classificare dati sequenziali in quanto sono in grado di apprendere le dipendenze a lungo termine tra fasi temporali di dati. <br>
<br>
Un'unità LSTM è composta tipicamente da una cella e tre porte: una di input, una di output e una di oblio. La cella ricorda valori a intervalli di tempo arbitrari e le porte regolano il flusso di informazioni in entrata e in uscita dalla cella. Le porte di oblio decidono quali informazioni scartare dallo stato precedente, mappando lo stato precedente e l'input corrente su un valore compreso tra 0 e 1. Un valore (arrotondato) di 1 indica la conservazione delle informazioni, mentre un valore di 0 rappresenta l'eliminazione. Le porte di input decidono quali nuove informazioni memorizzare nello stato corrente della cella, utilizzando lo stesso sistema delle porte di oblio. Le porte di output controllano quali informazioni nello stato corrente della cella emettere, assegnando un valore da 0 a 1 alle informazioni, considerando lo stato precedente e quello corrente. L'emissione selettiva di informazioni rilevanti dallo stato corrente consente alla rete LSTM di mantenere dipendenze utili a lungo termine per effettuare predizioni, sia al passo corrente sia in quelli futuri. 

</details>
</div>

---

<div class = "domanda1">
55. Quale <strong>funzione di loss</strong> è tipicamente utilizzata per una rete neurale per classificazione a categorie multiple che utilizza softmax come attivazione finale?<br>
	-Binary crossentropy<br>
	-<span class="evidenzia_risposta">Categorical crossentropy</span><br>
	-Absolute error<br>
	-Mean squared error<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Categorical crossentropy<br>

<strong>Spiegazione</strong>: Richiesta di una funzione di loss per una rete che fa classificazione a categorie multiple (<strong> multinomial regression </strong>) e usa <strong>softmax</strong>. 


</details>
</div>

---

<div class = "domanda1">
56. Quali delle seguenti tecniche <strong>NON</strong> può essere usata per contrastare <strong>overfitting</strong>?<br>
	-Early stopping<br>
	-Data augmentation<br>
	-Introduzione di dropout layers<br>
	-<span class="risposta_errata">Aggiunta di skip connections</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Aggiunta di skip connections<br>

<strong>Spiegazione</strong>: early stopping, dropout layers, data augmentation (it helps to prevent overfitting by providing the model with more data to learn from) sono tutte tecniche che CONTRASTANO overfitting. 
La tecnica dropout layer, consiste nello "spegnere" momentaneamente determinati neuroni per far trovare al modello nuovi cammini e dargli la possibilità di ragionare in modo migliore

</details>
</div>

---

<div class = "domanda1 riprendere">
57. Il numero dei parametri di un <strong>layer convolutivo</strong> dipende da:<br>
	-Unicamente dalle dimensioni dei layers di input e output<br>
	-Lo stride del kernel e tutte le dimensioni di input e output, compresi i canali<br>
	-<span class="evidenzia_risposta">La dimensione spaziale del kernel e il numero dei canali di input e output</span><br>
	-Lo stride del kernel e le dimensioni spaziali di input e output<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: la dimensione spaziale del kernel e il numero dei canali di input e output<br>

<strong>Spiegazione</strong>:  kernel size: the dimension of the linear filter,
stride: movement of the linear filter
padding Artificial enlargement of the input to allow the
application of filters on borders
depth: number of features maps 

</details>
</div>

---

<div class = "domanda1">
58. Quale tra i seguenti è un tipico campo di applicazione della <strong>U-Net</strong>?<br>
	-<span class="evidenzia_risposta">Segmentazione semantica</span><br>
	-Generazione musicale<br>
	-Object detection<br>
	-Natural language processing<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Segmentazione semantica<br>

<strong>Spiegazione</strong>: U-Net is a convolutional neural network that was developed for image segmentation. The network is based on a fully convolutional neural network.


</details>
</div>

---

<div class = "domanda1">
59. Selezionare la risposta <strong>SCORRETTA</strong> relativa alla <strong>Mutua Informazione</strong> I(X,Y) tra due variabili aleatorie X e Y (anche detta Information Gain nel contesto degli Alberi di Decisione)<br>
	-Funzione simmetrica: I(X,Y) = I(Y,X)<br>
	-<span class="risposta_errata">Coincide con l'entropia H(Y|X) di Y dato X</span><br>
	-Può essere utilizzata per guidare la selezione degli attributi durante la costruzione di un albero di decisione<br>
	-Misura il guadagno di informazione su Y dopo aver osservato X<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Coincide con l'entropia H(Y|X) di Y dato X<br>

<strong>Spiegazione</strong>: Entropia = quantità di incertezza che ho su una decisione.<br>
Situazione Iniziale (H(Y)): Devo indovinare se domani piove (Y). Massima incertezza. Questa è l'entropia iniziale.<br>
L'indizio (X): Qualcuno dice: "Domani è nuvoloso" (X). <br>
Situazione dopo l'indizio (H(Y|X)): Ora ho ancora un po' di dubbio (potrebbe piovere o no), ma sono meno confuso di prima. Questa nuova incertezza ridotta è l'entropia condizionata, H(Y|X) (l'incertezza di Y dato che conosco X).<br>
Il Guadagno (I(X,Y)): L'Information Gain (Mutua Informazione) è: "Quanta confusione ho eliminato grazie all'indizio?". Matematicamente è la sottrazione tra l'incertezza di prima e quella di adesso.


</details>
</div>


$$\text{Guadagno} = \text{Incertezza}_{\text{Prima}} - \text{Incertezza}_{\text{Dopo}}$$
$$I(X,Y) = H(Y) - H(Y|X)$$
$$ \text{Simmetria: }I(X,Y)=H(X)−H(X∣Y)=H(Y)−H(Y∣X)$$
---

<div class = "domanda1 riprendere">
60. Il tensore di input di un <strong>layer convolutivo</strong> 2D ha dimensione (32,32,8). Sintetizzo un unico kernel con dimensione spaziale (4,4), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell'output?<br>
	-(16,16,1)<br>
	-(16,16,8)<br>
	-(15,15,8)<br>
	-<span class="evidenzia_risposta">(15, 15,1)</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: (15, 15,1)<br>

<strong>Spiegazione</strong>: 

</details>
</div>
$$\text{Output} = \frac{W + P - K}{S} + 1$$
---

<div class = "domanda1 riprendere">
61. Quale è la derivata della funzione di <strong>MaxPooling</strong>?<br>
	-Identità<br>
	-Non è derivabile<br>
	-<span class="evidenzia_risposta">1 in corrispondenza del massimo e 0 altrove</span><br>
	-1 ovunque<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 1 in corrispondenza del massimo e 0 altrove<br>

<strong>Spiegazione</strong>: Max pooling is a pooling operation that selects the maximum element from the region of the feature map covered by the filter. <br>
Quando si calcola il gradiente (la derivata) per tornare indietro (Backpropagation):<br>
La rete si chiede: "Chi ha contribuito a questo output?"<br>
Solo il "vincitore" (il massimo) ha contribuito. Gli altri numeri sono stati ignorati<br>
Di conseguenza, il gradiente passa integralmente (1) attraverso la posizione del massimo e viene bloccato (0) per tutte le altre posizioni che non erano il massimo.<br>È una sorta di interruttore, 1 per il valore più alto, 0 per gli altri (...)
</details>
</div>

---

<div class = "domanda1">
62. Selezionare la risposta <strong>ERRATA</strong> relativa alla <strong>derivata della funzione logistica</strong><br>
	-<span class="risposta_errata">È una funzione monotona</span><br>
	-Tende a 0 quando X tende a meno infinito<br>
	-Ha il suo massimo in corrispondenza dello 0<br>
	-<span class="risposta_errata">È una funzione simmetrica</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:è una funzione simmetrica, è una funzione monotona<br>

<strong>Spiegazione</strong>: letteralmente guarda l'immagine


</details>
</div>

![[Screenshot 2025-11-26 alle 16.44.21.png]]


---
<div class = "domanda1">
63. Selezionare la risposta <strong>ERRATA</strong> relativa all' <strong>apprendimento supervisionato</strong><br>
	-<span class="risposta_errata">Richiede costante supervisione di un esperto durante il training</span><br>
	-Può comprendere sia problemi di regressione che di classificazione<br>
	-Si riferisce all'apprendimento di funzioni basato su esempi di training composti da coppie input-output<br>
	-La definizione della ground truth può richiedere l'intervento umano ed essere onerosa<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: richiede costante supervisione di un esperto durante il training<br>

<strong>Spiegazione</strong>: 
<strong>Ground truth</strong>...: corretto, building supervised training sets is expensive, since it requires a complex human operation to create ground truth annotations.<br>
<strong>Problemi di regressione e classificazione</strong>...: corretto, presente nella "definizione" slide iniziali.



</details>
</div>

---
 
 <div class = "domanda1">
64. Selezionare la risposta <strong>CORRETTA</strong> relativa alla <strong>regressione multinomiale</strong><br>
	-Per n features di input e m classi, il numero dei parametri del modello cresce come O(n+m)<br>
	-<span class="evidenzia_risposta">Il peso con cui è valutata ogni feature è tipicamente diverso per ogni classe</span><br>
	-I pesi delle features sono sempre tutti positivi, i bias possono essere negativi<br>
	-Per ogni input esiste esiste almeno una classe con probabilità >0.5 <br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Il peso con cui è valutata ogni feature è tipicamente diverso per ogni classe.<br>

<strong>Spiegazione</strong>: <br>
<strong>Come cresce il numero dei parametri del modello</strong>: <i>n x m + m</i><br>
<strong>Pesi delle features</strong>...:il peso w associato a una feature x indica la direzione e l'intensità della relazione tra quella feature e la classe target. Possono essere positivi, negativi o pari a zero.


</details>
</div>

---

<div class = "domanda1">
65. Selezionare la risposta <strong>CORRETTA</strong> relativa alla <strong>funzione softmax</strong><br>
	-Non può essere utilizzata nel caso di una classificazione binaria<br>
	-<span class="evidenzia_risposta">Restituisce una distribuzione di probabilità sulle classi</span><br>
	-Per una data classe, la somma dei valori su tutti gli input di un minibatch è sempre 1<br>
	-Produce valori compresi nell'intervallo [-1, 1]<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Restituisce una distribuzione di probabilità sulle classi<br>

<strong>Spiegazione</strong>: <br>
<strong>Produce valori compresi tra [-1, 1]</strong>: errato, softmax produce probabilità, la probabilità non può mai essere negativa.<br>
<strong>Somma dei valori su tutti gli input</strong>...: Per un dato input, la somma dei suoi valori su tutte le classi è sempre 1 !!!<br>
<strong>Classificazione binaria</strong>: La funzione softmax è usata in vari metodi di classificazione multi-classe, come la regressione logistica multinomiale, analisi discriminante lineare multiclasse, classificatori bayesiani e reti neurali artificiali.

per una data classe tu hai che la somma delle probabilità che le features siano una determinata classe deve fare 1. Per esempio tu hai un'immagine (la tua feature) e devi classificare se è l'immagine di un topo, di un cane o di un gatto. Ecco la probabilità che la feature sia un gatto, sommata alla probabilità che sia un cane o un topo deve fare 1!



</details>
</div>


---

<div class = "domanda1">
66. In quali di questi casi una tecnica di <strong>classificazione lineare</strong> potrebbe non fornire risultati soddisfacenti<br>
	-<span class="evidenzia_risposta">Quando la classificazione dipende da un confronto tra le features</span><br>
	-Quando esiste una elevata correlazione tra le features<br>
	-Quando non tutte le features di input sono rilevanti ai fini della classificazione<br>
	-Quando le feature sono indipendenti tra loro, data la classe<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Quando la classificazione dipende da un confronto tra le features. <br>

<strong>Spiegazione</strong>: Un classificatore lineare funziona tracciando una linea retta per separare le classi. La sua equazione è una somma pesata: y=w1 x1 +w2 x2 +b. Questo modello presuppone che ogni caratteristica (x1, x2 ) contribuisca al risultato in modo indipendente e additivo. Quando la risposta dipende da un "confronto" o da una interazione complessa tra le feature (problema dello XOR), la relazione diventa non lineare.





</details>
</div>

---

<div class = "domanda1 riprendere">
67. Selezionare la sentenza <strong>CORRETTA</strong> relativa alle <strong>tecniche discriminative</strong><br>
	-Cercano di determinare le distribuzioni di probabilità delle varie classi di dati<br>
	-<span class="evidenzia_risposta">Si focalizzano sulla definizione delle frontiere di decisione (decision boundaries)</span><br>
	-Si applicano per lo più in ambito di apprendimento non supervisionato<br>
	-Sono tipicamente meno espressive delle tecniche generative<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Si focalizzano sulla definizione delle frontiere di decisione (decision boundaries). <br>

<strong>Spiegazione</strong>: Si focalizzano sulla definizione delle frontiere di decisione (decision boundaries) (...)


</details>
</div>

---

<div class = "domanda1">
68. Selezionare la risposta <strong>ERRATA</strong> relativa alla funzione <strong>ReLu(x)</strong><br>
	-Lei o le sue varianti sono tipicamente utilizzate per i livelli interni delle reti neurali profonde<br>
	-La sua derivata è una funzione a gradino<br>
	-È una funzione monotona non decrescente<br>
	-<span class="risposta_errata">Non può essere utilizzata per layer convoluzionali</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Non può essere utilizzata per layer convoluzionali. <br>

<strong>Spiegazione</strong>: In realtà, la ReLU È la funzione standard utilizzata nei layer convoluzionali (CNN). La struttura classica di una rete per immagini è quasi sempre: Convoluzione -> ReLU -> Pooling. <br>
<strong>Utilizzo nei livelli interni</strong>...: risolve vanishing gradient problem e efficienza computazionale. 



</details>
</div>

![[Screenshot 2025-11-27 alle 14.34.10.png|294x156]]

![[Code_Generated_Image.png|302x227]]

---

<div class = "domanda1">
69. Selezionare la risposta <strong>SCORRETTA</strong> relativa agli <strong>autoencoders</strong><br>
	-Possono essere utilizzati per la rimozione del rumore (denoising)<br>
	-La rappresentazione interna prodotta dall'encoder abitualmente ha una dimensione ridotta rispetto a quella di partenza <br>
	-L'encoder e il decoder non devono essere necessariamente simmetrici<br>
	-<span class="risposta_errata">Gli autoencoders richiedono l'uso di livelli densi</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Gli autoencoders richiedono l'uso di livelli densi<br>

<strong>Spiegazione</strong>: gli autoencoders POSSONO usare livelli densi. Però per compiti come l'elaborazione di immagini, si utilizzano comunemente i <strong>Convolutional Autoencoders</strong>, composti da livelli convoluzionali.



</details>
</div>

---

<div class = "domanda1 riprendere">
70. Selezionare la risposta <strong>SCORRETTA</strong> relativa alla <strong>backpropagation</strong> per reti neurali<br>
	-Richiede la memorizzazione delle attivazioni di tutti i neuroni della rete durante la forward pass<br>
	-Ha un costo computazionale paragonabile a quello del calcolo in avanti (inference) lungo la rete <br>
	-<span class="risposta_errata">Si basa principalmente su algoritmi di tipo generico</span><br>
	-Tipicamente si effettua solo durante la fase di training della rete<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Si basa principalmente su algoritmi di tipo genetico<br>

<strong>Spiegazione</strong>: algoritmi di tipo genetico vengono usati per ingannare la rete (black box), non per l'addestramento standard tramite backpropagation.<br>
<strong>Memorizzazione delle attivazioni</strong>...: Poiché la backpropagation avviene andando all'indietro (dall'output all'input), per calcolare questa formula è necessario aver memorizzato il valore Al−1​ che era stato calcolato durante il passaggio in avanti (...)


</details>
</div>

---

<div class = "domanda1">
71. Selezionare la risposta <strong>SCORRETTA</strong> relativa al <strong>campo ricettivo</strong> di un neurone di una CNN<br>
	-Definisce la porzione dell'input che influenza l'attivazione di un determinato neurone<br>
	-Dipende dalla profondità del layer in cui si trova il neurone e dalle dimensioni e gli strides dei kernel dei layers precedenti<br>
	-<span class="risposta_errata">E' sempre almeno pari alla dimensione spaziale del dato di input</span><br>
	-Aumenta rapidamente con l'attraversamento di livelli con downsampling<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:E' sempre almeno pari alla dimensione spaziale del dato di input. <br>

<strong>Spiegazione</strong>: Nei primi livelli della rete, il campo ricettivo è molto piccolo (pari alla dimensione del kernel, es. 3x3 o 5x5), quindi è molto più piccolo della dimensione dell'input (che potrebbe essere un'immagine intera). Diventa grande quanto l'input solo se la rete è abbastanza profonda. <br>
<strong>Porzione dell'input</strong>...: receptive field corresponds to the dimension of the input region influencing it.<br>
<strong>Dipende da profondità dei layers</strong>...: By stacking kernels we enlarge their receptive fields. Quindi dipende dalla profondità (stacking) e dalle dimensioni dei kernel precedenti.<br>
<strong>Aumenta con attraversamento</strong>...: We may also rapidly enlarge the receptive fields by means of downsampling layers. 


</details>
</div>

---

<div class = "domanda1">
72. Il tensore di input di un layer convolutivo 2D ha dimensione (16,16,32). Sintetizzo 8 kernel con dimensione spaziale (3,3), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell'output?<br>
	-(7, 7, 15)<br>
	-(8, 8, 8)<br>
	-<span class="evidenzia_risposta">(7, 7, 8)</span><br>
	-(8, 8, 32)<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: (7,7,8)<br>

<strong>Spiegazione</strong>: <br>
La profondità dell'output non dipende dalla dimensione dell'input, ma dal numero di kernel (filtri) che vengono applicati. Feature maps produced by different kernels are stacked along the channel dimension.<br>
Il testo dice: "Sintetizzo 8 kernel", di conseguenza la profondità dell'output sarà 8.
<strong>N.B.</strong>: The dimension of the output only depends from the number of
times the kernel is applied.

</details>
</div>

$$\text{Output} = \frac{W + P - K}{S} + 1$$
---

<div class = "domanda1">
73. Selezionare la risposta <strong>SCORRETTA</strong> relativa alla tecnica<strong> a discesa del gradiente</strong><br>
	-Potrebbe convergere a un minimo locale<br>
	-<span class="risposta_errata">Può essere applicata solo se la funzione da minimizzare ha superficie concava</span><br>
	-Il risultato può dipendere dall'inizializzazione dei parametri del modello<br>
	-È opportuno decrementare il learning rate verso la fine dell'apprendimento<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Può essere applicata solo se la funzione da minimizzare ha superficie concava<br>

<strong>Spiegazione</strong>: riguardo alla regressione logistica "the error surface is convex" (la superficie di errore è convessa, a forma di ciotola). Una superficie concava (a forma di collina o arco) non avrebbe un minimo verso cui scendere, ma andrebbe verso −∞.<br>
<strong>Converge a un minimo locale</strong>: Le superfici di errore complesse hanno molti minimi locali<br>
<strong>Risultato dipende da inizializzazione dei parametri</strong>...: Se la superficie ha molti minimi locali, il punto di partenza (inizializzazione dei pesi) / initial random guess, determina in quale valle finirà l'algoritmo.<br>
<strong>Learning Rate</strong>...: Attraverso gli optimizer (by dynamically adapting the learning rate). È pratica standard ridurlo alla fine per atterrare nel minimo con precisione senza oscillare.

</details>
</div>

---

<div class = "domanda1">
74. Quale <strong>funzione di loss</strong> è tipicamente utilizzata in una rete neurale per classificazionebinaria che utilizza una sigmoid come attivazione finale?<br>
	-<span class="evidenzia_risposta">Binary crossentropy</span><br>
	-Categorical crossentropy<br>
	-Absolute error<br>
	-Mean squared error<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Binary crossentropy<br>

<strong>Spiegazione</strong>: La Binary Crossentropy è la funzione di costo standard per la classificazione binaria (due classi, 0 e 1) quando l'output della rete è una probabilità calcolata tramite una Sigmoide.<br>
<strong>Categorical crossentropy</strong>: È associata alla Softmax come funzione di attivazione, non alla Sigmoide. Presente nel contesto della "Multinomial Regression" per gestire categorie multiple, dove la loss è la categorical crossentropy. <br>
<strong>Absolute error</strong>: funzione di loss tipica per problemi di regressione<br>
<strong>Mean squared error</strong>: funzione di loss standard per la regressione <br> (...)
</details>
</div>

---

<div class = "domanda1">
75. Un layer convolutivo 2D con stride 1, kernel size 3x3, e senza padding prende in input un layer con dimensioni (32,32,3) e restituisce un layer di dimensione (32,32,16). Quanti sono i suoi parametri?<br>
	-160<br>
	-28<br>
	-432<br>
	-<span class="evidenzia_risposta">448</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>:448<br>

<strong>Spiegazione</strong>: <br>
<strong>Calcolo dei pesi per il singolo kernel</strong>:<br>
If the input layer has depth D, and the kernel spatial size is NxM, the actual dimension of the kernel will be NxMxD.<br>
Quindi: 3 x 3 x 3 = 27<br>
<br>
<strong>Calcolo dei pesi totali</strong>:<br>
Il numero totale di pesi dipende dal numero di filtri (o kernel) che vuoi creare, che corrisponde alla profondità dell'output.<br>
Quindi: 27 x 16 = 432<br>
<br>
<strong>Calcolo dei bias</strong>: 16<br>
<br>
<strong>Calcolo dei parametri totali</strong>:<br>
432 + 16 = 448<br>



la profondità dell'input deve essere uguale alla profondità del kernel
</details>
</div>

$$
\text{Parametri} = ((K \times K \times D_{in}) + 1) \times D_{out}
$$

**Dove:**
- $K$: Dimensione lato kernel (in questo caso $3$)
- $D_{in}$: Canali input (in questo caso $3$)
- $1$: Il bias per ogni filtro
- $D_{out}$: Canali output/Numero filtri (in questo caso $16$)

---

<div class = "domanda1">
76. Selezionare la risposta <strong>SCORRETTA</strong> relativa ai<strong> modelli generativi</strong><br>
	-Generative Adversarial Networks, Variational Autoencoders e Diffusion models sono esempi di tecniche generative profonde<br>
	-Un tipico esempio di tecnica generativa è Naive Bayes<br>
	-Sono modelli che cercano di apprendere la distribuzione di probabilità dei dati<br>
	-<span class="risposta_errata">Sono modelli meta-teorici rivolti alla automatizzazione della generazione di reti neurali</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Sono modelli meta-teorici rivolti alla automatizzazione della generazione di reti neurali<br>

<strong>Spiegazione</strong>: Generative Model: a model that tries to learn the actual distribution pdata of real data. <br>
<strong>Naïve Bayes</strong>: Example of generative classifiers

</details>
</div>

---

<div class = "domanda1">
77. Selezionare la risposta <strong>SCORRETTA</strong> relativa al problema di <strong> scomparsa del gradiente</strong><br>
	-<span class="risposta_errata">Se il gradiente tende a zero anche parametri e le attivazioni dei neuroni tendono a zero</span><br>
	-Se il gradiente tende a zero i parametri non sono più aggiornati e la rete smette di apprendere<br>
	-Il problema è mitigato dall'uso di link residuali all'interno della rete<br>
	-Il problema è fortemente attenuato dall'uso di ReLU (o sue varianti) come funzione di attivazione per i livelli nascosti della rete<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Se il gradiente tende a zero anche parametri e le attivazioni dei neuroni tendono a zero<br>

<strong>Spiegazione</strong>: Il vanishing gradient riguarda la derivata dell'errore rispetto ai pesi (il gradiente), che diventa piccolissima. Non implica che i parametri o le attivazioni vadano a zero.<br>
<strong>Problema mitigato da link residuali</strong>...: during back propagation, the gradient at higher layers can easily pass to lower layers, without being mediated by the weight layers, which may cause vanishing gradient.<br>
<strong>Uso di ReLU</strong>...: problema vanishing gradient risolto: by the introduction on new activation functions, such as Rectified Linear Units (RELU)
</details>
</div>

---

<div class = "domanda1 riprendere">
78. Selezionare la risposta <strong>SCORRETTA</strong> relativa alle <strong> Transposed Convolutions</strong><br>
	-Possono essere interpretate come convoluzioni normali con stride sub unitario<br>
	-Sono prevalentemente usate in architetture per Image-to-Image processing, come autoencoders o U-Nets<br>
	-Sono essenzialmente equivalenti alla applicazione di un livello di upsampling seguito da una convoluzione normale<br>
	-<span class="risposta_errata">Richiedono la trasposizione dell'input prima di calcolare la convoluzione del Kernel</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Richiedono la trasposizione dell'input prima di calcolare la convoluzione del Kernel<br>

<strong>Spiegazione</strong>:<br>
<strong>Prevalentemente usate per Image-to-Image processing</strong>...: corretto! Le U-Net e gli Autoencoder prima rimpiccioliscono (<strong>encoder</strong>) e poi devono ingrandire per ricostruire l'immagine originale (<strong>decoder</strong>). Le Transposed Convolutions sono lo strumento standard per fare questo ingrandimento (Upsampling) imparando dai dati.<br>
<br>
<strong>Equivalenti a applicazione di livello di upsampling</strong>...: corretto! Una Transposed Convolution fa due cose insieme: allarga l'immagine (mettendo degli zeri tra i pixel) e applica un filtro. Si può ottenere lo stesso effetto facendo manualmente un upsampling seguito da una convoluzione classica. Il risultato finale è equivalente: un'immagine più grande processata.
</details>
</div>

---

<div class = "domanda1">
79. Selezionare la risposta <strong>SCORRETTA</strong> relativa alle<strong> Random Forest</strong> (foreste di alberi decisionali)<br>
	-Richiedono tecniche opportune per la creazione di alberi di decisione diversi relativi a uno stesso dataset<br>
	-<span class="risposta_errata">Tendono a migliorare l'explainability degli alberi di decisione riducendo l'instabilità nella selezione degli attributi</span><br>
	-Tentano di mitigare il fenomeno dell'overfitting tipico degli alberi di decisione<br>
	-È una tecnica di apprendimento ad "ensemble" basata su di una combinazione di alberi di decisione<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Tendono a migliorare l'explainability degli alberi di decisione riducendo l'instabilità nella selezione degli attributi<br>
<strong>Spiegazione</strong>: Gli alberi di decisione sono usati come componenti nelle foreste random. In pratica si fa un insieme di alberi di decisione che sfruttano il principio di tanti modelli non correlati per avere risultati più efficienti.<br>
Random Forest: È composta da centinaia o migliaia di alberi che "votano". È quasi impossibile per un umano seguire il percorso logico di 500 alberi contemporaneamente per capire perché la rete ha dato un certo risultato. Diventa una "Black Box".<br>
<br>
<strong>Richiedono tecniche opportune</strong>...: se tutti gli alberi fossero uguali, la foresta sarebbe inutile (sarebbe come avere un solo albero ripetuto). Per funzionare, la Random Forest deve creare diversità usando tecniche come il Bagging e scegliendo a caso solo alcune feature per ogni taglio.<br>
<strong>Mitigare fenomeno overfitting</strong>...: un singolo albero di decisione tende a imparare "a memoria" i dati (overfitting). Mettendo insieme tanti alberi e facendone la media, la Random Forest riduce questo rischio, generalizzando meglio.

</details>
</div>

---

<div class = "domanda1">
80. Una variabile aleatoria discreta con valori a, b e c ha la seguente distribuzione di probabilità: P(a)=1/4, P(b)=1/2, P(c)=1/4. Qual è la sua <strong>entropia</strong>?<br>
	-<span class="evidenzia_risposta">3/2</span><br>
	-Log(3)<br>
	-4/5<br>
	-5/4<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 3/2<br>

<strong>Spiegazione</strong>: guarda sotto, non avevo voglia di scriverlo non in latex
</details>
</div>

$$H(X) = - \sum_{i=1}^{n} P(X=i)\log_2 P(X=i)$$
**Calcoli e passaggi**:
$H = - \left[ \frac{1}{4} \log_2\left(\frac{1}{4}\right) + \frac{1}{2} \log_2\left(\frac{1}{2}\right) + \frac{1}{4} \log_2\left(\frac{1}{4}\right) \right]$
$H = - \left[ \left(\frac{1}{4} \cdot -2\right) + \left(\frac{1}{2} \cdot -1\right) + \left(\frac{1}{4} \cdot -2\right) \right]$
$H = - \left[ -\frac{1}{2} - \frac{1}{2} - \frac{1}{2} \right]$
$H = - \left[ -\frac{3}{2} \right] = \frac{3}{2}$

---

<div class = "domanda1">
81. In che situazioni si parla di <strong>apprendimento auto-supervisionato</strong>?<br>
	-Quando il modello è in grado di riconfigurare in modo automatico la propria architettura<br>
	-Quando il modello è dovrebbe contribuire alla creazione di nuovi dati di training<br>
	-<span class="evidenzia_risposta">Quando i dati di input possono essere considerati come annotazioni (labels) per guidare l'apprendimento, come nel caso degli autoencoders</span><br>
	-Quando l'apprendimento prevede una sinergia tra l'uomo e la macchina<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Quando i dati di input possono essere considerati come annotazioni (labels) per guidare l'apprendimento, come nel caso degli autoencoders. <br>

<strong>Spiegazione</strong>: L'apprendimento auto-supervisionato è una tecnica in cui il modello non ha bisogno di etichette fornite dall'uomo (come "gatto" o "cane"). Invece, genera le proprie "etichette" partendo dai dati stessi. <strong> Esempio </strong>: autoencoders. <br>
<strong>Riconfigurazione dell'architettura</strong>...: applicato a NAS o reti neurali, non c'entra con il modo in cui il modello apprende dai dati, ma con come è costruita la sua struttura.<br>
<strong>Creazione di nuovi dati di training</strong>...: questo descrive meglio i Modelli Generativi (come le GAN o i modelli di diffusione) o tecniche di Data Augmentation. Sebbene l'apprendimento auto-supervisionato possa essere usato per compiti generativi, la sua definizione non è creare dati, ma imparare rappresentazioni dai dati esistenti senza etichette.<br>
<strong>Sinergia tra uomo e macchina</strong>...: si riferisce all'active learning.
</details>
</div>

---

<div class = "domanda1">
82. Avendo 5 categorie di dati e 3 features di input booleane, quanti parametri indipendenti devono essere stimati secondo la tecnica <strong>Naive Bayes</strong> (compresi i priors).<br>
	-15<br>
	-16<br>
	-<span class="evidenzia_risposta">19</span><br>
	-20<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 19 <br>

<strong>Spiegazione</strong>: ti basta pensare al fatto che i parametri indipendenti sono le feature (questo perché si parla di naive bayes) quindi sono 3 feature moltiplicate per ogni categoria di dati (aka. label, aka, Y, ovvero l'output di cui calcolare la probabilità) a questo punto ci sommi anche i priors, che sono le probabilità a priori. Queste saranno 4.
</details>
</div>

$P(C_1) + P(C_2) + P(C_3) + P(C_4) + P(C_5) = 1 \quad \rightarrow \quad 5 - 1 = 4$
$(\text{Numero di Classi}) \times (\text{Numero di Features}) \quad \rightarrow \quad 5 \times 3 = 15$
$\text{Priors} = 4, \quad \text{Totale} = 4 + 15 = 19$

---

<div class = "domanda1">
83. Quale delle seguenti situazioni NON è particolarmente problematica dal punto di vista dell' <strong>overfitting</strong>?<br>
	-Avere pochi dati di training<br>
	-<span class="risposta_errata">Avere dati molto rumorosi</span><br>
	-Disporre di un modello molto espressivo<br>
	-Effettuare un training molto prolungato<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Avere dati molto rumorosi <br>

<strong>Spiegazione</strong>: Il rumore è una caratteristica dei dati, non una causa diretta del meccanismo di apprendimento eccessivo. Avere dati molto rumorosi spesso impedisce al modello di adattarsi perfettamente ai dati, rendendo l'overfitting "perfetto" più difficile da raggiungere rispetto alle altre situazioni.
</details>
</div>

---

<div class = "domanda1">
83. Un dataset contiene 2/3 di positivi e 1/3 di negativi. La precisione del modello è 9/10. Che percentuale dei dati totali sono <strong>Falsi Positivi</strong>?<br>
	-1/9<br>
	-<span class="evidenzia_risposta">Non può essere stabilito</span><br>
	-2/27<br>
	-1/10<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Non può essere stabilito <br>

<strong>Spiegazione</strong>: Guarda le formule, non hai nulla per effettuare il calcolo.
</details>
</div>

$$
\begin{aligned}
\text{Positivi Totali (P)} &= TP + FN \\
\text{Negativi Totali (N)} &= TN + FP \\
\text{Totale Dati (All)} &= TP + TN + FP + FN \\
\\[10pt]
\text{Accuratezza} &= \frac{TP + TN}{\text{All}} \\
\\[10pt]
\text{Precisione} &= \frac{TP}{TP + FP} \\
\\[10pt]
\text{Richiamo (Recall)} &= \frac{TP}{TP + FN} \\
\\[10pt]
\text{Specificità} &= \frac{TN}{TN + FP} \\
\\[10pt]
\text{F1 Score} &= 2 \cdot \frac{\text{Precisione} \cdot \text{Recall}}{\text{Precisione} + \text{Recall}}
\end{aligned}
$$
---

<div class = "domanda1">
84. Siano date le seguenti distribuzioni di probabilità P e Q: P(0)=3/8, P(1)=1/2, P(2)=1/8, and Q(0)=1/2, Q(1)=1/4, Q(2)=1/4. Quanto vale la crossentropy H(P|Q) tra P e Q?<br>
	-<span class="evidenzia_risposta">13/8</span><br>
	-3/2+log(3)<br>
	-5/2-log(3)/2<br>
	-2<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 13/8 <br>

<strong>Spiegazione</strong>: Guarda sotto non ho voglia di scrivere procedimento senza Latex
</details>
</div>

$$H(P, Q) = - \sum_{x} P(x) \cdot \log_2(Q(x))$$
Le variabili x possono assumere i valori {0,1,2}.
- **P (distribuzione vera/target):**
    - P(0)=3/8
    - P(1)=1/2
    - P(2)=1/8
- **Q (distribuzione stimata/predetta):**
    - Q(0)=1/2
    - Q(1)=1/4
    - Q(2)=1/4

$\begin{aligned} H(P, Q) &= - \left[ P(0)\log_2(Q(0)) + P(1)\log_2(Q(1)) + P(2)\log_2(Q(2)) \right] \\ &= - \left[ \frac{3}{8}\log_2\left(\frac{1}{2}\right) + \frac{1}{2}\log_2\left(\frac{1}{4}\right) + \frac{1}{8}\log_2\left(\frac{1}{4}\right) \right] \\ &= - \left[ \frac{3}{8}(-1) + \frac{1}{2}(-2) + \frac{1}{8}(-2) \right] \\ &= \frac{3}{8} + 1 + \frac{2}{8} \\ &= \frac{3}{8} + \frac{8}{8} + \frac{2}{8} \\ &= \frac{13}{8} \end{aligned}$

---
@
<div class = "domanda1">
85. Selezionare la sentenza <strong>ERRATA</strong> relativa alla <strong>regressione LINEARE</strong>.<br>
	-<span class="risposta_errata">Cerca di determinare un iperpiano di separazione tra due categorie di dati</span><br>
	-Il problema di ottimizzazione ammette una soluzione in forma chiusa<br>
	-La funzione di loss è tipicamente una distanza quadratica tra i valori predetti e quelli osservati<br>
	-Cerca di stabilire una relazione tra i valori di una variabile di output e i valori di una o più features di input<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Cerca di determinare un iperpiano di separazione tra due categorie di dati.<br>

<strong>Spiegazione</strong>: La definizione descrive un problema di <strong>Classificazione</strong>, <strong>NON</strong> di Regressione Lineare. Classificazione: L'obiettivo è tracciare una linea (o iperpiano) che separi i punti rossi dai punti blu (es. email spam vs non spam). Regressione Lineare: l'obiettivo è tracciare una linea che passi attraverso i punti per predire un valore numerico continuo (es. predire il prezzo di una casa in base ai metri quadri). <strong>Non separa categorie, ma stima valori</strong>.<br>
<strong>Soluzione in forma chiusa</strong>...: Nella regressione lineare classica, non si è obbligati a usare algoritmi iterativi (come il Gradient Descent) per trovare i parametri migliori. Si usa <strong>EQUAZIONE NORMALE</strong>.<br>
<strong>Funzione di loss</strong>...: il metodo più comune per allenare una regressione lineare è il metodo dei Minimi Quadrati (Mean Squared Error).<br>
<strong>Relazione variabile di output</strong>...: la regressione cerca una relazione (spesso indicata come y=wx+b) tra gli input (features) e l'output (target).<br>


</details>
</div>

---

<div class = "domanda1 riprendere">
86. Componendo due layer Conv2D con stride 1, il primo con kernel 5x5 e il secondo con kernel 3x3 quale sarà il <strong>campo ricetttivo</strong> dei neuroni finali?<br>
	-<span class="evidenzia_risposta">7</span><br>
	-8<br>
	-Dipende dal padding<br>
	-3<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 7 <br>

<strong>Spiegazione</strong>: Ogni volta che aggiungi un nuovo livello, non sommi semplicemente la larghezza del nuovo filtro. Aggiungi solo i bordi extra che il nuovo filtro guadagna spostandosi a destra e a sinistra rispetto al centro.<br>
Avevi 5. Il filtro da 3 ha un centro e 2 estremità (una a destra, una a sinistra). Queste 2 estremità allargano la visuale di 1 pixel ciascuna, 5 + 2 = 7.<br>
<strong>N.B.</strong> la Regola dell'Espansione: quando aggiungi un filtro sopra un altro (con stride 1), il nuovo filtro espande la visuale. Quanto espande? La sua dimensione - 1.

</details>
</div>

$$RF_{\text{totale}} = RF_{\text{precedente}} + (\text{Kernel} - 1) \cdot stride$$
$RF_1 = 1 + (5 - 1) = 5$
$RF_{\text{finale}} = 5 + (3 - 1) = 5 + 2 = 7$

---

<div class = "domanda1 riprendere">
87. Il tensore di input di un layer convolutivo 2D ha dimensione (16,16,8). Sintetizzo 4 kernel con dimensione spaziale (5,5), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell'output?<br>
	-<span class="evidenzia_risposta">(6, 6, 4)</span><br>
	-(8, 8, 8)<br>
	-(7, 7, 4)<br>
	-(7, 7, 8)<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: (6, 6, 4)<br>

<strong>Spiegazione</strong>: <br>
<strong>N.B.</strong> Se l'esercizio dice Nessun padding (o Valid padding): Metti P=0. <br>
Se l'esercizio dice Padding = 1 (o Same padding su kernel 3x3): Significa 1 a sinistra + 1 a destra, metti P=2.<br>
Se l'esercizio dice Padding = 2: Significa 2 a sinistra + 2 a destra, metti P=4.<br>
In sintesi: Nella tua formula, P è la somma totale dei bordi aggiunti (Sinistra + Destra). <br>
(...) Perché non quadruplicato?

</details>
</div>


$$\begin{aligned}
\text{Output} &= \frac{W + P - K}{S} + 1 \\
\\[10pt]
&= \frac{16 + 0 - 5}{2} + 1 \\
\\[10pt]
&= \frac{11}{2} + 1 \\
\\[10pt]
&= 5.5 + 1 \\

&\quad \downarrow \text{ (prendo solo la parte intera)} \\
&= 5 + 1 \\
\\[10pt]
&= 6
\end{aligned}$$
---
questa ragionaci!
<div class = "domanda1">
88. Selezionare la sentenza errata relativa all'<strong>inception module</strong>.<br>
	-Sfutta kernel di dimensione diversa<br>
	-Tende a ridurre il costo computazionale sfruttando convoluzioni unarie per diminuire il numero dei canali<br>
	-<span class="risposta_errata">Utilizza al proprio interno delle skip-connections per bypassare l'applicazione di parte dei kernel</span><br>
	-E' un componente tipico della rete Inception-v3<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Utilizza al proprio interno delle skip-connections per bypassare l'applicazione di parte dei kernel <br>

<strong>Spiegazione</strong>: Quella è la definizione di una <strong>Residual Unit</strong>, non di un inception module.<br>
<strong>ResNet</strong>:Usa le skip-connections per saltare dei layer e sommare l'input direttamente all'output F(x)+x. Serve a combattere il problema del gradiente che svanisce nelle reti molto profonde.<br>
<strong>Inception Module</strong>: La sua logica non è saltare, ma allargare. Esegue diverse operazioni in parallelo (convoluzioni 1×1, 3×3, 5×5, pooling) e poi concatena tutti i risultati insieme. Non c'è un bypass, c'è un'unione di caratteristiche diverse.<br>
<br>
<strong>Kernel di dimensioni diverse</strong>: invece di decidere se usare un filtro 3×3 o 5×5, li usa tutti contemporaneamente su rami paralleli per catturare dettagli sia fini che grossolani.<br>
<strong>Ridurre il costo computazionale</strong>: Le "convoluzioni unarie" sono le convoluzioni 1×1. Nel modulo Inception vengono messe prima dei kernel grossi (3×3, 5×5) per ridurre il numero di canali (profondità). Questo agisce come un "collo di bottiglia" (bottleneck) che rende il calcolo molto più leggero<br>
<strong>Riduzione costo computazionale</strong>...: Le "convoluzioni unarie" sono le convoluzioni **1×1**. Nel modulo Inception vengono messe _prima_ dei kernel grossi (3×3, 5×5) per ridurre il numero di canali (profondità). Questo agisce come un "collo di bottiglia" (bottleneck) che rende il calcolo molto più leggero
</details>
</div>

---

<div class = "domanda1">
89. Quale delle seguenti tecniche <strong>NON</strong> può aiutare ad uscire da <strong>minimi locali</strong> durante la fase di training.<br>
	-Ridurre la dimensione del minibatch<br>
	-<span class="risposta_errata">Fare clipping del gradiente in una range prefissato</span><br>
	-Aumentare il learning rate<br>
	-Aggiungere un "momento" al gradiente, cioè parte del gradiente del passo precedente<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Fare clipping del gradiente in una range prefissato<br>

<strong>Spiegazione</strong>: Il gradient clipping serve a prevenire il problema opposto, ovvero l'<strong>Exploding Gradient</strong>(quando il modello fa passi così grandi da "rompere" il training e andare verso l'infinito).<br>
<br>
<strong>Ridurre dimensione minibatch</strong>...: usare pochi dati per volta introduce molto rumore statistico. Il gradiente non è preciso, è "ballerino". Questo tremolio continuo (jitter) è utilissimo perché fa sì che il modello non scenda dritto nel buco, ma possa casualmente saltarne fuori grazie all'imprecisione del calcolo.<br>
<strong>Aumentare learning rate</strong>...: se aumenti il learning rate, fai passi più lunghi. Facendo passi giganti, è probabile che tu riesca a "scavalcare" interamente una piccola buca (minimo locale) senza caderci dentro.<br>
<strong>Aggiungere momento al gradiente</strong>...: il momento funziona come una pallina pesante che rotola. Se la pallina ha preso velocità (inerzia), non si fermerà appena incontra una piccola risalita (il bordo del minimo locale), ma la supererà grazie alla rincorsa accumulata.

</details>
</div>

---

<div class = "domanda1">
90.
Un layer convolutivo 2D con stride 1, kernel size 1x1, e senza padding prende in input un layer con dimensioni (32,32,16) e restituisce un layer di dimensione (32,32,4). Quanti sono i suoi parametri?<br>
	-2<br>
	-<span class="evidenzia_risposta">68</span><br>
	-8<br>
	-64<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 68<br>

<strong>Spiegazione</strong>: calcoli in Latex sotto
</details>
</div>

$$\text{Parametri} = [(\text{Kernel}_h \times \text{Kernel}_w \times C_{in}) + 1] \times C_{out}$$
$\text{Parametri}= [(1 \times 1 \times 16) + 1] \times 4$ 
$= [16 + 1] \times 4$
$= 17 \times 4$
$= 68$

---

<div class = "domanda1">
91. Selezionare la sentenza SCORRETTA relativa alla <strong>Intersection over Union</strong> (IoU)<br>
	-Frequentemente utilizzata come misura di similitudine tra bounding boxes<br>
	-Restituisce un valore nel range [0,1]<br>
	-<span class="risposta_errata">Non è una funzione simmetrica dei suoi input</span><br>
	-È una metrica principalmente utilizzata nel campo della Object Detection<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Non è una funzione simmetrica dei suoi input<br>

<strong>Spiegazione</strong>: Guarda definizione<br>
<strong>Misura di similitudine</strong>...: è la definizione standard. Si usa per calcolare quanto due rettangoli sono sovrapposti.<br>
<strong>Restituisce un valore nel range[0,1]</strong>: 0 significa che i box non si toccano, 1 significa che i box sono identici e sovrapposti.<br>
<strong>Object Detection</strong>...: è la metrica fondamentale per valutare algoritmi come YOLO, Faster R-CNN, ecc. Serve a decidere se un oggetto è stato trovato correttamente o no.

</details>
</div>

$$\text{IoU}(A, B) = \frac{ |A \cap B| }{ |A \cup B| }$$

---
<div class = "domanda1 riprendere">
92. Selezionare la sentenza SCORRETTA relativa ai <strong>transformers</strong>.<br>
	-Hanno una tipica struttura encoder-decoder, ognuno formato da uno stack di sotto componenti modulari<br>
	-Sono alla base delle reti della famiglia BERT e GPT<br>
	-Utilizzano pesantemente il meccanismo di attenzione<br>
	-<span class="risposta_errata">Aggiungono ad ogni livello della rete un encoding posizionale per enfatizzare la posizione relativa dei tokens</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Aggiungono ad ogni livello della rete un encoding posizionale per enfatizzare la posizione relativa dei tokens.<br>

<strong>Spiegazione</strong>: Nel Transformer standard il Positional Encoding viene aggiunto solo all'inizio, direttamente agli input embeddings, prima ancora che entrino nel primo strato della rete. <br>
<strong>Struttura ad encoder e decoder</strong>...: l'architettura originale del Transformer è composta da due pile (stack): un Encoder (che legge la frase di input) e un Decoder (che genera la traduzione).(...)<br>
<strong>BERT E GPT</strong>: evoluzioni più famose<br>
<strong>Meccanismo di attenzione</strong>...: I Transformer hanno abbandonato le ricorrenze (RNN) e le convoluzioni per basarsi interamente sulla Multi-Head Attention, che permette al modello di capire quali parole sono correlate tra loro, indipendentemente dalla distanza nella frase.

</details>
</div>

---

<div class = "domanda1">
93. Se un modello calcola una distribuzione di probabilità, aggiungere alla funzione obiettivo una <strong>componente tesa</strong> a diminuirne l'<strong>entropia</strong> avrà effetto di:<br>
	-Favorire l'uscita dai minimi locali<br>
	-<span class="evidenzia_risposta">Focalizzare le scelte sui casi più probabili</span><br>
	-Nessun effetto concreto<br>
	-Ridistribuire le probabilità in modo più bilanciato tra tutti i casi<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Focalizzare le scelte sui casi più probabili<br>

<strong>Spiegazione</strong>: Bassa Entropia, la distribuzione è spiked. Il modello è molto sicuro di una scelta (es. 90%, 5%, 3%, 2%).<br>
<strong>Ridistribuire le probabilità in modo più bilanciato tra tutti i casi</strong>: è l'esatto opposto<br>
<strong>Uscita dai minimi locali</strong>: tipico dell'aumento di entropia
</details>
</div>

---
<div class = "domanda1">
94. Un <strong>training set</strong> è composto da 10000 dati. Se la batchsize è 50, quante volte verrà effettuata la backpropagation durante una singola epoca?<br>
	-50<br>
	-10000<br>
	-<span class="evidenzia_risposta">200</span><br>
	-Nessuna delle risposte è corretta<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: 200<br>

<strong>Spiegazione</strong>: Guarda formula
</details>
</div>

$$ \text{Numero di Backpropagation} = \frac{\text{Totale Dati}}{\text{Batch Size}}$$

---

<div class = "domanda1">
95. Quale è l'obiettivo principale dell'algortimo di <strong>clustering K-means</strong>?<br>
	-Minimizzare la distanza tra punti in cluster differenti<br>
	-<span class="evidenzia_risposta">Trovare i K clusters che minimizzano la somma delle distanze quadratiche tra i punti del cluster e il rispettivo centroide</span><br>
	-Massimizzare la distanza tra i punti all'interno di uno stesso cluster<br>
	-Massimizzare il numero di clusters del dataset<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: trovare i K clusters che minimizzano la somma delle distanze quadratiche tra i punti del cluster e il rispettivo centroide<br>

<strong>Spiegazione</strong>: L'obiettivo matematico del K-means è rendere i gruppi (cluster) il più "compatti" possibile. Per fare questo, l'algoritmo cerca di ridurre al minimo la "dispersione" dei punti attorno al centro del proprio gruppo (il centroide).<br>
<strong>Minimizzare distanza tra i punti cluster differenti</strong>...: Questo è l'esatto contrario di ciò che vogliamo. Se minimizziamo la distanza tra cluster diversi, stiamo avvicinando i gruppi tra loro fino a sovrapporli. Un buon algoritmo di clustering vuole massimizzare la separazione tra gruppi diversi (Inter-cluster distance), affinché siano ben distinguibili.<br>
<strong>Massimizzare la distanza tra punti in uno stesso cluster</strong>...: il contrario di ciò che è detto sopra.<br>
<strong>Massimizzare il numero di clusters</strong>...: Nel K-means, il numero di cluster K è un parametro fisso deciso dall'utente prima di iniziare (input). L'algoritmo non può modificarlo.

</details>
</div>

---

<div class = "domanda1 riprendere">
96. Selezionare la sentenza SCORRETTA relativa alla <strong>Principal Component Analysis</strong> (PCA)<br>
	-<span class="risposta_errata">Tecnica per selezionare le features migliori tra quelle date, senza modificarle</span><br>
	-Tecnica per ridurre il numero delle features<br>
	-Vengono create nuove features come combinazioni lineari delle features esistenti<br>
	-I dati sono convertiti in un nuovo sistema di coordinate in modo da preservare la varianza massima tra di essi<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Tecnica per selezionare le features migliori tra quelle date, senza modificarle<br>

<strong>Spiegazione</strong>: ...

</details>
</div>

---

<div class = "domanda1">
97. Qual è il ruolo principale della <strong>funzione di loss</strong> in una rete neurale?<br>
	-Fornire un criterio quantitativo per valutare le prestazioni del modello.<br>
	-<span class="evidenzia_risposta">Misurare la discrepanza tra le previsioni del modello e i valori reali, guidando l'ottimizzazione dei parametri.</span><br>
	-Regolare il tasso di apprendimento durante l'addestramento.<br>
	-Penalizzare modelli troppo complessi per migliorare la generalizzazione.<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Misurare la discrepanza tra le previsioni del modello e i valori reali, guidando l'ottimizzazione dei parametri.<br>

<strong>Spiegazione</strong>: <strong>misurare la discrepanza</strong>: Calcola la distanza matematica tra ciò che la rete ha predetto e la realtà + <strong>guidare l'ottimizzazione</strong>: la loss deve essere derivabile. Attraverso il calcolo del gradiente della loss (Backpropagation), l'algoritmo di ottimizzazione capisce in che direzione modificare i pesi per ridurre l'errore al passo successivo.<br>
<strong>Criterio quantitativo</strong>...: la loss effettivamente ci dice come va il modello, ma questo compito spetta principalmente alle metriche<br>
<strong>Regolare tasso di apprendimento</strong>...: questo è il compito degli scheduler <br>
<strong>Penalizzare modelli troppo complessi</strong>...: questo è il compito della regolarizzazione <br>

</details>
</div>

- - -

<div class = "domanda1">
98. Selezionare la sentenza <strong>CORRETTA</strong> relativa agli <strong>alberi di decisione</strong><br>
	-Possono essere utilizzati solo con features discrete<br>
	-Costo computazionale molto elevato<br>
	-Non presentano problemi di overfitting<br>
	-<span class="evidenzia_risposta">Possono esprimere qualunque funzione di classificazione</span><br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: Possono esprimere qualunque funzione di classificazione <br>

<strong>Spiegazione</strong>: straightforward<br>



</details>
</div>

---

<div class = "domanda1 ripasso">
99. Quale di queste reti NON è stata creata per la <strong>classificazione di immagini</strong>?<br>
	-Inception v-3<br>
	-<span class="risposta_errata">U-Net</span><br>
	-VGG19<br>
	-ResNet<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: U-Net<br>

<strong>Spiegazione</strong>: U-Net is a convolutional neural network that was developed for image segmentation.


</details>
</div>

---

<div class = "domanda1 ripasso">
100. Quale è l'effetto tipico dell' <strong>aumento della dimensione del minibatch</strong> durante il training?<br>
	-La Backpropagation è effettuata meno frequentemente e l'aggiornamento dei parametri è meno accurato<br>
	-La Backpropagation è effettuata più frequentemente ma l'aggiornamento dei parametri è meno accurato<br>
	-<span class="evidenzia_risposta">La Backpropagation è effettuata meno frequentemente ma l'aggiornamento dei parametri è più accurato</span><br>
	-La Backpropagation è effettuata più frequentemente e l'aggiornamento dei parametri è più accurato<br>
<details>
<summary> Clicca qui per la soluzione e la spiegazione</summary>

<strong>Risposta corretta</strong>: La Backpropagation è effettuata meno frequentemente ma l'aggiornamento dei parametri è più accurato<br>

<strong>Spiegazione</strong>: 

</details>
</div>

---
