### diagrammi di stato

un **evento** è la specificazione di un avvenimento che si posiziona nello spazio e nel tempo 

la **transizione**, è il movimento da uno stato all'altro in risposta ad un evento(ovvero la riga anche se molto spesso vanno aggiunte cose per la specificazione) oltre alla source e la destination potrebbe specificare 
* event, un evento che attiva il cambio di stato
* Guardia (blocca o permette eventualmente di passare allo stato successivo)
* action: una determinata operazione che risulta dal cambio di stato
*sintassi*: `event [guard] / action` 

i pallini pieni sono pseudo stati che indicano da dove iniziamo (lo stato iniziale). Sono presenti anche i pallini cerchiati che indicano la fine dello stato.
- - -
 entry do exit
 - **entry**: eseguita quando l'oggetto entra in un determinato stato
 - **exit**: eseguito quando un oggetto esce da uno stato
 - **do**: eseguita quando un oggetto è in un determinato stato
- - -
#### stati composti
spesso utilizzati per ridurre la complessità del modello
* dall'esterno è visibile un macro stato, mentre al suo interno contiene molteplici stati
![[Pasted image 20251015160552.png]]