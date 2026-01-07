Si parla prima di database passivi:
> [!Info] Prima usavamo database passivi?
> Ni, perché usavamo comportamenti reattivi nei database come `on delete | updated` e `cascade | set null | set default | no action`. Non sono passivi in senso stretto ma fanno parte della logica interna del database e non della nostra applicazione: reagiscono agli eventi, ma non eseguono flussi complessi né prendono decisioni autonome.

## Database Attivi
Evento-Condizione-Azione
- Eventi sono cambiamenti che avvengono nella base di dati
- Una condizione è verificata in base ad un valore vero/falso
- Una o più azioni vengono eseguite
Questi database hanno un comportamento reattivo (quindi l'opposto di passivo) Non eseguono solo le transizioni dell'utente ma anche le regole

La parte dopo serve poco, serve per introdurre le Tabelle e i *TRIGGER*, come sappiamo utilizziamo un front-end per visualizzare i dati, backend per collegarsi al db.

Non possiamo ficcare sopra il front-end un LLM per due motivi: Consumo di corrente e batteria ma va messo in fondo (???? like se lo mettessimo sopra grazie al cazzo;r.d)

I database che hanno regole attive (TRIGGER)
## TRIGGER
- Definiti da DDL (Data Definition Language) con estensione `create trigger`
-> Basati su eventi-condizione-azione

> [!Example] Esempio
> Evento: `insert, delete, update`
> Condizione: Predicato SQL
> Azione: sequenza di istruzioni SQL :D
> 
> Quando accade un evento (attivazione), se la condizione è soddisfatta (verifica) esegui le azione (esecuzione [no way!!])

Devono essere **IMMEDIATI** (prima o dopo evento) o differita al tempo della fine della transizione (commit).
## Active Database Regole semantiche

* Let $T^U = U_1; \dots ;U_n$ be the user transaction
* If the rules of $P$ have form $E, C \rightarrow A$ with $E$ event, $C$ condition and $A$ action, then:
	* **Immediate** semantic generates:
	  $$\LARGE T^I = U_1; U^P_1; \dots U_n; U^P_n \text{ mettiamo le regole insieme agli eventi}$$
	* **Deferred** semantic generates:
	  $$\LARGE T^D = U_1; \dots U_n; U^P_1; \dots ; U^P_n \text{qui li cacciamo in fondo}$$

> [!INFO] Note
> Where $U^P_i$ represents the actions induced **<u>by</u>** $U_i$ on $P$.

* **Problems:**
	* Termination
	* Confluence
	* Equivalence
## SQL TRIGGER Sintassi Generale
La struttura definisce le regole Evento-Condizione-Azione (ECA).
grazie chattie!!! 💜

> [!abstract] Legenda Sintassi
> * **`{ ... | ... }`**: Scelta **obbligatoria** tra le opzioni (OR).
> * **`[ ... ]`**: Clausola **opzionale**.
> * **`maiuscolo`**: Parole chiave SQL.
> * **`corsivo`**: Variabili definibili dall'utente.

```sql
CREATE TRIGGER triggerName
    -- 1. TIMING (Obbligatorio)
    { BEFORE | AFTER }
    
    -- 2. EVENTO (Obbligatorio)
    { INSERT | DELETE | UPDATE [OF column] }
    ON targetTable

    -- 3. VARIABILI DI TRANSIZIONE (Opzionale)
    -- Permette di accedere ai dati prima/dopo la modifica
    [REFERENCING 
        -- Accesso all'intero set di righe modificate (per Statement-level)
        { [OLD TABLE [AS] oldTableVar]
          [NEW TABLE [AS] newTableVar] } 
        |
        -- Accesso alla singola riga (per Row-level)
        { [OLD [ROW] [AS] oldTupleVar]
          [NEW [ROW] [AS] newTupleVar] }
    ]

    -- 4. GRANULARITÀ (Opzionale - Default: Statement)
    [FOR EACH { ROW | STATEMENT }]

    -- 5. CONDIZIONE (Opzionale)
    -- Se falsa, l'azione non viene eseguita
    [WHEN condition]

    -- 6. AZIONE (Body)
    SQLProceduralStatement;```
