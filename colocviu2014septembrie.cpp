/// 2025-08-21-09-45-11-15

/// NOTA: 5.5

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

/// Angajat: nume, prenume, tipContract(permanent/in plata cu ora), dataIntrareInVigoareContract

/// Clasas abstracta
class Angajat {
private:
protected:
    static int idAngajatGenerator;
    int idAngajat;
    string nume, prenume, tipContract, dataIntrareInVigoareContract;
public:
    Angajat(const string &nume, const string &prenume, const string &tipContract, const string &dataIntrareInVigoareContract) {
        this->nume = nume;
        this->prenume = prenume;
        this->tipContract = tipContract;
        this->dataIntrareInVigoareContract = dataIntrareInVigoareContract;
        idAngajat = ++idAngajatGenerator;
    }

    virtual ~Angajat() {
        cout << "Angajat #" << idAngajat << " iesit din evidenta\n";
    }

    /// Getter static, constant, implicit inline
    static int getIdAngajatGenerator() { return idAngajatGenerator; }

    /// Getter static care returneaza o constanta, idAngajat
    const int getIdAngajat() const { return idAngajat; }

    /// Functie virtuala pura
    virtual void afiseazaAngajat() const = 0;
};

int Angajat::idAngajatGenerator = 0;

/// TesaPermanent : Angajat, weekend

class TesaPermanent : public Angajat {
private:
    string tipActivitate;
    int weekend;
protected:
public:
    TesaPermanent(const string &nume, const string &prenume, const string &tipContract, const string &dataIntrareInVigoareContract, const string &tipActivitate, const int &weekend) : Angajat(nume, prenume, tipContract, dataIntrareInVigoareContract) {
        this->tipActivitate = tipActivitate;
        this->weekend = weekend;
        cout << "Angajat TESA permanent" << getIdAngajatGenerator() << " intrat in evidenta\n";
    }

    ~TesaPermanent() {
        cout << "Angajat TESA permanent " << getIdAngajat() << " iesit din evidenta\n";
    }

    void afiseazaAngajat() const {
        cout << getIdAngajat() << ". " << nume << " " << prenume << ", " << tipContract << ", " << dataIntrareInVigoareContract << ", " << tipActivitate << ", weekend " << weekend << "\n";
    }
};

/// LucrativPermanent : Angajat, minori

class LucrativPermanent : public Angajat {
private:
    string tipActivitate;
    int minori;
protected:
public:
    LucrativPermanent(const string &nume, const string &prenume, const string &tipContract, const string &dataIntrareInVigoareContract, const string &tipActivitate, const int &minori) : Angajat(nume, prenume, tipContract, dataIntrareInVigoareContract) {
        this->tipActivitate = tipActivitate;
        this->minori = minori;
        cout << "Angajat lucrativ permanent" << getIdAngajatGenerator() << " intrat in evidenta\n";
    }

    ~LucrativPermanent() {
        cout << "Angajat lucrativ permanent " << getIdAngajat() << " iesit din evidenta\n";
    }

    void afiseazaAngajat() const {
        cout << getIdAngajat() << ". " << nume << " " << prenume << ", " << tipContract << ", " << dataIntrareInVigoareContract << ", " << tipActivitate << ", minori " << minori << "\n";
    }
};

/// AngajatCuOra : Angajat, dataTerminareContract

class AngajatCuOra : public Angajat {
private:
    const string dataTerminareContract;
protected:
public:
    AngajatCuOra(const string &nume, const string &prenume, const string &tipContract, const string &dataIntrareInVigoareContract, const string &dataTerminareContract) : Angajat(nume, prenume, tipContract, dataIntrareInVigoareContract), dataTerminareContract(dataTerminareContract) {
        cout << "Angajat cu ora " << getIdAngajatGenerator() << " intrat in evidenta\n";
    }

    ~AngajatCuOra() {
        cout << "Angajat cu ora " << getIdAngajat() << " iesit din evidenta\n";
    }

    void afiseazaAngajat() const {
        cout << getIdAngajat() << ". " << nume << " " << prenume << ", " << tipContract << ", " << dataIntrareInVigoareContract << "-" << dataTerminareContract << "\n";
    }
};

class SingletonMenu {
private:
    static SingletonMenu* instanta;
    vector<Angajat*> angajati;

