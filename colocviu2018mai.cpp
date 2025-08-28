/// 2025-08-28-1230-1330
/// Nota: 5.50

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

////////////////
/// Ierarhie ///
////////////////

/// Companie: denumire, codFiscal, tarif
///     - Codul fiscal este unic
/// CompaniePrecomanda: nume, data, ora, sursa, destinatie
///     - Daca comanda este catre aeroport, tariful pe km este dublu fata de cel standard

/// Clasa abstracta
class Companie {
    /// Campuri de date
    static int id;
    int codFiscal;
    string denumire;
    double tarif;
public:
    /// Constructor
    Companie(const string &denumire, const double &tarif) {
        this->denumire = denumire;
        this->tarif = tarif;
        codFiscal = ++id;
    }

    /// Destructor virtual
    virtual ~Companie() {}

    /// Getter
    static int &getId() { return id; }
    const int &getCodFiscal() const { return codFiscal; }
    const string &getDenumire() const { return denumire; }
    const double &getTarif() const { return tarif; }

    /// Metoda virtuala pura
    virtual void afiseaza() const = 0;
};

/// Preinitializare variabila statica
int Companie::id = 0;

/// Clasa folosita pentru a putea afisa o companie simpla
class CompanieSimpla : public Companie {
public:
    CompanieSimpla(const string &denumire, const double &tarif) : Companie(denumire, tarif) {
        cout << "Companie simpla #" << getId() << " adaugata\n";
    }

    ~CompanieSimpla() {
        cout << "Companie simpla #" << getCodFiscal() << " scoasa\n"; 
    }

    void afiseaza() const override {
        cout << getCodFiscal() << ". " << getDenumire() << " - tarif: " << getTarif() << ";\n";
    }
};

class CompaniePrecomanda : public Companie {
    string nume, data, ora, sursa, destinatie;
public:
    CompaniePrecomanda(const string &denumire, const double &tarif, const string &nume, const string &data, const string &ora, const string &sursa, const string &destinatie) : Companie(denumire, tarif), nume(nume), data(data), ora(ora), sursa(sursa), destinatie(destinatie) {
        cout << "Companie precomanda #" << getId() << " adaugata\n";
    }

    ~CompaniePrecomanda() {
        cout << "Companie precomanda #" << getCodFiscal() << " scoasa\n"; 
    }

    void afiseaza() const override {
        cout << getCodFiscal() << ". " << getDenumire() << " - tarif: " << getTarif() << ", nume: " << nume << ", data: " << data << ", ora: " << ora << ", sursa: " << sursa << ", destinatie: " << destinatie << ";\n";
    }
};

/// Singleton
class SingletonMenu {
    /// Mebrii de acces
    static SingletonMenu* instanta;
    vector<Companie*> companii;

    /// Constructor privat
    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    /// Destructor
    ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
        for (auto &companie : companii) {
            delete companie;
            companie = nullptr;
        }
    }

    /// Metoda statica
    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    /// Nu mai repetam liniile de cod
    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Adauga companie\n";
        cout << "2. Afiseaza companiile\n";
        cout << "3. Afiseaza optiunile\n";
        cout << "4. Iesi din meniu\n";
    }

    void op1() {
        string denumire, raspuns;
        double tarif;
        cout << "Adaug companie...\n";
        cout << "Denumire: ";
        getline(cin, denumire);
        cout << "Tarif: ";
        cin >> tarif;
        cin.get();
        cout << "Precomanda (da/nu): ";
        getline(cin, raspuns);

        /// Exceptia se propaga
        if (raspuns != "da" && raspuns != "nu") {
            throw invalid_argument("Raspuns invalid\n");
        } else if (raspuns == "da") {
            string nume, data, ora, sursa, destinatie;
            cout << "Nume: ";
            getline(cin, nume);
            cout << "Data: ";
            getline(cin, data);
            cout << "Ora: ";
            getline(cin, ora);
            cout << "Sursa: ";
            getline(cin, sursa);
            cout << "Destinatie: ";
            getline(cin, destinatie);
            companii.push_back(new CompaniePrecomanda(denumire, tarif, nume, data, ora, sursa, destinatie));
        } else {
            companii.push_back(new CompanieSimpla(denumire, tarif));
        }
    }

    void op2() const {
        cout << "Afisez companiile...\n";

        /// Verificam daca avem vreo companie
        if (companii.empty()) {
            cout << "Nu exista nicio companie\n";
        }

        /// Afisam fiecare companie
        for (auto &companie : companii) {
            companie->afiseaza();
        }
    }

    void op3() const {
        afiseazaOptiuni();
    }

    void op4() const {
        cout << "Ies din meniu...\n";
    }
};

