/// 2025-09-05-1100-1229
/// Irimia David
/// g++ main.cpp -o e.exe
/// ./e.exe
/// Radu Tudor Vrinceanu
/// Seria 14

////////////////
/// Ierarhie ///
////////////////

/// Bilet: plecare, sosire, dataSiOraPlecarii, codTren, durataCalatorie, distantaParcursa, pret, serie /// seria e de forma <tip><clasa>-<id>, de exemplu: RII-453
/// Tren: clasa, codTren
///     TrenRegio: /// circula pe distante medii si mici si opreste in toate statiile
///     TrenInterRegio: loc /// circula pe distante medii si lungi

/// Pretul se calculeaza astfel:
///     - 0.39 lei/km pentru trenuri regio
///     - 0.7 lei/km pentru trenuri inter-regio
///     - Biletele la clasa I au taxa 20% din pretul biletului initial

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

/// Tren: clasa, codTren
class Tren {
    string clasa, codTren;
    static int id;
    int idTren;
public:
    Tren(const string &clasa, const string &codTren) {
        this->clasa = clasa;
        this->codTren = codTren;
        idTren = ++id;
    }

    virtual ~Tren() {}

    virtual void afiseaza() = 0;

    const string &getClasa() const { return clasa; }
    const string &getCodTren() const { return codTren; }
    static int getId() { return id; }
    const int getIdTren() const { return idTren; }
};

int Tren::id = 0;

/// TrenRegio: /// circula pe distante medii si mici si opreste in toate statiile
class TrenRegio : public Tren {
public:
    TrenRegio(const string &clasa, const string &codTren = "R") : Tren(clasa, codTren) {
        cout << "Tren regio #" << getId() << " adaugat\n";
    }

    ~TrenRegio() {
        cout << "Tren regio #" << getIdTren() << " scos\n";
    }

    void afiseaza() {
        cout << "Tren regio: " << getCodTren() << "-" << getIdTren() << ", clasa: " << getClasa() << "\n";
    }
};

/// TrenInterRegio: loc /// circula pe distante medii si lungi
class TrenInterRegio : public Tren {
    int loc;
public:
    TrenInterRegio(const string &clasa, const int loc, const string &codTren = "IR") : Tren(clasa, codTren), loc(loc) {
        cout << "Tren inter-regio #" << getId() << " adaugat\n";
    }

    ~TrenInterRegio() {
        cout << "Tren inter-regio #" << getIdTren() << " scos\n";
    }

    void afiseaza() {
        cout << "Tren inter-regio: " << getCodTren() << "-" << getIdTren() << ", clasa: " << getClasa() << ", loc: " << loc << "\n";
    }

    const int getLoc() const { return loc; }
};

/// Bilet: plecare, sosire, dataSiOraPlecarii, durataCalatorie, distantaParcursa, pret, serie /// seria e de forma <tip><clasa>-<id>, de exemplu: RII-453
class Bilet {
    const Tren *t;
    string plecare, sosire, dataSiOraPlecarii;
    int durataCalatorie, distantaParcursa;
    double pret;
    static int id;
    int idBilet;
public:
    Bilet(const string &plecare, const string &sosire, const string &dataSiOraPlecarii, const int durataCalatorie, const int distantaParcursa, const double pret, const Tren *t) : plecare(plecare), sosire(sosire), dataSiOraPlecarii(dataSiOraPlecarii), durataCalatorie(durataCalatorie), distantaParcursa(distantaParcursa), pret(pret), t(t) {
        cout << "Bilet eliberat\n";
    }

    ~Bilet() {
        cout << "Bilet distrus\n";
        delete t;
        t = nullptr;
    }

    void afiseaza() const {
        cout << t->getCodTren() << "-" << idBilet << ". Plecare: " << plecare << "; Sosire: " << sosire << "; Data si ora plecarii: " << dataSiOraPlecarii << "; Durata calatorie: " << durataCalatorie << "; Distanta parcursa: " << distantaParcursa << "; Pret: " << pret << "; Seria: " << t->getCodTren() << t->getClasa() << "-" << t->getIdTren() << "\n";
    }

    const Tren *getTren() const { return t; }
    const string getPlecare() const { return plecare; }
    const string getSosire() const { return sosire; }
    const string getDataSiOraPlecarii() const { return dataSiOraPlecarii; }
    const int getDurataCalatorie() const { return durataCalatorie; }
    const int getDistantaParcursa() const { return distantaParcursa; }
    const double getPret() const { return pret; }
    const int getIdBilet() const { return idBilet; }
    static int getId() { return id; }
    const int getIdTren() const { return t->getIdTren(); }
    const string getCodTren() const { return t->getCodTren(); }
};

