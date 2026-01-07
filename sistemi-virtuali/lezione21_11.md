Umvu è composto da tre livelli:
- sottomoduli (es. vudev)
- moduli (es. vufs, vunet)
-  Hypervisor (umvu) 
Feature non utilizzata: altre system call create, alcune possibilmente da implementare, dovremo guardarlo come semmai volessimo creare una systemcall in più, come si vivrebbe il mondo.

`vu_syscalls.conf` diventa sorgente per gli script python che generano codice c!

`lstat` è centrale per l'architettura, ma deve essere implementata per ogni modulo.
I quattro "tag" sono:
`lstat/112, stat/12, fstatat/314, newfstatat/314, fstat/2: std, lstat, NULL, NULL`
* std (standard)
* lstat, nome del wrapper di input. Quando avviene una lstat avviene il wrapper di input
### Come scrivere un modulo: 
- Libreria dinamica, deve essere caricato come un plugin
```c

	struct vu_module_t vu_module = {
		.name = "nopasswd",
		.description = "map /etc/passwd to /etc/hostname",
		.flags = VU_USE_PRW
	};
```

