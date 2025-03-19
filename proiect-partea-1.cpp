/// Proiect #1 Due March 24, 2025 11:59 PM

#include <iostream>
#include <cstring>
#include <limits> /// numeric_limits pentru a goli buffer-ul
using namespace std;

/// Cerinte
/*
    DONE Minim patru clase
    DONE Fiecare clasa are cel putin o functionalitate (daca am o clasa de tip Agenda atunci aceasta ar putea afisa datele disponibile dintr-o anumita luna)
    TODO Fiecare clasa trebuie sa implementeaze: 
    TODO constructorul fara parametrii
    TODO constructorul cu toti parametrii
    TODO cel putin doi constructori cu parametrii
    TODO constructorul de copiere
    TODO desconstructorul
    TODO forma supraincarcata a operatorului =
    TODO supraincarcarea operatorilor pentru stream << si >>
    TODO Fiecare clasa trebuie sa respecte principiul incapsularii datelor (cu setteri si getteri)
    TODO Fiecare clasa trebuie sa aiba cel putin trei atribute (proprietati) iar in tot proiectul sa regasim variabile de urmatoarele tipuri:
    DONE int sau long long
    TODO bool
    DONE char*
    DONE float
    DONE char
    DONE int* sau float*
    TODO static
    DONE const
    TODO Fiecare clasa trebuie sa implementeze supraincarcarea pentru urmatorii operatori:
    TODO operatorul de indexare - [] (care sa spunem daca avem o clasa de tip Eveniment iar in clasa Eveniment avem Participant* putem folosi operatorul de indexare pentru a accesa direct informatiile despre participant de la pozitia i)
    TODO operatorul ++ sau -- (postfixat sau prefixat, pentru postfixat aveti nevoie de un parametru dummy)
    TODO minim doi operatori matematici (+, *, / sau -) - (sa se respecte comutativitatea)
    TODO operatorul de verificare a egalitatii (==) (de exemplu avem doua obiecte de tip Elev si putem folosi supraincarcarea operatorului == pentru a verifica daca Elevii sunt din aceeasi clasa sau nu)
    TODO un operator conditional dintre (<, <=, >, >=)
    TODO Proiectul trebuie sa vina cu un meniu interactiv sau o forma de meniu prin care sa poata exemplifica functionalitatile implementate. (Ar trebui pentru sistemele de gestiune sa putem efectua CRUD-uri - Create Read Update Delete)
    TODO mentiune: Daca am o clasa Eveniment atunci as putea sa creez un Eveniment citind informatiile despre acesta precum: data inceput, data sfarsit, numar maxim de participanti, locatie, etc. Pot sa afisez toate evenimentele create folosind o variabila de tip static Eveniment* pentru a retine evenimentele intr-o lista (aveti grija la memory leaks). As putea sa selectez un eveniment dintr-o lista si sa ii actualizez atributele precum locatia sau / si datele de inceput final este problema voastra cum vreti sa gestionati actualizarea (cititi despre HTTP PATCH vs PUT). As putea elimina un eveniment din lista de evenimente pe baza unui cod (ID) sau a numelui.
*/

/// Ideea jocului: Bunicul Neculai este plecat intr-o vacanta la munte. De aceea, te-a rugat sa te ocupi de ferma lui pentru cateva saptamani. Crezi ca vei face fata?
/// Gameplay: Fiecare actiune este realizata pe parcursul unei zile. Dupa un anumit numar se zile se intampla nush ce.

class Jucator {
private:
    char denumireJucator[80];
    int nivelJucator;
protected:
public:
    Jucator() {
        strcpy(denumireJucator, "Anonim");
        nivelJucator = 0;
    }
    ~Jucator() {
        cout << denumireJucator << " a iesit din joc avand nivelul " << nivelJucator << endl;
    }
    void setName(const char* nume = "Abel Diriclet") {
        strcpy(denumireJucator, nume);
    }
    void showInfo() {
        cout << "--------------------------------------------\n";
        cout << "Jucator: " << denumireJucator << " | Nivel: " << nivelJucator << endl;
        cout << "--------------------------------------------\n";
    }
    void levelUp() {
        nivelJucator++;
        cout << "Hurray! A mai trecut o zi! Ai atins nivelul " << nivelJucator << endl;
    }
};

class Casa {
private:
    int nivelComfort, venitChirie;
    float taxe;
    char nivelReparatii[80];
protected:
public:
    /// Afiseaza informatiile despre casa: nivelComfort, nivelReparatii, venitChirie, taxe
};

class Teren {
private:
    int nivelIngrasamant, nivelProductie;
    float venit, taxe;
    long long resurseGrau, resurseCartofi, resurseMorcovi;
    int* niveleApa;
protected:
public:
    /// Afiseaza informatiile despre teren: nivelIngrasamant, nivelProductie, nivelApa, resurseGrau, resurseCartofi, resurse morcovi, venit, taxe
};

class Tarc {
private:
    int capacitateAnimale, resurseIgiena, resurseHrana;
    float venit;
protected:
public:
    /// Afiseaza informatiile despre tarc: capacitateAnimale, resurseIgiena, resurseHrana, venit
};

class Tractor {
private:
    int nivelBenzina, itp;
    char* reparatii[8];
protected:
public:
    /// Afiseaza informatiile despre tactor: nivelBenzina, reparatii, itp
};

void initializareJoc() {
    Jucator j;
    char numeleTau[80];
    j.showInfo();
    cout << "Fiind prima zi, intalnesti un vecin care s-a mutat de curand la ferma..." << endl;
    cout << "[Noul vecin]: Sal'tare tinere! Care-ti este numele dumitale?" << endl;
    cin.getline(numeleTau, 80);
    cout << "============================================\n";
    j.setName(numeleTau);
    j.levelUp();
    j.showInfo();
}

void introducere() {
    bool continuaJoc = false;
    cout << "Bunicul Neculai este plecat intr-o vacanta la munte.\nDe aceea, te-a rugat pe tine sa te ocupi de ferma lui pentru cateva saptamani.\nCrezi ca vei face fata?\nRaspunsul tau (0 - NU; 1 - DA): " << endl;
    cin >> continuaJoc;
    cout << "--------------------------------------------\n";
    cout << "============================================\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curatam buffer-ul, pentru numeric_limits trebuie sa includem biblioteca limits
    if (continuaJoc) {
        initializareJoc();
    } else {
        cout << "Imi pare rau sa aud asta! In acest caz nu am ce-ti face! Pe curand!\n";
    }
}

int main() {
    introducere();
    
    return 0;
}