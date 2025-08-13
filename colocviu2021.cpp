/// 2025-08-13-11-45-13-18

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

/// Jucarie: denumire, dimensiune, tip
/// JucarieClasica: denumire, dimensiune, tip, material, culoare
/// JucarieEducativa: denumire, dimensiune, tip, abilitate
/// JucarieElectronica: denumire, dimensiune, tip, baterii
/// JucarieModerna: denumire, dimensiune, tip, brand, model
/// Copil: ID, nume, prenume, adresa, varsta, fapte, jucarii

/// Clasa abstracta
class Jucarie {
private:
protected:
    string denumire, tip; /// tip: figurina, papusa, robotel, telefon, etc.
    int dimensiune;
public:
    Jucarie(const string &denumire, const int dimensiune, const string &tip) {
        this->denumire = denumire;
        this->dimensiune = dimensiune;
        this->tip = tip;
    }

    virtual ~Jucarie() {
        cout << "Jucarie distrusa\n";
    }

    virtual void afiseazaJucarie() const = 0; /// functie virtuala pura
};

class JucarieClasica : public Jucarie {
private:
    string material, culoare;
protected:
public:
    JucarieClasica(const string &denumire, const int dimensiune, const string &tip, const string &material, const string &culoare) : Jucarie(denumire, dimensiune, tip), material(material), culoare(culoare) {}

    ~JucarieClasica() override {
        cout << "Jucarie clasica distrusa\n";
    }

    void afiseazaJucarie() const override {
        cout << "\t" << denumire << ", " << dimensiune << ", " << tip << ", " << material << ", " << culoare << "\n";
    }
};

class JucarieEducativa : virtual public Jucarie {
private:
    string abilitate; /// abilitate: gandirea, atentia, simtul umorului, lucru in echipa, general, etc.
protected:
public:
    JucarieEducativa(const string &denumire, const int dimensiune, const string &tip, const string abilitate) : Jucarie(denumire, dimensiune, tip), abilitate(abilitate) {}

    virtual ~JucarieEducativa() override {
        cout << "Jucarie educativa distrusa\n";
    }

    virtual void afiseazaJucarie() const override {
        cout << "\t" << denumire << ", " << dimensiune << ", " << tip << ", " << abilitate << "\n";
    }
};

class JucarieElectronica : virtual public Jucarie {
private:
    int baterii;
protected:
public:
    JucarieElectronica(const string &denumire, const int dimensiune, const string &tip, const int baterii) : Jucarie(denumire, dimensiune, tip), baterii(baterii) {}

    virtual ~JucarieElectronica() override {
        cout << "Jucarie electronica distrusa\n";
    }

    virtual void afiseazaJucarie() const override {
        cout << "\t" << denumire << ", " << dimensiune << ", " << tip << ", " << baterii << "\n";
    }
};

class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    string brand, model;
protected:
public:
    JucarieModerna(const string &denumire, const int dimensiune, const string &tip, const string &brand, const string &model) : Jucarie(denumire, dimensiune, tip), JucarieEducativa(denumire, dimensiune, tip, "general"), JucarieElectronica(denumire, dimensiune, tip, 1), brand(brand), model(model) {}

    ~JucarieModerna() override {
        cout << "Jucarie moderna distrusa\n";
    }

    void afiseazaJucarie() const override {
        cout << "\t- " << denumire << ", " << dimensiune << ", " << tip << ", " << brand << ", " << model << "\n";
    }
};

class Copil {
private:
    static int idGenerator;
    int ID, varsta, fapte;
    string nume, prenume, adresa;
    vector<Jucarie*> jucarii;
protected:
public:
    Copil(const string &nume, const string &prenume, const string &adresa, const int varsta, const int fapte) : nume(nume), prenume(prenume), adresa(adresa), varsta(varsta), fapte(fapte), ID(++idGenerator) {}

    /// Evitam memory leaks
    ~Copil() {
        for (auto *jucarie : jucarii) {
            delete jucarie;
        }
    }

    const int getID() const {
        return ID;
    }

    static int getNumarCopii() {
        return idGenerator;
    }

    void afiseazaCopil() const {
        cout << ID << ". " << nume << " " << prenume << ", adresa: " << adresa << ", varsta: " << varsta << " ani, numar de fapte bune: " << fapte << ", jucarii: \n";
        for (Jucarie *j : jucarii) {
            j->afiseazaJucarie();
        }
    }

