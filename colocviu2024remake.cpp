/* Irimia David 141
g++ ./141_Irimia_David.cpp -o ./e.exe
Radu Tudor Vrinceanu */

/// 2025-05-31-1320-1447 First session
/// 2025-05-31-2025-2223 Second session

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/// Clasa abstracta deoarece contine cel putin o metoda virtuala pura
class Element {
private:
    /// Folosim doua variabile pentru a da un id unic fiecarui element: idGenerator e static int pentru a fi comun tuturor instantelor clasei Element
    static int idGenerator;
    int id;
protected:
public:
    /// Incrementam idGenerator la fiecare constructie, astfel urmatorul obiect construit va avea id-ul cu unu mai mare fata de precedentul
    Element() : id(idGenerator++) {}
    int getId() const {
        return id;
    }
    /// Metoda virtuala pura
    virtual void afiseaza() const = 0;
};
int Element::idGenerator = 1;

class Zid : public Element {
private:
    double inaltime, lungime, grosime;
protected:
public:
    /// Constructor cu toti parametrii
    Zid(double inaltime = 0, double lungime = 0, double grosime = 0) {
        this->inaltime = inaltime;
        this->lungime = lungime;
        this->grosime = grosime;
    }
    /// Afisam detalii despre element
    void afiseaza() const override {
        cout << "Element: Zid; Inaltime: " << inaltime << "m; Lungime: "  << lungime << "m; Grosime: " << grosime << "m\n"; 
    }
};

class Turn : public Element {
private:
    int putereaRazei;
protected:
public:
    /// Constructor cu toti parametrii, in cazul asta numai unul
    Turn(int putereaRazei = 0) {
        this->putereaRazei = putereaRazei;
    }
    /// Afisam detalii despre element
    void afiseaza() const override {
        cout << "Element: Turn; PutereRazei: " << putereaRazei << "kw\n"; 
    }
};

class Robot : public Element {
private:
protected:
    int damage, nivel, viata;
    bool areScut;
public:
    /// Constructor cu toti parametrii
    Robot(int nivel, int damage, int viata) : nivel(nivel), damage(damage), viata(viata) {}
};

class RobotAerian : public Robot {
private:
    int autonomie;
protected:
public:
    /// Constructor cu toti parametrii
    RobotAerian(int nivel, int damage, int viata, int autonomie = 0) : Robot(nivel, damage, viata), autonomie(autonomie) {}
    /// Afisam detalii despre element
    void afiseaza() const override {
        cout << "Element: RobotAerian; Nivel: " << nivel << "; Damage: " << damage << "; Viata: " << viata << "; Autonomie: " << autonomie << " ore\n"; 
    }
};

class RobotTerestru : public Robot {
private:
    int gloante;
protected:
public:
    /// Constructor cu toti parametrii
    RobotTerestru(int nivel, int damage, int viata, int gloante) : Robot(nivel, damage, viata) {
        this->nivel = nivel;
        this->damage = damage;
        this->viata = viata;
        this->gloante = gloante;
    }
    /// Afisam detalii despre element
    void afiseaza() const override {
        cout << "Element: RobotTerestru; Nivel: " << nivel << "; Damage: " << damage << "; Viata: " << viata << "; Gloante: " << gloante << "\n"; 
    }
};

class Jucator {
private:
    int puncte;
    vector<Element*> inventar;
protected:
public:
    /// Constructor cu toti parametrii
    Jucator(int puncte = 10000) {
        this->puncte = puncte;
    }
    /// Getter folosit pentru a verifica buget
    int getPuncte() const {
        return puncte;
    }
    /// Adaugam elementul in inventar
    void adauga(Element* e, int puncteMinus = 0) {
        inventar.push_back(e);
        puncte -= puncteMinus;
        cout << "Dupa achizitie ati ramas cu " << puncte << " puncte\n";
    }
    /// Afisam detalii despre element
    void afiseazaElemente() {
        cout << "DEBUG: Numar elemente: " << inventar.size() << "\n";
        for (Element* e : inventar) {
            cout << "ID: " << e->getId() << "; ";
            e->afiseaza();
        }
    }
    /// Destructor, evitam memory leaks
    ~Jucator() {
        for (Element* e : inventar) {
            delete e;
        }
    }
};

int main() {
    /// Jucatorul pleaca cu 50000 puncte
    Jucator* j = new Jucator (50000);
    int optiune;
    do {
        cout << "Scrie 1 pentru a adauga un element\n";
        cout << "Scrie 2 pentru a upgrada un element\n";
        cout << "Scrie 3 pentru a afisa elementele din inventar crescator dupa costul de upgrade\n";
        cout << "Scrie 4 pentru a afisa elementele din inventar de tip robot\n";
        cout << "Scrie 5 pentru a vinde un element in schimbul a 500 puncte\n";
        cout << "Scrie 0 pentru a iesi de aici\n";
        cin >> optiune;
        /// Meniu interactiv
        if (optiune == 0) {
            cout << "Iesire...\n";
        } else if (optiune == 1) {
            string numeElement;
            cout << "Ai ales sa adaugi un element\n";
            cout << "Iata ce poti alege: zid la 300 puncte, turn la 500 puncte, robot_aerian la 100 puncte, robot_terestru la 50 puncte\nScrie unul dintre urmatoarele elemente: zid, turn, robot_aerian, robot_terestru\n";
            cin >> numeElement;
            /// Verificam daca jucatorul isi permite elementul si exista vreun astfel de element
            if (numeElement == "zid" && j->getPuncte() >= 300) {
                cout << "Ai ales sa adaugi un zid\n";
                Element* e = new Zid (1, 1, 0.5);
                /// Adaugam zidul si scadem 300 din totalul punctelor
                j->adauga(e, 300);
            } else if (numeElement == "turn" && j->getPuncte() >= 500) {
                cout << "Ai ales sa adaugi un turn\n";
                Element* e = new Turn (1000);
                /// Adaugam turnul si scadem 500 din totalul punctelor
                j->adauga(e, 500);
            } else if (numeElement == "robot_aerian" && j->getPuncte() >= 100) {
                cout << "Ai ales sa adaugi un robot aerian\n";
                Element* e = new RobotAerian (1, 100, 100, 10);
                /// Adaugam robotul aerian si scadem 100 din totalul punctelor
                j->adauga(e, 100);
            } else if (numeElement == "robot_terestru" && j->getPuncte() >= 50) {
                cout << "Ai ales sa adaugi un robot terestru\n";
                Element* e = new RobotTerestru (1, 100, 100, 500);
                /// Adaugam robotul terestru si scadem 50 din totalul punctelor
                j->adauga(e, 50);
            } else {
                cout << "Nu pot adauga elemntul: fie nu iti ajung banii, fie nu ai scris la fel ca mai sus\n";
            }
        } else if (optiune == 2) {
            cout << "Ai ales sa upgradezi un element\n";
        } else if (optiune == 3) {
            cout << "Ai ales sa afisezi elementele din inventar crescator dupa costul de upgrade\n";
            /// Inventarul apartine jucatorului. De aceea, apelam functia afiseazaElemente din clasa Jucator
            j->afiseazaElemente();
        } else if (optiune == 4) {
            cout << "Ai ales sa afisezi elementele din inventar de tip robot\n";
        } else if (optiune == 5) {
            cout << "Ai ales sa vinzi un element in schimbul a 500 puncte\n";
        } else {
            throw "Nu pricep ce vrei sa faci. Alege un numar cuprins intre zero si cinci!\n";
        }
    } while (optiune);

    /// Evitam memory leaks
    delete j;

    return 0;
}
