/// 2025-08-18-11-25-12-54

/// E.C => nota 1

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

/// Persoana: idPersoana, inventar

/// Clasa abstracta
class Persoana {
private:
protected:
    static int idPersoanaGenerator;
    int idPersoana;
    Inventar inventar;
public:
    Persoana(Inventar inventar) {
        this->inventar = inventar;
        idPersoana = idArtefactGenerator++;
    }
    
    /// Destructor virtual
    virtual ~Persoana() {}

    /// Metoda virtuala pura
    virtual void afiseaza() const = 0;
};
int Persoana::idPersoanaGenerator = 1;

/// PersoanaFizica: nume(real sau alias)

class PersoanaFizica : public Persoana {
private:
    const string nume;
protected:
public:
    PersoanaFizica(const string &nume, Inventar inventar = {}) : Inventar(inventar) {
        this->nume = nume;
    }

    ~PersoanaFizica() {
        cout << "Persoana fizica iesita din vedere\n";
    }

    void afiseaza() const override {
        cout << idPersoana << ". " << nume << ":\n";
        inventar.afiseaza();
    }
};

/// PersoanaJuridica: organizatie, reprezentanti

class PersoanaJuridica : public Persoana {
private:
    const string organizatie;
    const vector<string> reprezentanti;
protected:
public:
    PersoanaJuridica(const string &organizatie, const vector<string> &reprezentanti, Inventar inventar = {}) : Inventar(inventar), organizatie(organizatie), reprezentanti(reprezentanti) {}

    ~PersoanaJuridica() {
        cout << "Persoana juridica iesita din vedere\n";
    }

    void afiseaza() const override {
        bool ePrimul = true;
        cout << idPersoana << ". " << organizatie << ": ";
        for (auto reprezentant : reprezentanti) {
            if (ePrimul) {
                cout << reprezentant;
                ePrimul = false;
            } else {
                cout << ", " << reprezentant;
            }
        }
        cout << ":\n";
        inventar.afiseaza();
    }
};

/// Inventar: artefacte

class Inventar {
private:
    vector<Artefact*> artefacte;
protected:
public:
    Inventar(vector<Artefact*> artefacte = {}) : artefacte(artefacte) {}
    
    /// Destructor virtual
    virtual ~Inventar() {
        cout << "Inventar distrus\n";
        delete[] artefacte;
    }

    void afiseaza() const {
        for (auto artefact : artefacte) {
            artefact.afiseaza();
        }
    }
};

/// Artefact: idArtefact, nume, data sau era aproximativa din care dateaza, pretul initial de listare

/// Clasa abstracta
class Artefact {
private:
protected:
    static int idArtefactGenerator;
    const int idArtefact, pret;
    const string nume, data;
public: 
    Artefact(const string &nume, const string &data, const int pret) : idArtefact(idArtefactGenerator++), nume(nume), data(data), pret(pret) {}

    virtual ~Artefact {
        cout << "Artefact: " << nume << " distrus\n";
    }

    /// Functie virtuala pura
    virtual void afiseaza() const = 0;
};

int Artefact::idArtefactGenerator = 1;

/// ArtefactIstoric: persoane

class ArtefactIstoric : public Artefact {
private:
    const vector<string> persoane;
protected:
public:
    ArtefactIstoric(const string &nume, const string &data, const int pret, const vector<string> &persoane) : Artefact(nume, data, pret), persoane(persoane) {}

    ~ArtefactIstoric() {
        cout << "Artefact istoric distrus\n";
    }

    void afiseaza() const override {
        bool ePrima = true;
        cout << "\t" << idArtefact << ". " << nume << ", data: " << data << ", pret: " << pret << "persoane: ";
        for (auto persoana : persoane) {
            if (ePrima) {
                cout << persoana;
                ePrima = false;
            } else {
                cout << ", " << persoana;
            }
        }
        cout << "\n";
    }
};

/// ArtefactArtistic: tip(pictura/sculptura), material(acrilic, ulei pentru picturi, lemn, piatra, marmura pentru sculpturi)

