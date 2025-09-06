# Examen 14 iunie 2024 numarul 2

## Cerinte

8. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;

class C
{
    int x;
public:
    C(int x = 0) : x(x) {}
    operator int() 
    {
        return x;
    }
}

int main()
{
    C *arr = new C[12](2020);
    for (int i = 1; i < 12; i++) cout << arr[i];
    return 0;
}
```

9. Precizati raspunsul corect pentru fiecare din intrebarie de mai jos:
    1. [A/F] Operatorii "sizeof()", "::" si "?" pot fi suprascrisi doar ca functii membre.
    2. [A/F] Se poate schimba precedenta operatorilor, dar nu se poate schimba numarul de operanzi.
    3. [A/F] Clasele derivate pot sa-si redefineasca operatorii
    4. [A/F] Operatorul de atribuire poate fi supraicarcat numai ca functie prieten.
    5. [A/F] Functiile operator nu pot intoarce referinte.

10. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;

class B {
public:
    B() { cout << "B"; }
    virtual ~B() { cout << "~B"; }
};
struct C : B {
    C() { cout << "C"; }
    ~C() { cout << "~C"; }
};

class D : C {
public:
    D() { cout << "D"; }
    ~D() { cout << "~D"; }
};

int main() {
    B *pb = new D();
    delete pb;
}
```

11. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>

class A {
protected:
    int x;
public:
    A(int a = 1) : x(a) { std::cout << "?"; }
    int getx() { return x; }
    virtual void fct() const {};
    virtual ~A() {};
};

class B : public {
    int y;
public:
    B(int b = 2) : y(b) { std::cout << "!!"; }
    void fct(int z) const { std::cout << x << " " << z << "\n"; }
};

void g(const A &am) {
    am.fct(2025);
}

int main() {
    A getx;
    B Y(getx.getx());
    g(Y);
}
```

12. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;

class A {
    int &x;
    int y;
public:
    A(int a, int b = 0) : x(b) { y = a; }
    operator int () { return x + y; }
    void foo() { y += x; }
};

int main() {
    A a(20, 25);
    a.foo();
    A b(3101); b = a;
    cout << b;
    return 0;
}
```

13. Precizati raspunsul corect pentru fiecare din intrebarie de mai jos:
    1. [A/F] O functie membra statica poate fi virtuala.
    2. [A/F] O functie membra statica nu poate fi supraincarcata intr-o clasa derivata prin schimbarea numarului de parametrii.
    3. [A/F] O functie membra statica poate folosi atat variabile statice cat si constante statice.
    4. [A/F] O functie membra statica nu poate face parte dintr-o clasa locala.
    5. [A/F] O data membra constanta statica trebuie sa fie definita in afara clasei.

14. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>

using namespace std;

class Baza {
protected: int x;
public:
    Baza() { cout << "1 "; }
    Baza(int xx) { x = xx; cout << "2 "; }
    Baza(Baza &ob) { x = ob.x; cout << "3 "; } };

class Derivata : public Baza { int y;
public:
    Derivata() { cout << "4 "; x = 7; y = 8; }
    Derivata(int u) { cout << "5 "; y = 9; }
    Derivata(Derivata &ob) : Baza(ob) { cout << "6 "; y = ob.y; } };

void f(Derivata ob3) { Derivata ob4(10); }
int main() { Derivata ob1, ob2(ob1); f(ob2); }
```

15. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;

class B { public: int functie() { return 10; } };

class D : virtual public B {
public: int functie() { return B::functie() + 2; } };

class D2 : virtual public B {
public: int functie() { return B::functie() + 3; } };

class MM : public D, public D2 { int x;
public:
    MM() { x = B::functie() + D::functie() + D2::functie(); }
    int functie() { return x; } };

int main() {
    B *o = new MM();
    cout << o->functie() << "\n";
    MM *p = dynamic_cast<MM*>(o);
    if (p) cout << p->functie() << "\n";
    D *p2 = dynamic_cast<D*>(o);
    if (p2) cout << p2->functie() << "\n";
    return 0; }
```

16. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class B { protected: int x;
public:
    B(int i = 0) : x(i) {}
    operator int() { return x; }
};
class D : public B {
public:
    D(int i = 0) : B(i) {}
    operator B() { return B(); }
    operator float() { return x; }
};
int main() { D ob(12);
    try { throw ob; }
    catch (float a) { cout << "A"; }
    catch (B b) { cout << "B"; }
    catch (D d) { cout << "C"; }
    catch(...) { cout << "D"; }
    return 0; }
```

17. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class cls1 {
    int x;
public:
    cls1() { x = 1; }
    int g() { static int i; i++; return (i + 2*x); }
};

class cls2 {
    int x;
public:
    cls2() { x = 2; }
    cls &f() { cout << x << endl; static cls1 ob; return ob; }
};
int main() {
    cls2 ob;
    cout << ob.f().g();
    return 0;
}
```

18. Precizati raspunsul corect pentru fiecare din intrebarie de mai jos:
    1. Selectati caracteristica corecta incapsularii:
        a. Desemneaza ca private toate datele membre si toate functiile membre ale clasei.
        b. Reprezinta incorporarea componentelor unei clase in alta.
        c. Doar metodele proprii ale obiectului pot accesa starea acestuia.
        d. Nu permite definirea nivelurilor de acces pentru elementele unei clase.
    2. [A/F] O clasa derivata nu este obligata sa mosteneasca toate elementele clasei de baza.
    3. [A/F] Cand tipul return at de o functie nu este declarat explicit, i se atribuie automat int.
    4. [A/F] Declararea unei clase Y ca prieten al clasei C limiteaza accesul functiilor clasei Y.
    5. [A/F] Class, union si struct pot participa la mostenire.

## Rezolvarea mea (2025-08-30-1340-1430)

8. Nu compileaza, deoarece nu a supraincarcat operatorul de iesire "<<". Modificam linia 18: `for (int i = 1; i < 12; i++) cout << i;`

9.  Avem:
    1 - F
    2 - A
    3 - A
    4 - F
    5 - F

10. Compileaza si afiseaza BCD~D~C~B

11. Nu compileaza, deoarece argumentul e de tipul B, iar parametrul e de tipul clasei A. Modificam linia 20: `void g(const B &am)`

12. Nu compileaza, intrucat nu am supraincarcat operatorul de iesire "<<". Modificam linia 17: `cout << 8;`

13. Avem:
    1 - F
    2 - A
    3 - A
    4 - F
    5 - A

14. Compileaza si afiseaza 1 4 1 6 1 6 1 5

15. Compileaza si afiseaza 53

16. Compileaza si afiseaza C 

17. Nu compileaza, intrucat obiectul ob de tipul cls2 nu contine nicio metoda g(). Modificam linia 10: `class cls2 : public cls1`

18. Avem:
    1 - b 
    2 - F
    3 - A
    4 - A
    5 - A
