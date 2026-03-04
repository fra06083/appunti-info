- - -
è un pattern che permette di aggiungere nuove operazioni a classi già esistenti senza dover cambiare il loro codice, questo permette modularità e mantenibilità del codice.

vari componenti:
- visitor interface
	- dichiara un visit method per ogni tipo di elemento presente nell'oggetto, ognuno dei quali gestirà un determinato elemento
- concrete visitor
	- implementa i visit method dell'interfaccia. Qui è contenuta la logica che viene applicata per ogni elemento 
- element interface
	- questa interfaccia definisce un metodo `accept` che prende come argomento un visitor. Questo metodo permette al visitor la visita dei concrete elements
- concrete element
	- implementano il metodo accept, in modo da chiamare il corretto visitor.
- object structure (nell'esempio si trova nel main)
	- collezione di elementi (credo insieme di elementi concreti) sulla quale il visitor opererà, contiene metodi per l'aggiunta e/o rimozione di elementi

```python
from abc import ABC, abstractmethod  
# abstract visitor  
class ShapeVisitor(ABC):  
   @abstractmethod  
   def visitCircle(self, circle):  
       pass  
   @abstractmethod  
   def visitSquare(self, square):  
       pass  
   @abstractmethod  
   def visitTriangle(self, triangle):  
       pass  
       
# concrete visitor  
class AreaCalculator(ShapeVisitor):  
  
   def visitCircle(self, circle):  
       print(f"area cerchio {circle.radius**2*3.14}")  
  
   def visitSquare(self, square):  
       print(f"area quadrato {square.edge**2}")  
  
   def visitTriangle(self, triangle):  
       area = (triangle.b*triangle.h)/2  
       print(f"area triangolo {area}")  

# abstract element  
class Shape(ABC):  
   @abstractmethod  
   def acceptVisitor(self, shapeVisitor):  
       pass  
  
# concrete elements  
class Circle(Shape):  
   def __init__(self):  
       self.radius = 5  
  
   def acceptVisitor(self, shapeVisitor):  
       shapeVisitor.visitCircle(self)  
  
class Square(Shape):  
   def __init__(self):  
       self.edge = 10  
   def acceptVisitor(self, shapeVisitor):  
       shapeVisitor.visitSquare(self)  
  
class Triangle(Shape):  
   def __init__(self):  
       self.b = 3  
       self.h = 10  
   def acceptVisitor(self, shapeVisitor):  
       shapeVisitor.visitTriangle(self)
  
if __name__ == "__main__":  
   shapes = []  
   shapes.append(Circle())  
   shapes.append(Square())  
   shapes.append(Triangle())  
  
   areaCalculator = AreaCalculator()  
   for shape in shapes:  
       shape.acceptVisitor(areaCalculator)
```

qui il giochino sta nel fatto che dentro le classi elemento, queste chiamano il corretto e adatto metodo di visita tramite il metodo di accept.

Dentro al concrete visitor `AreaCalculator` si trova il corrispondente metodo di visita per ogni elemento, quindi la classe di per sé chiama solo il metodo non ha codice effettivo al suo interno