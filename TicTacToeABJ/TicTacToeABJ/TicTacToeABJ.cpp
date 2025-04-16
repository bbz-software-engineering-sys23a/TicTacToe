#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Enum für den Spielstatus
enum class Spielstatus { Laufend, Gewonnen, Unentschieden };

class Gewinnerkennung {
    private:
        bool xGewinnt = false;
        bool oGewinnt = false;
        bool tempXDiagVal = true;
        bool tempODiagVal = true;
        int diagIndex = 2;

        

    public:

        Gewinnerkennung(char Feld[3][3]) {

            for (int i = 0; i < 3; i++) {
                if ((Feld[i][i]) != 'X') {
                    tempXDiagVal = false;
                }
                if ((Feld[i][i]) != 'O') {
                    tempODiagVal = false;
                }
            }

            for (int i = 0; i < 3; i++) {
                if ((Feld[i][diagIndex]) != 'X') {
                    tempXDiagVal = false;
                }
                if ((Feld[i][diagIndex]) != 'O') {
                    tempODiagVal = false;
                }
                diagIndex--;
            }

            xGewinnt = tempXDiagVal;
            oGewinnt = tempODiagVal;

            diagIndex = 2;
            
            for (int row = 0; row < 3; row++) {
                
                if (Feld[row][0] == 'X' && Feld[row][1] == 'X' && Feld[row][2] == 'X') {
                    xGewinnt = true;
                } else if (Feld[row][0] == 'O' && Feld[row][1] == 'O' && Feld[row][2] == 'O') {
                    oGewinnt = true;
                }
                
            }

            for (int column = 0; column < 3; column++) {
                
                if (Feld[0][column] == 'X' && Feld[1][column] == 'X' && Feld[2][column] == 'X') {
                    xGewinnt = true;
                } else if (Feld[0][column] == 'O' && Feld[1][column] == 'O' && Feld[2][column] == 'O') {
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

char name_benutzer_1[50];
char name_benutzer_2[50];
char symbol_benutzer_1= 'X';
char symbol_benutzer_2= 'o';




    printf("Willkommen zu Tic Tac Toe \n") ;
    printf( " \n Bitte geben Sie Ihre Namen an  \n Name Benutzer 1 : ");
    scanf("%s", name_benutzer_1);
    printf( "\n Name Benutzer 2 : ");
    scanf("%s", name_benutzer_2);
    printf("\nSpieler 1: %s spielt mit '%c'\n", name_benutzer_1, symbol_benutzer_1);
    printf("Spieler 2: %s spielt mit '%c'\n", name_benutzer_2, symbol_benutzer_2);



    return 0;
}