- - -
è un pattern che definisce un'interfaccia per la creazione di un oggetto, ma lascia decidere alla sottoclasse quale oggetto istanziare.
La creazione di un oggetto viene delegata ad un metodo.


```python
from abc import ABC, abstractmethod  
  
class Veichle(ABC):  
   @abstractmethod  
   def printVeichle(self):  
       pass  
  
class TwoWheeler(Veichle):  
   def printVeichle(self):  
       print("sono qualcosa a due ruote, ganzo")  
  
class FourWheeler(Veichle):  
   def printVeichle(self):  
       print("sono una macchina")  
  
  
class VeichleFactory(ABC):  
   @abstractmethod  
   def createVeichle(self):  
       pass  
  
class TwoWheelFactory(VeichleFactory):  
   def createVeichle(self):  
       return TwoWheeler()  
  
class FourWheelFactory(VeichleFactory):  
   def createVeichle(self):  
       return FourWheeler()  
  
if __name__ == "__main__":  
   factoryDueRuote = TwoWheelFactory()  
   moto = factoryDueRuote.createVeichle()  
   moto.printVeichle()  
  
   factoryQuattroRuote = FourWheelFactory()  
   macchina = factoryQuattroRuote.createVeichle()  
   macchina.printVeichle()
```