/* Irimia David 141
g++ ./141_Irimia_David.cpp -o ./e.exe
Radu Tudor Vrinceanu */

// 2025-05-31-1320-1447

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Element {
private:
    int id;
protected:
public:
    int getId() const {
        return id;
    }
    // virtual void afiseaza() = 0;
    virtual ~Element() {
        cout << "Element distrus\n";
    } 
};

class Zid : public Element {
private:
    double inaltime, lungime, grosime;
protected:
public:
    Zid(double inaltime = 0, double lungime = 0, double grosime = 0) {
        this->inaltime = inaltime;
        this->lungime = lungime;
        this->grosime = grosime;
    }
    void afiseaza() const {
        cout << "Element: Zid; Inaltime = " << inaltime << "; Lungime = "  << lungime << "; Grosime = " << grosime << "\n"; 
    }
};

class Turn : public Element {
private:
    int putereaRazei;
protected:
public:
    Turn(int putereaRazei = 0) {
        this->putereaRazei = putereaRazei;
    }
    void afiseaza() const {
        cout << "Element: Turn; PutereRazei = " << putereaRazei << "\n"; 
    }
};

class Robot : public Element {
private:
    int damage, nivel, viata;
    bool areScut;
protected:
public:
};

class RobotAerian : public Robot {
private:
    int autonomie;
protected:
public:
    void afiseaza() const {
        cout << "Element: RobotAerian; Autonomie = " << autonomie << "\n"; 
    }
};

class RobotTerestru : public Robot {
private:
    int gloante;
protected:
public:
    void afiseaza() const {
        cout << "Element: RobotTerestru; Gloante = " << gloante << "\n"; 
    }
};

class Jucator {
private:
    int puncte;
    vector<Element*> inventar;
protected:
public:
    Jucator(int puncte = 10000) {
        this->puncte = puncte;
    }
    int getPuncte() const {
        return puncte;
    }
    void adauga(Element* e) {
        inventar.push_back(e);
    }
    void afiseazaElemente() {
        for (Element* e : inventar) {
            // cout << "ID: " << e->getId << "; ";
            // e->afiseaza();
        }
    }
    ~Jucator() {
        for (Element* e : inventar) {
            delete e;
        }
    }
};

int main() {
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
        if (optiune == 0) {
            cout << "Iesire...\n";
        } else if (optiune == 1) {
            string numeElement;
            cout << "Ai ales sa adaugi un element\n";
            cout << "Iata ce poti alege: zid la 300 puncte, turn la 500 puncte, robot_aerian la 100 puncte, robot_terestru la 50 puncte\nScrie unul dintre urmatoarele elemente: zid, turn, robot_aerian, robot_terestru\n";
            cin >> numeElement;
            if (numeElement == "zid" && j->getPuncte() >= 300) {
                cout << "Ai ales sa adaugi un zid\n";
                Element* e = dynamic_cast <Element*> (new Zid (1, 1, 0.5));
                j->adauga(e);
            } else if (numeElement == "turn" && j->getPuncte() >= 500) {
                cout << "Ai ales sa adaugi un turn\n";
            } else if (numeElement == "robot_aerian" && j->getPuncte() >= 100) {
                cout << "Ai ales sa adaugi un robot aerian\n";
            } else if (numeElement == "robot_terestru" && j->getPuncte() >= 50) {
                cout << "Ai ales sa adaugi un robot terestru\n";
            } else {
                cout << "Nu pot adauga elemntul: fie nu iti ajung banii, fie nu ai scris la fel ca mai sus\n";
            }
        } else if (optiune == 2) {
            cout << "Ai ales sa upgradezi un element\n";
        } else if (optiune == 3) {
            cout << "Ai ales sa afisezi elementele din inventar crescator dupa costul de upgrade\n";
            j->afiseazaElemente();
        } else if (optiune == 4) {
            cout << "Ai ales sa afisezi elementele din inventar de tip robot\n";
        } else if (optiune == 5) {
            cout << "Ai ales sa vinzi un element in schimbul a 500 puncte\n";
        } else {
            cout << "Nu pricep ce vrei sa faci. Alege un numar cuprins intre zero si cinci!\n";
        }
    } while (optiune);

    delete j;

    return 0;
}
