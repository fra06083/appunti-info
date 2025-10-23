   Introduzione    storica gas
- - -
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
- - -
```sql
SELECT Motherk, FATHERHOOD.child, Father
	FROM MOTHERHOOD JOIN FATHERHOOD ON FATHERHOOD.Child = MOTHERHOOD.Child
```
Qui non si utilizza la parte di where per collegare le due tabelle, in generale è meglio usare quelle esplicite, l'ottimizzatore, usa funzioni più veloci se sa che sono presenti join
```sql
SELECT ...
	FROM LEFTTABLE { ... JOIN ... ON ... }
```

#### Sorting
- - -
utilizziamo order per poter ordinare i dati:

```sql
SELECT NAME, INCOME
FROM PEOPLE
WHERE AGE < 30
ORDER BY NAME ASC -- o 'Desc' che è in ordine decrescente 
```
Persone che hanno meno di trent'anni in ordine alfabetico.

#### Union 🦄
---
La union permette di unire :O due tabelle con query diverse. Normalmente il risultato è dato da righe uniche, fatta eccezione per quando si inserisce il campo `ALL` in UNION (in questo caso si ha il **multiset union**).
```SQL
SELECT child
FROM MOTHERHOOD
UNION -- ALL
SELECT child
FROM FATHERHOOD
```
ricorda che vale la notazione posizionale. Nel caso in cui due tabelle di cui si fa la UNION abbiano schemi diversi, per esempio:
```SQL
SELECT Father, child
FROM MOTHERHOOD
UNION -- ALL
SELECT Mother, child
FROM FATHERHOOD
```
allora nel risultato della tabella, lo schema valutato sarà del tipo (Father, child) 

#### Difference - Intersection
- - -
```SQL
-- DIFFERENCE
SELECT Name
FROM EMPLOYEE
EXCEPT
SELECT Surname AS Name
FROM EMPLOYEE
```

```SQL
-- INTERSECTION
SELECT Name
FROM EMPLOYEE
INTERSECT
SELECT Surname AS Name
FROM EMPLOYEE
```

#### Nested Queries
- - -
mega supercazzola sulle nested query usando ANY, ALL e IN 
ANY, seguito da un'espressione fai il match se l'espressione viene rispettata da almeno una tupla 
```SQL
SELECT Father
FROM FATHERHOOD
WHERE Child = ANY (SELECT Name
				   FROM PEOPLE
				   WHERE Income > 20)
```
* ALL stesso concetto, ma devono essere rispettate tutte le tuple dell'espressione
* IN, stessa solfa, ciò che viene messo prima di IN deve essere presenta nella tupla restituita dall'espressione dopo IN.
* EXISTS ...

#### Aggregate functions
- - -
Nella target list è possibile inserire espressioni che computano il valore da un set di tuple attraverso funzioni aggregate:
* `aggr: COUNT | MIN | MAX | AVG | SUM`
esempio:
Il numero dei figli di Frank:
```SQL
SELECT COUNTA(*) AS NumFrankChildren 
FROM FATHERHOOD
WHERE FATHER = 'Frank'
```


## Updating operations
- - -
#### **INSERT**
```SQL
INSERT INTO table -- opzionale lista attributi [(AttList)]
  VALUES -- (Vals)
  -- OPPURE
INSERT INTO table 
  SELECT ...
```
ricorda che di norma le liste hanno lo stesso numero di attributi.
Nel caso in cui venga omesso un attributo viene messo un valore NULL o di rimpiazzamento, (credo :3 )

esempio:
![[insertExample.png|500x299]]
#### **DELETE** 
rimuove le tuple che soddisfano una determinata condizione, presta attenzione perché potrebbero essere eliminate anche altre tuple di altre tabelle (se i constraint sono definiti usando la key word `CASCADE`)
```SQL
DELETE FROM Table
WHERE -- [condition]
-----------
DELETE FROM PEOPLE
WHERE Age < 35
-----------
DELETE FROM FATHERHOOD
WHERE Child NOT IN (SELECT Name 
					FROM PEOPLE)
-----------
DELETE FROM FATHERHOOD
```

#### **UPDATE**
```SQL
UPDATE 'TableName'
SET Attribute = 'Expr..'
WHERE -- eventuale condizione se necessaria
```
eseeeempio:
```SQL
UPDATE PEOPLE 
SET Income = 45
WHERE Name = Bob
```
Prima e dopo:
![[esempioUpdate.png|211x300]]
###### FINE PACCO SLIDE DI SQL'S BASICS


