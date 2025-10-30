(cortissimo, c'è stato 20 minuti :( )
## 🏗️ System Design

Attività svolta **dopo l’analisi dei requisiti** e **prima della codifica**. Definisce **come sarà strutturato il sistema**.

### Sottoinsiemi del System Design

- **Hardware Design**
    
- **Software Architecture**
    
    - Identificazione **stili architetturali**
        
    - Descrizione **del sistema ad alto livello**
        

> [!Warning] 
> Cercare di formalizzare è INUTILE!

---

## 🔧 Principali Stili Architetturali

### ✅ Pipe & Filter

- Pipeline di elaborazioni
    
- Ogni **filtro è indipendente** (non conosce sorgente o destinazione dei dati)
    
- Molto usato in **compiler** e **UNIX (comando | pipe)**
- input → filtro1 → filtro2 → filtro3 → output
- ---

### ✅ Data Abstraction & Repository

- Dati gestiti tramite **astrazioni**
    
- Componenti (attori) possono avere **esecuzione autonoma**
    
- Possibile interazione **peer-to-peer**
    

---

### ✅ Layered Architecture (a strati)

- Divide il sistema in **livelli**  
    (es. UI → Business Logic → Data Access → OS)
    
- **Separa alto e basso livello**
    
- Ogni strato usa solo quello **immediatamente sotto**
    

---

### ✅ Event-Based (a eventi)

- Basata su **eventi e listener**
    
- Il flusso dipende da **trigger esterni**
	
- Gli annunciatori di eventi non sanno chi reagirà 
    

> 📱 _Esempio:_ App Android  
> Main loop attende eventi → `while(true) wait(event)`

---
nelle slide ci sarebbe anche "repositories", non so perché qua non ci sia, magari il prof. l'ha saltato
- - -
### ✅ Interpreti

- Usata per **sistemi complessi**
    
- Si crea un **sottosistema interprete** che esegue specifiche regole/linguaggi
    
    - Esempio: interpreti SQL, JVM, interpreti di linguaggio
        

---

e poi boh, mancano tipo 40 slide. Le ha saltate? Uh