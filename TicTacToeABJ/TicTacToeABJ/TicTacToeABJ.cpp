#include <iostream>//Standardlibrary
#include <string>  //Für Stringbearbeitung
#include <limits>  //Für Eingabelimitierung
#include <cstring> //Für Memorycopy


/*Tic Tac Toe Spiel
* Armin Karsumovic
* Joel Frei
* Benjamin Eichenberger
* SYS23a
* Projekt der Seminarwoche Softwareentwicklung von 14.04.2025-17.04.2025
* Last update on: 17.04.2025
*/

using namespace std;

//Enum für den Spielstatus
enum class Spielstatus { laufend, victoryX, victoryO, unentschieden }; //Für Statuserkennung

//Klasse für das Spielbrett
class Spielbrett {
private:
    char feld[3][3];
public:
    //Konstruktor initialisiert das Feld
    Spielbrett() { reset(); }

    //Setzt das 2D-Array zurück: alles leer (' ')
    void reset() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                feld[i][j] = ' ';
    }//endoffunction

    //Gibt das Feld aus
    void anzeigen() const {
        const int size = 3; //Wäre variabel möglich, 3 --> Standardfeld Tic Tac Toe
        int lineSize = (size - 1) * 4;
        string lineLength = string("-----") + string(lineSize, '-') + "\n";

        cout << lineLength;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << "| ";
                char inhalt = feld[i][j];
                if (inhalt == ' ') inhalt = '1' + i * 3 + j;
                cout << inhalt << " ";
            }
            cout << "|\n" << lineLength;
        }
    }//endoffunction

    //Übeprüft ob ein Spielzug korrekt ist, gibt true zurück wenn erfolgreich
    bool spielen(int eingabe, char symbol) {
        if (eingabe < 1 || eingabe > 9) return false;
        int zeile = (eingabe - 1) / 3;
        int spalte = (eingabe - 1) % 3;
        if (feld[zeile][spalte] == ' ') {
            feld[zeile][spalte] = symbol;
            return true;
        }
        return false;
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

//Gibt Zugriff auf das interne Array für Statusprüfung
    char(&getFeld())[3][3]{ return feld; }
};//endofclass

//Klassenhierarchie für Spieler
class Spieler {
public:
    string name;
    char symbol;
    Spieler(const string& n, char s) : name(n), symbol(s) {}
    virtual ~Spieler() = default;
};//endofclass

class KreuzSpieler : public Spieler {
public:
    KreuzSpieler(const string& n) : Spieler(n, 'X') {}
};//endofclass

class KreisSpieler : public Spieler {
public:
    KreisSpieler(const string& n) : Spieler(n, 'O') {}
};//endofclass

//Klasse zur Erkennung des Spielstatus
class Statuserkennung {

private:
    char Feld[3][3]; //Das kopierte Spielbrett

public:

    //Spielfeld setzen 
    void setFeld(char feld[3][3]) {
        //Kopiert Parameter auf klassenlokale Variable (Uebernommen von StackOverflow)
        std::memcpy(Feld, feld, sizeof(char) * 3 * 3);
    }

    //Spielstatus berechnen
    Spielstatus status() {

        //Lokale Variablen 
        bool xGewinnt = false;
        bool oGewinnt = false;
        bool isRunning = false;

        //Lokale Variablen zur pruefung von Diagonalen
        bool tempXDiagVal = true;
        bool tempODiagVal = true;
        int diagIndex = 2;

        //Hauptdiagonale (links oben nach rechts unten)
        for (int i = 0; i < 3; i++) {
            if (Feld[i][i] != 'X') tempXDiagVal = false;
            if (Feld[i][i] != 'O') tempODiagVal = false;
        }

        //Gegendiagonale (links unten nach rechts oben)
        for (int i = 0; i < 3; i++) {
            if (Feld[i][diagIndex] != 'X') tempXDiagVal = false;
            if (Feld[i][diagIndex] != 'O') tempODiagVal = false;
            diagIndex--;
        }

        //Variablen uebertragen (Falls kein Gewinn -> ändert sich nichts)
        xGewinnt = tempXDiagVal;
        oGewinnt = tempODiagVal;

        //Reihen prüfen
        for (int row = 0; row < 3; row++) {
            if (Feld[row][0] == 'X' && Feld[row][1] == 'X' && Feld[row][2] == 'X') xGewinnt = true;
            if (Feld[row][0] == 'O' && Feld[row][1] == 'O' && Feld[row][2] == 'O') oGewinnt = true;
        }

        //Spalten prüfen
        for (int col = 0; col < 3; col++) {
            if (Feld[0][col] == 'X' && Feld[1][col] == 'X' && Feld[2][col] == 'X') xGewinnt = true;
            if (Feld[0][col] == 'O' && Feld[1][col] == 'O' && Feld[2][col] == 'O') oGewinnt = true;
        }

        //Prüfen ob freie Felder vorhanden sind
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Feld[i][j] == ' ') {
                    isRunning = true;
                }
            }
        }

        //Status zurückgeben
        if (xGewinnt) return Spielstatus::victoryX;
        if (oGewinnt) return Spielstatus::victoryO;
        if (isRunning) return Spielstatus::laufend;
        return Spielstatus::unentschieden;
    }
};//endofclass

