/// 2025-08-14-11-57-13-30

#include <iostream>
#include <stdexcept> /// exception, out_of_range, invalid_argument
#include <vector>
#include <list>
#include <string>

using namespace std;

////////////////
/// Ierarhie ///
////////////////

/// Malware: double ratingImpact, string data, string nume, string metodaDeInfectare = unkwnown by default, vector<string> registriiModificati
    /// Rootkit: list<string> listaImporturi, list<string> listaStringuriSemneficative
    /// Keylogger: list<string> listaFunctiiFolosite, list<string> listaTasteSpecialeDefinite
        /// KernelKeylogger: Rootkit, Keylogger, bool ascundeFisiere, bool ascundeRegistrii
    /// Ransomware: int ratingCriptare(1-10), double ratingObfuscare
/// Computer: int idComputer, list<Malware*> listaMalware, double ratingFinal = suma ratingImpact a fiecarui Malware

class Malware {
private:
protected:
    double ratingImpact;
    string data, nume, metodaDeInfectare;
    vector<string> registriiModificati;
public:
    Malware(const double ratingImpact, const string &data, const string &nume, const vector<string> &registriiModificati, const string &metodaDeInfectare = "unknown") {
        this->ratingImpact = ratingImpact;
        this->data = data;
        this->nume = nume;
        this->registriiModificati = registriiModificati;
        this->metodaDeInfectare = metodaDeInfectare;
    }

    virtual ~Malware() {
        cout << "Malware distrus";
    }

    virtual void afiseaza() const = 0; /// afiseaza() e functie virtuala pura; Malware e clasa abstracta
};

class Rootkit : public virtual Malware {
private:
protected:
    list<string> listaImporturi, listaStringuriSemneficative;
public:
    Rootkit(const double ratingImpact, const string &data, const string &nume, const vector<string> &registriiModificati, const list<string> &listaImporturi, const list<string> &listaStringuriSemneficative, const string &metodaDeInfectare = "unknown") : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare), listaImporturi(listaImporturi), listaStringuriSemneficative(listaStringuriSemneficative) {}

    virtual void afiseaza() const override {
        bool ePrimulTermen = true;
        cout << "\trating impact: " << ratingImpact << "; data: " << data << "; nume: " << nume << "; registrii modificati: ";
        for (auto registru : registriiModificati) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << registru;
            } else {
                cout << ", " << registru;
            }
        }
        cout << "; lista importuri: ";
        ePrimulTermen = true;
        for (auto import : listaImporturi) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << import;
            } else {
                cout << ", " << import;
            }
        }
        cout << "; lista stringuri semnificative: ";
        ePrimulTermen = true;
        for (auto stringSemnificativ : listaStringuriSemneficative) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << stringSemnificativ;
            } else {
                cout << ", " << stringSemnificativ;
            }
        }
        cout << "; metoda de infectare: " << metodaDeInfectare << "\n";
    }
};

class Keylogger : public virtual Malware {
private:
protected:
    list<string> listaFunctiiFolosite, listaTasteSpecialeDefinite;
public:
    Keylogger(const double ratingImpact, const string &data, const string &nume, const vector<string> &registriiModificati, const list<string> &listaFunctiiFolosite, const list<string> &listaTasteSpecialeDefinite, const string &metodaDeInfectare = "unknown") : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare), listaFunctiiFolosite(listaFunctiiFolosite), listaTasteSpecialeDefinite(listaTasteSpecialeDefinite) {}

    virtual void afiseaza() const override {
        /// ratingImpact, data, nume, registriiModificati, listaFunctiiFolosite, listaTasteSpecialeDefinite, metodaDeInfectare
        bool ePrimulTermen = true;
        cout << "\trating impact: " << ratingImpact << "; data: " << data << "; nume: " << nume << "; registrii modificati: ";
        for (auto registru : registriiModificati) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << registru;
            } else {
                cout << ", " << registru;
            }
        }
        cout << "; lista functii folosite: ";
        ePrimulTermen = true;
        for (auto functie : listaFunctiiFolosite) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << functie;
            } else {
                cout << ", " << functie;
            }
        }
        cout << "; lista taste speciale definite: ";
        ePrimulTermen = true;
        for (auto tasta : listaTasteSpecialeDefinite) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << tasta;
            } else {
                cout << ", " << tasta;
            }
        }
        cout << "; metoda de infectare: " << metodaDeInfectare << "\n";
    }
};

