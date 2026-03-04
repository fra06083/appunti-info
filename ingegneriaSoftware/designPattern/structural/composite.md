- - -
ok, immagina di dover gestire un sistema di vendita di prodotti. Hai una struttura ad albero dove gli item sono le foglie e le box sono i nodi, ricorda che le box possono contenere altre box! Dato il component, classe astratta che definisce un metodo comune sia al composite che alla leaf, non è necessario sapere se si sta trattando un oggetto semplice o complesso, il risultato sarà "lo stesso". 
[sos](https://www.geeksforgeeks.org/java/composite-design-pattern-in-java/)

```python
from abc import ABC, abstractmethod  
  
# component  
class Box(ABC):  
   @abstractmethod  
   def showPrice(self) -> int:  
       pass  
  
# composite  
class AmazonBox(Box):  
   def __init__(self):  
       self.children = []  
  
   def add(self, item):  
       self.children.append(item)  
  
   def remove(self, item):  
       self.children.remove(item)  
  
   def showPrice(self):  
       fullPrice = 0  
       for child in self.children:  
           fullPrice += child.showPrice()  
       print(f"prezzo totale {fullPrice}")  
       return fullPrice  
  
# leaf  
class Item(Box):  
   def __init__(self, name, price):  
       self.name = name  
       self.price = price  
  
   def showPrice(self):  
       print(f"il prezzo dell'item {self.name} e' {self.price}")  
       return self.price  
  
if __name__ == "__main__":  
   box = AmazonBox()  
   charger = Item("charger", 20)  
   headPhones = Item("headPhones", 50)  
  
   box.add(charger)  
   box.add(headPhones)  
  
   smallerBox = AmazonBox()  
   phone = Item("phone", 300)  
   mouse = Item("mouse", 30)  
  
   smallerBox.add(phone)  
   smallerBox.add(mouse)  
  
   box.add(smallerBox)  
  
   box.showPrice()  
   box.showPrice()
```