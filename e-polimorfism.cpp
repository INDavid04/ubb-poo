/// TODO: Understand polymorphism up casting and down casting 

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <iomanip> /// hex, setw

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

//////////////////////////////////////////////
/// 2. Up-casting (din derivata spre baza) ///
//////////////////////////////////////////////

/// Problema 3: Echipa sportiva
/// Cerinta: Creeaza o clasa Jucator si una derivata JucatorFotbal. Creeaza un vector de Jucator* si stocheaza in el obiecte de tip JucatorFotbal (up-cast implicit). Apeleaza o metoda virtuala descriere().

class Jucator {
private:
protected:
    string nume;
    int varsta;
public:
    Jucator (string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
    }
    virtual void afiseazaDetalii () const {
        cout << "Jucator: " << nume << " are varsta: " << varsta << "\n";
    }
    virtual ~Jucator() {
        cout << "Jucatorul " << nume << " a iesit de tot\n";
    }
};

class JucatorFotbal : public Jucator {
private:
    string echipa;
protected:
public:
    JucatorFotbal(string nume, int varsta, string echipa) : Jucator(nume, varsta) {
        this->echipa = echipa;
    }
    void afiseazaDetalii() const override {
        cout << "Jucator: " << nume << " are varsta: " << varsta << " si este in echipa: " << echipa << "\n";
    }
    ~JucatorFotbal() {
        cout << "Jucatorul " << nume << " a iesit din echipa " << echipa << "\n";
    }
};

/// Take out: Daca lucrezi cu clase polimorfice, metodele ce trebuies suprascrise trebuie sa fie virtuale si destructorul sa fie virtual, de asemenea.

/// Problema 4: Angajati
/// Cerinta: Ai o clasa Angajat si o clasa derivata Manager. Fa o functie care primeste pointer la Angajat si primeste ca parametru un Manager*. Foloseste up-casting pentru a apela metode comune.

class Angajat {
private:
protected:
    string nume;
    int varsta;
public:
    Angajat(string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
    }
    virtual void afiseaza() const {
        cout << "Angajatul " << nume << " are " << varsta << " ani\n";
    }
    virtual ~Angajat() {
        cout << "Angajatul " << nume << " a iesit de tot\n";
    }
};

class Manager : public Angajat {
private:
    string numeCompanie;
protected:
public:
    Manager(string nume, int varsta, string numeCompanie) : Angajat(nume, varsta) {
        this->numeCompanie = numeCompanie;
    }
    void afiseaza() const override {
        cout << "Angajatul " << nume << " este manager peste " << numeCompanie << "\n";
    }
    ~Manager() {
        cout << "Managerul " << nume << " a iesit din functie\n";
    }
};

////////////////////////////////////////////////
/// 3. Down-casting (din baza spre derivata) ///
////////////////////////////////////////////////

/// Problema 5: Joc video cu iteme
/// Cerinta: Ai o clasa Item si o clasa derivata Arma. Intr-o functie care primeste un Item*, verifica daca acel Item este o Arma (folosing dynamic_cast), apoi afiseaza detalii doar daca conversia reuseste.

class Item {
private:
protected:
public:
    virtual void descriere() const {
        cout << "Item generic\n";
    }
    virtual ~Item() {
        cout << "Item distrus\n";
    }
};

class Arma : public Item {
private:
    string nume;
    int damage;
protected:
public:
    Arma(string nume, int damage) {
        this->nume = nume;
        this->damage = damage;
    }

    void descriere() const override {
        cout << "Arma: " << nume << ", damage: " << damage << "\n";
    }

    string getNume() const {
        return nume;
    }

    int getDamage() const {
        return damage;
    }

    ~Arma() {
        cout << "Arma " << nume << " distrusa\n";
    }
};

void verificaDacaItemEsteArma(Item* i) {
    i->descriere();
    Arma* a = dynamic_cast<Arma*>(i);
    // cout << "DEBUG: a = " << a << "\n";
    /// a retine 0 daca nu i nu este arma; a retine adresa catre obiectul i daca este arma
    if(a) {
        a->descriere();
    } else {
        cout << "Itemul nu este o arma\n";
    }
}

/// Problema 6: Vehicule
/// Cerinta: Creeaza o clasa Vehicul si deriva clasele Bicicleta, Masina. Ai o lista de Vehicul*. Pentru fiecare, incearca un dynamic_cast la Masina* si, daca reuseste, afiseaza numarul de cai putere.

