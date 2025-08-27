/// 2025-08-27-11-30-12-20-BREAK-12-25-12-45-BREAK-12-50-13-25
/// Out of time: 50 + 20 + 35 = 105 (min)

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

////////////////
/// Ierarhie ///
////////////////
/// Pacient: colesterol, dataColesterol, tensiune, dataTensiune, nume, prenume, varsta si adresa
    /// Explicatie: sub 200 mg/dl – optim; între 200-239 mg/dl – normal și peste 240 mg/dl - crescut
    /// Explicatie: Valoarea normală superioară a tensiunii arteriale este de 130-139
/// PacientMatur: fumator și sedentarism
    /// Explicatie: peste 40 de ani
    /// Explicatie: fumator(da/nu)
    /// Explicatie: sedentarism(scazut/mediu/ridicat)
/// PaceintCopil: proteina, antecedente
    /// Explicatie: daca sunt antecedente, retinem numele complet al parintelui/parintilor
    /// Explicatie: proteina c reactiva, daca este sub 0.60 mg/dl => optim
/// Explicatie: Un pacient are risc cardiovascular daca, fie:
    /// 1. Depaseste valoarea normala superioara
    /// 2. Are antecedente in familie
    /// 3. Fumator si grad ridicat sedentarism
/// Eplicatie: Un pacient are risc cardiovascular ridicat daca sunt prezente cel putin doua dintre situatiile de risc cardiovascular

/// Pacient: colesterol, dataColesterol, tensiune, dataTensiune, nume, prenume, varsta si adresa

class Pacient {
    static int id;
    string nume, prenume, dataColesterol, dataTensiune, adresa;
    bool riscCardiovascular, riscCardiovascularRidicat;
    int colesterol, tensiune, idPacient, varsta;
public:
    Pacient(const string &nume, const string &prenume, const int &colesterol, const string &dataColesterol, const int &tensiune, const string &dataTensiune, const int &varsta = 0, const string &adresa = "necunoscuta") {
        this->nume = nume;
        this->prenume = prenume;
        this->colesterol = colesterol;
        this->dataColesterol = dataColesterol;
        this->tensiune = tensiune;
        this->dataTensiune = dataTensiune;
        this->varsta = varsta;
        this->adresa = adresa;
        this->riscCardiovascular = false;
        this->riscCardiovascularRidicat = false;
        idPacient = ++id;
        if (colesterol >= 240 && tensiune >= 140) {
            riscCardiovascular = true;
        }
    }

    virtual ~Pacient() {}

    virtual void afiseaza() const  = 0;

    static int getId() { return id; }
    const string &getNume() const { return nume; }
    const string &getPrenume() const { return prenume; }
    const string &getDataColesterol() const { return dataColesterol; }
    const string &getDataTensiune() const { return dataTensiune; }
    const string& getAdresa() const { return adresa; }
    const bool getRiscCardiovascular() const { return riscCardiovascular; }
    const bool getRiscCardiovascularRidicat() const { return riscCardiovascularRidicat; }
    const int getColesterol() const { return colesterol; }
    const int getTensiune() const { return tensiune; }
    const int getIdPacient() const { return idPacient; }
    const int getVarsta() const { return varsta; }

    void setRiscCardiovascular(const bool &val) { riscCardiovascular = val; }
    void setRiscCardiovascularRidicat(const bool &val) { riscCardiovascularRidicat = val; }
};

int Pacient::id = 0;

/// PacientMatur: fumator și sedentarism

class PacientMatur : public Pacient {
    bool fumator;
    string sedentarism;
public:
    PacientMatur(const string &nume, const string &prenume, const int &colesterol, const string &dataColesterol, const int &tensiune, const string &dataTensiune, const bool &fumator, const string& sedentarism, const int &varsta = 0, const string &adresa = "necunoscuta") : Pacient(nume, prenume, colesterol, dataColesterol, tensiune, dataTensiune, varsta, adresa) {
        this->fumator = fumator;
        this->sedentarism = sedentarism;
        if (colesterol >= 240 && tensiune >= 140) {
            setRiscCardiovascular(true);
            if (fumator && sedentarism == "ridicat") {
                setRiscCardiovascularRidicat(true);
            }
        }
    }

    void afiseaza() const {
        /// Exemplu: Ionescu Paul: Risc cardiovascular – RIDICAT; Colesterol (25.05.2014): 250 mg/dl; TA (04.05.2014): 135; Fumător: da; Sedentarism: ridicat.
        cout << getId() << ". " << getNume() << " " << getPrenume() << ": Risc cardiovascular - ";
        if (getRiscCardiovascular() == true) {
            cout << "DA";
        } else {
            cout << "NU";
        }
        cout << "; Colesterol (" << getDataColesterol() << "): " << getColesterol() << " mg/dl; TA (" << getDataTensiune() << "): " << getTensiune() << "; Fumator: ";
        if (fumator) {
            cout << "DA";
        } else {
            cout << "NU";
        }
        cout << "; Sedentarism: " << sedentarism << ";\n"; 
    }
};

