#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept> // [Barem] pentru exceptii
#include <typeinfo>  // [Barem] pentru RTTI (dynamic_cast, typeid)

using namespace std;

// =============================================================
// [Barem] 2p - ierarhie de clase
// Clasa abstractă Candidat este baza pentru toate tipurile de candidați
// =============================================================
class Candidat {
protected:
    string nume;
    string serieCI;
    int numarCI;
    double medieBac;
    int numarInregistrare;
    static int contorGeneral; // [Barem] atribut static pentru ID auto-increment
public:
    // [Barem] constructor + validare (aruncă excepție dacă numele e gol)
    Candidat(const string& nume_, const string& serie, int nr, double medie)
        : nume(nume_), serieCI(serie), numarCI(nr), medieBac(medie) 
    {
        if (nume.empty()) 
            throw invalid_argument("Nume invalid"); // [Barem] exceptia se propaga
        numarInregistrare = ++contorGeneral; // [Barem] ID comanda incrementat automat
    }

    // [Barem] destructor virtual
    virtual ~Candidat() {}

    // [Barem] metoda const
    int getNumarInregistrare() const { return numarInregistrare; }

    // [Barem] abstract - functie virtuala pura
    virtual double calculMedie() const = 0;

    // [Barem] metoda virtuala pentru afisare
    virtual void afiseaza() const {
        cout << "Nume: " << nume << ", CI: " << serieCI << " " << numarCI 
             << ", Medie Bac: " << medieBac << ", Nr. inregistrare: " << numarInregistrare;
    }
};
int Candidat::contorGeneral = 0; // initializare atribut static

// =============================================================
// [Barem] mostenire - IF fara a doua facultate
// =============================================================
class CandidatIF : public Candidat {
    double notaProba;
public:
    CandidatIF(const string& nume_, const string& serie, int nr, double medie, double notaProba_)
        : Candidat(nume_, serie, nr, medie), notaProba(notaProba_) {}

    double calculMedie() const override { // rescriere metoda abstracta
        return 0.8 * notaProba + 0.2 * medieBac;
    }

    void afiseaza() const override {
        Candidat::afiseaza(); // [Barem] apel functie clasa de baza
        cout << ", Tip: IF, Nota proba: " << notaProba << ", MA: " << calculMedie() << "\n";
    }
};

// =============================================================
// [Barem] mostenire - ID fara a doua facultate
// =============================================================
class CandidatID : public Candidat {
    double notaProba;
    double notaMateBac;
public:
    CandidatID(const string& nume_, const string& serie, int nr, double medie, double notaProba_, double notaMate_)
        : Candidat(nume_, serie, nr, medie), notaProba(notaProba_), notaMateBac(notaMate_) {}

    double calculMedie() const override {
        return 0.6 * notaProba + 0.4 * notaMateBac;
    }

    void afiseaza() const override {
        Candidat::afiseaza();
        cout << ", Tip: ID, Nota proba: " << notaProba << ", Nota mate Bac: " << notaMateBac 
             << ", MA: " << calculMedie() << "\n";
    }
};

// =============================================================
// [Barem] mostenire - IF pentru a 2-a facultate
// =============================================================
class CandidatIF2 : public Candidat {
    double notaProba;
    double mediePrimaFac;
public:
    CandidatIF2(const string& nume_, const string& serie, int nr, double medie, double notaProba_, double medieFac_)
        : Candidat(nume_, serie, nr, medie), notaProba(notaProba_), mediePrimaFac(medieFac_) {}

    double calculMedie() const override {
        return 0.6 * notaProba + 0.4 * mediePrimaFac;
    }

    void afiseaza() const override {
        Candidat::afiseaza();
        cout << ", Tip: IF2, Nota proba: " << notaProba << ", Medie prima facultate: " << mediePrimaFac
             << ", MA: " << calculMedie() << "\n";
    }
};

