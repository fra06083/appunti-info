es. 1
```sql
SELECT DISTINCT S.Surname 
FROM STUDENT AS S JOIN LECTURER AS L on S.Surname = L.Surname
```

es.  2
```sql
SELECT L.Surname, COUNT(EX.Student)
FROM LECTURER AS L, EDITION AS ED, EXAM AS EX  
WHERE L.Id = ED.Lecturer AND ED.Course = EX.Course
		AND ED.Year = EX.Year
GROUP BY EX.Course, L.Id, L.Surname, ED.Year
HAVING COUNT(EX.Student) > 10
```

si formano i gruppi sulla base dell'uguaglianza della condizione degli attributi messi nella condizione di group by.
dividere in classe di equvalenza

es. 3
```sql
SELECT MAX(T.Mile), MIN(T.Mile)
FROM TRAIN as T
WHERE (T.Departure = 'Chicago' AND T.Arrival = 'Boston') OR 
	  (T.Departure = 'Boston' AND T.Arrival = 'Chicago')
```
si, esistono max e min zio pera......

es. 4
```sql
-- IDK chiedi a mathieu
SELECT COUNT(*)
FROM REGION AS REG, RESIDENCE AS RES
WHERE REG.Name = RES.Region
GROUP BY REG.Name
HAVING COUNT()
```

aiut..

es. 5
```sql
SELECT F.Title
FROM FILM AS F JOIN RATING AS R -- qui non so se era necessario il join boh
WHERE F.Year >= 1990 AND F.Year <= 2000 
GROUP BY F.Title,  F.FilmID
HAVING AVG(R.Rating) >= 7
	```

pd ho dimenticato di scrivere l'es 6, stica fallo è ez

es. 7
```sql
SELECT DISTINCT p.Name
FROM PLAYLIST AS P, ALBUM AS AL, ARTIST AS AR, SONG AS S
WHERE AR.ID = AL.Artist AND S.Album = AL.ID AND P.Song = S.ID AND
		AL.Year < 2001 AND AR.Labels = 'UMG'
```

es. 8
```sql
SELECT F.Title
FROM FILM AS F
WHERE F.Year > 1960 AND F.Director = 'Federico Fellini'
```

questo ez da paura
es. 9
```sql
SELECT F.Title
FROM FILM AS F
WHERE (F.Genre = 'Sci-fi' AND F.Year > 1990 AND F.Country = 'Japan') OR 
	(F.Genre = "Sci-fi" AND F.Country = 'France')
```

	
es. 10
```sql
SELECT F.Title, F.Genre
FROM FILM AS F, SCREENING AS S, ROOM AS R
WHERE F.Code = S.Film AND S.Room = R.Code AND
	R.City = 'London' AND S.Date = '2023-12-25'
```

es. 11
```sql
SELECT COUNT(*)
FROM ROOM AS R
WHERE R.City = 'London' AND R.Seats > 60
```
qui si poteva usare il groub  by? Boh

es. 12
```sql
SELECT F.Director, A.Name, COUNT(*)
FROM FILM AS F, ACTOR AS A, RECITAL AS R
WHERE R.Film = F.Code AND A.Id = R.Actor
GROUP BY F.Director, A.Name
-----------------or, forse-------------
SELECT F.Director, A.Name, COUNT(*)
FROM FILM AS F, ACTOR AS A, RECITAL AS R
WHERE R.Film = F.Code AND A.Id = R.Actor
GROUP BY F.Director, R.Actor
```

es. 13
```sql
-- prima sol, con actor che in realtà non servirebbe
SELECT F.Director, F.Title 
FROM FILM AS F, ACTOR AS A, RECITAL AS R
WHERE R.Film = F.Code AND A.Id = R.Actor
GROUP BY F.Director, F.Code, F.Title
HAVING COUNT(A.Id) < 6
----modo fancy per farlo, honest da capire-----
SELECT F.Director, F.Title, F.Code
FROM FILM AS F
WHERE 6 > (
			SELECT COUNT(*)
			FROM RECITAL AS R
			WHERE F.Code = R.Film
			)
```

