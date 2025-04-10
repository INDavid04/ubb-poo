#include <iostream>


class Dispozitiv {
    bool in_use;
    protected:
        void repara() { /**/ }
    public:
       Dispozitiv() {
          in_use = false;
          std::cout << "constr dispozitiv\n"; }
       // constr de copiere
       Dispozitiv(const Dispozitiv& other) : in_use(other.in_use)
       { std::cout << "cc dispozitiv\n"; }
       ~Dispozitiv() { std::cout << "destr dispozitiv\n"; }
       void start() { in_use = true; }
       void start(std::string mesaj) { in_use = true; }
       bool status() const { return in_use; }
       void stop() { in_use = false; }
};

class Calculator : public Dispozitiv {
    public:
        void start(int) {
        std::cout << "afis logo\n"; Dispozitiv::start(); }
};
class Bruiabil {
    int db;
    public: void bruiaza() { std::cout << "trece ambulanta\n"; }
    Bruiabil(int zgomot) : db(zgomot) {
    std::cout << "constr bruiabil\n"; 
    }
    ~Bruiabil() {
    std::cout << "destr bruiabil\n"; 
    }
};

class Proiector : public Dispozitiv, public Bruiabil { 
    // Dispozitiv disp;
    // Bruiabil b;

    std::string model;
    int scara = 1;
    int nr_butoane{};
    char categorie = 'c';
public:
    Proiector() : Dispozitiv(), Bruiabil(70), model("digital projection"), scara(1) {     std::cout << "constr proiector\n"; 
    }
    Proiector(const Proiector& other) : Dispozitiv(other), Bruiabil(other) { std::cout << "cc Proiector\n"; }
    ~Proiector() {
        std::cout << "destr proiector\n"; 
    }
    void foloseste() {
       start(); // Different name call
       repara();
       std::cout << "proiecteaza lectie\n"; 
    }
bool status() {
     return Dispozitiv::status() &&
             scara > 0; // Same-name function call  
       }
};


class Sala {
    Dispozitiv disp;
public:
    void prezinta() {
        disp.start();
    }
};



 
int main() { 
     std::cout << sizeof(Dispozitiv) << ' ' << sizeof(Proiector); 
    Calculator c1;
    //c1.start(std::string("ceva"));   
    c1.start(2);
    Dispozitiv d1; d1.start(); d1.start("ceva");
     Proiector pr, pr2(pr);
      pr.start(); // funcție din interfața clasei Dispozitiv 
//      pr.repara();
      pr.stop();
      pr.foloseste();
      std::cout << (pr.status() ? "on" : "off"); // Redefined functions hide base versions: 
}

