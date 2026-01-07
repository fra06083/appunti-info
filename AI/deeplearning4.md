- - -
si fa un prodotto scalare fra il filtro e la corrispondente posizione dell'input
![[filtroConvoluzione.png|359x249]]

convoluzione! Per ogni pixel si calcola il prodotto scalare dei 8 valori (attorno, poi ovviamente includi anche il pixel) con il filtro, inserendo il risultato nella parte trasposta della sezione dei nuovi pixel. 

esempio calcolo:
![[esempioCalcoloFiltroConvoluzione.png|371x226]]

nota, la corrispondenza che c'è fra i valori di input e i valori di output
punti importanti 
* parametri
* dimensione del filtro (non necessariamente quadrato)
* operazione di spostamento, numero di passi (stride)
	* aumentando lo stride (quindi si saltano dei valori) si rischia di avere un down sampling
* creazione di padding (varie tecniche esistenti, normalmente si sceglie lo zero come valore) del input per centrare valori anche esterni

la funzione `myconvlayer()`, in output, prende 4 dimensioni, la prima non l'ho capita.
La seconda e la terza sono le dimensioni reali, x e y per intenderci. La terza è la dimensione dei canali, ovvero quella inerente ai colori. Per le immagini in bianco e nero, ho 1 come valore, per immagini colorate ho 3 (reed, green, blue)f


