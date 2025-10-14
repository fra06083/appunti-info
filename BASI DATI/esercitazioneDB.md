https://docs.google.com/presentation/d/1OuxnSOqHkj6Uq6xCSGzfK0mAlCn3xGZUVThRiFzQkrQ/edit?slide=id.p9#slide=id.p9
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
$\large \pi_{\text{UserId}}$($\large \sigma_{author = Fleming}$(BOOK)
$\large \Join$ 
(BORROWING))
$\LARGE -$
$\large \pi_{\text{UserId}}$($\large \sigma_{author \neq Fleming}$(BOOK)
$\large \Join$ 
(BORROWING))
- - -
esercizio 11
equi-join fra booking e room, li unisco tramite gli attributi code e room

$\large \pi_{name,building}$($\large \sigma_{subject = Database \land date = today}$(EXAM)
$\large \Join_{code=exam}$ 
(ROOM)
$\large \Join_{room=code}$ 
(BOOKING))