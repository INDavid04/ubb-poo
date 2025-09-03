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

## Solutions
3. merge si ne da 6 21 3
4. linia 20, nu putem parsa obiect de tip problema in functie mister2 ce primeste adresa de memorie, stergem& la void mister2(persoana& o)
5. Corect, da 7 7 7 pt ca la downcast la d, in continuare cand apeleaza getterul se uita la getterul din B si dupa a cel mai derivat(adica din MM chiar daca e pointer la D)
6. Corect, va da 6, la b+=a apeleaza operatorul int() si transforma a-ul in int
7. Eroare la linia 19, cand apeleaza new D nu are acces la baza B(fiind protected), facem mostenirea publica class D: public B{ iar ca rezultat ne da 1(pt ca typeid.name nu e D*, e cv gen P1D si deci nu afiseaza 2-ul). Daca era obiect ( D a nu crapa, dar crapa la cout<<a.get_i() din acelasi motiv) de revizuit
8. Crapa la linia 17, nu are acces la ob.x( x fiind camp protected, dar considerat ca privat pt alte obiecte, il facem public si ne da -5
9. Merge, afiseaza 1131
10. Ruleaza, afiseaza valoarea de la( adresa din memorie al lui a + 23)
11. Crapa la linia 20, nu recunoaste operatorul <<, ca sa rezolvam ar trb scris coutul invers ( (a1+a2)<<cout;)
12. crapa la linia 17, cand creeaza vector implicit apeleaza constructorul fara parametrii care nu exista, ca sa rezolvam punem parametrul din constructorul cu parametru o valoare default si dupa afiseaza 0123456789
13. Compileaza, se pare ca daca difera parametrul, ca e float si nu int atunci nu avem ambiguitate
14. Crapa la linia 29, nu avem constructor fara parametrii, setam la constructorul lui B o valoare default si va afisa 112112 
15. compileaza, ne da 5-19 pt ca se apeleaza constructori impliciti
16. Merge, afiseaza -12
17. Merge, afiseaza -11 
18. Merge, se va afisa adresa lui a + 5
19. Merge, se va afisa -17
20. Crapa, la linia 31 unde avem declarat { MM b } si comentam acele linii, si va afisa 7 7 7
21. Merge, afiseaza -15, se la e2=e1 se apeleaza copy constructorul.
22. Crapa, i-ul e privat, se pune protected
23. Crapa la linia 43, trb dynamic_cast la p ca sa poti afisa
24. Crapa la linia 28, se apeleaza functia f care este ambigua, ca sa rezolvam redenumim functia float in f1 sau schimbam antetul functiei
25. Crapa deoarece nu avem referire la zona de memorie statica, ca sa rezolvam stergem keywordul static de la linia 4 si va afisa 212
26. Merge si afiseaza -12 (este identic cu grila 16)
27. Crapa la linia 25 pt ca nu exista obiectul o in memorie, el a fost distrus la finalul else-ului. O solutie ar fi sa nu-l mai afisam, sau sa-l declaram in main, la inceput
28. linia 20, nu putem parsa obiect de tip problema in functie mister2 ce primeste adresa de memorie, stergem& la void mister2(persoana& o) (este identic cu exercitiul 4)
29. Merge, afiseaza 7 7 7(identic cu ex 5)
30. Merge, da +6
31. Crapa, faci pointer la o derivata ce mosteneste o clasa protected, ca sa reparam facem mostenirea publica.
32. Acelasi cu ex8
33. Acelasi cu ex9
34. Acelasi cu ex10
35. Acelasi cu ex11
36. Acelasi cu ex12
37. Merge, afiseaza 7 (poti avea getter nestatic pe variabila statica)
38. Crapa la linia 7 pt ca incearca sa adune pointeri, ca solutie inlocuim la linia 17 cu cout<<f(*a,*b);
39. Crapa, ambiguitate la linia 38 pt ca sunt mai multe functii cu acelasi antet, inlocuim antetul unei functii(ii punem alt nume) si apelam functia cu acel nume
40. Merge si afiseaza 5
41. Merge
42. Crapa la linia 20, nu exista o in memorie
43. Merge, afiseaza c1 c2 c1 c2 c1 c3 d3 d1 d2 d1 d2 d1
44. Merge, afiseaza 1
45. Crapa la linia 7 ca ai const acolo si daca functia returneaza o adresa se poate modifica, ca sa rezolvam scoatem adresa si afiseaza -1
46. Crapa la linia 17, nu poti face egalitate intre un D si un B, ca sa rezolvi faci downcast la tipul D
47. Ruleaza, insa nu afiseaza nimic
48. Crapa. Nu are acces la getter fiind mostenire protected, ca sa rezolvi faci mostenirea publica
49. Merge si afiseaza 1500
50. Merge si afiseaza B D D2 MM 7 7 7
51. Merge si afiseaza 1
52. Crapa la linia 24, incearca sa apeleze D::get_x fara sa avem obiect, ca solutie facem getterul static
53. Crapa la linia 8 (aceeasi problema ca la ex12)
56. Merge
57. Merge, afiseaza 0 0
58. E ca 57
59. Crapa la linia 19, nu are acces la campul x, trebuie apelat cu return B::get_x();
60. Merge si da 200
61. Merge si afiseaza 20 22.
62. Identic cu 61
63. Eroare la linia 13, nu poti apela f(d) pt ca f e metoda, ca sa rezolvi o scrii in afara clasei si scoti adresa.
64. Merge, va afisa 0, probabil se apeleaza copy constructor implicit
65. Merge, va afisa 98765432210
67. Crapa la linia 22, nu e acces la u.x deoarece obiectul u are campul private si se face copie, si 
68. Crapa la linia 9, functia nu face conversie implicita la apelul functiei. Ca sa reparam facem sa primeasca un obiect de tip 1 si reparam comentand linia 9 si va afisa 30 30
70. Merge si afiseaza 28
71. Merge si afiseaza 14
72. Merge si afiseaza 37
73. Crapa pt ca avem si constructor fara parametrii si constructor cu valoare default ce duce la ambiguitate. Ca sa rezolvam stergem constructorul fara parametrii si ne va afisa 41
74. Compileaza, dar nu afiseaza nimic pentru ca obiectul returnat din functia f este referinta si altfel este distrus, deci nu se salveaza.
75. Merge si afiseaza 20 30.
76. obiectul de tip cls e constant iar in functia f nu e dat ca si const, deci ca sa reparam scoatem constul.
77. Merge si afiseaza 1
79. Crapa la linia 31 pt ca apeleaza a[i] dar a e constant, scoatem constul de la linia 31
80. Crapa la linia 15, nu are acces la campul x fiind privat. trb facut protected 
81. Merge si va afisa 41
82. Merge si va afisa o valoare din memorie(v[0] nu a fost initializat cu 0), dupa 3 de 0, -15, si dupa zerouri
83. Crapa la linia 12, nu poti da ++ la o zona de memorie pusa constanta, ca sa rezolvi modifici linia 12 in b=a.f(); si va afisa 14
84. Crapa la liniile 19 si 20 intrucat x-ul este privat(NU CONTEAZA daca e static sau nu, el tot privat), ca sa modificam vom pune protected si va afisa 2 2 1
85. Merge si va afisa 11
86. Crapa la linia 8 ca e apelata functia fara parametru, ca sa rezolvam vom returna x/2 si programul va afisa 0
87. Merge insa va afisa niste chestii aiurea deoarece la final dezaloca memoria pt vector de 2 ori deoarece nu exista operatorul = supraincarcat si se copiaza bit cu bit
88. Merge si nu afiseaza nimic deoarece in if-ul acela cu typeid nu va intra
89. Crapa la linia 17 pt ca nu are constructor fara parametrii, ii dam la cel cu parametru o valoare default pt i.
90. Merge si afiseaza -3 (cum la apel functiei f(a,b) nu se incadreaza nici pt template, nici pt specializare, face conversie din float in int si intra in specializare)
91. Crapa la linia 9 (referinta de la o zona de memorie la un const int nepermisa), solutie1: scoatem constul, solutie2: scoatem adresa si va afisa 5
92. Crapa la linia 26 ca nu am constructor pt A fara parametrii, si ca sa rezolvam punem valoarea default 5 la cel cu parametri si va afisa 5 de 1
93. Merge si va afisa "tipuri diferite" pt ca p e pointer de tip A chiar daca ii dai new B
94. Merge si va afisa -16
96. Crapa la linia 14 pt ca a nu are acces la campul lui, punem in clasa A ca e friend class B
97. Crapa la linia 21, nu face conversie implicita de la B la int, ca sa modificam schimbam la operatorul + cu += si va afisa -21 (pt ca tu afisezi b-ul care nu se modifica)
98. Crapa la linia 44, cand apeleaza coutul se face copie a lui B cu copy constructor si nu-i convine tipul, scoatem constul.
99. Merge si da 4
100.Crapa la linia 6, incerc sa-i dau valoare la o variabila statica in constructor, scot de acolo declararea
101.Merge si afiseaza 11315
102.Merge si afiseaza 3
103.Crapa la linia 14, nu poti avea pointer de derivata catre obiect de baza, ci invers: B* p = new D
104.Merge si va afisa: cb  cd1  cd2  cb  cd1  cb  cd1 6 dd1  db  dd1  db  dd2  dd1  db  dd1  db  dd2  dd1  db 
105.Merge si va afisa 102
106.Merge si va afisa 7 7 7 7 14
107.Crapa ca nu are acces la get_x, facem mostenirea de la B publica
108.Merge si afiseaza 22345
109.Crapa la liniile 6 si 8 pt ca obiectul constant apeleaza metoda f1 care nu e constanta, si ii punem const
110.Crapa la linia 7 pt ca x-ul e static si nu e declarat inafara clasei. Ca solutie, il declaram inafara clasei iar programul va compila dar nu va afisa nimic
111.Eroare la linia 18, conversie din tip derivat in tip de baza, ca sa reparam face al 2 lea pointer de tip d si va afisa 51.
112.Eroare la linia 8, ca acea metoda nu e folosita corect, ar trebui sa o facem FRIEND