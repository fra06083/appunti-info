<span style="color:Tomato">Regole di query:</span>
Non possiamo impostare valori nulli in cui quel valore è necessario per fare valutazioni, ci sarebbe ambiguità pensa come se il nome mancasse in una tabella per le classi.
Puoi rinominare i campi direttamente nella query:
```
Select Docenti.NOME as NOMEDOCENTE, Studenti.nome as NomeStudente FROM Studenti, Docenti
```
possiamo scegliere anche prefissi per le tabelle
CHIEF := Employee
CHIEF.Wage