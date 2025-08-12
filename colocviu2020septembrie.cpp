// 2025-08-12-12-00-12-50

#include <iostream>
#include <vector>
#include <list>
#include <string>
// #include <stdexception>

using namespace std;

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
    // virtual ~Produs const {
    //     cout << "Produsul cu id-ul: " << idProdus << " a fost scos\n";
    // }
};
int Produs::idGenerator = 0;

class Carte : public Produs {
private:
    string titlu;
    vector<string> autori;
    string editura;
protected:
public:
    Carte(string titlu, string* autori, string editura) : Produs::idProdus(++idGenerator), pret(pret), cantitate(cantitate), titlu(titlu), autori(autori), editura(editura) {}
};

class DVD : public Produs {
private:
    int minute;
protected:
public:
    DVD(int minute) : minute(minute) {}
};

class DVDMuzica : public DVD {
private:
    string album;
    vector<string> interpreti;
protected:
public:
    DVDMuzica(string album, string* interpreti) : album(album), interpreti(interpreti) {}
};

class DVDFilme : public DVD {
private:
    string film, gen;
protected:
public:  
    DVDFilme(string film, string gen) : film(film), gen(gen) {}
};

class ObiectColectie : public Produs {
private:
    string denumire;
protected:
public:
    ObiectColectie(string denumire) : denumire(denumire) {}
};

class Figurina : public ObiectColectie {
private:
    string categorie; /// muzica, film, jocuri, video, etc.
    string brand, material;
protected:
public:
    Figurina(string categorie, string brand, string material) : categorie(categorie), brand(brand), material(material) {}
};

class Poster : public ObiectColectie {
private:
    string format; /// A3, A4, etc.
protected:
public:
    Poster(string format) : format(format) {}
};

class MeniuSingleton {
private:
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
        if(instanta == NULL) {
            instanta = new MeniuSingleton;
        }
        return instanta;
    }
    void op1() {
        cout << "Citesc n produse...\n";
    }
    void op2() {
        cout << "Afisez produsele citite...\n";
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

MeniuSingleton* MeniuSingleton::instanta;

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
