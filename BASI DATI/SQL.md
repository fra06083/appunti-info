   Introduzione    storica gas
- - -
RICORDARE DI SPIEGARE LA ROBA SULL'AND NELLA SELECTION

#### Data definition
```sql
CREATE DATABASE db_name
```
crea un database (no way, non ci credo)

```sql
CREATE SCHEMA schema_name
-- oppure
CREATE SCHEMA schema_name
AUTHORIZATION 'user_name' 
```
questo, è identificato da un nome e descrive gli elementi che vi appartengono. Lo schema apparterrà allo user che lo avrà creato; lo statement può essere accompagnato dalla keyword AUTHORIZATION per specificare un determinato user che possiede lo schema

``` sql
CREATE TABLE
```
Specifica una nuova relazione e crea la sua istanza vuota.
esempio:
```sql
CREATE TABLE EMPLOYEE (
Number CHARACTER(6) PRIMARY KEY,
Name CHARACTER(20) NOT NULL,
Surname CHARACTER(20) NOT NULL,
Dept CHARACTER(15),
Wage NUMERIC(9) DEFAULT 0,
FOREIGN KEY(Dept) REFERENCES
DEPARTMENT(Dept),
UNIQUE (Surname, Name)
)
```
arrivato alla slide 15
- - -
#### 🗑 DROP Table
- con drop table rimuoviamo i dati e lo schema di una tabella
```sql
DROP tabella
```
possiamo aggiungere un vincolo con DOMAIN: un dominio definito dall'utente ad esempio *voto*.
#### 📔 Indici
Elenco di numeri ordinati, rendiamo così la ricerca dei dati più veloci, utilizziamo quegli algoritmi che abbiamo visto dal mitico Pietruzzo di Lena...
Sono definiti a livello fisico e non logico!```
```SQL
CREATE INDEX idx_Surname
	ON OFFICER (Surname)
```
Utilizziamo create index per creare un indice in base all'attributo Surname della tabella officer
- - -
## SQL DATA Operations:
Query e Edit:
- EDIT
	Insert, Delete, Update:
- SELECT:
		Selezione di due attribuzione da una tabella e condizioni
```sql
SELECT Number, Name (3)
FROM OFFICER (1)
WHERE Surname = 'Jones' (2)
```
- (La lettura va in ordine definita tra le () prima tabella, poi condizione -> poi prende gli attrubuti richiesti)
La stessa formula in algebra relazionale è la seguente:
$$\Large \pi_{\text{Number, Name}} ( \sigma_{\text{Surname='Jones'}} \text{(OFFICER)}))$$
```sql
SELECT <AttributeList> -- anche detta target list
FROM <TableList>
[ WHERE <Condition> ] -- [] opzionale
```

```sql
SELECT * FROM R
```
Se usassi * non utilizzo proiezione, prendo tutte le tabelle tramite selection (sigma) $\sigma$ 

##### Predicato LIKE:
- LIKE si utilizza per date un pattern
```sql
SELECT * FROM PEOPLE
	WHERE Name LIKE 'J_m%' -- Cerco i nomi che hanno J all'inizio e m come terza -- lettera
```





#### esempii algebra relazionale e SQL
- - -
```SQL
SELECT Name, Income
FROM PEOPLE
WHERE Age < 30
```
$\Large \pi_{name,income}(\sigma_{age<30}(PEOPLE))$
![[condivisione gas/BASI DATI/images/image-3.png|382x277]]

**esempio di select con shortcut**
![[image-2.png|382x277]]

![[image-1.png|418x286]]

Se facciamo il select, ci appare due volte Rossi Rome, per quel motivo dovremmo utilizzare **DISTINCT**
La select di default mantiene i **predicati(?)** {mantiene le righe delle tabelle uguali}.
![[condivisione gas/BASI DATI/images/image-3.png]]

## Differenze tra SQL e Algebra relazionale:
- - -
* R1(A1, A2) R2(A3, A4)
```SQL
SELECT DISTINCT R1.A1, R2.A4
FROM R1, R2
WHERE R1.A2 = R2.A3
```
* prodotto cartesiano (FROM)
* selection (WHERE)
* Projection (SELECT)
$\Large \pi_{A1, A4}(\sigma_{A2=A3}(R1 \Join R2))$


#### EXPLICIT JOIN:
```sql
SELECT Motherk, FATHERHOOD.child, Father
	FROM MOTHERHOOD JOIN FATHERHOOD ON FATHERHOOD.Child = MOTHERHOOD.Child
```
Qui non si utilizza la parte di where per collegare le due tabelle, in generale è meglio usare quelle esplicite, l'ottimizzatore, usa funzioni più veloci se sa che sono presenti join
```sql
SELECT ...
	FROM LEFTTABLE { ... JOIN ... ON ... }
```