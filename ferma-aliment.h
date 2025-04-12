#include <iostream>
#include <cstring>
using namespace std;

class Aliment {
protected:
    char* nume;
    int calorii;
public:
    Aliment(const char* numeInitial = "aer", int caloriiInitiale = 0) {
        nume = new char[strlen(numeInitial) + 1];
        strcpy(nume, numeInitial);
        calorii = caloriiInitiale;
    }

    virtual void afiseaza() {
        cout << "Alimentul " << nume << " are " << calorii << " calorii.\n";
    }

    virtual ~Aliment() {
        delete[] nume;
    }

    const char* getNume() const {
        return nume;
    }

    int getCalorii() const {
        return calorii;
    }
};

class Faina : virtual public Aliment {
protected:
    const char* numeFaina = "faina";
    int caloriiFaina = 300;
public:
    Faina() : Aliment() {}

    void afiseaza() {
        cout << "Primul ingredient este alimentul " << numeFaina << " care are " << caloriiFaina << " calorii.\n";
    }

    int getCalorii() const {
        return caloriiFaina;
    }
};

class Branza : virtual public Aliment {
protected:
    const char* numeBranza = "branza";
    int caloriiBranza = 250;
public:
    Branza() : Aliment() {}

    void afiseaza() {
        cout << "Al doilea ingredient este alimentul " << numeBranza << " care are " << caloriiBranza << " calorii.\n";
    }

    int getCalorii() const {
        return caloriiBranza;
    }
};

class Placinta : public Faina, public Branza {
public:
    Placinta() {
        delete[] nume;
        nume = new char[strlen("placinte cu branza") + 1];
        strcpy(nume, "placinte cu branza");
        calorii = Faina::getCalorii() + Branza::getCalorii();
    }

    void afiseaza() {
        cout << "Pentru reteta ai nevoie de cateva ingrediente:\n";
        Faina::afiseaza();
        Branza::afiseaza();
        cout << "Conform nutritionistului, reteta " << nume << " are un total de " << calorii << " calorii.\n";
    }
};
