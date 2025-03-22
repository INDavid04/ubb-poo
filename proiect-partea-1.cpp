/// Proiect #1 Due March 24, 2025 11:59 PM

#include <iostream>
#include <cstring>
using namespace std;

/// Cerinte
/*
    DONE Minim patru clase
    DONE Fiecare clasa are cel putin o functionalitate (daca am o clasa de tip Agenda atunci aceasta ar putea afisa datele disponibile dintr-o anumita luna)
    DONE Fiecare clasa trebuie sa implementeaze: 
    DONE constructorul fara parametrii
    DONE constructorul cu toti parametrii
    DONE cel putin doi constructori cu parametrii
    DONE constructorul de copiere
    DONE desconstructorul
    DONE forma supraincarcata a operatorului =
    DONE supraincarcarea operatorilor pentru stream << si >>
    DONE Fiecare clasa trebuie sa respecte principiul incapsularii datelor (cu setteri si getteri)
    DONE Fiecare clasa trebuie sa aiba cel putin trei atribute (proprietati) iar in tot proiectul sa regasim variabile de urmatoarele tipuri:
    DONE int sau long long
    DONE boolf
    DONE char*
    DONE float
    DONE char
    DONE int* sau float*
    DONE static
    DONE const
    DONE Fiecare clasa trebuie sa implementeze supraincarcarea pentru urmatorii operatori:
    DONE operatorul de indexare - [] (care sa spunem daca avem o clasa de tip Eveniment iar in clasa Eveniment avem Participant* putem folosi operatorul de indexare pentru a accesa direct informatiile despre participant de la pozitia i)
    DONE operatorul ++ sau -- (postfixat sau prefixat, pentru postfixat aveti nevoie de un parametru dummy)
    DONE minim doi operatori matematici (+, *, / sau -) - (sa se respecte comutativitatea)
    DONE operatorul de verificare a egalitatii (==) (de exemplu avem doua obiecte de tip Elev si putem folosi supraincarcarea operatorului == pentru a verifica daca Elevii sunt din aceeasi clasa sau nu)
    DONE un operator conditional dintre (<, <=, >, >=)
    DONE Proiectul trebuie sa vina cu un meniu interactiv sau o forma de meniu prin care sa poata exemplifica functionalitatile implementate. (Ar trebui pentru sistemele de gestiune sa putem efectua CRUD-uri - Create Read Update Delete)
    DONE mentiune: Daca am o clasa Eveniment atunci as putea sa creez un Eveniment citind informatiile despre acesta precum: data inceput, data sfarsit, numar maxim de participanti, locatie, etc. Pot sa afisez toate evenimentele create folosind o variabila de tip static Eveniment* pentru a retine evenimentele intr-o lista (aveti grija la memory leaks). As putea sa selectez un eveniment dintr-o lista si sa ii actualizez atributele precum locatia sau / si datele de inceput final este problema voastra cum vreti sa gestionati actualizarea (cititi despre HTTP PATCH vs PUT). As putea elimina un eveniment din lista de evenimente pe baza unui cod (ID) sau a numelui.
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
        numeJucator = new char[40];
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
    /// Setter
    void setName(const char* nume = "Abel Diriclet") {
        delete[] numeJucator;
        numeJucator = new char[strlen(nume) + 1];
        strcpy(numeJucator, nume);
    }
    /// Getter
    const char* getName() {
        return numeJucator;
    }
    float getMonede() {
        return monede;
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
    /// Supraincarcare operator ++ prefixat
    // Jucator& operator++() {
    //     nivelJucator++;
    //     monede += 20;
    //     return *this;
    // }
    /// Supraincarcare operator -- postfixat
    // Jucator operator--(int) {
    //     Jucator temp = *this;
    //     if (nivelJucator > 1) nivelJucator--;
    //     return temp;
    // }
    /// Operator ==
    bool operator==(const Jucator& altJucator) const {
        return this->nivelJucator == altJucator.nivelJucator;
    }
    void showInfo() {
        cout << "-Jucator-----------------------------------------------------------------------------------------\n";
        cout << "Nume: " << numeJucator << " | Nivel: " << nivelJucator << " | Monede: " << monede << endl;
        cout << "-------------------------------------------------------------------------------------------------\n";
    }
    void levelUp(int contor = 1) {
        monede += 20 * contor;
        nivelJucator++;
        cout << "Hurray! A mai trecut o zi! In plus, ai mai castigat si " << 20 * contor << " monede.\n";
    }
    void moneyUp(float money = 0) {
        monede += money;
    }
    void moneyDown(float money = 0) {
        monede -= money;
    }
};

class Joc {
private:
    int zi;
    bool gameOver;
    static long long counterContinueGame;
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
        cout << "Joc finalizat! Ati petrecut " << counterContinueGame << " ore la ferma bunicului.\n";
    }
    /// Setter
    void setDay(int specificDay = 0) {
        zi = specificDay;
    }
    /// Getter
    static long long getCounterContiuneGame() {
        return counterContinueGame;
    }
    void separator() {
        cout << "\n=================================================================================================\n\n";
    }
    void showDay() {
        cout << "\n==============================================Ziua" << zi++ << "==============================================\n\n";
    }
    void continueGame() {
        counterContinueGame++;
        char continuaJoc = '1';
        cout << "Apasa 1 pentru a continua jocul: ";
        cin >> continuaJoc;
        cin.get();
        if (continuaJoc != '1') {
            cout << "Iesire din joc ...\n";
            exit(0); /// inchidem programul
        }
        cout << "\n=================================================================================================\n\n";
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
            cin.get();
            cout << "\n=================================================================================================\n\n";
            switch (optiune) {
                case 1:
                    counterContinueGame++;
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
        if (ruleazaMeniu) {
            cout << "\n=================================================================================================\n";
        }
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
    char nivelComfort[10]; 
    int venitChirie;
    float taxe;
protected:
public:
    /// Constructor fara parametrii
    Casa() {
        strcpy(nivelComfort, "low");
        venitChirie = 0;
        taxe = 10;
    }
    /// Constructor cu toti parametrii
    Casa(const char* nivelComfortInitial, int venitChirieInitial, float taxeInitial) {
        strcpy(nivelComfort, nivelComfortInitial);
        venitChirie = venitChirieInitial;
        taxe = taxeInitial;
    }
    /// Constructor cu parametrii
    Casa(const char* nivelComfortInitial, int venitChirieInitial) {
        strcpy(nivelComfort, nivelComfortInitial);
        venitChirie = venitChirieInitial;
        taxe = 0;
    }
    /// Constructor cu parametrii
    Casa(int venitChirieInitial, float taxeInitial) {
        strcpy(nivelComfort, "low");
        venitChirie = venitChirieInitial;
        taxe = taxeInitial;
    }
    /// Constructor de copiere
    Casa(const Casa& altaCasa) {
        strcpy(nivelComfort, altaCasa.nivelComfort);
        venitChirie = altaCasa.venitChirie;
        taxe = altaCasa.taxe;
    }
    /// Suprascrierea operatorului egal
    Casa& operator=(const Casa& altaCasa) {
        if(this != &altaCasa) { 
            strcpy(nivelComfort, altaCasa.nivelComfort);
            venitChirie = altaCasa.venitChirie;
            taxe = altaCasa.taxe;
        }
        return *this;
    }
    /// Destructor
    ~Casa() {
        cout << "Desi casa este a lui, vrea sa stii ca usa iti e mereu deschisa.\n";
    }
    /// Setter
    void setComfort(const char* status = "low") {
        strcpy(nivelComfort, status);
    }
    void setChirie() {
        if (strcmp(nivelComfort, "low") == 0) {
            venitChirie = 50;
        } else if (strcmp(nivelComfort, "medium") == 0) {
            venitChirie = 100;
        } else {
            venitChirie = 200;
        }
    }
    /// Getter
    int getChirie() {
        return venitChirie;
    }
    float getTaxa() {
        return taxe;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Casa& c) {
        out << "Nivel comfort: " << c.nivelComfort << ", Venit chirie: " << c.venitChirie << ", Taxe: " << c.taxe;
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
        return in;
    }
};

class Teren {
private:
    int nivelIngrasamant, nivelProductie;
    float venit, taxe;
    long long resurse[3];
protected:
public:
    /// Constructor fara parametrii
    Teren() {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurse[0] = 0; /// grau
        resurse[1] = 0; /// cartofi
        resurse[2] = 0; /// morcovi
    }
    /// Constructor cu toti parametrii
    Teren(int nivelIngrasamantInitial, int nivelProductieInitial, float venitInitial, float taxeInitial, long long resurseGrauInitial, long long resurseCartofiInitial, long long resurseMorcoviInitial) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = venitInitial;
        taxe = taxeInitial;
        resurse[0] = resurseGrauInitial;
        resurse[1] = resurseCartofiInitial;
        resurse[2] = resurseMorcoviInitial;
    }
    /// Constructor cu parametrii
    Teren(int nivelIngrasamantInitial, int nivelProductieInitial) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = 0;
        taxe = 0;
        resurse[0] = 0;
        resurse[1] = 0;
        resurse[2] = 0;
    }
    /// Constructor cu parametrii
    Teren(long long resurseMorcoviInitial) {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurse[0] = 0;
        resurse[1] = 0;
        resurse[2] = resurseMorcoviInitial;
    }
    /// Constructor de copiere
    Teren(const Teren& altTeren) {
        nivelIngrasamant = altTeren.nivelIngrasamant;
        nivelProductie = altTeren.nivelProductie;
        venit = altTeren.venit;
        taxe = altTeren.taxe;
        resurse[0] = altTeren.resurse[0];
        resurse[0] = altTeren.resurse[1];
        resurse[0] = altTeren.resurse[2];
    }
    /// Suprascrierea operatorului egal
    Teren& operator=(const Teren& altTeren) {
        if(this != &altTeren) { 
            nivelIngrasamant = altTeren.nivelIngrasamant;
            nivelProductie = altTeren.nivelProductie;
            venit = altTeren.venit;
            taxe = altTeren.taxe;
            resurse[0] = altTeren.resurse[0];
            resurse[1] = altTeren.resurse[1];
            resurse[2] = altTeren.resurse[2];
        }
        return *this;
    }
    // Supraincarcare operator +
    Teren operator+(const Teren& altTeren) const {
        return Teren(this->nivelProductie + altTeren.nivelProductie);
    }
    // Supraincarcare operator *
    Teren operator*(int factor) const {
        return Teren(this->nivelProductie * factor);
    }
    /// Destructor
    ~Teren() {
        cout << "Bineinteles ca nu va uita sa aiba grija si de teren.\n";
    }
    /// Supraincarcare operator de indexare adica []
    long long operator[](int index) const {
        if (index >= 0 && index < 3) return resurse[index];
        return -1; /// i.e. nu-i valid
    }
    /// Setter
    void setIngrasamant(int cantitate = 0) {
        nivelIngrasamant = cantitate;
    }
    void setTaxa(float monede = 0) {
        taxe = monede;
    }
    /// Getter
    long long getGrau() {
        return resurse[0];
    }
    long long getCartofi() {
        return resurse[1];
    }
    long long getMorcovi() {
        return resurse[2];
    }
    float getTaxa() {
        return taxe;
    }
    float getVenit() {
        return venit;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Teren& t) {
        out << "Nivel ingrasamant: " << t.nivelIngrasamant << ", nivel productie: " << t.nivelProductie << ", resurse grau: " << t.resurse[0] << ",resurse cartofi: " << t.resurse[1] << ", resurse morcovi: " << t.resurse[2] << ", venit: " << t.venit << ", taxe: " << t.taxe;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Teren& t) {
        cout << "Introdu nivel ingrasamant: ";
        in >> t.nivelIngrasamant;
        cout << "Introdu nivel productie: ";
        in >> t.nivelProductie;
        cout << "Introdu resurse grau: ";
        in >> t.resurse[0];
        cout << "Introdu resurse cartofi: ";
        in >> t.resurse[1];
        cout << "Introdu resurse morcovi: ";
        in >> t.resurse[2];
        cout << "Introdu venit: ";
        in >> t.venit;
        cout << "Introdu taxe: ";
        in >> t.taxe;
        return in;
    }
    /// Operator < 
    bool operator<(const Teren& altTeren) const {
        return this->nivelProductie < altTeren.nivelProductie;
    }
    void cumparaResurse(int index, long long cantitate) {
        if (index >= 0 && index <= 2) {
            resurse[index] += cantitate;
            venit += resurse[index] * cantitate * 0.2;
        }
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
        capacitateAnimale = 15;
        resurseIgiena = 5;
        resurseHrana = 10;
        venit = 20;
    }
    /// Constructor cu toti parametrii
    Tarc(int capacitateAnimaleInitial, int resurseIgienaInitial, int resurseHranaInitial, float venitInitial) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = resurseHranaInitial;
        venit = venitInitial;
    }
    /// Constructor cu parametrii
    Tarc(int capacitateAnimaleInitial, int resurseIgienaInitial) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = 0;
        venit = 0;
    }
    /// Constructor cu parametrii
    Tarc(int resurseHranaInitial, float venitInitial) {
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
        cout << "Bunicul Neculai s-a intors si este bucuros sa ingrijeasca de noile animalute.\n";
    }
    /// Setter
    void setAnimale(int capacitate = 0) {
        capacitateAnimale = capacitate;
    }
    /// Getter
    float getVenit() {
        return venit;
    }
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
    void cumparaAnimale(int cantitate = 0) {
        capacitateAnimale += cantitate;
        venit += cantitate * 0.2;
    }
};

long long Joc::counterContinueGame = 0;  /// inigializam variabila statica counterContinueGame

int main() {
    /// Ziua 0
    Joc g; /// g de la game, j e luat pentru jucator :)
    Jucator j; /// j de la jucator, bineinteles :)
    bool continuaJoc = true;
    g.showDay();
    cout << "Bunicul Neculai este plecat intr-o vacanta la munte.\n";
    g.continueGame();
    cout << "De aceea, te-a rugat pe tine sa te ocupi de ferma lui pentru cateva zile.\n";
    g.continueGame();
    cout << "Crezi ca vei face fata?\n";
    g.continueGame();

    /// Ziua 1
    char numeleTau[80];
    g.showDay();
    cout << "Fiind prima zi, intalnesti un vecin care s-a mutat de curand la ferma ...\n";
    g.continueGame();
    cout << "[Noul vecin]: Sal'tare tinere! Care-ti este numele dumitale?\n";
    cin.getline(numeleTau, 80); /// getline for "Irimia David" and get for "Irimia", for example
    j.setName(numeleTau);
    g.continueGame();
    cout << "[Noul vecin]: " << numeleTau << ", ce nume frumos!\n";
    g.continueGame();
    cout << "Imi pare bine sa te intalnesc pe aici, " << numeleTau << "!\n";
    g.continueGame();
    cout << "[Noul vecin]: Eu sunt George Petru.\n";
    g.continueGame();
    j.levelUp();
    // j++; /// in loc de j.levelUp();
    g.menu(g, j);

    /// Ziua 2
    g.showDay();
    cout << "In cea de-a doua zi observi ca bunicul Neculai a lasat casa 'vraiste'.\n";
    g.menu(g, j);
    cout << "Cumva il intelegi ca era foarte ocupat cu treburile sale.\n";
    g.menu(g, j);
    cout << "Tocmai de aceea si-a luat si el o bine-meritata vacanta.\n";
    g.menu(g, j);
    cout << "Prin urmare, decizi sa dai o mana de ajutor.\n";
    g.menu(g, j);
    cout << "Vazand pe usa frigiderului o lista de task-uri, observi, insa, ca nu sunt aranjate.\n";
    g.menu(g, j);
    cout << "Cum ai aranja datoriile?\n1 - Spala WC\n2 - Du gunoiul\n3 - Spala aragazul\n4 - Da cu aspiratorul\n(Nota: Scrie numarul de ordine al task-urilor separate prin caracterul spatiu!)\n";
    cout << "Ordinea mea: ";
    int ordineaTa[4] = {0}, ordineaMea[4] = {3, 4, 1, 2};;
    int punctajObtinut = 0;
    for (int i = 0; i < 4; i++) {
        cin >> ordineaTa[i];
        cin.get();
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

    /// Ziua 3
    g.showDay();
    Casa c;
    Teren t;
    int aux = 0;
    cout << "Nici bine nu te-ai trezit in a treia zi, ca iti bate cineva la usa ...\n";
    g.menu(g, j);
    cout << "[George]: Vecine, ziua asta nu a inceput deloc bine!\n";
    g.menu(g, j);
    cout << "[George]: Azi noapte a luat foc hambarul si focul s-a extins pana ...\n";
    g.menu(g, j);
    cout << "[George]: Pana la casa noastra! Iti vine sa crezi asa ceva, " << j.getName() << "?\n";
    g.menu(g, j);
    cout << "[George]: Ai fii amabil sa ne gazduiesti pe mine si pe familia mea?\n";
    g.menu(g, j);
    cout << "[George]: Bineinteles, contra-cost: 50 monede pe zi!\n";
    g.menu(g, j);
    cout << "[George]: Multumim foarte mult, " << j.getName() << "!\n";
    g.menu(g, j);
    cout << "Facanduti-se mila de vecin, hotarasti sa ii dai resursele tale de grau, cartofi si morcovi.\n";
    g.menu(g, j);
    cout << "Ajuns in piata, vanzatoarea te intreaba ce cantitate doresti din fiecare:\n";
    g.menu(g, j);
    cout << "[Vanzatoarea]: 1 leu kilu' de grau. Cate kile vrei, tinere?\n";
    cin >> aux;
    while(aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 1 leu kilu' de grau. Cate kile vrei, tinere?\n";
        cin >> aux;
    }
    j.moneyDown(aux);
    t.cumparaResurse(0, aux);
    g.menu(g, j);
    cout << "[Vanzatoarea]: 5 lei kilu' de cartofi. Cat sa-ti dau?\n";
    cin >> aux;
    while(5 * aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 5 lei kilu' de cartofi. Cat sa-ti dau?\n";
        cin >> aux;
    }
    j.moneyDown(5 * aux);
    t.cumparaResurse(1, aux);
    g.menu(g, j);
    cout << "[Vanzatoarea]: 3 lei kilu' de morcovi. Cate kile?\n";
    cin >> aux;
    while(3 * aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 3 lei kilu' de morcovi. Cate kile?\n";
        cin >> aux;
    }
    j.moneyDown(3 * aux);
    t.cumparaResurse(2, aux);
    g.menu(g, j);
    j.levelUp();
    g.menu(g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g.menu(g, j);
    c.setChirie();
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g.menu(g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g.menu(g, j);

    /// Ziua 4
    g.showDay();
    Tarc f;
    cout << "In ziua a patra, planuiesti sa ii faci o bucurie bunicului Neculai.\n";
    g.menu(g, j);
    cout << "Ce poate fi mai bun decat niste animale? ... \n";
    g.menu(g, j);
    cout << "Mai multe animale :)\n";
    g.menu(g, j);
    cout << "Numai bine, ca au trecut niste negustori prin zona cu niste oferte irefuzabile ...\n";
    g.menu(g, j);
    cout << "[" << j.getName() << "]: Ziua buna! Mai lasati din pret?\n";
    g.menu(g, j);
    cout << "[Negustorii]: Buna sa iti fie si inima! Ti se pare ca avem noi cumva marfa ieftina?\n";
    g.menu(g, j);
    cout << "[" << j.getName() << "]: Oh! N-am vrut sa intelegeti gresit! Imi pare rau!\n";
    g.menu(g, j);
    cout << "[" << j.getName() << "]: Ce voiam sa zic este ca sunt interesat de o oferta!\n";
    g.menu(g, j);
    cout << "[Negustorii]: Aha! Daca vrei oferta ...\n";
    g.menu(g, j);
    cout << "[Negustorii]: Uite aici una care n-are cum sa nu iti placa!\n";
    g.menu(g, j);
    cout << "[Negustorii]: Ce alegi?\n";
    cout << "1 - 2 cai la pret de unu' (40) | 2 - 3 porci la pret de 2 (70) | 3 - Refuza oferta\n";
    cin >> aux;
    cin.get();
    g.separator();
    if (j.getMonede() < 40 || (j.getMonede() < 70 && aux == 2)) {
        cout << "[Negustorii]: Sorry man! Deoarece nu ai bani, nu ai incotro decat sa refuzi oferta!\n";
        // j--; /// just for fun, ne imaginam ca ne iau negustorii un nivel pentru ca le-am pierdut timpul :)
        cout << "Ati mai pierdut un nivel!\n";
    } else if (aux == 1) {
        cout << "[Negustorii]: Buna afacere! Sa te bucuri de cai!\n";
        j.moneyDown(40);
        f.cumparaAnimale(2);
    } else if (aux == 2) {
        cout << "[Negustorii]: Buna afac1ere! Sa te bucuri de porci!\n";
        j.moneyDown(70);
        f.cumparaAnimale(3);
    } else if (aux == 3) {
        cout << "[Negustorii]: Nicio problema! Ne mai auzim cand dai de bani!\n";
    }
    g.menu(g, j);
    j.levelUp();
    g.menu(g, j);
    t.setTaxa(5);
    cout << "Taxa pe teren a crescut la " << t.getTaxa() << " monede!\n";
    g.menu(g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g.menu(g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g.menu(g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g.menu(g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g.menu(g, j);
    cout << "\nDetalii finale\n";
    j.showInfo();
    g.menu(g, j);

    return 0;
}
