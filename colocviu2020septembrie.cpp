// 2025-08-12-12-00-12-50

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>

using namespace std;

/// Clasa abstracta
class Produs {
private:
protected:
    double pret;
    int cantitate;
    int idProdus;
    static int idGenerator;
public:
    Produs(double pret, int cantitate) {
        this->pret = pret;
        this->cantitate = cantitate;
        idProdus = ++idGenerator;
    }

    virtual ~Produs() {
        cout << "Produsul cu id-ul: " << idProdus << " a fost scos\n";
    }

    virtual void afiseaza() = 0; /// functie virtuala pura
};
int Produs::idGenerator = 0;

class Carte : public Produs {
private:
    string titlu;
    vector<string> autori;
    string editura;
protected:
public:
    Carte(double pret, int cantitate, const string &titlu, const vector<string> &autori, const string &editura) : Produs(pret, cantitate), titlu(titlu), autori(autori), editura(editura) {}

    void afiseaza() const override {
        cout << idProdus << ". " << pret << ", " << cantitate << ", " << titlu << ", ";
        for (auto autor : autori) {
            cout << autor << ", ";
        }
        cout << editura << "\n";
    }
};

class DVD : public Produs {
private:
    int minute;
protected:
public:
    DVD(double pret, int cantitate, int minute) : Produs(pret, cantitate), minute(minute) {}

    virtual void afiseaza() = 0;
};

class DVDMuzica : public DVD {
private:
    string album;
    vector<string> interpreti;
protected:
public:
    DVDMuzica(double pret, int cantitate, int minute, const string &album, const vector<string> &interpreti) : DVD(pret, cantitate, minute), album(album), interpreti(interpreti) {}

    void afiseaza() const override {
        cout << idProdus << ". " << pret << ", " << cantitate << ", " << minute << ", " << album;
        for (auto interpret : interpreti) {
            cout << ", " << interpret;
        }
        cout << "\n";
    }
};

class DVDFilme : public DVD {
private:
    string film, gen;
protected:
public:  
    DVDFilme(double pret, int cantitate, int minute, const string &film, const string &gen) : DVD(pret, cantitate, minute), film(film), gen(gen) {}

    void afiseaza() const override {
        cout << idProdus << ". " << pret << ", " << cantitate << ", " << minute << ", " << film << ", " << gen << "\n";
    }
};

class ObiectColectie : public Produs {
private:
    string denumire;
protected:
public:
    ObiectColectie(double pret, int cantitate, const string &denumire) : Produs(pret, cantitate), denumire(denumire) {}

    virtual void afiseaza() = 0;
};

class Figurina : public ObiectColectie {
private:
    string categorie; /// muzica, film, jocuri, video, etc.
    string brand, material;
protected:
public:
    Figurina(double pret, int cantitate, const string &denumire, const string &categorie, const string &brand, const string &material) : ObiectColectie(pret, cantitate, denumire), categorie(categorie), brand(brand), material(material) {}

    void afiseaza() const override {
        cout << idProdus << ". " << pret << ", " << cantitate << ", " << denumire << ", " << categorie << ", " << brand << ", " << material << "\n";
    }
};

class Poster : public ObiectColectie {
private:
    string format; /// A3, A4, etc.
protected:
public:
    Poster(double pret, int cantitate, const string &denumire, const string &format) : ObiectColectie(pret, cantitate, denumire), format(format) {}

    void afiseaza() const override {
        cout << idProdus << ". " << pret << ", " << cantitate << ", " << denumire << ", " << format << "\n";
    }
};

