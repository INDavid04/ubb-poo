/// 2025-08-23-09-30-11-00

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

////////////////
/// Ierarhie ///
////////////////

/// Curs: cod("S/P/I" + idGenerator), denumire, pret, durata
/// Participant: nume
/// Student: Participant, universitate, anulDeStudiu
/// Somer: Participant, ultimul loc de munca avut
/// Angajat: Participant, contract(perioada determinata/perioada nedeterminata)

///////////
/// Cod ///
///////////

/// Curs: cod("S/P/I" + idGenerator), denumire, pret, durata

class Curs {
    static int idGenerator;
    int cod;
    string tip, denumire;
    double pret;
    int durata;
public: 
    Curs(const string &tip, const string &denumire, const double &pret, const int &durata) {
        this->cod = ++idGenerator;
        this->denumire = denumire;
        this->pret = pret;
        this->durata = durata;
    }

    void afiseaza() const {
        cout << "\t" << tip << "_" << cod << ": " << denumire << ", " << pret << " lei, " << durata << " minute\n";
    }
};

int Curs::idGenerator = 0;

/// Participant: nume

class Participant {
    string nume;
    vector<Curs*> cursuri;
public:
    Participant(const string &nume) {
        this->nume = nume;
        this->cursuri = cursuri;
        cout << "Participant intrat organizatia X\n";
    }

    virtual ~Participant() {
        for (auto &curs : cursuri) {
            delete curs;
        }
        cout << "Participant iesit din organizatia X\n";
    }

    virtual void afiseaza() const = 0;

    void afiseazaCursuri() const {
        if (cursuri.empty()) {
            cout << "Nu este inscris la niciun curs\n";
        } else {
            for (auto &curs : cursuri) {
                curs->afiseaza();
            }
        }
    }

    const string &getNume() const { return nume; }

    void adaugaCurs(const string &tip, const string &denumire, const double &pret, const int &durata) {
        cursuri.push_back(new Curs(tip, denumire, pret, durata));
    }
};

/// Student: Participant, universitate, anulDeStudiu

class Student : public Participant {
    string universitate;
    int anulDeStudiu;
public:
    Student(const string &nume, const string& universitate, const int &anulDeStudiu) : Participant(nume), universitate(universitate), anulDeStudiu(anulDeStudiu) {
        cout << "Student intrat in organizatia X";
    }

    virtual ~Student() {
        cout << "Student iesit din organizatia X\n";
    }

    virtual void afiseaza() const override {
        cout << "Nume: " << getNume() << ", universitate: " << universitate << ", anul de studiu: " << anulDeStudiu << "\n";
        afiseazaCursuri();
    }
};

/// Somer: Participant, ultimul loc de munca avut

class Somer : public Participant {
    string ultimulLocDeMunca;
public:
    Somer(const string &nume, const string& ultimulLocDeMunca) : Participant(nume), ultimulLocDeMunca(ultimulLocDeMunca) {
        cout << "Somer intrat in organizatia X\n";
    }

    virtual ~Somer() {
        cout << "Somer iesit din organizatia X\n";
    }

    virtual void afiseaza() const override {
        cout << "Nume: " << getNume() << ", ultimul loc de munca: " << ultimulLocDeMunca << "\n";
        afiseazaCursuri();
    }
};

/// Angajat: Participant, contract(perioada determinata/perioada nedeterminata)

class Angajat : public Participant {
    string contract;
public:
    Angajat(const string &nume, const string& contract) : Participant(nume), contract(contract) {
        cout << "Angajat intrat in organizatia X\n";
    }

    virtual ~Angajat() {
        cout << "Angajat iesit din organizatia X\n";
    }

    virtual void afiseaza() const override {
        cout << "Nume: " << getNume() << ", contract pe o perioada: " << contract << "\n";
        afiseazaCursuri();
    }
};

/// OrganizatiaX: participanti

class OrganizatiaX {
    static OrganizatiaX* instanta;
    vector<Participant*> participanti;

    OrganizatiaX() {
        afiseazaOptiuni();
    }

public:
    ~OrganizatiaX() {
        for (auto &participant : participanti) {
            delete participant;
        }
    }

