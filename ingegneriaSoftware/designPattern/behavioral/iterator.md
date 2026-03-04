- - -
è un patter che permette il traversamento degli elementi di una determinata collezione senza esporre la sua effettiva rappresentazione (list, stack, tree, ecc..)

sono presenti quattro componenti principali:
- iterator
	- classe astratta/interfaccia per l'accesso o per traversare gli elementi della collezione
- concrete iterator
	- classe che implementa a tutti gli effetti i metodi per il traversamento definiti nell'interfaccia
- aggregate (o iterable collection)
	- classe astratta/interfaccia che definisce i metodi per la creazione degli iteratori
- concrete aggregate (o concrete collection)
	- classe che rappresenta la collezione di oggetti e che implementa i metodi per la creazione dell'iteratore

in teoria per l'esempio fatto servirebbe anche una classe semplice employee

```python
from abc import ABC, abstractmethod  
  
# iterator  
class Iterator(ABC):  
   @abstractmethod  
   def hasNext(self) -> bool:  
       pass  
  
   @abstractmethod  
   def next(self):  
       pass  
  
  
# concrete iterator  
class EmployeeIterator(Iterator):  
   def __init__(self, employees):  
       self.employees = employees  
       self.currentIndex = 0  
  
   def hasNext(self):  
       return self.currentIndex < len(self.employees)  
  
   def next(self):  
       if not self.hasNext():  
           raise StopIteration("panico")  
  
       nextEmployee = self.employees[self.currentIndex]  
       self.currentIndex += 1  
       return nextEmployee  
  
  
  
# aggregate  
class Aggregate(ABC):  
   @abstractmethod  
   def createIterator(self) -> EmployeeIterator:  
       pass  
  
# simple object  
class Employee:  
   def __init__(self, name, salary):  
       self.name = name  
       self.salary = salary  
  
   def getSalary(self):  
       return self.salary  
  
# concrete aggregate  
class Company(Aggregate):  
   def __init__(self):  
       self.employees = []  
   def addEmployee(self, employee):  
       self.employees.append(employee)  

   def createIterator(self):  
       return EmployeeIterator(self.employees)  
  
  
if __name__ == "__main__":  
   totalSalary = 0  
   company = Company()  
  
   company.addEmployee(Employee("Alice", 50000))  
   company.addEmployee(Employee("Bob", 60000))  
   company.addEmployee(Employee("Charlie", 70000))  
  
   companyIterator = company.createIterator()  
  
   while companyIterator.hasNext():  
       emp = companyIterator.next()  
       totalSalary += emp.getSalary()  
  
   print(totalSalary)

```