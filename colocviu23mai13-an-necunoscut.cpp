/// 2025-09-03-1230-1357
/// Irimia David
/// VS Code
/// g++ main.cpp -o e.exe
/// ./e.exe
/// Radu Tudor Vrinceanu

////////////////
/// Ierarhie ///
////////////////

/// Statie: adresa(strada+numar+sector), mijloaceTransport, cod(SU-1, SE-2), idStatie, nume 
///     StatieUrbana: punctAchizitionareLegitimatii
///     StatieExtraurbana: suburbii

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

/// Statie: adresa(strada+numar+sector), mijloaceTransport, cod(SU-1, SE-2), idStatie, nume 
/// Clasa abstracta
class Statie {
    static int id;
    int idStatie;
    string adresa, cod, nume;
    vector<string> mijloaceTransport;
public:
    /// Constructor
    Statie(const string &adresa, const vector<string> &mijloaceTransport, const string &nume, const string &cod) {
        this->idStatie = ++id;
        this->adresa = adresa;
        this->cod = cod;
        this->nume = nume;
        this->mijloaceTransport = mijloaceTransport;
    }

    /// Destructor virtual
    virtual ~Statie() {}

    /// Metoda virtuala pura
    virtual void afiseaza() = 0;

    /// Getteri
    static int getId() { return id; }
    const int getIdStatie() const { return idStatie; }
    const string &getAdresa() const { return adresa; }
    const string &getCod() const { return cod; }
    const string &getNume() const { return nume; }
    const vector<string> &getMijloaceTransport() const { return mijloaceTransport; }

};

/// Initializam varibila statica id = 0
int Statie::id = 0;

/// StatieUrbana: punctAchizitionareLegitimatii
class StatieUrbana : public Statie {
    string punctAchizitionareLegitimatii;
public:
    /// Constructor
    StatieUrbana(const string &adresa, const vector<string> &mijloaceTransport, const string &nume, const string &punctAchizitionareLegitimatii, const string &cod = "SU") : Statie(adresa, mijloaceTransport, nume, cod), punctAchizitionareLegitimatii(punctAchizitionareLegitimatii) {
        cout << "Statie urbana #" << getId() << " adaugata\n";
    }

    /// Destructor
    ~StatieUrbana() {
        cout << "Statie urbana #" << getIdStatie() << " scoasa\n";
    }

    /// Afiseaza statia urbana
    void afiseaza() {
        bool first = true;
        cout << getCod() << "-" << getIdStatie() << ". Adresa: " << getAdresa() << "; nume statie: " << getNume() << "; punct achizitionare legitimatii: " << punctAchizitionareLegitimatii << "; mijloace transport: ";
        for (auto mijlocTransport : getMijloaceTransport()) {
            if (first) {
                cout << mijlocTransport;
                first = false;
            } else {
                cout << ", " << mijlocTransport;
            }
        }
        cout << ".\n";
    }
};

///     StatieExtraurbana: suburbii
class StatieExtraurbana : public Statie {
    vector<string> suburbii;
public:
    /// Constructor
    StatieExtraurbana(const string &adresa, const vector<string> &mijloaceTransport, const string &nume, const vector<string> &suburbii, const string &cod = "SE") : Statie(adresa, mijloaceTransport, nume, cod), suburbii(suburbii) {
        cout << "Statie extraurbana #" << getId() << " adaugata\n";
    }

    /// Destructor
    ~StatieExtraurbana() {
        cout << "Statie extraurbana #" << getIdStatie() << " scoasa\n";
    }

    /// Afiseaza statia extraurbana
    void afiseaza() {
        bool first = true;
        cout << getCod() << "-" << getIdStatie() << ". Adresa: " << getAdresa() << "; nume statie: " << getNume() << "; mijloace transport: ";
        for (auto mijlocTransport : getMijloaceTransport()) {
            if (first) {
                cout << mijlocTransport;
                first = false;
            } else {
                cout << ", " << mijlocTransport;
            }
        }
        cout << "; suburbii: ";
        /// Prima suburbie nu are virgula inainte, asta pentru o afisare mai eleganta
        first = true;
        for (auto suburbie : suburbii) {
            if (first) {
                cout << suburbie;
                first = false;
            } else {
                cout << ", " << suburbie;
            }
        }
        cout << ".\n";
    }
};

