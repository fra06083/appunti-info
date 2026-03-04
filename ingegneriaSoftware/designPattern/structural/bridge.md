- - -
è un pattern che permette la separazione fra astrazione ed implementazione

sono presenti due parti diverse entrambi interfacce o classi astratte: 
- astrazione 
- implementazione
vengono separati gli sviluppi dell'astrazione e dell'implementazione. Il codice del cliente può accedere alla parte di astrazione senza preoccuparsi dell'implementazione.

la parte di astrazione contiene riferimenti all'implementatore, cioè l'implementazione , inoltre 
- classi figlie dell'astrazione sono dette **astrazioni migliorate**
- classi figlie dell'implementatore sono detti **concrete implementor**

```python
from abc import ABC, abstractmethod  
  
# abstraction  
class Shape(ABC):  
   def __init__(self, color):  
       self.actualColor = color  
  
   @abstractmethod  
   def draw(self):  
       pass  
  
# refined abstraction  
class Square(Shape):  
   def draw(self):  
       print("sono un quadrato")  
       self.actualColor.fill()  
  
  
# implementor  
class Color(ABC):  
   @abstractmethod  
   def fill(self):  
       pass  
  
# concrete implementor  
class Red(Color):  
   def fill(self):  
       print("rosso")  
  
if __name__ == "__main__":  
   rosso = Red()  
  
   quadratoRosso = Square(rosso)  
  
   quadratoRosso.draw()
```
### spiegazione:
- - -
- problema:
	- immagina di avere una classe shape, poi ci sono le classi figlie square, circle ecc.
	- vuoi aggiungere un colore (che magari ha delle determinate proprietà) alle forme quindi per ogni figlia di shape fai le combinazioni, `RedSquare`, `RedCircle` ecc.
	- panico, dovresti fare un milione di combinazioni di classi

**soluzione**:
crei un abstraction `Shape`, ovvero la classe principale che delega le varie operazioni, questa conterrà un riferimento alla classe `Color`. All'interno di shape ci sarà la definizione di un metodo `draw()` che le classi shape dovranno poi implementare. Per far sì che le classi figlie di shape abbiano un colore, si definisce un `__init__(self, Color)` che prende in input la classe colore, così che le classi figlie square, circle ecc. possano ereditare quella classe, diciamo che sta qui il "bridge" concettuale.

Color, l'implementor, verrà "bridgiato" (termine inventato da me in questo momento uau) grazie alla classe shape, quindi ora le classi figlie di Shape avranno un colore!

Nel main, o codice client, si crea una classe figlia di Color (che ovviamente implementerà a modo suo i metodi template della classe Color)