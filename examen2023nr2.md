# Examen scris: Programare Orientata pe Obiecte
**Data:** 24/06/2023
**Nr:** 2

1. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class cls {
        int x;
    pulbic:
        cls(int i) { x = i; }
        int set_x(int i) { int y = x; x = i; return y; }
        int get_x() {return x;}
    };
    int main()  {
        cls *p = new cls[10];
        int i = 3;
        for (; i < 10; i++) { p[i].set_x(i); }
        for (i = 0; i < 10; i++) { cout << p[i].get_x(); }
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

2. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class A {
    protected:
        int x = 5;
    public:
        A(int i = 0) { x = i; }
        virtual A schimb() { return (2022 - x); }
        virtual void afisare() { cout << x; }
    };
    class B : public A {
    public:
        B(int i = 0) { x = i; }
        void afisare() { cout << x + 1; }
    };
    int main() {
        A *p = new B(2023);
        *p = p->schimb();
        p->afisare();
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

3. Descrieti pe scurt clasele de tip template/sablon (sintaxa, particularitati, exemplu).

4. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class C1 {
        int x;
    public:
        C1(int xx = 3) { x = xx; }
        int get_x() { return x; }
    };
    class C2 {
        int y;
    public:
        C2(int yy = 7) { y = yy; }
        int get_y() { return y; }
        C1 operator+(C2 b) { return C1(y + b.y); }
    };
    C2 operator+(C1 a, C1 b) { return C2(a.get_x() + b.get_x()); }
    int main() {
        C1 a, b; C2 c;
        c = (a + b) + c;
        cout << c.get_y();
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

5. Descrieti pe scurt caracteristicile transmiterii parametrilor unei functii prin pointer, respectiv prin referinta si diferente intre aceste modalitati (dati si un exemplu).

6. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class C {
        const int i;
    public:
        C(int &j) : i(j) { cout << "C" << " "; }
    };
    int main() {
        int i = 6, j = 2023;
        C ob1(i), ob2(j), ob3(ob1);
        ob3 = ob2;
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

7. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class C {
        int x;
    public:
        C() : x(12) { cout << "C" << ' '; }
        C(const C &c) : x(c.x) { cout << "C&" << " "; }
        void increase() { this->x += 2023; }
    };
    C foo(C &c) {
        c.increase();
        return c;
    }
    int main() {
        C c;
        C x = foo(c);
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

8. Explicati diferenta intre up-casting si down-casting. In ce situatii putem/trebuie sa ne folosim de aceste functionalitati?

9. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class A {
    public:
        A() {}
        void f() { throw 3; }
        ~A() { f(); }
    };
    int main() {
        try {
            A a;
            throw 10;
        } catch (int val) {
            cout << "Value: " << val << "\n";
        }
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

10. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class clsB {
        int x;
    public:
        clsB(int i = 0) { cout << "C0 "; x = i; }
        ~clsB() { cout << "D0 "; }
    };
    class cls : public clsB {
        int x;
    public:
        cls(int i = 0) { cout << "C1 "; x = i; }
        ~cls() { cout << "D1 "; }
    } p;
    class clss : virtual public clsB {
        int x;
        cls xx;
    public:
        clss(int i = 0) { cout << "C2 "; x = i; }
        ~clss() { cout << "D2"; }
    };
    class clss2 {
        int x;
        clss xx;
        clss xxx;
    public:
        clss2(int i = 0) { cout << "C3 "; x = i; }
        ~clss2() { cout << "D3"; }
    };
    clss o;
    int main() {
        clss2 s;
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

11. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    template <class T, class U>
    T f(T x, U y) { return x + y; }
    int f(int x, int y) { return x - y; }
    int main() {
        int *a = new int(3);
        int b = 23;
        cout << f(*a, *a);
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

12. Descrieti utilizarea cuvantului cheie mutable in C++.

13. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    class A {
        int &a;
    public:
        A(int &a) : a(a) {}
        void set_a(int value) { a = value; }
    };
    int main() {
        int a = 10;
        const A obj(a);
        obj.set_a(3);
        std::cout << a << std::endl;
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

14. Supraincarcarea operatorilor binari (sintaxa, exemple particularitati).

15. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    using namespace std;
    class Base {
    protected:
        int x;
    public:
        Base(int i) : x(i) {}
        int getX() const { return x; }
        void setX(int x) { this->x = x; }
        virtual int add(int z) { return x + z * 2; }
        virtual ~Base() {}
    };
    class Derived : public Base {
        int y;
    public:
        Derived(int i = 1, int k = 2) : Base(i), y(k) {}
        int getY() const { return y; }
        void setY(int y) { this->y = y; }
        int add(int z) { return x + y * 2 + z * 3; }
    };
    void func(Base *b, int i) {
        Base b_obj = *b;
        cout << b_obj.add(i) << "; ";
    }
    int main() {
        Base *d = new Derived();
        func(d, 4);
        d->setY(4);
        d->setX(3);
        func(d, 5);
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

16. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    #include <typeinfo>
    using namespace std;
    class B {
        int i;
    public:
        B() { i = 100; }
        virtual int get_i() { return i; }
    };
    class D : B {
        int j;
    public:
        D() { j = 32; }
        int get_j() { return j; }
    };
    int main() {
        B *p = new D;
        cout << p->get_i();
        if (typeid(*p) == typeid(D)) { cout << (D*)p->get_j(); }
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu []

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

17. Descrieti rolul marcarii functiilor si claselor cu keyword-ul friend, ilustrati sintaxa prin exemple.

18. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.

    ```cpp
    #include <iostream>
    class Forma {
    public:
        virtual double arie() const = 0;
        virtual ~Forma() {}
    };
    class Cerc {
        double raza;
    public:
        double arie() const { return 3.14 * raza * raza; }
    };
    int main() {
        Forma *cerc = new Cerc(5);
        std::cout << cerc->arie() << std::endl;
        delete cerc;
        return 0;
    }
    ```

    Programul compileaza? DA [] Nu [ ]

    Daca DA ce se afiseaza pe ecran:

    Daca NU: de ce nu?

    Modificarea care il face sa mearga (o singura linie modificata, precizat nr linie modificata si modificarea)

## Rezolvarea mea
Rezolvarea mea: 

1. Nu compileaza. Inlocuim `cls(int i) { x = i; }` cu `cls(int i = 0) { x = i; }` 

2. Complieaza si afiseaza 2017 

3. Template, sintaxa: `template <class T>`. Utile pentru claritate, corectitudine a codului. Permite numar variabil de parametrii pentru functii 

4. Compileaza si afiseaza 13 

5. Transmiterea unui parametru prin pointeri aloca memorie unei variabile ce retine adresa retinuta de pointer; prin referinta nu se mai aloca memorie extra, se lucreaza direct cu respectiva referinta. Analog pentru returnarea valorii. Sintaxa pointer: `void f(int *p) {}`. Sintaxa referitna: `void g(int &r) {}`

6. Nu compileaza, nu are copy constructor. Adaugam linia `C (C ob) { this->i = ob->i; }` inainte de linia `};` 

7. Compileaza si afiseaza "C C& " 

8. Upcasting: atunci cand derivata ia locul bazei. Downcasting: atunci cand baza ia locul derivatei. Upcasting: avem clasa persoana si derivatele fizica, juridica si vrem un vector de persoane (si fizice si juridice) 

9. Compileaza si afiseaza "Value: 10" (Explicatie: destructor neapelat inaintea lui throw 10; intrucat obiectul a nu a iesit din scope) 

10. Nu compileaza 

11. Nu compileaza. Modificam linia `cout << f(*a, *b);` in `cout << f(*a, b);` 

12. mutable? 

13. Nu compileaza. Modificam linia const A obj(a); in A obj(a); 

14. Supraincarcarea operatorilor binari? 

15. Compileaza si afiseaza "9; 13; " 

16. Nu compileaza. Modificam linia class D : B in class D : public B 17. Friend ... nush 18. Nu compileaza. Modificam `class Cerc {` in `class Cerc : public Forma {`
