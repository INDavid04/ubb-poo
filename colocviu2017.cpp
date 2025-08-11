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
    int numarCI;
    float medieBAC;
    string categorie;
protected:
public:
    Candidat(string nume, int serie, int numarCI, float medieBAC, string categorie) {
        nume = this->nume;
        serie = this->serie;
        numarCI = this->numarCI;
        medieBAC = this->medieBAC;
        categorie = this->categorie;
    }
};

class Formular : public Candidat {
private:
    static int cnt;
    int nr_inregistrare;
    list<Formular*> listaIF1;
    list<Formular*> listaIF2;
    list<Formular*> listaID1;
    list<Formular*> listaID2;
protected:
public:  
    Formular(int n = 1) {
        for (int i = 0; i < n; i++) {
            string nume_candidat;
            int serie_candidat;
            int numarCI_candidat;
            float medieBac_candidat;
            string categorie_candidat;

            nr_inregistrare = cnt++;
            cin >> nume_candidat >> serie_candidat >> numarCI_candidat >> medieBac_candidat >> categorie_candidat;
            
            if (categorie_candidat == "if1") {
                listaIF1.push_back(new Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBac_candidat, categorie_candidat));
            } else if (categorie_candidat == "if2") {
                listaIF2.push_back(new Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBac_candidat, categorie_candidat));
            } else if (categorie_candidat == "id1") {
                listaID1.push_back(new Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBac_candidat, categorie_candidat));
            } else if (categorie_candidat == "id2") {
                listaID2.push_back(new Candidat(nume_candidat, serie_candidat, numarCI_candidat, medieBac_candidat, categorie_candidat));
            } else {
                cout << "Categorie gresita! Alege intre: if1, if2, id1 si id2!";
            }
        }
    }

    void afisareListe() const {
        int dimListaIF1 = listaIF1.length(), dimListaIF2 = listaIF2.length(), dimListaID1 = listaID1.length(), dimListaID2 = listaID2.length();
        cout << "Lista IF1 are " << dimListaIF1 << " candidati:\n";
        for (int i = 0; i < dimListaIF1; i++) {
            cout << listaIF1[i] << " ";
        }
        cout << "\nLista IF2 are " << dimListaIF2 << " candidati:\n";
        for (int i = 0; i < dimListaIF2; i++) {
            cout << listaIF2[i] << " ";
        }
        cout << "\nLista ID1 are " << dimListaID1 << " candidati:\n";
        for (int i = 0; i < dimListaID1; i++) {
            cout << listaID1[i] << " ";
        }
        cout << "\nLista ID2 are " << dimListaID2 << " candidati:\n";
        for (int i = 0; i < dimListaID2; i++) {
            cout << listaID[i] << " ";
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
                cin >> numarCandidati;
                throw numarCandidati;
            } catch (int numarCandidati) {
                if (numarCandidati < 1) {
                    cout << "Nu pot adauga " << numarCandidati << " candidati!\n";
                    break;
                }
                f.Formular(numarCandidati);
            }
        } else if (optiune == 2) {
            f.afisareListe();
        } else if (opiune == 3) {
            cout << "3\n";
        } else if (optiune == 4) {
            cout << "4\n";
        } else {
            cout << "Nu pricep ce vrei sa fac! Alege un numar intre zero si patru!\n";
        }
    } while (optiune != 0);

    return 0;
}
