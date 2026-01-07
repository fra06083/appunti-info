- - -
demone `ioth_conf`

3 attività diverse
- correttezza
	- guardare di aver rispettato gli rfc nelle cose che facciano
	- lavoro che dà due effetti collaterali
		- provare che siano coerenti
		- si studia come funziona il programma
- sintassi
	- la sinstassi copre le funzionalità base? Ci sono funzionalità che non rispettano le funzionalità base
- estensione
	- vedere cosa manca
	- il problema dei thread in background
citati `dhclient` e `dhcpcd` dice di vedere come fanno loro


### Cado
- - -
due funzionalità `cado` ma anche `scado` che sta per script cado

sudo è fatto per lavorare da console, l'effetto è come se il comando l'avesse fatto root.
Domanda posta: 

quando si lancia l'eseguibile `/usr/bin/passwd` il programma deve sapere chi sta lanciando il comando

all'interno dello script vogliamo lanciare l'eseguibile che però abbia determinate capability. Root ha dato la delega agli utenti per scegliere le capability

`scado` è una delega di deleghe uh

citati i `cron` per i job "automatizzati" controlla con `crontab -e`

nella prima versione di cado era un set user id, ma non a root. Un modo sarebbe quello di farlo diventare root e dare il permesso a tutti, ma in questo modo non si garantiva la sicurezza 
lui ha settato il config di cado in un file `cado.conf` all' interno di /etc/

`scado` controlla l'autorizzazione, controlla il file, controlla la signature e lancia la copia controllata.
Un problema era non lasciare delle copie in giro e la tecnica utilizzata per risolvere il problema viene detta watchdog

tu hai un processo che lancia un processo figlio, collegato con il padre tramite pipe.
Il figlio legge da pipe ma questa è `close on exec`

È pieno di possibili progetti, descrizioni, documentazione, eventuali bug da trovare 