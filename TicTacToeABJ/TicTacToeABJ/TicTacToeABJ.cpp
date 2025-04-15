// TicTacToeABJ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

//Enum für Spielstatus
enum class Spielstatus {Laufend, Gewonnen, Unentschieden};

class Spielbrett {
private:
    char Feld[3][3];

public:
    Spielbrett() {Reset();}

    void Reset() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                Feld[i][j] = ' ';
    }//endoffunction

    void Anzeigen() {

    }//endoffunction

    bool ZugSpielen(int Nummer, char Symbol) {

    }//endoffunction
};//endofclass

class Spieler {
protected: 
    char Symbol;
public: 
};//endofclass

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


};//endofclass


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