/// PacientAdult
class PacientAdult : public Pacient {
public:
    void afiseaza() const override {
        /// Exemplu: Popescu Ionut: Risc cardiovascular – DA; Colesterol (25.05.2014): 245 mg/dl; TA (04.05.2014): 138.
        cout << getId() << ". " << getNume() << " " << getPrenume() << ": Risc cardiovascular - ";
        if (getRiscCardiovascular()) {
            cout << "DA";
        } else {
            cout << "NU";
        }
        cout << "; Colesterol (" << getDataColesterol() << "): " << getColesterol() << " mg/dl; TA (" << 
        getDataTensiune() << "): " << getTensiune() << ";\n";
    }
};

/// PaceintCopil: proteina, antecedente

class PacientCopil : public Pacient {
    bool antecedente;
    int proteina;
    string dataProteina;
    vector<string> parinti;
public:
    PacientCopil(const string &nume, const string &prenume, const int &colesterol, const string &dataColesterol, const int &tensiune, const string &dataTensiune, const bool &antecedente, const int &proteina, const string &dataProteina, const int &varsta = 0, const string &adresa = "necunoscuta") : Pacient(nume, prenume, colesterol, dataColesterol, tensiune, dataTensiune), antecedente(antecedente), proteina(proteina), dataProteina(dataProteina) {
        if (colesterol >= 240 && tensiune >= 140) {
            setRiscCardiovascular(true);
            if (antecedente) {
                setRiscCardiovascularRidicat(true);
            }
        }
        if (antecedente) {
            string parinte, raspuns;
            cout << "Numele complet al parintelului: ";
            getline(cin, parinte);
            parinti.push_back(parinte);
            cout << "Si celalalt parinte? (da/nu): ";
            getline(cin, raspuns);
            if (raspuns != "da" && raspuns != "nu") {
                throw invalid_argument("Alege intre nu si da!\n");
            }
            if(raspuns == "da") {
                cout << "Numele complet al parintelului: ";
                getline(cin, parinte);
                parinti.push_back(parinte);
            }
        }
    }

    void afiseaza() const {
        /// Exemplu: Caragiale Luca: Risc cardiovascular – NU; Colesterol (25.05.2014): 180 mg/dl; TA (04.05.2014): 131; Proteina C reactivă (17.03.2014): 0.55 mg/dl; Antecedente familie: nu.
        cout << getId() << ". " << getNume() << " " << getPrenume() << ": Risc cardiovascular - ";
        if (getRiscCardiovascular()) {
            cout << "DA";
        } else {
            cout << "NU";
        }
        cout << "; Colesterol (" << getDataColesterol() << "): " << getColesterol() << " mg/dl; TA (" << getDataTensiune() << "): " << getTensiune() << "; Proteina C reactiva (" << dataProteina << "): " << proteina << " mg/dl; Antecedente familie: ";
        if (antecedente) {
            bool first = true;
            cout << "da; Nume parinti: ";
            for (auto &nume : parinti) {
                if (first) {
                    cout << nume;
                } else {
                    cout << ", " << nume;
                }
            }
        } else {
            cout << "nu";
        }
        cout << ";\n"; 
    }
};

class SingletonMenu {
    static SingletonMenu* instanta;
    vector<vector<Pacient*>> pacienti;

    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    ~SingletonMenu() {
        cout << "Eliberez memoria\n";
        for (auto &listaPacienti : pacienti) {
            for (auto &pacient : listaPacienti) {
                delete pacient;
                pacient = nullptr;
            }
        }   
    }

    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Afiseaza informtiile medicale pentru toti pacientii\n";
        cout << "2. Afiseaza informatiile medicale pentru toti pacientii adulti cu factor de risc cardiovascular ridicat\n";
        cout << "3. Afiseaza informatii medicale pentru toti pacientii copii cu factor de risc cardiovascular\n";
        cout << "4. Afiseaza informatii pentru toti pacientii care au un nume de familie dat\n";
        cout << "5. Adauga pacient\n";
        cout << "6. Afiseaza optiunile\n";
        cout << "7. Iesi din meniu\n";
    }


    void op1() const {
        cout << "1. Afiseaza informtiile medicale pentru toti pacientii\n";
    }

    void op2() const {
        cout << "2. Afiseaza informatiile medicale pentru toti pacientii adulti cu factor de risc cardiovascular ridicat\n";
    }
    
    void op3() const {
        cout << "3. Afiseaza informatii medicale pentru toti pacientii copii cu factor de risc cardiovascular\n";
    }

    void op4() const {
        cout << "4. Afiseaza informatii pentru toti pacientii care au un nume de familie dat\n";
    }

    void op5() {
        cout << "5. Adauga pacient\n";
    }

    void op6() const {
        afiseazaOptiuni();
    }
    
    void op7() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

//////////////////////////////////////////////////////////////
/// Bonus (Ceva test pentru a lucra cu vector de vectori): ///
//////////////////////////////////////////////////////////////
// vector<vector<int>> numere;
// vector<int> n1 = {1, 2, 3};
// vector<int> n2 = {4, 5};
// numere.push_back(n1);
// numere.push_back(n2);
// for(auto &n : numere) {
//     for (auto &i : n) {
//         cout << i << " ";
//     }
//     cout << "\n";
// }

int main() {    
    SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune:\n";
            cin >> optiune;

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
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what();
    }

    /// Aici am uitat sa mai scriu `delete m;`

    return 0;
}

// - Barem 2014 mai (nota: 5)
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
//     - [x]  -0.5p - depunctari, de exemplu: memory leaks
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
