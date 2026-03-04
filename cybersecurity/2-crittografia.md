- - -
20/02
Nella crittografia gli step principali sono:
- denotare e descrivere un preciso modello di pericolo 
- proporre una costruzione
- provare che "rompere" la costruzione sotto il modello di pericolo definito in precedenza, può risolvere un 


#### criptazione a chiave simmetrica:
- - -
img a pagina 12, magari da mettere su imgur

due tipi di use case:
- single-use key, quindi utilizzo la chiave per criptare un solo messaggio

- multi-use key, stessa chiave per criptare molteplici file 

#### criptazione a chiave asimmetrica
- - -
presenza di due tipi di chiave:
- **pubblica**
- **privata**
In questo caso si possono utilizzare le chiavi in modo particolare per diversi scenari, per esempio garantire la firma digitale.
da notare che la firma della stessa persona può cambiare sui diversi documenti

#### piccolo cenno storico 
- - - 
Il cifrario di Cesare fu uno dei primi esempi di crittografia. Data una chiave che denotava il numero di shift dell'alfabeto, si cifrava il messaggio shiftando le lettere in base a quella chiave

#### shift cipher
- - -
Questa tecnica è anche detta **shift cipher**. Dal punto di vista matematico si ha: $$\large \exists k\in K, 0\leq K \leq 25$$ $$\large e_k(p) = p + k \quad mod 26 \quad \text{ e } \quad d_k(c) = c-k \quad mod26 $$ in realtà è molto ez da rompere. Basta andare di brute force e calcolare i possibili messaggi con tutte e 26 le chiavi
a pagina 33 c'è un esempio specifico.

#### monoalphabetic substitution cipher
- - -
Una versione più strong del shift cipher è il $\Large \text{monoalphabetic substitution cipher}$
Dove lo spazio di K di possibili chiavi è dato dall'insieme di possibili permutazioni dell'alfabeto

ogni lettera del messaggio viene mappata su una lettera che appartiene all'alfabeto che appartiene all'insieme di permutazioni. Nel caso di un attacco brute force, le possibili combinazioni per azzeccare la chiave sono 26! quindi siamo nell'ordine del $\large 10^{26}$, un numero grandino insomma..
**Fuck brute force**, ora si utilizza la testa. Entra in gioco la **letter frequency analysis**:
- dato il messaggio cifrato e un particolare schema che indica la maggior frequenza di una lettera in una determinata lingua, si vanno a confrontare le lettere che hanno maggiore frequenza 



Un'altra versione di cipher per sostituzione è l'**affine cipher**, dove la funzione di criptazione è $$\large e(x) = ax+b(mod 26) \quad a,b\in Z_{26}$$ecco che tornano le congruenze della Morigi..
In questo caso la chiave è composta dalla coppia (a,b)
Per poter applicare questa tecnica è necessario che la funzione sia **iniettiva** e quindi basta studiare la congruenza $$\large ax\equiv y \pmod{26}$$da notare che la congruenza ha una sola soluzione se e solo se $\large gcd(a, 26) = 1$ 
svolti degli esercizi d'esame su questa tecnica


#### Vigenère cipher
- - -
cifraggio a sostituzione polialfabetica :3
ogni lettera del messaggio può essere sposta di tot valori

dato un valore m positivo che indicherà la lunghezza della keyword, 
si suddivide il messaggio originale in sotto messaggi, nella quale ogni lettera verrà mappata nella posizione (posizione all'interno dell'alfabeto) descritta dalla keyword corrispondente in mod 26 
formalmente per criptare: $$\large e_k(p_1,p_2,...,p_m) = (p_1+k_1, p_2+k_2, ..., p_m+k_m) \pmod{26}$$per decriptare: $$\large d_k(c_1,c_2,...,c_m) = (c_1-k_1, c_2-k_2, ..., c_m-k_m) \pmod{26}$$esempi a pagina 49
per rompere questa tecnica "basterebbe" trovare la lunghezza m