class KernelKeylogger : public Rootkit, public Keylogger {
private:
    bool ascundeFisiere, ascundeRegistrii;
protected:
public:
    KernelKeylogger(const double ratingImpact, const string &data, const string &nume, const vector<string> &registriiModificati, const list<string> &listaImporturi, const list<string> &listaStringuriSemneficative, const list<string> &listaFunctiiFolosite, const list<string> &listaTasteSpecialeDefinite, const bool ascundeFisiere, const bool ascundeRegistrii, const string &metodaDeInfectare = "unknown") : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare), Rootkit(ratingImpact, data, nume, registriiModificati, listaImporturi, listaStringuriSemneficative, metodaDeInfectare), Keylogger(ratingImpact, data, nume, registriiModificati, listaFunctiiFolosite, listaTasteSpecialeDefinite, metodaDeInfectare), ascundeFisiere(ascundeFisiere), ascundeRegistrii(ascundeRegistrii) {}

    virtual void afiseaza() const override {
        
        bool ePrimulTermen = true;
        cout << "\trating impact: " << ratingImpact << "; data: " << data << "; nume: " << nume << "; registrii modificati: ";
        for (auto registru : registriiModificati) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << registru;
            } else {
                cout << ", " << registru;
            }
        }
        cout << "; lista importuri: ";
        ePrimulTermen = true;
        for (auto import : listaImporturi) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << import;
            } else {
                cout << ", " << import;
            }
        }
        cout << "; lista stringuri semnificative: ";
        ePrimulTermen = true;
        for (auto stringSemnificativ : listaStringuriSemneficative) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << stringSemnificativ;
            } else {
                cout << ", " << stringSemnificativ;
            }
        }
        cout << "; lista functii folosite: ";
        ePrimulTermen = true;
        for (auto functie : listaFunctiiFolosite) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << functie;
            } else {
                cout << ", " << functie;
            }
        }
        cout << "; lista taste speciale definite: ";
        ePrimulTermen = true;
        for (auto tasta : listaTasteSpecialeDefinite) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << tasta;
            } else {
                cout << ", " << tasta;
            }
        }
        cout << (ascundeFisiere == true) ? "; ascunde fisiere" : "; nu ascunde fisiere";
        cout << (ascundeRegistrii == true) ? "; ascunde registrii" : "; nu ascunde registrii";
        cout << "; metoda de infectare: " << metodaDeInfectare << "\n";
        /// ratingImpact, data, nume, registriiModificati, listaImporturi, listaStringuriSemnificative, listaFunctiiFolosite, listaTasteSpecialeDefinite, ascundeFisiere, ascundeRegistrii, metodaDeInfectare
    }
};

class Ransomware : public Malware {
private:
    int ratingCriptare; /// 1-10
    double ratingObfuscare;
protected:
public:
    Ransomware(const double ratingImpact, const string &data, const string &nume, const vector<string> &registriiModificati, const int ratingCriptare, const double ratingObfuscare, const string &metodaDeInfectare = "unkwnown") : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare), ratingCriptare(ratingCriptare), ratingObfuscare(ratingObfuscare) {}

    virtual void afiseaza() const override {
        /// ratingImpact, data, nume, registriiModificati, ratingCriptare, ratingObfuscare, metodaDeInfectare
        bool ePrimulTermen = true;
        cout << "\trating impact: " << ratingImpact << "; data: " << data << "; nume: " << nume << "; registrii modificati: ";
        for (auto registru : registriiModificati) {
            if (ePrimulTermen) {
                ePrimulTermen = false;
                cout << registru;
            } else {
                cout << ", " << registru;
            }
        }
        cout << "; rating criptare: " << ratingCriptare << "; rating obfuscare: " << ratingObfuscare << "; metoda de infectare: " << metodaDeInfectare << "\n";
    }
};

