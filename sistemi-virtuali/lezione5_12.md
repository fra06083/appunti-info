- - -
##### Recap
generazione indirizzi via hash, così non è necessario configurare il dns.
basta battezzare un nodo e quello funziona
abbiamo usato `hashaddr` per configurare il nodo, ma si può fare ancora meglio?
Name dhcp!
Si chiede ad un host l'indirizzo ip
L'idea è quella di dire al `dhcp` "io ho questo nome, dammi un ip"

### [namedpch](https://github.com/virtualsquare/namedhcp)

il router advertisement demon serve per mandare messaggi di configurazione della rete

```bash
# Terminale 1
vde_plug null:// hub:///tmp/hub
```

```bash
# Terminale 2
iothradvd -s vde:///tmp/hub -P 10 fc00::/64/L/86400/14400
```

il client chiede dhcp a namedhcp che a sua volta chiederà a iothnamed dns, quindi una risoluzione del nome

questo è quello su github
```bash
$ vdens -R fc00::24 /tmp/hub
$ ip link set vde0 up
$ echo 'send fqdn.fqdn "one.test.local";' > one.conf
$ truncate -s 0 one.leases
$ /sbin/dhclient -6 -cf one.conf -v vde0 -lf one.leases -pf /dev/null

```

questo è quello effettivamente fatto a lezione
```bash
vdens -R fc00::24 /tmp/hub
ipconf eth # tira su l'interfaccia, cambiato dal tutorial
ipconf dhcp6,fqdb=one,test.local
```

a questo punto proviamo con l'hash!
quindi si rifanno tutti quanti i setup presenti nel readme

```bash
vdens -R fc00::24 /tmp/hub
ipconf eth # tira su l'interfaccia, cambiato dal tutorial
ipconf dhcp6,fqdb=h1.hash.local
```

problemino con ipconf. Per come funziona il dhcp, ogni tot tempo viene chiesto se quell'indirizzo assegnato è ancora utilizzato. Questo ipconf, non lo fa, sarebbe una possibile parte da scrivere


reverse proxy, si mette in mezzo fra la rete e un servizio tcp o udp, che non sa nulla di otip. E le persone che parlano nella rete, in realtà parleranno con rproxy


esempio di `otip_rproxy.rc`, file di configurazione
`instack` parla con il kernel
```conf
# external stack. supported tags: stack, vnl, iface
extstack stack=vdestack,vnl=vde:///tmp/hub

# internal stack. full iothconf syntax
intstack stack=kernel

# dns (if basename is a fqdn)
dns 80.80.80.80

# fqdn of the otip address
# name renzo.otip
# name renzo.otipcs.v2.cs.unibo.it
name renzo.otip

# base adress to compute the current address
# baseaddr 2001:760:2e00:ff00::
baseaddr fc01::

# it is possible to define baseaddr as a fdqn
# (it requires dns access)
# baseaddr otipcs.v2.cs.unibo.it

# otip password
passwd mypassword

# udp and tcp proxy configurations:
#    extport,inthost,intport
udp	4242,::1,8484
tcp	4242,::1,8484
tcp	22,::1,22

# configuration parameters
# otip address validity period (sec)
# client and rproxy must agree on the same value
otip_period 32
# pre-activation time (sec)
# in advance activation (to support negative drifts of clients' clocks)
otip_preactive 8
# post-activation time (sec)
# delayed deactivation (to support positive drifts of clients' clocks)
otip_postactive 8
# tcp listen argument
tcp_listen_backlog 5
# timeout to drop tcp idle connections (sec)
tcp_timeout 120
# timeout to drop udp reply map (sec)
udp_timeout 8
```
se uno chiama da fuori udp 4242 verrà mappato a udp 8484
stessa cosa per `tcp`
stessa cosa per `ssh` 


demo!
```bash
vdens /tmp/hub
ipconf eth
ipconf ip= # qualcosa aiuto non ho visto
ping -n `otipaddr -b fc01:: renzo.otip mypassword`

```

in questo caso viene cambiato l'indirizzo ogni tot secondi (40, 32 + 8) e quindi bisogna far ripartire il ping

ora demo con iothnamed
faccio partire `otip rproxy`

faccio partire un client dicendogli di usare come dns il dns utilizzato prima

```bash
ipconf eth
ipconf ip=fc01::1
ip addr
ping -n renzo.otip
```

il client usa un dns locale che gli altri non vedono. 

```bash
# la clausola serverAliveInterval manda un pacchetto fittizio ogni n secondi 
# per comunicare che siamo ancora lì e la connessione non deve essere interrotta 
ssh INDIRIZZO -o ServerAliveInterval=60
```


Nel caso di utilizzo di una applicazione che sfrutta tcp-ip, come si fa a fare una query al dns per avere un'indirizzo ip associato ad un nome simbolico?