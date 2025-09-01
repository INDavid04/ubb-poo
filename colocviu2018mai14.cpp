/// 2025-01-09-1200-1331

/// Seria 14 - 24 mai 2018

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

////////////////
/// Ierarhie ///
////////////////

/// Vizitator: nume, varsta, categorie(pensionar/elev/student/etc)
/// Eveniment: titlu, vizitatori
///     ExpozitiePermanentaGratuita
///     EvenimentTemporar: pretIntrare, evenimenteSpeciale(re-enactment de evenimente istorice/demonstratii de lupta cu spada cu participarea unor trupe de teatru/etc)
/// Muzeu: adresa, deschis, evenimente, vizitatori

////////////////
////////////////
////////////////

/// Vizitator: nume, varsta, categorie(pensionar/elev/student/etc)
class Vizitator {
    static int id;
    int idVizitator;
    string nume, categorie;
    int varsta;
public:
    Vizitator(const string &nume, const int varsta, const string &categorie) {
        this->nume = nume;
        this->varsta = varsta;
        this->categorie = categorie;
        idVizitator = ++id;
    }

    static int getId() { return id; }
    const int getIdVizitator() const { return idVizitator; }
    const string &getNume() const { return nume; }
    const int getVarsta() const { return varsta; }
    const string &getCategorie() const { return categorie; }

    void afiseaza() const {
        cout << idVizitator << ". " << nume << ", " << varsta << " ani, " << categorie << "\n";
    }
};

int Vizitator::id = 0;

/// Eveniment: titlu, vizitatori
class Eveniment {
    string titlu;
    vector<Vizitator*> vizitatoriEveniment;
public:
    Eveniment(const string &titlu, const vector<Vizitator*> &vizitatoriEveniment) : titlu(titlu), vizitatoriEveniment(vizitatoriEveniment) {}

    virtual ~Eveniment() {
        cout << "Vizitator scos\n";
        for (auto *vizitator : vizitatoriEveniment) {
            delete vizitator;
            vizitator = nullptr;
        }
    }

    virtual void afiseaza() const = 0;

    const vector<Vizitator*> &getVizitatoriEveniment() const { return vizitatoriEveniment; }
    const string &getTitlu() const { return titlu; }
};

///     ExpozitiePermanentaGratuita
class ExpozitiePermanentaGratuita : public Eveniment {
public:
    ExpozitiePermanentaGratuita(const string &titlu, const vector<Vizitator*> &vizitatoriEveniment) : Eveniment(titlu, vizitatoriEveniment) {}

    ~ExpozitiePermanentaGratuita() {
        cout << "Vizitator expozitie permanenta gratuita scos\n";
        for (auto *vizitator : getVizitatoriEveniment()) {
            delete vizitator;
            vizitator = nullptr;
        }
    }

    void afiseaza() const override {
        cout << "\n" << getTitlu() << "\n";
        for (auto *vizitator : getVizitatoriEveniment()) {
            vizitator->afiseaza();
        }
    }
};

///     EvenimentTemporar: pretIntrare, evenimenteSpeciale(re-enactment de evenimente istorice/demonstratii de lupta cu spada cu participarea unor trupe de teatru/etc)
class EvenimentTemporar : public Eveniment {
    double pretIntrare;
    vector<string> evenimenteSpeciale;
public:
    EvenimentTemporar(const string &titlu, const vector<Vizitator*> &vizitatoriEveniment, const double pretIntrare, const vector<string> &evenimenteSpeciale) : Eveniment(titlu, vizitatoriEveniment), pretIntrare(pretIntrare), evenimenteSpeciale(evenimenteSpeciale) {}

    ~EvenimentTemporar() {
        cout << "Vizitator eveniment temporar scos\n";
        for (auto *vizitator : getVizitatoriEveniment()) {
            delete vizitator;
            vizitator = nullptr;
        }
    }

    void afiseaza() const override {
        cout << "\n" << getTitlu() << "\n";
        for (auto *vizitator : getVizitatoriEveniment()) {
            vizitator->afiseaza();
        }
    }
};

/// Muzeu: adresa, deschis, evenimente, vizitatori
class Muzeu {
    string adresa, deschis;
    vector<Eveniment*> evenimente;
    vector<Vizitator*> vizitatoriMuzee;
public:
    Muzeu(const string &adresa, const string &deschis, const vector<Eveniment*> &evenimente, const vector<Vizitator*> &vizitatoriMuzee) : adresa(adresa), deschis(deschis), evenimente(evenimente), vizitatoriMuzee(vizitatoriMuzee) {}

    ~Muzeu() {
        cout << "Muzeu scos\n";
        for (auto *eveniment : evenimente) {
            delete eveniment;
            eveniment = nullptr;
        }
        for (auto *vizitator : vizitatoriMuzee) {
            delete vizitator;
            vizitator = nullptr;
        }
    }

    void afiseaza() {
        cout << "Adresa: " << adresa << ", deschis in intervalul: " << deschis << ", vizitatori muzeu:\n";
        for (auto *vizitator : getVizitatorMuzee()) {
            vizitator->afiseaza();
        }
        cout << "Evenimente:\n";
        for (auto *eveniment : evenimente) {
            eveniment->afiseaza();
        }
    }