int Bilet::id = 0;

class SingletonMenu {
    static SingletonMenu* instanta;
    vector<Bilet> bilete;

    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
    }

    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Elibereaza bilet nou\n";
        cout << "2. Listeaza biletele eliberate pentru un anumit tren (dupa codul trenului)\n";
        cout << "3. Afiseaza optiuni\n";
        cout << "4. Iesi din meniu\n";
    }

    void op1() {
        cout << "Eliberez bilet nou...\n";
        /// Bilet(const string &plecare, const string &sosire, const string &dataSiOraPlecarii, const int durataCalatorie, const int distantaParcursa, const double pret, const Tren *t)
        string plecare, sosire, dataSiOraPlecarii, clasa, codTren;
        int durataCalatorie, distantaParcursa;
        double pret;

        cout << "Statia de plecare: ";
        getline(cin, plecare);
        cout << "Statia de sosire: ";
        getline(cin, sosire);
        cout << "Data si ora plecarii: ";
        getline(cin, dataSiOraPlecarii);
        cout << "Durata calatoriei in minute: ";
        cin >> durataCalatorie;
        cin.get();
        cout << "Distanta parcursa in km: ";
        cin >> distantaParcursa;
        cin.get();

        /// Pretul se calculeaza astfel:
        ///     - 0.39 lei/km pentru trenuri regio
        ///     - 0.7 lei/km pentru trenuri inter-regio
        ///     - Biletele la clasa I au taxa 20% din pretul biletului initial

        cout << "Tren (R/IR): ";
        getline(cin, codTren);

        if (codTren == "R") {
            /// TrenRegio(const string &clasa, const string &codTren)
            cout << "Clasa (I/II): ";
            getline(cin, clasa);

            if (clasa == "I") {
                pret = 0.39 * distantaParcursa;
                pret = pret + (20/100) * pret;
            } else if (clasa == "II") {
                pret = 0.39 * distantaParcursa;
            } else {
                throw invalid_argument("Clasa invalida. Alege intre I si II!\n");
            }

            bilete.push_back(Bilet(plecare, sosire, dataSiOraPlecarii, durataCalatorie, distantaParcursa, pret, new TrenRegio(clasa, codTren)));
        } else if (codTren == "IR") {
            /// TrenInterRegio(const string &clasa, const int loc, const string &codTren = "IR")
            cout << "Clasa (I/II): ";
            getline(cin, clasa);

            if (clasa == "I") {
                pret = 0.7 * distantaParcursa;
                pret = pret + (20/100) * pret;
            } else if (clasa == "II") {
                pret = 0.7 * distantaParcursa;
            } else {
                throw invalid_argument("Clasa invalida. Alege intre I si II!\n");
            }     
            
            int loc;
            cout << "Loc: ";
            cin >> loc;
            cin.get();

            bilete.push_back(Bilet(plecare, sosire, dataSiOraPlecarii, durataCalatorie, distantaParcursa, pret, new TrenInterRegio(clasa, loc, codTren)));
        } else {
            throw invalid_argument("Tren invalid. Alege intre R si IR!\n");
        }
    }

    void op2() const {
        cout << "Listez biletele eliberate pentru un anumit tren, dupa codul trenului...\n";
        if (bilete.empty()) {
            cout << "Nu aveti bilete\n";
        } else {
            string codTren;
            int idTren;
            bool gasit = false;
            cout << "Introduceti codul trenului pentru care vreti sa aflati biletele eliberate: ";
            getline(cin, codTren);
            cout << "Introduceti id-ul trenului pentru care vreti sa aflati biletele eliberate: ";
            cin >> idTren;
            cin.get();
            for (auto bilet : bilete) {
                if (bilet.getCodTren() == codTren && bilet.getIdTren() == idTren) {
                    gasit = true;
                    bilet.afiseaza();
                }
            }
            if (!gasit) {
                cout << "Nu am gasit trenul repsectiv\n";
            }
        }
    }

    void op3() const {
        afiseazaOptiuni();
    }

    void op4() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 4) {
                throw out_of_range("Optiune invalida\n");
            }

            switch (optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
            }
        } while (optiune != 4);
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    }
    
    delete m;

    return 0;
}
