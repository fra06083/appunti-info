- - -
è un design pattern comportamentale che permette ad un oggetto di passare una richiesta ad una catena di gestori. Ogni gestore può decidere se risolvere la richiesta oppure passarla al prossimo gestore

componenti:
- handler interface
	- interfaccia o classe astratta, che definisce l'interfaccia per la gestione o il passaggio ad un altro handler della richiesta
- concrete handler
	- classe che implementa i metodi dentro l'handler interface, quindi implementa la gestione della richiesta e l'eventuale passaggio di essa
- client
	- invia la richiesta al primo handler della catena 
```python
from abc import ABC, abstractmethod
from enum import Enum

# --- Priority Enum ---
class Priority(Enum):
    BASIC = 1
    INTERMEDIATE = 2
    CRITICAL = 3

# --- Request Class ---
class Request:
    def __init__(self, priority: Priority):
        self._priority = priority

    @property
    def priority(self):
        return self._priority

# --- Handler Interface (Abstract Base Class) ---
class SupportHandler(ABC):
    def __init__(self):
        self._next_handler = None

    def set_next_handler(self, handler):
        self._next_handler = handler
        # Ritorno l'handler passato per permettere il concatenamento (opzionale ma comodo)
        return handler

    @abstractmethod
    def handle_request(self, request: Request):
        pass

# --- Concrete Handlers ---

class Level1SupportHandler(SupportHandler):
    def handle_request(self, request: Request):
        if request.priority == Priority.BASIC:
            print("Level 1 Support handled the request.")
        elif self._next_handler:
            self._next_handler.handle_request(request)

class Level2SupportHandler(SupportHandler):
    def handle_request(self, request: Request):
        if request.priority == Priority.INTERMEDIATE:
            print("Level 2 Support handled the request.")
        elif self._next_handler:
            self._next_handler.handle_request(request)

class Level3SupportHandler(SupportHandler):
    def handle_request(self, request: Request):
        if request.priority == Priority.CRITICAL:
            print("Level 3 Support handled the request.")
        else:
            print("Request cannot be handled.")
    
    # Nota: In Python ereditiamo set_next_handler, quindi tecnicamente
    # potremmo aggiungere un livello 4 dopo questo senza modificare il codice.
    # Nel tuo esempio Java il metodo era vuoto, qui lo lasciamo ereditato
    # ma semplicemente non lo useremo nel main per questo oggetto.

# --- Main ---
if __name__ == "__main__":
    # Creazione degli handler
    level1_handler = Level1SupportHandler()
    level2_handler = Level2SupportHandler()
    level3_handler = Level3SupportHandler()

    # Creazione della catena: L1 -> L2 -> L3
    level1_handler.set_next_handler(level2_handler)
    level2_handler.set_next_handler(level3_handler)

    # Creazione delle richieste
    request1 = Request(Priority.BASIC)
    request2 = Request(Priority.INTERMEDIATE)
    request3 = Request(Priority.CRITICAL)
    request4 = Request(Priority.CRITICAL) # Esempio extra per testare un caso non gestito (se modificassimo le priorità)

    # Passaggio delle richieste sempre al PRIMO anello della catena
    print("--- Request 1 ---")
    level1_handler.handle_request(request1)

    print("\n--- Request 2 ---")
    level1_handler.handle_request(request2)

    print("\n--- Request 3 ---")
    level1_handler.handle_request(request3)
```

lo so, lo so. È fatto con l'ai, lo stavo scrivendo io, ho fatto un casino e ho perso il file. Questo pattern mi ha stancato..

ci sarà un handler generico, ovvero l'interface handler, che definisce il metodo per la risoluzione della richiesta. E un metodo per settare il prossimo handler, questo andrà fatto nel main.

per ogni concrete handler implemento il metodo handlerequest in cui controllo prima se l'oggetto request lo posso "handlare" con questo handler. In caso positivo printo successo, altrimenti, se è stato dato valore al nextHandler (attributo non presente nella classe stessa ma ereditato dalla classe astratta), chiamo il metodo handleRequest di quel nextHandler

nel main vado a istanziare i 3 handler e le 3 request con priorità diverse