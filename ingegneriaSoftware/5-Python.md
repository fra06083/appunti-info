- - -
#### Concetto di Referential Transparency:

il valore del riferimento è trasparente, ovvero che il valore non dipende dall'ordine di esecuzione delle operazioni (Puoi sostituire un’espressione con il suo valore senza cambiare il significato del programma)

Le variabili non cambiano valore
risultato delle operazioni non cambia se scambio le operazioni.
```python
x = "abc"
```
le variabili sono immutabili posso solo ricreare nuove stringhe

```python
y = x + 'd'
``` 
```bash
% "abcd" 
```

| Immutabilità                                          | Trasparenza referenziale                                                                     |
| ----------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| Un valore non può essere modificato dopo la creazione | Puoi sostituire un’espressione con il suo valore senza cambiare il significato del programma |

### l'immutabilità fa avere trasparenza referenziale

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

tupla = (4, 3, 2) # da notare che la tupla si identifica dalla virgola non dalla tonda
tuplaInvalida = (4) # non va, diventa int
tuplaValida = (4, )

> tupla
% (4, 3, 2)
```

la copy per le tuple non esiste, dato che è presente l'operatore di "=" che fa una copia, elemento per elemento in memoria ! Per copiare tutti gli elementi interni, si può utilizzare la `deepcopy`.

![[esempioShallowDeepCopy.png|0x0]]


- Spiegazione SUCCI: Quando ho una struttura dati (array puntatori) mi copia fisicamente l'array.
opzione 1: q=p prende lo stesso indirizzo
opzione 2 copy (a destra): q->50 q->70 hanno gli stessi dati ma sono copiati in altre parti
opzione 3 (deepcopy): mi copio le strutture dati come liste, in una allocazione di memoria
![[esempioDiQualcosaAllaLavagna.png|378x504]]
questa img non ricordo di cosa sia scusa mi sono scordaro
##### Sets 
- - -
collezione di dati disordinati e immutabili, **senza duplicati** 
le operazioni gasanti sono l'unione `|` e l'intersezione `&`. 
```python
thisset = {"apple", "banana", "cherry", True, 1, 2} # 1 e True sono considerati uguali
> thisset
secondset = {"c"}
thirdset = thisset | secondset
> thirdset
% {"apple", "banana", "cherry", True, 1, 2, "c"}
third
>
```

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
#### scoping.py
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
- - -
### Moduli
La struttura è simile a C; il nome del modulo è il nome del file senza estensione ed è messo in `___name__` se è chiamato direttamente `__main__`


```python
import amodule
```
e il file deve essere caricato nell'environment `PYTHONPATH`
>[!Warning] Se non carico il nome ma tutto amodule devo effettivamente specificarlo sempre con:

```python
from amodule import goofy
```
- - - 

### namespace
- - -
Insieme di tutti i nomi associati visibili in un determinato periodo in un determinato posto
Il namespace corrente è accessibile con l'istruzione `dir()`
E' anche possibile vedere il namespace di un determinato modulo: `dir(amodule)`

### Packages
- - -
Un package è un insieme di moduli. Dentro la lista specificata sys.path
con un `___init__.py` file che può essere anche vuoto.

QUINDI
> Quando un pacchetto viene caricato viene eseguito l'init.


*fine parte python come linguaggio imperativo*


# Python come linguaggio funzionale
- - - 
Lambda expression e immutabile.

Da w3schools: A lambda function can take any number of arguments, but can only have one expression.
### OVERLOADING
- - - 
In java c'è overriding ma non overloading
In python non è presente il full overloading delle funzioni. Nel caso di definizioni multiple con lo stesso nome di una funzione, solo l'ultima definizione verrà utilizzata
>[!Info] L'overloading serve per funzioni che possono avere tipi diversi di variabili e avere un tipo diverso in base alla variabile passata. Es. passo 2 int mi fa la somma, passo 2 stringhe me li concatena...

nota: è possibile passare funzioni come parametri.
controlla *map, filter, reduce*

|             | Spiegazione: <br>                                                                                                                                                                                                    |
| ----------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Overloading | è una tecnica di programmazione che consente di definire più funzioni o metodi con lo stesso nome, ma con tipo e/o numero di parametri diversi NON PRESENTE IN JAVA                                                  |
| Overriding  | significa **sovrascrivere** o **ridefinire** un metodo ereditato da una superclasse in una sottoclasse, mantenendo lo stesso nome, gli stessi parametri e lo stesso tipo di ritorno per modificarne il comportamento |
##### Lazy evaluation
- - -
*yield* permette di restituire on demand un singolo iteratore
>[!info]
>da w3chools: *The `yield` keyword is used to return a list of values from a function.*

Cosa si può fare con le liste:
![[listComprehension.png]]


con zip io ritorno un iteratore di tuple
![[beyondListComprehension.png|663x355]]


# Python come linguaggio ad oggetti
- - -
da certi punti di vista python è anche un linguaggio ad oggetti! Le classi sono definiti con `class`. Per riferirsi al oggetto in sé si usa `self`, l'inizializzatore, simile al costruttore è definito tramite `__init__`, le variabili di istanziazione sono spesso definite dentro il costruttore.

Le variabili di classe sono definite globalmente dentro la classe, i metodi delle classi sono definiti con `@classmethod decoration` una referenziazione alla classe `cls` e con la solita indentazione 


### Ereditarietà
- - -
* python supporta ereditarietà singola e multipla.
* ogni classe senza una super classe è implicitamente derivata dalla classe `object`
* Un oggetto `object` è di tipo TIPO (`type`)
* quando un nuovo oggetto viene creato il metodo di inizializzazione `__init__` viene chiamato
```python
class Dog(Animal):
	def __init__(self, name):
		super().__init__(name)
	def identifyYourself(self):
		print("Hello! I am a dog and my name is " + self.name)

