- - -
è un pattern che fa da ponte. Permette ad un client di utilizzare una classe esistente, magari non aggiornata o non adatta, tramite l'utilizzo di una classe wrapper adapter.


```python
from abc import ABC, abstractmethod  
  
# target  
class Printer(ABC):  
   @abstractmethod  
   def printing(self):  
       pass  
  
# adaptee  
class LegacyPrinter():  
   def printDocument(self):  
       print("ciao sono una stampante vecchia")  
  
# adapter  
class PrinterAdapter(Printer):  
   def __init__(self):  
       self.legacy_printer = LegacyPrinter()  
  
   def printing(self):  
       self.legacy_printer.printDocument()  

# client  
if __name__ == "__main__":  
   printerAdapter = PrinterAdapter()  
  
   printerAdapter.printing()
```


qui il client utilizza l'adapter per poter usufruire della classe `adaptee` che per varie ragioni, non aggiornata, obsoleta, non compatibile ecc. non può essere utilizzata direttamente. `Adapter` implementa il metodo della classe astratta target (dove target è "l'effetto" che il client si aspetta di avere) facendo da tramite per l'utilizzo della classe `adaptee`.
- ricorda che il client non deve sapere l'esistenza della legacy_printer, lui pensa di avere davanti una stampante!