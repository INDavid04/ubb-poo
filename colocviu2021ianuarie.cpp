/// 2025-08-30-1030-1200

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

////////////////
/// Ierarhie ///
////////////////

/// Vaccin: idVaccin, producator, pret, temperatura, substante
class Vaccin {
    static int id;
    int idVaccin;
    string producator;
    double pret, temperatura;
    vector<string> substante;
public:
    Vaccin(const string &producator, const double pret, const double temperatura, const vector<string> &substante) {
        idVaccin = ++id;
        this->producator = producator;
        this->pret = pret;
        this->temperatura = temperatura;
        this->substante = substante;
    }

    virtual ~Vaccin() {}

    static int getId() { return id; }
    const int getIdVaccin() const { return idVaccin; }
    const string &getProducator() const { return producator; }
    const double getPret() const { return pret; }
    const double getTemperatura() const { return temperatura; }
    const vector<string> &getSubstante() const { return substante; }

    virtual void afiseaza() const = 0;
};

int Vaccin::id = 0;

/// VaccinAntigripal: tulpini, respecta
class VaccinAntigripal : public Vaccin {
    vector<string> tulpini;
    bool respecta;
public:
    VaccinAntigripal(const string &producator, const double pret, const double temperatura, const vector<string> &substante, const vector<string> &tulpini, const bool respecta) : Vaccin(producator, pret, temperatura, substante), tulpini(tulpini), respecta(respecta) {
        cout << "Vaccin antigripal #" << getId() << " adaugat\n";
    }

    ~VaccinAntigripal() {
        cout << "Vaccin antigripal #" << getIdVaccin() << " scos\n";
    }

    void afiseaza() const override {
        cout << getIdVaccin() << ". Producator: " << getProducator() << ", pret: " << getPret() << ", temperatura: " << getTemperatura() << ", substante: ";
        bool first = true;
        for (auto &substanta : getSubstante()) {
            if (first) {
                cout << substanta;
                first = false;
            } else {
                cout << ", " << substanta;
            }
        } 
        cout << ", tulpini: ";
        first = true;
        for (auto &tulpina : tulpini) {
            if (first) {
                cout << tulpina;
                first = false;
            } else {
                cout << ", " << tulpina;
            }
        } 
        if(respecta) {
            cout << ", respecta recomandarile date de Organizaaia Mondiala a Sanatatii\n";
        } else {
            cout << ", nu respecta recomandarile date de Organizaaia Mondiala a Sanatatii\n";
        }
    }
};

/// VaccinAntisarscov2: reactii, eficienta, medicamente
class VaccinAntisarscov2 : public Vaccin {
    vector<string> reactii, medicamente;
    double eficienta;
public:
    VaccinAntisarscov2(const string &producator, const double pret, const double temperatura, const vector<string> &substante, const vector<string> &reactii, const double eficienta, const vector<string> &medicamente) : Vaccin(producator, pret, temperatura, substante), reactii(reactii), eficienta(eficienta), medicamente(medicamente) {
        cout << "Vaccin anti Sars-Cov2 #" << getId() << " adaugat\n";
    }

    ~VaccinAntisarscov2() {
        cout << "Vaccin antianti Sars-Cov2 #" << getIdVaccin() << " scos\n";
    }

    void afiseaza() const override {
        cout << getIdVaccin() << ". Producator: " << getProducator() << ", pret: " << getPret() << ", temperatura: " << getTemperatura() << ", substante: ";
        bool first = true;
        for (auto &substanta : getSubstante()) {
            if (first) {
                cout << substanta;
                first = false;
            } else {
                cout << ", " << substanta;
            }
        } 
        /// reactii, eficienta, medicamente
        cout << ", reactii: ";
        first = true;
        for (auto &reactie : reactii) {
            if (first) {
                cout << reactie;
                first = false;
            } else {
                cout << ", " << reactie;
            }
        } 
        cout << ", eficienta: " << eficienta << ", medicamente: ";
        first = true;
        for (auto &medicament : medicamente) {
            if (first) {
                cout << medicament;
                first = false;
            } else {
                cout << ", " << medicament;
            }
        } 
        cout << "\n";
    }
};

