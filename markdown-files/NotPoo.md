<b style="color:crimson">ATENTIE</b> La pointeri nu poti accesa cu `.` trebuie cu `->`

<b style="color:crimson">ATENTIE</b> Fiecare constructor are o listă de inițializare. Dacă tu nu o scrii explicit, compilatorul o generează implicit pentru tine.

<b style="color:crimson">ATENTIE</b> Ordinea de inițializare în lista de initializare la constructor este determinată de ordinea declarării membrilor în clasă, nu de ordinea în care apar în lista de inițializare.

<b style="color:crimson">ATENTIE</b> Nu se poate atribui la o clasa care are const cu operator=-ul default:
```c++
class C {
	const int i;
public:
	C(int& j) : i(j) {cout << "C ";}
};

int main() {
	int i = 6, j = 2023;
	C ob1(i), ob2(j);
	C ob3(ob1); // Functioneaza
	ob3 = ob2; // EROARE
	return 0;
}
```


<b style="color:crimson">ATENTIE</b> Daca o clasa are `const` non-static sau `&` se sterge operatorul= sau cand are un membru/clasa de baza care are operatorul= inaccesibil sau sters:
```c++
class A {
	int &x; // Sau const int x;
	int y;
public:
	A(int a, int b = 0) : x(b) {y = a;}
	operator int() {return x + y;}
	void foo() {y += x;}
};

int main() {
	A a(20, 25);
	a.foo();
	A b(3101);
	b = a;     // NU MERGE
	cout << b; // Functioneaza
}
```

<b style="color:crimson">ATENTIE:</b> Nu se fac conversii (???)
```c++
class B {
protected:
    int x;
public:
    B(int i = 0) : x(i) {}
    operator int() {return x;}
};
class D: public B {
public:
    D(int i = 0) : B(i) {}
    operator B() {return B();}
    operator float() {return x;}
};

int main() {
    D ob(12);
    try { throw ob; }
    catch(float a) { cout << "float"; }
    catch(B b) { cout << "B"; }  //BINGO
    catch(D d) { cout << "D"; }
    catch(...) { cout << "altcevaw"; }
}
```

<b style="color:crimson">ATENTIE:</b> Destructorul virtual trebuie DOAR LA POINTERI:
```c++
class A {
    public: ~A() {cout << "A";}
};
class B : public A {
    public: ~B() {cout << "B";}
};
int main() {
    A* p = new B();
    delete p;        //Afiseaza doar 'A' pentru ca nu este destructorul virtual
}
```

<b style="color:crimson">ATENTIE</b> Cand vezi static, cauta sa fie declarat in afara.

<b style="color:crimson">ATENTIE</b> Specializarea partiala a unui template este permisa pentru clase DAR NU SI PENTRU FUNCTII:  

```c++
template <class T, class U> class MyClass {}; // Template primar
template <class T> class MyClass<T, int> {};  // Specializare partiala - OK

template <class T, class U> void myFunc(T, U) {} // Template primar
// template <class T> void myFunc<T, int>(T, int) {} // EROARE! Nu poti specializa partial functii
```

<b style="color:crimson">ATENTIE</b> LA `vector<A>`: `push_back(i)`, va crea un A(i) si apoi il copiaza in structura, dupa care destructorul se apeleaza pentru A(i)-ul creat. Daca mai facem push odata, se va apela C, CC, CC, D, D in aceasta ordine, pentru ca trebuie sa realoce spatiu. La realocare SE COPIAZA FIECARE ELEMENT si SE DISTRUG CELE VECHI!!

<b style="color:crimson">ATENTIE</b>, la list nu se realoca spatiul ca mai sus, la fel si deque, map, set. Unordered_map si unordered_set face realocare la rehashing.

<b style="color:orange">Quiz P7</b> | <b style="color:crimson">ATENTIE</b> Nu putem face upcasting daca avem mostenire private SAU protected, putem doar daca e mostenire publica.

<b style="color:orange">Quiz P8</b> | <b style="color:crimson">ATENTIE</b> O clasă derivată (D) are acces la membrii protected ai porțiunii sale de bază (B). Ea NU are acces la membrii protected ai altor obiecte independente de tip B, chiar dacă sunt în aceeași funcție: `B f(B ob) { return x + ob.x - 1; }`, DAR daca era `B f(D ob) { return x + ob.x - 1; }` ar fi mers.

<b style="color:orange">Quiz P11</b> | <b style="color:crimson">ATENTIE</b> Daca nu se poate deduce tipul T atunci nu se creaza nici-o functie dupa acel template, si nu are ce sa apeleze.

<b style="color:orange">Quiz P17</b> | <b style="color:crimson">ATENTIE</b> Putem sa facem downcast doar de la o clasa de baza doar daca contine doar membrii statici.

<b style="color:orange">Quiz P21</b> | <b style="color:crimson">ATENTIE</b> Cand avem mostenire virtuala multipla, clasa derivata este responsabila sa initializeze 

<b style="color:orange">Quiz P92</b> | <b style="color:crimson">ATENTIE</b> La initializarea bazei in constructorul de copiere cand nu are constructor implicit!

<b style="color:orange">Quiz P100</b> | <b style="color:crimson">ATENTIE</b> Nu se poate initializa un membru static y din lista de initializare la constructor!! De exemplu nu putem face asta: `A(int i,int j):x(i),y(j){}` unde `y` este un membru static al lui `A` dar putem face asta `A(int i,int j):x(i) {y = j;}`

<b style="color:orange">Quiz P112</b> | <b style="color:crimson">ATENTIE</b>    La suprascrierea de operatori binari, nu este `int operator*(cls a, cls b) { return (a.x * b.x); }` ci este `    int operator*(cls b) { return (x * b.x); }`

