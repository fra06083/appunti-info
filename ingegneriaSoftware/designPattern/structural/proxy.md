- - -
è un pattern strutturale, che fornisce un'interfaccia per il controllo dell'accesso ad un particolare oggetto, permettendo di fare operazioni prima o dopo l'accesso ad esso

per esempio il caricamento di un'immagine pesante su un sito. Un oggetto placeholder proxy viene messo al posto dell'immagine effettiva, quando questa non è visualizzata

principalmente si utilizza il concetto di lazy initialization, onde evitare carichi troppo pesanti, che causerebbero lentezza nel sistema. C'è anche un utilizzo concettuale della cache!

componenti 
- subject
- concrete subject
- proxy
```python
from abc import ABC, abstractmethod  
  
# subject  
class Image(ABC):  
   @abstractmethod  
   def display(self):  
	       pass  
  
# concrete subject  
class RealImage(Image):  
   def __init__(self, name):  
       self.name = name  
       self.loadFromDisk()  
  
   def loadFromDisk(self):  
       print("ueue sto caricando dal disco, ci metto del tempo")  
  
   def display(self):  
       print(f"zio pera, nome immagine: {self.name}")  
  
# proxy  
class Proxy(Image):  
   def __init__(self, name):  
       self.name = name  
       self.realImage = None  
  
   def display(self):  
       if self.realImage is None:  
           self.realImage = RealImage(self.name)  
       self.realImage.display()  
  
if __name__ == "__main__":  
   image = Proxy("gattong")  
  
   # caricamento lento dell'immagine a causa della lettura  
   # dal disco  
   image.display()  
  
   # in questo caso l'immagine non verrà caricata dal disco  
   # ma è presente nella cache del proxy, quindi si ha un  
   # riscontro più veloce  
   image.display()
```

idealmente l'utente non sa nulla di come viene gestita la cosa in background, lui inserisce il nome del file da visualizzare e boom, funziona in modo celere

ci sarebbe anche l'esempio del davidone dove il proxy controlla se prima del pagamento ci siano abbastanza soldi sul conto

todo: fare sul tablet