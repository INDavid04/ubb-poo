/// TODO: Understand polymorphism up casting and down casting 

#include <iostream>
using namespace std;

/////////////////////////////////////////
/// 1. Polimorfism (dinamic & static) ///
/////////////////////////////////////////

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

/// Problema 2: Forme geometrice
/// Cerinta: Creeaza o clasa Forma cu metoda virtuala arie(). Deriveaza clasele Patrat si Cerc si implementeaza calculul ariei. Creeaza un vector de pointeri la Forma si afiseaza aria fiecareia - observa cum metodele virtuale permit comportament diferit la acelasi apel.

class Forma {
private:
protected:
    int dimensiune;
public:
    Forma(int dimensiune = 0) {
        this->dimensiune = dimensiune;
    }
    virtual void arie() = 0;
};

class Patrat : public Forma {
private:
protected:
public:
    Patrat(int dim) : Forma(dim) {} /// constructorul clasei patrat face doua lucruri: pe de o parte, primeste un parametru dim si pe de alata parte apeleaza constructorul clasei de baza Forma cu acest parametru adica trimite dim catre Forma si seteaza dimensiune = dim
    void arie() {
        cout << "Aria patratului este " << dimensiune*dimensiune << "cm.\n";
    }
};

class Cerc: public Forma {
private:
protected:
public:
    Cerc(int dim) : Forma(dim) {} /// analog ca la Patrat (constructor cu lista de initializare)
    void arie() {
        cout << "Aria cercului este " << 3.14*dimensiune*dimensiune << "cm.\n";
    }
};

int main() {
    ////////////////////////////////////////////////////
    /// 1. Polimorfism > Problema 1: Afisare animale ///
    ////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// error: cannot declare variable 'a' to be of abstract type 'Animal' ///
    //////////////////////////////////////////////////////////////////////////

    // Animal a;
    // a.sunet(); 

    //////////////////////////
    /// Varianta primitiva ///
    //////////////////////////

    // Caine c;
    // c.sunet(); /// out: Cainele face "Ham! Ham!"
    // Pisica p;
    // p.sunet(); /// out: Pisica face "Miau! Miau!"

    /////////////////////////////////////////////////////
    /// error: invalid abstract type 'Animal' for 'a' ///
    /////////////////////////////////////////////////////
    
    // Animal a[2]; /// creeaza doua obiecte de tip Animal
    // a[1] = new Caine();
    // a[2] = new Pisica();
    // for (int i = 0; i < 2; i++) {
    //     a[i].sunet();
    //     delete a[i];
    // }

    ///////////////////////////////////////
    /// Array de elemente de tip Animal ///
    ///////////////////////////////////////
    
    // Animal* a[2]; /// creeaza doi pointeri catre obiecte de clase derivate (Caine sau Pisica)
    // a[0] = new Caine();
    // a[1] = new Pisica();
    // for (int i = 0; i < 2; i++) {
    //     a[i] -> sunet(); /// polimorfismul
    //     delete a[i];
    // }

    //////////////////////////////////////////////////////
    /// Diagrama: `Animal* a[2]; // Array de pointeri` ///
    //////////////////////////////////////////////////////
    ///
    /// +---------+            +-------------+
    /// | a[0] ---|----------> |  Caine      |
    /// +---------+            +-------------+
    /// 
    /// +---------+            +-------------+
    /// | a[1] ---|----------> |  Pisica     |
    /// +---------+            +-------------+

    /////////////////////////////////////////////////
    /// Pointeri vs. obiecte vs. polimorfism      ///
    /// Raspunde cu „✔️ merge” sau „❌ nu merge” ///
    /////////////////////////////////////////////////
    
    ////////////////////////
    /// Exercitiul 1 ❌ ///
    ///////////////////////
    
    // Animal a; /// nu poti crea obiecte de tip abstract, Animal e clasa abstracta deoarece contine o metoda virtuala pura
    // a.sunet();
    
    ////////////////////////
    /// Exercitiul 2 ✔️ ///
    ///////////////////////

    // Animal* p = new Caine();
    // p -> sunet();
    // delete p;

    ////////////////////////
    /// Exercitiul 3 ✔️ ///
    ///////////////////////

    // Caine c;
    // Animal* p = &c; /// upcast de la Caine la Animal*
    // p -> sunet();

    ////////////////////////
    /// Exercitiul 4 ❌ ///
    ///////////////////////

    // Animal a[3]; /// nu pot avea un array cu trei obiecte de tip Animal pentru ca Animal este o clasa abstracta

    ////////////////////////
    /// Exercitiul 5 ✔️ ///
    ///////////////////////

    // Animal* a[3]; /// solutia este sa am un array de pointeri la Animal deoarece fiecare element pointeaza catre un obiect concret (Caine sau Pisica)
    // a[0] = new Pisica();
    // a[1] = new Caine();
    // a[2] = new Pisica();
    // for (int i = 0; i < 3; i++) {
    //     a[i]->sunet();
    //     delete a[i];
    // }

    /////////////////////////////////////////////////////
    /// 1. Polimorfism > Problema 2: Forme geometrice ///
    /////////////////////////////////////////////////////

    Forma* f[5];
    f[0] = new Patrat(5);
    f[1] = new Cerc(10);
    f[2] = new Cerc(20);
    f[3] = new Patrat(13);
    f[4] = new Patrat(90);
    for (int i = 0; i < 5; i++) {
        f[i]->arie();
        delete f[i];
    }

    return 0;
}