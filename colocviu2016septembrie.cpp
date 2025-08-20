/// 2025-08-20-09-55-11-20

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/// OK if:
/// HomeConfiguration: videoproiector("on"), ecranDeProiectie("down"), tablaSmart("off")
/// HomeConfiguration: videoproiector("off"), ecranDeProiectie("up"), tablaSmart("on")
/// HomeConfiguration: videoproiector("off"), ecranDeProiectie("off"), tablaSmart("off")
/// Else "Nu am  inteles cerinta!"

class Home {
private:
    static int homeIdGenerator;
    int homeId;
protected:
    bool videoproiector, ecranDeProiectie, tablaSmart;
public:
    /// Constructor fara parametrii
    Home(bool videoproiector = 0, bool ecranDeProiectie = 0, bool tablaSmart = 0) {
        this->videoproiector = videoproiector;
        this->ecranDeProiectie = ecranDeProiectie;
        this->tablaSmart = tablaSmart;
        homeId = ++homeIdGenerator;
        cout << "Constructor apelat pentru un obiect de tip home #" << getHomeIdGenerator() << "\n";
    }

    /// Destructor virtual (Home este clasa de baza, Education este clasa derivata)
    virtual ~Home() {
        cout << "Destructor apelat pentru un obiect de tip home #" << getHomeId() << "\n";
    }

    /// Metoda statica care returneaza o constanta, homeIdGenerator
    const static int getHomeIdGenerator() {
        return homeIdGenerator;
    }

    /// Metoda care returneaza o constanta, homeId
    const int getHomeId() {
        return homeId;
    }

    /// Suprascrierea operatorului >> nereusita
    void operator>>(Home &obj) {
        string videoproiector, ecranDeProiectie, tablaSmart;

        cout << "Videoproiector(on/off): ";
        getline(cin, videoproiector);
        cout << "Ecran de proiectie(up/down): ";
        getline(cin, ecranDeProiectie);
        cout << "Tabla smart(on/off): ";
        getline(cin, tablaSmart);

        this->videoproiector = (videoproiector == "on") ? 1 : 0;
        this->ecranDeProiectie = (ecranDeProiectie == "down") ? 1 : 0;
        this->tablaSmart = (tablaSmart == "on") ? 1 : 0;
    }

    /// Fucntie care opresete un anumit dispozitiv
    void Home_opreste(const string &dispozitiv) {
        if (dispozitiv == "videoproiector") {
            this->videoproiector = 0;
            cout << "Video-proiector oprit\n";
        } else if (dispozitiv == "ecran") {
            this->ecranDeProiectie = 0;
            cout << "Ecran de proiectie oprit\n";
        } else if (dispozitiv == "tabla") {
            this->tablaSmart = 0;
            cout << "Tabla smart oprita\n";
        } else {
            /// Exceptia se propaga
            throw invalid_argument("Dispozitiv necunoscut. Incearca: videoproiector/ecran/tabla!\n");
        }
    } 
};

/// Initializam variabila statica
int Home::homeIdGenerator = 0;

/// Education request if:
/// EducationConfiguration: tabla(off), videoproiector(on), ecran(on)

class Education : public Home {
private:
    static int idGenerator;
    int id;
protected:
public:
    /// Constructor
    Education(bool videoproiector = 0, bool ecranDeProiectie = 0, bool tablaSmart = 0) : Home(videoproiector, ecranDeProiectie, tablaSmart), id(++idGenerator) {}

    /// Destructor
    ~Education() {
        cout << "Destructor apelat pentru un obiect de tip education\n";
    }

    /// Metoda care returneaza o constanta, id
    const int getId() {
        return id;
    }

    /// Metoda care verifica daca o anume cerere de tip education este valida, returnand 1(true) in caz afirmativ si 0(false) in caz contrar
    const bool valid() const {
        if (tablaSmart == 0 && videoproiector == 1 && ecranDeProiectie == 1) {
            return 1;
        } else {
            return 0;
        }
    }
};

/// Initializam variabila statica idGenerator
int Education::idGenerator = 0;

int main() {
    /// Testam pe codul din cerinta
    Home h1, h2(1), h3(0, 0, 1);
    // cin >> h1;
    h2.Home_opreste("tabla");
    
    /// Adaugam alte teste, ca bonus
    cout << "\nBonus\n";
    /// Incercam blocul de instructiuni de mai jos, prinzand exceptia din metoda obiectului de tip Home in cazul in care exista
    try {
        h2.Home_opreste("videoproiector");
        h2.Home_opreste("ecran");
        h2.Home_opreste("tabla");
        h2.Home_opreste("ceva");
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    } catch(...) {
        cout << "Exception: unknown";
    }

    /// Afisam mesajele corespunzatoare validarii a trei comenzi: e1, e2, e3
    Education e1, e2(1, 1, 0), e3(0, 0, 1);
    if(e1.valid()) {
        cout << "Cererea de tip education #" << e1.getId() << " este valida\n";
    } else {
        cout << "Cererea de tip education #" << e1.getId() << " nu este valida\n";
    }
    if(e2.valid()) {
        cout << "Cererea de tip education #" << e2.getId() << " este valida\n";
    } else {
        cout << "Cererea de tip education #" << e2.getId() << " nu este valida\n";
    }
    if(e3.valid()) {
        cout << "Cererea de tip education #" << e3.getId() << " este valida\n";
    } else {
        cout << "Cererea de tip education #" << e3.getId() << " nu este valida\n";
    }

    return 0;
}

// - Barem 2016 septembrie (4.75)
//     - [x]  1p - oficiu (sursa compileaza)
//     - [x]  2p - ierarhie (identificarea claselor + atributelor)
//     - [x]  0.25p - const (pentru atribute, functii sau argumente la functii)
//     - [x]  0.25p - static (functii si atribute statice)
//     - [x]  0.25p - destructor virtual (folosit in toate locurile in care este necesar)
//     - [x]  0.25p - mostenire (reutilizare de cod, ex: apeleaza o functie a clasei de baza in momentul rescrierii ei in clasa derivata)
//     - [ ]  0.25p - abstract (exista o clasa abstracta)
//     - [ ]  0.25p - STL containers (vector, list, map, etc.)
//     - [ ]  0.25p - STL alte elemente (sort, transform, swap)
//     - [x]  0.25p - exceptia se propaga (nu poate fi tratata in acelasi loc de locul unde a fost aruncata)
//     - [x]  0.25p - exceptia este prinsa (tratarea cu sens a unei exceptii aruncate)
//     - [ ]  0.25p - RTTI (dynamic_cast, type_info)
//     - [ ]  0.25p - clasa Singleton
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
