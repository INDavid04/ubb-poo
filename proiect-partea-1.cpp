/// Proiect #1 Due March 24, 2025 11:59 PM

#include <iostream>
#include <cstring>
// #include <limits> /// numeric_limits pentru a goli buffer-ul insa nu mai e nevoie, ne scapa cin.get()
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

class Joc {
private:
    int zi;
protected:
public:
    Joc() {
        zi = 0;
    }
    ~Joc() {
        cout << "GameOver!\n";
    }
    void showDay() {
        cout << "\n===============================================Ziua" << zi++ << "===============================================\n";
    }
    bool continueGame() {
        bool continuaJoc = false;
        cout << "Apasa 1 pentru a continua: ";
        cin >> continuaJoc; 
        cin.get();
        cout << "===================================================================================================\n";
        if (!continuaJoc) {
            return false;
        }
        return true;
    }
};

class Jucator {
private:
    char numeJucator[80];
    int nivelJucator;
    float monede;
protected:
public:
    Jucator() {
        strcpy(numeJucator, "Anonim");
        nivelJucator = 0;
        monede = 0;
    }
    ~Jucator() {
        cout << numeJucator << " a iesit din joc avand nivelul " << nivelJucator << endl;
    }
    void setName(const char* nume = "Abel Diriclet") {
        strcpy(numeJucator, nume);
    }
    void showInfo() {
        cout << "---------------------------------------------------------------------------------------------------\n";
        cout << "Jucator: " << numeJucator << " | Nivel: " << nivelJucator << " | Monede: " << monede << endl;
        cout << "---------------------------------------------------------------------------------------------------\n";
    }
    void levelUp(int contor = 1) {
        int castig = 20 * contor;
        monede += castig;
        nivelJucator += contor;
        cout << "Hurray! A mai trecut o zi! In plus, ai mai castigat si " << castig << " monede.\n";
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

int main() {
    /// Ziua 0
    Joc g; /// g de la game, j e luat pentru jucator :)
    g.showDay();
    cout << "Bunicul Neculai este plecat intr-o vacanta la munte.\n";
    if(!g.continueGame()) return 0;
    cout << "De aceea, te-a rugat pe tine sa te ocupi de ferma lui pentru cateva saptamani.\n";
    if(!g.continueGame()) return 0;
    cout << "Crezi ca vei face fata?\n";
    if(!g.continueGame()) return 0;

    /// Ziua 1
    Jucator j;
    char numeleTau[80];
    g.showDay();
    cout << "Fiind prima zi, intalnesti un vecin care s-a mutat de curand la ferma...\n";
    if(!g.continueGame()) return 0;
    cout << "[Noul vecin]: Sal'tare tinere! Care-ti este numele dumitale?" << endl;
    cin.getline(numeleTau, 80); /// getline for "Irimia David" and get for "Irimia", for example
    j.setName(numeleTau);
    if(!g.continueGame()) return 0;
    cout << "[Noul vecin]: " << numeleTau << ", ce nume frumos! Imi pare bine sa te intalnesc pe aici, " << numeleTau << "!\n";
    if(!g.continueGame()) return 0;
    cout << "[Noul vecin]: Eu sunt George Petru.\n";
    if(!g.continueGame()) return 0;
    j.levelUp();
    if(!g.continueGame()) return 0;
    j.showInfo();

    /// Ziua 2
    g.showDay();
    cout << "In cea de-a doua zi observi ca bunicul Neculai a lasat casa 'vraiste'.\n";
    if(!g.continueGame()) return 0;
    cout << "Cumva il intelegi ca era foarte ocupat cu treburile sale si de aceea si-a luat si el o bine-meritata vacanta.\n";
    if(!g.continueGame()) return 0;
    cout << "Prin urmare, decizi sa dai o mana de ajutor.\n";
    if(!g.continueGame()) return 0;
    cout << "Vazand pe usa frigiderului o lista de task-uri, observi, insa, ca nu sunt aranjate.\n";
    if(!g.continueGame()) return 0;
    cout << "Cum ai aranja datoriile?\n1 - Spala WC\n2 - Du gunoiul\n3 - Spala aragazul\n4 - Da cu aspiratorul\n(Nota: Scrie nuamrul de ordine al task-urilor separate prin caracterul spatiu!)\n";
    cout << "Ordinea mea: ";
    int ordineaTa[4] = {0}, ordineaMea[4] = {3, 4, 1, 2};;
    int punctajObtinut = 0;
    for (int i = 0; i < 4; i++) {
        cin >> ordineaTa[i];
        if (ordineaMea[i] == ordineaTa[i]) {
            punctajObtinut++;
        }
    }
    if(!g.continueGame()) return 0;
    cout << "Bravo! Ai reusit sa faci " << punctajObtinut << " din cele 4 taskuri.\n";
    if(!g.continueGame()) return 0;
    cout << "Chiar daca ziua a doua a fost mai obositoare, s-a meritata sa castigi " << punctajObtinut << " nivel(e)!\n"; 
    j.levelUp(punctajObtinut);
    if(!g.continueGame()) return 0;
    j.showInfo();

    /// Ziua 3
    g.showDay();

    return 0;
}
