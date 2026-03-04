- - -
questo pattern viene utilizzato quando la creazione di un determinato oggetto diventa lunga e costosa. Quindi si creano oggetti a partire da copie di oggetti già esistenti

```python
class Shape():    
   def clone(self):  
       pass  
  
class Circle(Shape):  
      
   def __init__(self, radius):  
       self.radius = radius  
  
   def clone(self):  
       return Circle(self.radius)  
  
  
if __name__ == '__main__':  
   circle = Circle(10)  
  
   cerchio = circle.clone()  
  
   print(circle.radius)  
  
   print(cerchio.radius)  
  
   print(circle == cerchio)
```

il prototype pattern è utile quando si devono creare molteplici oggetti che hanno piccole differenze fra di loro.

un esempio di utilizzo è dato dalle applicazioni come paint o photoshop, che permettono di disegnare molteplici forme in base a quella selezionata, quadrato, cerchio, triangolo ecc.
Quando una forma viene selezionata si fa una copia di quell'oggetto per permettere all'utente di disegnarlo