class Vehicul {
private:
protected:
public:
    virtual void afiseaza() const {
        cout << "Vehicul\n";
    }
    ~Vehicul() {
        cout << "Vehicul distrus\n";
    }
};

class Bicicleta : public Vehicul {
private:
protected:
public:
    void afiseaza() const override {
        cout << "Bicicleta\n";
    }
    ~Bicicleta() {
        cout << "Bicicleta distrusa\n";
    }
};

class Masina : public Vehicul {
private:
    int numar_cai_putere;
protected:
public:
    Masina(int numar_cai_putere) {
        this->numar_cai_putere = numar_cai_putere;
    }
    void afiseaza() const override {
        cout << "Masina are " << numar_cai_putere << " cai putere\n";
    }
    ~Masina() {
        cout << "Masian distrusa\n";
    }
};

void vehiculEsteMasina(Vehicul* vehicul) {
    vehicul->afiseaza();
    Masina* masina = dynamic_cast<Masina*>(vehicul);
    if (masina) {
        masina->afiseaza();
    } else {
        cout << "Vehiculul nu este masina\n";
    }
}

////////////////////////////////////////
/// 4. Operatori de cast             ///
/// 4.1 C-style cast: (Tip)variabila ///
////////////////////////////////////////

/// Problema 7: Creeaza o clasa Temperatura care are un float in Celsius. Supraincarca operatorul float() pentru a permite conversia in float. In main, converteste un Temperatura in float folosind (float)obj.

class Temperatura {
private:
    float celsius;
protected:
public:
    Temperatura(float celsius) {
        this->celsius = celsius;
    }
    operator float() const {
        return celsius;
    }
};

/// Problema 8: Creeaza o clasa Bani cu o valoare interna in float. Foloseste un cast C-style pentru a o converti intr-un int, pierzand fractia.

class Bani {
private:
    float teanc;
protected:
public:
    Bani(float teanc) {
        this->teanc = teanc;
    }
    operator int() const {
        int teancRotunjit;
        teancRotunjit = teanc;
        return teancRotunjit;
    }
};

////////////////////////
/// 4.2 dynamic_cast ///
////////////////////////

/// Problema 9: Ai o clasa Animal cu metode virtuale si derivezi Pisica. Creeaza o functie care primeste un Animal* si verifica daca e Pisica* - daca da, apeleaza metoda toarce().

class Animalut {
private:
protected:
public:
    virtual void toarce() const {
        cout << "Animalul toarce\n";
    }
    virtual ~Animalut() {
        cout << "Animalul a fugit\n";
    }
};

class Pisicuta : public Animalut {
private:
protected:
public:
    void toarce() const override {
        cout << "Pisica toarce\n";
    }
};

void verificaDacaEstePisica(Animalut* a) {
    a->toarce();
    Pisicuta* p = dynamic_cast <Pisicuta*> (a);
    if (p) {
        p->toarce();
    } else {
        cout << "Acest animal nu este o pisica\n";
    }
}

/// Problema 10: Ai o baza Obiect, din care deriva Electronic. Intr-un vector de Obiect*, unele sunt Electronic, altele nu. Parcurgi vectorul: afisezi descrierea fiecarui obiect; daca e electronic, folosesti dynamic_cast si apelezi verificaGarantie().

class Obiect {
private:
protected:
public:
    virtual void detalii() const {
        cout << "Acesta este un obiect\n";
    }
    virtual ~Obiect() {
        cout << "Obiect distrus\n";
    }
};

class Electronic : public Obiect {
private:
    bool areGarantie;
protected:
public:
    Electronic(bool areGarantie) {
        this->areGarantie = areGarantie;
    }
    void verificaGarantie() const {
        if (areGarantie) {
            cout << "Electronicul are garantie\n";
        } else {
            cout << "Electronicul nu are garantie\n";
        }
    }
};

///////////////////////
/// 4.3 static_cast ///
///////////////////////

/// Problema 11: Ai o clasa Metru si o clasa Centimetru. Creeaza un constructor care permite conversia intre ele cu static_cast. Fa conversii bidirectionale.

class Centimetru;

class Metru {
private:
    float valoare;
protected:
public:
    Metru(float valoare) {
        this->valoare = valoare;
    }
    Metru(const Centimetru& cm);
    // this->valoare = cm.getValoare() / 100.0f;
    float getValoare () const {
        return valoare;
    }
    void afiseaza() const {
        cout << valoare << " metrii\n";
    }
};

