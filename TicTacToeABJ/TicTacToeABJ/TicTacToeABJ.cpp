#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Enum für den Spielstatus
enum class Spielstatus {Laufend, VictoryX, VictoryO, Untentschieden};

class Spieler {
    string name; //Name von Spieler 1 und 2
    char symbol; //X oder O

};//endofclass

char feld[3][3]; //Spielfeld initialisieren
void anzeigen() {
}//endoffunction

 void spielen() {
    //einlesen von eingabe für jeweiligen Spieler
}
    

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