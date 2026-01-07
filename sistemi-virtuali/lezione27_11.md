- - -
`iothconf` serve per poter avere la configurazione di una rete `ioth` con una stringa, basta una stringa

gli strumenti che si usano per configurare, funzionano anche per parlare con il kernel, non sono specifici di `iothconf`

#### Options supported by `ioth_config` and `ioth_newstackc`
- - -
- `iface=...` : select the interface e.g. `iface=eth0` (default value vde0)
- `ifindex=...` : id of the interface (it can be used instead of `iface`)

se non viene specificata l'interfaccia viene usata di default vde0 :3
- `gli strumenti di iothconf consento di attribuire indirizzi calcolati sulla hash del nome. usando questo metodo si semplifica la configurazione del dns.`
[a fine pagina altri parametri gasanti](https://github.com/virtualsquare/iothconf)


#### configurazione DNS
- - -
esempio di un dns molto utilizzato, **bind**

I dns solitamente adottano una tecnica di master-slave, dove gli slave copiano la configurazione del master. 

gli strumenti per interrogare un dns sono
- host
- dig
quando viene fatto il comando `host` di un determinato indirizzo il dns controlla l'indirizzo "a rovescio".
`host 130.136.5.6` allora verrà letto prima 130, poi 136, 5 e infine 6
![[dnsConf.png|361x481]]

named.conf è il file con tutti i nomi dei domini che esso gestisce, aka 'il bando della matassa'

per esempio `shp.cd.unibo.it` è di tipo slave, definito altrove

#### [iothnamed](https://github.com/virtualsquare/iothnamed)
- - -
**a DNS server/forwarder/cache for the Internet of Threads**

i dns aperti a tutti sono pericolosi perché si corre il rischio di ricevere una marea di query

aggiunge nomi locali, si può vedere la risoluzione di tutto! Questo perché, quando si fanno le domande, lui chiede a 8.8.8.8 o 80.80.80.80 

progetti nuovi, sviluppare iothnamed dns over https, oppure riscrivere la documentazione e i tutorial
