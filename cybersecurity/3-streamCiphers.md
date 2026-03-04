- - -
23/02

### cifraggi simmetrici
- - -
un cifraggio è detto simmetrico quando è definito su (K, P, C) e una coppia di algoritmi simmetrici (E, D) dove: $$\large E: K \text{ x } P \to C$$ $$\large D: K \text{ x } C \to P$$tale che $\large \forall m\in P, \forall k\in K: D(k, E(k,m)) = m$
con: 
- E che viene spesso randomizzato 
- D è sempre deterministico

Un esempio può essere il One-Time Pad:
$K = P = C = {0,1}^n$
$k ∊ K, m ∊ P, c ∊ C$
$E(k, m) = k ⊕ m = c$
$D(k, c) = k ⊕ c$
con k che viene usata una volta sola ed è presa in modo randomico secondo la distribuzione uniforme
(spesso fa una domanda su otp, quindi guardalo bene!)
pro e contro


### cifraggio sicuro
- - -
ponendo che il tipo di attacco sia un ciphertext only attack, i possibili requisiti di sicurezza sono:
- l'attaccante non deve poter trovare la chiave segreta cioè 
	- $\large E(k, m) = m$ dovrebbe essere sicuro
- l'attaccante non deve poter ricavare tutto il plain text cioè
	- $\large E(k, m_0 || m_1) = m_0 || k ⊕ m_1$ 


###### teorema di Shannon sulla sicurezza dell'informazione
- - -
dato un cifraggio (E, D) su (K, P, C) allora questo avrà una segretezza perfetta se: $$\large \forall m_0, m_1 \in P, \quad len(m_0) = len(m_1) \text{ e } \forall c \in C$$ $$\large Pr[E(k,m_0) = c] = Pr[D(k, m_1) = c]$$con k è uniforme in K

Quindi in poche parole, dato un testo cifrato non si può ricavare il testo plain text e quindi la maggior parte degli attacchi non ricavano niente su PT da CT. Siamo salvi dai CT only attacks!



l'OTP è sicuro [...]?

c'è un teorema che afferma che se un cifraggio ha segretezza perfetta allora la lunghezza della chiave è maggiore della lunghezza del messaggio


### Generatori pseudo-random
- - -
tramite un algoritmo deterministico si genera uno stream di bit pseudo random 
è necessario avere un seed che rispetta determinati criteri:
- il seed deve essere sicuro (quindi unpredictable)
- PRNG è un algoritmo deterministico
- il seme deve essere random o pseudo random
- tipicamente il seme è generato tramite un "true random number generator"

Esempi di PRNG scarsi:
[. . .]

un buon PRNG è il blum blum shub 

si scelgono due numeri primi molto grandi, faccio il prodotto e ottengo n
prendo un numero s relativamente primo a n (non ci sono divisori comuni fra n e s)
l'algoritmo blum blum shub va a generare una sequenza di bit $\large B_i$:
$X_0 = s^2 \pmod n$ 
`for i = 1 to ∞`
	$X_i = (X_{i-1})^2 \pmod n$
	$B_i = X_i \pmod 2$ 
così il bit meno significativo viene preso ad ogni iterazione

il BBS è anche detto cryptographically secure pseudorandom bit generator. Questo passa il next bit test.
Dati i primi k bit dell'output, non esiste un algoritmo con costo polinomiale, che permette di prevedere se il bit sarà 1 o 0 con una probabilità superiore al 50%


Tornando agli stream ciphers
Idea: cambiamo la chiave "random" con una "pseudorandom", quindi si parla di PRG
La funzione G è un PRG $$\large G:\{0,1\}^s \to \{0,1\}^n \quad n>>s$$quindi la chiave viene mappata su uno spazio più grande

una struttura generica è la seguente
<img src="https://imgur.com/VDu8bf5.png"> 
Ma lo stream cipher non ha una segretezza perfetta, questo perché la dimensione della chiave è minore del messaggio



### Esempi reali di stream cipher
- - -
###### RC4 (Rivest Cipher 4)
- usato per SSL/TLS
- usato per WEP e WPA
questo algoritmo non è particolarmente complesso, ha una chiave di lunghezza variabile che può variare da 8 a 2048 bit, utilizzata per inizializzare uno state vector da 256 byte con elementi da S[0] a S[255] 
Il vettore S contiene la permutazione dei numeri fatti con 8 bit, da 0 a 255. Quindi abbiamo 256!
nel mentre che i valori di k sono generati, le entries di S sono permutato ancora e ancora

per cifrare e decifrare un byte k viene generato dal vettore S, selezionando uno dei 255 valori
```pseudo
/* Initialization of S*/
for i = 0 to 255 do
	S[i] = i;
	T[i] = K[i mod keylen];
```

```pseudo
/* Initial Permutation of S */
j = 0;
for i = 0 to 255 do
	j = (j + S[i] + T[i]) mod 256;
	Swap (S[i], S[j]);
```

```pseudo
/* stream generation */
i, j = 0;
while (true)
	i = (i + 1) mod 256;
	j = (j + S[i]) mod 256;
	Swap (S[i], S[j]);
	t = (S[i] + S[j]) mod 256;
	k = S[t];
```

Debolezze di RC4:
- due studiosi hanno provato che, anche assumendo una inizializzazione perfetta, l'output (lo stream della chiave) sarà biased $\large Pr[ 2^{nd} byte = 0 ] = 2/256 = 1/128$
- ce n'è un'altra da capire aiut
- related-key attacks: attacchi sul WEP


Negli stream ciphers moderni si utilizza un **nonce** $$\large G:\{0,1\}^s \text{ x } r \to \{0,1\}^n \quad n>>s$$infatti $$\large E(k, m , r) = m ⊕ PRG(k , r)$$
### Tipi di attacchi a OTP e stream cipher
- - - 
attacco 1:
$$c 1 ← m 1 ⊕ PRG(k) \qquad c_2 ← m_2 ⊕ PRG(k)$$$\large c_1 ⊕ c_2 \to m_1 ⊕ m_2$  
zio pera si riesce a trovare il messaggio originale..


Quindi alla fine della fiera non usare mai più di una volta la stream cipher key


attacco 2:
Non è garantita l'integrità del messaggio, il man in the middle potrebbe prendere il messaggio inviato da alice, fare lo xor con una p generica: $\large c^* = c \oplus p$ per poi inviarlo a bob
l'otp è malleabile