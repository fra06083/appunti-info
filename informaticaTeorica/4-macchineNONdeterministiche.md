- - -
$\large N = < \Sigma, \Gamma, \text{blank}, Q, q_0, F, \delta>$  

det: $\large \delta: Q \text{ x } \Gamma \to \{ <-, ->\}$ 

le macchine non deterministiche non esistono

quando si blocca in un punto e deve scegliere se andare in uno stato o in un altro formalmente non sceglie perché non esiste

il motivo per cui le studiamo è che ci semplifica lo studio dei linguaggi

formalizziamo ora cos'è la computazione di una macchina non deterministica 

quindi si parla di computation tree, quindi un albero di tutte le possibili scelte che una macchina non deterministica può fare

è un albero i cui nodi sono tutte le possibili configurazioni che la macchina non deterministica può osservare nel momento in cui processa la stringa w

la radice di questo albero è la configurazione iniziale della macchina sulla stringa w e si ha un arco fra una configurazione e un'altra se la configurazione successiva è una configurazione legale di quella precedente

sono macchine che basta che abbiano un modo per accettare una stringa per poter essere accettanti

la macchina rifiuta quando non ci sono stati accettanti

aiuto ho scritto in modo un po' confuso 

Una MT N non deterministica accetta l'input w se e solo se all'interno del computation tree di N su w è presente una configurazione accettante (non ci interessa dove). La macchina rifiuta
se non c'è nessun modo per accettare w.

il poter espressivo di una macchina di Turing non deterministica è uguale a quello di una macchina di Turing deterministica
Come?
La macchina di Turing deterministica può esplorare in modo ordinato l'albero di computazione della macchina non deterministica, potendo decidere se accettare lo stesso linguaggio valutato da una macchina non deterministica

il motivo per cui la lettura dell'albero (da parte della macchina deterministica) viene fatta con una BFS è data dal fatto che se lo facesse con una DFS si potrebbe bloccare in possibili cicli dettati dalla non accettazione della macchina non deterministica 

ma quanto costa la simulazione della macchina non deterministica mono nastro, usando una macchina deterministica multinastro abbiamo un costo esponenziale, zio pera, lentino.
Si può fare di meglio? Bo .., allora sorge la domanda: si può dimostrare che NON si può fare di meglio? No, è una domanda ancora aperta, siamo nel limbo

ora notiamo che abbiamo aggiunto vari optional (da macchine multi nastro a macchine mono nastro) alle macchine, senza ottenere maggiore potenza espressiva

Tesi di Church-Turing
tutto ciò che sarà mai calcolabile, è calcolabile da una macchina di Turing
perché è un'ipotesi e non un teorema? Stiamo definendo la calcolabilità secondo la definizione di macchina di Turing, non abbiamo una definizione formale di ciò che è calcolabile. Questo ci porta a introdurre le classi di calcolabilità
- RE (ricorsivamente enumerabili)
- R (linguaggi ricorsivi o detti anche linguaggi decidibili)
dove R è contenuta in RE

Una classe di calcolabilità è un insieme di linguaggi

La classe R è la classe dei linguaggi o dei **problemi ricorsivi**, in cui ci stanno tutti quei linguaggi che sono decisi da una macchina di Turing (det o non det), che garantiscono una risposta garantita sul si o sul no {linguaggi per cui esiste un algoritmo}

I linguaggi non decidibili sono tutti al di fuori di R ma quelli che stanno in RE e non in R sono i linguaggi SEMI-decidibili, ovvero tutti quei linguaggi per cui abbiamo una macchina di Turing che li accetta {problemi per cui non abbiamo la garanzia di risposta negativa}

>[!Warning]
>**PER ESAME:** Guess and Check, non risolvere in maniera non deterministica. Cercare di avere un intuizione su come è fatto una stringa di un linguaggio.



### Esercizi
- - -
il concetto che sta dietro alle macchine NON deterministiche è il guess and check, ovvero diamo delle possibilità alla macchina e poi "filtriamo" solo quelle che hanno un effettivo senso.
È un tipo di computazione!


<img src="https://i.imgur.com/TvJ3nbt.png">
<img src="https://i.imgur.com/FcxS7JE.png">
Due guess A in B e A$^R$ in B
Cosa succede alla macchina durante la sua lavorazione trova A$^R$ dentro B?
- E' a trabocchetto pd... Non accetta in quel ramo di computazione, però in altri rami lo sta cercando e quindi accetta in quelli. 

tutto ciò che porta ad un rifiuto deve essere provato tramite DETERMINISMO

<img src="https://i.imgur.com/0VTEirP.png">



$$\large L = \{x^n \# w_1 \# \cdots \# w_n \mid u > 0, W_i \in (a|b|c|d)^+ \land \forall i, 1 \leq i \leq n, \exists S_i, S_i \subseteq w_i (|S_i| = i, S_i = {S_i}^x)\}$$
Nastro che ci tenga L, uno che ci tenga i e poi selezioniamo $w_i$ e controlliamo che sia palindroma


NASTRI: 1: input; 2: n; 3: i; 4: S$\Large_i$; 5: S$\Large_i$;![[esercizio4.png|Esercizio 4 risolto|700x354]]

$\large L = \{ A\#B\#w_1w_1w_2w_2\dots w_nw_n \mid A, B, w_i \in (0 \mid 1)^+, |A| > |B|, n = |A| - |B|, |w_i| \geq |B| \}$
Sia $\alpha \in \{0, 1\}$
*Verifichiamo che $|A| > |B|$ mentre calcoliamo $n$, per ogni $i$ copiamo $w$ sul nastro 4 assicurandoci che sia più lunga di $B$, poi indoviniamo quando siamo a metà e controlliamo.*
Nastri: 1 = input, 2 = $|A| - |B|$, 3 = $|B|$, 4 = $w_i$![[esercizio5.png|Esercizio 5|697]]


**NON LA DOBBIAMO PRENDERE DETERMINISTICA!** e stabiliamo quando finiscono le w$\large_i$
!!! In q$_5$ non è deterministico

$\large L = \{ A\#B\#w_1w_1w_2w_2\dots w_nw_n \mid A, B, w_i \in (0 \mid 1)^+, |A| > |B|, n = |A| - |B|, |w_i| \geq |B| \}$
Sia $\alpha \in \{0, 1\}$
*Verifichiamo che $|A| > |B|$ mentre calcoliamo $n$, per ogni $i$ copiamo $w$ sul nastro 4 assicurandoci che sia più lunga di $B$, poi indoviniamo quando siamo a metà e controlliamo.*
Nastri: 1 = input, 2 = $|A| - |B|$, 3 = $|B|$, 4 = $w_i$![[esercizio6.png|697]]
Dobbiamo stabilire se w$_i$ sia dispari o pari: Abbiamo poi un database, poi si tratta di assemblare pezzi. Non so di principio ma dipende dove finisce lo stato, se finisce in q4 è dispari sennò pari.

All'inizio leggo un simbolo quindi è dispari, se leggo un altro carattere è pari e così via.
Ad un certo punto finiremo w$_i$ (ce ne accorgiamo perché c'è un # o un blank) Ed a quel punto trovo B$^R$ scorrendo in modo NON DETERMINISTICO!!