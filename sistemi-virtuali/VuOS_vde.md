[<small><span style="color:red">il dio bestia</span></small>](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTlXmghmC5A6SQV9pG-gxkKUe4QRbiP0pX7Zw&s)
- - -
### ❓Cos'è un device?
I devices sono file speciali che troviamo nella directory `/dev`, è presente solo l'i-node e per far si che il sistema capisca che sia un device controlla due numeri il **major ID** e **minor number**
quando usiamo open, il sistema si accorge che è un device.
#### ❓ Cosa cambia lavorare tra file e devices
Entrambi usano l'approccio di write e read, ma avvengono in modo diverso: Ci serve **IOCTL**
- **IOCTL virtualizzato**  prende in input il file, cosa deve fare e terzo argomento dipende dai due
#### Creazione di un sistema in RAM
costruiamo quindi un file system in RAM in maniera usermode. Usiamo il modulo fuse (servizio che consente di montare un file system in user mode, di solito montare viene eseguito in kernel mode.)
`truncate -s 10M /tmp/ddd` # Crea un file vuoto di 10 mega
`/sbin/mkfs.ext3 /tmp/ddd` # Creiamo un file system nel file vuoto di 10 mega di tipo ext3
- `fuse2fs -o fakeroot /tmp/ddd /tmp/mnt && ls /tmp/mnt` # è come un collegamento, lo vede come mnt.
- `fuse2fs /tmp/ddd /tmp/mnt` stesso comando ma senza fakeroot, la differenza è che prima lo abbiamo fatto nello spazio kernel, ora spazio utente, gli altri terminali non vedono nulla. 
- `fusermount` ci serve per dialogare con il kernel, uno dei pericolosi file **setuserID**
- `/sbin/mkfs.vfat /tmp/fatdisk` usiamo `fusefatfs -o rw+ /tmp/fatdisk /tmp/mnt` per accedere al file system fat. -> Non si vede nulla perché fat non ha i lost+found. (-o rw+ ci dà il permesso di scrittura)
- :LiGlasses: uevu avvia un applicazione in modalità user
Nel modo reale spesso si usa ROOT che è molto sbagliato poiché possiamo scassare qualcosa.
Usiamo le stesse metologie a livello utente, come se fosse una situazione normale

### Altri servizi
- - -
#### vudevpartx
- `uevu terminale`
- Creo directory vuota, devo avere due partizioni, quindi 2 directory
- `vu_insmod vudev fuse`
- `vumount -t vudevpartx` (è in grado di gestire entrambe le opzioni di mount)
Creiamo partizione hda1 e hda2 poi:
- filefatfs /dev/hda1 /tmp/mnt
- fuse2fs /dev/hda2 /tmp/mnt2
Stiamo poi creando la tabella di partizione
esempio di utilizzo: il boss si era scordato la password  di root del rasberry pi ha fatto sta cosina qua sopra, cambiato la password e voilà, problema della password scordata risolto
Raspberry pi ha una prima parte fat perché riesce solo a fare boot tramite fat, il resto ext4
### vufs
---
permette di spostare/far sparire dei pezzi di file system

Vediamo un esempio di base:
- Caso più facile è vedere contenuto di var,
	- monto come user `vumount -t vufs /var /mnt`
	- 
#### Bind 
collega questo a quello
#### merge 
unisce le due directory
- mkdir a b merge
- echo ciaoa > a/ciaoa
- echo ciaob > b/ciaob
- vumount -t vufs -o merge /tmp/a /tmp/b
- echo ciaoc > /tmp/b/ciaoc
- ls /tmp/b
nel mondo reale ciaoc è finito in ciaob
#### cow 
copy on write :3
stessa cosa, ma le modifiche vengono fatte sulla partizione montata
#### mincow
prova a farlo sul file system normale sennò fa cow.
`vuemount -t vufs -o mincow /tmp/fake /mnt`
dobbiamo escludere dal moontaggio /tmp e /proc
directory .- (compaiono i file modificati)
E' come se applicassimo una benda sopra al file system, noi vediamo cosa succede se facessimo determinate modifiche, ma in realtà non tocchiamo nulla
#### Virtual Networking
- vdens slirp:// otteniamo un espace collegato alla rete, di solito lo fa il kernel
- carico il modulo vudev
vumount -t vunetioth -o slirp:// vdestack /dev/net/x
monto uno stack e creo un device che rappresenta lo stack
unix non riconosce lo stato, quindi scrive weird file
vustack /dev/net/x && ip addr -> così vedo l'altro stack
/sbin/updhcpc -t vde0 (si comporta come l'altro)

- - -

### Note generali
Ricorda di usare vi_insmod per caricare il vari moduli in questa lezione carica `fuse`
Utilizza vumount per "montarlo" in maniera virtuale, senza l'utilizzo di root.
- /sbin/mkfs.ext3 /dev/ramdisk ci costruisce un un file system e lo costruiamo in ram
- fuse2fs /dev/ramdisk /mnt




































*Fitter happier  
More productive  
Comfortable  
Not drinking too much  
Regular exercise at the gym (3 days a week)  
Getting on better with your associate employee contemporaries  
At ease  
Eating well (no more microwave dinners and saturated fats)  
A patient, better driver  
A safer car (baby smiling in back seat)  
Sleeping well (no bad dreams)  
No paranoia  
Careful to all animals (never washing spiders down the plughole)  
Keep in contact with old friends (enjoy a drink now and then)  
Will frequently check credit at (moral) bank (hole in the wall)  
Favours for favours  
Fond but not in love  
Charity standing orders  
On Sundays ring road supermarket  
(No killing moths or putting boiling water on the ants)  
Car wash (also on Sundays)  
No longer afraid of the dark or midday shadows  
Nothing so ridiculously teenage and desperate  
Nothing so childish  
At a better pace  
Slower and more calculated  
No chance of escape  
Now self-employed  
Concerned (but powerless)  
An empowered and informed member of society (pragmatism not idealism)  
Will not cry in public  
Less chance of illness  
Tyres that grip in the wet (shot of baby strapped in back seat)  
A good memory  
Still cries at a good film  
Still kisses with saliva  
No longer empty and frantic  
Like a cat  
Tied to a stick  
That's driven into  
Frozen winter shit (the ability to laugh at weakness)  
Calm  
Fitter, healthier and more productive  
A pig  
In a cage  
On antibiotics*