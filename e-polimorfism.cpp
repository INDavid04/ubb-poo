/// TODO: Understand polymorphism up casting and down casting 

#include <iostream>
using namespace std;

/// 1. Polimorfism (dinamic & static)

/// Problema 1: Afisare animale
/// Cerinta: Creeaza o clasa de baza Animal cu o metoda virtuala sunet(). Deriveaza clasele Caine si Pisica, fiecare cu propria implementare de sunet(). Creeaza o functie care primeste un Animal* si apeleaza sunet() - observa comportamentul polimorf.
class Animal {
private:
protected:
public:
    virtual void sunet() = 0;
};

class Caine : public Animal {
private:
protected:
public:
    void sunet() {
        cout << "Cainele face \"Ham! Ham!\"\n";
    }
};

class Pisica : public Animal {
private:
protected:
public:
    void sunet() {
        cout << "Pisica face \"Miau! Miau!\"\n";
    }
};

int main() {
    /// error: cannot declare variable 'a' to be of abstract type 'Animal'
    // Animal a;
    // a.sunet(); 

    /// Varianta primitiva
    // Caine c;
    // c.sunet(); /// out: Cainele face "Ham! Ham!"
    // Pisica p;
    // p.sunet(); /// out: Pisica face "Miau! Miau!"

    /// error: invalid abstract type 'Animal' for 'a'
    // Animal a[2]; /// creeaza doua obiecte de tip Animal
    // a[1] = new Caine();
    // a[2] = new Pisica();
    // for (int i = 0; i < 2; i++) {
    //     a[i].sunet();
    //     delete a[i];
    // }

    /// Array de elemente de tip Animal
    Animal* a[2]; /// creeaza doi pointeri catre obiecte de clase derivate (Caine sau Pisica)
    a[0] = new Caine();
    a[1] = new Pisica();
    for (int i = 0; i < 2; i++) {
        a[i] -> sunet(); /// polimorfismul
        delete a[i];
    }
    /// Diagrama: `Animal* a[2]; // Array de pointeri`
    ///
    /// +---------+            +-------------+
    /// | a[0] ---|----------> |  Caine      |
    /// +---------+            +-------------+
    /// 
    /// +---------+            +-------------+
    /// | a[1] ---|----------> |  Pisica     |
    /// +---------+            +-------------+

    return 0;
}