class MeniuSingleton {
private:
    list<Produs*> listaProduse;
    static MeniuSingleton* instanta;
    vector<Produs*> v;
    MeniuSingleton() {
        cout << "Alege optiunea [1-7]:\n";
        cout << "1. Citeste n produse\n";
        cout << "2. Afiseaza produsele citite\n";
        cout << "3. Editeaza un produs\n";
        cout << "4. Ordoneaza crescator produsele dupa pret\n";
        cout << "5. Cauta o carte dupa titlu\n";
        cout << "6. Afiseaza produsul cu cea mai mare cantitate disponibila\n";
        cout << "7. Iesi din meniu\n";
    }
protected:
public:
    static MeniuSingleton* getInstanta() {
        if(instanta == nullptr) {
            instanta = new MeniuSingleton;
        }
        return instanta;
    }
    void op1() {
        cout << "Citesc n produse...\n";
        int n;
        cout << "n: "; cin >> n; cin.get();
        for (int i = 0; i < n; i++) {
            string tip;
            cout << "Tip produs (carte/dvd_muzica/dvd_filme/figurina/poster): "; cin >> tip; cin.get();

            double pret;
            int cantitate;
            cout << "Pret: "; cin >> pret; cin.get();
            cout << "Cantitate: "; cin >> cantitate; cin.get();

            if (tip == "carte") {
                string titlu, editura, raspuns;
                vector<string> autori;
                cout << "Titlu: "; cin >> titlu; cin.get();
                do {
                    string autor;
                    cout << "Autor: "; cin >> autor; cin.get();
                    autori.push_back(autor);
                    cout << "Mai adaugi un autor? (da/nu): "; cin >> raspuns; cin.get();
                } while (raspuns == "da");
                cout << "Editura: "; cin >> editura; cin.get();
                listaProduse.push_back(Carte(pret, cantitate, titlu, autori, editura));
            } else if (tip == "dvd_muzica") {
                int minute;
                string album, raspuns;
                vector<string> interpreti;
                cout << "Minute: "; cin >> minute; cin.get();
                cout << "Album: "; cin >> album; cin.get();
                do {
                    string interpret;
                    cout << "Interpret: "; cin >> interpret; cin.get();
                    interpreti.push_back(interpreti);
                    cout << "Mai adaugi un interpret? (da/nu): "; cin >> raspuns; cin.get();
                } while (raspuns == "da");
                listaProduse.push_back(DVDMuzica(pret, cantitate, minute, album, interpreti));
            } else if (tip == "dvd_filme") {
                int minute;
                string film, gen;
                cout << "Minute: "; cin >> minute; cin.get();
                cout << "Film: "; cin >> film; cin.get();
                cout << "Gen: "; cin >> gen; cin.get();
                listaProduse.push_back(DVDFilme(pret, cantitate, minute, film, gen));
            } else if (tip == "figurina") {
                string denumire, categorie, brand, material;
                cout << "Denumire: "; cin >> denumire; cin.get();
                cout << "Categorie: "; cin >> categorie; cin.get();
                cout << "Brand: "; cin >> brand; cin.get();
                cout << "Material: "; cin >> material; cin.get();
                listaProduse.push_back(Figurina(pret, cantitate, denumire, categorie, brand, material));
            } else if (tip == "poster") {
                string denumire, format;
                cout << "Denumire: "; cin >> denumire; cin.get();
                cout << "Format: "; cin >> format; cin.get();
                listaProduse.push_back(Poster(pret, cantitate, denumire, format));
            } else {
                cout << "Nu exista produsul: " << tip << ". Prin urmare, lista ramane la fel.\n";
            }
        }
    }
    void op2() {
        cout << "Afisez produsele citite...\n";
        for (auto produs : listaProduse) {
            produs.afiseaza();
        }
    }
    void op3() {
        cout << "Editez un produs...\n";
    }
    void op4() {
        cout << "Ordonez crescator produsele dupa pret...\n";
    }
    void op5() {
        cout << "Caut o carte dupa titlu...\n";
    }
    void op6() {
        cout << "Afisez produsul cu cea mai mare cantitate disponibila...\n";
    }
    void op7() {
        cout << "Ies din meniu...\n";
    }
};

MeniuSingleton* MeniuSingleton::instanta = nullptr;

int main() {
    int optiune;
    MeniuSingleton* m;
    m = MeniuSingleton::getInstanta();

    do {
        try {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();
            if (optiune < 1 || optiune > 7) {
                throw "Optiunea nu exista. Alege intre 1 si 7!\n";
            }
            if (optiune == 1) {
                m->op1();
            } else if (optiune == 2) {
                m->op2();
            } else if (optiune == 3) {
                m->op3();
            } else if (optiune == 4) {
                m->op4();
            } else if (optiune == 5) {
                m->op5();
            } else if (optiune == 6) {
                m->op6();
            } else if (optiune == 7) {
                m->op7();
            }

        } catch (const char* errorString) {
            cout << errorString;
        }
    } while (optiune != 7);

    return 0;
}