/// Singelton
class SingletonMenu {
    static SingletonMenu* instanta;
    vector<Statie*> statii;
    /// Constructor privat
    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    /// Destrucor public
    ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
        for (auto *statie : statii) {
            delete statie;
            statie = nullptr;
        }
    }

    /// Metoda statica pentru a returna variabila statica, instanta
    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    /// Pentru a nu repeta codul si in constructorul privat si in metoda op5()
    void afiseazaOptiuni() const {
        cout << "1. Adauga o statie\n";
        cout << "2. Afiseaza o statie\n";
        cout << "3. Afiseaza toate statiile\n";
        cout << "4. Estimeaza pretul intre doua statii\n";
        cout << "5. Afiseaza optiuni\n";
        cout << "6. Iesi din meniu\n";
    }

    void op1() {
        string adresa, mijlocTransport, raspuns, nume, tip;
        vector<string> mijloaceTransport;
        /// Statie: adresa(strada+numar+sector), mijloaceTransport, cod(SU-1, SE-2), idStatie, nume 
        cout << "Adaug o statie...\n";
        cout << "Adresa (strada + numar + sector): ";
        getline(cin, adresa);
        do {
            cout << "Mijloc de transport: ";
            getline(cin, mijlocTransport);
            mijloaceTransport.push_back(mijlocTransport);
            cout << "Inca unul (da/nu): ";
            getline(cin, raspuns);
            
            /// Exceptia se propaga
            if (raspuns != "da" && raspuns != "nu") {
                throw invalid_argument("Raspuns invalid\n");
            }
        } while (raspuns == "da");
        cout << "Nume statie: ";
        getline(cin, nume);
        
        cout << "Tip (urbana/extraurbana): ";
        cin >> tip;
        cin.get();
        if (tip == "urbana") {
            /// StatieUrbana: punctAchizitionareLegitimatii
            string punctAchizitionareLegitimatii;
            cout << "Punct achizitionare legitimatii: ";
            getline(cin, punctAchizitionareLegitimatii);
            statii.push_back(new StatieUrbana(adresa, mijloaceTransport, nume, punctAchizitionareLegitimatii));
        } else if (tip == "extraurbana") {
            /// StatieExtraurbana: suburbii
            string suburbie;
            vector<string> suburbii;
            do {
                cout << "Suburbie: ";
                getline(cin, suburbie);
                suburbii.push_back(suburbie);
                cout << "Inca una (da/nu): ";
                getline(cin, raspuns);
                
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            statii.push_back(new StatieExtraurbana(adresa, mijloaceTransport, nume, suburbii));
        } else {
            throw invalid_argument("Tip invalid\n");
        }
    }

    void op2() const {
        string criteriu;
        cout << "Afisez o statie...\n";
        /// Verificam daca avem statii adaugate
        if (statii.empty()) {
            cout << "Nu exista nicio statie\n";
        } else {
            cout << "Criteriu: (nume/adresa/cod): ";
            getline(cin, criteriu);
            
            if (criteriu == "nume") {
                bool statieGasita = false;
                string nume;
                cout << "Numele statiei cautate: ";
                getline(cin, nume);
                for (auto *statie : statii) {
                    if (nume == statie->getNume()) {
                        statie->afiseaza();
                        statieGasita = true;
                    }
                }
                if (!statieGasita) {
                    cout << "Nu am gasit statia cu numele " << nume << "\n";
                }
            } else if (criteriu == "adresa") {
                bool statieGasita = false;
                string adresa;
                cout << "Adresa statiei cautate: ";
                getline(cin, adresa);
                for (auto *statie : statii) {
                    if (adresa == statie->getAdresa()) {
                        statie->afiseaza();
                        statieGasita = true;
                    }
                }
                if (!statieGasita) {
                    cout << "Nu am gasit statia cu adresa " << adresa << "\n";
                }
            } else if (criteriu == "cod") {
                bool statieGasita = false;
                string tip;
                int idStatie;
                cout << "Tipul statiei cautate (SU/SE): ";
                getline(cin, tip);
                cout << "Id-ul statiei cautate: ";
                cin >> idStatie;
                cin.get();
                for (auto *statie : statii) {
                    if (tip == statie->getCod() && idStatie == statie->getIdStatie()) {
                        statie->afiseaza();
                        statieGasita = true;
                    }
                }
                if (!statieGasita) {
                    cout << "Nu am gasit statia cu codul " << tip << "-" << idStatie << "\n";
                }
            }
        }
    }

    void op3() const {
        cout << "Afisez toate statiile...\n";
        /// Verificam daca avem statii adaugate
        if (statii.empty()) {
            cout << "Nu exista nicio statie\n";
        }
        for (auto *statie : statii) {
            statie->afiseaza();
        }
    }

    void op4() const {
        cout << "Estimez pretul intre doua statii...\n";
        /// Verificam daca avem statii adaugate
        if (statii.empty()) {
            cout << "Nu exista nicio statie\n";
        }
    }

    void op5() const {
        afiseazaOptiuni();
    }

    void op6() const {
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
            
            if (optiune < 1 || optiune > 6) {
                throw out_of_range("Optiune invalida\n");
            }

            switch(optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
                case 5: m->op5(); break;
                case 6: m->op6(); break;
            }
        } while (optiune != 6);
    } catch (const out_of_range &e) {
        /// Exceptia este prinsa si tratata
        cout << "Out of range: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    }

    /// Pentru apela destructorul obiectului m
    delete m;

    return 0;
}
