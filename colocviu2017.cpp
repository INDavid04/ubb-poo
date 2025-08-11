// 2025-08-11-14-02-15-25

#include <iostream>
#include <string>
#include <list>

using namespace std;

/// Candidat: nume, seria, numarCI, medieBAC, categorie (la categorie putem avea 1 pentru prima si 2 pentru a doua facultate)

class Candidat {
private:
    string nume;
    int serie;
    string numarCI;
    float medieBAC;
    string categorie;
protected:
public:
    Candidat(string nume, int serie, string numarCI, float medieBAC, string categorie) {
        this->nume = nume;
        this->serie = serie;
        this->numarCI = numarCI;
        this->medieBAC = medieBAC;
        this->categorie = categorie;
    }
    void afisare() const {
        cout << nume << " " << serie << " " << numarCI << " " << medieBAC << " " << categorie << "\n";
    }
};

class Formular {
private:
    static int cnt;
    int nr_inregistrare;
    list<Candidat> listaIF1, listaIF2, listaID1, listaID2;
protected:
public:  
    void adaugaCandidati(int n = 1) {
        for (int i = 0; i < n; i++) {
            string nume_candidat;
            int serie_candidat;
            string numarCI_candidat;
            float medieBAC_candidat;
            string categorie_candidat;

            /// TODO: fix: infinite loop
            nr_inregistrare = cnt++;
            if (i == 0) {
                cin.ignore(); /// curatam bufferul doar la primul candidat
            }
            cout << "Nume: "; getline(cin, nume_candidat);
            cout << "Serie: "; cin >> serie_candidat; 
            cout << "Numar CI: "; cin >> numarCI_candidat;
            cout << "Medie BAC: "; cin >> medieBAC_candidat;
            cout << "Categorie: "; cin >> categorie_candidat;

            if (categorie_candidat == "if1") {
                listaIF1.push_back(Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBAC_candidat, categorie_candidat));
            } else if (categorie_candidat == "if2") {
                listaIF2.push_back(Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBAC_candidat, categorie_candidat));
            } else if (categorie_candidat == "id1") {
                listaID1.push_back(Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBAC_candidat, categorie_candidat));
            } else if (categorie_candidat == "id2") {
                listaID2.push_back(Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBAC_candidat, categorie_candidat));
            } else {
                cout << "Categorie gresita! Alege intre: if1, if2, id1 si id2!";
            }
        }
    }

    void afisareListe() const {
        int dimListaIF1 = listaIF1.size(), dimListaIF2 = listaIF2.size(), dimListaID1 = listaID1.size(), dimListaID2 = listaID2.size();
        cout << "Lista IF1 are " << dimListaIF1 << " candidati:\n";
        for (auto &candidat : listaIF1) {
            candidat.afisare();
        }
        cout << "\nLista IF2 are " << dimListaIF2 << " candidati:\n";
        for (auto &candidat : listaIF2) {
            candidat.afisare();
        }
        cout << "\nLista ID1 are " << dimListaID1 << " candidati:\n";
        for (auto &candidat : listaID1) {
            candidat.afisare();
        }
        cout << "\nLista ID2 are " << dimListaID2 << " candidati:\n";
        for (auto &candidat : listaID2) {
            candidat.afisare();
        }
        cout << "\nIn total: " << dimListaIF1 + dimListaIF2 + dimListaID1 + dimListaID2 << " candidati\n";
    }
};

int Formular::cnt = 1;

int main() {
    Formular f;
    int optiune;
    do {
        cout << "Apasa 0 pentru a iesi din meniu\n";
        cout << "Apasa 1 pentru a adauga n candidati\n";
        cout << "Apasa 2 pentru a afisa numarul si listele cu toti candidatii inscrisi la fiecare sectiune de admitere, in ordinea depunerii dosarelor\n";
        cout << "Apasa 3 pentru a afisa listele cu toti candidatii declarati admisi la fiecare sectiune de admitere (daca media >= 5 si pozitia <= numar de locuri, descrescator dupa media de admitere)\n";
        cout << "Apasa 4 pentru a afisa toti candidatii care s-au inscris la ambele forme de invatamant si au fost declarati admisi macar la una\n";   
        cin >> optiune;
        if (optiune == 0) {
            cout << "Iesire...\n";
            break;
        } else if (optiune == 1) {
            int numarCandidati;

            try {
                cout << "Numar candidati: ";
                cin >> numarCandidati;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw string("Input invalid: Introdu un numar intreg!\n");
                }
                if (numarCandidati < 1) {
                    throw numarCandidati;
                }
                f.adaugaCandidati(numarCandidati);
            } catch (int numarCandidati) {
                cout << "Nu pot adauga " << numarCandidati << " candidati!\n";
            } catch (string &errorString) {
                cout << errorString;
            }
        } else if (optiune == 2) {
            f.afisareListe();
        } else if (optiune == 3) {
            cout << "3\n";
        } else if (optiune == 4) {
            cout << "4\n";
        } else {
            cout << "Nu pricep ce vrei sa fac! Alege un numar intre zero si patru!\n";
        }
    } while (optiune != 0);

    return 0;
}
