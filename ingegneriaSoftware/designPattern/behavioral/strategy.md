- - -
è un patter che permette di prendere una famiglia di algoritmi, metterli ognuno in una separata classe per poi rendere gli oggetti interscambiabili 

componenti:
- context
	- classe o oggetto che assegna task ad uno strategy object, contiene anche un riferimento ad esso
- strategy interface
	- classe astratta/interfaccia che definisce un insieme di metodi comuni per tutte le strategie 
- concrete strategy 
	- classe che implementa i metodi della strategy interface. Questa classe contiene uno specifico algoritmo o comportamento per risolvere la task definita dalla strategy interface
- client 
	- è responsabile della corretta selezione e configurazione della strategia da dare al context

```python
from abc import ABC, abstractmethod  
# strategy interface  
class SortingStrategy(ABC):  
   @abstractmethod  
   def sort(self, array):  
       pass  
  
# context  
class SortingContext:  
   def __init__(self, sortingStrategy):  
       self.sortingStrategy = sortingStrategy  
  
   def setSortingStrategy(self, sortingStrategy):  
       self.sortingStrategy = sortingStrategy  
  
   def performSort(self, array):  
       self.sortingStrategy.sort(array)  
  
# concrete strategies  
class BubbleSortStrategy(SortingStrategy):  
   def sort(self, array):  
       print(f"using bubble sort on {array}")  
  
class MergeSortStrategy(SortingStrategy):  
   def sort(self, array):  
       print(f"using merge sort on {array}")  
  
class QuickSortStrategy(SortingStrategy):  
   def sort(self, array):  
       print(f"using quick sort on {array}")  
  
if __name__ == "__main__":  
   array1 = ["cpp","c","java","python3","csharp","html","css","javascript",  
             "php","cpp14","cobol","dart","go","julia","kotlin","lisp",  
             "matlab","node","objc","perl","r","rust","ruby","scala","swift","solidity","xml"]  
   sortingContext = SortingContext(BubbleSortStrategy())  
   sortingContext.performSort(array1)  
  
   sortingContext.setSortingStrategy(QuickSortStrategy())  
   sortingContext.performSort(array1)
```


quindi tu hai una classe context che praticamente si occupa di gestire le task, al suo interno si possono gestire e intercambiare gli algoritmi da utilizzare.

la strategy interface ha al suo interno il metodo sort che le varie classi strategie devono poi implementare. Il codice client o main, conterrà array da ordinare e istanzierà il context, dalla quale poi sceglieremo la strategia da utilizzare