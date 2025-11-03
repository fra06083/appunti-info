- - -
#### Concetto di Referential Transparency:
Le variabili non cambiano valore
risultato delle operazioni non cambia se scambio le operazioni.
```python
x = "abc"
```
le variabili sono immutabili posso solo ricreare nuove stringhe




| Immutabilità                                          | Trasparenza referenziale                                                                     |
| ----------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| Un valore non può essere modificato dopo la creazione | Puoi sostituire un’espressione con il suo valore senza cambiare il significato del programma |
l'immutabilità fa avere trasparenza referenziale

nelle liste, occhio alla differenza fra la copia: tramite l'utilizzo dell'operatore "=" e `w.copy()`



Esempio succi:

```python
x = [1,2,3]
y=x
z= x.copy()
```

esecuzione

| x   | @300 |
| --- | ---- |
| y   | @300 |
| z   | @400 |
|     | 3    |
|     | 2    |
| 300 | 1    |
|     |      |
|     | 3    |
|     | 2    |
| 400 | 1    |
x e y sono stessa cosa, z è una sua copia

##### Tuple!
- - -
Collezione di dati **immutabili** ed **ordinati**, con una sintassi simile a quella degli array
```python
aTuple=("touple", 2, 9, [10, 2, 3], "start")
aTuple 
(’touple’, 2, 9, [10, 2, 3], ’start’)
```

la copy per le tuple non esiste, dato che è presente l'operatore di "=" che fa una copia, elemento per elemento in memoria ! Per copiare tutti gli elementi interni, si può utilizzare la `deepcopy`, **(che non ho ben capito uhhhhhhhhhhh, differenza in memoria tra uguale e deepcopy aiuto).**

##### Sets 
- - -
collezione di dati disordinati e immutabili, **senza duplicati** 
le operazioni gasanti sono l'unione `|` e l'intersezione `&`. 

##### Dictionaries
- - -
collezione ordinata di coppie, `chiave:valore` indicizzati da una chiave, dove ogni chiave è **univoca**!



Costrutti per uscire fuori dai loop:

Break come in C
continue passa al flusso successivo del loop (continua esecuzione)
pass: non esegue quello dopo ma vado al blocco successivo, **questo da riguardare**



##### Iterators
- - -
a parole è più complicato che con del codice:
```python
string = "iter"
stringIterator = iter(string)
print(next(stringIterator))
print(next(stringIterator))
print(stringIterator.__next__())
print(stringIterator.__next__())

print(stringIterator.__next__())

# verrà stampato i, poi t, e, r e un errore 
```

ci sono anche gli iterable
anche command line arguments

`__` richiama un metodo privato ma a quanto pare non serve ad un pipo perché si può chiamare comunque wtf.


### Python as an imperative language
- - -
<small> In informatica, la programmazione imperativa è un paradigma di programmazione secondo cui un programma viene inteso come un insieme di istruzioni, ciascuna delle quali può essere pensata come un "ordine" che viene impartito alla macchina virtuale del linguaggio di programmazione utilizzato.</small>



**funzioni anonime**
- - -
Le funzioni anonime, anche dette funzioni lambda:
```python
def apply(f, a);
	return f(a)
def main():
	x = apply(lambda x: x+1.3)
	y = apply(lambda x: x+2.4)
	print(x,y)
if __name__ == "__main__": // se è la funzione principale.
	main();
```
```bash
python example.py
> 16
```

**nested functions** . . .


#### Regole di scope
- - -
Scoping rules (3/5)
# scoping.py
```python
x = 5
def testScope(a):
	y = x + a
	global z
	z = y + 1
	return y + z
def main():
	print (testScope(5) + z)
if __name__ == "__main__" :
	main()
```
```bash
% python3 scoping.py

32
 ```


esempio:
```python
x = 1
y = 2
w = 3
z = 4

def testScope():
    y = 20
    w = 30
    k = z
    def testInnerScope():
        w = 300
        global x
        nonlocal y
        x = 100
        y = 200
        z = 400
        print(f"testInnerScope: x={x},y={y},w={w},z={z}") 
    testInnerScope()
    print(f"testScope: x={x},y={y},w={w},z={z}")

def main():
    testScope()
    print(f"main: x={x},y={y},w={w},z={z}")

if __name__ == "__main__":
    main()
```

`nonlocal` definisce che deve prendere la prima definizione non locale che trova fuori

quando viene chiamata la funzione testScope() io creo un'altra variabile y, another w e k che equivale alla z globale.

poi viene chiamata testInnerScope(), viene creata una nuova variabile w = 300. Global x dice che da quel momento in poi dentro la funzione verrà utilizzata la x globale! nonlocal y (def scritta sopra di nonlocal). Modifico la x globale, la y di testScope e pongo (una nuova) z uguale a 400