- - -

### Reti neurali
- - -
* Ogni neurone prende più input e produce un singolo output che può essere passato in input a molti altri neuroni
* inoltre ogni neurone implementa un regressore logistico $$\large \sigma(wx + b)$$
* ogni neurone della rete k-1 è collegato ad ogni neurone della k

un singolo neurone: $$\large O^1=I^n*W^n+B^1$$ 
dove:
- O è l'output finale (a quanto pare uno scalare)
- I è l'input, con n caratteristiche
- W è il peso che viene assegnato ad ogni input
- B è il bias.
	- quando hai problemi a ricordare cosa chezzo è il bias, ricorda l'esempio di in input un pixel nero che ha valore 0, moltiplicato per il suo peso il risultato è sempre zero! Cosa no buona..
