-------------------------------------
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
Esempio di **RBAC**:
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
sviluppiamo i permessi usando i ruoli:
- così non dobbiamo assegnare ad ogni persona un set di permessi. (sarebbe scomodo, se mi dimenticassi di rimuovere i permessi ad un utente?) Con i ruoli basta rimuoverlo dal ruolo ed abbiamo fatto.
> [!Warning] Occhio alla differenza tra gruppi e ruoli, sono due cose diverse
> **I Gruppi sono usati per dare permessi agli utenti, un ruolo invece serve per dare i permessi ad una determinata tabella... etc** 

 
### Transazioni
- - -
Una **transazione** è un programma in esecuzione che forma un'unità logica del database in processo (si parla di operazioni atomiche!)

#### Proprietà ACID
* **A**tomicity 
* **C**onsistency preservation
* **I**solation 
* **D**urability (permanency)

###### Atomicity
* ..
###### Consistent
* il database passa da uno stato ad un altro, ma rimane sempre in uno stato **consistente**!

###### Isolation
* ogni utente/programma che esegue la transazione lo esegue in isolamento, come se non avesse interruzioni o interferenze da parti di altri "attori"

###### Durability
* Quando una transazione termina (detta anche committed al termine) io ho un effetto di durabilità, della transazione

La transazione potrebbe terminare in due modi:
* commit [work], quindi le operazioni sono salvate nel database
* rollback [work], le operazioni vengono scartate e il database torna allo stato precedente
Di norma la maggior parte dei database relazionali hanno la funzione di auto-commit dove ogni statement è una diversa transazione

```SQL
start transaction
  update BANKACCOUNT
    set Balance = Balance - 10
    where AccountNumber = 42177;
  update BANKACCOUNT
    set Balance = Balance + 10
    where AccountNumber = 12202;
commit work;
```