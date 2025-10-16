hhttps://docs.google.com/presentation/d/1OuxnSOqHkj6Uq6xCSGzfK0mAlCn3xGZUVThRiFzQkrQ/edit?slide=id.p9#slide=id.p9
![[image-9.png]] 
es 3 questo boh selfie
	start           end
da boston ad atlanta

da atlanta  a   chicago

$\large \Join$  
- - -
esercizio 4
natural join associa gli attributi con lo stesso nome motivo per cui ho bisogno di fare il rename da name a course 
$\sigma_{Price> Age * 10}$ ($\large \rho_{Person<-- Id}$ (PERSON)
$\Join$
(ENROLLMENT)
$\Join$ 
$\large \rho_{Course <-- Name}$ (COURSE))
- - -
esercizio 5
$\large \pi_{name, sruname, id}$($\large \rho_{student<--id}$(STUDENT)
$\large \Join$
$\large \sigma_{mark = 30}$(EXAM))
- - -
esercizio 6
$\large \pi_{name, surname, id}$(STUDENT) - $\large \pi_{name, sruname, id}$($\large \rho_{student<--id}$(STUDENT)
$\large \Join$
$\large \sigma_{mark = 30}$(EXAM))

- - -
esercizio 7
$\large \pi_{name}$((SUPPLIER)
$\Join_{Id=SupId}$
$\sigma_ProdId \neq \text{PX274}$(SUPPLYING))
- - -
esercizio 8
$\large \rho_{<--SupId, ProdId, Quantity}$(SUPPLYING)
$\large \Join$
(SUPPLYING)
- - -
esercizio 9
$\large \pi_{\text{UserId}}$($\large \sigma_{author = Fleming}$(BOOK)
$\large \Join$ 
(BORROWING))
- - -
esercizio 10
fai la differenza fra le due tabelle (vedila come una sottrazione fra insiemi)
$\large \pi_{\text{UserId}}$($\large \sigma_{author = Fleming}$(BOOK)
$\large \Join$ 
(BORROWING))
$\LARGE -$
$\large \pi_{\text{UserId}}$($\large \sigma_{author \neq Fleming}$(BOOK)
$\large \Join$ 
(BORROWING))
- - -
esercizio 11
$\large\pi_{name, building}$($\large \sigma_{subject = "database"}$(EXAM)
$\Join_{code = exam}$
$\large \sigma_{date=today}$(BOOKING))
$\Join_{room=code}$
(ROOM)
- - -
Esercizio 12
R3 := $\large \rho_{date<--date1}$ R2 - $\large \pi_{student,date1}$($\large \sigma_{date<date1}$(R1 := $\large \pi_{student,date}$ ($\large \sigma_{mark = 30}$(EXAM))
$\Join$ 
R2 := $\large \rho_{date1 = date}$(R1))


$\large \pi_{name,surname,date}(STUDENT \Join_{id=student}R3)$ 

tutto da rivedere questo aiut
- - -
esercizio 13

foto sul telefono aiuto

- - -
esercizio 14

$\large \pi_{wineshop}$((CATALOG)
$\Join_{wine = code}$
$\large \sigma_{color = rose \lor color = red}$(WINE))
- - -
esercizio 15

$\large \pi_{name}$((WINESHOP)
$\Join$
$\Large \sigma_{color = red \land color = rose}$(WINE))

sbagliato zio pera, non puoi fare $\Large \sigma_{color = red \land color = rose}$ 
![[Pasted image 20251015102153.png]]
non puoi fare l'and, perché il colore o è rosso o rosé
- - -
esercizio 16

$\large \pi_{name}$($\large \sigma_{gender = female}$(PERSON)
$\Join$
$\large \sigma_{pizza = mushroom}$(EATS))
$\LARGE \cap$
$\large \pi_{name}$($\large \sigma_{gender = female}$(PERSON)
$\Join$
$\large \sigma_{pizza = pepperoni}$(EATS))
qua prima tocca fare prima la proiezione, perché se la facessi dopo l'intersezione ci potrebbero essere dei problemi con le chiavi, data la presenza di righe duplicate (?)
- - -
esercizio 17
la differenza serve per prendere la parte con SOLO i maschi o SOLO le femmine
$\large \pi_{pizzeria}$($\Large \sigma_{gender = F}$(PERSON) $\Join$ (FREQUENTS))
-
$\large \pi_{pizzeria}$($\Large \sigma_{gender = M}$(PERSON) $\Join$ (FREQUENTS))
$\large \cup$
$\large \pi_{pizzeria}$($\Large \sigma_{gender = M}$(PERSON) $\Join$ (FREQUENTS))
-
$\large \pi_{pizzeria}$($\Large \sigma_{gender = F}$(PERSON) $\Join$ (FREQUENTS))
- - -
esercizio 18 
mia sol
$\large \pi_{code,name}$( (MAGAZINE)
$\large \Join$
(ARTICLE) - $\large \sigma_{topic = motorcycling}$(ARTICLE)) {fare sta differenza equivale a fare la selection sul topic diverso da motorcycling}

scazzato, almeno un articolo che non sia sul motorcycling

la sol la trovi sul telefono gasante:

- - -
esercizio 19

$\pi_{id,name}$(SAILOR
$\Join{id=sailor}$

$\large \pi_{sailor}$((BOOKING)
$\large \Join_{id =boat}$
$\large \sigma_{color = red}$(BOAT)
$\LARGE\cap$
$\large \pi_{sailor}$((BOOKING)
$\large \Join_{id =boat}$
$\large \sigma_{color = green}$(BOAT)))

sul telefono, foto di una sol alternativa
- - -
esercizio 20

S := $\large \pi_{Eid, Pid}$($\large \sigma_{range = 5000}$(PLANE)    $\large \Join_{id=pid}$ (CERTIFICATE))

$\LARGE \pi_{id,name}$(EMPLOYEE $\Join_{Id=Eid}$  $\large \rho_{p1, E1 <-- pid, eid}$ (S)
$\large \Join_{p1 \neq p2 \land E1 = E2}$
$\large \rho_{p2, E2 <-- pid, eid}$ (S)))

on at least two aircraft, ovvero si intende, maggiore di uno
uh, noccapito il join di employee aiut

