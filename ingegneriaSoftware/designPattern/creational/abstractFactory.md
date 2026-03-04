è un pattern che fornisce un'interfaccia per la creazione di famiglie di oggetti legati/dipendenti fra di loro, senza dover specificare la classe concreta.

fa un po' da creatore di fabbriche che producono a loro volta specifici oggetti che però sono legati fra loro!
Tu crei una furniture che ha tutti mobili moderni o vittoriani, non un misto.

```python
from abc import ABC, abstractmethod  
  
  
class Chair(ABC):  
   @abstractmethod  
   def sitOn(self):  
       pass  
class Sofa(ABC):  
   @abstractmethod  
   def sitOnSofa(self):  
       pass  
class Table(ABC):  
   @abstractmethod  
   def eatOn(self):  
       pass  
  
class ModernChair(Chair):  
   def sitOn(self):  
       print("seduta moderna")  
  
class ModernSofa(Sofa):  
   def sitOnSofa(self):  
       print("seduta sul sofa moderna")  
  
class ModernTable(Table):  
   def eatOn(self):  
       print("mangiata moderna")  
  
class FurnitureFactory(ABC):  
   @abstractmethod  
   def createChair(self):  
       pass  
   @abstractmethod  
   def createSofa(self):  
       pass  
   @abstractmethod  
   def createTable(self):  
       pass  
  
class ModernFurniture(FurnitureFactory):  
   def createChair(self):  
       return ModernChair()  
  
   def createSofa(self):  
       return ModernSofa()  
  
   def createTable(self):  
       return ModernTable()  
  
  
def clientCode(factory):  
   chair = factory.createChair()  
   sofa = factory.createSofa()  
   table = factory.createTable()  
  
   chair.sitOn()  
   sofa.sitOnSofa()  
   table.eatOn()  
  
if __name__ == "__main__":  
   modernFactory = ModernFurniture()  
      
   clientCode(modernFactory)
```