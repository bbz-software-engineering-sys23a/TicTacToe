#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Enum für den Spielstatus
enum class Spielstatus {laufend, victoryX, victoryO, untentschieden};

class Spieler {
    string name; //Name von Spieler 1 und 2
    char symbol; //X oder O

};//endofclass

char feld[3][3]; //Spielfeld initialisieren
void anzeigen() {
}//endoffunction

bool spielen(int eingabe, char symbol) {
    //einlesen von Eingabe und überprüft ob Feld frei oder besetzt, Rückgabewert true--> Spielzug korrekt, false--> falsche Eingabe oder Feld bereits besetzt
    if (eingabe < 1 || eingabe > 9) return false; //Eingabe nicht korrekt
    int zeile;
    zeile = (eingabe - 1) / 3; //Berechnung Zeile
    int spalte;
    spalte = (eingabe - 1) % 3; //Berechnung Spalte
    if (feld[eingabe][spalte] == ' ') {
        feld[eingabe][spalte] = symbol;
        return true; //Spielzug erfolgreich
    }
    return false; //Feld nicht frei
}//endoffunction
/*
* Erklärung der Funktion Rechenweg:
* Tik Tac Toe Spielfeld
* 1     2       3
* 4     5       6
* 7     8       9
* Dementsprechedes 2D Array
* feld[0][0] feld[0][1] feld[0][2]
* feld[1][0] feld[1][1] feld[1][2]
* feld[2][0] feld[2][1] feld[2][2]
* 
* Eingabe 7
* Zeile: (7-1)/3 = 2
* Spalte: (7-1)%3 = 0
* 
* Eingabe 5
* Zeile: (5-1)/3 = 1
* Spalte: (5-1)%3 = 1
*/

void reset() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            feld[i][j] = ' ';
}//endoffunction

class Gewinnerkennung {

    //todo counter adden für Spieler 1 und 2 wie oft gewonnen
private:
    bool xGewinnt = false;
    bool oGewinnt = false;
    bool tempXDiagVal = true;
    bool tempODiagVal = true;
    int diagIndex = 2;



public:

    Gewinnerkennung(char feld[3][3]) {

        for (int i = 0; i < 3; i++) {
            if ((feld[i][i]) != 'X') {
                tempXDiagVal = false;
            }
            if ((feld[i][i]) != 'O') {
                tempODiagVal = false;
            }
        }

        for (int i = 0; i < 3; i++) {
            if ((feld[i][diagIndex]) != 'X') {
                tempXDiagVal = false;
            }
            if ((feld[i][diagIndex]) != 'O') {
                tempODiagVal = false;
            }
            diagIndex--;
        }

        xGewinnt = tempXDiagVal;
        oGewinnt = tempODiagVal;

        diagIndex = 2;

        for (int row = 0; row < 3; row++) {

            if (feld[row][0] == 'X' && feld[row][1] == 'X' && feld[row][2] == 'X') {
                xGewinnt = true;
            }
            else if (feld[row][0] == 'O' && feld[row][1] == 'O' && feld[row][2] == 'O') {
                oGewinnt = true;
            }

        }

        for (int column = 0; column < 3; column++) {

            if (feld[0][column] == 'X' && feld[1][column] == 'X' && feld[2][column] == 'X') {
                xGewinnt = true;
            }
            else if (feld[0][column] == 'O' && feld[1][column] == 'O' && feld[2][column] == 'O') {
                oGewinnt = true;
            }

        }

    }

    bool getXGewinnt() {
        return xGewinnt;
    }

    bool getOGewinnt() {
        return oGewinnt;
    }


};//endofclass

int main() {
    string n1, n2; //String für Spielernamen
    anzeigen();
    while (1) {

    }//endofwhile
}//endofmain