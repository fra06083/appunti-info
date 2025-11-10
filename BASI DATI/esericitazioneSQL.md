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

si formano i gruppi sulla base dell-uguaglianza della condizione degli attributi messi nella condizione di group by.

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
-- IDK chiedi a mathie
SELECT COUNt(*)
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