class Computer {
private:
    static int idGenerator;
    int idComputer;
    list<Malware*> listaMalware;
    double ratingFinal;
protected:
public:
    Computer() : idComputer(++idGenerator) {}

    const int getIdComputer() const {
        return idComputer;
    }

    void adaugaMalware() {
        string nume;
        cout << "Nume (rootkit/keylogger/kernelkeylogger/ransomware): "; getline(cin, nume);

        if (nume != "rootkit" && nume != "keylogger" && nume != "kernelkeylogger" && nume != "ransomware") {
            throw invalid_argument("Nume malware gresit\n");
        } else {
            double ratingImpact;
            string data, metodaDeInfectare, raspuns;
            vector <string> registriiModificati;
            cout << "Rating impact: "; cin >> ratingImpact; cin.get();
            cout << "Data: "; getline(cin, data);
            cout << "Metoda de infectare: "; getline(cin, metodaDeInfectare);
            do {
                string registruModificat;
                cout << "Registru modificat: "; getline(cin, registruModificat);
                registriiModificati.push_back(registruModificat);
                cout << "Mai adaugi inca un registru? (da/nu): "; getline(cin, raspuns);
            } while (raspuns == "da");

            if (nume == "rootkit") {
                list<string> listaImporturi, listaStringuriSemneficative;
                string import, stringSemnificativ;
                do {
                    cout << "Import: "; getline(cin, import);
                    listaImporturi.push_back(import);
                    cout << "Mai adaugi inca unul? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                do {
                    cout << "String semnificativ: "; getline(cin, stringSemnificativ);
                    listaStringuriSemneficative.push_back(stringSemnificativ);
                    cout << "Mai adaugi inca unul? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                listaMalware.push_back(new Rootkit(ratingImpact, data, nume, registriiModificati, listaImporturi, listaStringuriSemneficative, metodaDeInfectare));
            } else if (nume == "keylogger") {
                list<string> listaFunctiiFolosite, listaTasteSpecialeDefinite;
                string functie, tasta;
                do {
                    cout << "Functie folosita: "; getline(cin, functie);
                    listaFunctiiFolosite.push_back(functie);
                    cout << "Mai adaugi inca una? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                do {
                    cout << "Tasta speciala definita: "; getline(cin, tasta);
                    listaTasteSpecialeDefinite.push_back(tasta);
                    cout << "Mai adaugi inca una? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                listaMalware.push_back(new Keylogger(ratingImpact, data, nume, registriiModificati, listaFunctiiFolosite, listaTasteSpecialeDefinite, metodaDeInfectare));
            } else if (nume == "kernelkeylogger") {
                list<string> listaImporturi, listaStringuriSemneficative, listaFunctiiFolosite, listaTasteSpecialeDefinite;
                string import, stringSemnificativ, functie, tasta;
                bool ascundeFisiere, ascundeRegistrii;
                do {
                    cout << "Import: "; getline(cin, import);
                    listaImporturi.push_back(import);
                    cout << "Mai adaugi inca unul? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                do {
                    cout << "String semnificativ: "; getline(cin, stringSemnificativ);
                    listaStringuriSemneficative.push_back(stringSemnificativ);
                    cout << "Mai adaugi inca unul? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                do {
                    cout << "Functie folosita: "; getline(cin, functie);
                    listaFunctiiFolosite.push_back(functie);
                    cout << "Mai adaugi inca una? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                do {
                    cout << "Tasta speciala definita: "; getline(cin, tasta);
                    listaTasteSpecialeDefinite.push_back(tasta);
                    cout << "Mai adaugi inca una? (da/nu): "; getline(cin, raspuns);
                } while (raspuns == "da");
                cout << "Ascunde fisiere (da/nu): "; cin >> raspuns; cin.get();
                ascundeFisiere = (raspuns == "da") ? true : false;
                cout << "Ascunde registrii (da/nu): "; cin >> raspuns; cin.get();
                ascundeRegistrii = (raspuns == "da") ? true : false;
                listaMalware.push_back(new KernelKeylogger(ratingImpact, data, nume, registriiModificati, listaImporturi, listaStringuriSemneficative, listaFunctiiFolosite, listaTasteSpecialeDefinite, ascundeFisiere, ascundeRegistrii, metodaDeInfectare));
            } else { /// ransomware
                int ratingCriptare;
                double ratingObfuscare;
                cout << "Rating criptare (1-10): "; cin >> ratingCriptare; cin.get();
                cout << "Rating obfuscare (1-100): "; cin >> ratingObfuscare; cin.get();
                listaMalware.push_back(new Ransomware(ratingImpact, data, nume, registriiModificati, ratingCriptare, ratingObfuscare, metodaDeInfectare));
            }
        }
    }

    void afiseaza() const {
        int cnt = 1;
        for (auto *malware : listaMalware) {
            malware->afiseaza();
        }
    }
};

int Computer::idGenerator = 0;

class SingletonMenu {
private:
    static SingletonMenu* instanta;
    vector<Computer*> calculatoare;

    /// Constructor privat
    SingletonMenu() {
        cout << "Optiuni:\n";
        cout << "1. Adauga calculatoare\n";
        cout << "2. Adauga tipuri de malware\n";
        cout << "3. Afiseaza calculatoare\n";
        cout << "4. Iesi\n";
    }
protected:
public:
    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu();
        }
        return instanta;
    }

