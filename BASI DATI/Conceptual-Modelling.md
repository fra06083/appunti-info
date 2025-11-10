Dobbiamo trovare un modo per creare uno schema per costruire un database efficiente e non rigido.
#### Dobbiamo usare il ciclo di vita:
- Durata di una certa cosa, quanto verrà usata.

abbiamo uno step di life cycle da fare:
- **Studio di fattibilità**: analisi di cosa fa un'azienda, la sua filosofia... Definizione di costi e priorità. L'output evidenzia cosa è necessario fare, i rischi, i tempi. **Sarebbe da far eseguire ad un attore esterno.**
- **Raccolta e analisi dei requisiti**: analisi delle proprietà del sistema da realizzare. Deve essere dettagliata e approvata con il committente. Va controfirmata da sviluppatore e cliente.
- **Progettazione**: analisi dei dati da memorizzare e sviluppo dei metodi da realizzare. L'output è un progetto esecutivo (implementabile). Anche questo documento va approvato e firmato.
- **Implementazione**: realizzazione del progetto.
- **Validazione**: check del modello e collaudo (debug).
- **Deployment**: messa in esecuzione del sistema. Comprende la formazione del personale per essere sicuri che il sistema venga utilizzato correttamente. Da subito dopo il deployment il prodotto entra in manutenzione.

quando capita di dover fare un passo indietro nel life cycle, è chiaro che c'è stato un errore nello step in cui si deve tornare.
Più in basso ti accorgi dell'errore, più fatica si farà nel trovarlo, dovendo fare passi indietro nel life cycle
![[lifeCycle.png|515x322]]

### design methodology
- - -
vari step che permettono di mantenere una buona qualità del progetto:
* definire task separati
* selection criteria
* rappresentazione dei modelli
* Soluzioni generali e User-friendliness
	* permettere la fruibilità del prodotto ad una vasta gamma di clienti


**due tipi di modelli:**
* ***Modelli logici***:
	* organizzazione dei dati nel dbsm
* ***Modelli concettuali***:
	* permette la rappresentazione dei dati, indipendentemente dal sistema
	* rappresentare il concetto del mondo reale(?)


### Entity-relationship (ER)
- - -
* **entità**: ovvero una classe di oggetti uniforme che condividono proprietà fra di loro e hanno un'esistenza autonoma (e.g. Employee, City, BankAccount ecc.)
	* **istanza**, un elemento dell'istanza (non il singolo dato eh!)
* **Relazione**: associazioni tra due o più entità nello stesso modello di dominio
	- Binarie: Ci consentono di mettere in relazione due entità (solitamente è questo) 1-1
	- N-arie: esistono ma non le useremo spesso 1-n n-m
* **Associazione**: Il collegamento tra due entità (IL NOME es. tra Studente e Corso è `ESAME`)
* In caso volessimo fare un collegamento al più di uno 
	(N $\large \to$ N) possiamo creare un entità che collega le due entità
>[!Info] Lo vedremo quando creeremo gli schemi ER
* **attributo**: è una proprietà che appartiene alle relazioni o alle entità. Associa ad un valore che appartiene ad un insieme chiamato **dominio**. Gli attributi aiutano ad identificare e distinguere le istanze![[esempioAttributiIstanza.png]]
* **composite attributes (eh eh inglese)** <small>attributi composti</small>: raggruppano insieme attributi della stessa entità o relazione che hanno delle similitudine nel significato o nell'uso


##### Cardinalità
- - -
Coppia di valori coinvolta nelle associazioni, ci interessa specificare numero min e max di associazioni a cui può partecipare

0-50 ad esempio come default 0 MASSIMO 50
in base alla cardinalità, esistono vari tipi di relazioni

* Relazioni **Many to Many**

`Student`$\LARGE ^{(0, N)}$ ◆──◆  `Exam` ◆──◆$\LARGE ^{(0, N)}$ `Course`

* relazioni **one to many**
`town`$\LARGE ^{(1, 1)}$ ◆──◆ `partOf` ◆──◆$\LARGE ^{(1, n)}$`district`
<small>poni particolare attenzione alle cardinalità definite nelle relazioni one to many</small>

* relazione **one to one**
`person`$\LARGE ^{(0, 1)}$ ◆──◆ `holds` ◆──◆$\LARGE ^{(0, 1)}$`pacemaker`

##### Identificatori di entità
- - -
È una tecnica per identificare in modo univoco le occorrenze di una determinata entità
è formato da:
* gli attributi dell'entità (?) **identificatori interni**
* attributi più le entità esterne, raggiungibili tramite relazioni **identificatori esterni**![[esempioIdentificatoriEsterni.png]]
honest non ho compreso bene gli identificatori esterni


##### Generalizzazione
collega una o più entità con un'altra entità avente tot entità come specifici casi
$\large E$  è una **generalizzazione** di $\large E_1, E_2, ..., E_n$ 
$\large E_1, E_2, ..., E_n$ sono una **specializzazione** di $\large E$

* proprietà:
	* 

**Tipi di generalizzazione**
- Totale .. 
- disgiunta ..
	- disgiunzione parziale
	- disgiunzione totale


