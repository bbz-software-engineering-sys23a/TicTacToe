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
