- - -
La "forma normale" è una proprietà che garantisce qualità delle relazioni dei database

una relazione è in forma **non** normale quando:
- per esempio sono presenti delle ridondanze
- ha comportamentiUna relazione 𝑟 è in forma normale di Boyce e Codd se per ogni dipendenza funzionale non banale
𝑋 → 𝐴 definita su di essa, 𝑋 contiene una chiave 𝐾 di 𝑟, cioè 𝑋 è superchiave per 𝑟. indesiderati durante gli aggiornamenti 
Solitamente le forme normali vengono definite negli modelli relazionali (in realtà anche nei modelli tipo E-R)


#### Normalizzazione
- - -
Questa operazione permette di trasformare uno schema non normalizzato in uno schema normalizzato
Deve essere utilizzata come **tecnica di verifica** per testare il design del database


Abbiamo due tipi di normalizzazione: Quella più restrittiva:

### Boyce-Codd Normal Form (BCNF)
La forma normale più importante è quella che prende il nome da Boyce e Codd (BCNF)

>[!info] Definizione: BCNF
>Una relazione 𝑟 è in forma normale di Boyce e Codd se per ogni dipendenza funzionale non banale
𝑋 → 𝐴 definita su di essa, 𝑋 contiene una chiave 𝐾 di 𝑟, cioè 𝑋 è superchiave per 𝑟.
## Non è detto che sia possibile sempre farlo!
Abbiamo infatti una scappatoia: la *3NF*
### *Third normal form*:

> [!info] Definition: Third Normal Form
> A relation $r$ is in **third normal form** if, for each non-trivial FD $X \to Y$ on $r$, at least one of the following conditions is met:
> 
> * $K \subseteq X$, $X$ is superkey in $r$
> 
> OPPURE
> * Each attribute $Y$ is in at least one key of $r$

praticamente uguale se non per l'ultimo punto.
Dobbiamo semplificare le associazioni, creare tabelle più piccoli

>[!Warning] Parole del montesone:
>Quando facciamo schemi ER occhio a fare sti diamantini perché possiamo spezzarli
>Di solito chi crea un tabellone fa economia o medicina e lo fa su EXCEL!!