    const vector<Vizitator*> &getVizitatorMuzee() const { return vizitatoriMuzee; }
};

class SingletonMenu {
    static SingletonMenu* instanta;
    vector<Muzeu*> muzee;

    SingletonMenu() {
        afiseazaOptiuni();
    }
    
public:
    ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
        for (auto *muzeu : muzee) {
            delete muzeu;
            muzeu = nullptr;
        }
    }

    static SingletonMenu *getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    void afiseazaOptiuni() {
        cout << "Optiuni:\n";
        cout << "1. Afiseaza vizitatorii\n";
        cout << "2. Adauga muzeu\n";
        cout << "3. Afiseaza optiuni\n";
        cout << "4. Iesi din meniu\n";
    }

    void op1() const {
        cout << "Afisez vizitatorii...\n";
        if (muzee.empty()) {
            cout << "Nu avem niciun vizitator\n";
        }
    }

    void op2() {
        cout << "Adaug muzeu...\n";
        string raspuns; /// folosit in while-uri pentru a adauga un numar variabil de vizitatori/muzee

        /// Muzeu: adresa, deschis, evenimente, vizitatori
        string adresa, deschis;
        vector<Eveniment*> evenimente;
        vector<Vizitator*> vizitatoriMuzee;
        cout << "Adresa: ";
        getline(cin, adresa);
        cout << "Deschis in intervalul orar: ";
        getline(cin, deschis);

        /// Vizitator: nume, varsta, categorie(pensionar/elev/student/etc)
        string nume, categorie;
        int varsta;
        cout << "Adaug vizitator muzeu...\n";
        do {
            cout << "Nume: ";
            getline(cin, nume);
            cout << "Varsta: ";
            cin >> varsta;
            cin.get();
            cout << "Categorie (pensionar/elev/student/etc): ";
            getline(cin, categorie);
            vizitatoriMuzee.push_back(new Vizitator(nume, varsta, categorie));
            cout << "Adauga inca un vizitator la muzeu (da/nu): ";
            getline(cin, raspuns);
            if (raspuns != "da" && raspuns != "nu") {
                throw invalid_argument("Raspuns invalid\n");
            }
        } while (raspuns == "da");

        /// Eveniment: titlu, vizitatori
        string titlu, tip;
        vector<Vizitator*> vizitatoriEveniment;
        cout << "Adaug eveniment...\n";
        cout << "Tip (expozitie permanenta gratuita / eveniment temporar): ";
        getline(cin, tip);
        if (tip == "expozitie permanenta gratuita") {
            /// ExpozitiePermanentaGratuita
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Adaug vizitator eveniment...\n";
            do {
                string nume, categorie;
                int varsta;
                cout << "Nume: ";
                getline(cin, nume);
                cout << "Varsta: ";
                cin >> varsta;
                cin.get();
                cout << "Categorie (pensionar/elev/student/etc): ";
                getline(cin, categorie);
                vizitatoriEveniment.push_back(new Vizitator(nume, varsta, categorie));
                cout << "Adauga inca un vizitator la eveniment (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            evenimente.push_back(new ExpozitiePermanentaGratuita(titlu, vizitatoriEveniment));
            muzee.push_back(new Muzeu(adresa, deschis, evenimente, vizitatoriMuzee));
        } else if (tip == "eveniment temporar") {
            /// EvenimentTemporar: pretIntrare, evenimenteSpeciale(re-enactment de evenimente istorice/demonstratii de lupta cu spada cu participarea unor trupe de teatru/etc)
            double pretIntrare;
            string evenimentSpecial;
            vector<string> evenimenteSpeciale;
            cout << "Titlu: ";
            getline(cin, titlu);
            cout << "Adaug vizitator eveniment...\n";
            do {
                string nume, categorie;
                int varsta;
                cout << "Nume: ";
                getline(cin, nume);
                cout << "Varsta: ";
                cin >> varsta;
                cin.get();
                cout << "Categorie (pensionar/elev/student/etc): ";
                getline(cin, categorie);
                vizitatoriEveniment.push_back(new Vizitator(nume, varsta, categorie));
                cout << "Adauga inca un vizitator la eveniment (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            cout << "Pret intrare: ";
            cin >> pretIntrare;
            cin.get();
            do {
                cout << "Eveniment special (re-enactment de evenimente istorice/demonstratii de lupta cu spada cu participarea unor trupe de teatru/etc): ";
                getline(cin, evenimentSpecial);
                evenimenteSpeciale.push_back(evenimentSpecial);
                cout << "Adauga inca un eveniment special (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            evenimente.push_back(new EvenimentTemporar(titlu, vizitatoriEveniment, pretIntrare, evenimenteSpeciale));
            muzee.push_back(new Muzeu(adresa, deschis, evenimente, vizitatoriMuzee));
        } else {
            throw invalid_argument("Eveniment invalid\n");
        }
    }

    void op3() {
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
