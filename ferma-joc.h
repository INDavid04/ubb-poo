#include <iostream>
using namespace std;

class Joc {
private:
    int zi;
    bool gameOver;
    static long long counterContinueGame;
    static Joc* instanta; /// instanta unica

    /// Constructor fara parametrii
    Joc() {
        zi = 0;
        gameOver = false;
        counterContinueGame = 0; /// fiecare incrementare ar fi echivalentul a trecerii unei ore, realizez ca nu prea are sens insa trebe folosit si getter-ul, right?
    }
    /// Constructor cu toti parametrii
    Joc(int ziDefault, bool gameOverDefault, long long counterContinueGameDefault) {
        zi = ziDefault;
        gameOver = gameOverDefault;
        counterContinueGame = counterContinueGameDefault;
    }
    /// Constructor cu parametrii
    Joc(int ziDefault, bool gameOverDefault) {
        zi = ziDefault;
        gameOver = gameOverDefault;
        counterContinueGame = 0;
    }
    /// Constructor cu parametrii
    Joc(bool gameOverDefault, long long counterContinueGameDefault) {
        zi = 0;
        gameOver = gameOverDefault;
        counterContinueGame = counterContinueGameDefault;
    }
    /// Constructor de copiere
    Joc(const Joc& altJoc) {
        zi = altJoc.zi;
        gameOver = altJoc.gameOver;
        counterContinueGame = altJoc.counterContinueGame;
    }
protected:
public:
    static Joc* getInstanta() {
        if (!instanta) {
            instanta = new Joc();
        }
        return instanta;
    }
    /// Suprascrierea operatorului egal
    Joc& operator=(const Joc& altJoc) {
        if(this != &altJoc) { 
            zi = altJoc.zi;
            gameOver = altJoc.gameOver;
            counterContinueGame = altJoc.counterContinueGame;
        }
        return *this;
    }
    /// Destructor
    ~Joc() {
        cout << "Joc finalizat! Ati petrecut " << counterContinueGame << " ore la ferma bunicului.\n";
    }
    /// Setter
    void setDay(int specificDay = 0) {
        zi = specificDay;
    }
    /// Getter
    int getZi() {
        return zi;
    }
    static long long getCounterContiuneGame() {
        return counterContinueGame;
    }
    void separator() {
        cout << "\n=================================================================================================\n\n";
    }
    void showDay() {
        cout << "\n==============================================Ziua" << zi++ << "==============================================\n\n";
    }
    void continueGame() {
        counterContinueGame++;
        char continuaJoc = '1';
        cout << "Apasa 1 pentru a continua jocul: ";
        cin >> continuaJoc;
        cin.get();
        if (continuaJoc != '1') {
            cout << "Iesire din joc ...\n";
            exit(0); /// inchidem programul
        }
        cout << "\n=================================================================================================\n\n";
    }
    void menu(Joc& g, Jucator& j) { /// referintele obiectelor
        bool ruleazaMeniu = true;
        while (ruleazaMeniu) {
            int optiune = 0;
            cout << "\n Meniu-------------------------------------------------------------------------------------------\n";
            cout << "| 1 - Continua jocul | 2 - Despre jucator | 3 - Afla orele petrecute la ferma | 4 - Iesi din joc |\n";
            cout << " ------------------------------------------------------------------------------------------------\n";
            cout << "Alege o optiune din cele de mai sus [1,4]: ";
            cin >> optiune;
            cin.get();
            cout << "\n=================================================================================================\n\n";
            switch (optiune) {
                case 1:
                    counterContinueGame++;
                    ruleazaMeniu = false;
                    break;
                case 2:
                    j.showInfo();
                    break;
                case 3:
                    cout << "Ai petrecut " << g.getCounterContiuneGame() << " ore la ferma bunicului!\n";
                    break;
                case 4:
                    cout << "Iesire din joc ...\n";
                    exit(0); /// termina complet programul
                default:
                    cout << "Nu inteleg ce vrei sa faci! Alege un numar intre 1 si 4: ";
            }
        }
        if (ruleazaMeniu) {
            cout << "\n=================================================================================================\n";
        }
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Joc& j) {
        out << "Game Day: " << j.zi << ", Game Over: " << (j.gameOver ? "DA" : "NU") << ", Game Counter: " << j.counterContinueGame;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Joc& j) {
        cout << "Introdu ziua curenta: ";
        in >> j.zi;
        cout << "Joc terminat? (1 - DA, 0 - NU): ";
        in >> j.gameOver;
        cout << "Introdu un numar ce reprezinta un contor al numarului de continuari ale jocului: ";
        in >> j.counterContinueGame;
        return in;
    }
};

Joc* Joc::instanta = nullptr;
