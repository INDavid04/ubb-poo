/// 2025-08-16-09-45-11-20
/// 5 minutes over time
/// a lot of errors

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

/// Clasa abstracta
class Intrebare {
private:
protected:
    static int idIntrebareGenerator;
    int idIntrebare;
    string enunt, raspunsCorect;
    list<string> listaTaguri;
public:
    Intrebare(const string &enunt, const string &raspunsCorect, const list<string> &listaTaguri) {
        this->enunt = enunt;
        this->raspunsCorect = raspunsCorect;
        this->listaTaguri = listaTaguri;
        idIntrebare = ++idIntrebareGenerator;
    }

    /// Pentru intrebarea libera nu avem raspuns corect
    Intrebare(const string &enunt, const list<string> &listaTaguri) {
        this->enunt = enunt;
        this->listaTaguri = listaTaguri;
        idIntrebare = ++idIntrebareGenerator;
    }

    virtual ~Intrebare() {
        cout << "info: Intrebare distrusa\n";
    }

    virtual void afiseazaIntrebare() const = 0; /// functie virtuala pura
};

int Intrebare::idIntrebareGenerator = 0;

class IntrebareGrila : public Intrebare {
private:
    const int numarOptiuniDeRaspuns;
    const list<string> listaOptiuniDeRaspuns;
protected:
public:
    // IntrebareGrila(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const int numarOptiuniDeRaspuns, const list<string> &listaOptiuniDeRaspuns) : Intrebare(enunt, listaTaguri, raspunsCorect), numarOptiuniDeRaspuns(numarOptiuniDeRaspuns), listaOptiuniDeRaspuns(listaOptiuniDeRaspuns) {}

    ~IntrebareGrila() {
        cout << "info: Intrebare grila distrusa\n";
    }

    void afiseazaIntrebare() const override {
        cout << idIntrebare << ". " << enunt;
        char cnt = 'a';
        for (auto optiuneDeRaspuns : listaOptiuniDeRaspuns) {
            cout << "\n\t" << cnt++ << " - " << optiuneDeRaspuns;
        }
        cout << "\n";
    }
};

class IntrebareAdevaratSauFals : public Intrebare {
private:
    const bool raspuns;
protected:
public:  
    // IntrebareAdevaratSauFals(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const bool raspuns = "(A/F)") : Intrebare(enunt, listaTaguri, raspunsCorect), raspuns(raspuns) {}

    ~IntrebareAdevaratSauFals() {
        cout << "info: Intrebare adevarat sau fals distrusa\n";
    }

    void afiseazaIntrebare() const override {
        cout << idIntrebare << ". " << enunt << " " << raspuns << "\n";
    }
};

class IntrebarePereche : public Intrebare {
private:
    const vector<string> multimeA, multimeB;
protected:
public:  
    // IntrebarePereche(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const vector<string> &multimeA, const vector<string> &MultimeB) : Intrebare(enunt, listaTaguri, raspunsCorect), multimeA(multimeA), multimeB(multimeB) {}

    ~IntrebarePereche() {
        cout << "info: Intrebare pereche distrusa\n";
    }

    void afiseazaIntrebare() const override {
        cout << idIntrebare << ". " << enunt;
        char cntA = 'a';
        int cntB = 1, limit = 1;
        for (auto itemA : multimeA) {
            cout << "\n\t" << cntA++ << ". " << itemA;
            int cnt = 1;
            for (auto itemB : multimeB) {
                if (cnt == limit) {
                    cout << "\t" << cntB++ << ". " << itemB;
                    break;
                }
                cnt++;
            }
            limit++;
        }
        cout << "\n";
    }
};

class IntrebareLibera : public Intrebare {
private:
    const string raspuns;
protected:
public:
    IntrebareLibera(const string &enunt, const list<string> &listaTaguri, const string &raspuns) : Intrebare(enunt, listaTaguri), raspuns(raspuns) {}

    ~IntrebareLibera() {
        cout << "info: Intrebare pereche distrusa\n";
    }

    void afiseazaIntrebare() const override {
        cout << idIntrebare << ". " << enunt << "\n";
    }
};

class SingletonMenu {
private:
    static SingletonMenu *instanta;
    vector<Intrebare> *intrebari;

