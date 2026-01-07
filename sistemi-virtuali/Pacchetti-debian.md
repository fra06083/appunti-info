Distribuzione: Insieme di strumenti software (collezione)
una distribuzione può anche essere senza kernel

distribuzione: è una collezione di strumenti software amministrati in maniera armoniosa, per poter avere la garanzia che tutti gli strumenti caricati possano lavorare senza problemi

motivo per cui uno dovrebbe utilizzare una distro:
* Armonia tra strumenti esistenti
* la possibilità di essere aggiornati in "automatico" su eventuali cambiamenti dei programmi
- responsabilità: malfattore riesce ad integrarsi nel gruppo Debian
differenza tra package manager:

`apt` funziona su distro debian-like: debiam, ubuntu, kubuntu


Pacchetto gestito come un file archivio (tar)
```bash
ar x file.deb # spacchetta file.deb
```

si scopre che c'è un archivio con dentro archivi. debian-binary (ha la versione del pacchetto) così so se è solo aggiornamento

Dentro control.tar.xz c'è
- Control dà informazioni di controllo del pacchetto
- md5sums
Dentro data c'è una gerarchia di file che ha struttura che parte dalla root di sistema

La versione ha il numero (es. 2.10-5) in più c'è quante volte è stato modificato [quel -5 è la patch] (sono modifiche più veloci che risparmiano il tempo della compilazione e ricreazione del pacchetto)

i pacchetti per le distro vengono forniti in formato binario (con un .deb per debian per esempio)

Control nella directory `debian` ha praticamente lo stesso contenuto.

`apt source` ci dà i file sorgente del pacchetto

[Lintian](https://wiki.debian.org/Lintian) è un package checker, se dà rosso o arancione il pacchetto non rientrebbe.

`dput` serve per mandarlo su debian.

Debian-contributor: dà una mano ma non ha posizione formale
debian-mantainer amministra indipendemente determinati tipi di pacchetti
Debiam-dev: possono fare tutto, aggiustare anche pacchetti degli altri. 


	
auto tool: meccanismi di compilazione.
Creazione pacchetto debian:
```c
#include <stidio.h»

main.... {
printf("Hello my world!");
}
```
si ispira a randmac, ora creiamo il CMakeLists.txt
```c++
cmake_minimum_required(VERSION 2.25) // versione minima cmake
project([nome progetto],
VERSION 0.0.1
DESCRIPTION "test test"
LANGUAGES ()
)
//serve per dire che viene installato secondo gli standard di gnu
include(GNUInstallDirs) 


add_executable(myhello myhello.c)
install(TARGETS myhello
RUNTIME 
)
```
Uninstall non serve configurazione, prende i file da CMake


uso i comandi:

```bash
cmake ../myhello
make
sudo make install # costruisce su /var/local 
sudo make uninstall # disinstalla %%
```
virtualsquare utilizza invece cmake 




parte da debian developer [preso spunto da qui per alcuni comandi](https://wiki.virtualsquare.org/#/distros/debian): 

```bash 
mkdir myhello
cd myhello/
git init -b upstream
git clone 
git init --bare -b upstram # risolve così
#### copiamo direttamente
git add -a
### time skipp incasinato
git tag upstream/0.0.1 # creazione tag con versione
git branch debian/sid
git checkout debian/sid
## upstream ha contenuto uguale come sviluppatore ora facciamo quello debian
wget https://raw.githubusercontent.com/virtualsquare/virtualsquare.github.io/master/archive/debian/debian_xxxxx.tgz # directory base da mettere a posto.
mv xxxxx.install myhello.installgit status
vi myhello # cambia l'eseguibile e mette usr/bin/*
dch # cambia il changelog che non va
vi changelog # unstable + modifica versione

## dimenticanza di git add debian
git add debian
git status
git commit -m "initial packaging"
git tag debian/0.0.1_1
git log


### TEST BUILD PACKAGE
gbp buildpaclage -us -uc # uc è per non firmarlo 


git add -u
git commit --amend # modificare il commit vecchio
dpkg -i my-hello-xxxx.deb
apt uninstall my-hello
```
In control: l'impostazione any indica che il pacchetto va ricompilato (per architetture diverse), all no.
Sviluppo:
```bash
git remote add salsa /tmp/vsd/debian # non si chiama salsa, è un falso %
git push salsa master:upstream # directory locale salsa (non va)
#### copiamo direttamente davoli è molto arrabbiato 👿
cp -a * /tmp/vsd/debian_package/myhello
```


controlla il comando `gpb` 
[ITP](https://wiki.debian.org/ITP): sottomissione di bug, serve per far capire alla comunità di debian
watch: serve per capire a che versione è arrivata la versione degli sviluppatori.

## aptitude serve per vedere i pacchetti scaricati con tutte le info