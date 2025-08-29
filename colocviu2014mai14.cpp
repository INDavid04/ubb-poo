/// Nume: Irimia David; Grupa: 141; Compilat cu: `g++ ./main.cpp -o ./e.exe`; Executat cu: `./e.exe`; Tutore laborator: Radu Tudor Vrinceanu

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

///////////////
/// General ///
///////////////

/// 2025-08-29-1000-1131
/// Modelul de colocviu din 2014 mai de la seria 14

////////////////
/// Ierarhie ///
////////////////

/// MaterialBibliografic: titlu
///     MaterialTiparit: autori, an, nume,
///         Articol: numar, numere
///         Carte: oras
///     MaterialElectronic: 
///         PaginaWeb: proprietar, url, data

/// MaterialBibliografic: titlu
class MaterialBibliografic {
    static int id;
    int idMaterial;
    string titlu;
public:
    MaterialBibliografic(const string &titlu) {
        this->titlu = titlu;
        idMaterial = ++id;
    }

    virtual ~MaterialBibliografic() {}

    static int getId() { return id; }
    const int getIdMaterial() const { return idMaterial; }
    const string &getTitlu() const { return titlu; }

    virtual void afiseaza() const = 0;
};

int MaterialBibliografic::id = 0;

///     MaterialTiparit: autori, an, nume
class MaterialTiparit : public MaterialBibliografic {
private:
    int an;
    string nume;
protected:
    vector<vector<string>> autori;
public:
    MaterialTiparit(const string &titlu, const vector<vector<string>> &autori, const int an, const string &nume) : MaterialBibliografic(titlu), autori(autori), an(an), nume(nume) {
        cout << "Material tiparit #" << getId() << " adaugat\n";
    }

    virtual ~MaterialTiparit() {
        cout << "Material tiparit #" << getId() << " scos\n";
    }

    // vector<vector<string>> &getAutori() const () { return autori; }
    const int getAn() const { return an; }
    const string getNume() const { return nume; }

    virtual void afiseaza() const override = 0;
};

///         Articol: numar, numere
class Articol : public MaterialTiparit {
    int numar;
    vector<string> numere;
public:
    Articol(const string &titlu, const vector<vector<string>> &autori, const int an, const string &nume, const int numar, const vector<string> &numere) : MaterialTiparit(titlu, autori, an, nume), numar(numar), numere(numere) {
        cout << "Articol #" << getId() << " adaugat\n";
    }

    virtual ~Articol() {
        cout << "Articol #" << getId() << " scos\n";
    }

    virtual void afiseaza() const override {
        bool first = true;
        /// Anderson, O., Grew, P.: Stress corrosion theory of crack propagation with applications to geophysics. Reviews of Geophysics and Space Physics, 1977, 15, 77-104.
        cout << getIdMaterial() << ". ";
        for (auto &autor : autori) {
            if (first) {
                bool firstName = true;
                for (auto &nume : autor) {
                    if (firstName) {
                        cout << nume;
                        firstName = false;
                    } else {
                        cout << " " << nume;
                    } 
                }
                first = false;
            } else {
                cout << ", ";
                bool firstName = true;
                for (auto &nume : autor) {
                    if (firstName) {
                        cout << nume;
                        firstName = false;
                    } else {
                        cout << " " << nume;
                    } 
                }
            }
        }
        cout << ": " << getTitlu() << ". " << getNume() << ", " << getAn() << ", " << numar;
        first = true;
        for (auto &n : numere) {
            if (first) {
                cout << n;
                first = false;
            } else {
                cout << "-" << n;
            }
        }
        cout << ".\n";
    }
};

///         Carte: oras
class Carte : public MaterialTiparit {
    string oras;
public:
    Carte(const string &titlu, const vector<vector<string>> &autori, const int an, const string &nume, const string &oras) : MaterialTiparit(titlu, autori, an, nume), oras(oras) {
        cout << "Carte #" << getId() << " adaugata\n";
    }

    virtual ~Carte() {
        cout << "Carte #" << getId() << " scoasa\n";
    }

    virtual void afiseaza() const override {
        bool first = true;
        /// Bakhvalov, N., Panasenko, G.: Homogenisation: Averaging Processes in Periodic Media. Kluwer Academic Publisher Group, Dordrecht, 1989.
        cout << getIdMaterial() << ". ";
        for (auto &autor : autori) {
            if (first) {
                bool firstName = true;
                for (auto &nume : autor) {
                    if (firstName) {
                        cout << nume;
                        firstName = false;
                    } else {
                        cout << " " << nume;
                    } 
                }
                first = false;
            } else {
                cout << ", ";
                bool firstName = true;
                for (auto &nume : autor) {
                    if (firstName) {
                        cout << nume;
                        firstName = false;
                    } else {
                        cout << " " << nume;
                    } 
                }
            }
        }
        cout << ": " << getTitlu() << ". " << getNume() << ", " << oras << ", " << getAn() << ".\n";
    }
};

///     MaterialElectronic: 
class MaterialElectronic : public MaterialBibliografic {
public:
    MaterialElectronic(const string &titlu) : MaterialBibliografic(titlu) {
        cout << "Material electronic #" << getId() << " adaugat\n";
    }

    virtual ~MaterialElectronic() {
        cout << "Material electronic #" << getId() << " scos\n";
    }

    virtual void afiseaza() const override = 0;
};

///         PaginaWeb: proprietar, url, data
class PaginaWeb : public MaterialElectronic {
    string proprietar, url, data;
public:
    PaginaWeb(const string &titlu, const string &url, const string &data, const string &proprietar = "***") : MaterialElectronic(titlu), proprietar(proprietar), url(url), data(data) {
        cout << "Pagina web #" << getId() << " adaugata\n";
    }

