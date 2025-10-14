Introduzione storica gas
- - -
#### Data definition
```sql
CREATE DATABASE db_name
```
crea un database (no way, non ci credo)

```sql
CREATE SCHEMA schema_name
-- oppure
CREATE SCHEMA schema_name
AUTHORIZATION 'user_name' 
```
questo, è identificato da un nome e descrive gli elementi che vi appartengono. Lo schema apparterrà allo user che lo avrà creato; lo statement può essere accompagnato dalla keyword AUTHORIZATION per specificare un determinato user che possiede lo schema

``` sql
CREATE TABLE
```
Specifica una nuova relazione e crea la sua istanza vuota.
esempio:
```sql
CREATE TABLE EMPLOYEE (
Number CHARACTER(6) PRIMARY KEY,
Name CHARACTER(20) NOT NULL,
Surname CHARACTER(20) NOT NULL,
Dept CHARACTER(15),
Wage NUMERIC(9) DEFAULT 0,
FOREIGN KEY(Dept) REFERENCES
DEPARTMENT(Dept),
UNIQUE (Surname, Name)
)
```
arrivato alla slide 15 