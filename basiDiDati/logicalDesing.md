- - -
[slides](https://docs.google.com/presentation/d/152cGKrMUaZDzY1ge4WRAv7v82qkC6gtvgGlyAn1Zl_Y/edit?slide=id.g28d05021a84_0_45#slide=id.g28d05021a84_0_45)

### Obiettivi del logical design
- - -
- C'è una "traduzione" dello schema concettuale in schema logico, rappresentando gli stessi dati in modo corretto ed efficiente

- con uno schema logico si cerca di parlare di efficienza, anche se ad un livello un po' astratto (per l'appunto, logico)

prende in input:
- schema concettuale
- modello logico

produce in output:
- schema logico (relazionale, orientato agli oggetti oppure un grafo)
- documentazione associata allo schema
ricorda che questa traduzione non è sempre facile, alcuni aspetti potrebbero non essere rappresentati direttamente


### Performance
- - -
Non è possibile valutare la performance in modo preciso attraverso uno schema concettuale, quindi è necessario prendere in considerazione dei particolari **indicatori**:
- **spazio**: ovvero il numero aspettato di istanze memorizzate
- **tempo**: numero di istanze (quindi di entità e relazioni) visitate durante le operazioni

esempio di valutazione del costo:
- ritornare tutti i dati di un determinato dipendente, i dati del dipartimento a cui appartiene e tutti i dati dei progetti alla quale lavora.
si costruisce una **tabella degli accessi** seguendo lo **schema di navigazione**
esempio a pagina 14

### Ridondanza
- - -
Una ridondanza, negli schemi ER, è un'informazione rilevante ma che può essere derivata da altri
- pro:
	- semplificazione delle query
- contro:
	- gli aggiornamenti sono più lenti
	- la memoria occupata aumenta
non sempre ha senso eliminare le ridondanze, a pagina 28 c'è l'esempio

### Eliminazione delle gerarchie
- - -
Il modello relazionale dei dati non supporta direttamente le generalizzazioni, non sono direttamente rappresentabili. Mentre invece le relazioni e le entità, sono direttamente rappresentabili. Quindi rimuovo le gerarchie sostituendole con entità e relazioni

guarda gli esempi a pagina 31


### Ricostruzione degli attributi
- - - 
La **ricostruzione** può fornire più efficienza nelle operazioni, riducendo il numero degli accessi:
- attributi acceduti separatamente sono divisi
- attributi acceduti allo stesso tempo sono raggruppati, anche se appartengono a entità/relazioni diverse

Sono presenti casi diversi:
- partizionamento verticale delle entità
- ricostruzione di attributi multi valuta
- raggruppamento di relazioni/entità
- partizionamento orizzontale della relazione 
	- questo non si capisce tanto dalle slide aiuto




#### Identificazione delle chiavi primarie
- - -
vari criteri:
- informazione obbligatoria
- semplicità
- utilizzata per la maggior parte o le operazioni più importanti

##### Rule of thumb
- **le entità** diventano "tabelle", la quale schema corrisponde agli attributi dell'entità
- **relazioni**, diventano "tabelle" e il loro schema corrisponde agli attributi dell'entità più gli identificatori delle entità straniere prese in causa

esempio
- EMPLOYEE(**Number**, Surname, Wage)
- PROJECT(Code, Name, Budget)
- ENROLLMENT(**Number**, **Code**, StartDate)
allora -->
- ENROLLMENT(**Employee**, **Project**, StartDate)

quando fai questi tipi di "accorpamenti" fai attenzione alla cardinalità dello schema!
Un esempio su cui fare attenzione è presente nelle slide 67-68-69-70, dove in base alla cardinalità è possibile o meno unire le entità/relazioni in un unica tabella