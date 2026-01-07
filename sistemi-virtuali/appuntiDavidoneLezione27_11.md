# RETI: IoT (Internet of Threads)   27/11/2025

### Introduzione
- dal punto di vista dell'amministratore di rete: *ip route* è il comando che si usa su shell 
    + c'è il protocollo netlink, che rende facile la gestione di cose diverse (rispetto ad ioctl)
    + Inizialmente si usava ioctl, si apriva un socket: c'erano diversi problemi:
        - a seconda di cosa si voleva fare si dovevano inserire molte flag diverse 
        - mancava di fatto una API che facesse le stesse cose che si fanno su terminale (con ip addr, ip link, ecc...) e 
          mancava un supporto per il server che manda le configurazioni (che in virtualsquare è stato fatto): 
            - quando uso ip di fatto sono un client, che ottiene da un server netlink (il kernel del SO) la configurazione di rete 
            - per esempio con ioctl non posso configurare uno stack attraverso il dhcp - iothnamed in virtualsquare 

## In virtualsquare 
- contiene un API per fare le stesse cose che ci sono sul terminale, sia per lato client che lato server 


### <u>iothconf</u>
- https://github.com/virtualsquare/iothconf

- iothconf può configurare uno stack ioth (cioè una rete ioth) passando una stringa, mettendo: 
    + dati statici: cioè metto gli indirizzi direttamente 
    + dhcp (IPv4 e IPv6): protocollo di livello 3 che funziona che una macchina manda un pacchetto in broadcast e chiede a tutti se c'è qualcuno che può assegnare a tale macchina l'indirizzo IP: il dhcp server risponde e da' anche altre informazioni (es.  )
        + in IPv6 è diverso, perchè in IPv4 finchè non si assegna l'indirizzo ad una certa interfaccia non si può comunicare. Invece in IPv6 appena si accende l'interfaccia viene assegnato un indirizzo detto <u>indirizzo link local</u> che consente di parlare in IPv6 con le macchine della rete locale:
            - tale indirizzo comincia con fe80:: 
            - non si possono mandare ancora pacchetti sulla rete globale
            - il dhcp server IPv6 usa pacchetti udp IPv6 (Neighbor Discovery Protocl), il protocollo IPv6 però è stato creato per poter avere anche un'autoconfigurazione usando un altro protocollo, detto *router discovery*, che funziona nel seguente modo: 
                - l'interfaccia di una macchina manda un pacchetto che si chiama router discovery (ICMPv6), che chiede se ci siano dei router, se ci sono rispondono con un *router advertisement*, che indica quali sono i primi 64 bit della rete locale
                - combinando questi 64 bit del router advertisement, assieme ai 64 bit che si ottengono dal MAC Address, si ottiene l'indirizzo completo IPv6
            - In IPv6 è normale avere più indirizzi per un'interfaccia (indirizzo link local e indirizzo global)
            - Allora la domanda è "A cosa serve il dhcp IPv6?" - può fornire altre informazioni es. Il DNS server da usare 

    - Esperimento 1: auto configurazione IPv6
    - ```bash
    $vde_plug hub:///tmp/hub cmd://'ssh vde vde_plug'#metto hub perchè così vedo i pacchetti passare, e l'ho messo come default 
    ```
    - apre un altro terminale
    ```bash
        $vdens vde:///tmp/hub
        $ip link set vde0 up
        $wireshark 
    ```
    - Wireshark: qualcuno fa port scanning durante la lezione, ci disturberà un po', ha aperto wireshark, c'erano un sacco di pacchetti ARP 

    - Esperimento 2: IPv4: il pacchetto va dalla rete vera (almawifi), va alla tap (interfaccia della macchina virtuale) e poi alla macchina virtuale con l'indirizzo configurato 
    
    ```bash
        $vdens vde:///tmp/hub
        $ip link set vde0 up
        $ip addr add 130.136.31.2/24 dev vde0 
        $ip addr  
        $ip route add default via 130.136.31.1 
        $traceroute 130.136.31.1/24
    ```

    - in ioth l'indirizzo può essere calcolato sulla hash del nome, anche il DNS server può fare il calcolo con l'hash del nome    
        + si semplifica enormemente la configurazione del DNS server, indicando che le macchine in un certo dominio abbiano l'hash calcolato in quel modo 
        + vedi https://github.com/virtualsquare/iothconf?tab=readme-ov-file#options-supported-by-ioth_config-and-ioth_newstackc, con una semplice stringa si può configurare tutto 

