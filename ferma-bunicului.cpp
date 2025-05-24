/// Ferma bunicului - Proiect, Programare Orientata pe Obiecte, Irimia David

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include "ferma-jucator.h"
#include "ferma-joc.h"
#include "ferma-casa.h"
#include "ferma-teren.h"
#include "ferma-tarc.h"
#include "ferma-animal.h" /// contains also the following classes: Cal, Arab, Mustang, Porc
#include "ferma-aliment.h"
using namespace std;

/// NICE: move this comments into a markdown file and organize the code just a little :)
/// Partea #1 Due March 24, 2025 11:59 PM
/*
## Mandatory
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

/// Partea #2 Due April 13, 2025 11:59 PM
/*
## Mandatory
    DONE Minim 5 clase care vor avea implementate cel puțin o funcționalitate
    DONE Exemplifica conceptul de virtualizare
    DONE Foloseste conceptul de moștenire (minim 3 clase în ierarhie)
    DONE Foloseste conceptul de polimorfism
    DONE Minim o clasă abstractă / interfață
    DONE Moștenirea în diamant (moștenirea multiplă) corect rezolvată
    DONE Citiți despre HTTP PATCH vs. PUT
## Nice
    TODO Diagrama de decizie
    TODO Adauga inventar
    TODO La supraincarcare trebe comutativitate (forma friend, fie in prima ori in a doua)
    TODO Incearca sa modifici momentul din care contorizezi numarul de ore petrecute la ferma
    TODO Ajuta utilizatorul sa inteleaga ca trebuie sa ordoneze el treburile din casa in ziua 2
    TODO Acorda jucatorului posibilitatea de a refuza oferta lui George
    TODO Afiseaza inventarul, daca e, sau macar cati bani mai are
    TODO Gandeste-te la intrebarea: Ce sa fac daca nu mai am bani si totusi ma aflu in piata?
    TODO Check if the player have enough money to buy the horse
    TODO Try a better order because initially was 3412, from Diana 1342 and from Stefan 1324
    TODO Try to think a better exprimation instead of "tinere" to apply for men and women
    TODO Replace ce cal frumos aveti with ce cai frumosi aveti and other messages because we can have more horses not only one
    TODO Offer feedback after the user gives a 3 characters string whichs starts with a and ends with r
## Aside
### Virtualization
    DONE https://www.youtube.com/watch?v=oIV2KchSyGQ (Virtual keyword generates a v table for the following function (v from virtual, may be? yeap! see the fourth video)
    DONE https://www.youtube.com/watch?v=4NPOIaUxnnk (We can use -> instead of the dot (.) to acces a function)
    DONE https://www.youtube.com/watch?v=T8f4ajtFU9g (Check the notion Anul I page because it is not space here for romans :))
    DONE https://www.youtube.com/watch?v=FncNE2vdtwQ (A virtual table is an array which contains the addresses of the virtual functions)
### Abstract classes / interfaces
    DONE to fix this error: invalid new-expression of abstract class type 'Cal', watch the next line video
    DONE https://www.youtube.com/watch?v=ZB-np0g2eGk (`public interface INameOfInterface`syntax in c sharp, be careful to title next time :))
    DONE https://www.youtube.com/watch?v=FGToBKDO8Zc (An abstract class can not be innitated... see more on POO>Notite>Abstract Classes & Interfaces, link here: https://lowly-shoemaker-999.notion.site/Anul-I-1133959ea72180fea407f2b4f01f1e63)
    DONE https://www.youtube.com/watch?v=UWAdd13EfM8 (a pure virtual function forces all derived classes functions to have an implementation of that function)
### Diamond inheritance
    DONE https://www.youtube.com/watch?v=X8nYM8wdNRE (Inheritance in C++ by The Cherno, prea tare finalul clipului :) )
    DONE https://www.youtube.com/watch?v=7Zpuz4T4SGw (Animal-Lion-Tiger-Liger "Un ligru este un animal hibrid, rezultat din împerecherea între un leu mascul și o femelă de tigru.", conform https://ro.wikipedia.org/wiki/Ligru)
    DONE https://www.youtube.com/watch?v=-W-TYjL0aFE (protected to use a variable in more classes)
    DONE https://www.youtube.com/watch?v=VaACMwpNz7k (Engine-Car-Robot-Transformer Optimus JR :) )
    DONE https://www.youtube.com/watch?v=DiUXoiOLZY0 (Since Derrived1 and Derrived2 are virtually inheriting Base, the compiler understands to send only one copy to Derrived3)
    DONE https://www.youtube.com/watch?v=NxTyUifYJ74 (last derrived class, let's say Derrived3 has acces to all protected/public variables from Base, Derrived1, Derrived2, which means we will have the following variables in Derrived3: varA, varB, varA, varC, varD)
    DONE https://www.youtube.com/watch?v=KVREEoovDd4 (Entity-Warrior-Goblin-Player)
    DONE https://www.youtube.com/watch?v=V6vna4lGygk (The problem is D is inheriting A twice: once through B and once through C)
    DONE https://www.youtube.com/watch?v=sswTE0u0r7g (Use '::' to remove ambiguity `derivata obj; obj.base2::funct1();`)
    DONE https://www.youtube.com/watch?v=biZEd8pF4OU (one tertiary class derived from two secondary classes derived from one primary class)
*/

