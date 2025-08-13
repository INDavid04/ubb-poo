/// 2025-08-13-11-45-13-18

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Jucarie {
private:
    string denumire, tip; /// tip: figurina, papusa, robotel, telefon, etc.
    int dimensiune;
protected:
public:
    Jucarie(const string &denumire, const int dimensiune, const string &tip) {
        this->denumire = denumire;
        this->dimensiune = dimensiune;
        this->tip = tip;
    }

    virtual ~Jucarie() {
        cout << "Jucarie distrusa\n";
    }
};

class JucarieClasica : public Jucarie {
private:
    string material, culoare;
protected:
public:
    JucarieClasica(const string &denumire, const int dimensiune, const string &tip, const string &material, const string &culoare) : Jucarie(denumire, dimensiune, tip), material(material), culoare(culoare) {}

    ~JucarieClasica() {
        cout << "Jucarie clasica distrusa\n";
    }
};

class JucarieEducativa : public Jucarie {
private:
    string abilitate; /// abilitate: gandirea, atentia, simtul umorului, lucru in echipa, general, etc.
protected:
public:
    JucarieEducativa(const string &denumire, const int dimensiune, const string &tip, const string abilitate) : Jucarie(denumire, dimensiune, tip), abilitate(abilitate) {}

    virtual ~JucarieEducativa() {
        cout << "Jucarie educativa distrusa\n";
    }
};

class JucarieElectronica : public Jucarie {
private:
    int baterii;
protected:
public:
    JucarieElectronica(const string &denumire, const int dimensiune, const string &tip, const int baterii) : Jucarie(denumire, dimensiune, tip), baterii(baterii) {}

    virtual ~JucarieElectronica() {
        cout << "Jucarie electronica distrusa\n";
    }
};

class JucarieModerna : virtual JucarieEducativa, virtual JucarieElectronica {
private:
    string brand, model;
protected:
public:
    JucarieModerna(const string &denumire, const int dimensiune, const string &tip, const string &brand, const string &model) : JucarieEducativa(denumire, dimensiune, tip, "general"), JucarieElectronica(denumire, dimensiune, tip, 1), brand(brand), model(model) {}

    ~JucarieModerna() {
        cout << "Jucarie moderna distrusa\n";
    }
};

/// Jucarie: denumire, dimensiune, tip
/// JucarieClasica: denumire, dimensiune, tip, material, culoare
/// JucarieEducativa: denumire, dimensiune, tip, abilitate
/// JucarieElectronica: denumire, dimensiune, tip, baterii
/// JucarieModerna: denumire, dimensiune, tip, brand, model
/// Copil: ID, nume, prenume, adresa, varsta, fapte, jucarii

class Copil {
private:
    static int idGenerator;
    int ID, varsta, fapte;
    string nume, prenume, adresa;
    vector<Jucarie*> jucarii;
protected:
public:
    Copil(const string &nume, const string &prenume, const string &adresa, const int varsta, const int fapte) : nume(nume), prenume(prenume), adresa(adresa), varsta(varsta), fapte(fapte), ID(++idGenerator) {}
    
    static int getNumarCopii() {
        return idGenerator;
    }

    void adaugaJucarie(Jucarie* j) const {
        // jucarii.push_back(j);
    }
};

int Copil::idGenerator = 0;

class MenuSingleton {
private:   
    vector<Copil*> copii;
    static MenuSingleton* instanta;
    MenuSingleton() {
        cout << "Operatiuni:\n";
        cout << "1. Adauga n copii\n";
        cout << "2. Adauga m jucarii copilului n\n";
        cout << "3. Afiseaza copii\n";
        cout << "4. Iesi din meniu\n";
    }
protected:
public:
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
        /// Out of time
        // for (auto copil* : copii) {
        //     copil->adaugaJucarie(Jucarie* j);
        // }
    }

    void op3() {
        cout << "Afisez copii...\n";
    }
};

MenuSingleton* MenuSingleton::instanta = nullptr;

int main() {
    Jucarie* j = new Jucarie("masina cu telecomanda", 5, "masina");
    delete j;

    JucarieModerna* jm = new JucarieModerna("masina cu telecomanda", 5, "masina", "Mercedess", "G Class");
    delete jm;

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
        } catch (const exception &e) {
            cout << "Alta exceptie: " << e.what();
        }
    } while (optiune != 4);

    return 0;
}

/// TODO: trebe neaparat ca toti destructorii sa fie virtuali sau doar aceia a caror clasa este parinte?

/// TODO: virtual nu facea sa afisez numai destructorul ultimului copil din arbore?