/// Proiect #1 Due March 24, 2025 11:59 PM

#include <iostream>
#include <cstring>
using namespace std;

/// Cerinte
/*
    DONE Minim patru clase
    DONE Fiecare clasa are cel putin o functionalitate (daca am o clasa de tip Agenda atunci aceasta ar putea afisa datele disponibile dintr-o anumita luna)
    TODO Fiecare clasa trebuie sa implementeaze: 
    DONE constructorul fara parametrii
    DONE constructorul cu toti parametrii
    DONE cel putin doi constructori cu parametrii
    DONE constructorul de copiere
    DONE desconstructorul
    DONE forma supraincarcata a operatorului =
    DONE supraincarcarea operatorilor pentru stream << si >>
    TODO Fiecare clasa trebuie sa respecte principiul incapsularii datelor (cu setteri si getteri)
    DONE Fiecare clasa trebuie sa aiba cel putin trei atribute (proprietati) iar in tot proiectul sa regasim variabile de urmatoarele tipuri:
    DONE int sau long long
    DONE bool
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
    char* numeJucator;
    int nivelJucator;
    float monede;
protected:
public:
    /// Constructor fara parametrii
    Jucator() {
        strcpy(numeJucator, "Anonimus");
        nivelJucator = 0;
        monede = 0;
    }
    /// Constructor cu toti parametrii
    Jucator(const char* numeJucatorDefault, int nivelJucatorDefault, float monedeDefault) {
        numeJucator = new char[strlen(numeJucatorDefault) + 1];
        strcpy(numeJucator, numeJucatorDefault);
        nivelJucator = nivelJucatorDefault;
        monede = monedeDefault;
    }
    /// Constructor cu parametrii
    Jucator(const char* numeJucatorDefault, int nivelJucatorDefault) {
        numeJucator = new char[strlen(numeJucatorDefault) + 1];
        strcpy(numeJucator, numeJucatorDefault);
        nivelJucator = nivelJucatorDefault;
        monede = 0;
    }
    /// Constructor cu parametrii
    Jucator(int nivelJucatorDefault, float monedeDefault) {
        strcpy(numeJucator, "Anonimaroi");
        nivelJucator = nivelJucatorDefault;
        monede = monedeDefault;
    }
    /// Constructor de copiere
    Jucator(const Jucator& altJucator) {
        numeJucator = new char[strlen(altJucator.numeJucator) + 1];
        strcpy(numeJucator, altJucator.numeJucator);
        nivelJucator = altJucator.nivelJucator;
        monede = altJucator.monede;
    }
    /// Suprascrierea operatorului egal
    Jucator& operator=(const Jucator& altJucator) {
        if(this != &altJucator) { /// skip pentru j = j, de exemplu
            delete[] numeJucator;
            numeJucator = new char[strlen(altJucator.numeJucator) + 1];
            strcpy(numeJucator, altJucator.numeJucator);
            nivelJucator = altJucator.nivelJucator;
            monede = altJucator.monede;
        }
        return *this;
    }
    /// Destructor
    ~Jucator() {
        cout << numeJucator << " a iesit din joc avand nivelul " << nivelJucator << endl;
        delete[] numeJucator;
    }
    void setName(const char* nume = "Abel Diriclet") {
        delete[] numeJucator;
        numeJucator = new char[strlen(nume) + 1];
        strcpy(numeJucator, nume);
    }
    void showInfo() {
        cout << "-Jucator-----------------------------------------------------------------------------------------\n";
        cout << "Nume: " << numeJucator << " | Nivel: " << nivelJucator << " | Monede: " << monede << endl;
        cout << "-------------------------------------------------------------------------------------------------\n";
    }
    void levelUp(int contor = 1) {
        int castig = 20 * contor;
        monede += castig;
        nivelJucator += contor;
        cout << "Hurray! A mai trecut o zi! In plus, ai mai castigat si " << castig << " monede.\n";
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Jucator& j) {
        out << "Name: " << j.numeJucator << ", Level: " << j.nivelJucator << ", Points: " << j.monede;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Jucator& j) {
        cout << "Introdu numele jucatorului: ";
        in >> j.numeJucator;
        cout << "Cate nivele a terminat?: ";
        in >> j.nivelJucator;
        cout << "Cate monede a agonisit?: ";
        in >> j.monede;
        return in;
    }
};

class Joc {
private:
    int zi;
    bool gameOver;
    long long counterContinueGame;
protected:
public:
    /// Constructor fara parametrii
    Joc() {
        zi = 0;
        gameOver = false;
        counterContinueGame = 0; /// fiecare incrementare ar fi echivalentul a trecerii unei ore, realizez ca nu prea are sens insa trebe folosit si getter-ul, right?
    }
    /// Constructor cu toti parametrii
    Joc(int ziDefault, bool gameOverDefault, long long counterContinueGameDefault) {
        zi = ziDefault;
        gameOver = gameOverDefault;
        counterContinueGame = counterContinueGameDefault;
    }
    /// Constructor cu parametrii
    Joc(int ziDefault, bool gameOverDefault) {
        zi = ziDefault;
        gameOver = gameOverDefault;
        counterContinueGame = 0;
    }
    /// Constructor cu parametrii
    Joc(bool gameOverDefault, long long counterContinueGameDefault) {
        zi = 0;
        gameOver = gameOverDefault;
        counterContinueGame = counterContinueGameDefault;
    }
    /// Constructor de copiere
    Joc(const Joc& altJoc) {
        zi = altJoc.zi;
        gameOver = altJoc.gameOver;
        counterContinueGame = altJoc.counterContinueGame;
    }
    /// Suprascrierea operatorului egal
    Joc& operator=(const Joc& altJoc) {
        if(this != &altJoc) { 
            zi = altJoc.zi;
            gameOver = altJoc.gameOver;
            counterContinueGame = altJoc.counterContinueGame;
        }
        return *this;
    }
    /// Destructor
    ~Joc() {
        cout << "GameOver!\n";
    }
    /// Getter
    long long getCounterContiuneGame() {
        return counterContinueGame;
    }
    void showDay() {
        cout << "\n==============================================Ziua" << zi++ << "==============================================\n";
    }
    void continueGame() {
        char continuaJoc = '1';
        cout << "Apasa 1 pentru a continua jocul: ";
        cin >> continuaJoc;
        cin.ignore(1000, '\n'); /// eliminam \n din citirea anterioara 
        if (continuaJoc != '1') {
            cout << "Iesire din joc ...\n";
            exit(0); /// inchidem programul
        }
        cout << "=================================================================================================\n";
    }
    void menu(Joc& g, Jucator& j) { /// referintele obiectelor
        bool ruleazaMeniu = true;
        while (ruleazaMeniu) {
            int optiune = 0;
            cout << "\n Meniu-------------------------------------------------------------------------------------------\n";
            cout << "| 1 - Continua jocul | 2 - Despre jucator | 3 - Afla orele petrecute la ferma | 4 - Iesi din joc |\n";
            cout << " ------------------------------------------------------------------------------------------------\n";
            cout << "Alege o optiune din cele de mai sus [1,4]: ";
            cin >> optiune;
            switch (optiune) {
                case 1:
                    ruleazaMeniu = false;
                    break;
                case 2:
                    j.showInfo();
                    break;
                case 3:
                    cout << "Ai petrecut " << g.getCounterContiuneGame() << " ore la ferma bunicului!\n";
                    break;
                case 4:
                    cout << "Iesire din joc ...\n";
                    exit(0); /// termina complet programul
                default:
                    cout << "Nu inteleg ce vrei sa faci! Alege un numar intre 1 si 4: ";
            }
        }
        cout << "=================================================================================================\n";
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Joc& j) {
        out << "Game Day: " << j.zi << ", Game Over: " << (j.gameOver ? "DA" : "NU") << ", Game Counter: " << j.counterContinueGame;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Joc& j) {
        cout << "Introdu ziua curenta: ";
        in >> j.zi;
        cout << "Joc terminat? (1 - DA, 0 - NU): ";
        in >> j.gameOver;
        cout << "Introdu un numar ce reprezinta un contor al numarului de continuari ale jocului: ";
        in >> j.counterContinueGame;
        return in;
    }
};

class Casa {
private:
    int nivelComfort, venitChirie;
    float taxe;
    char listaReparatii[80];
protected:
public:
    /// Constructor fara parametrii
    Casa() {
        nivelComfort = 0;
        venitChirie = 0;
        taxe = 0;
        listaReparatii[0] = 'e';
    }
    /// Constructor cu toti parametrii
    Casa(int nivelComfortInitial = 0, int venitChirieInitial = 0, float taxeInitial = 0, char listaReparatiiInitial = 'e') {
        nivelComfort = nivelComfortInitial;
        venitChirie = venitChirieInitial;
        taxe = taxeInitial;
        listaReparatii[0] = listaReparatiiInitial;
    }
    /// Constructor cu parametrii
    Casa(int nivelComfortInitial = 0, int venitChirieInitial = 0) {
        nivelComfort = nivelComfortInitial;
        venitChirie = venitChirieInitial;
        taxe = 0;
        listaReparatii[0] = 'e';
    }
    /// Constructor cu parametrii
    Casa(float taxeInitial = 0, char listaReparatiiInitial = 'e') {
        nivelComfort = 0;
        venitChirie = 0;
        taxe = taxeInitial;
        listaReparatii[0] = listaReparatiiInitial;
    }
    /// Constructor de copiere
    Casa(const Casa& altaCasa) {
        nivelComfort = altaCasa.nivelComfort;
        venitChirie = altaCasa.venitChirie;
        taxe = altaCasa.taxe;
        listaReparatii[0] = altaCasa.listaReparatii[0];
    }
    /// Suprascrierea operatorului egal
    Casa& operator=(const Casa& altaCasa) {
        if(this != &altaCasa) { 
            nivelComfort = altaCasa.nivelComfort;
            venitChirie = altaCasa.venitChirie;
            taxe = altaCasa.taxe;
            listaReparatii[0] = altaCasa.listaReparatii[0];
        }
        return *this;
    }
    /// Destructor
    ~Casa() {
        cout << "Casa s-a prabusit.\n";
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Casa& c) {
        out << "Nivel comfort: " << c.nivelComfort << ", Venit chirie: " << c.venitChirie << ", Taxe: " << c.taxe << ", Lista reparatii: " << c.listaReparatii[0];
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Casa& c) {
        cout << "Introdu nivelul de comfort: ";
        in >> c.nivelComfort;
        cout << "Introdu venit chirie: ";
        in >> c.venitChirie;
        cout << "Introdu taxe: ";
        in >> c.taxe;
        cout << "Introdu lista reparatii: ";
        in >> c.listaReparatii[0];
        return in;
    }
};

class Teren {
private:
    int nivelIngrasamant, nivelProductie;
    float venit, taxe;
    long long resurseGrau, resurseCartofi, resurseMorcovi;
    int* niveleApa;
protected:
public:
    /// Constructor fara parametrii
    Teren() {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurseGrau = 0;
        resurseCartofi = 0;
        resurseMorcovi = 0;
        niveleApa = {0};
    }
    /// Constructor cu toti parametrii
    Teren(int nivelIngrasamantInitial = 0, int nivelProductieInitial = 0, float venitInitial = 0, float taxeInitial = 0, long long resurseGrauInitial = 0, long long resurseCartofiInitial = 0, long long resurseMorcoviInitial = 0, int* niveleApaInitial = nullptr) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = venitInitial;
        taxe = taxeInitial;
        resurseGrau = resurseGrauInitial;
        resurseCartofi = resurseCartofiInitial;
        resurseMorcovi = resurseMorcoviInitial;
        niveleApa = niveleApaInitial;
    }
    /// Constructor cu parametrii
    Teren(int nivelIngrasamantInitial = 0, int nivelProductieInitial = 0) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = 0;
        taxe = 0;
        resurseGrau = 0;
        resurseCartofi = 0;
        resurseMorcovi = 0;
        niveleApa = {0};
    }
    /// Constructor cu parametrii
    Teren(long long resurseMorcoviInitial = 0, int* niveleApaInitial = nullptr) {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurseGrau = 0;
        resurseCartofi = 0;
        resurseMorcovi = resurseMorcoviInitial;
        niveleApa = nullptr;
    }
    /// Constructor de copiere
    Teren(const Teren& altTeren) {
        nivelIngrasamant = altTeren.nivelIngrasamant;
        nivelProductie = altTeren.nivelProductie;
        venit = altTeren.venit;
        taxe = altTeren.taxe;
        resurseGrau = altTeren.resurseGrau;
        resurseCartofi = altTeren.resurseCartofi;
        resurseMorcovi = altTeren.resurseMorcovi;
        niveleApa = altTeren.niveleApa;
    }
    /// Suprascrierea operatorului egal
    Teren& operator=(const Teren& altTeren) {
        if(this != &altTeren) { 
            nivelIngrasamant = altTeren.nivelIngrasamant;
            nivelProductie = altTeren.nivelProductie;
            venit = altTeren.venit;
            taxe = altTeren.taxe;
            resurseGrau = altTeren.resurseGrau;
            resurseCartofi = altTeren.resurseCartofi;
            resurseMorcovi = altTeren.resurseMorcovi;
            niveleApa = altTeren.niveleApa;
        }
        return *this;
    }
    /// Destructor
    ~Teren() {
        cout << "Terenul a fost inundat\n";
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Teren& t) {
        out << "Nivel ingrasamant: " << t.nivelIngrasamant << ", nivel productie: " << t.nivelProductie << ", nivlee apa: " << t.niveleApa[0] << ", resurse grau: " << t.resurseGrau << ",resurse cartofi: " << t.resurseCartofi << ", resurse morcovi: " << t.resurseMorcovi << ", venit: " << t.venit << ", taxe: " << t.taxe;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Teren& t) {
        cout << "Introdu nivel ingrasamant: ";
        in >> t.nivelIngrasamant;
        cout << "Introdu nivel productie: ";
        in >> t.nivelProductie;
        cout << "Introdu nivele apa: ";
        in >> t.niveleApa[0];
        cout << "Introdu resurse grau: ";
        in >> t.resurseGrau;
        cout << "Introdu resurse cartofi: ";
        in >> t.resurseCartofi;
        cout << "Introdu resurse morcovi: ";
        in >> t.resurseMorcovi;
        cout << "Introdu venit: ";
        in >> t.venit;
        cout << "Introdu taxe: ";
        in >> t.taxe;
        return in;
    }
};

class Tarc {
private:
    int capacitateAnimale, resurseIgiena, resurseHrana;
    float venit;
protected:
public:
    /// Constructor fara parametrii
    Tarc() {
        capacitateAnimale = 0;
        resurseIgiena = 0;
        resurseHrana = 0;
        venit = 0;
    }
    /// Constructor cu toti parametrii
    Tarc(int capacitateAnimaleInitial = 0, int resurseIgienaInitial = 0, int resurseHranaInitial = 0, float venitInitial = 0) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = resurseHranaInitial;
        venit = venitInitial;
    }
    /// Constructor cu parametrii
    Tarc(int capacitateAnimaleInitial = 0, int resurseIgienaInitial = 0) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = 0;
        venit = 0;
    }
    /// Constructor cu parametrii
    Tarc(int resurseHranaInitial = 0, float venitInitial = 0) {
        capacitateAnimale = 0;
        resurseIgiena = 0;
        resurseHrana = resurseHranaInitial;
        venit = venitInitial;
    }
    /// Constructor de copiere
    Tarc(const Tarc& altTarc) {
        capacitateAnimale = altTarc.capacitateAnimale;
        resurseIgiena = altTarc.resurseIgiena;
        resurseHrana = altTarc.resurseHrana;
        venit = altTarc.venit;
    }
    /// Suprascrierea operatorului egal
    Tarc& operator=(const Tarc& altTarc) {
        if(this != &altTarc) { 
            capacitateAnimale = altTarc.capacitateAnimale;
            resurseIgiena = altTarc.resurseIgiena;
            resurseHrana = altTarc.resurseHrana;
            venit = altTarc.venit;
        }
        return *this;
    }
    /// Destructor
    ~Tarc() {
        cout << "Tarcul a fost spart.\n";
    }
    /// Afiseaza informatiile despre tarc: capacitateAnimale, resurseIgiena, resurseHrana, venit
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Tarc& f) {
        out << "Capacitate animale: " << f.capacitateAnimale << ", resurse igiena: " << f.resurseIgiena << ", resurse hrana: " << f.resurseHrana << ", venit: " << f.venit;
        return out;
    }

    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Tarc& f) {
        cout << "Introdu capacitate animale: ";
        in >> f.capacitateAnimale;
        cout << "Introdu resurse igiena: ";
        in >> f.resurseIgiena;
        cout << "Introdu resurse hrana: ";
        in >> f.resurseHrana;
        cout << "Introdu venit: ";
        in >> f.venit;
        return in;
    }
};

int main() {
    /// Ziua 0
    Joc g; /// g de la game, j e luat pentru jucator :)
    Jucator j; /// j de la jucator, bineinteles :)
    bool continuaJoc = true;
    g.showDay();
    cout << "Bunicul Neculai este plecat intr-o vacanta la munte.\n";
    g.continueGame();
    cout << "De aceea, te-a rugat pe tine sa te ocupi de ferma lui pentru cateva saptamani.\n";
    g.continueGame();
    cout << "Crezi ca vei face fata?\n";
    g.continueGame();

    /// Ziua 1
    char numeleTau[80];
    g.showDay();
    cout << "Fiind prima zi, intalnesti un vecin care s-a mutat de curand la ferma...\n";
    g.continueGame();
    cout << "[Noul vecin]: Sal'tare tinere! Care-ti este numele dumitale?\n";
    cin.getline(numeleTau, 80); /// getline for "Irimia David" and get for "Irimia", for example
    cin.get(); /// golim buffer-ul
    j.setName(numeleTau);
    g.continueGame();
    cout << "[Noul vecin]: " << numeleTau << ", ce nume frumos! Imi pare bine sa te intalnesc pe aici, " << numeleTau << "!\n";
    g.continueGame();
    cout << "[Noul vecin]: Eu sunt George Petru.\n";
    g.continueGame();
    j.levelUp();
    g.menu(g, j);
    j.showInfo();

    /// Ziua 2
    g.showDay();
    cout << "In cea de-a doua zi observi ca bunicul Neculai a lasat casa 'vraiste'.\n";
    g.menu(g, j);
    cout << "Cumva il intelegi ca era foarte ocupat cu treburile sale si de aceea si-a luat si el o bine-meritata vacanta.\n";
    g.menu(g, j);
    cout << "Prin urmare, decizi sa dai o mana de ajutor.\n";
    g.menu(g, j);
    cout << "Vazand pe usa frigiderului o lista de task-uri, observi, insa, ca nu sunt aranjate.\n";
    g.menu(g, j);
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
    g.menu(g, j);
    cout << "Bravo! Ai reusit sa faci " << punctajObtinut << " din cele 4 taskuri.\n";
    g.menu(g, j);
    cout << "Chiar daca ziua a doua a fost mai obositoare, s-a meritata sa castigi " << punctajObtinut << " nivel(e)!\n"; 
    g.menu(g, j);
    j.levelUp(punctajObtinut);
    g.menu(g, j);
    j.showInfo();

    /// Ziua 3
    g.showDay();

    return 0;
}
