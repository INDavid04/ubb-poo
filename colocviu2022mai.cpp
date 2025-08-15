/// 2025-08-15-09-20-10-50

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

/// BiletSuprafata: taxa 2 lei, folosit pentru tramvaie si autobuze
/// BiletMetrou: taxa 2.5 lei, folosit pentru metrou
/// BiletTranzit: taxa 3 lei, folosit 90 minute atat la suprafata cat si la metrou

/// CardSuprafata: poate fi incarcat cu BiletSuprafata si BiletMetrou
/// CardSubteran: poate fi incarcat cu BiletSuprafata si BiletMetrou
/// CardTranzit: poate fi incarcat doar cu BiletTranzit

/// Card: tipulUltimuluiBiletFolosit, momentulValidarii, sumaBileteNeutilizate
/// BiletTranzit: fie numarul de minute fie "expirat" daca a fost depasit
/// AparatValidare: numarScanari, locatie(suprafata/subteran)

class AparatValidare {
private:
    static int scanGenerator;
    int numarScanari;
    string locatie;
protected:
public:
    AparatValidare(const string &locatie) : locatie(locatie), numarScanari(scanGenerator++) {}
};

int AparatValidare::scanGenerator = 1;

class Bilet {
private:
protected:
    string tip, folosire;
    double taxa;
public:
    Bilet(const string &tip, const double taxa, const string &folosire) {
        this->tip = tip;
        this->taxa = taxa;
        this->folosire = folosire;
    }

    /// Destructor virtual
    virtual ~Bilet() {
        cout << "Bilet aruncat la gunoi\n";
    }
};

class BiletSuprafata : public virtual Bilet {
private:
protected:
public:
    BiletSuprafata(const string &tip = "suprafata", const double taxa = 2, const string &folosire = "tramvaie si autobuze") : Bilet(tip, taxa, folosire) {}

    virtual ~BiletSuprafata() {
        cout << "Bilet de suprafata aruncat la gunoi\n";
    }
};

class BiletMetrou : public virtual Bilet {
private:
protected:
public:
    BiletMetrou(const string &tip = "metrou", const double taxa = 2.5, const string &folosire = "metrou") : Bilet(tip, taxa, folosire) {}

    virtual ~BiletMetrou() {
        cout << "Bilet de metrou aruncat la gunoi\n";
    }
};

class BiletTranzit : public BiletSuprafata, public BiletMetrou {
private:
    int minute;
protected:
public:
    BiletTranzit(const string &tip = "tranzit", const double taxa = 3, const string &folosire = "tramvaie, autobuze si metrou", const int minute = 90) : Bilet(tip, taxa, folosire), BiletSuprafata(tip, taxa, folosire), BiletMetrou(tip, taxa, folosire) {
        this->minute = minute;
    }

    ~BiletTranzit() {
        cout << "Bilet de tranzit aruncat la gunoi\n";
    }
};

class Card {
private:
    string tipulUltimuluiBiletFolosit;
    double sumaBileteNeutilizate;
    list<Bilet*> listaBilete;
protected:
public:
    Card(const string &tipulUltimuluiBiletFolosit = "", const list<Bilet*> listaBilete = {}, const double sumaBileteNeutilizate = 0) {
        this->tipulUltimuluiBiletFolosit = tipulUltimuluiBiletFolosit;
        this->listaBilete = listaBilete;
        this->sumaBileteNeutilizate = sumaBileteNeutilizate;
    }

    virtual ~Card() {
        cout << "Card distrus\n";
    }
};

class CardSuprafata : public Card {
private:    
    string tip;
protected:
public:
    CardSuprafata(const string &tipulUltimuluiBiletFolosit = "", const list<Bilet*> listaBilete = {}, const double sumaBileteNeutilizate = 0, const string &tip = "suprafata") : Card(tipulUltimuluiBiletFolosit, listaBilete, sumaBileteNeutilizate), tip(tip) {}

    ~CardSuprafata() {
        cout << "Card de suprafata distrus\n";
    }
};

class CardSubteran : public Card {
private:    
    string tip;
protected:
public:
    CardSubteran(const string &tipulUltimuluiBiletFolosit = "", const list<Bilet*> listaBilete = {}, const double sumaBileteNeutilizate = 0, const string &tip = "subteran") : Card(tipulUltimuluiBiletFolosit, listaBilete, sumaBileteNeutilizate), tip(tip) {}

