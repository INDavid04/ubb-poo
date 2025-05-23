# Exerciții rezolvate tutoriat 1

### Pentru fiecare dintre programele de mai jos, supneți dacă sunt corecte. În caz afirmativ, spuneți ce afișează, în caz negativ spuneți ce nu este corect și ce ați corecta.

1. Ex 1
```C++
class cls
{
    public:
        int x;
        cls() {x=3;}
        void f(cls &c) {cout << c.x;}
};
int main(){
    cls d;
    f(d);
    return 0;
}
```
R: GRESIT: eroare de compilare

E: ```f``` este metoda a clasei ```cls``` deci poate fi accesata doar prin intermediul unei instante(obiect) a acesteia.

Corect:
```C++
#include <iostream>
using namespace std;
class cls
{
    public:
        int x;
        cls() {x=3;}
        void f(cls &c) {cout << c.x;}
};
int main(){
    cls d;
    d.f(d); // afiseaza 3
    return 0;
}
``` 
2. Ex 2
```C++
#include<iostream>
class cls
{
public:
    int x,y;
    cls(int i=0, int j=0) {x=i; y=j;}
};
int main(){
    cls a, b, c[3]={cls(1,1), cls(2,2), a};
    cout << c[2].x;
    return 0;
}
```
R: GRESIT: eroare de compilare

E: lipseste ```using namespace std``` (```std``` abreviaitie de la *standard* si lipsa lui inseamna ca nu putem folosi lucruri din namespace-ul *standard* cum ar fi ```cout/cin```)

Corect: Adaugam linia ```using namespace std;``` inainte de definitia clasei.

3. Ex 3
```C++
#include <iostream>
using namespace std;

class cls2;
class cls1 {
    public:
        int vi;
        cls1(int v=30) {vi=v;}
        cls1(cls2 p) {vi=p.vi;}
};
class cls2 {
    public:
        int vi;
        cls2(int v=20) {vi=v;}
};
cls1 f(cls1 p) {
    p.vi++;
    return p;
}
int main() {
    cls1 p;
    f(p);
    cout << endl << p.vi;
    cls2 r; 
    f(r); 
    cout << endl << r.vi;
    return 0;
}
```
R: GRESIT: eroare de compilare

E: chiar daca ```cl2``` este declarata inainte de definitia ```cls1```, compilatorul vede variabila ```p``` din constructorul lui ```cls1(cls2 p)``` ca avand declaratie incompleta.

Corect:Mutam definitia lui ```cls2``` deasupra lui ```cls1```.
```C++
class cls2 {
    public:
        int vi;
        cls2(int v=20) {vi=v;}
};
class cls1 {
    public:
        int vi;
        cls1(int v=30) {vi=v;}
        cls1(cls2 p) {vi=p.vi;}
};
cls1 f(cls1 p) {
    /* aici se lucreaza cu o copie care va fi distrusa dupa 
    terminarea functiei => p.vi++ nu are niciun impact pe 
    obiectele din main */
    p.vi++;
    return p;
}
int main() {
    cls1 p;
    f(p);
    cout << endl << p.vi;  // afiseaza 30
    cls2 r; 
    f(r); 
    cout << endl << r.vi; // afiseaza 20
    return 0;
}
```

4. Ex 4
```C++
#include <iostream>
using namespace std;

class cls {
    public:
        int x, y;
        cls(int i=2, int j=3) {x=i+j/2; y=i-j/2;}
};
int main() {
    cls a, b, c=a;
    cout << a.x; // afiseaza 3
}
```
R: CORECT 

5. Ex 5
```C++
#include<iostream>
using namespace std;
class Test
{
    public:
        Test();
};
Test::Test() {
    cout<<"Constructor Called \n";
}
int main()
{
    cout<<"Start \n";
    Test t1();
    cout<<"End \n";
    return 0;
    /*
    afiseaza:
        Start
        End
    */
}
```
R: CORECT

E: declaratia ```Test t1()``` este vazuta ca o declaratie de functie, nu de obiect. Pentru un obiect ar fi fost ```Test t1;``` sau ```Test *t1 = new Test();``` si atunci s-ar fi apelat constructorul clasei.

6. Ex 6
```C++
#include<iostream>
using namespace std;

class Test {
        int value;
    public:
        Test (int v = 0) {value = v;}
        int getValue() { return value; }
};
int main() {
    Test t;
    cout << t.getValue(); // afiseaza 0
    return 0;
}
```
R: CORECT

7. Ex 7
```C++
#include<iostream>
using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point(int i, int j);
};
Point::Point(int i = 0, int j = 0) {
    x = i;
    y = j;
    cout << "Constructor called";
}
int main()
{
    Point t1, *t2;
    return 0;
    // afiseaza: Constructor called
}
```
R: CORECT