<b style="color:crimson">ATENTIE</b> Un obiect temporar nu poate fi trimis ca parametru decat prin const reference:
```c++
problema mister1() { return problema(6); }
void mister2(problema& o)
{
    o.afiseaza();
    o.schimba();
    o.afiseaza();
}
int main()
{
    mister2(mister1()); //EROARE
    return 0;
}
```
```c++
problema mister1() { return problema(6); }
void mister2(const problema& o)
{
    o.afiseaza();
    o.schimba(); // EROARE
    o.afiseaza();
}
int main()
{
    mister2(mister1()); //Ok
    return 0;
}
```

<b style="color:orange">Quiz P49</b> | <b style="color:crimson">ATENTIE</b> operator cu friend si operator ca membru functioneaza diferit! Cel cu friend accepta conversii atat pentru operandul din stanga cat si cel din dreapta, cel fara friend ACCEPTA DOAR DIN DREAPTA conversia.
| Caracteristică            | Funcție Membru (`NonFriend`)                                   | Funcție Non-Membru (`Friend`)                                |
| ------------------------- | -------------------------------------------------------------- | ------------------------------------------------------------ |
| **Număr de Parametri**    | **Unul**. Operandul din stânga este `*this` (implicit).         | **Doi**. Ambii operanzi sunt parametri expliciți.            |
| **Sintaxă Apel Echivalent** | `a.operator*(b)`                                               | `operator*(a, b)`                                            |
| **Operandul din Stânga**  | **Trebuie** să fie un obiect al clasei (sau derivat).          | Poate fi orice tip care se poate converti la primul parametru. |
| **Simetrie**              | **Asimetrică**. Nu funcționează dacă operandul din stânga nu e de tipul clasei. | **Simetrică**. Permite conversii pentru ambii operanzi.      |
---

<b style="color:crimson">ATENTIE</b> Operatorul de precrementare (++x) este `operator++()` si cel de postcrementare (x++) este `operator++(int)` (FARA NUME LA INT).

<br><br><br>

# Definitii:
<b>Upcasting:</b>
	De la derivata => baza, mereu e safe
<b>Downcasting:</b>
	De la baza => derivata, nu mereu e safe; cu dynamic_cast

<b>Late binding:</b>
	Vtable, cu virtual chesiti, stabilit la runtime

<b>Încapsulare:</b>
Este procesul de a lega datele (atributele) și metodele care operează asupra lor într-o singură unitate numită clasă, ascunzând detaliile interne de implementare. Accesul la starea obiectului se face controlat, prin interfețe publice.

<b>Moștenire:</b>
Este un mecanism prin care o clasă nouă (subclasa) preia atributele și metodele unei clase existente (superclasa), creând o relație de tip "este un/o" (is-a). Permite reutilizarea codului și crearea de ierarhii de clase.

<b>Compunere:</b>
Este un mecanism prin care un obiect este construit prin includerea altor obiecte, creând o relație de tip "are un/o" (has-a). Permite construirea de obiecte complexe din părți mai simple și independente.

<b>Moștenire vs. Compunere:</b>
Moștenirea ("is-a") creează o cuplare strânsă (tight coupling) între clase, stabilită la compilare. Compunerea ("has-a") oferă o cuplare slabă (loose coupling) și mai multă flexibilitate, permițând schimbarea componentelor la runtime. Principiul de bază este: „Favorizează compunerea în detrimentul moștenirii”.

<b>Mutable:</b>
    Cuvântul cheie mutable permite modificarea unui membru de date al unei clase chiar și atunci când acesta face parte dintr-un obiect constant  (const).

<b>Clasa polimorfica:</b>
O clasă polimorfică este orice clasă care declară sau moștenește cel puțin o funcție virtuală.

<b>Late Binding (Legare târzie):</b>
Este procesul de a determina metoda exactă care trebuie apelată la momentul execuției (runtime), nu la compilare. Este fundamentul polimorfismului, permițând unei variabile de tip superclasă să invoce metoda corectă a obiectului subclasă pe care îl referă.

<b>Design Pattern (Șablon de proiectare):</b>
Este o soluție generală, reutilizabilă, la o problemă des întâlnită în proiectarea software. Nu este un cod specific, ci un model sau o "rețetă" care descrie cum să structurezi clasele și obiectele pentru a rezolva problema respectivă.

<b>Tipuri de Design Patterns:</b><br>
<b>Creaționale:</b> Se ocupă de mecanismele de creare a obiectelor (ex: Singleton, Factory).<br>
<b>Structurale:</b> Descriu cum pot fi compuse clasele și obiectele pentru a forma structuri mai mari (ex: Adapter, Decorator).<br>
<b>Comportamentale:</b> Se concentrează pe comunicarea și distribuirea responsabilităților între obiecte (ex: Observer, Strategy).

<b>Principiile SOLID:</b>
Sunt cinci principii de proiectare care urmăresc să facă sistemele software mai ușor de înțeles, flexibile și mentenabile.

<b>S - Single Responsibility Principle:</b> O clasă trebuie să aibă o singură responsabilitate (un singur motiv de a fi modificată).<br>
<b>O - Open/Closed Principle:</b> Entitățile software trebuie să fie deschise pentru extindere, dar închise pentru modificare.<br>
<b>L - Liskov Substitution Principle:</b> Subtipurile trebuie să poată înlocui tipurile de bază fără a afecta corectitudinea programului.<br>
<b>I - Interface Segregation Principle:</b> Niciun client nu trebuie forțat să depindă de interfețe pe care nu le folosește.<br>
<b>D - Dependency Inversion Principle:</b> Modulele de nivel înalt nu trebuie să depindă de cele de nivel scăzut. Ambele trebuie să depindă de abstracțiuni.<br>