    ~CardSubteran() {
        cout << "Card subteran distrus\n";
    }
};

class CardTranzit : public Card {
private:    
    string tip;
protected:
public:
    CardTranzit(const string &tipulUltimuluiBiletFolosit = "", const list<Bilet*> listaBilete = {}, const double sumaBileteNeutilizate = 0, const string &tip = "tranzit") : Card(tipulUltimuluiBiletFolosit, listaBilete, sumaBileteNeutilizate), tip(tip) {}

    ~CardTranzit() {
        cout << "Card de tranzit distrus\n";
    }
};

class SingletonMenu {
private:
    static SingletonMenu* instanta;
    vector<Card*> carduri;

    /// Constructor privat
    SingletonMenu() {
        cout << "Optiuni: \n";
        cout << "1. Creeaza un card\n";
        cout << "2. Creeaza un aparat de validare\n";
        cout << "3. Adauga un bilet la un card\n";
        cout << "4. Valideaza un card\n";
        cout << "5. Modifica minutul curent\n";
        cout << "6. Afiseaza detaliile unui card\n";
        cout << "7. Afiseaza detaliile unui aparat de validare\n";
        cout << "8. Iesi\n";
    }
protected:
public:
    static SingletonMenu* getInstanta() {
        if (instanta == nullptr) {
            instanta = new SingletonMenu();
        }
        return instanta;
    }

    void op1() {
        string tip;
        cout << "Creez un card...\n";

/// BiletSuprafata: taxa 2 lei, folosit pentru tramvaie si autobuze
/// BiletMetrou: taxa 2.5 lei, folosit pentru metrou
/// BiletTranzit: taxa 3 lei, folosit 90 minute atat la suprafata cat si la metrou

/// CardSuprafata: poate fi incarcat cu BiletSuprafata si BiletMetrou
/// CardSubteran: poate fi incarcat cu BiletSuprafata si BiletMetrou
/// CardTranzit: poate fi incarcat doar cu BiletTranzit

/// Card: tipulUltimuluiBiletFolosit, momentulValidarii, sumaBileteNeutilizate
/// BiletTranzit: fie numarul de minute fie "expirat" daca a fost depasit
/// AparatValidare: numarScanari, locatie(suprafata/subteran)

/// Card(const string &tipulUltimuluiBiletFolosit, const list<Bilet*> listaBilete, const double sumaBileteNeutilizate = 0)
        cout << "Tip(suprafata/subteran/tanzit): ";
        cin >> tip;
        cin.get();

        if (tip != "suprafata" && tip != "subteran" && tip != "tranzit") {
            throw invalid_argument("Nu exista tipul de card specificat\n");
        } else if (tip == "suprafata") {
            carduri.push_back(new CardSuprafata());
        } else if (tip == "subteran") {
            carduri.push_back(new CardSubteran());
        } else { /// tip == "tranzit"
            carduri.push_back(new CardTranzit());
        }
    } 

    void op2() {
        cout << "Creez un aparat de validare...\n";
    }
    
    void op3() {
        cout << "Adaug un bilet la un card...\n";
    }

    void op4() const {
        cout << "Validez un card...\n";
    }

    void op5() {
        cout << "Modific minutul curent...\n";
    }
    
    void op6() const {
        cout << "Afisez detaliile unui card...\n";
    }
    
    void op7() const {
        cout << "Afisez detaliile unui aparat de validare...\n";
    }
    
    void op8() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* :: SingletonMenu::instanta = nullptr;

int main() {
    int optiune;
    SingletonMenu* m;
    m = SingletonMenu::getInstanta();

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 8) {
                throw out_of_range("Nu exista optiunea respectiva\n");
            }

            switch (optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
                case 5: m->op5(); break;
                case 6: m->op6(); break;
                case 7: m->op7(); break;
                case 8: m->op8(); break;
            }
        } while (optiune != 8);
    } catch (const out_of_range &e) {
        cout << "Out of range exception: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument exception: " << e.what();
    } catch (const exception &e) {
        cout << "Exception: " << e.what();
    }

    return 0;
}