```


parlando di `__init__` :3 questo è un inizializzatore. 
Se mancasse `__init__`, viene chiamato `__init__` dalla prima classe padre.

esempio
Animal è un oggetto a cui applico il metodo `()`, questo metodo mi ritorna un oggetto istanza.
```python
class Parrot(Animal): 
	def __init__(self): 
		super().__init__() 
		print("Creating a parrot") 
class Dove(Animal):
	pass
class Penguin(Animal):
	def __init__(self):
		print("Creating a penguin")
 
if __name__ == "__main__": 
	a = Animal() # Creating an animal
	pe = Penguin() # Creating a Penguin
	pa = Parrot() # Chiama prima la superclasse poi parrot 
	d = Dove() # ha il pass non ha init -> superclasse
	
'''
output:
Creating an animal 
Creating a penguin 
Creating an animal 
Creating a parrot 
Creating an animal
'''
```

### Operator overloading
- - -
Tipo speciale di funzioni!
![[overloadingOperatoriEsempio1.png|550x334]]
(altro esempio a pagina 113)
#### Tutti gli operatori presenti:
- `getitem (self,index)` for subscripting in the rhs, that is the x = anObject[index]
- `setitem (self,index)` for subscripting in the lhs, that is the anObject[index] = x contains (self,index) for the in operator
- `repr (self)` to convert an object in a string, used in print with the template pattern
- `iter (self)` to generate an iterable, like iter(anObject) to use then, say, in a for
- `enter (self)` and `exit (self,...)` to handle entering and exiting blocks

`__call__` permette di chiamare oggetti funzionali, per gestire determinate strutture, idk quali. 


---
Un oggetto in python ha un'identità un valore o uno stato definito dagli attributi, un tipo o una base (simile ad una superclasse)
```python
>>> type(3)
<class ’int’>
>>> type(animal)
<class ’__main__.Animal’>
>>> type(dog)
<class ’__main__.Dog’>
>>> type(int)
<class ’type’>
>>> type(Animal)
<class ’type’>
>>> type(Dog)
<class ’type’>
>>> type(object)
<class ’type’>
>>> type(type)
<class ’type’>
```

`dir()` da l'elenco dei metodi che posso richiamare su una determinata classe passata come parametro


### Metaclassi
una metaclasse è una classe le cui istanza sono delle classi
zio pera è come se fossero dei generatori di classi


Creo al volo un oggetto:
```python
>>> Cat = type("Cat",(Animal,),{"nickname":"Prr", "weight":10}) // creazione oggetto
>>> c = Cat("Garfield")
>>> print(c)
<__main__.Cat object at 0x11148fa90>
>>> print(c.nickname)
Prr
>>> print(c.weight)
10
>>> print(c.name)
Garfield
```

**processo di creazione:**
```python
dog = Dog()
```
`__call__` --> `__new__` -> `__init__`

new alloca spazio prima di istanziare l'oggetto
per creare oggetti della classe `Dog` 

encore sulle metaclassi:
nella metaclasse inserisco informazioni che aiutano a costruire il tipo e non all'istanza del tipo. 

cls è il metodo che passiamo, per poter accedere ai metodi di classe. È il "puntatore" alla classe che permette di accedere alla variabile di classe `_instances` (questo di pagina 152)

- - -
qua tutta la roba che manca sui type hints


- - -

### Reflection and Introspection
- - -
* introspezione: ovvero l'abilità di poter scoprire informazioni su un oggetto a runtime
* riflessione: estende l'introspezione, permettendo la modifica degli oggetti a runtime



### Decoratori
- - -
I decoratori sono delle funzioni di ordine superiore, che permettono di alterare dinamicamente il comportamento delle funzioni o delle classi.

tre tipi principali di decoratori:
* di funzione
* di metodo
* di classe
```python
def decorator_name(func): # ’func’ represents the function being decorated
	def wrapper(*args, **kwargs):
		# Code before
		result = func(*args, **kwargs)
		# Code after
	return result
return wrapper
@decorator_name
def function_to_decorate():
pass
```
###### Decoratori di classe
- - - 
- 
un metodo statico è un metodo che viene messo all'interno per ragioni di visibilità (questione di coesione)

un metodo di classe mi permette di accedere agli attributi ma non a quelli di istanza


class method non può accedere agli attributi di istanza

> owner serve a specificare la classe di cui fa parte, viene istanziato automaticamente a class. Fa riferimento a cls (cls: parametro che passiamo ai metodi di classi per poter accedere ai parametri di classe.)


```python
def add_class_name(cls):          # cls is the class being decorated
	cls.class_name = cls.__name__ # Add a new attribute ’class_name’
	return cls                    # Return the modified class

@add_class_name                   # Apply the decorator to the Person class
class Person:
	pass
print(Person.class_name) # Access the added class attribute

# Output:
# Person
```
che stronzo però sincero cioé 45 minuti come cazzo fai dio *****ti********* non farmi agitare sennò scuoio e finisco al tg




@property sembra trasformare il metodo in una variabile

è possibile applicare più decoratori tramite:
* decorator chaining -> passo un decorator ad un altro decorator

Fine tortura esame PAGINA 193. ne- 1+9+3 fa 13.... numerologia fa fortuna. 


```python
'''prof quando vado ad utilizzare 2 decorators su una funzione
ma entrambi i decorator vanno a fare qualcosa sia prima che dopo la chiamata della funzione, in che ordine vengono eseguite le cose?'''
dec1:
     print('1')
     func()
      print('2')

dec2:
     print('3')
     func()
      print('4')

@dec2
@dec1
func()

'''
l'output da quanto mi pare di aver capito è 
3
1
func()
2
4
'''
```
