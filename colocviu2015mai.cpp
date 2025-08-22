/// 2025-08-22-09-40-11-18
/// Conform gpt, nota: 7
/// Conform baremului, nota: 5
/// Penalizare -0.5p: memory leak

#include <iostream>
#include <stdexcept> /// pentru out_of_range, invalid_argument
#include <string>
#include <vector>

using namespace std;

/// Produs: denumire, unitate

/// Clasa abstracta
class Produs {
    static int idProdusGenerator;
    int idProdus;
    string denumire, unitate;
public:
    /// Constructor
    Produs(const string &denumire, const string &unitate) {
        this->denumire = denumire;
        this->unitate = unitate;
        idProdus = ++idProdusGenerator;
    }

    /// Destructor virtual
    virtual ~Produs() {
        cout << "Produs eliminat\n";
    }

    /// Getter inline
    /// Initial: `const string getDenumire() const { return denumire; }`
    /// Modificat: `const string& getDenumire() const { return denumire; }`
    /// Explicatie: Returnam referinta la variabila de tip string, denumire, pentru eficienta
    const string& getDenumire() const { return denumire; }

    const string& getUnitate() const { return unitate; }

    const int& getIdProdus() const { return idProdus; }

    /// Getter static
    static int& getIdProdusGenerator() { return idProdusGenerator; }

    /// Metoda virtuala pura
    virtual void afiseaza() const = 0;
};

/// Preinitializare variabila statica
int Produs::idProdusGenerator = 0;

/// ProdusSimplu: Produs (Explicatie: Avem nevoie si de aceasta clasa pentru a putea afisa un produs care nu este nici perisabil nici in promotie, pastrand clasa Produs ca o clasa abstracta)

class ProdusSimplu : public Produs {
    /// Initial: `const string perioada;`
    /// Modificat: linie scoasa
    /// Explicatie: camp nefolosit
public:
    /// Constructor
    ProdusSimplu(const string &denumire,const string &unitate) : Produs(denumire, unitate) {
        /// Initial: `cout << "Produs #" << getIdProdusGenerator << " adaugat.\n";`
        /// Modificat: `cout << "Produs #" << getIdProdusGenerator() << " adaugat.\n";`
        /// Explicatie: am uitat sa pun `()`
        cout << "Produs #" << getIdProdusGenerator() << " adaugat.\n";
    }

    /// Destructor
    ~ProdusSimplu() {
        cout << "Produs eliminat\n";
    }

    /// Metoda din clasa de baza Produs suprascrisa in clasa derivata ProdusSimplu, constanta pentru ca nu modifica campurile de date
    virtual void afiseaza() const override {
        cout << getIdProdus() << ". Denumire: " << getDenumire() << ", unitate: " << getUnitate() << ";\n";
    }
};

/// ProdusPerisabil: Produs, perioada

class ProdusPerisabil : public Produs {
    const int valabil;
public:
    /// Constructor
    ProdusPerisabil(const string &denumire, const string &unitate, const int &valabil) : Produs(denumire, unitate), valabil(valabil) {
        cout << "Produs perisabil #" << getIdProdusGenerator() << " adaugat.\n";
    }

    /// Destructor
    virtual ~ProdusPerisabil() {
        cout << "Produs perisabil eliminat\n";
    }

    /// Initial: `/// Getter constant care returneaza o constanta`
    /// Modificat: `/// Getter care returneaza o referinta`
    const int& getValabil() const { return valabil; }

    /// Metoda din clasa de baza Produs suprascrisa in clasa derivata ProdusPerisabil, constanta pentru ca nu modifica campurile de date
    virtual void afiseaza() const override {
        cout << getIdProdus() << ". Denumire: " << getDenumire() << ", unitate: " << getUnitate() << ", valabil: " << valabil << " zile;\n";
    }
};

/// ProdusPromotie: Produs, dicount

class ProdusPromotie : virtual public Produs {
    const int discount;
public:
    /// Constructor
    ProdusPromotie(const string &denumire,const string &unitate, const int &discount) : Produs(denumire, unitate), discount(discount) {
        cout << "Produs promotie #" << getIdProdusGenerator() << " adaugat.\n";
    }

    /// Destructor
    ~ProdusPromotie() {
        cout << "Produs promotie eliminat\n";
    }

