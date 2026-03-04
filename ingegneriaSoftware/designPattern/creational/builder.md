è un pattern che fornisce un approccio step by step per la costruzione di oggetti complessi.
separa il processo di creazione di un oggetto dalla sua rappresentazione.
viene incapsulata la logica per la creazione di un oggetto in una classe separata 

vari componenti:
- product
	- l'oggetto complesso alla quale applichiamo il pattern
- builder
	- interfaccia/classe astratta che definisce gli step per la creazione dell'oggetto (product)
- concrete builder
	- classe che implementa gli step per la creazione di un determinato prodotto
- director (opzionale)
	- gestisce il processo di costruzione, definendo l'ordine dei passaggi

```python
'''product'''  
class Computer:  
   def __init__(self):  
       self.cpu = " "  
       self.ram = " "  
       self.storage = " "  
  
   def set_cpu(self, cpu):  
       self.cpu = cpu  
  
   def set_ram(self, ram):  
       self.ram = ram  
  
   def set_storage(self, storage):  
       self.storage = storage  
  
   def displayInfo(self):  
       print(self.cpu, self.ram, self.storage)  
  
'''builder'''  
class Builder:  
   def build_cpu(self):  
       pass  
   def build_ram(self):  
       pass  
   def build_storage(self):  
       pass  
  
   def get_result(self):  
       pass  
  
'''concrete builder'''  
class GamingComputerBuilder:  
   def __init__(self):  
       self.computer = Computer()  
  
   def build_cpu(self):  
       self.computer.set_cpu("cpu_pazza")  
  
   def build_ram(self):  
       self.computer.set_ram("ram_pazza")  
  
   def build_storage(self):  
       self.computer.set_storage("storage_pazzo")  
  
   def get_result(self):  
       return self.computer  
  
'''director'''  
class ComputerDirector:  
   def constructor(self, builder):  
       builder.build_ram()  
       builder.build_storage()  
       builder.build_cpu()  
  
  
'''client'''  
if __name__ == '__main__':  
   gaming_builder = GamingComputerBuilder()  
   director = ComputerDirector()  
      
   director.constructor(gaming_builder)  
   gaming_computer = gaming_builder.get_result()  
  
   gaming_computer.displayInfo()
   
   '''senza director'''
'''
if __name__ == '__main__': 
	gaming_builder = GamingComputerBuilder()
	gaming_builder.build_ram()
	gaming_builder.build_storage()
	gaming_builder.build_cpu()
	
	gaming_computer = gaming_builder().get_result()
	gaming_computer.display_info()
'''
```

quindi come prima cosa si definisce una classe prodotto Computer che avrà dei metodi set per la cpu, ram e lo storage, ovviamente questi vanno anche "dichiarati" tramite il metodo init, altrimenti i metodi set non avranno niente da settare

a questo punto si passa alla classe **builder**, in questo caso, `Builder` che conterrà i template dei metodi per la costruzione dell'oggetto

Ora tocca alla classe concrete builder `GamingComputerBuilder` che implementa i metodi della classe builder, ma ha bisogno al suo interno di un'istanza della classe Computer (motivo per cui si prende utilizzando l'init, così facendo stai creando una istanza specifica per quel determinato oggetto) dopodiché modifichi opportunamente i campi dell'istanza e poi la ritorni

Il main consisterà nella creazione del gaming_builder, ovvero il "contenitore" dell'istanza della classe `GamingBuilder`. Dopo avrai bisogno del director, che decide l'ordine delle operazioni da eseguire per la creazione dell'oggetto computer, queste verranno eseguite e si dovrà ritornare l'oggetto creato tramite get_result. 