/// Irimia David
/// Grupa 141
/// g++ .\colocviu2020simulare.cpp -o e.exe

////////////////////////////////////////
/// Simulare in timpul laboratorului ///
////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Masina {
private:
    int anul_inceperii_productiei, viteza_maxima, greutatea;
    string numele_modelului;
protected:
public:
    Masina(int anul_inceperii_productiei = 1980, int viteza_maxima = 180, int greutatea = 1800, string numele_modelului = "Opel") {
        this->anul_inceperii_productiei = anul_inceperii_productiei;
        this->viteza_maxima = viteza_maxima;
        this->greutatea = greutatea;
        this->numele_modelului = numele_modelului;
    }
    void setAn(int anul_inceperii_productiei = 1980) {
        this->anul_inceperii_productiei = anul_inceperii_productiei;
    }
    void setViteza(int viteza_maxima = 180) {
        this->viteza_maxima = viteza_maxima;
    }
    void setGreutate(int greutatea = 1800) {
        this->greutatea = greutatea;
    }
    void setNume(string numele_modelului) {
        this->numele_modelului = numele_modelului;
    }
};

class MasinaPeBazaDeCombustibiliFosili : virtual Masina {
private:
    string tipul_combustibilului; /// benzina si motorina
    int capacitatea_rezervorului;
protected:
public:
    MasinaPeBazaDeCombustibiliFosili(string tipul_combustibilului = "benzina", int capacitatea_rezervorului = 20) {
        this->tipul_combustibilului = tipul_combustibilului;
        this->capacitatea_rezervorului = capacitatea_rezervorului;
    }

    void setCombustibil(string tipul_combustibilului = "benzina") {
        this->tipul_combustibilului = tipul_combustibilului;
    }

    void setRezervor(int capacitatea_rezervorului = 20) {
        this->capacitatea_rezervorului = capacitatea_rezervorului;
    }
};

class MasinaElectrica : virtual Masina {
private:
    int capacitatea_bateriei;
protected:
public:
    MasinaElectrica(int capacitatea_bateriei = 1200) {
        this->capacitatea_bateriei = capacitatea_bateriei;
    }

    void setBaterie(int capacitatea_bateriei = 1200) {
        this->capacitatea_bateriei = capacitatea_bateriei;
    }
};

class MasinaHibrida : public MasinaPeBazaDeCombustibiliFosili, public MasinaElectrica {
private:
protected:
public:
};

int main () {
    int optiune = -1;
    do {
        cout << "---\n";
        cout << "Apasa 0 pentru a renunta\n";
        cout << "Apasa 1 pentru a adauga un nou model masina\n";
        cout << "Apasa 2 pentru a adauga o tranzactie\n";
        cout << "Apasa 3 pentru a afisa cel mai vandut model\n";
        cout << "Apasa 4 pentru a afisa modelul cu autonomia cea mai mare\n";
        cout << "Apasa 5 pentru a optimiza un anumit model\n";
        cout << "---\n";
        cout << "Introduceti optiunea aici (intre 0 si 5): ";
        cin >> optiune;
        cin.get(); /// golim buffer-ul
        if (optiune == 0) {
            continue;
        } else if (optiune == 1) {
            string tipul_masinii;
            cout << "===\n";
            cout << "Ati ales sa adaugati un nou model de masina\n";

            Masina* m = new Masina;
            int an, viteza, greutate; 
            string nume;
            cout << "Scrie anul in care a inceput productia acestei masini: ";
            cin >> an;
            cout << "Scrie viteza maxima a masinii: ";
            cin >> viteza;
            cout << "Scrie greutatea masinii: ";
            cin >> greutate;
            cout << "Scrie numele masinii: ";
            cin >> nume;
            cin.get();

            m->setAn(an);
            m->setViteza(viteza);
            m->setGreutate(greutate);
            m->setNume(nume);

            bool am_ales_masina = true;
            do {
                cout << "Optiuni: \n\tpe_baza_de_combustibili_fosili\n\telectrica\n\thibrid\n";
                cout << "Introduceti aici tipul noii masini: ";
                cin >> tipul_masinii;
                cin.get();
                cout << "===\n";
                if (tipul_masinii == "pe_baza_de_combustibili_fosili") {
                    cout << "Ati ales sa adaugati o masina pe baza de combustibili fosili\n";
                    am_ales_masina = true;
                    
                    MasinaPeBazaDeCombustibiliFosili* m1 = new MasinaPeBazaDeCombustibiliFosili;

                    string combustibil;
                    int capacitate;
                    
                    cout << "Scrie tipul de combustibil al masinii: ";
                    cin >> combustibil;
                    cin.get();
                    cout << "Scrie capacitatea: ";
                    cin >> capacitate;
                    
                    m1->setCombustibil(combustibil);
                    m1->setRezervor(capacitate);
                } else if (tipul_masinii == "electrica") {
                    cout << "Ati ales sa adaugati o masina electrica\n";
                    am_ales_masina = true;

                    MasinaElectrica* m2 = new MasinaElectrica;

                    int baterie;
                    cout << "Scrie capacitatea bateriei: ";
                    cin >> baterie;
                    m2->setBaterie(baterie);

                } else if (tipul_masinii == "hibrid") {
                    cout << "Ati ales sa adaugati o masini hibrid (si pe combustibili fosili si electrica)\n";
                    am_ales_masina = true;
                } else {
                    cout << "Nu cunosc acest tip de masina.\n";
                    am_ales_masina = false;
                }
            } while (!am_ales_masina);
            cout << "===\n";
        } else {
            cout << "Nu inteleg ce vrei sa faci! Alege un numar intre zero si cinci!\n";
        }
    } while (optiune);

    return 0;
}