    /// Getter constant
    const int& getDiscount() const { return discount; }

    /// Metoda din clasa de baza Produs suprascrisa in clasa derivata ProdusPromotie, constanta pentru ca nu modifica campurile de date
    virtual void afiseaza() const override {
        cout << getIdProdus() << ". Denumire: " << getDenumire() << ", unitate: " << getUnitate() << ", discount promotie: " << discount << ";\n";
    }
};

/// data: 03.05.2015, cantitate: 150 kg, denumire: cireșe, valabil: 5 zile, pret: 20 lei pe kg
/// data: 05.05.2015, cantitate: 500 buc, denumire: caciuli, pret: 15 lei bucata
/// data: 16.05.2015, cantitate: 300 kg, denumire: cirese, valabil: 3 zile, pret: 15 lei pe kg, discount de 20%
/// data: 19.05.2015, cantitate: 100 de litri, denumire: rom, pret: 25 de lei pe litru, discount: 10%

/// Meniu implementat cu ajutorul singleton

class SingletonMenu {
    static SingletonMenu *instanta;
    vector<Produs*> produse;

    /// Constructor privat
    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    /// Destructor public
    ~SingletonMenu() {
        cout << "Meniu distrus\n";
        /// Aici am uitat sa eliberez memoria produselor stocate in vector (penalizare)
        for (auto &produs : produse) {
            delete produs;
            produs = nullptr;
        }
    }

    /// Metoda care returneaza variabila statica, instanta
    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    /// Metoda constanta care afiseaza optiunile pentru a nu avea cod care se repetea si in constructor si in op3()
    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Adauga produs nou\n";
        cout << "2. Afiseaza toate produsele pe care magazinul le poate comercializa\n";
        cout << "3. Afiseaza optiuni\n";
        cout << "4. Iesi din meniu\n";
    }

    void op1() {
        /// Pentru fiecare produs, cunoastem denumirea si unitatea acestuia
        string denumire, unitate, tip;
        cout << "Adaug produs nou\n";
        cout << "Denumire: ";
        getline(cin, denumire);
        cout << "Unitate(bucata/greutate/volum): ";
        getline(cin, unitate);

        /// Daca unitatea nu se regaseste in lista aruncam o exceptie care se propaga in main()
        if (unitate != "bucata" && unitate != "greutate" && unitate != "volum") {
            throw invalid_argument("Unitate invalida\n");
        }

        cout << "Tip(simplu/perisabil/promotie): ";
        getline(cin, tip);

        /// Daca tipul nu se regaseste in lista aruncam o exceptie care se propaga in main()
        if (tip != "simplu" && tip != "perisabil" && tip != "promotie") {
            throw invalid_argument("Tip invalid\n");
        } else if (tip == "simplu") {
            produse.push_back(new ProdusSimplu(denumire, unitate));
        } else if (tip == "perisabil") {
            int valabil;
            cout << "Valabil(in zile): ";
            cin >> valabil;
            cin.get();
            produse.push_back(new ProdusPerisabil(denumire, unitate, valabil));
        } else { /// tip == "promotie"
            int discount;
            cout << "Discount(in procente): ";
            cin >> discount;
            cin.get();
            produse.push_back(new ProdusPromotie(denumire, unitate, discount));
        }
    }

    void op2() const {
        /// Verificam daca avem produse, afisand un mesaj corespunzator
        if (produse.empty()) {
            cout << "Nu exista produse pe care magazinul pe poate comercializa\n";
        } else {
            cout << "Afisez toate produsele pe care magazinul le poate comercializa\n";
            /// Pentru fiecare produs apelam metoda afiseaza
            for (auto &produs : produse) {
                produs->afiseaza();
            }
        }
    }

    void op3() const {
        afiseazaOptiuni();
    }

    void op4() const {
        cout << "Iesire...\n";
    }
};

/// Preinitializam variabila statica instanta
SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu* m = SingletonMenu::getInstanta();

    int optiune;
    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            /// Verificam ca optiunea sa fie valida, adica sa fie in intervalul [1, 4]
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
    } catch (invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    } catch (out_of_range &e) {
        cout << "Out of range: " << e.what();
    }

    /// Eliberam memoria
    delete m;

    return 0;
}

// - Barem 2015 mai
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