    void op1() {
        int n;
        cout << "Adaug calculatoare...\n";
        cout << "Numar calculatoare de adaugat: "; cin >> n; cin.get();
        for (int i = 0; i < n; i++) {
            calculatoare.push_back(new Computer());
        }
    }

    void op2() {
        int m;
        cout << "Adaug tipuri de malware...\n";
        for (auto *calculator : calculatoare) {
            cout << "Pentru calculatorul #" << calculator->getIdComputer() << " numarul de tipuri de malware de adaugat: "; cin >> m; cin.get();
            for (int i = 1; i <= m; i++) {
                cout << "Malware #" << i << "\n";
                calculator->adaugaMalware();
            }
        }
    }

    void op3() const {
        cout << "Afisez calculatoare...\n";
        for (auto *calculator : calculatoare) {
            cout << "Calculatorul #" << calculator->getIdComputer() << ":\n";
            calculator->afiseaza();
        }
    }

    void op4() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu* m;
    m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: "; cin >> optiune; cin.get();
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
        cout << "Out of range exception: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid arugment exception: " << e.what();
    } catch (const exception &e) {
        cout << "Exception: " << e.what();
    }

    return 0;
}

/// Q: De ce se pune &e in loc de e in cazul catch(const out_of_range &e) {...}?
/// A: Mai sigur si mai eficient. Cu & avem referinta constanta la obiectul aruncat, fara copie si cu pastrarea completa a tipului dinamic.

/// Q: Care-i diferenta intre a pune const inainte, dupa, precum si inaintea si dupa o functie (const int f() {...} VS int f() const {} VS const int f() const {...})?
/// A: Const inainte (const int f() {...}) adica returnam o constanta pe care nu mai putem modifica. Const dupa (int f() const {...}) adica functia nu poate modifica membrii obiectului, de exemplu daca am class {int x; public: int f() const { x = 5; }} mi-ar da eroare intrucat nu pot modifica x. Const inainte si dupa e combinatia celor doua adica returnam ceva constant si nu putem modifica membrii clasei in care regasim functia.

// - Barem 2021 mai (nota: 5.5)
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