    SingletonMenu() {
        afiseazaOptiuni();
    }
protected:
public:
    /// AFTER: destructor
    ~SingletonMenu() {
        for (auto *angajat : angajati) {
            delete angajat;
            angajat = nullptr;
        }

        /// AFTER: os delete it
        // delete instanta;
        // instanta = nullptr;

        cout << "Meniu distrus. Memoria a fost eliberata\n";
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Afiseaza toti angajatii\n";
        cout << "2. Afiseaza angajatii lucrativi permanenti care au copii minori in ingrijire\n";
        cout << "3. Afiseaza angajatii care is fac rezervare la munte in al doilea weekend din decembrie\n";
        cout << "4. Afiseaza angajatii in regim de plata cu ora, care au contract pana cel putin in martie 2015\n";
        cout << "5. Adauga angajat\n";
        cout << "6. Reafiseaza optiunile\n";
        cout << "7. Iesi din meniu\n";
    }

    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    void op1() {
        cout << "Ai ales: Afiseaza toti angajatii\n";
    }

    void op2() {
        cout << "Ai ales: Afiseaza angajatii lucrativi permanenti care au copii minori in ingrijire\n";
    }

    void op3() {
        cout << "Ai ales: Afiseaza angajatii care is fac rezervare la munte in al doilea weekend din decembrie\n";
    }

    void op4() {
        cout << "Ai ales: Afiseaza angajatii in regim de plata cu ora, care au contract pana cel putin in martie 2015\n";
    }

    void op5() {
        /// Angajat: nume, prenume, tipContract, dataIntrareInVigoareContract
        string nume, prenume, tipContract, dataIntrareInVigoareContract;
        cout << "Ai ales: Adauga angajat\n";
        cout << "Nume: "; getline(cin, nume);
        cout << "Prenume: "; getline(cin, prenume);
        cout << "Tip contract(permanent/in plata cu ora): "; getline(cin, tipContract);
        cout << "Data intrare in vigoare contract: "; getline(cin, dataIntrareInVigoareContract);

        if (tipContract != "contract permanent" && tipContract != "in plata cu ora") {
            throw invalid_argument("Tip contract invalid. Incearca contract permanent sau in plata cu ora!\n");
        } else if (tipContract == "contract permanent") {
            string tipActivitate;
            cout << "Tip activitate(lucrativ/tesa): "; getline(cin, tipActivitate);
            if (tipActivitate != "lucrativ" && tipActivitate != "TESA") {
                throw invalid_argument("Tip activitate invalid. Incearca lucrativ sau TESA!\n");
            } else if (tipActivitate == "TESA") {
                /// TesaPermanent : Angajat, tipActivitate, weekend
                int weekend;
                cout << "Weekend: "; cin >> weekend; cin.get();
                angajati.push_back(new TesaPermanent(nume, prenume, tipContract, dataIntrareInVigoareContract, tipActivitate, weekend));
            } else if (tipActivitate == "lucrativ") {
                /// LucrativPermanent : Angajat, tipActivitate, minori
                int minori;
                cout << "Minori: "; cin >> minori; cin.get();
                angajati.push_back(new LucrativPermanent(nume, prenume, tipContract, dataIntrareInVigoareContract, tipActivitate, minori));
            }
        } else { /// tipContract == "in plata cu ora"
            /// AngajatCuOra : Angajat, dataTerminareContract
            string dataTerminareContract;
            cout << "Data terminare contract: "; getline(cin, dataTerminareContract);
            angajati.push_back(new AngajatCuOra(nume, prenume, tipContract, dataIntrareInVigoareContract, dataTerminareContract));
        }
    }

    void op6() {
        cout << "Ai ales: Reafiseaza optiunile\n";
    }

    void op7() {
        cout << "Ai ales: Iesi din meniu\n";
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

            if (optiune < 1 || optiune > 7) {
                throw out_of_range("Optiune invalida. Alege intre in intervalul [1,7]!\n");
            }

            switch (optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
                case 5: m->op5(); break;
                case 6: m->op6(); break;
                case 7: m->op7(); break;
            }
        } while (optiune != 7);
    } catch (out_of_range &e) {
        cout << "Out of range: " << e.what();
    }

    /// Apelam destructorul, ~SingletonMenu(), care va elibera memoria
    delete m;

    return 0;
}

/// Q: De ce nu se apeleaza destructorul ~SingletonMenu?
/// A: Nu este definit :) In plus, nu am sters pointerul la finalul functiei main, acel `delete m;`

// - Barem 2014 septembrie
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