es. 14
```sql
SELECT R.Name, SUM(S.Profits)
FROM SCREENING AS S, ROOM AS R
WHERE S.Room = R.Code AND R.City = 'Rome' 
	AND (S.Date >= '2005-01-01' 
    and S.Date <= '2005-01-31') 
GROUP BY R.Name, R.Code
HAVING SUM(S.Profits) > 20000
```

es.15
```sql
SELECT F.Title
FROM FILM AS F
WHERE NOT EXIST (SELECT *
				 FROM SCREENING AS S, ROOM AS R
				 WHERE R.Code = S.Room AND 
					   S.Film = F.Code AND
					   R.City = 'Berlin')
```

es.16
```sql
SELECT F.Title
FROM FILM AS F
WHERE NOT EXISTS (SELECT *
				 FROM SCREENING AS S, ROOM AS R
				 WHERE R.Code = S.Room AND 
					   S.Film = F.Code AND
					   S.Profits > 500)
-------------------------------altra soluzione-----------------------------------
SELECT F.Title
FROM FILM AS F
WHERE 500 > (SELECT max(S.profits)
				 FROM SCREENING AS S
				 WHERE S.Film = F.Code)
```

es.17
```sql
SELECT F.Title
FROM FILM AS F
WHERE 500 < (SELECT min(S.profits)
				 FROM SCREENING AS S
				 WHERE S.Film = F.Code)
-------------------------------altra soluzione-----------------------------------
-- questa con group by, quindi preferita
SELECT F.Title
FROM FILM AS F
WHERE S.Film = F.Title
GROUP BY F.Code, F.Title
HAVING min(S.Profit) > 500
```

es.18
```sql
SELECT M.NAME
FROM MUSEUM AS M
WHERE M.City = 'London' AND
	  NOT EXISTS (SELECT *
				  FROM WORK AS W
				  WHERE W.NameA = 'Tiziano' AND
				  W.NameM = M.Name)
-- qui il join va fatto per forza dentro la query interna per questioni di scope
```

es .19
```sql

SELECT M.NAME
FROM MUSEUM AS M
WHERE M.City = 'London' AND
	  NOT EXISTS (SELECT *
				  FROM WORK AS W
				  WHERE W.NameA ≠ 'Tiziano' AND
				  W.NameM = M.Name)
-------------------------------altra soluzione---------------------------------
SELECT M.NAME
FROM MUSEUM AS M
WHERE M.City = 'London' AND 
	  'Tiziano' = ALL (SELECT W.NameA
		   FROM WORK AS W
		   WHERE W.NameW = M.Name)
-- tutti i nomi che ci sono degli artisti e controlla che siano tutti uguali a Tiziano
```

es.20
```sql
SELECT M.Name
FROM MUSEUM AS M, WORK AS W, ARTIST AS A
WHERE A.Name = W.NameA AND W.NameN = M.Name AND A.Nationality = 'Italy'
GROUP BY M.Name
HAVING COUNT(*) > 20
```

es.21
```SQL
SELECT C.Plate, O.Name
FROM CARS AS C, OWNERS AS O, INSURANCE AS I
WHERE C.Owner = O.Code AND C.CodeIns = I.CodeIns AND
	  I.CodeIns = 'AVIVA' AND (C.Brand = 'BMW' OR C.power > 120) 
```

es.22
```sql
SELECT I.Name, I.Hq, COUNT(*) AS NumCars
FROM INSURANCES AS I, CARS AS C
WHERE C.CodeIns = I.CodeIns
GROUP BY I.CodeIns, I.Name, I.Hq
```

es.23
```sql
SELECT C.Plate, I.Name, sum(IC.AmountDamage) AS damages
FROM INVOLVEDCARS AS IC, CARS AS C, INSURANCES AS I
WHERE C.CodeIns = I.CodeIns AND IC.Plate = C.Plate
GROUP BY C.Plate, I.Name, I.CodeIns
HAVING COUNT(IC.CodeAcc) > 1
```

es.24
```sql
SELECT C.Plate
FROM CARS AS C
WHERE NOT EXISTS (SELECT *
  					FROM INVOLVEDCARS AS IC, ACCIDENT AS A
  					WHERE IC.Plate = C.Plate AND IC.CodeAcc = A.CodeAcc AND
                  		  A.Date > '2020-05-04'
					)
```

da fare fino al 30