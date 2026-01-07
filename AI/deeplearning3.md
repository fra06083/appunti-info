È possibile calcolare qualsiasi funzione tramite un solo neurone?

combinazione lineare degli input sommando il bias
![[casoConUnSoloNeurone.png|434x274]]

se si è sopra la retta, quindi nella parte superiore dell'iperpiano, verrà restituito uno, in caso contrario 0
![[iperpianoEsempio.png|467x284]]
- - -

È possibile calcolare la porta logica NAND tramite l'uso di un solo neurone?
![[emepioNand.png|464x272]]

Problema di classificazione! C'è un modo di far passare una linea sul piano che permetta di dividere i punti verdi dal punto rosso? Si, sono infinite!

![[divisionePuntiRossiVerdi.png|421x289]]

Per quanto riguarda lo XOR, questo non è calcolabile! Per definizione lo xor restituisce 1 quando i due valori sono diversi. Basta immaginare la stessa cosa dell'immagine di sopra ma con (0,0) come puntino rosso. A quel punto sarebbe possibile separare i puntini rossi da quelli verdi, con una linea retta? No.
In realtà, mettendo in cascata dei perceptrons (qeulli con la quale costruisci il nand) è possibile generare una porta logica xor

Nel caso dei multi perceptrons hai una completezza logica, essendo in grado di calcolare la tutte le funzioni continue! È possibile calcolare ogni funzione booleana grazie ad essi


### Training
- - -
gli output hanno un peso quando passano ad un neurone, i pesi vengono sommati e ad essi viene aggiunto il bias
* current loss
* parameter updating
* backpropagation

### Back propagation algorithm
- - -
Una rete neurale calcola una funzione complessa, che è il risultato di molteplici strati neurali
bisogna calcolare la derivata della composizione di due funzioni! Per fare questo si utilizza la chain rule (per le derivate).

`QUESTION: why binary thresholding is not a good activationfunction for backpropagation?`
Banalmente perché la derivata in ogni punto è zero (la rappresentazione del tresholding è tipo una scaletta).

il risultato viene passato ad una funzione di attivazione, a sarà il l'output del layer, z è l'input di sigma.
z equivale alla somma del bias di quel determinato livello con i parametri (?) del neurone di quel livello


$\large \delta^l$=derivata parziale della funzione di loss rispetto all'ultimo z