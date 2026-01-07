[umvu](https://github.com/virtualsquare/vuos/tree/master/umvu)

- vuname
`umvu_peekpoke.c`, serve a scambiare i dati tra hyper visor e processi utente

- umvu_tracer.c
il main chiama `umvu_tracer_fork()` che praticamente fa una fork
dentro questa funzione viene chiamata la `r_fork()` (r sta per real) infatti si vuole che venga chiamata la vera real system call, non quella virtualizzata.
Il padre si deve assicurare che il figlio sia veramente partito, fatto tramite la `r_wait4()`

*le variabili con __ thread sono variabili globali ma che hanno un'istanza distinta per ogni thread.*

la funzione `umvu_trace()` è la funzione cuore dell'hypervisor
si aspetta un evento:
* che può essere un errore. In questo caso esce l'hypervisor del processo
* può essere un evento di exit
* potrebbe arrivare un evento da un processo diverso da quello dell'angelo custode, questo vuol dire che il processo ha fatto un figlio. In questo caso è presente la funzione `transfer_trancee()`
* può anche essere una system call. L'evento viene chiamato prima della `syscall` per mettere a posto i parametri di essa e poi viene effettivamente avviata la `syscall`. Prende le informazioni del processo e le copia nel `pcb`. Nel `syscal_desc` possono esserci diverse risposte:
	* DOIT
	* SKIPIT, per skippare attua una `getpid()`, veloce e senza effetti collaterali 
	* DOIT_CB_AFTER falla ma fai qualcosa prima (di specifico) di concludere
	* BLOCKIT
	* DO_IT_AGAIN sposta il program counter indietro così da poter ripetere la system call

come si gestiscono gli angeli custodi?
Quando arriva il pid di un processo che non conosco, blocca il chiamante, prende la system call e fa una `ppoll()` che non aspetta nessun file, si ha così una chiamata bloccante! A questo punto si fa il detach, quel processo è fermo, a questo punto lo scollego. Creo un nuovo thread e un annesso angelo custode, che avvierà il codice di `spawn_tracer()`.


il linguaggio parlato dall'hypervisor ai moduli è il linguaggio delle `syscall`
"scrivere un modulo significa far dare una risposta alle `syscall`"