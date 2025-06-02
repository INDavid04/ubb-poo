/*
Irimia David - Grupa 141
g++ .\141_Irimia_David.cpp -o ./e.exe
./e.exe
Radu Tudor Vrinceanu
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

/// Clasa Produs este o clasa abstracta intrucat contine metoda afiseazaProdus() care este o metoda virtuala pura
class Produs {
private:
    string nume;
    double gramaj;
protected:
    double valoareEnergie;
public:
    /// Metoda virtuala pura
    virtual void afiseazaProdus() const = 0;
};

class Comanda {
private:
    static int idGenerator;
    int id;
    list<Produs*> produse;
protected:
public:
    /// Constructor fara parametrii
    Comanda() {
        id = idGenerator++;
    }
    int getId() const {
        return id;
    }
    void adaugaProdus(Produs* p) {
        produse.push_back(p);
    }
    void afiseazaProduse() const {
        /// Pargurgem lista de produse si afisam fiecare produs in parte
        for (Produs* p : produse) {
            p->afiseazaProdus();
        }
    }
};

int Comanda::idGenerator = 1;

class Angajat {
private:
    list<Comanda*> comenzi;
    int energie;
protected:
public:
};

class Bautura : public Produs {
private:
    bool eLaSticla;
protected:
public:
    /// Constructor cu parametrii (inline)
    Bautura(bool eLaSticla = false) : eLaSticla(eLaSticla) {}
    void afiseazaProdus() const {
        /// Verficam daca este sau nu la sticla
        if (eLaSticla) {
            cout << "O bautura care e la stica\n";
        } else {
            cout << "O bautura care nu e la sticla\n";
        }
    }
};


class Desert : public Produs {
private:
    string formatulServirii; /// felie, cupa sau portie
protected:
public:
    /// Constructor cu parametru
    Desert(string formatulServirii = "") {
        this->formatulServirii = formatulServirii;
    }
    void afiseazaProdus() const {
        cout << "Un desert servit ca o " << formatulServirii << "\n";
    }
};

class Burger : public Produs {
private:
    string ingrediente; /// rosii, varza, etc.
protected:
public:
    Burger(string ingrediente = "") {
        this->ingrediente = ingrediente;
    }
    void afiseazaProdus() const {
        cout << "Un burger cu " << ingrediente << "\n";
    }
};

class Livrator : public Angajat {
private:
protected:
public:
};

class Bucatar : public Angajat {
private:
protected:
public:
};

class Casier : public Angajat {
private:
protected:
public:
};

int main() {
    int optiune;
    /// Meniu interactiv
    do {
        cout << "Apasa 1 pentru a afisa numarul de angajati pentru fiecare tip in parte\n";
        cout << "Apasa 2 pentru a implementa simularea si pentru a afisa un ciclu\n";
        cout << "Apasa 3 pentru a creea o optiune ca intre cicluri sa poti selecta comenzi care sunt prioritare\n";
        cout << "Apasa 4 pentru a optimiza ciclul\n";
        cout << "Apasa 5 pentru a selecta strategia de alegere a comenzilor care sunt preparate\n";
        cout << "Apasa 0 pentru a termina complet\n";
        cin >> optiune;
        /// Verificam optiunea selectata
        if (optiune == 0) {
            /// Asta inseamna ca utilizatorul a ales sa iasa
            cout << "Iesire...\n";
        } else if (optiune == 1) {
            cout << "Ai ales sa afisezi numarul de angajati pentru fiecare tip in parte\n";
        } else if (optiune == 2) {
            Comanda c;
            int adaugaComanda;
            cout << "Ai ales sa implementezi simularea si pentru a afisa un ciclu\n";
            do {
                cout << "Adaugare comanda? (1/0): ";
                try {
                    cin >> adaugaComanda;
                    throw adaugaComanda;
                } catch (int adaugaComanda) {
                    if (adaugaComanda == 0){
                        break;
                    } else if (adaugaComanda == 1) {
                        string denumireProdus;
                        cout << "Adauga la comanda (bautura/desert/burger): ";
                        cin >> denumireProdus;
                        if (denumireProdus == "bautura") {
                            bool eLaSticla;
                            cout << "Ai ales sa adaugi o bautura\n";
                            cout << "Scrie 1 daca vrei sa fie la sticla sau 0 daca nu vrei sa fie la sticla: ";
                            cin >> eLaSticla;
                            c.adaugaProdus(new Bautura (eLaSticla));
                        } else if (denumireProdus == "desert") {
                            string formatulServirii;
                            cout << "Ai ales sa adaugi un desert\n";
                            cout << "Scrie formatul servirii (felie/cupa/portie): ";
                            cin >> formatulServirii;
                            c.adaugaProdus(new Desert (formatulServirii));
                        } else if (denumireProdus == "burger") {
                            string ingrediente;
                            cout << "Ai ales sa adaugi un burger\n";
                            cout << "Scrie ingrediente (de exemplu: rosii, varza; recomandare: scrie un singur ingredient): ";
                            cin >> ingrediente;
                            cin.get();
                            c.adaugaProdus(new Burger (ingrediente));
                        } else {
                            cout << "Nu pricep ce vrei sa adaugi! Alege intre bautura, desert, burger!\n";
                        }
                    } else {
                        cout << "Nu pricep ce vrei sa fac. Data viitoare alege intre 1 si 0!\n";
                        break;
                    }
                }
            } while (adaugaComanda);
            cout << "Comanda cu id-ul " << c.getId() << " are: \n";
            c.afiseazaProduse();
        } else if (optiune == 3) {
            cout << "Ai ales sa creezi o optiune ca intre cicluri sa poti selecta comenzi care sunt prioritare\n";
        } else if (optiune == 4) {
            cout << "Ai ales sa optimizezi ciclul";
        } else if (optiune == 5) {
            cout << "Ai ales sa selectezi strategia de alegere a comenzilor care sunt preparate\n";
        } else {
            cout << "Nu inteleg ce vrei sa faci. Alege o cifra cuprinsa intre 0 si 5\n";
        }
    } while (optiune);

    return 0;
}