### Configurazione di un DNS
- uno dei DNS più utilizzati è *bind*: 
    - directory /etc/bind/name.conf 
    ```conf
        //Lista degli slaves 
        acl "virtlabslaves"{
            <indirizzo IPv4>
            <indirizzo IPv4>
        }

        zone "virtlab.unibo.it" in {
            type master;                //Il master è il dns principale, ha gli slaves cioè macchine che ne copiano la configurazione, se crolla il master si      usano gli slaves 
            notify yes; 
            file "/etc/bind/pri/db.virtlab.unibo.it";       
            allow-transfer {"virtlabslaves";};              //chi può chiedere il trasferimento 
            allow-query {"any";};                           //chi può fare le query 
        }
    ```
    - Il dns si interroga con due comandi: *host* (dns lookup utility) e *dig* 
    - L'indirizzo è al contrario perchè se uno legge .it, va al DNS più grande -> si legge il contenitore più grande e poi quello più piccolo nella risoluzione della dns query 

   ```bash 
    $host -t any 161.136.130.in-addr.arpa   
    ```
    - CNAME nel dns, se c'è il punto alla fine indica un dominio al di fuori di quello locale 
    - Se io ho creato un dns locale, devo fare la delega al dns di livello superiore per poter mostrarlo 

    - gerarchia: 
        + named.conf e poi per ogni dominio di risoluzioni dirette o inverse, c'è un file che contiene le definizioni che devono essere viste 

### <u>iothnamed</u>
- https://github.com/virtualsquare/iothnamed
- è un DNS server per l'Internet of Threads 
- Il DNS interagisce con: 
    + chi fa le query 
    + gli altri DNS server a monte 
- Se il DNS server non ha il nome che deve risolvere nella cache, deve chiedere al DNS server sopra di lui 
    + ha due stack: uno per gestire le richieste, uno per inoltrarle 
    
- Questo dns usa nomi locali e proxy: consente di vedere la risoluzione di tutto 
    - vedi https://github.com/virtualsquare/iothnamed#static-local-names--proxy--cache
    ```bash
        # The service is provided for queriers reaching this server on the
        # vde network vde:///tmp/hub, IP address 192.168.1.24.
        rstack    stack=vdestack,vnl=vde:///tmp/hub
        rstack    mac=80:01:01:01:01:01,eth
        rstack    ip=192.168.1.24/24
        # The kernel stack is used to forward requests to remote dns servers
        fstack    stack=kernel

        # forward requests using IPv4 packets to 8.8.8.8 or 80.80.80.80 ~ N.B: I DNS APERTI A TUTTI sono pericolosi, si rischia di ricevere una marea di query 
        dns       8.8.8.8       #google dns 
        dns       80.80.80.80   #altro dns libero 

        # the net name 'local' defines the ip range 192.168.1.0/24
        net       local 192.168.1.0/24

        # clients from 'local' are allowed to send tcp dns requests
        auth      accept local
        # clients from 'local' can receive replies for names xxxx.test.local
        auth      static local .test.local
        # clients from 'local' can receive replies for names 1.168.192.in-addr.arpa
        auth      static local 192.168.1.0/24
        # search in the cache (forwarded query results are cached)
        auth      cache local .
        # requests from 'local' can be forwarded
        auth      fwd local .


        # static definitions
        static    A one.test.local 192.168.1.1      #Nomi locali (risoluzione diretta)
        static    A two.test.local 192.168.1.2
        # static definitions for reverse resolution
        static    PTR 192.168.1.1 one.test.local    #Nomi locali (risoluzione inversa)
        static    PTR 192.168.1.2 two.test.local 

    ```
    - I DNS si possono interrogare in UDP e TCP, ma si potrebbero interrogare in HTTPS (questioni di sicurezza)

    - Esperimento 4: dns (inizialmente rovinato da almawifi perchè impedisce di usare altri dns)
    - In questo modo, usando in DNS locale, si possono usare nomi locali nascosti al mondo e anche tutti quelli disponibili con i dns ufficiali 
    - auth hash - usa l'hash per calcolare l'indirizzo IPv6, parlando con il server in IPv4
    ```bash 
        $vde_plug hub:///tmp/hub null://
    ```
    - altro terminale
    ```bash 
        $host <name_macchina>.hash.local 
    ```
    - se la macchina non c'è gli mette l'indirizzo IPv6 
    