int siege1 = 0; //Counter für Anzahl Siege Spieler 1
int siege2 = 0; //Counter für Anzahl Siege Spieler 2
char revanche;  //Abfrage char für Revanche
bool gueltigeEingabe = false; //Überprüfungsvariable, ob Eingabe korrekt für Abfrage bei Revanche --> true bei korrekter Eingabe
bool X_anfang = true; //Wechselt nach jeder Revanche

int main() {
    cout << "Willkommen zu Tic Tac Toe\n";
    cout << "Bitte geben Sie Ihre Namen an\n";
    cout << "Name Benutzer 1: ";
    string name_benutzer_1, name_benutzer_2;
    getline(cin, name_benutzer_1);
    cout << "Name Benutzer 2: ";
    getline(cin, name_benutzer_2);

    KreuzSpieler spielerX(name_benutzer_1);
    KreisSpieler spielerO(name_benutzer_2);
    Spieler* aktuellerSpieler;

    Statuserkennung checker;
    Spielbrett brett;

    do {
        brett.reset();
        gueltigeEingabe = false;
        //Starter wechseln per if-else
        if (X_anfang) {
            aktuellerSpieler = static_cast<Spieler*>(&spielerX);
        }
        else {
            aktuellerSpieler = static_cast<Spieler*>(&spielerO);
        }
        X_anfang = !X_anfang;

        Spielstatus status = Spielstatus::laufend;

        while (status == Spielstatus::laufend) {
            brett.anzeigen();
            int eingabe;
            cout << aktuellerSpieler->name << " (" << aktuellerSpieler->symbol << ") waehle ein Feld (1-9): ";
            cin >> eingabe;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ungültige Eingabe. Bitte gib eine Zahl zwischen 1 und 9 ein.\n";
                continue;
            }
            if (!brett.spielen(eingabe, aktuellerSpieler->symbol)) {
                cout << "Ungültiger Zug oder Feld besetzt. Versuche es erneut.\n";
                continue;
            }
            //Status prüfen
            checker.setFeld(brett.getFeld());
            status = checker.status();
            //Spieler wechseln per if-else
            if (aktuellerSpieler == static_cast<Spieler*>(&spielerX)) {
                aktuellerSpieler = static_cast<Spieler*>(&spielerO);
            }
            else {
                aktuellerSpieler = static_cast<Spieler*>(&spielerX);
            }
        }

        brett.anzeigen();
        if (status == Spielstatus::victoryX) {
            cout << spielerX.name << " gewinnt!\n";
            ++siege1;
        }
        else if (status == Spielstatus::victoryO) {
            cout << spielerO.name << " gewinnt!\n";
            ++siege2;
        }
        else {
            cout << "Unentschieden!\n";
        }

        cout << "Aktueller Spielstand:\n"
            << spielerX.name << ": " << siege1 << " Siege\n"
            << spielerO.name << ": " << siege2 << " Siege\n";

        while (!gueltigeEingabe) {
            std::cout << "Wollen Sie eine Revanche? (j/n): ";
            std::cin >> revanche;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoriert alle Eingaben wenn mehr als 1 Zeichen und löscht diese
            if (revanche == 'j' || revanche == 'J') {
                cout << "\nNeue Runde wird gestartet\n";
                gueltigeEingabe = true;
            }
            else if (revanche == 'n' || revanche == 'N') {
                cout << "\nSpiel wird beendet. Danke fürs Spielen!\n";
                gueltigeEingabe = true;
            }
            else {
                cout << "Ungültige Eingabe, bitte 'j' oder 'n' eingeben.\n";
            }
        }//endofwhile

    }//endofdo
    while (revanche == 'j' || revanche == 'J');
    return 0;
}//endofmain