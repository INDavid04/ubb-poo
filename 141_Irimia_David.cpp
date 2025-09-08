/*
Irimia David
Grupa 141
g++ 141_Irimia_David.cpp -o e.exe
./e.exe
Radu Tudor Vrinceanu
*/

////////////////
/// Ierarhie ///
////////////////

/// Artefact: idArtefact, nume, data, pretInitial
/// ArtefactIstoric: Artefact, persoana
/// ArtefactArtistic: Artefact, tip(pictura/sculptura), material(acrilic, ulei pentru picturi, lemn, piatra, marmura pentru sculpturi)
/// ArtefactPretios: Artefact, designer("Necunoscut" default), greutatea

/// Persoana: idPersoana
/// PersoanaFizica: Persoana, nume
/// PersoanaJuridica: Persoana, organizatie, persoaneFizice

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

/// Artefact: idArtefact, nume, data, pretInitial
/// Clasa abstracta
class Artefact {
    static int id;
    int idArtefact;
    string nume, data;
    double pretInitial;
public:
    /// Constructor
    Artefact(const string &nume, const string &data, const double pretInitial) {
        this->nume = nume;
        this->data = data;
        this->pretInitial = pretInitial;
        idArtefact = ++id;
    }

    /// Destructor virtual
    virtual ~Artefact() {}

    /// Fucntie virtuala pura
    virtual void afiseaza() const = 0;

    /// Getteri pentru incapsulare
    static int getId() { return id; }
    const int getIdArtefact() const { return idArtefact; }
    const string &getNume() const { return nume; }
    const string &getData() const { return data; }
    const double getPretInitial() const { return pretInitial; }
};

int Artefact::id = 0;

/// ArtefactIstoric: Artefact, persoana
class ArtefactIstoric : public Artefact {
    string persoana;
public:
    /// Constructor
    ArtefactIstoric(const string &nume, const string &data, const double pretInitial, const string &persoana) : Artefact(nume, data, pretInitial), persoana(persoana) {
        cout << "Artefact istoric #" << getId() << " adaugat\n";
    }

    /// Destructor
    ~ArtefactIstoric() {
        cout << "Artefact istoric #" << getIdArtefact() << " scos\n";
    }

    /// Metoda declarata virtual in baza si redefinita in derivata
    void afiseaza() const override {
        cout << getId() << ". " << getNume() << ", " << getData() << ", " << getPretInitial() << " lei, persoana renumita: " << persoana << "\n";
    }

    /// Getter
    const string &getPersoana() const { return persoana; }
};

/// ArtefactArtistic: Artefact, tip(pictura/sculptura), material(acrilic, ulei pentru picturi, lemn, piatra, marmura pentru sculpturi)
class ArtefactArtistic : public Artefact {
    string tip, material;
public:
    /// Constructor
    ArtefactArtistic(const string &nume, const string &data, const double pretInitial, const string &tip, const string &material) : Artefact(nume, data, pretInitial), tip(tip), material(material) {
        cout << "Artefact artistic #" << getId() << " adaugat\n";
    }

    /// Destructor
    ~ArtefactArtistic() {
        cout << "Artefact artistic #" << getIdArtefact() << " scos\n";
    }

    void afiseaza() const override {
        cout << getId() << ". " << getNume() << ", " << getData() << ", " << getPretInitial() << " lei,  tip: " << tip << ", material: " << material << "\n";
    }

    /// Getteri
    const string &getTip() const { return tip; }
    const string &getMaterial() const { return material; }
};

/// ArtefactPretios: Artefact, designer("Necunoscut" default), greutatea
class ArtefactPretios : public Artefact {
    string designer;
    int greutate;
public:
    /// Construcor
    ArtefactPretios(const string &nume, const string &data, const double pretInitial, const int greutate, const string &designer = "Necunoscut") : Artefact(nume, data, pretInitial), designer(designer), greutate(greutate) {
        cout << "Artefact pretios #" << getId() << " adaugat\n";
    }

    /// Destructor
    ~ArtefactPretios() {
        cout << "Artefact pretios #" << getIdArtefact() << " scos\n";
    }

    void afiseaza() const override {
        cout << getId() << ". " << getNume() << ", " << getData() << ", " << getPretInitial() << " lei,  designer: " << designer << ", greutatea in grame: " << greutate << "\n";
    }

    /// Getteri
    const string &getDesigner() const { return designer; }
    const int getGreutate() const { return greutate; }
};

/// Persoana: idPersoana
/// Clasa abstracta
class Persoana {
    static int id;
    int idPersoana;
public:
    /// Constructor
    Persoana() {
        idPersoana = ++id;
    }

    /// Destructor virtual
    virtual ~Persoana() {}

    /// Metoda virtuala pura
    virtual void afiseaza() const = 0;

    /// Getteri
    static int getId() { return id; }
    const int getIdPersoana() const { return idPersoana; }
};

int Persoana::id = 0;

/// PersoanaFizica: Persoana, nume
class PersoanaFizica : public Persoana {
    string nume;
public:
    /// Constructor
    PersoanaFizica(const string &nume) {
        this->nume = nume;
    }

    /// Destructor
    ~PersoanaFizica() {}

    void afiseaza() const override  {
        cout << getIdPersoana() << ". " << nume << "\n";
    }

    /// Getter
    const string &getNume() const { return nume; }
};

/// PersoanaJuridica: Persoana, organizatie, persoaneFizice
class PersoanaJuridica : public Persoana {
    string organizatie;
    vector<string> persoaneFizice;
public:
    /// Constructor
    PersoanaJuridica(const string &organizatie, const vector<string> &persoaneFizice) : Persoana(), organizatie(organizatie), persoaneFizice(persoaneFizice) {}

