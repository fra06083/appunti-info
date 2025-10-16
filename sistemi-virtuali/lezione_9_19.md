
vdesl: 

multi: 
serve per fare end-off fra livelli sottostanti creando una duplicazione dei pacchetti (questo dà più sicurezza)

bonding:
fa il round robin dei pacchetti
prima lo mando su un cavo poi su un altro e così via 

---
è possibile avere dei pacchetti che si frappongono fra il client e il plugin ordinario


**nesting plugins**
agno: fa crittografia agnostica sui pacchetti Ethernet.

il secondo pacchetto che viene spedito non usa la chiave del primo, ma una chiave che viene trasformata usando il contenuto del pacchetto precedente, la chiave del terzo pacchetto viene invece fatta usando il contenuto dei pacchetti precedenti e così via

---
protocollo 802.1q (standard per le VLAN)
all'interno del pacchetto, nel tipo di connessione è presente, non ipv4 o ipv6, bensì 8100, che passa la gestione del pacchetto al gestore delle vlan

---

esperimento:

vlan/create 42
* in altri 4 terminali ha fatto vdens vde:///tmp/sw
due terminali saranno all'interno della vlan 42, gli altri due all'interno della vlan 0 

Ha fatto vedere che il ping fra le due macchine nella stessa vlan (la 42) avviene; spostando una macchina dalla vlan 42 alla 0 il ping smette di funzionare (per fare lo spostamento di vlan ha fatto port/setvlan 1 0)

ovviamente per far vedere i pacchetti bisogna anche fare il setup degli indirizzi
in questo caso per la vlan 0 ha scelto 10.0.0.1 e 10.0.0.2, mentre per la vlan 42 10.0.1.1 e 10.0.1.2
- - -
lezione 10/10
tagged e untagged, differenza
con untagged i client connessi alla vlan, sono all'oscuro di essere all'interno di una rete virtule e vedono solo i pacchetti appartenenti a quel tipo di rete

si usano le reti untagged per le telecamere di una casa per esempio.
```
Quindi, quando si dice che una VLAN è “untagged”, normalmente ci si riferisce ai corrispondenti frame senza 801.Q tag trasmessi su una o più porte. Questi frame avranno un tag implicito. (Il caso più comune è quando una porta di un dispositivo di networking è connessa ad una end station come un PC che non ha bisogno di ricevere il tag esplicito nel pacchetto. In questo caso i frame saranno generalmente trasmessi al PC untagged.)

Una VLAN invece è “tagged” quando su tutte le porte in esame i frame corrispondenti contengono un tag 801.Q con il corrispondente VLAN ID. (Il caso più comune è quando si hanno link di interconnessione di switch e di router, dove l’uso di VLAN untagged non è raccomandato.)
```

vxvde gasa da paura:
è privo di configurazioni! A differenza di vtep e vxlan, che necessitano di svariati procedimenti e configurazioni, con vxvde basta che gli host di due reti virtuali diverse siano entrambi registrati all'ip di multicast e il passaggio dei pacchetti attraverso esso avviene senza alcun problema.
A per comunicare con B, necessita solo dell'indirizzo ip multicast
- - -
come avvengono le virtualizzazioni
con moduli e sotto moduli
modulo delle virtualizzazioni delle reti, dei device, dei file system ecc

- - - 
vuos è un mattoncino che riceve richieste e ne fa sotto forma di system callsetti