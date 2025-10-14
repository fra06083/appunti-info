si parla di _**overfitting**_ (oppure **adattamento eccessivo**) quando un modello statistico molto complesso si adatta ai dati osservati (il campione) perché ha un numero eccessivo di parametri rispetto al numero di osservazioni.

si dice che $\large h$ **overfitta** il training set se esiste un'altra ipotesi $\large h'$ tale che $$\large  error_{train}(h) <  error_{train}(h')$$ e $$\large  error_{D}(h) >  error_{D}(h')$$dove nel secondo caso si trattano i dati **reali** (alla quale solitamente non si ha accesso) e non di **training**

Dato l'errore relativo all'ipotesi h $\in$ J
Scegliamo h in modo da minimizzare l'errore $\large \rightarrow error_{train}(h)$
![[Pasted image 20251002134456.png]]
![[Schermata_20251002_134318.png]]


.... Il modello sembra andare bene, però in realtà non generalizza e va peggio del precedente


Nel caso in cui non si conoscano i dati $\large D$, si dividono i dati in due insiemi disgiunti: 
* **training set** utilizzato per scegliere l'ipotesi $\large h$ 
* **validation set** utilizzato per misurare accuracy e overfitting 

#### Metodi per evitare overfitting su alberi di decisione
* **early stopping**: fermare la costruzione dell'albero finché il miglioramento del modello non è più statisticamente significativo (per esempio quando il guadagno informativo non supera una certa soglia)
* **post-pruning**: si sviluppa l'intero albero e quindi si procede a portarlo all'indietro
	* Costruire un albero di decisione completo per il **training set**
	* ripetere la seguente operazione finché ogni ulteriore pruning non migliora l'accuratezza della predizione:
		* per ogni sotto albero si valuta **l'impatto** della sua **rimozione** sull'accuratezza
		* effettuare in **modo greedy** il pruning del sotto albero che ottimizza l'accuracy
#### Foreste (Random forests)
Gli **alberi di decisione** vengono utilizzati come **componenti delle Random Forests**, dove sono utilizzata con la tecnica dell'**ensemble** *(unisce)*
	$\LARGE \rightarrow$ sfruttano il principio che un grande numero di modelli scorrelati operano come un comitato e prevedono risultati migliori rispetto a quelli singoli.
selfie

