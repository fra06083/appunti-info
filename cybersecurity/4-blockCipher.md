ay- - - 
27/02

parti da un blocco plain text di n bits
per poi crittarlo tramite un algoritmo 

esempi reali
- DES
	- n = 64 bits e chiave k = 56 bits (dal punto di vista teorico sono 56 bit, mentre poi nella realtà sulle macchine si lavora con potenze di due e quindi si avrà una chiave da 64. All'esame sarà richiesto di utilizzare 56 bit)
- 3DES
	- n = 64 bits e chiave k = 168 bits
- AES 
	- n = 128 bits e chiave k = 128, 192, 256 bits

come funzionano però questi blocchi?
si fa un'espansione della chiave e per ogni n-esima chiave ottenuta si applica a catena una Round Function su m i-esimo con k i-esimo

- DES usa 16 iterazioni
- 3DES usa 48 iterazioni
- AES-128 usa 10 iterazioni


### DES - data encryption standard
- - - 
Feistel Network
date d funzioni $\large f_1, ... f_d: \{0,1\}^{2n} \to \{0,1\}^{2n}$ non necessariamente invertibili, il main goal è quello di calcolare una funzione invertibile $\large F: \{0,1\}^{2n} \to \{0,1\}^{2n}$ 
R è la parte destra del messaggio, mentre L è la parte sinistra del messaggio

in simboli avrai $\large R_{i-1} = L_i$ e $\large R_i = f_i(L_i) \oplus L_{i-1}$ quindi posso ricavare che $$\large L_{i-1} = f_i(L_i)\oplus R_i$$ricorda che lo xor di qualcosa con sé stesso dà zero
il circuito per decifrare è praticamente identico con le funzioni che vengono applicate in ordine inverso quindi dalla funzione d alla funzione 1

**16 round Feistel network**
$\large f_1, ... f_16: \{0,1\}^{32} \to \{0,1\}^{32}$ 
con k_i è una sotto-chiave e una certa permutazione di bit selezionati di k

Parto da una chiave iniziale, tramite la matrice PC1 che è nota (presente nelle slide), questa definisce le posizioni da mettere in $\large c_0$ e $\large d_0$dei bit presenti nella chiave originale; ricorda che ignoro i parity bit!

faccio uno shift a sinistra (uh), unisco c1 e d1 e faccio la stessa cosa che ho fatto con PC1 ma utilizzando la matrice PC2 e così via

un problema di DES è dato dalla possibile presenza del sub **key collision problem**, cioè se parto da una chiave debole può capitare che la stessa sub-key venga generata in più round
queste sono le chiavi weak che generano il problema:
- `01010101 01010101`
- `FEFEFEFE FEFEFEFE`
- `E0E0E0E0 F1F1F1F1`
- `1F1F1F1F 0E0E0E0E`


###### avalanche effect
- - - 
è una proprietà che solitamente si vuole raggiungere con un generico algoritmo di cifraggio.
Un cambiamento su un bit del plain text o un cambiamento su un bit della chiave deve produrre un cambiamento su tantissimi bit del testo cifrato

per concludere DES con una chiave da 56 bit fa un po' schifo quindi si applicano dei metodi per rendere più forte l'algoritmo

