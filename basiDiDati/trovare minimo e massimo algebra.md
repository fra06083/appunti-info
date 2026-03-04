- Trovare un minimo/massimo
    
    [Relational algebra: obtaining the largest value - Diego Assencio](https://diego.assencio.com/?index=85b94ecb875ce2f318beabfa7f0150a7)
    
    Ho una tabella $T$ con una colonna di numeri.
    
    Voglio trovare il min/max in quella colonna.
    
    Estraggo la colonna con $\pi$.
    
    Rinomino il campo $C$ di $T$ in modo da poter fare un join con sé stessa.
    
    Chiamo questo campo $C'$.
    
    Faccio un $\bowtie_{C < C'}$ tra $T,T'$ (con sé stessa).
    
    Quello che esce da questo join è una tabella che contiene solo i valori che avevano almeno un valore più grande (quindi tutti tranne il MAX).
    
    Ora faccio una sottrazione tra la colonna “intera” e quella ottenuta dal procedimento, formata da tutti i valori tranne il MAX.