// =============================================================
// [Barem] mostenire - ID pentru a 2-a facultate
// =============================================================
class CandidatID2 : public Candidat {
    double notaProba;
    double mediePrimaFac;
public:
    CandidatID2(const string& nume_, const string& serie, int nr, double medie, double notaProba_, double medieFac_)
        : Candidat(nume_, serie, nr, medie), notaProba(notaProba_), mediePrimaFac(medieFac_) {}

    double calculMedie() const override {
        return 0.6 * notaProba + 0.4 * mediePrimaFac;
    }

    void afiseaza() const override {
        Candidat::afiseaza();
        cout << ", Tip: ID2, Nota proba: " << notaProba << ", Medie prima facultate: " << mediePrimaFac
             << ", MA: " << calculMedie() << "\n";
    }
};

// =============================================================
// [Barem] clasa Factory - creeaza candidati pe baza tipului
// =============================================================
class FactoryCandidati {
public:
    static Candidat* creeaza(const string& tip) {
        if (tip == "IF") 
            return new CandidatIF("Popescu", "AB", 12345, 9.5, 8.7);
        if (tip == "ID") 
            return new CandidatID("Ionescu", "CJ", 54321, 8.2, 7.5, 9.0);
        if (tip == "IF2") 
            return new CandidatIF2("Georgescu", "B", 11111, 7.5, 7.0, 8.0);
        if (tip == "ID2") 
            return new CandidatID2("Marinescu", "BV", 22222, 8.0, 7.2, 8.5);
        throw invalid_argument("Tip necunoscut");
    }
};

// =============================================================
// [Barem] Singleton - aplicatie cu meniu
// =============================================================
class Aplicatie {
private:
    static Aplicatie* instanta;
    vector<Candidat*> candidati; // [Barem] STL container vector
    Aplicatie() {}
public:
    static Aplicatie* getInstanta() {
        if (!instanta) instanta = new Aplicatie();
        return instanta;
    }

    void adaugaCandidat(Candidat* c) {
        candidati.push_back(c);
    }

    void afiseazaTot() const {
        for (auto c : candidati) {
            c->afiseaza();
        }
    }

    void afiseazaDoarIF() const {
        for (auto c : candidati) {
            if (dynamic_cast<CandidatIF*>(c)) // [Barem] RTTI cu dynamic_cast
                c->afiseaza();
        }
    }

    // [Barem] STL sort
    void afiseazaSortatDupaMedie() {
        vector<Candidat*> copie = candidati;
        sort(copie.begin(), copie.end(), [](Candidat* a, Candidat* b) {
            return a->calculMedie() > b->calculMedie();
        });
        for (auto c : copie) c->afiseaza();
    }
};
Aplicatie* Aplicatie::instanta = nullptr;

// =============================================================
// [Barem] template - functie generica de afisare
// =============================================================
template<typename T>
void afiseazaVector(const vector<T>& v) {
    for (auto& elem : v) {
        cout << elem << " ";
    }
    cout << "\n";
}

// =============================================================
// main - cu meniu si try-catch
// =============================================================
int main() {
    Aplicatie* app = Aplicatie::getInstanta();

    try {
        app->adaugaCandidat(FactoryCandidati::creeaza("IF"));
        app->adaugaCandidat(FactoryCandidati::creeaza("ID"));
        app->adaugaCandidat(FactoryCandidati::creeaza("IF2"));
        app->adaugaCandidat(FactoryCandidati::creeaza("ID2"));
    }
    catch (const exception& e) { // [Barem] exceptia este prinsa
        cout << "Eroare: " << e.what() << "\n";
    }

    cout << "\n--- Toti candidatii ---\n";
    app->afiseazaTot();

    cout << "\n--- Candidati IF ---\n";
    app->afiseazaDoarIF();

    cout << "\n--- Sortati dupa medie ---\n";
    app->afiseazaSortatDupaMedie();

    return 0;
}
