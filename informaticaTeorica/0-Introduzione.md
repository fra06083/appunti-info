- - -
16/02
domandeng:
- ha detto che gli algoritmi sono tanti quanti i numeri interi, mentre i problemi sono tanti quanti i numeri reali. Motivo per cui ci saranno problemi senza soluzioni. Perché gli algoritmi sono in egual misura dei numeri interi?
	- quanti sono i possibili programmi in python? (infiniti)
	- si possono ordinare? Si, quindi i programmi più lunghi vengo dopo quelli più corti e quelli con lunghezza uguale si ordinano per alfabeto. Quindi a questo punto si possono contare!



## Calcolabilità
- - -
Ci stiamo chiedendo se per quel determinato problema possa esistere
determinato algoritmo in grado di risolverlo.



>[!Definizione]
>Un algoritmo è una sequenza finita di istruzioni basilari, che in un tempo finito, risolve un certo problema, dati degli input. Solitamente ci viene già dato un problema e ci soffermiamo a ideare un algoritmo che lo risolva.
## Complessità
---
Quante risorse di calcolo siano necessarie a risolvere un problema calcolabile. Per risorse di calcolo intendiamo o la memoria o il tempo necessario per risolvere un'istanza del problema. Vedremo quindi che i problemi possono essere classificati in base alla loro complessità e questo ci permetterà di individuare problemi più semplici e problemi più complicati. Si studieranno le metodologie formali che permettono di
individuare la complessità intrinseca dei problemi.

- una volta che il problema è nell'area dei problemi risolvibili, si cerca di capire se è un problema facile o difficili.

>[!Warning]
>Per complessità non si intende quella studiata in algoritmi e strutture dati ma quanto sia facile o difficile un problema.

esistono tecniche che permettono di capire la complessità senza contare l'algoritmo usato

**Problema facile $\iff$ esiste algoritmo polinomiale che lo risolve**
## Decibilità
- - -
studiare la decidibilità significa: 
- dato un problema, esiste o non esiste un algoritmo che lo risolve?

ci sono problemi che non ammetteranno MAI una soluzione algoritmica (che dia **sempre** la risposta corretta)

>[!Warning]
È per SEMPRE irrisolvibile non c'entra con la potenza o altro. Dimostreremo che ha una struttura particolare.


nell'insieme dei problemi decidibili, si trovano i problemi **facili**



#### Problemi
- - -
un problema è definito come una relazione binaria tra stringhe in cui la prima stringa è l'input e la seconda è l'output
(non ci richiede come si stabilisce l'output a partire dall'input)

S -> Output


```python
ADD
x,y  x+y -> z

<I, O> # prima stringa input, secondo output atteso
<(2,3), 5>
<(1, 4), 5>
<(0, 5), 5>
<(1, 2), 3>
```

Domande esplicite su come è organizzato il problema:
cos'è l'input e come viene rappresentato?
cos'è l'output e come viene rappresentato?
che relazione c'è fra output ed input?



### HALT
- - - 
```python
<(P, I), bool> # è si se P mentre ha I si arresta sennò no.
```

programma p scritto in python (quindi una stringa) e una stringa, con output booleano. Si se il programma P, mentre ha come input I, si arresta. No se, mentre processa la stringa I, non si arresta  


PROBLEMA: HALTING
INPUT: Una stringa 𝑃 che rappresenti il codice di una one-string function
e.g. 𝑃 = "def someFunc(someString)…", e un’altra stringa 𝐼
DOMANDA: La funzione 𝑃 si ferma quando eseguita su 𝐼 come input?

**dimostriamo** che questo problema appartiene alla classe dei problemi INDECIDIBILI (non si avrà **mai** un algoritmo che danno **SEMPRE** la risposta corretta; In altre parole, non esiste un algoritmo che per ogni input 𝑃 e 𝐼, dia la risposta corretta al problema della fermata).

Dimostrazione per assurdo HALT
- - -
**supponiamo** che esista una funzione che chiamiamo `haltChecker(<P, I>)` che prende in input una coppia, programma P e una stringa I, che risolva il problema HALT
<small>nota che qui non si sta assumendo nulla, la tecnologia, il linguaggio ecc. quindi lo stiamo dimostrando in generale!</small>

```python
def reverser(P):
	# perché passiamo P e P. Perché possiamo farlo zio pera, tanto sono 
	# entrambe stringhe!
	halts = haltChecker(P, P) 
	if (halts): 
		while (true) # ciclo infinito
	else
		pass        # termina  
	 
```

siccome `reverser(P)` la possiamo chiamare,  compilare ed eseguire all'interno di un programma, come argomento gli passiamo il codice contenente la funzione stessa! Comprende tutte le casistiche possibili, si ferma o non si ferma. Guardiamo entrambi i casi:

- supponiamo che il programma si arresti (l'esecuzione di reverser si arresta sul suo stesso codice). Se si è arrestato vuol dire che è entrato nel ramo else e quindi che la variabile halts sia falsa. Ma questo implica che `haltChecker(P,P)` non si sarebbe dovuta fermare, cosa che accade dato che siamo nel ramo else

- supponiamo che il programma vada in loop, se va in loop l'esecuzione è andata in while true, cioè che halts ha ottenuto il valore vero ok ez ricorda la definizione del perché si dovrebbe fermare <(P, I), bool> # è si se P mentre ha I si arresta sennò no.