class Centimetru {
private:
    float valoare;
protected:
public:
    Centimetru(float valoare) {
        this->valoare = valoare;
    }
    Centimetru(const Metru& m) {
        this->valoare = m.getValoare() * 100.0f;
    }
    float getValoare() const {
        return valoare;
    }
    void afiseaza() {
        cout << valoare << " centimetrii\n";
    }
};

Metru::Metru(const Centimetru& cm) {
    this->valoare = cm.getValoare() / 100.0f;
}

/// Problema 12: Creeaza o ierarhie Forma -> Cerc. Intr-o functie, primeste Forma* si foloseste static_cast<Cerc*> pentru a accesa raza. Observa ca, spre deosebire de dynamic_cast, nu verifica tipul la runtime!

class FormaProblema12 {
private:
protected:
public:
};

class CercProblema12 : public FormaProblema12 {
private:
    int raza;
protected:
public:
    CercProblema12(int raza) {
        this->raza = raza;
    }
    int getRaza() const {
        return raza;
    }
};

void afiseazaRaza(FormaProblema12* f) {
    CercProblema12* c = static_cast <CercProblema12*> (f);
    cout << "Raza are dimensiunea " << c->getRaza() << "\n";
}

//////////////////////
/// 4.4 const_cast ///
//////////////////////

/// Problema 13: Ai o functie care primeste un const char*. Creeaza o variabila char*, transmite-o prin const_cast, apoi modifica continutul daca e permis.

void modificaConstanta(const char* cuvant) {
    char cuvantInitial[4];
    strncpy(cuvantInitial, cuvant, 3);
    cuvantInitial[3] = '\0';
    char* cuvantModificat = const_cast <char*> (cuvant);
    cuvantModificat[1] = 'e';
    cout << cuvantInitial << " este schimbat in " << cuvantModificat << "\n";
}

/// Problema 14: Ai o functie void afisare(const int* p) care afiseaza o valoare. In main, transmite un int* prin const_cast pentru a apela functia.

void afisareProblema14(const int* p) {
    cout << "Valoarea este " << *p << "\n";
}

////////////////////////////
/// 4.5 reinterpret_cast ///
////////////////////////////

/// Problema 15: Ai un int, dar vrei sa-l interpretezi ca char* (periculos, dar posibil cu reinterpret_cast). Creeaza un exemplu care afiseaza byte cu byte valoarea unui int.

void problema15() {
    int valoare = 0x12345678;
    unsigned char* bytes = reinterpret_cast <unsigned char*> (&valoare);
    for (int i = 0; i < sizeof(int); ++i) {
        cout << "0x" << hex << setw(2) << setfill('0') << (int)bytes[i] << " ";
    }
    cout << "\n";
}

/// Problema 16: Converteste un pointer catre o functie intr-un void* si invers cu reinterpret_cast. Observa comportamentul platform-dependent.