/// VaccinAntihepatita: tip, mod
class VaccinAntihepatita : public Vaccin {
    string tip, mod;
public:
    VaccinAntihepatita(const string &producator, const double pret, const double temperatura, const vector<string> &substante, const string &tip, const string &mod) : Vaccin(producator, pret, temperatura, substante), tip(tip), mod(mod) {
        cout << "Vaccin anti hepatita #" << getId() << " adaugat\n";
    }

    ~VaccinAntihepatita() {
        cout << "Vaccin antianti hepatita #" << getIdVaccin() << " scos\n";
    }

    void afiseaza() const override {
        cout << getIdVaccin() << ". Producator: " << getProducator() << ", pret: " << getPret() << ", temperatura: " << getTemperatura() << ", substante: ";
        bool first = true;
        for (auto &substanta : getSubstante()) {
            if (first) {
                cout << substanta;
                first = false;
            } else {
                cout << ", " << substanta;
            }
        } 
        /// tip, mod
        cout << ", tip: " << tip << ", mod de vaccinare: " << mod << "\n";
    }
};

/// Comanda: idComanda, data, nume, vaccinuri
class Comanda {
    static int id;
    int idComanda;
    string data, nume;
    vector<string> vaccinuri;
public:
    Comanda(const string &data, const string &nume, const vector<string> &vaccinuri) : idComanda(++id), data(data), nume(nume), vaccinuri(vaccinuri) {
        cout << "Comanda #" << id << " adaugata\n";
    }

    ~Comanda() {
        cout << "Comanda #" << idComanda << " scoasa\n";
    }

    void afiseaza() const {
        cout << idComanda << ". " << "Data: " << data << ", nume: " << nume << ", vaccinuri: ";
        bool first = true;
        for (auto &vaccin : vaccinuri) {
            if (first) {
                cout << vaccin;
                first = false;
            } else {
                cout << ", " << vaccin;
            }
        }
        cout << "\n";
    }
};

int Comanda::id = 0;