/// Partea #3 Due May 26, 2025 12:00 PM
/*
Cerinte:
## Mandatory
    DONE Sa se implementeze din libraria STL cel putin un vector, un set, o lista si un map pentru a gestiona datele aplicatiei
    DONE Scrierea si citirea din fisier
    DONE Aplicatia va contine un meniu (in consola) prin care utilizatorul poate alege diverse optiuni (import/export date, citire obiect nou de la tastatura, diverse functionalitati ale aplicatiei) de tip Singletone
    DONE Folosirea a cel putin o clasa Template
    DONE Folosirea a cel putin doua metode Template
    DONE Proiectul trebuie sa trateze toate exceptiile posibile care pot aparea la executarea codului (codul trebuie sa arunce cel putin sase exceptii dintre care minim trei diferite)
    DONE Exemplificarea conceptelor de upcasting si downcasting (trebuie sa foloseasca si dynamic_cast)
    DONE Exemplificarea conceptului de mostenire pana la nepot (Parinte -> Copil -> Nepot)
    DONE Fiecare clasa sa contine:
        DONE Constructorul fara parametrii
        DONE Constructorul cu toti parametrii
        DONE Copy Constructorul
        DONE Operator egal
        DONE Destructor
        DONE Operator de citire
        DONE Operator de afisare
## Aside
### Notite pentru cerinta: 'Citiți despre HTTP PATCH vs. PUT' (de data trecuta)
    - API stands for Application Programming Interface
    - PATCH is used to replace a part of the resource
    - PUT is used to replace entire resource
    - From: https://apidog.com/blog/http-put-vs-patch/?utm_term=&gad_campaignid=22062217351
*/

/// Gameplay: Fiecare actiune este realizata pe parcursul unei zile. Dupa un anumit numar se zile se intampla nush ce.

long long Joc::counterContinueGame = 0;  /// initializam variabila statica counterContinueGame

template<typename T>
ostream& operator<<(ostream& out, const set<T>& setAnimale)
{
    if (setAnimale.empty())
        return out << "Din nefericire n-am reusit sa achizitionam vreun animal.";
    out << "Avem " << *setAnimale.begin();
    for_each (
        next(setAnimale.begin()), setAnimale.end(), [&out](const T& animale) {
            out << ", " << animale;
        }
    );
    return out << ".\n";
}

/// Clasa template
template <typename T>
class Raport {
private:
    vector<T> monede;
protected:
public:
    Raport(const vector<T>& v) : monede(v) {}
    T calculeazaMedia() const {
        if (monede.empty()) throw runtime_error("Nu-s date in raport");
        T suma = 0;
        for (const T& val : monede) suma += val;
        return suma / monede.size();
    }
    void addMonede(float valoare) {
        monede.push_back(monede);
    }
};

/// Metode template

template <typename T>
T venitMinim(const vector<T>& lst) {
    if (lst.empty()) throw runtime_error("Lista este goala.");
    return *min_element(lst.begin(), lst.end());
}

template <typename T>
T venitMaxim(const vector<T>& lst) {
    if (lst.empty()) throw runtime_error("Lista este goala.");
    return *max_element(lst.begin(), lst.end());
}

