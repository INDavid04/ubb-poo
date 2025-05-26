/// Laboratorul 13 - Un exemplu de colocviu din 2022

#include <iostream>
#include <list>
#include <string>

using namespace std;

class PachetClasic {
private:
    int numarMesePeZi; /// pe care animalul le va primi
    bool vreaAnimalSingur; /// se dorete ca animalul sa fie cazat singur in camera
    list<string> listaAlergeni = {}; /// ca: pui, vita, orez, etc.
protected:
public:
};

class PachetSport : virtual PachetClasic {
private:
    int numarPlimbari; /// zilnice a cate 30 minute fiecare; nu poate fi mai mare ca 5
protected:
public:
};

class PachetConfort : virtual PachetClasic {
private:
    list<string> listaActivitati = {}; /// ca: spalare, periere, joaca, dresaj, socializare; se pot alege maxim doua activitati zilnice pe durata cazarii
protected:
public:
};

class PachetVIP : virtual PachetClasic, virtual PachetConfort {
private:
    list<string> listaOre = {}; /// clientii pot alege orele de plimbare ale animalelor
    int durataPlimbare; /// minim 30 minute
    int numarActivitati; /// poate fi mai mare decat doi numarul activitatilor dorite din lista disponibila
protected:
public:
};

class FormularCazare {
private:
    string dataInceput, dataFinal, numePachet, detaliiAnimal, detaliiClient;
    double pretCazare; /// e pretul final de cazare
    int codFormular; /// unic
protected:
public:
    FormularCazare(string dataInceput, string dataFinal, string numePachet, string detaliiAnimal, string detaliiClient, double pretCazare, int codFormular) {
        this->dataInceput = dataInceput;
        this->dataFinal = dataFinal;
        this->numePachet = numePachet;
        this->detaliiAnimal = detaliiAnimal;
        this->detaliiClient = detaliiClient;
        this->pretCazare = pretCazare;
        this->codFormular = codFormular;
    }

    void afiseazaDataCodulPretul() {
        cout << "Formularul are data de inceput: " << dataInceput << ", codul: " << codFormular << " si pretul: " << pretCazare << "\n";
    }
};

class Client {
private:
    string numeClient, numarTelefon, adresa, CNP;
protected:
public:
};

class Animal {
    string numeAnimal, rasaAnimal;
    int varstaAnimal;
    int codFormular; /// acelasi cu codul unic al formularului de cazare
};

int main () {
    int optiune = -1;
    do {
        cout << "Apasa 1 pentru a adauga un nou formular\n";
        cout << "Apasa 2 pentru a afisa toate formularele cu detalii despre data de inceput a cazarii, codul si pretul acestora\n";
        cout << "Apasa 3 pentru a selecta un formular prin care se poate opta intre a afisa detalii despre oferta, animal sau client\n";
        cout << "Apasa 4 pentru afisarea tuturor formularelor ordonate crescator in functie de pret dintr-o anumita zi\n";
        cout << "Apasa 5 pentru a iesi complet de aici\n";
        cin >> optiune;
        if (optiune == 1) {
            string dataInceput, dataFinal, numePachet, detaliiAnimal, detaliiClient;
            double pretCazare;
            int codFormular;
            list<FormularCazare> listaFormulare = {};
            cout << "Introdu data de inceput a cazarii (YYYY/MM/DD)\n";
            cin >> dataInceput;
            cin.get();
            cout << "Introdu data de final a cazarii (YYYY/MM/DD)\n";
            cin >> dataFinal;
            cin.get();
            cout << "Introdu numele pachetului ales\n";
            cin >> numePachet;
            cin.get();
            cout << "Introdu detalii despre animal\n";
            cin >> detaliiAnimal;
            cin.get();
            cout << "Introdu detalii despre client\n";
            cin >> detaliiClient;
            cin.get();
            cout << "Introdu pretul final de cazare\n";
            cin >> pretCazare;
            cin.get();
            cout << "Introdu codul unic de formular\n";
            cin >> codFormular;
            cin.get();
            FormularCazare f (dataInceput, dataFinal, numePachet, detaliiAnimal, detaliiClient, pretCazare, codFormular);
            listaFormulare.push_back(f);
            f.afiseazaDataCodulPretul();
        } else if (optiune == 2) {
            cout << "afisez toate formularele\n";
        } else if (optiune == 3) {
            cout << "selectez formular\n";
        } else if (optiune == 4) {
            cout << "afisez formularele ordonate\n";
        } else if (optiune == 5) {
            cout << "iesire ...\n";
        } else {
            cout << "Nu pricep ce vrei sa fac! Alege un numar intre 1 si 5!\n";
        }
    } while (optiune != 5);

    return 0;
}
