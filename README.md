# TicTacToe

## Mitwirkende

- [Joel Frei](https://github.com/joel724)
- [Benjamin Eichenberger](https://github.com/hiimbooom)
- [Armin Kasumovic](https://github.com/Arminski99)

## Features

- 3x3 TicTacToe Feld
- Best-of-one Spielbar
- Gewinnerkennungsalgorithmus

## Zusatzfeatures

- Variables TicTacToe-Feld
- Beliebiges Best-of
- Scoreboard
- Revanche Option

## Usecase

![simpleUsecase](/pictures/simpleUsecase.png)

> [!NOTE]
> Dies ist nur ein simpler Usecase ohne Zusatzfeatures und Errorhandling


## Dokumentation





## Spielanleitung 


### Spielregeln

1. **Abwechselndes Setzen**

    o Die Spieler setzen abwechselnd ihr Symbol („X“ oder „O“) auf
       ein freies Feld im Raster.
       
2. **Ziel des Spiels**

    o Wer es zuerst schafft, drei seiner Symbole waagrecht,
    senkrecht oder diagonal in einer Reihe zu platzieren, gewinnt.

3. **Unentschieden**

    o Wenn alle 9 Felder belegt sind und niemand drei in einer Reihe
       hat, endet das Spiel unentschieden.


### Spielablauf

**1. Benutzerregistrierung**

    - Der Name des ersten Spielers wird eingegeben
    - Der Name des zweiten Spielers wird eingegeben
    - Die Spieler werden automatisch den Symbolen „X“ und „O“ zugewiesen

**2. Spielstart**

    - Der erste Spieler wird aufgefordert, seinen Spielzug zu machen
    - Durch die Eingabe einer Zahl von 1 bis 9 wird das gewünschte Feld ausgewählt
    - Das Spielfeld wird nach jedem Zug aktualisiert angezeigt
    - Anschliessend ist der nächste Spieler an der Reihe

**3. Spielverlauf**

    - Das Spiel verläuft gemäß den bekannten Spielregeln (siehe oben)

**4. Spielende**

    - Nach Spielende (Sieg oder Unentschieden) wird die Anzahl der bisherigen Siege
    angezeigt
    - Es besteht die Möglichkeit, eine Revanche zu spielen
    Mit „j“ (ja) oder „n“ (nein) kann die Revanche angenommen oder abgelehnt werden
    - Wird die Revanche angenommen, startet das Spiel von vorn
    - Wird die Revanche abgelehnt, wird das Programm beendet

### Sequenzdiagramm
![sequenzdiagramm](/pictures/sequenzdiagramm.png)

### Struktogramm
![struktogramm](/pictures/struktogramm.png)