# Advanced SQL
------------------------------------ -
Altri tipi di constraints:
##### Check
```SQL
CHECK -- predicato
```
Il check specifica determinati constraints sulle tuple (in certi casi è possibile specificarne alcuni che non in tutte le implementazioni di SQL sono supportati). La loro implementazione è molto costosa, ma il loro utilizzo può essere molto utile
Esempio:
![[esempioCheck.png]] Non sempre la clausola select è sempre supportata per tutte le implementazioni di sql

##### Assertion
Definisce dei constraint a livello di schema
```SQL
create assertion NameAs check -- predicato
-- oppure
create assertion AtLeastOneEmployee
check (1 <= (select count(*) 
			 from EMPLOYEE))
-- la select non sepre è supportata 
```


#### View update
- - -
con check option stai specificando solo modifiche a gli attributi contenuti in quella vista (?)
honest noccapito da rivedere sta parte

##### Esempio sbagliato di query:
- - -
Provide the average number of offices per departement
```SQL
select avg(count(distinct Office))
from EMPLOYEE
group by Dept
```
non si può fare!! La sintassi non permette annidamenti di avg, count ecc.
In questo caso allora si usano le **viste**:
```SQL
create view DEPTOFFICES(NameDept, OffNum) as
	select Dept, count(distinct Office)
	from EMPLOYEE
	group by Dept;
	
select avg(OffNum)
from DEPTOFFICES
```
in teoria poi ci sarebbero altri esempi, vai a controllarli.


#### Recursive queries
- - - 
![[esempioRicorsione.png|468x310]]

INCHARGE è il risultato della chiusura transitiva

#### Funzioni scalari
- - -
Sono funzioni a livello di tuple che forniscono un singolo valore per tupla, ce ne sono diverse.
* current_date()
* extract(*yearExpression*)
* char_length
* lower
* cast


#### conditional expression
- - -
**COALESCE**
Prende in input molteplici espressioni e ritorna il primo di questi che non è NULL
Un esempio di utilizzo può essere per un valore di default per sostituire i valori NULL:
```SQL
select Name, Surname,
	coalesce(Dept, 'None')
	from EMPLOYEE
```

**NULLIF**
confronta il primo argomento (per esempio l'attributo di una determinata relazione) con il secondo (per esempio una costante). Ritorna NULL se i due argomenti fanno match, altrimenti ritorna il valore del primo argomento

**CASE**
funziona che permette di specificare strutture condizionali, la quale il risultato dipende dal risultato dalla valutazione del contenuto della tabella
Dà un effetto del tipo di if then else, quindi si può usare per quel tipo di logica.
![[esempioCase.png|504x292]]


### Database security
- - -
SQL permette di garantire determinati privilegi (read, write...) per ogni utente.
I privilegi possono essere garantiti su relazioni, attributi, viste o domini.

Un **privilegio** è descritto come:
* una specifica risorsa
* l'utente che garantisce una risorsa
* l'utente che ha un determinato privilegio
* una specifica operazione
* se un utente può propagare il privilegio o no

**tipi di privilegio**:
* insert
* update
* delete
* select
* references: permette di definire constraints di integrità referenziale
* usage: permette di utilizzare una definizione (per esempio un tipo di dato custom)

**granting privileges**
```SQL
grant -- < Privileges | all privileges >
on  -- Resource
to -- User [ with grant option ]
```

attenzione!! grant option può permettere la propagazione del proprio privilegio ad altri
```SQL
grant select on DEPARTMENT to Jack
```

**revoking privileges**
```SQL
revoke Privileges on Resource
from User [restrict | cascade]
```
attenzione a cascade che causa una reazione a catena

L'implementazione SQL deve nascondere le parti del database che non sono accessibili per l'utente.
Si potrebbero usare delle viste per mostrare solo alcune tuple ad un utente.

In SQL-3 sono stati implementati i role based access control **RBAC**, dove ogni ruolo è una sorta di container con svariati privilegi che possono essere assegnati tramite il comando grant
Esempio di RBAC:
```SQL
-- create a new role
create role Employee;

-- grant the privilege to the previously defined role
grant create table to Employee;

-- grant the privilege to a specific user
grant Employee to user;

-- revoke the previously granted privilege
revoke create table from Employee;
```