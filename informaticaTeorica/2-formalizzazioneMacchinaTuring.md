- - -
20-02
### Configurazione (ID instantaneous description)
- - -
è uno screenshot dello stato corrente della macchina
la configurazione è un oggetto (stringa di simboli) che contiene:
- fotografia di cosa sta sul nastro
- lo stato in cui la macchina si trova
- dove si trova la testina

da queste informazioni, conoscendo la funzione di transizione, possiamo dedurre il prossimo passo della macchina

esempio:
$\large aq_1abb$ 
sul nastro ci sono a abb; sta leggendo la lettera a (a destra di $q_1$) e si trova nello stato $\large q_1$ 
oppure
$\large aabq_3b/$ 



una configurazione si dice **accettante** quando al suo interno compare uno stato accettante della macchina (anche se può fare un altro passo)

una configurazione si dice **finale** quando non può più fare passi

il **legal successor** di una configurazione è definito come segue:
- sia $\large c_1$ una configurazione, $\large c_2$ è il legal successor di $c1$ secondo la funzione di transizione di m se e solo se la configurazione descritta da $c2$ è raggiungibile in un solo passo, partendo dalla configurazione $c1$ di m

una **computazione parziale** della macchina m è una sequenza di configurazioni $\large c_1,c_2,...,c_n$ tale per cui sono il legal successor del successivo. (c2 è il legal successor di c1, c3 è il legal successor di c2 e così via)

computazione di m (m generica macchina di Turing) sulla stringa $w=w_1w_2...w_e$ è una computazione parziale (ovvero una sequenza di configurazioni con le configurazioni che si seguono secondo il concetto di legal successor) dove c1 è la configurazione iniziale ovvero $\large c_1 = q_0w_1w_2...w_e$ e $\large c_n$ è una configurazione finale

la macchina m accetta una stringa w se la macchina si ferma su una configurazione finale e accettante
se nella sua computazione si arresta su uno configurazione accettante


la macchina m rifiuta una stringa w se la macchina ha la configurazione $\large c_n$ non accettante 
quindi se non è vero che si arresta in uno stato accettante 

la macchina per dire di sì deve fermarsi e dire di sì
una macchina per dire no può non fermarsi mai. Ma questo è un problema perché se non si ferma non sappiamo, quando si fermerà e, di conseguenza, quando ci darà la risposta no


### Linguaggio di una macchina di Turing
- - -
Il linguaggio di una macchina di Turing è definito come: $$\large L(M) = \{w|M(w)=1\}$$il linguaggio sulla quale la macchina di Turing si ferma e dice di sì

Sia $\large L$ un linguaggio. $\large M$ **decide** $\large L$ se $\large \forall w \in \Sigma^*$ $$\large w\in L \to M \text{ accetta } w$$$$\large w\notin L \to M \text{ non accetta } w \text{ e si arresta }$$In questo caso hai la certezza di risposta e di arresto
Tutte le stringhe appartengono ad L (da capire edit, credo le stringhe che L accetta)



$\large M$ **riconosce** se abbiamo garanzie di risposta su sì ma non sul no, cioè
$$\large w\in L \to M \text{ accetta } w$$$$\large w\notin L \to M \text{ non accetta } w \text{ e non è detto che si arresti }$$
## **Esercizi**: 
- - -
<img src="https://i.imgur.com/PWVWI6z.png">
<img src="https://i.imgur.com/953qbSU.png">

- - -
2
#### Esercizio 1 per casa:
- - - 
<img src="https://i.imgur.com/HOuq9t5.jpeg" max-width="100%">


