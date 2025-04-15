#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Enum für den Spielstatus
enum class Spielstatus { Laufend, Gewonnen, Unentschieden };

// Basisklasse Spieler
class Spieler {
protected:
    string name;
    char symbol;
public:
    Spieler(const string& n, char s) : name(n), symbol(s) {}
    virtual int macheZug() = 0; // Polymorph: jede Spielerart kann eigenen Zug machen
    string getName() const { return name; }
    char getSymbol() const { return symbol; }
};

// Menschlicher Spieler (von Spieler abgeleitet)
class MenschlicherSpieler : public Spieler {
public:
    MenschlicherSpieler(const string& n, char s) : Spieler(n, s) {}
    int macheZug() override {
        int eingabe;
        cout << name << " ist am Zug (" << symbol << "). Wähle ein Feld (1-9): ";
        cin >> eingabe;
        return eingabe;
    }
};

// Spielbrett Klasse
class Spielbrett {
private:
    char feld[3][3];

public:
    Spielbrett() { reset(); }

    void reset() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                feld[i][j] = ' ';
    }

    void anzeigen() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " ";
            for (int j = 0; j < 3; ++j) {
                char display = feld[i][j];
                if (display == ' ') display = '1' + i * 3 + j;
                cout << display;
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "-----------\n";
        }
        cout << "\n";
    }

    bool zugSpielen(int nummer, char symbol) {
        if (nummer < 1 || nummer > 9) return false;
        int i = (nummer - 1) / 3;
        int j = (nummer - 1) % 3;
        if (feld[i][j] == ' ') {
            feld[i][j] = symbol;
            return true;
        }
        return false;
    }

    Spielstatus pruefeStatus(char symbol) {
        for (int i = 0; i < 3; ++i) {
            if ((feld[i][0] == symbol && feld[i][1] == symbol && feld[i][2] == symbol) ||
                (feld[0][i] == symbol && feld[1][i] == symbol && feld[2][i] == symbol))
                return Spielstatus::Gewonnen;
        }
        if ((feld[0][0] == symbol && feld[1][1] == symbol && feld[2][2] == symbol) ||
            (feld[0][2] == symbol && feld[1][1] == symbol && feld[2][0] == symbol))
            return Spielstatus::Gewonnen;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (feld[i][j] == ' ') return Spielstatus::Laufend;

        return Spielstatus::Unentschieden;
    }
};


// Spiellogik Klasse
class Spiel {
private:
    Spielbrett brett;
    Spieler* spieler[2];
    int scores[2] = { 0, 0 };
    int starter = 0;

public:
    Spiel() {
        string name1, name2;
        cout << "Spieler 1 Name: "; getline(cin, name1);
        cout << "Spieler 2 Name: "; getline(cin, name2);
        spieler[0] = new MenschlicherSpieler(name1, 'X');
        spieler[1] = new MenschlicherSpieler(name2, 'O');
    }

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


    ~Spiel() {;
        delete spieler[0];
        delete spieler[1];
    }

    void starten() {
        char nochmal;
        do {
            brett.reset();
            spielen();
            cout << "\nAktueller Spielstand:\n";
            cout << spieler[0]->getName() << ": " << scores[0] << " Siege\n";
            cout << spieler[1]->getName() << ": " << scores[1] << " Siege\n";
            cout << "Revanche spielen? (j/n): ";
            cin >> nochmal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (nochmal == 'j' || nochmal == 'J');
    }

    void spielen() {
        int zugIndex = 0;
        Spielstatus status = Spielstatus::Laufend;

        while (status == Spielstatus::Laufend) {
            brett.anzeigen();
            Spieler* aktuellerSpieler = spieler[(zugIndex + starter) % 2];
            int eingabe = aktuellerSpieler->macheZug();

            if (brett.zugSpielen(eingabe, aktuellerSpieler->getSymbol())) {
                status = brett.pruefeStatus(aktuellerSpieler->getSymbol());
                if (status == Spielstatus::Gewonnen) {
                    brett.anzeigen();
                    cout << aktuellerSpieler->getName() << " gewinnt!\n";
                    if ((zugIndex + starter) % 2 == 0) ++scores[0];
                    else ++scores[1];
                    starter = (zugIndex + starter + 1) % 2;
                }
                else if (status == Spielstatus::Unentschieden) {
                    brett.anzeigen();
                    cout << "Unentschieden!\n";
                    starter = (starter + 1) % 2;
                }
                ++zugIndex;
            }
            else {
                cout << "Ungültiger Zug. Versuche es erneut.\n";
            }
        }
    }
};

int main() {
    Spiel spiel;
    spiel.starten();
    return 0;
}