/// Ferma bunicului - Proiect, Programare Orientata pe Obiecte, Irimia David

#include <iostream>
#include <cstring>
#include "ferma-jucator.h"
#include "ferma-joc.h"
#include "ferma-casa.h"
#include "ferma-teren.h"
#include "ferma-tarc.h"
#include "ferma-animal.h" /// contains also the following classes: Cal, Arab, Mustang, Porc
using namespace std;

/// NICE: move this comments into a markdown file and organize the code a little bit :)
/// Partea #1 Due March 24, 2025 11:59 PM
/*
Cerinte:
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
    TODO Foloseste conceptul de moștenire (minim 3 clase în ierarhie)
    TODO Foloseste conceptul de polimorfism
    DONE Minim o clasă abstractă / interfață
    TODO Moștenirea în diamant (moștenirea multiplă) corect rezolvată
    TODO Citiți despre HTTP PATCH vs. PUT
## Nice
    TODO Adauga inventar
    TODO La supraincarcare trebe comutativitate
    TODO Incearca sa modifici momentul din care contorizezi numarul de ore petrecute la ferma
    TODO Ajuta utilizatorul sa inteleaga ca trebuie sa ordoneze el treburile din casa in ziua 2
    TODO Acorda jucatorului posibilitatea de a refuza oferta lui George
    TODO Afiseaza inventarul, daca e, sau macar cati bani mai are
    TODO Gandeste-te la intrebarea: Ce sa fac daca nu mai am bani si totusi ma aflu in piata?
    TODO check if the player have enough money to buy the horse;
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

/// Gameplay: Fiecare actiune este realizata pe parcursul unei zile. Dupa un anumit numar se zile se intampla nush ce.

long long Joc::counterContinueGame = 0;  /// initializam variabila statica counterContinueGame

int main() {
    /// Ziua 0 (Aici incepe prima parte a proiectului)
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
    cout << "[Negustorii]: Ce alegi?\nApasa 1 pentru doi cai la pret de unu'\nApasa 2 pentru trei porci la pret de doi\nApasa 3 pentru a refuza oferta\n";
    cin >> aux;
    cin.get();
    g.separator();
    if (j.getMonede() < 40 || (j.getMonede() < 70 && aux == 2)) {
        cout << "[Negustorii]: Sorry man! Deoarece nu ai bani, nu ai incotro decat sa refuzi oferta!\n";
        j.levelDown(); /// just for fun, ne imaginam ca ne iau negustorii un nivel pentru ca le-am pierdut timpul :)
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

    /// Ziua 5 (aici incepe partea a doua a proiectului)
    char cuv[3];
    g.showDay();
    /// In aux am retinut 1 pentru cai, 2 pentru porci si 3 pentru a refuza oferta sau daca nu am avut bani de cai/porci
    cout << "In cea de-a cincea zi ai chef de-o inspectie a hambarului!\n";
    g.menu(g, j);
    cout << "Nici bine nu deschizi usa, ca ...\n";
    g.menu(g, j);
    if (aux == 1) {
        Animal* animal = new Frizon();
        animal -> faceZgomot();
    } else if (aux == 2) {
        Animal* animal = new Porc();
        animal -> faceZgomot();
    } else {
        Animal animal;
        animal.faceZgomot();
    }
    g.menu(g, j);
    cout << "Mai spre seara, venira un ingrijitor de cai, anume Caleb Iosua.\n";
    g.menu(g, j);
    if (aux == 1) {
        cout << "[Caleb Iosua]: Buna seara! Ce cal frumos aveti! Ce rasa este?\n";
        g.menu(g, j);
        cout << "[" << j.getName() << "]: Buna! Sincer sa va zic, nu am nici cea mai mica idee.\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Nicio problema! Va pot ajuta in schimbul unui targ!\n";
        g.menu(g, j);
        cout << "[" << j.getName() << "]: Da, sigur! Despre ce este vorba?\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Am un mic rebus pe care nu reusesc sa il termin de cateva zile bune.\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Imi mai lipseste un singur cuvant care incepe cu a si se termina cu r.\n";
        g.menu(g, j);
        cout << "Introduceti un cuvant de trei litere:\n";
        cin >> cuv;
        g.menu(g, j);
        if (strcmp(cuv, "aer")) {
            Cal* rasa = new Arab();
            rasa -> afiseazaDescriere();
        } else {
            Cal* rasa = new Mustang();
            rasa -> afiseazaDescriere();
        }
    } else {
        cout << "[Caleb Iosua]: Buna seara! Vad ca va lipseste un cal in aceasta frumoasa ferma!\n";
        g.menu(g, j);
        cout << "[" << j.getName() << "]:Da, aveti dreptate!\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Va pot ajuta in schimbul unui favor...\n";
        g.menu(g, j);
        cout << "[" << j.getName() << "]: Da, sigur! Despre ce este vorba?\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Am un mic rebus pe care nu reusesc sa il termin de cateva zile bune.\n";
        g.menu(g, j);
        cout << "[Caleb Iosua]: Imi mai lipseste un singur cuvant care incepe cu a si se termina cu r.\n";
        g.menu(g, j);
        cout << "Introduceti un cuvant de trei litere care incepe cu a si se termina cu r:\n";
        cin >> cuv;
        g.menu(g, j);
        if (strcmp(cuv, "aer")) {
            Cal* rasa = new Arab();
            rasa -> afiseazaDescriere();
        } else {
            Cal* rasa = new Mustang();
            rasa -> afiseazaDescriere();
        }
    }
    g.menu(g, j);
    j.levelUp();
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

    /// Let's call this section final touches even it is not the best name, currently I like it :)
    cout << "Detalii finale\n";
    j.showInfo();
    g.menu(g, j);

    return 0;
}