    /// Destructor
    ~PersoanaJuridica() {}

    void afiseaza() const override  {
        bool first = true;
        cout << getIdPersoana() << ". " << organizatie << "; Persoane fizice: ";
        /// Folosim bool first pentru o afisare mai eleganta, primul termen fiind fara virgula, ceilalti avand o virtual - pentru enumerare: t1, t2, t3 si asa mai depare in loc de , t1, t2, t3 si asa mai departe
        for (auto persoana : persoaneFizice) {
            if (first) {
                cout << persoana;
                first = false;
            } else {
                cout << ", " << persoana;
            }
        }
        cout << "\n";
    }

    /// Getter
    const string &getOrganizatie() const { return organizatie; }
    const vector<string> &getPersoaneFizice() const { return persoaneFizice; }
};

/// Singleton
class SingletonMenu {
    static SingletonMenu* instanta;
    vector<Persoana*> participanti;
    vector<Artefact*> artefacte;

    /// Constructor privat
    SingletonMenu() {
        afiseazaOptiuni();
    }

public:
    /// Destructor, aici dezalocam memoria
    ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
        
        for (auto *participant : participanti) {
            delete participant;
            participant = nullptr;
        }

        for (auto *artefact : artefacte) {
            delete artefact;
            artefact = nullptr;
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
        cout << "1. Adauga participant\n";
        cout << "2. Adauga artefact\n";
        cout << "3. Afiseaza participanti\n";
        cout << "4. Afiseaza articole disponibile pentru licitatie\n";
        cout << "5. Afiseaza optiuni\n";
        cout << "6. Iesi din meniu\n";
    }

    void op1() {
        string tip;
        cout << "Adaug participant...\n";
        /// Persoana: idPersoana
        /// PersoanaFizica: Persoana, nume
        /// PersoanaJuridica: Persoana, organizatie, persoaneFizice
        cout << "Persoana (fizica/juridica): ";
        getline(cin, tip);

        if (tip == "fizica") {
            string nume;
            cout << "Nume: ";
            getline(cin, nume);
            participanti.push_back(new PersoanaFizica(nume));
        } else if (tip == "juridica") {
            string organizatie, persoanaFizica, raspuns;
            vector<string> persoaneFizice;
            cout << "Organizatie: ";
            getline(cin, organizatie);
            do {
                cout << "Persoana fizica: ";
                getline(cin, persoanaFizica);
                persoaneFizice.push_back(persoanaFizica);
                cout << "Adauga (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n"); /// exceptia se propaga
                }
            } while (raspuns == "da");
            participanti.push_back(new PersoanaJuridica(organizatie, persoaneFizice));
        } else {
            throw invalid_argument("Persoana invalida\n");
        }
    }

    void op2() {
        string artefact, nume, data;
        double pretInitial;
        cout << "Adaug artefact...\n";
        /// Artefact: idArtefact, nume, data, pretInitial
        /// ArtefactIstoric: Artefact, persoana
        /// ArtefactArtistic: Artefact, tip(pictura/sculptura), material(acrilic, ulei pentru picturi, lemn, piatra, marmura pentru sculpturi)
        /// ArtefactPretios: Artefact, designer("Necunoscut" default), greutatea
        
        cout << "Nume: ";
        getline(cin, nume);
        cout << "Data: ";
        getline(cin, data);
        cout << "Pret Initial: ";
        cin >> pretInitial;
        cin.get(); 

        cout << "Artefact (istoric/artistic/pretios): ";
        getline(cin, artefact);

        if (artefact == "istoric") {
            string persoana;
            cout << "Persoana: ";
            getline(cin, persoana);
            artefacte.push_back(new ArtefactIstoric(nume, data, pretInitial, persoana));
        } else if (artefact == "artistic") {
            string tip, material;
            cout << "Tip (pictura/sculptura): ";
            getline(cin, tip);
            if (tip != "pictura" && tip != "sculptura") {
                throw invalid_argument("Tip artefact invalid\n");
            }
            cout << "Mateial: ";
            getline(cin, material);
            artefacte.push_back(new ArtefactArtistic(nume, data, pretInitial, tip, material));
        } else if (artefact == "pretios") {
            int greutate;
            cout << "Greutatea in grame: ";
            cin >> greutate;
            cin.get();
            artefacte.push_back(new ArtefactPretios(nume, data, pretInitial, greutate));
        } else {
            throw invalid_argument("Artefact invalid\n");
        }
    }

    void op3() const {
        cout << "Afisez participanti...\n";
        /// Verificam mai intai sa vedem daca sunt participanti
        if (participanti.empty()) {
            cout << "Nu exista participanti\n";
        } else {
            for (auto &participant : participanti) {
                participant->afiseaza();
            }
        }
    }

    void op4() const {
        cout << "Afisez aricole disponibile pentru licitatie...\n";
        /// Verificam mai intai sa vedem daca sunt artefacte
        if (artefacte.empty()) {
            cout << "Nu exista articole\n";
        } else {
            for (auto &artefact : artefacte) {
                artefact->afiseaza();
            }
        }
    }

    void op5() const {
        afiseazaOptiuni();
    }

    void op6() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

template <class T>
void verifica(T op) {
    if (op < 1 || op > 6) {
        throw out_of_range("Optiune invalida\n"); /// exceptia se propaga
    }
}

int main() {
    static SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            verifica(optiune);

            switch(optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
                case 5: m->op5(); break;
                case 6: m->op6(); break;
            }
        } while (optiune != 6);
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    }

    /// Mai sus, prindem exceptiile si le tratam

    /// La final, dezalocam memoria
    delete m;

    return 0;
}