void salutProblema16() {
    cout << "Salut, Problema 16!\n";
}

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

    // Forma* f[5];
    // f[0] = new Patrat(5);
    // f[1] = new Cerc(10);
    // f[2] = new Cerc(20);
    // f[3] = new Patrat(13);
    // f[4] = new Patrat(90);
    // for (int i = 0; i < 5; i++) {
    //     f[i]->arie();
    //     delete f[i];
    // }

    ///////////////////////////////////////////////////
    /// 2. Up-casting > Problema 3: Echipa sportiva ///
    ///////////////////////////////////////////////////

    // vector<Jucator*> echipa; /// vector de pointeri la baza - upcasting
    // echipa.push_back(new JucatorFotbal("Popescu", 24, "FC Universitatea"));
    // echipa.push_back(new JucatorFotbal("Vlad", 20, "Dinamo"));
    // echipa.push_back(new JucatorFotbal("Olaru", 39, "FC Arges"));
    // echipa.push_back(new JucatorFotbal("Mircea", 23, "Real Madrid"));

    // for (Jucator* j : echipa) {
    //     j->afiseazaDetalii(); /// apel virtual; se executa functia din clasa derivata
    //     // delete j;
    // }

    // for (Jucator* j : echipa) {
    //     delete j;
    // }

    ////////////////////////////////////////////
    /// 2. Up-casting > Problema 4: Angajati ///
    ////////////////////////////////////////////

    // vector<Angajat*> listaAngajati;
    // listaAngajati.push_back(new Manager("Marcel", 40, "eClean"));
    // listaAngajati.push_back(new Manager("Grigore", 22, "Wanta"));
    // listaAngajati.push_back(new Manager("Samuel", 25, "Listenario"));

    // for (Angajat* a : listaAngajati) {
    //     a->afiseaza(); /// se apeleaza functia din clasa derivata
    // }

    // for (Angajat* a : listaAngajati) {
    //     delete a;
    // }

    ////////////////////////////////////////////////////////
    /// 3. Down-casting > Problema 5: Joc video cu iteme ///
    ////////////////////////////////////////////////////////

    // Item* i1 = new Item();
    // Item* i2 = new Arma("prastie", 10);
    // verificaDacaItemEsteArma(i1);
    // verificaDacaItemEsteArma(i2);
    // delete i1;
    // delete i2;

    //////////////////////////////////////////////
    /// 3. Down-casting > Problema 6: Vehicule ///
    //////////////////////////////////////////////

    // list<Vehicul*> listaVehicule = {};
    // listaVehicule.push_back(new Vehicul());
    // listaVehicule.push_back(new Bicicleta());
    // listaVehicule.push_back(new Masina(70));
    // listaVehicule.push_back(new Bicicleta());
    // listaVehicule.push_back(new Masina(54));
    // for (Vehicul* vehicul : listaVehicule) {
    //     vehiculEsteMasina(vehicul);
    // }
    // for (Vehicul* vehicul : listaVehicule) {
    //     delete vehicul;
    // }

    //////////////////////////////////////
    /// 4.1 C-style cast: > Problema 7 ///
    //////////////////////////////////////

    // Temperatura t(38.9f);
    // float valoare = float(t);
    // cout << "Valoarea temperaturii este " << valoare << " grade celsius\n";

    //////////////////////////////////////
    /// 4.1 C-style cast: > Problema 8 ///
    //////////////////////////////////////

    // Bani b(100.89f);
    // int rotunjit = int(b);
    // cout << "Teancul rotunjit este " << rotunjit << "RON\n";

    /////////////////////////////////////
    /// 4.2 dynamic_cast > Problema 9 ///
    /////////////////////////////////////

    // Animalut* a1 = new Pisicuta();
    // Animalut* a2 = new Animalut();
    // verificaDacaEstePisica(a1);
    // verificaDacaEstePisica(a2);
    // delete a1;
    // delete a2;

    //////////////////////////////////////
    /// 4.2 dynamic_cast > Problema 10 ///
    //////////////////////////////////////

    // vector<Obiect*> vectorObiecte = {};
    // vectorObiecte.push_back(new Obiect());
    // vectorObiecte.push_back(new Electronic(true));
    // vectorObiecte.push_back(new Electronic(false));
    // vectorObiecte.push_back(new Obiect());
    // for (Obiect* o : vectorObiecte) {
    //     Electronic* e = dynamic_cast <Electronic*> (o);
    //     if (e) {
    //         e->verificaGarantie();
    //     } else {
    //         o->detalii();
    //     }
    // }
    // for (Obiect* o : vectorObiecte) {
    //     delete o;
    // }

    /////////////////////////////////////
    /// 4.3 static_cast > Problema 11 ///
    /////////////////////////////////////

    // Metru m1(12.4f);
    // m1.afiseaza();
    // Centimetru cm = static_cast <Centimetru> (m1);
    // cm.afiseaza();
    // Metru m2 = static_cast <Metru> (cm);
    // m2.afiseaza();

    /////////////////////////////////////
    /// 4.3 static_cast > Problema 12 ///
    /////////////////////////////////////

    // FormaProblema12* f = new CercProblema12(109);
    // afiseazaRaza(f);

    ////////////////////////////////////
    /// 4.4 const_cast > Problema 13 ///
    ////////////////////////////////////

    // char cuvant[] = "aur";
    // modificaConstanta(cuvant);

    ////////////////////////////////////
    /// 4.4 const_cast > Problema 14 ///
    ////////////////////////////////////

    // int valoare = 14;
    // int* pointer = &valoare;
    // afisareProblema14(const_cast <const int *> (pointer));

    //////////////////////////////////////////
    /// 4.5 reinterpret_cast > Problema 15 ///
    //////////////////////////////////////////

    // problema15();

    //////////////////////////////////////////
    /// 4.5 reinterpret_cast > Problema 16 ///
    //////////////////////////////////////////

    // 1. Pointer catre functie
    void (*pf)() = salutProblema16;

    // 2. Convertim pointerul catre functie intr-un void*
    void* genericPtr = reinterpret_cast<void*>(pf);

    // 3. Convertim inapoi din void* in pointer la functie
    void (*pf2)() = reinterpret_cast<void(*)()>(genericPtr);

    // 4. Apelam functia prin pointerul reconvertit
    pf2();  // Ar trebui sa afiseze mesajul

    return 0;
}