    static OrganizatiaX* getInstanta() {
        if (!instanta) {
            instanta = new OrganizatiaX;
        }
        return instanta;
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Afiseaza toti cursantii\n";
        cout << "2. Afiseaza toate cursurile care se termina in maxim doua luni alese de studentii de anii 2 si 3\n";
        cout << "3. Afiseaza toti angajatii pe perioada determinata si somerii, grupati pe cursuri\n";
        cout << "4. Afiseaza profitul organizatiei pana in prezent\n";
        cout << "5. Adauga cursant\n";
        cout << "6. Afiseaza optiuni\n";
        cout << "7. Iesi din meniu\n";
    }

    void op1() const {
        cout << "1. Afiseaza toti cursantii\n";
        if (participanti.empty()) {
            cout << "Niciun participant\n";
        } else {
            for (auto &participant : participanti) {
                participant->afiseaza();
            }
        }
    }

    void op2() const {
        cout << "2. Afiseaza toate cursurile care se termina in maxim doua luni alese de studentii de anii 2 si 3\n";
    }

    void op3() const {
        cout << "3. Afiseaza toti angajatii pe perioada determinata si somerii, grupati pe cursuri\n";
    }

    void op4() const {
        cout << "4. Afiseaza profitul organizatiei pana in prezent\n";
    }

    void oferaPosibilitateaDeAdaugareCurs(Participant &p) {
        string adauga;
        do {
            cout << "Adauga curs (da/nu): ";
            getline(cin, adauga);
            
            if (adauga != "da" && adauga != "nu") {
                throw invalid_argument("Alege intre nu si da!");
            }

            if (adauga == "da") {
/// Curs: cod("S/P/I" + idGenerator), denumire, pret, durata
                string tip, denumire;
                double pret;
                int durata;

                cout << "Categorie(S/P/I): ";
                getline(cin, tip);

                if (tip != "S" && tip != "P" && tip != "I") {
                    throw invalid_argument("Alege intre S/P/I\n");
                }

                cout << "Denumire: ";
                getline(cin, denumire);
                cout << "Pret (in lei): ";
                cin >> pret;
                cin.get();
                cout << "Durata (in minute): ";
                cin >> durata;
                cin.get();

                oferaPosibilitateaDeAdaugareCurs(p);
            }
        } while (adauga == "da");
    }

    void op5() {
        string nume, tip;
        cout << "5. Adauga cursant\n";
        cout << "Nume: ";
        getline(cin, nume);

        cout << "Tip (student/somer/angajat): ";
        getline(cin, tip);

        if (tip == "stuent") {
            string universitate;
            int anulDeStudiu;
            cout << "Universitate: ";
            getline(cin, universitate);
            cout << "Anul de studiu: ";
            cin >> anulDeStudiu;
            Participant *p = new Student(nume, universitate, anulDeStudiu);
            // p->adaugaCurs();
/// Student: Participant, universitate, anulDeStudiu
        } else if (tip == "somer") {
/// Somer: Participant, ultimul loc de munca avut
        } else if (tip == "angajat") {
/// Angajat: Participant, contract(perioada determinata/perioada nedeterminata)
        } else {
            throw invalid_argument("Alege intre student/somer/angajat\n");
        }
    }

    void op6() const {
        afiseazaOptiuni();
    }
    
    void op7() const {
        cout << "7. Iesi din meniu\n";
    }
};

OrganizatiaX* OrganizatiaX::instanta = nullptr;

/// Studentii platesc 50%

/// Somerii beneficiaza de gratuitate la cursurile de initiere

/// Somerii au reducere 50% la cursurile de claificare si perfectionare

/// Angajatii platesc cursurile integral

/// La cursurile de perfectionare nu pot participa studentii sau persoanele (angajati sau someri) care au o vechime in munca mai mica de 3 ani

int main() {
    OrganizatiaX* m = OrganizatiaX::getInstanta();

    int optiune;
    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 7) {
                throw out_of_range("Optiunei invalida\n");
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

// - Barem 2018 iunie (nota: 5.50)
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
