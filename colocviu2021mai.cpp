/// 2025-08-14-11-57-TODO

#include <iostream>
#include <stdexcept> /// exception, out_of_range, invalid_argument
#include <vector>
#include <list>
#include <string>

using namespace std;

/// Malware: double ratingImpact, string data, string nume, string metodaDeInfectare = unkwnown by default, vector<string> registriiModificati
    /// Rootkit: list<string> listaImporturi, list<string> listaStringuriSemneficative
    /// Keylogger: list<string> listaFunctiiFolosite, list<string> listaTasteSpecialeDefinite
        /// KernelKeylogger: Rootkit, Keylogger, bool ascundeFisiere, bool ascundeRegistrii
    /// Ransomware: int ratingCriptare(1-10), double ratingObfuscare
/// Computer: int idComputer, list<Malware*> listaMalware, double ratingFinal = suma ratingImpact a fiecarui Malware

class Malware {
private:
    double ratingImpact;
    string data, nume, metodaDeInfectare;
    vector<string> registriiModificati;
protected:
public:
    Malware(const double ratingImpact, const string data, const string nume, const vector<string> &registriiModificati, const string metodaDeInfectare = "unknown") {
        this->ratingImpact = ratingImpact;
        this->data = data;
        this->nume = nume;

        // error: cannot convert 'const std::__cxx11::basic_string<char>' to 'std::__cxx11::string* {aka std::__cxx11::basic_string<char>*}' in initialization
        //  for (string *registruModificat : registriiModificati) {
        //                                   ^~~~~~~~~~~~~~~~~~~
        // for (string *registruModificat : registriiModificati) {
        //     this->registriiModificati.push_back(registruModificat);
        // }
        this->metodaDeInfectare = metodaDeInfectare;
    }

    virtual ~Malware() {
        cout << "Malware distrus";
    }
};

class Rootkit : public virtual Malware {
private:
    list<string> listaImporturi, listaStringuriSemneficative;
protected:
public:
    // Rootkit(const double ratingImpact, const string data, const string nume, const vector<string> registriiModificati, const string metodaDeInfectare = "unknown", const list<string> listaImporturi, const list<string> listaStringuriSemneficative) : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare = "unknown"), listaImporturi(listaImporturi), listaStringuriSemneficative(listaStringuriSemneficative) {}
};

class Keylogger : public virtual Malware {
private:
    list<string> listaFunctiiFolosite, listaTasteSpecialeDefinite;
protected:
public:
    // Keylogger(const double ratingImpact, const string data, const string nume, const vector<string> registriiModificati, const string metodaDeInfectare = "unknown", const list<string> listaFunctiiFolosite, const list<string> listaTasteSpecialeDefinite) : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare = "unknown"), listaFunctiiFolosite(listaFunctiiFolosite), listaTasteSpecialeDefinite(listaTasteSpecialeDefinite) {}
};

class KernelKeylogger : public Rootkit, public Keylogger {
private:
    bool ascundeFisiere, ascundeRegistrii;
protected:
public:
    // KernelKeylogger(const double ratingImpact, const string data, const string nume, const vector<string> registriiModificati, const string metodaDeInfectare = "unknown", const list<string> listaImporturi, const list<string> listaStringuriSemneficative, const list<string> listaFunctiiFolosite, const list<string> listaTasteSpecialeDefinite, const bool ascundeFisiere, const bool ascundeRegistrii) : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare = "unknown"), Rootkit(listaImporturi, listaStringuriSemneficative), Keylogger(listaFunctiiFolosite, listaTasteSpecialeDefinite), ascundeFisiere(ascundeFisiere), ascundeRegistrii(ascundeRegistrii) {}
};

class Ransomware : public Malware {
private:
    int ratingCriptare; /// 1-10
    double ratingObfuscare;
protected:
public:
    // Ransomware(const double ratingImpact, const string data, const string nume, const vector<string> registriiModificati, const string metodaDeInfectare = "unknown", const int ratingCriptare, const double ratingObfuscare) : Malware(ratingImpact, data, nume, registriiModificati, metodaDeInfectare = "unknown"), ratingCriptare(ratingCriptare), ratingObfuscare(ratingObfuscare) {}
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
};

int Computer::idGenerator = 0;

class SingletonMenu {
private:
    static SingletonMenu* instanta;
protected:
public:
    SingletonMenu() {
        cout << "Optiuni:\n";
        cout << "1. Adauga calculatoare\n";
        cout << "2. Adauga tipuri de malware\n";
        cout << "3. Afiseaza calculatoare\n";
        cout << "4. Iesi\n";
    }

    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu();
        }
        return instanta;
    }

    void op1() const {
        cout << "Adaug calculatoare...\n";
    }

    void op2() const {
        cout << "Adaug tipuri de malware...\n";
    }

    void op3() const {
        cout << "Afisez calculatoare...\n";
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

/// Q: Care-i diferenta intre a pune const inainte, dupa, precum si inaintea si dupa o functie (const int f() {...} VS int f() const {} VS const int f() const {...})?
