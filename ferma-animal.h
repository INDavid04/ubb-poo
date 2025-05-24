#include <iostream>
#include <set> /// STL
using namespace std;

class Animal {
private:
protected:
    const char* numeStapan;
public:
    Animal (const char* numeStapanInitial = "Ion") {
        numeStapan = numeStapanInitial;
    }
    virtual void faceZgomot() {
        cout << "Te ia cu intristare vazandu-l gol si incepi sa iti cauti de treaba!\n";
    }
};

/// Cal fiind o clasa abstracta, nu poate fi instantiata direct cu `new Cal()`
class Cal : public Animal {
public:
    void faceZgomot() {
        /// Putem folosi variabila numeStapan intrucat e declarata in clasa de baza in zona protected, iar tipul mosternirii este public, ceea ce face sa ramana protected
        cout << "Caii se uita la " << numeStapan << ", astepand un mar!\n";
    }
    virtual void afiseazaDescriere() = 0; /// fiind functie virtuala pura, clasa cal devine o clasa abstracta
};

class Arab : public Cal {
public:
    void afiseazaDescriere() override {
        cout << "[Caleb Iosua]: Calul dvs. este un cal arab de culoare alba la 450kg si inaltime de 1.5m.\n";
    }
};

class Mustang : public Cal {
public:
    void afiseazaDescriere() override {
        cout << "[Caleb Iosua]: Calul dvs. este un mustang de culoare alb-maro la 400kg si inaltime de 1.3m.\n";
    }
};

class Frizon : public Cal {
public:
    void afiseazaDescriere() override {
        cout << "[Caleb Iosua]: Calul dvs. este un frizon de culoare neagra la 730kg si inaltime de 1.6m.\n";
    }
};

class Porc : public Animal {
public:
    void faceZgomot() {
        /// Aceeasi poveste ca mai sus
        cout << "Un porc da navala peste " << numeStapan << " trantindu-l la pamant.\n";
    }
};