E: chiar daca definitia contructorului din interiorul clasei nu are valori default ai parametrilor, redefinirea acestuia in afara clasei este permisa, inlocuind-o pe cea din clasa.

8. Ex 8
```C++
#include<iostream>
using namespace std;

class Test {
    int value;
public:
    Test(int v);
};
Test::Test(int v) {
    value = v;
}
int main() {
    Test t[100];
    return 0;
}
```
R: GRESIT: eroare de compilare

E: chiar daca declaratia vectorului de 100 de elemente de tipul ```Test``` este corecta, nu avem o valoare default in parametrul constructorului, deci nu va sti cu ce valoare sa initializeze cele 100 de elemente.

Corect: Adaugam valoare default la definitia constructorului. Compileaza, dar nu afiseaza nimic.
```C++
class Test {
    int value;
public:
    Test(int v = 0); // aici
};
Test::Test(int v) {
    value = v;
}
int main() {
    Test t[100];
    return 0;
}
```

9.  Ex 9
```C++
#include<iostream>
using namespace std;

class Test {
    int &t;
public:
    Test (int &x) { t = x; }
    int getT() { return t; }
};
int main()
{
    int x = 20;
    Test t1(x);
    cout << t1.getT() << " ";
    x = 30;
    cout << t1.getT() << endl;
    return 0;
}
```
R: GRESIT: eroare de compilare

E: La apelul din constructor problema se reduce la ``` int &t = int &x``` ceea ce nu e o secventa corecta, deoarece o referinta nu poate fi reasignata. In schimb, se poate schimba valoarea unei referinte doar prin intermediul listei de initializare.

Corect: Ca sa pastrez functionalitatea programului, folosesc pentru ```t``` lista de initializare. Variabila ```x``` din ```main``` fiind transmisa ca parametru prin referinta, la schimbarea valorii acesteia va fi schimbata si valoarea datei membre ```t```, deoarece referentiaza catre aceeasi zona de memorie.

Mai multe detalii [aici](https://stackoverflow.com/questions/10956139/uninitialized-reference-member).

```C++
#include<iostream>
using namespace std;

class Test {
    int t; //aici
public:
     Test (int &x): t(x) {}
    int getT() { return t; }
};
int main()
{
    int x = 20;
    Test t1(x);
    cout << t1.getT() << " "; 
    x = 30;
    cout << t1.getT() << endl;
    return 0;
    // afiseaza: 20 30
}

```
10.  Ex 10
```C++
#include <iostream>
using namespace std;

class Fraction
{
private:
    int den;
    int num;
public:
    void print() { cout << num << "/" << den; }
    Fraction() { num = 1; den = 1; }
    int &Den() { return den; }
    int &Num() { return num; }
};
int main()
{
    Fraction f1; 
    f1.Num() = 7;
    f1.Den() = 9;
    f1.print();
    return 0;
}
```
R: CORECT: afiseaza: 7/9

E: La initializarea obiectului ```f1``` este apelat constructorul pentru care valorile lui ```num``` si ```den``` devin 1. Metodele ```Num()``` si ```Den()``` intorc referinte catre valorile datelor membre, deci orice modificare a rezultatului acestora, se va vedea si pe acestea.

11.  Ex 11
```C++
#include <iostream>
using namespace std;

class Test
{
private:
    int x;
public:
    void setX (int x) { Test::x = x; }
    void print() { cout << "x = " << x << endl; }
};
int main()
{
    Test obj;
    int x = 40;
    obj.setX(x);
    obj.print();
    return 0;
}
```

R: CORECT: afiseaza: x= 40

E: valoarea datei membre ```x``` este setata prin intermediul setter-ului ```setX```, si afisata prin intermediul metodei ```print()```.

12.  Ex 12
```C++
#include <iostream>
using namespace std;
class A
{
    int id;
public:
    A (int i) { id = i; }
    void print () { cout << id << endl; }
};
int main()
{
    A a[2];
    a[0].print();
    a[1].print();
    return 0;
}
```
R: GRESIT: eroare de compilare

E: lipseste valoarea default din parametrul constructorului clasei ```A```. Secventa ```A a[2]``` reprezinta declararea unui vector de 2 elemente de tipul ```A```. Pentru fiecare dintre ele este apelat constructorul, care nu stie ce valoare sa ii dea lui ```i```. 

Corect: Adaugam valoarea default la parametrul constructorului.
```C++
#include <iostream>
using namespace std;
class A
{
    int id;
public:
    A (int i=0) { id = i; }
    void print () { cout << id << endl; }
};
int main()
{
    A a[2];
    a[0].print();
    a[1].print();
    return 0;
    /*
    afiseaza: 
    0
    0
    */
}
```
