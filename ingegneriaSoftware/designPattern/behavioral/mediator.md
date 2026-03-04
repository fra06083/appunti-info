- - -
è un patter che migliora la comunicazione fra oggetti, facendo passare le comunicazioni attraverso un **mediator**. Questo diminuisce la dipendenza fra gli oggetti

componenti:
- Mediator
	- interfaccia che definisce i template dei metodi per la comunicazione degli oggetti colleghi
- concrete mediator:
	- implementa l'interfaccia mediator per la comunicazione di oggetti colleghi
- Colleague
	- interfaccia che definisce i metodi per la comunicazione con altri colleghi
- concrete colleague
	- implementa l'interfaccia colleague e i metodi per la comunicazione con gli altri colleghi, utilizza il mediator per comunicare


```python 
from abc import ABC, abstractmethod  
  
# interface colleague  
class Airplane(ABC):  
   @abstractmethod  
   def requestTakeoff(self):  
       pass  
  
   @abstractmethod  
   def requestLanding(self):  
       pass  
  
# concrete colleague  
class CommercialAirplane(Airplane):  
   def __init__(self, name, airMediator):  
       self.airMediator = airMediator  
       self.name = name  
  
   def requestTakeoff(self):  
       self.airMediator.requestTakeoff(self.name)  
  
   def requestLanding(self):  
       self.airMediator.requestLanding(self.name)  
  
# mediator  
class AirTrafficControlTower(ABC):  
   @abstractmethod  
   def requestTakeoff(self, airplane):  
       pass  
  
   @abstractmethod  
   def requestLanding(self, airplane):  
       pass  
  
# concrete mediator  
class AirportControlTower(AirTrafficControlTower):  
   def requestTakeoff(self, airplane):  
       print(f"Requesting takeoff clearance from {airplane}.")  
  
   def requestLanding(self, airplane):  
       print(f"Requesting landing clearance from {airplane}.")  
  
  
if __name__ == "__main__":  
   airMediator = AirportControlTower()  
  
   publicAirplane = CommercialAirplane("boing747", airMediator)  
   publicAirplane.requestLanding()  
   publicAirplane.requestTakeoff()
```