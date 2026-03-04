Requisiti e schemi concettuali
dopo aver riorganizzato e omogeneizzato i vari requisiti, si deve generare uno schema concettuale, utilizzando gli schemi ER.

*Domanda*:
* quale tipo di costrutto logico si utilizza per uno specifico term nei requisiti?
ripasso dei vari costrutti per rispondere:
* Entità: se il term ha delle proprietà rilevanti e descrive degli oggetti stand-alone
* attributi: se è un term semplice senza molte specificazioni
* relazioni: quando un term si riferisce ad altri term
* generalizzazione: un term è un caso più generale rispetto ad un altro

### reificazione degli attributi
ci sono un casino di esempi che honestly sono piuttosto auto esplicativi, guarda quelli!
pagina 26 fino a 32



Per mappare i requisiti in istanze di schemi ER è possibile utilizzare varie strategie
* Top-Down
* Bottom-Up
* Inside-Out

#### Top-Down
leggo i requisiti, si producono le entità, si definisco eventuali generalizzazioni ecc.

#### Bottom-Up
utile nel caso di tanti requisiti che vanno frammentati
si fanno molteplici schemi che poi verranno uniti in uno unico

#### Inside-Out
strategia che parte da un certo punto e si allarga.
Si arricchisce lo schema man mano che si leggono le informazioni.

Attenzione alla rule of thumb!!! 
Utilizza sempre uno stile mixato, prima fai uno sketch utilizzando le entità più rilevanti. Scomponi lo schema poi:
* perfezioni
* integri
* espandi
È buona pratica seguire questa metodologia:
* analisi dei requisiti
* casi base
* casi iterativi (da ripetere finché, ..., non sembra ok? uh)
* analisi della qualità (da ripetere su tutto lo schema)

##### Alcune misure
- - -
* correttezza
		tutto ciò che c'è nei requisiti lo trovo nello schema niente di più, niente di meno
* completezza
		tutto ciò che 
* chiarezza
		i concetti che sono chiesti da modellare sono stati rispettati e descritti in modo chiaro e lineare
* minimalismo
		nella sua rappresentazione quello che si sta definendo nello schema ER non deve aggiungere cose in più rispetto a quanto definito nei requisiti
	*comunque la differenza è che deve essere corretto se letteralmente ogni requisito compare nello schema, mentre e minimale se ho vari schemi ER tutti sugli stessi requsiti e c'è n'è uno che ha un requisito in più inutile, lo schema non è minimale e nemmeno corretto, di fatto è come se fossero legati* 
	pero è come se la correttezza si concentrasse solo ed esclusivamente se tutti i requisiti compaiono nello schema, il minimalismo si trova più quando si hanno più schemi diversi per gli stessi requisiti 