int main() {
    /// Resetam fisierul ferma-extras in sensul sa ii stergem vechiul continut
    ofstream fout("ferma-extras.txt");
    fout << ""; /// empty
    fout.close();

    /// Ziua 0 (Aici incepe prima parte a proiectului) /////////////////////////////////////////////////////////////////
    Joc* g = Joc::getInstanta(); /// g de la game, j e luat pentru jucator :)
    Jucator j; /// j de la jucator, bineinteles :)
    bool continuaJoc = true;
    g->showDay();
    cout << "Bunicul Neculai este plecat intr-o vacanta la munte.\n";
    g->continueGame();
    cout << "De aceea, te-a rugat pe tine sa te ocupi de ferma lui pentru cateva zile.\n";
    g->continueGame();
    cout << "Crezi ca vei face fata?\n";
    g->continueGame();

    /// Ziua 1
    char numeleTau[80];
    g->showDay();
    cout << "Fiind prima zi, intalnesti un vecin care s-a mutat de curand la ferma ...\n";
    g->continueGame();
    cout << "[Noul vecin]: Sal'tare tinere! Care-ti este numele dumitale?\n";
    cin.getline(numeleTau, 80); /// getline for "Irimia David" and get for "Irimia", for example
    j.setName(numeleTau);
    g->continueGame();
    cout << "[Noul vecin]: " << numeleTau << ", ce nume frumos!\n";
    g->continueGame();
    cout << "Imi pare bine sa te intalnesc pe aici, " << numeleTau << "!\n";
    g->continueGame();
    cout << "[Noul vecin]: Eu sunt George Petru.\n";
    g->continueGame();
    j.levelUp();
    // j++; /// in loc de j.levelUp();
    ofstream fout1("ferma-extras.txt", ios::app);
    fout1 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout1.close();
    g->menu(*g, j);

    /// Ziua 2
    g->showDay();
    cout << "In cea de-a doua zi observi ca bunicul Neculai a lasat casa 'vraiste'.\n";
    g->menu(*g, j);
    cout << "Cumva il intelegi ca era foarte ocupat cu treburile sale.\n";
    g->menu(*g, j);
    cout << "Tocmai de aceea si-a luat si el o bine-meritata vacanta.\n";
    g->menu(*g, j);
    cout << "Prin urmare, decizi sa dai o mana de ajutor.\n";
    g->menu(*g, j);
    cout << "Vazand pe usa frigiderului o lista de task-uri, observi, insa, ca nu sunt aranjate.\n";
    g->menu(*g, j);
    cout << "Cum ai aranja datoriile?\n1 - Spala WC-ul\n2 - Du gunoiul\n3 - Spala aragazul\n4 - Da cu aspiratorul\n(Nota: Scrie numarul de ordine al task-urilor separate prin caracterul spatiu!)\n";
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
    g->menu(*g, j);
    cout << "Bravo! Ai reusit sa faci " << punctajObtinut << " din cele 4 taskuri.\n";
    g->menu(*g, j);
    cout << "Chiar daca ziua a doua a fost mai obositoare, s-a meritata sa castigi " << punctajObtinut << " nivel(e)!\n"; 
    g->menu(*g, j);
    j.levelUp(punctajObtinut);
    ofstream fout2("ferma-extras.txt", ios::app);
    fout2 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout2.close();
    g->menu(*g, j);

    /// Ziua 3
    g->showDay();
    Casa c;
    Teren t;
    int aux = 0;
    cout << "Nici bine nu te-ai trezit in a treia zi, ca iti bate cineva la usa ...\n";
    g->menu(*g, j);
    cout << "[George]: Vecine, ziua asta nu a inceput deloc bine!\n";
    g->menu(*g, j);
    cout << "[George]: Azi noapte a luat foc hambarul si focul s-a extins pana ...\n";
    g->menu(*g, j);
    cout << "[George]: Pana la casa noastra! Iti vine sa crezi asa ceva, " << j.getName() << "?\n";
    g->menu(*g, j);
    cout << "[George]: Ai fii amabil sa ne gazduiesti pe mine si pe familia mea?\n";
    g->menu(*g, j);
    cout << "[George]: Bineinteles, contra-cost: 50 monede pe zi!\n";
    g->menu(*g, j);
    cout << "[George]: Multumim foarte mult, " << j.getName() << "!\n";
    g->menu(*g, j);
    cout << "Facanduti-se mila de vecin, hotarasti sa ii dai resursele tale de grau, cartofi si morcovi.\n";
    g->menu(*g, j);
    cout << "Ajuns in piata, vanzatoarea te intreaba ce cantitate doresti din fiecare:\n";
    g->menu(*g, j);
    cout << "[Vanzatoarea]: 1 leu kilu' de grau. Cate kile vrei, tinere?\n";
    cin >> aux;
    while(aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 1 leu kilu' de grau. Cate kile vrei, tinere?\n";
        cin >> aux;
    }
    if (j.getMonede() < aux) throw logic_error("Fonduri insuficiente\n");
    j.moneyDown(aux);
    t.cumparaResurse(0, aux);
    g->menu(*g, j);
    cout << "[Vanzatoarea]: 5 lei kilu' de cartofi. Cat sa-ti dau?\n";
    cin >> aux;
    while(5 * aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 5 lei kilu' de cartofi. Cat sa-ti dau?\n";
        cin >> aux;
    }
    j.moneyDown(5 * aux);
    t.cumparaResurse(1, aux);
    g->menu(*g, j);
    cout << "[Vanzatoarea]: 3 lei kilu' de morcovi. Cate kile?\n";
    cin >> aux;
    while(3 * aux > j.getMonede()) {
        cout << "[Vanzatoarea]: Nu-ti ajung banii! Nu te arunca prea curand, incearca si tu mai putin :)\n";
        cout << "[Vanzatoarea]: 3 lei kilu' de morcovi. Cate kile?\n";
        cin >> aux;
    }
    j.moneyDown(3 * aux);
    t.cumparaResurse(2, aux);
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    c.setChirie();
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    ofstream fout3("ferma-extras.txt", ios::app);
    fout3 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout3.close();
    g->menu(*g, j);
    
    /// Ziua 4
    Animale a;
    set<string> setAnimale{};
    g->showDay();
    Tarc f;
    cout << "In ziua a patra, planuiesti sa ii faci o bucurie bunicului Neculai.\n";
    g->menu(*g, j);
    cout << "Ce poate fi mai bun decat niste animale? ... \n";
    g->menu(*g, j);
    cout << "Mai multe animale :)\n";
    g->menu(*g, j);
    cout << "Numai bine, ca au trecut niste negustori prin zona cu niste oferte irefuzabile ...\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Ziua buna! Mai lasati din pret?\n";
    g->menu(*g, j);
    cout << "[Negustorii]: Buna sa iti fie si inima! Ti se pare ca avem noi cumva marfa ieftina?\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Oh! N-am vrut sa intelegeti gresit! Imi pare rau!\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Ce voiam sa zic este ca sunt interesat de o oferta!\n";
    g->menu(*g, j);
    cout << "[Negustorii]: Aha! Daca vrei oferta ...\n";
    g->menu(*g, j);
    cout << "[Negustorii]: Uite aici una care n-are cum sa nu iti placa!\n";
    g->menu(*g, j);
    cout << "[Negustorii]: Ce alegi?\nApasa 1 pentru doi cai la pret de unu'\nApasa 2 pentru trei porci la pret de doi\nApasa 3 pentru a refuza oferta\n";
    cin >> aux;
    cin.get();
    g->separator();
    if (j.getMonede() < 40 || (j.getMonede() < 70 && aux == 2)) {
        cout << "[Negustorii]: Sorry man! Deoarece nu ai bani, nu ai incotro decat sa refuzi oferta!\n";
        j.levelDown(); /// just for fun, ne imaginam ca ne iau negustorii un nivel pentru ca le-am pierdut timpul :)
    } else if (aux == 1) {
        cout << "[Negustorii]: Buna afacere! Sa te bucuri de cai!\n";
        j.moneyDown(40);
        f.cumparaAnimale(2);
        f.addAnimale("cai", 2);
        a.addAnimal("cai");
        setAnimale.insert("cai");
    } else if (aux == 2) {
        cout << "[Negustorii]: Buna afac1ere! Sa te bucuri de porci!\n";
        j.moneyDown(70);
        f.cumparaAnimale(3);
        setAnimale.insert("porci");
    } else if (aux == 3) {
        cout << "[Negustorii]: Nicio problema! Ne mai auzim cand dai de bani!\n";
    }
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    t.setTaxa(5);
    cout << "Taxa pe teren a crescut la " << t.getTaxa() << " monede!\n";
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    ofstream fout4("ferma-extras.txt", ios::app);
    fout4 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout4.close();
    g->menu(*g, j);
    
    /// Ziua 5 (aici incepe partea a doua a proiectului) ///////////////////////////////////////////////////////////////
    char cuv[3];
    g->showDay();
    /// In aux am retinut 1 pentru cai, 2 pentru porci si 3 pentru a refuza oferta sau daca nu am avut bani de cai/porci
    cout << "In cea de-a cincea zi ai chef de-o inspectie a hambarului!\n";
    g->menu(*g, j);
    cout << "Nici bine nu deschizi usa, ca ...\n";
    g->menu(*g, j);
    if (aux == 1) {
        Animal* a = new Frizon();
        Frizon* f = dynamic_cast<Frizon*>(a);  /// downcast cu verificare
        if (f) {
            f->faceZgomot();
        }
        delete a;
    } else if (aux == 2) {
        Porc* p = new Porc();
        Animal* a = p;  /// upcast implicit: Porc* → Animal*
        a->faceZgomot();
        delete p;
    } else {
        Animal animal;
        animal.faceZgomot();
    }
    g->menu(*g, j);
    cout << "Mai spre seara, venira un ingrijitor de cai, anume Caleb Iosua.\n";
    g->menu(*g, j);
    if (aux == 1) {
        cout << "[Caleb Iosua]: Buna seara! Ce cal frumos aveti! Ce rasa este?\n";
        g->menu(*g, j);
        cout << "[" << j.getName() << "]: Buna! Sincer sa va zic, nu am nici cea mai mica idee.\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Nicio problema! Va pot ajuta in schimbul unui targ!\n";
        g->menu(*g, j);
        cout << "[" << j.getName() << "]: Da, sigur! Despre ce este vorba?\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Am un mic rebus pe care nu reusesc sa il termin de cateva zile bune.\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Imi mai lipseste un singur cuvant care incepe cu a si se termina cu r.\n";
        g->menu(*g, j);
        cout << "Introduceti un cuvant de trei litere:\n";
        cin >> cuv;
        g->menu(*g, j);
        if (strcmp(cuv, "aer")) {
            Cal* rasa = new Arab();
            rasa -> afiseazaDescriere();
        } else {
            Cal* rasa = new Mustang();
            rasa -> afiseazaDescriere();
        }
    } else {
        cout << "[Caleb Iosua]: Buna seara! Vad ca va lipseste un cal in aceasta frumoasa ferma!\n";
        g->menu(*g, j);
        cout << "[" << j.getName() << "]: Da, aveti dreptate!\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Va pot ajuta in schimbul unui favor...\n";
        g->menu(*g, j);
        cout << "[" << j.getName() << "]: Da, sigur! Despre ce este vorba?\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Am un mic rebus pe care nu reusesc sa il termin de cateva zile bune.\n";
        g->menu(*g, j);
        cout << "[Caleb Iosua]: Imi mai lipseste un singur cuvant care incepe cu a si se termina cu r.\n";
        g->menu(*g, j);
        cout << "Introduceti un cuvant de trei litere care incepe cu a si se termina cu r:\n";
        cin >> cuv;
        g->menu(*g, j);
        if (strcmp(cuv, "aer")) {
            Cal* rasa = new Arab();
            rasa -> afiseazaDescriere();
        } else {
            Cal* rasa = new Mustang();
            rasa -> afiseazaDescriere();
        }
    }
    setAnimale.insert("cai");
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    ofstream fout5("ferma-extras.txt", ios::app);
    fout5 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout5.close();
    g->menu(*g, j);
    
    /// Ziua 6
    g->showDay();
    cout << "In ziua a sasea, sunteti vizitati de un grup de liceeni insotiti de profesorul Luca.\n";
    g->menu(*g, j);
    cout << "[Luca]: Salutare! Deranjam?\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Deloc! Cu ce ocazie, totusi?\n";
    g->menu(*g, j);
    cout << "[Luca]: In saptamana verde niste prieteni ai lui Neculai ne-au propus o vizita pe aici!\n";
    g->menu(*g, j);
    cout << "Fiind luat prin surprindere, decizi sa ii lasi pe mana lui George Petru!\n";
    g->menu(*g, j);
    cout << "Nu de alta dar trebuie sa te ocupi si de masa lor.\n";
    g->menu(*g, j);
    Placinta p;
    p.afiseaza();
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    ofstream fout6("ferma-extras.txt", ios::app);
    fout6 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout6.close();
    g->menu(*g, j);
    
    /// Ziua 7
    g->showDay();
    cout << "In cea de-a saptea zi, te bucuri de realizarile facute pana acum!\n";
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout7("ferma-extras.txt", ios::app);
    if (!fout7.is_open()) throw runtime_error("Nu s-a putut deschide fisierul pentru scriere!\n");
    fout7 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout7.close();
    g->menu(*g, j);
    
    /// Ziua 8 (aici incepe partea a treia a proiectului) //////////////////////////////////////////////////////////////
    g->showDay();
    cout << "In a opta zi, vine inspectia.\n";
    g->menu(*g, j);
    cout << "(Efect dramatic) Pam! Pam! Pam!\n";
    g->menu(*g, j);
    cout << "[Inspectia] Prea bine! Hai da sa incepem cu terenul!\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Da, sigur! Am " << t.getGrau() << "kg de grau.\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Urmate de " << t.getCartofi() << "kg de cartofi.\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Si " << t.getMorcovi() << "kg de morcovi.\n";
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "[Inspectia] No, si cu animalele cum o duceti?\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: " << setAnimale << '\n';
    g->menu(*g, j);
    j.levelUp();
    g->menu(*g, j);
    cout << "[Inspectia]: Nu aveti probleme, pe moment! Zi minunata!\n";
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout8("ferma-extras.txt", ios::app);
    fout8 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout8.close();
    g->menu(*g, j);
    
    /// Ziua 9
    list<string> listaTarc = {"cai", "porci"};
    g->showDay();
    cout << "Vazand ca in ziua 8 nu prea ai destule animale, in ziua 9 iei atitudine.\n";
    g->menu(*g, j);
    cout << "Prin urmare mergi la targ pentru a extinde ferma cu mai multe tarcuri.\n";
    g->menu(*g, j);
    do {
        cout << "Apasa 1 pentru a iesi din targ\n";
        cout << "Apasa 2 pentru a cumpara 2 gaini (10 monede)\n";
        cout << "Apasa 3 pentru a cumpara 3 vaci (30 monede)\n";
        cout << "Apasa 4 pentru a cumpara 4 oi (32 monede)\n";
        cin >> aux;
        g->menu(*g, j);
        if (aux == 1) {
            cout << "Vroom! Vroom! Tocmai ai ales sa parasesti targul si sa te intorci la ferma.\n";
            g->menu(*g, j);
        } else if (aux == 2) {
            if (j.getMonede() < 10) {
                cout << "[Vanzatoarea]: Imi cer mii de scuze! Nu iti pot vinde gainile numai pentru " << j.getMonede() << " monede!\n";
                g->menu(*g, j);
                j.levelDown(); /// just for fun, ne imaginam ca ne ia negustoarea un nivel pentru ca i-am pierdut timpul :)
                g->menu(*g, j);
            } else {
                int ordineTarc = -1;
                f.cumparaAnimale(2);
                f.addAnimale("gaini", 2);
                a.addAnimal("gaini");
                cout << "[Vanzatoarea]: Sa te bucuri de cele doua gaini!\n";
                g->menu(*g, j);
                j.levelUp();
                g->menu(*g, j);
                cout << "Ai vrea gainile la inceputul sau la sfarsitul tarcurilor?\n";
                g->menu(*g, j);
                cout << "Apasa 8 pentru a pune gainile la inceputul tarcurilor\n";
                cout << "Apasa 9 pentru a pune gainile la sfarsitul tarcurilor\n";
                cin >> ordineTarc;
                g->menu(*g, j);
                if (ordineTarc == 8) {
                    listaTarc.push_front("gaini");
                } else if (ordineTarc == 9) {
                    listaTarc.push_back("gaini");
                } else {
                    cout << "Nu pricep ce ai vrut sa faci! Am intuit alegerea de a pune gainile la final.\n";
                    listaTarc.push_back("gaini");
                    g->menu(*g, j);
                }
            }
        } else if (aux == 3) {
            if (j.getMonede() < 30) {
                cout << "[Vanzatoarea]: Imi cer mii de scuze! Nu iti pot vinde vacile numai pentru " << j.getMonede() << " monede!\n";
                g->menu(*g, j);
                j.levelDown(); /// just for fun, ne imaginam ca ne ia negustoarea un nivel pentru ca i-am pierdut timpul :)
                g->menu(*g, j);
            } else {
                int ordineTarc = -1;
                f.cumparaAnimale(3);
                f.addAnimale("vaci", 3);
                a.addAnimal("vaci");
                cout << "[Vanzatoarea]: Sa te bucuri de cele trei vaci!\n";
                g->menu(*g, j);
                j.levelUp();
                g->menu(*g, j);
                cout << "Ai vrea vacile la inceputul sau la sfarsitul tarcurilor?\n";
                g->menu(*g, j);
                cout << "Apasa 8 pentru a pune vacile la inceputul tarcurilor\n";
                cout << "Apasa 9 pentru a pune vacile la sfarsitul tarcurilor\n";
                cin >> ordineTarc; 
                g->menu(*g, j);
                if (ordineTarc == 8) {
                    listaTarc.push_front("vaci");
                } else if (ordineTarc == 9) {
                    listaTarc.push_back("vaci");
                } else {
                    cout << "Nu pricep ce ai vrut sa faci! Am intuit alegerea de a pune vacile la final.\n";
                    listaTarc.push_back("vaci");
                    g->menu(*g, j);
                }
            }
        } else if (aux == 4) {
            if (j.getMonede() < 32) {
                cout << "[Vanzatoarea]: Imi cer mii de scuze! Nu iti pot vinde oile numai pentru " << j.getMonede() << " monede!\n";
                g->menu(*g, j);
                j.levelDown(); /// just for fun, ne imaginam ca ne ia negustoarea un nivel pentru ca i-am pierdut timpul :)
                g->menu(*g, j);
            } else {
                int ordineTarc = -1;
                f.cumparaAnimale(4);
                f.addAnimale("oi", 4);
                a.addAnimal("oi");
                cout << "[Vanzatoarea]: Sa te bucuri de cele patru oi!\n";
                g->menu(*g, j);
                j.levelUp();
                g->menu(*g, j);
                cout << "Ai vrea oile la inceputul sau la sfarsitul tarcurilor?\n";
                g->menu(*g, j);
                cout << "Apasa 8 pentru a pune oile la inceputul tarcurilor\n";
                cout << "Apasa 9 pentru a pune oile la sfarsitul tarcurilor\n";
                cin >> ordineTarc; 
                g->menu(*g, j);
                if (ordineTarc == 8) {
                    listaTarc.push_front("oi");
                } else if (ordineTarc == 9) {
                    listaTarc.push_back("oi");
                } else {
                    cout << "Nu pricep ce ai vrut sa faci! Am intuit alegerea de a pune oile la final.\n";
                    listaTarc.push_back("oi");
                    g->menu(*g, j);
                }
            }
        } else if (!(cin >> aux)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Optiune introdusa gresit! Trebuie sa fie un numar intreg intre 1 si 4.\n");
        } 
    } while (aux != 1);
    cout << "Ajuns la ferma, primesti 3 porci de la vecinul George Petru.\n";
    f.addAnimale("porci", 3);
    a.addAnimal("porci");
    g->menu(*g, j);
    cout << "[George Petru]: Acum esti cu adevarat un fermier!\n";
    g->menu(*g, j);
    for (string animale : listaTarc) {
        cout << "[George Petru]: Ai " << animale << "\n";
        g->menu(*g, j);
    }
    cout << "[George Petru]: Ce vrei mai mult de atat? Haha! Esti boierul fara b! Ha! Ha!\n";
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout9("ferma-extras.txt", ios::app);
    fout9 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout9.close();
    g->menu(*g, j);
    
    /// Ziua 10
    g->showDay();
    cout << "Iata-ne ajunsi la ziua 10\n";
    g->menu(*g, j);
    cout << "Ai reusit sa stragi " << f.getCapacitateAnimale() << " animale\n";
    g->menu(*g, j);
    cout << "Dintre care: \n";
    g->menu(*g, j);
    f.cateAnimale();
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout10("ferma-extras.txt", ios::app);
    fout10 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout10.close();
    g->menu(*g, j);
    
    /// Ziua 11
    string denumireAnimal;
    vector<float> venituri = {};
    int ziua = -1;
    float monede = -1;
    g->showDay();
    cout << "In ziua 11 dai peste un politician renumit\n";
    g->menu(*g, j);
    cout << "Mai bine spus, el da peste tine cu urmatoarea intrebare:\n";
    g->menu(*g, j);
    cout << "[Gimucu Sorpa]: Bine o mai duceti, " << j.getName() <<"!\n";
    g->menu(*g, j);
    cout << "[Gimucu Sorpa]: N-ai vrea sa ne dai si noua raportul cu veniturile tale?\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Bineinteles, uit' aci extrasul de pe ultimele zece zile:\n";
    g->menu(*g, j);
    ifstream fin("ferma-extras.txt");
    /// Ziua X - Y monede unde Ziua, - si monede le citim in aux si X = ziua, y = numarul de monede
    while (fin >> aux >> ziua >> aux >> monede >> aux) {
        cout << "In ziua " << ziua << " am realizat un venit de " << monede << "monede\n";
        venituri.push_back(monede);
    }
    if (!fin.is_open()) throw runtime_error("Nu s-a putut deschide fisierul pentru citire!\n");
    fin.close();
    g->menu(*g, j);
    cout << "[Gimucu Sorpa]: Hai sa iti arat cat de bun sunt la matematica!\n";
    g->menu(*g, j);
    Raport<float> raportVenituri(venituri);
    cout << "Media veniturilor tale este de " << raportVenituri.calculeazaMedia() << " monede pe zi\n";
    g->menu(*g, j);
    cout << "Mai stiu si alte chestii, precum venitul maxim si venitul minim\n";
    g->menu(*g, j);
    cout << "Venitul tau maxim este " << venitMaxim(venituri) << " monede intr-o zi\n";
    g->menu(*g, j);
    cout << "Venitul tau minim este " << venitMinim(venituri) << " monede intr-o zi\n";
    g->menu(*g, j);
    cout << "[" << j.getName() << "]: Hai ca o ai cu matematica! Dar cu biologia cum o duci?\n";
    g->menu(*g, j);
    cout << "[Gimucu Sorpa]: Incearca-ma! Scrie mai jos unul dintre animalele tale sa vezi ce stiu despre el!\n";
    g->menu(*g, j);
    cin >> denumireAnimal;
    g->menu(*g, j);
    if (denumireAnimal != "oi" && denumireAnimal != "vaci" && denumireAnimal != "gaini" && denumireAnimal != "porci" && denumireAnimal != "cai") {
        throw domain_error("Nici macar nu ai acest animal!\n");
    } else {
        cout << "[Gimucu Sorpa]: Ce stiu despre " << denumireAnimal << " e ca-s animale ...\n";
        g->menu(*g, j);
        cout << "[Gimucu Sorpa]: Ai dreptate! Nu prea mi-au placut orele de biologie! De aia sunt politician si nu doctor\n";
    }
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout11("ferma-extras.txt", ios::app);
    fout11 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout11.close();
    g->menu(*g, j);

    /// Day 12
    g->showDay();
    cout << "In ziua 12 iara va odihniti!\n";
    g->menu(*g, j);
    cout << "Detalii finale\n";
    g->menu(*g, j);
    cout << "Au fost platite taxele pentru casa si teren in valoare de " << c.getTaxa() + t.getTaxa() << " monede.\n";
    j.moneyDown(c.getTaxa());
    j.moneyDown(t.getTaxa());
    g->menu(*g, j);
    j.moneyUp(c.getChirie());
    cout << "Ati primit " << c.getChirie() << " monede din partea lui George!\n";
    g->menu(*g, j);
    j.moneyUp(t.getVenit());
    cout << "In urma recoltei ai realizat un venit de " << t.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.moneyUp(f.getVenit());
    cout << "Animalele ti-au adus un venit de " << f.getVenit() << " monede!\n";
    g->menu(*g, j);
    j.levelUp();
    ofstream fout12("ferma-extras.txt", ios::app);
    fout12 << "Ziua " << g->getZi() - 1 << " - " << j.getMonede() << " monede\n";
    fout12.close();
    g->menu(*g, j);
    j.showInfo();
    g->menu(*g, j);

    return 0;
}