    SingletonMenu() {
        afiseazaOptiuni();
    }

    /// Q: De ce nu imi afiseaza mesajul?
    // ~SingletonMenu() {
    //     cout << "info: Eliberez memoria din SingletonMenu...\n";
    //     delete instanta;
    // }
protected:
public:
    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu();
        }
        return instanta;
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Adauga intrebare\n";
        cout << "2. Afiseaza toate intrebarile\n";
        cout << "3. Creeaza modul liber de antrenare\n";
        cout << "4. Creeaza modul de antrenare prin teste\n";
        cout << "5. Adauga mod de antrenare prin teste\n";
        cout << "6. Reafiseaza optiunile\n";
        cout << "7. Iesi din meniu\n";
    }

    void op1() {
        string tip;
        cout << "Adaug intrebare...\n";
        cout << "Tip (grila / adevarat sau fals / pereche / libera): ";
        getline(cin, tip);

        if (tip != "grila" && tip != "adevarat sau fals" && tip != "pereche" && tip != "libera") {
            throw invalid_argument("Tip intrebare invalid\n");
        } else if (tip == "grila") {
            // IntrebareGrila(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const int numarOptiuniDeRaspuns, const list<string> &listaOptiuniDeRaspuns)
            string enunt, raspunsCorect;
            int numarOptiuniDeRaspuns;
            list<string> listaTaguri, listaOptiuniDeRaspuns;
            cout << "Enunt: ";
            getline(cin, enunt);
            string raspuns, tag;
            do {
                cout << "Tag: ";
                getline(cin, tag);
                listaTaguri.push_back(tag);
                cout << "Inca unul (da/nu): ";
                getline(cin, raspuns);
            } while (raspuns == "da");
            cout << "Raspuns corect: ";
            getline(cin, raspunsCorect);
            cout << "Numar optiuni de raspuns: ";
            cin >> numarOptiuniDeRaspuns;
            cin.get();
            char cnt = 'a';
            string optiuneDeRaspuns;
            for (int i = 0; i < numarOptiuniDeRaspuns; i++) {
                cout << cnt++ << ": ";
                getline(cin, optiuneDeRaspuns);
                listaOptiuniDeRaspuns.push_back(optiuneDeRaspuns);
            }
            // intrebari->push_back(new IntrebareGrila(enunt, listaTaguri, raspunsCorect, numarOptiuniDeRaspuns, listaOptiuniDeRaspuns));
        } else if (tip == "adevarat sau fals") {
            /// IntrebareAdevaratSauFals(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const bool raspuns = "(A/F)")
            string enunt;
            const list<string> listaTaguri;
            cout << "Enunt: ";
            getline(cin, enunt);
            string raspuns, tag;
            do {
                cout << "Tag: ";
                getline(cin, tag);
                // listaTaguri.push_back(tag);
                cout << "Inca unul (da/nu): ";
                getline(cin, raspuns);
            } while (raspuns == "da");
            cout << "Raspuns corect: ";
            string raspunsCorect;
            getline(cin, raspunsCorect);
            // intrebari.push_back(enunt, listaTaguri, raspunsCorect);
        } else if (tip == "pereche") {
            /// IntrebarePereche(const string &enunt, const list<string> &listaTaguri, const string &raspunsCorect, const vector<string> &multimeA, const vector<string> &MultimeB)

        } else { /// tip == "libera"
            /// IntrebareLibera(const string &enunt, listaTaguri, const string &raspuns)

        }
    }

    void op2() const {
        cout << "Afisez intrebarile...\n";
    }
    
    void op3() {
        cout << "Creez modul liber de antrenare...\n";
    }
    
    void op4() {
        cout << "Creez modul de antrenare prin teste...\n";
    }
    
    void op5() {
        cout << "Adaug modul de antrenare prin teste...\n";
    }

    void op6() const {
        cout << "Reafisez optiunile...\n";
        afiseazaOptiuni();
    }
    
    void op7() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu *m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 7) {
                throw out_of_range("Optiune invalida\n");
            }

            switch (optiune) {
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
        cout << "Out of range exception: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument exception: " << e.what();
    }

    return 0;
}

// - Barem 2025 iulie (5.5)
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
//     - [x]  0.25p - ID incrementat automat in constructor
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