    void adaugaJucarii() {
        int m;
        cout << "Numar jucarii: "; cin >> m; cin.get();
        for (int i = 0; i < m; i++) {
            string denumire;
            cout << "Denumire (clasica/educativa/electronica/moderna): "; getline(cin, denumire);
            if (denumire != "clasica" && denumire != "educativa" && denumire != "electronica" && denumire != "moderna") {
                throw invalid_argument("Nu avem jucaria respectiva\n");
            } else if (denumire == "clasica") {
                int dimensiune;
                string tip, material, culoare;
                cout << "Dimensiune: "; cin >> dimensiune; cin.get();
                cout << "Tip: "; getline(cin, tip);
                cout << "Material: "; getline(cin, material);
                cout << "Culoare: "; getline(cin, culoare);
                jucarii.push_back(new JucarieClasica(denumire, dimensiune, tip, material, culoare));
            } else if (denumire == "educativa") {
                int dimensiune;
                string tip, abilitate;
                cout << "Dimensiune: "; cin >> dimensiune; cin.get();
                cout << "Tip: "; getline(cin, tip);
                cout << "Abilitate: "; getline(cin, abilitate);
                jucarii.push_back(new JucarieEducativa(denumire, dimensiune, tip, abilitate));
            } else if (denumire == "electronica") {
                int dimensiune, baterii;
                string tip;
                cout << "Dimensiune: "; cin >> dimensiune; cin.get();
                cout << "Tip: "; getline(cin, tip);
                cout << "Baterii: "; cin >> baterii; cin.get();
                jucarii.push_back(new JucarieElectronica(denumire, dimensiune, tip, baterii));
            } else { /// moderna
                int dimensiune;
                string tip, brand, model;
                cout << "Dimensiune: "; cin >> dimensiune; cin.get();
                cout << "Tip: "; getline(cin, tip);
                cout << "Brand: "; getline(cin, brand);
                cout << "Model: "; getline(cin, model);
                jucarii.push_back(new JucarieModerna(denumire, dimensiune, tip, brand, model));
            }
        }
    }
};

int Copil::idGenerator = 0;

class MenuSingleton {
private:   
    vector<Copil*> copii;
    static MenuSingleton* instanta;
protected:
public:
    MenuSingleton() {
        cout << "Operatiuni:\n";
        cout << "1. Adauga n copii\n";
        cout << "2. Adauga m jucarii copilului n\n";
        cout << "3. Afiseaza copii\n";
        cout << "4. Iesi din meniu\n";
    }

    /// Evitam memory leaks
    ~MenuSingleton() {
        for (auto *copil : copii) {
            delete copil;
        }
    }

    static MenuSingleton* getInstanta() {
        if (instanta == nullptr) {
            instanta = new MenuSingleton;
        }
        return instanta;
    }

    void op1() {
        cout << "Adaug n copii...\n";
        int n;
        cout << "n: "; cin >> n; cin.get();
        for (int i = 0; i < n; i++) {
            // Copil: ID, nume, prenume, adresa, varsta, fapte, jucarii
            string nume, prenume, adresa;
            int varsta, fapte;
            cout << "Nume: "; getline(cin, nume);
            cout << "Prenume: "; getline(cin, prenume);
            cout << "Adresa: "; getline(cin, adresa);
            cout << "Varsta: "; cin >> varsta; cin.get();
            cout << "Fapte: "; cin >> fapte; cin.get();
            copii.push_back(new Copil(nume, prenume, adresa, varsta, fapte));
        }
    }

    void op2() {
        cout << "Adaug jucarii fiecarui copil...\n";
        for (Copil *copil : copii) {
            cout << "Pentru ID: " << copil->getID() << "\n";
            copil->adaugaJucarii();
        }
    }

    void op3() {
        cout << "Afisez copii...\n";
        for (auto *copil : copii) {
            copil->afiseazaCopil();
        }
    }
};

MenuSingleton* MenuSingleton::instanta = nullptr;

int main() {
    MenuSingleton* m;
    m = MenuSingleton::getInstanta();
    int optiune;

    do {
        try {
            cout << "Optiune: "; cin >> optiune; cin.get();
            if (optiune < 1 || optiune > 4) {
                throw out_of_range("Optiunea nu exista\n");
            } else if (optiune == 1) {
                m->op1();
            } else if (optiune == 2) {
                m->op2();
            } else if(optiune == 3) {
                m->op3();
            } else {
                cout << "Iesire...\n";
            }
        } catch (const invalid_argument &e) {
            cout << "Eroare in timpul executiei uneia dintre optiuni: " << e.what(); /// exceptie propagata
        }
         catch (const exception &e) {
            cout << "Exceptie: " << e.what();
        }
    } while (optiune != 4);

    return 0;
}

/// Q: Trebe neaparat ca toti destructorii sa fie virtuali sau doar aceia a caror clasa este parinte?
/// A: Doar clasele care sunt parinte polimorfic au nevoie de destructor virtual.

/// Q: Virtual nu facea sa afisez numai destructorul ultimului copil din arbore?
/// A: Nu, dimpotriva, el asigura ca se apeleaza toata ierahia de destructori, de sus in jos (de la derivat la baza)