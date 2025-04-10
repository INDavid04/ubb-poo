#include <iostream>
#include <array>
#include <ctime>
#include <vector>


// În majoritatea situațiilor nu avem nevoie să suprascriem cc/op=/destr
// pentru că ne convin definițiile acestor funcții speciale pe care le
// generează compilatorul (regula celor 0)
//
// Situațiile când probabil este necesar să suprascriem cc/op=/destr sunt
// următoarele:
// - atribute const: operator= nu funcționează
// - atribute de tip pointer sau referință:
//   - copierile și atribuirile copiază adrese, iar ambele obiectele
//     vor arăta spre aceeași zonă de memorie
//   - poate deveni complicată gestionarea resurselor alocate explicit și
//     există riscul să eliberăm aceeași zonă de memorie de 2 ori
//     (undefined behavior)
//   - dacă dorim obiecte complet independente, trebuie suprascrise funcțiile
// - moșteniri de interfață: trebuie suprascris destructorul în bază
//
// Asta înseamnă că facem ceva special, deci cc/op=/destr generate de
// compilator nu fac ce trebuie. Dacă suprascriem una dintre ele, nu
// ne convine definiția generată de compilator, deci cel mai probabil
// înseamnă că și definițiile celorlalte 2 funcții speciale sunt greșite.
// Prin urmare, dacă suprascriem o funcție specială (cc/op=/destr) într-o
// clasă, trebuie să le suprascriem pe toate 3 (regula celor trei)
// https://en.cppreference.com/w/cpp/language/rule_of_three

/////////////////////////////////////////////////////////////////////////////
// exemplu cu atribut const

class ClasaCuConstante {
public:
    ClasaCuConstante() = default;

private:
    const int z{42};
    std::string nume;
    public:
    ClasaCuConstante(const ClasaCuConstante &other)
        : z(other.z),
          nume(other.nume) {
    }

    ClasaCuConstante& operator=(const ClasaCuConstante& other) {
        nume = other.nume;
        return *this;
    }

    ~ClasaCuConstante() { std::cout << "Destr " << nume << std::endl; }

    ClasaCuConstante(int z, const std::string &nume)
        : z(z),
          nume(nume) {
    }

    friend std::ostream & operator<<(std::ostream &os, const ClasaCuConstante &obj) {
        return os
               << "z: " << obj.z
               << " nume: " << obj.nume;
    }
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// exemplu cu specificatorii de acces la moștenire și tipuri de moștenire

class Baza {
    int x;
    void f() {}
protected:
    int y;
    void g() {}
public:
    int z;
    void h() {}
};

class Derivata1 : public Baza {
    public:
    // using Baza::g;
    void abc() {
        Baza b;
        //b.g();
        this->g();
    }
    void q() {
        z;
        h();
        y;
        g();
        // x;
        // f();
    }
};

class Derivata2 : protected Baza {
    void q() {
        z;
        h();
        y;
        g();
        // x;
        // f();
    }
};
class Derivata22 : protected Derivata2 {
    void q() {
        z;
        h();
        y;
        g();
        // x;
        // f();
    }
};
class Derivata3 : private Baza {
public:
    void q() {
        z;
        h();
        y;
        g();
        // x;
        // f();
    }
};
class Derivata33 : private Derivata3 {
    public:
    using Derivata3::q;
    void qq() {
        // z;
        // h();
        // y;
        // g();
        // x;
        // f();
    }
};

void test() {
    Derivata33 d33;
    d33.q();
    Derivata1 d;
    d.z;
    d.h();
    // d.y;
    // d.g();
    // d.x;
    // d.f();
    Derivata2 d2;
    // d2.h();
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// exemplu de ierarhie
// comportamentul la moștenire pentru:
// - constructori de inițializare
// - constructor de copiere, operator=, destructor

class Dispozitiv {
private:
    std::string nume{"Cisco"};
    int garantie{2};
protected:
    void repara() {}
    int nr_butoane{1};
public:
    Dispozitiv() = default;
    static void motd() { std::cout << "mentenanta\n"; }

    Dispozitiv(int nr_butoane, const std::string &nume, int garantie)
        : nr_butoane(nr_butoane),
          nume(nume),
          garantie(garantie) {
    }

    Dispozitiv(int nr_butoane, const std::string &nume)
        : nr_butoane(nr_butoane),
          nume(nume) {
    }

    Dispozitiv(const Dispozitiv &other)
        : nr_butoane(other.nr_butoane),
          nume(other.nume),
          garantie(other.garantie) {
    }

    Dispozitiv & operator=(const Dispozitiv &other) {
        if (this == &other)
            return *this;
        nr_butoane = other.nr_butoane;
        nume = other.nume;
        garantie = other.garantie;
        return *this;
    }

    ~Dispozitiv() {}
    void start() {}
    void use() {}
    void stop() {}
};



class Proiector : public Dispozitiv {
public:
    using Dispozitiv::Dispozitiv;
    static void motd(int) { std::cout <<"mai incearca\n"; }
    void proiecteaza() {
        nr_butoane--;
        repara();
        // std::cout << nume;
    }
    Proiector(const Proiector &other)
        : Dispozitiv(other) {
    }

    Proiector & operator=(const Proiector &other) {
        if (this == &other)
            return *this;
        Dispozitiv::operator =(other);
        return *this;
    }
};

class TablaInteligenta : public Dispozitiv {};


class Sala {
    std::string nume;
    std::vector<Calculator> calculatoare;

public:
    Sala(const std::string &nume, const std::vector<Calculator> &calculatoare)
        : nume(nume),
          calculatoare(calculatoare) {
    }

    explicit Sala(const std::string &nume)
        : nume(nume) {
    }

    friend std::ostream &operator<<(std::ostream &os, const Sala &obj) {
        os
                << "nume: " << obj.nume
                << " calculatoare:\n";
        for (const auto &calculator: obj.calculatoare)
            os << calculator << "\n";
        return os;
    }
    void prezinta(Dispozitiv& disp) {
        disp.start();
        disp.use();
        disp.stop();
    }
    void prezinta2(Dispozitiv* disp) {
        disp->start();
        disp->use();
        disp->stop();
    }
};


void f(Proiector& pr) {
    pr.start();
}

/////////////////////////////////////////////////////////////////////////////

// Ce face [[nodiscard]]?
// Ne dă warning dacă nu folosim tipul de retur pentru că vrem să semnalăm
// că valoarea de retur este importantă (de exemplu un cod de eroare)
// și nu trebuie ignorată.
[[nodiscard]] int ceva() { std::cout <<"ceva"; return 42; }

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// început exemplu virtual (funcții virtuale)

class B1 {
    int z;
public:
    virtual ~B1() { std::cout << "B1::~B1 called\n"; }
};
class B2 : public B1 {};
class B3 : public B2 {
    int *v = new int;
public:
    ~B3() {delete v;}
};

int main() {
    ClasaCuConstante c1, c2;
    ClasaCuConstante c3(c2);
    c1 = c3;
    std::cout << c1 << c2;
    // B1* bz = new B3;
    // delete bz;
    Dispozitiv::motd();
    Dispozitiv disp;
    // f(disp);
    Proiector::motd(1);
    Proiector pr;
    Proiector pr2{20, "plisco", 123};
    Proiector pr3{10, "disco"};
    Sala stoilow{"stoilow"};
    stoilow.prezinta(pr);
    stoilow.prezinta2(&pr);
    TablaInteligenta tb;
    stoilow.prezinta(tb);
    stoilow.prezinta2(&tb);

    return 0;
}