class SingletonMenu {
    static SingletonMenu* instanta;
    vector<Vaccin*> vaccinuri;
    vector<Comanda*> comenzi;

    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    ~SingletonMenu() {
        cout << "Eliberez memoria\n";
        for (auto *comanda : comenzi) {
            delete comanda;
            comanda = nullptr;
        }
        for (auto *vaccin : vaccinuri) {
            delete vaccin;
            vaccin = nullptr;
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
        cout << "1. Adauga vaccin nou\n";
        cout << "2. Afiseaza vacciunurile detinute\n";
        cout << "3. Afiseaza numele producatorilor\n";
        cout << "4. Adauga comanda\n";
        cout << "5. Afiseaza comenzile\n";
        cout << "6. Afiseaza optiunile\n";
        cout << "7. Iesi din meniu\n";
    }

    void op1() {
        /// Vaccin: producator, pret, temperatura, substante
        cout << "Adaug vaccin nou...\n";

        string producator, substanta, raspuns, tip;
        double pret, temperatura;
        vector<string> substante;

        cout << "Producator: ";
        getline(cin, producator);
        cout << "Pret: ";
        cin >> pret;
        cin.get();
        cout << "Temperatura: ";
        cin >> temperatura;
        cin.get();
        do {
            cout << "Substanta: ";
            getline(cin, substanta);
            substante.push_back(substanta);
            cout << "Adauga substanta (da/nu): ";
            getline(cin, raspuns);
            if (raspuns != "da" && raspuns != "nu") {
                throw invalid_argument("Raspuns invaid\n");
            }
        } while (raspuns == "da");

        cout << "Tip vaccin anti- (gripa/sarscov2/hepatita): ";
        getline(cin, tip);
        if (tip == "gripa") {
            /// VaccinAntigripal: tulpini, respecta
            vector<string> tulpini;
            string tulpina, raspuns;
            bool respecta;
            do {
                cout << "Tulpinia (de exemplu: A-H1N1, A-H3N2, A-California): ";
                getline(cin, tulpina);
                tulpini.push_back(tulpina);
                cout << "Adauga tulpina (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invaid\n");
                }
            } while (raspuns == "da");
            cout << "Respecta recomandarile date de Organizatia Mondiala a Sanatatii (da/nu): ";
            getline(cin, raspuns);
            respecta = (raspuns == "da") ? true : false;
            vaccinuri.push_back(new VaccinAntigripal(producator, pret, temperatura, substante, tulpini, respecta));
        } else if (tip == "sarscov2") {
            /// VaccinAntisarscov2: reactii, eficienta, medicamente
            string reactie, medicament, raspuns;
            vector<string> reactii, medicamente;
            double eficienta;
            do {
                cout << "Reactie (de exemplu: durere de cap, stare de voma, ameteala, etc.): ";
                getline(cin, reactie);
                reactii.push_back(reactie);
                cout << "Adauga reactie (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invaid\n");
                }
            } while (raspuns == "da");
            cout << "Rata de eficienta (in procente): ";
            cin >> eficienta;
            cin.get();
            do {
                cout << "Medicament contraindicat folosirii pe o perioada de 6 luni: ";
                getline(cin, medicament);
                medicamente.push_back(medicament);
                cout << "Adauga medicament (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invaid\n");
                }
            } while (raspuns == "da");
            vaccinuri.push_back(new VaccinAntisarscov2(producator, pret, temperatura, substante, reactii, eficienta, medicamente));
        } else if (tip == "hepatita") {
            /// VaccinAntihepatita: tip, mod
            string tip, mod;
            cout << "Tip (A, B, C): ";
            getline(cin, tip);
            cout << "Mod (intramuscular/subcutanat/intradermic): ";
            getline(cin, mod);
            vaccinuri.push_back(new VaccinAntihepatita(producator, pret, temperatura, substante, tip, mod));
        } else {
            throw invalid_argument("Tip invalid\n");
        }
    }

    void op2() const {
        cout << "Afisez vacciunurile detinute...\n";
        if (vaccinuri.empty()) {
            cout << "Niciun vaccin\n";
        }
        for (auto *vaccin : vaccinuri) {
            vaccin->afiseaza();
        }
    }

    void op3() const {
        cout << "Afisez numele producatorilor...\n";
        for (auto *vaccin : vaccinuri) {
            cout << vaccin->getProducator() << "\n";
        }
    }

    void op4() {
        /// Comanda: idComanda, data, nume, vaccinuri
        cout << "Adaug comanda...\n";   
        string data, nume, vaccin, raspuns;
        vector<string> vaccinuri;
        cout << "Data: ";
        getline(cin, data);
        cout << "Nume: ";
        getline(cin, nume);
        do {
            cout << "Vaccin: ";
            getline(cin, vaccin);
            vaccinuri.push_back(vaccin);
            cout << "Adauga vaccin (da/nu): ";
            getline(cin, raspuns);
            if (raspuns != "da" && raspuns != "nu") {
                throw invalid_argument("Raspuns invaid\n");
            }
        } while (raspuns == "da");
        comenzi.push_back(new Comanda(data, nume, vaccinuri));
    }

    void op5() const {
        cout << "Afisez comenzile...\n";
        if (comenzi.empty()) {
            cout << "Nicio comanda\n";
        }
    }

    void op6() {
        afiseazaOptiuni();
    }

    void op7() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu *m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune:\n";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 7) {
                throw out_of_range("Optiune invalida\n");
            }

            switch(optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
                case 5: m->op5(); break;
                case 6: m->op6(); break;
                case 7: m->op7(); break;
            }
        } while (optiune != 7);
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    }

    delete m;

    return 0;
}