    virtual ~PaginaWeb() {
        cout << "Pagina web #" << getId() << " scoasa\n";
    }

    virtual void afiseaza() const override {
        bool first = true;
        /// Microsoft Corporation: Microsoft DreamSpark. https://www.dreamspark.com/ (accesat 28.05.2014).
        cout << getIdMaterial() << ". " << proprietar << ": " << getTitlu() << ". " << url << " (accesat " << data << ").\n";
    }
};

///////////////
/// Exemplu ///
///////////////

/// Bibliografie
/// Articole
/// Anderson, O., Grew, P.: Stress corrosion theory of crack propagation with applications to geophysics. Reviews of Geophysics and Space Physics, 1977, 15, 77-104.
/// Cărți
/// Bakhvalov, N., Panasenko, G.: Homogenisation: Averaging Processes in Periodic Media. Kluwer Academic Publisher Group, Dordrecht, 1989.
/// Webografie
/// Microsoft Corporation: Microsoft DreamSpark. https://www.dreamspark.com/ (accesat 28.05.2014).

class SingletonMenu {
    static SingletonMenu* instanta;
    vector <MaterialBibliografic*> materiale;

    SingletonMenu() {
        afiseazaOptiuni();
    }
public:
    virtual ~SingletonMenu() {
        cout << "Eliberez memoria...\n";
        for (auto *material : materiale) {
            delete material;
            material = nullptr;
        }
    }

    static SingletonMenu* getInstanta() {
        if (!instanta) {
            instanta = new SingletonMenu;
        }
        return instanta;
    }

    void afiseazaOptiuni() const {
        cout << "Optiuni:\n";
        cout << "1. Adauga o referinta\n";
        cout << "2. Afiseaza toate referintele detinute\n";
        cout << "3. Afiseaza optiunile\n";
        cout << "4. Iesi din meniu\n";
    }

    void op1() {
        string tip;
        cout << "Adaug o referinta...\n";
/// MaterialBibliografic: titlu
///     MaterialTiparit: autori, an, nume,
///         Articol: numar, numere
///         Carte: oras
///     MaterialElectronic: 
///         PaginaWeb: proprietar, url, data
        cout << "Tip (articol / carte / pagina web): ";
        getline(cin, tip);

        if (tip != "articol" && tip != "carte" && tip != "pagina web") {
            throw invalid_argument("Tip invalid\n");
        } else if (tip == "articol") {
            /// Articol: titlu, autori, an, nume, numar, numere
            string titlu, n, autor, raspuns, nume;
            int numar, an;
            vector<string> numere, autori;
            cout << "Titlu: ";
            getline(cin, titlu);
            do {
                cout << "Autor: ";
                getline(cin, autor);
                autori.push_back(autor);
                cout << "Adauga autor (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            cout << "An: ";
            cin >> an;
            cin.get();
            cout << "Nume: ";
            getline(cin, nume);
            cout << "Numar pagini: ";
            cin >> numar;
            cin.get();
            cout << "Pagina de inceput: ";
            getline(cin, n);
            numere.push_back(n);
            cout << "Pagina de sfarsit: ";
            getline(cin, n);
            numere.push_back(n);
            // materiale.push_back(new Articol(titlu, autori, an, nume, numar, numere));
        } else if (tip == "carte") {
            /// Carte: titlu, autori, an, nume, oras
            string titlu, oras, raspuns, autor, nume;
            int an;
            vector<string> autori;
            cout << "Titlu: ";
            getline(cin, titlu);
            do {
                cout << "Autor: ";
                getline(cin, autor);
                autori.push_back(autor);
                cout << "Adauga autor (da/nu): ";
                getline(cin, raspuns);
                if (raspuns != "da" && raspuns != "nu") {
                    throw invalid_argument("Raspuns invalid\n");
                }
            } while (raspuns == "da");
            cout << "An: ";
            cin >> an;
            cin.get();
            cout << "Nume: ";
            getline(cin, nume);
            cout << "Oras: ";
            getline(cin, oras);
            // materiale.push_back(new Carte(titlu, autori, an, nume, oras));
        } else {
            /// tip == "pagina web"
            /// PaginaWeb: titlu, proprietar, url, data
            string titlu, proprietar, url, data;
            cout << "Tilu: ";
            getline(cin, titlu);
            cout << "Proprietar: ";
            getline(cin, proprietar);
            cout << "Url: ";
            getline(cin, url);
            cout << "Data: ";
            getline(cin, data);
            materiale.push_back(new PaginaWeb(titlu, url, data, proprietar));
        }
    }

    void op2() const {
        cout << "Afisez toate referintele detinute...\n";
        for (auto &material : materiale) {
            material->afiseaza();
        }
    }

    void op3() const {
        afiseazaOptiuni();
    }

    void op4() const {
        cout << "Iesire...\n";
    }
};

SingletonMenu* SingletonMenu::instanta = nullptr;

int main() {
    SingletonMenu* m = SingletonMenu::getInstanta();
    int optiune;

    try {
        do {
            cout << "Optiune: ";
            cin >> optiune;
            cin.get();

            if (optiune < 1 || optiune > 4) {
                throw out_of_range("Optiune invalida\n");
            }

            switch(optiune) {
                case 1: m->op1(); break;
                case 2: m->op2(); break;
                case 3: m->op3(); break;
                case 4: m->op4(); break;
            }
        } while (optiune != 4);
    } catch (const out_of_range &e) {
        cout << "Out of range: " << e.what();
    } catch (const invalid_argument &e) {
        cout << "Invalid argument: " << e.what();
    } catch (const exception &e) {
        cout << "Exceptiion: " << e.what();
    }

    delete m;

    return 0;
}