/// Preinitializam variabila statica
SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            /// Verificam ca optiunea sa fie in interval, altfel aruncam o exceptie de tip out_of_range
            if (optiune < 1 || optiune > 4) {
                throw out_of_range("Optiune invalida\n");
            }

            switch(optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
            }
        } while (optiune != 4);
        /// Mai jos exceptia este prinsa si tratata
    } catch (const out_of_range &e) {
        cout << "Out of range exception: " << e.what(); 
    } catch (const invalid_argument &e) {
        cout << "Invalid argument exception: " << e.what();
    }

    /// Evitam memory leaks, apeland destructorul ~SingletonMenu() stergem fiecare compaie alocata dinamic
    delete m;

    return 0;
}

// - Barem 2018 mai (nota: 5.50)
//     - [x]  1p - oficiu (sursa compileaza)
//     - [x]  2p - ierarhie (identificarea claselor + atributelor)
//     - [x]  0.25p - const (pentru atribute, functii sau argumente la functii)
//     - [x]  0.25p - static (functii si atribute statice)
//     - [x]  0.25p - destructor virtual (folosit in toate locurile in care este necesar)
//     - [x]  0.25p - mostenire (reutilizare de cod, ex: apeleaza o functie a clasei de baza in momentul rescrierii ei in clasa derivata)
//     - [x]  0.25p - abstract (exista o clasa abstracta)
//     - [x]  0.25p - STL containers (vector, list, map, etc.)
//     - [ ]  0.25p - STL alte elemente (sort, transform, swap)
//     - [x]  0.25p - exceptia se propaga (nu poate fi tratata in acelasi loc de locul unde a fost aruncata)
//     - [x]  0.25p - exceptia este prinsa (tratarea cu sens a unei exceptii aruncate)
//     - [ ]  0.25p - RTTI (dynamic_cast, type_info)
//     - [x]  0.25p - clasa Singleton
//     - [ ]  0.25p - clasa Factory
//     - [x]  0.25p - ID comanda incrementat automat in constructor
//     - [ ]  0.5p - bonus pentru folosirea conceptelor POO care nu sunt in barem, precum template
//     - [ ]  -0.5p - depunctari, de exemplu: memory leaks
//     - [ ]  0.25p - specific 2025-06-02, existenta unei functii ce calculeaza energia necesara pentru un produs (functie virtuala, rescrisa corespunzator in derivate)
//     - [ ]  0.25p - specific 2025-06-02, existenta unei functii care calculeaza energia necesara pentru o comanda (exista clasa Comanda)
//     - [ ]  0.25p - specific 2025-06-02, validarea tipului unui desert (in constructor se valideaza ca tipul este doar cel prestabilit, punctat si enum)
//     - [ ]  1p - specific 2025-06-02, identificare comportament de baza al clasei angajat (minim, functii care intorc costul de baza pentru preparare, livrare, comandare, recuperare; alte functii precum cele care verifica daca o actiune poate fi executata)
//     - [ ]  0.75p - specific 2025-06-02, identificare comportament clase derivate ale clasei angajat (rescrie functiile in clasele derivate ca sa fie evidentiat comportamentul specific al derivatelor, ex: rescrie functia de recuperare in clasa Bucatar)
//     - [ ]  0.5p - specific 2025-06-02, asamblare comportament Angajat (functii care imbina comportament de baza + verificari necesare ca sa creeze clasa Angajat)
//     - [ ]  0.5p - specific 2025-06-02, existenta unui meniu cu produse predefinite
//     - [ ]  0.5p - specific 2025-06-02, afisarea numarului de angajati de fiecare tip (doar daca e folosit dynamic_cast sau type_info)
//     - [ ]  1p - specific 2025-06-02, implementare ciclu dat ca exemplu
//     - [ ]  1p - specific 2025-06-02, prioritizare comanda (pot introduce un ID al unei comenzi care va prioritiza o anumita comanda a fi preparata/livrata prima)
//     - [ ]  0.5p - specific 2025-06-02, optimizarea ciclului (aloca actiunile specifice catre angajatii cu o anumita functie)
//     - [ ]  1p - specific 2025-06-02, strategia de alegere a comenzilor care sunt preparate