class ArtefactArtistic : public Artefact {
private:
    const string tip, material;
protected:
public:
    ArtefactArtistic(const string &nume, const string &data, const int pret, const string &tip, const string &material) : Artefact(nume, data, pret), tip(tip), material(material) {}

    ~ArtefactArtistic() {
        cout << "Artefact artistic distrus\n";
    }

    void afiseaza() const override {
        cout << "\t" << idArtefact << ". " << nume << ", data: " << data << ", pret: " << pret << "tip: " << tip << ", material: " << material << "\n";
    }
};

/// ArtefactPretios: designer("Necunoscut" by default), greutate(in grame)

class ArtefactPretios : public Artefact {
private:
    const string designer;
    const int greutate;
protected:
public:
    ArtefactPretios(const string &nume, const string &data, const int pret, const int greutate, const string &designer = "Necunoscut") : Artefact(nume, data, pret), greutate(greutate), designer(designer) {}

    ~ArtefactPretios() {
        cout << "Artefact pretios distrus\n";
    }

    void afiseaza() const override {
        cout << "\t" << idArtefact << ". " << nume << ", data: " << data << ", pret: " << pret << "greutate: " << greutate << ", designer: " << designer << "\n";
    }
};

class SingletonMenu {
private:
    static SingletonMenu* instanta;
    vector<Persoana*> participanti;

    /// Constructor privat
    SingletonMenu() {
        afiseazaOptiuni();
    }
protected:
public:
    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu();
        }
        return instanta;
    }

    /// Evitam memory leaks
    void elibereazaMemoria() {
        delete instanta;
        instanta = nullptr;
        delete[] participanti;
        for(auto participant : participanti) {
            participant = nullptr;
        }
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:";
        cout << "1. Adauga participant\n";
        cout << "2. Adauga artefact\n";
        cout << "3. Afiseaza participanti\n";
        cout << "4. Afiseaza artefacte\n";
        cout << "5. Afiseaza participanti in ordine descrescatoare numarului de artefacte cumparate\n";
        cout << "6. Reafiseaza optiuni\n";
        cout << "7. Iesi";
    }

    void op1() {
        cout << "Adaug participanti...\n";
        const string tip;
        cout << "Persoana (fizica/juridica): ";
        getline(cin, tip);
        if (tip == "fizica") {
            const string nume;
            cout << "Nume persoana fizica: ";
            getline(cin, nume);
            participanti.push_back(new PersoanaFizica(nume));
        } else if (tip == "juridica") {
            const string organizatie, reprezentant;
            const vector<string> reprezentanti;
            bool adaug;
            cout << "Nume organizatie: ";
            getline(cin, organizatie);
            do {
                cout << "Nume reprezentant: ";
                getline(cin, reprezentant);
                cout << "Adaug alt reprezentant (da/nu): ";
                getline(cin, adaug);
            } while (adaug);
            participanti.push_back(new PersoanaJuridica(organizatie, reprezentanti));
        } else {
            throw invalid_argument("Tip gresit. Alege doar intre: fizica/juridica\n");
        }
    }

    void op2() {
        cout << "Adaug artefacte...\n";
    }

    void op3() {
        cout << "Afisez participanti...\n";
    }

    void op4() {
        cout << "Afisez artefacte...\n";
    }

    void op5() {
        cout << "Afisez participanti in ordine descrescatoare numarului de artefacte cumparate...\n";
    }

    void op6() {
        cout << "Reafisez optiuni...\n";
    }

    void op7() {
        cout << "Ies din meniu...\n";
    }
};

SingletonMenu* SingletonMenu:: instanta = nullptr;

int main() {
    SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;

            if (optiune < 1 && optiune > 7) {
                throw out_of_range("Optiune invalida. Alege in intervalul [1,7]!\n");
            }

            switch(optiune) {
                case 1: op1(); break;
                case 2: op1(); break;
                case 3: op1(); break;
                case 4: op1(); break;
                case 5: op1(); break;
                case 6: op1(); break;
                case 7: op1(); break;
            }
        } while(optiune != 7);
    } catch (invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    } catch (out_of_range &e) {
        cout << "Out of range: " << e.what();
    }

    SingletonMenu::elibereazaMemoria();

    return 0;
}
