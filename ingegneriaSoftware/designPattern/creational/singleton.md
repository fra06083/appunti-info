Garantisce la possibilità di creazione di una sola istanza di una determinata classe.

IN PYTHON

```python
class Singleton:
	obj = None
	@staticmethod
	def __new__(cls):
		if Singleton.obj is None:
			Sngleton.obj = super().__new__(cls)
		return Singleton.obj
```

- - -
### Con meta-classi
```python
class AnimalType(type):
	animalObj = None
	def __call__(cls, name, bases, dct):
		if AnimalType.animalObj is None:
			print("Creating the unique animal")
			AnimalType.animalObj = cls.__new__(cls, *args, **kwargs)
		return AnimalType.animalObj
		
class Animal(metalclass=AnimalType):
	#def __new__(cls, *args, **kwargs):
	#	if AnimalType.animalObj is None:
	#		print("Creating the unique singleton")
	#		AnimalType.animalObj = super().__new__(cls)
	#	return AnimalType.animalObj
	pass
```

