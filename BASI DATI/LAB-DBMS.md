### Cos'è DBMS?
- - -
è un software che crea e gestisce i database dove noi possiamo eseguire le varie operazioni in maniera semplice e visualizzabile
![[Pasted image 20251016152111.png]]

### Query processor
- - -
è rappresentata da due componenti:
* **Query compiler**, che traduce la query in un 
```sql
SELECT A, B
FROM R1, R2
WHERE C = D AND C = 'c'
```
Diventa:
$\large \pi_{A,B}​(\sigma_{C=D} (\sigma_{C='c'}​(R1) \Join R2)$ 
- il join unisce le due tabelle e li utilizza per eseguire le operazioni
GRAFICO OPERAZIONI
$\large \sigma_{C='c'}​(R1), \quad \Join R2), \quad \sigma_{C=D}, \quad\pi_{A,B}$ 
### Resource manager
- - -
* index/file/record manager: dice che dato è R1
* buffer manager: se ce l'ha lui gasa, altrimenti vado in memoria secondaria
* storage manager: 
	* prende dalla memoria secondaria ciò che non è presente dentro il buffer

### transaction manager:
- - -
- Esempio su pagamento, faccio operazioni su bank account +500 se in caso ricevessi soldi, -500 da quello dell'azienda/capo
insieme di query particolarmente delicate vengono trattate come una singola query e in caso di problemi durante l'esecuzione di queste, si ritorna allo stato del database prima dell'inizio della query.
##### logging and recovery
- Al fine di assicurare la durabilità, il **Log Manager scrive separatamente su disco ogni cambiamento nel database.**
    
- Il Log Manager inizialmente **scrive il log nei buffer**, e negozia con il Buffer Manager per **assicurarsi che i buffer vengano scritti su disco** (dove i dati possono sopravvivere a un crash).
    
- Indipendentemente da quando si verifica un fallimento o un crash del sistema, il **Recovery Manager esamina i cambiamenti del log e ripristina il database a uno stato consistente.**




### concurrency control
- - -
- **Le transazioni devono apparire come se venissero eseguite in isolamento**, ma nella maggior parte dei sistemi, ci saranno in realtà **molte transazioni in esecuzione contemporaneamente.**
    
- Il **Concurrency-Control Manager deve assicurare che le singole azioni di più transazioni vengano eseguite in un ordine tale che l'effetto netto sia lo stesso di quello che si sarebbe avuto se le transazioni fossero state eseguite per intero, una alla volta.**
    
- Un tipico _scheduler_ (gestore delle operazioni) mantiene dei **blocchi (_locks_)** su determinate porzioni del database, **impedendo a due transazioni di accedere allo stesso dato in modi che interagiscono negativamente.** Lo _scheduler_ influenza l'esecuzione delle _query_ e di altre operazioni di database vietando l'accesso alle parti bloccate.

##### deadlock resolution
il mitico transaction manager decide quale tabella sbloccare e se necessario, viene avviata una procedura di rollback nel caso in cui una query l'abbia modificata drasticamente

### TECNICHE JOIN:
---
L'operazione di **JOIN** tra tabelle, ad esempio tra le tabelle R e S sugli attributi A e B, è notoriamente una delle operazioni che **richiede più tempo** nel processo di esecuzione delle _query_.
    
- Esistono quattro delle tecniche più comuni per eseguire un'operazione di JOIN:
    
    1. **Nested-loop Join** (JOIN a cicli annidati)
		- Scannerizza tutto quanto riga per riga, anche quelle già controllate.
    2. **Single-loop Join** (JOIN a ciclo singolo)
	    - una delle due tabelle viene ordinata
		- miglioramento del primo tipo di join, la metrica di ordine ci permette di sapere subito l'attributo richiesto, velocizzando il match (trovando ad esempio subito il valore B) PERÒ a volte non ho la metrica per gestire questo caso.
    3. **Sort-merge Join** (JOIN per ordinamento e fusione)
	    - entrambe le tabelle S ed R sono ordinate sul valore join di A e B, fanno match solamente dove hanno lo stesso valore.
    4. **Hash-based Join** (JOIN basato su _hashing_)
        - join basato su hashish, viene fatto su entrambi gli attributi del join, conviene nelle tabelle enormi. creo contenitori per restringere il calcolo
- Basandosi sulle statistiche del database, **l'ottimizzatore** di _query_ seleziona l'approccio con il **costo stimato più basso**.
- - -

## Transaction and concurrency control
problemi principali
* esecuzione concorrente delle transazioni
* crash recovery

#### ACID
per assicurare concorrenza, una transazione sicura e crash recovery, ogni transazione deve rispettare le seguenti proprietà:
* **A**tomicity .. 
* **C**onsistency ..
* **I**solation .. 
* **D**urability ..
<small>Stato di un database, ovvero una sorta di fotografia del database in quel momento</small>

altra roba da finire qua sulle proprietà acid

- - -
### Schedule
uno schedule S è una sequenza di azioni (read, write, commit e abort), prese da un set di transazioni 

attributi di una transazione
* complete schedule ..
* serial schedule ..



##### Anomalie di un'esecuzione intervallata
Possono generarsi delle inconsistenze nello stato del database
* **conflitto write-read**
* **conflitto read-write**
* **conflitto write-write**
esistono anche le anomalie "fantasma" 
* T1 fa una read su X
* T2 fa una read su X
* T1 fa una inserte/delete(a, X)
* T2 fa una read su X
- - -
#### Parametri di una transazione
* ACCESS MODE
* STATEMENT MODE
* ISOLATION LEVEL
	* READ UNCOMMITED ..
	* READ COMMITED ..
	* REPEATABLE READS ..
	* SERIALIABLE ..



