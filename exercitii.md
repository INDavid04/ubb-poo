# Codul cpp aferent fiecarui exercitiu
- **Sursa:** Examen: Exercitii > Exercitiul1.pdf-Exercitiul12.pdf
---

```cpp
/// Exercitiu 1 Varianta 1

#include <iostream>

using namespace std;

class C{
    int c;
    public: C(int p=1){c=p;}
    int &get()const{return c;}
};

int f(C op){return op.get();}

int main(){
    C o1;
    int x=f(o1);

    /*
    Apelam C() si setam o1.c = 1
    x = 1

    Compileaza dar nu afiseaza nimic (gresit)
    */

    return 0;
}
```

```cpp
/// Exercitiu 1 Varianta 2

#include <iostream>

using namespace std;

class C{
    int c;
    public: C(int p=1){c=p;}
    const int & get(){return c;}
};

int f(const C*op){return op->get();}

int main(){
    C o1;
    int x=f(&o1);

    /// Copileaza (gresit)

    return 0;
}
```

```cpp
/// Exercitiu 1 Varianta 3

#include <iostream>

using namespace std;

class C{
    int c;
    public: C(int p=1){c=p;}
    const int & get() {return c;}
};

int f(const C &op) {return op.get();}

int main(){
    C o1;
    int x=f(o1);

    /// Nu compileaza deoarece functia f primeste ca parametru o referinta catre o constanta si apeleaza o functie pe care nu o cunoaste. Modificam linia 13: int f(const C op { return op.get(); }) (gresit)

    return 0;
}
```

```cpp
/// Exercitiu 1 Varianta 4

#include <iostream>

using namespace std;

class C{
    int c;
    public: C(int p=1){c=p;}
    const int & get()const{return c;}
};

int main(){
    const C o1;
    int x=o1.get();

    /// Nu compileaza deoarece obiectul o1 este constant, insa apeleaza get care si ea este constanta, ceea ce e bun insa imi returneaza c si dupa il incrementeaza. Modificam linia 10: const int &get() const { return c; } (corect)

    return 0;
}
```

```cpp
/// Exercitiu 1 Varianta 5

#include <iostream>

using namespace std;

class C{
    int c;
    public: C(int p=1){c=p;}
    const int & get(){return c;}
};

int f(const C op){return op.get();}

int main(){
    C o1;
    int x=f(o1);

    /// Compileaza desi functia f nu primeste ca argument formal o referinta ci un obiect constant, prin urmare se copiaza obiectul o1 in op si apeleaza op.get. (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 2 Varianta 1

#include <iostream>

using namespace std;

class B{
public: virtual B * fv(){return this;}
    int adun(int p){return p+1;}
};

class D:public B{
public: virtual D * fv(){return this;}
    int adun (int p){return p+2;}
};

int main(){
    B *p =new D;
    int x=p->fv()->adun(1);

    cout << x << "\n";

    /// Copileaza si retin in x valoarea 2 (corect)

    return 0;
}
```

```cpp
/// Exercitiul 2 Varianta 2

#include <iostream>

using namespace std;

class B{
public: virtual B* fv(){return this;}
    virtual int adun(int p){return p+1;}
};
class D:public B{
public: virtual B* fv(){return this;}
    virtual int adun (int p){return p+2;}
};
int main(){
    B *p =new D;
    int x=p->fv()->adun(1);

    cout << x << "\n";

    /// Compileaza si afiseaza 3 (corect)

    return 0;
}
```

```cpp
/// Exercitiul 2 Varianta 3

#include <iostream>

using namespace std;

class B{
public: virtual B* fv(){return this;}
    int adun(int p){return p+1;}
};

class D:public B{
public: virtual B* fv(){return this;}
    int adun (int p){return p+2;}
};

int main(){
    B *p =new D;
    int x=p->fv()->adun(1);

    cout << x << "\n";

    /// Compileaza si afiseaza 2 (corect)

    return 0;
}
```

```cpp
/// Exerctitiul 2 Varianta 4

#include <iostream>

using namespace std;

class B{
public: virtual B * fv(){return this;}
    virtual int adun(int p){return p+1;}
};

class D:public B{
public: virtual D * fv(){return this;}
    virtual int adun (int p){return p+2;}
};

int main(){
    B *p =new D;
    int x=p->fv()->adun(1);

    cout << x << "\n";

    /// Compileaza si afiseaza 3

    return 0;
}
```

```cpp
/// Exercitiul 2 Varianta 5

#include <iostream>

using namespace std;

class B{
public: B * fv(){return this;}
    virtual int adun(int p){return p+1;}
};

class D:public B{
public: B * fv(){return this;}
    virtual int adun (int p){return p+2;}
};

int main(){
    B *p =new D;
    int x=p->fv()->adun(1);

    cout << x << "\n";

    /// Compileaza si afiseaza 2 (gresit, explicatie, desi se apeleaza fv din B, se returneaza this, pointer care contine adresa obiectului de tip D)

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 1

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B{
    int *d;
public: 
    D(int p){d=new int; *d=p;}
    D(const D& s):B(s){d=new int; *d=*(s.d);}
    ~D(){delete d;}
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(3);
    o1=o2;o2.set(4);

    /// Avem D(2) care apeleaza B() care initializeaza private o1.b = 1 si ne intoarcem in derivata care initializeaza private o1.*d = 2
    /// Avem D(3) care apeleaza B() care initializeaza private o2.b = 1 si ne intoarcem in derivata care initializeaza private o2.*d = 3
    /// Pe urmatoarea linie din main, apelam constructorul de copiere al lui D care apeleaza B(s) insa deoarece nu avem vreun constructor de copiere al lui B, rezulta eroare de compilare.
    /// Asadar, nu compileaza deoarece se apeleaza B(s) fara a avea un constructor de copiere al lui B pentru un obiect de tipul D. Modificam linia 16: D(const D& s) {d=new int; *d=*(s.d);}
    /// Gresit(vezi pdf-ul)

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 2

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B{
    int *d;
public: 
    D(int p){d=new int; *d=p;}
    D(const D& s):B(s){d=new int; *d=*(s.d);}
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(o1);
    o1=o2;o2.set(4);

    /// Nu compileaza deoarece nu avem definit operatorul =, prin urmare se apeleaza operatorul defaul, cel predefinit copiind bit cu bit. De aceea se va sterge de doua ori d. (partial corect, vezi pdf-ul)

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 3

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B{
    int *d;
public: 
    D(int p):B(p){d=new int; *d=p;}
    D(const D& s){d=new int; *d=*(s.d);}
    D & operator=(const D & s){d=new int; *d=*(s.d);return *this; }
    ~D(){delete d;}
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(o1);
    o1=o2;

    /// Compileaza, se retine 2 la adresa lui d

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 4

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B {
    int *d;
public: 
    D(int p):B(p){d=new int; *d=p;}
    D & operator=(const D & s){d=new int; *d=*(s.d);return *this; }
    ~D(){delete d;}
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(o1);
    o2.set(3);

    /// Avem D(2) care apeleaza B(2) care initializeaza private o1.b = 2 si revine in derivata unde initializeaza private o1.*d = 2.
    /// Avem D(o1) care copiaza bit cu bit deoarece nu avem constructor de copiere definit de programator, il apeleaza pe cel default.
    /// Pe urmatoarea linie apeleam metoda set(3) care seteaza private o2.*d = 3
    /// Asadar, nu comileaza deoarece se va sterge de doua ori d, modificam linia 22: D o1(2), o2(2). (corect)

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 5

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B {
    int *d;
public: 
    D(int p):B(p){d=new int; *d=p;}
    D & operator=(const D & s){d=new int; *d=*(s.d);return *this; }
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(o1);
    o2.set(3);

    /// Nu compileaza, se apeleaza constructorul de copiere implicit, se copiaza bit cu bit, d retine aceeasi valoare si in o1 si in o2. Deoarece nu avem destructorul in care sa eliberam memoria, rezulta memory leak. Modificam linia 21: D o1(2), o2(2);

    return 0;
}
```

```cpp
/// Exercitiul 3 Varianta 6

#include <iostream>

using namespace std;

class B{
    int b;
public: B(int p=1){b=p;}
};

class D: public B {
    int *d;
public: 
    D(int p):B(p){d=new int; *d=p;}
    D & operator=(const D & s){d=new int; *d=*(s.d);return *this; }
    ~D(){delete d;}
    void set(int p){*d=p;}
};

int main() {
    D o1(2),o2(o1);
    o1=o2;o2.set(3);

    /// Nu compileaza deoarece se sterge de doua ori d intrucat nu avem constructor de copiere definit de programator asa ca se va apela constructorul de copiere implicit care va copia bit cu bit.

    return 0;
}
```

```cpp
/// Exercitiul 4 Varianta 1

#include <iostream>

using namespace std;

class C {
    float z;
public:
    C() { z = 1.3; }
    float op(float x, float y, float t) {
        return x + y + z + t;
    }
    float op(float x, float y = 1.0) {
        return x + y + z;
    }
    float op() {
        return z;
    }
};

int main() {
    C c;
    float i,j, k;
    i=c.op(1);
    j=i+c.op(2.2, 4.8);
    k=c.op(2.2, 3.5, 4);

    cout << i << " " << j << " " << k << "\n";

    /// Avem C() care seteaza private c.z = 1.3
    /// Dupa avem i = c.op(1) = 3.3
    /// Dupa avem j = i + c.op(2.2, 4.8) = 3.3 + 1.3 + 2.2 + 4.8 = 4.6 + 7 = 11.6
    /// Dupa avem k = c.op(2.2, 3.5, 4) = 1.3 + 2.2 + 3.5 + 4 = 3.5 + 7.5 = 11.0

    /// Compileaza si retine in i, j, k valorile 3.3, 11.6, 11.0 (corect insa de observat este ca se afiseaza 11 nu 11.0)

    return 0;
}
```

```cpp
/// Exercitiul 4 Varianta 2

#include <iostream>

using namespace std;

class C {
    float z;
public:
    C() { z = 1.3; }
    float op(float x, float y, float t) {
        return x + y + z + t;
    }
    float op(float x, float y = 1.0) {
        return x + y + z;
    }
    float op(float x) {
        return x + z;
    }
};

int main() {
    C c;
    float i,j, k;
    i=c.op(1.2);
    j=i+c.op(2.2, 4.8);
    k=c.op(2.2, 3.5, 4);

    /// i = 1.2 + 1.0 + 1.3 = 3.5
    /// j = i + 2.2 + 4.8 + 1.3 = 3.5 + 7 + 1.3 = 10.5 + 1.3 = 11.8
    /// k = 2.2 + 3.5 + 1.3 + 4 = 5.7 + 5.3 = 11

    /// Gresit, recunosc ca m-a furat, avem ambiguitate la primul apel, la i.

    return 0;
}
```

```cpp
/// Exercitiul 4 Varianta 3

#include <iostream>

using namespace std;

class C {
    float z;
public:
    C() { z = 1.3; }
    float op(float x, float y, float t) {
        return x + y + z + t;
    }
    float op(float x = 1.0, float y) {
        return x + y + z;
    }
    float op() {
        return z;
    }
};

int main() {
    C c;
    float i,j, k;
    i=c.op(1.2);
    j=i+c.op(2.2, 4.8);
    k=c.op(2.2, 3.5, 4);

    /// Nu compileaza deoarece parametrii formalli impliciti trebuiesc trecuti la final. Modificam linia 14: float op(float y, float x = 1.0) (corect)

    return 0;
}
```

```cpp
/// Exercitiul 4 Varianta 4

#include <iostream>

using namespace std;

class C {
    float z;
public:
    C() { z = 1.3; }
    float op(float x = 2.0, float y = 1.2, float t = 1.5) {
        return x + y + z + t;
    }
    int op(int y) {
        return y + z;
    }
    double op(double y) {
        return y + z;
    }
};

int main() {
    C c;
    float i,j, k;
    i=c.op();
    j=i+c.op(1.2);
    k=c.op(2);

    /// i = 2.0 + 1.2 + 1.3 + 1.5 = 6
    /// j = i + 1.2 + 1.3 = 8.5
    /// k = 1 + 2 = 3

    return 0;
}
```

```cpp
/// Exercitiul 4 Varianta 5

#include <iostream>

using namespace std;

class C {
    float z;
public:
    C() { z = 1.3; }
    float op(float x = 2.0, float y = 1.2, float t = 1.5) {
        return x + y + z + t;
    }
    float op(float y) {
        return y + z;
    }
    double op(double y) {
        return y + z;
    }
};

int main() {
    C c;
    cout << c.op() << "\n";
    cout << c.op(1.2) << "\n";
    cout << c.op(1) << "\n";

    /// Nu compileaza deoarece op(1.2) este ambiguu. Modificam inia 17: int op(int y) (corect)

    return 0;
}
```

```cpp
/// Exercitiul 5 Varianta 1

#include <iostream>

using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B() {x++; offset = 100;}
    ~B() { x--; }
    static int get_x() { return x; }
    int get_offset() { return offset; }
    int f() { return (x + offset) / 2; }
};

int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return ( (x + offset) / 2 + 1); }
};

void func(B* q, int n) {cout << q->get_x() << " ";
    for(int i = 0; i < n; i++) cout << q[i].f() << " ";
    cout<<"\n";
}

int main() {
    B* p = new B[2]; func(p, 2); delete[] p;
    p = new D; func(p, 1); delete p;
    cout << D::get_x(); 
    
    /// Avem B() care incrementeaza B::x de doua ori. Daca initial B::x era zero, acum devine 2. 
    /// Apoi apelam func(p, 2) care afiseaza "2 ". Dupa aveam un for de la 0 la 2 si afisam "50 51 \n"
    /// Apoi stergem p ceea ce face ca x sa revina la zero, B::x = 0
    /// Apoi facem un upcast, apelam D() care face ca B::x = 1, atentie, avem protected static int x deci si derivatele au acces la x
    /// Apelam func(p, 1) care afiseaza "1 " urmat de "50 \n"
    /// Apoi stergem p, adica B::x = 0
    /// La final, afisam 0
    /// Asadar, compileaza si afiseaza "2 50 51 \n 1 50 \n 0" (compileaza dar afiseaza altceva)

    return 0;
}
```

```cpp
/// Exercitiul 5 Varianta 2

#include <iostream>

using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B() { x++;offset = 100; }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_offset() { return offset; }
    int f() { return (x + offset) / 2; }
};

int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return (x + offset) / 2 + 1; }
};

void func(B* q, int n){
    cout << q->get_x() << " ";
    for(int i = 0; i < n; i++) cout << q[i].f() << " ";
    cout<<"\n";
}

int main() {
    B* p = new B[2];func(p, 2);delete[] p;
    p = new D;func(p, 1); delete p;
    cout << D::get_x();
}
```

```cpp
/// Exercitiul 5 Varianta 3

#include <iostream>

using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B() {x++; offset = 100; }
    ~B() { x--; }
    virtual static int get_x() { return x; }
    int get_offset() { return offset; }
    virtual int f() { return (x + offset) / 2; }
};

int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return (x + offset) / 2 + 1; }
};

void func(B* q, int n){
    cout << q->get_x() << " ";
    for(int i = 0; i < n; i++)cout << q[i].f() << " ";
    cout<<"\n";
}

int main() {
    B* p = new B[2];func(p, 2);delete[] p;
    p = new D;func(p, 1);delete p;
    cout << D::get_x();
}
```

```cpp
/// Exercitiul 5 Varianta 4

#include <iostream>

using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B(){ x++;offset = 100;}
    ~B() { x--; }
    static int f() { return x; }
    int get_offset() { return offset; }
    virtual int f() { return (x + offset) % 2; }
};

int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return (x + offset) % 2 + 1; }
};

void func(B* q, int n){
    for(int i = 0; i < n; i++) cout << q[i].f() << " ";
    cout<<"\n";
}

int main() {
    B* p = new B[2];func(p, 2);delete[] p;
    p = new D;func(p, 1);delete p;
}
```

```cpp
/// Exercitiul 5 Varianta 5

#include <iostream>

using namespace std;

class B {
protected:
    static int x;
    int offset;
public:
    B() { x++; offset = 100; }
    ~B() { x--; }
    static int get_x() { return x; }
    int get_offset() { return offset; }
    static int f() { return (x + get_offset()) % 2; }
};

int B::x = 0;

class D : public B {
public:
    D() { x++; }
    ~D() { x--; }
    int f() { return (x + offset) % 2 + 1; }
};

void func(B* q, int n){
    for(int i = 0; i < n; i++)cout << q[i].f() << " ";
    cout<<"\n";
}

int main() {
    B* p = new B[2];func(p, 2); delete[] p;
    p = new D; func(p, 1); delete p;
    cout << D::get_x();
}
```

```cpp
/// Exercitiul 6 Varianta 1

#include <iostream>

using namespace std;

class A{
    int x;
public:
    A(int i = 25){x = i; }
    int& get_x() const { return x; }
    void set_x(int i) { x = i; }
    A& operator=(A a1){
        set_x(a1.get_x());
        return *this;
    }
};

int main() {
    A a(18), b(7);
    (b=a).set_x(27);
    int i;
    i=b.get_x();

    /// Avem A(18) care initalizeaza private a.x = 18
    /// Avem A(7) care initalizeaza private b.x = 7
    /// Compileaza si initializeaza i = 27 (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 6 Varianta 2

#include <iostream>

using namespace std;

class A{
    int x;
public:
    A(int i = 25){ x = i; }
    int get_x() const{ return x;}
    void set_x(int i){ x=i; }
    A operator=(A a1) {
        set_x(a1.get_x());
        return a1;
    }
};

int main() {
    A a(18), b(7);
    (b=a).set_x(27);
    int i;
    i=b.get_x();

    /// Compileaza, i = 27 (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 6 Varianta 3

#include <iostream>

using namespace std;

class A {
    int *x;
public:
    A(int i = 25){ x = new int(i); }
    int& get_x() const { return *x; }
    void set_x(int i) { x = new int(i); }
    A& operator=(A a1) {
        set_x(a1.get_x());
        return *this;
    }
};

int main() {
    A a(18), b(7);
    (b=a).set_x(27);
    int i;
    i=b.get_x();

    /// Nu compileaza deoarece nu putem return o referinta care nu este constata. Stergem const. (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 6 Varianta 4

#include <iostream>

using namespace std;

class A {
    int *x;
public:
    A() { x = new int(0); }
    A(int i) { x = new int(i); }
    int& get_x() const { return *x; }
    void set_x(int i) { x = new int(i); }
    A operator=(A a1) { set_x(a1.get_x());return a1;}
};

class B : public A {
    int y;
public:
    B() : A() { y = 0; }
    B(int i) : A(i){ y = i;}
    void afisare() const { cout << y; }
};

int main() {
    B a(112), b, *c;
    int i;
    i=(b = a).get_x();
    (c = &a)->afisare();

    /// Compileaza si afiseaza 0 (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 6 Varianta 5

#include <iostream>

using namespace std;

class A {
    int x;
public:
    A(){ x = 0; }
    A(int i) { x = i; }
    int& get_x() const { return x; }
    void set_x(int i) { x = i; }
    A operator=(A a1) { set_x(a1.get_x()); return a1;}
};

class B : public A {
    int y;
public:
    B() : A(){ y = 0;}
    B(int i) : A(i) { y = i; }
    void afisare() const { cout << y; }
};

int main() {
    B a(112), b, *c;
    int i;
    // i= (b = a).get_x()<<"\n";
    (c = &a)->afisare();

    /// Nu compileaza, comentam linia 28 (gresit)

    return 0;
}
```

```cpp
/// Exercitiul 7 Varianta 1

#include <iostream>

using namespace std;

int x = 10;

void f(int x) {
    cout << x << " ";

    class A {
    protected:
        int x;
    public:
        A(int a = 30) {
            x = a;
            cout << x << " ";
        }
    };

    class B : public A {
        int x;
    public:
        B(int b = 40) {
            x = b;
            cout << x << " " << x << " ";
        }
        int afis() { return x + A::x; }
    } ob2;
    
    cout << x + ::x + ob2.afis();
}

int main() {
    f(20);

    /// Afiseaza "20 "
    /// ob2.x = 30
    /// Afiseaza "30 "

    /// Nu compileaza deoarece B mosteneste A care are un camp protected x si B are un camp private x. Inlocuim protected cu private.

    return 0;
}
```

```cpp

```

```cpp
/// Exercitiul 7 Varianta 3

#include <iostream>

using namespace std;

int x = 10;

void f(int x) {
    cout << x << " ";

    class A {
    protected:
        int x;
    public:
        A(int a = 20) {
            x = a;
            cout << x << " ";
        }
    };

    class B : public A {
        int x;
    public:
        B(int b = 30) {
            x = b;
            cout << x << " " << x << " ";
        }
        int afis() { return x + A::x; }
    } ob2;
    
    int B::afis() { return x + A::x; }
    cout << x + ::x + ob2.afis();
}

int main() {
    f(40);

    return 0;
}
```

```cpp
/// Exercitiul 7 Varianta 4

#include <iostream>

using namespace std;

int x = 50;

void f(int x) {
    cout << x << " ";

    class A {
    protected:
        int x;
    public:
        A(int a = 20) {
            x = a;
            cout << x << " ";
        }
    };

    class B : public A {
        static int x;
    public:
        B() {
            cout << x << " ";
        }
        int afis() { return x + A::x; }
    } ob;
    
    int B::x = 30;
    cout << x + ::x + ob.afis();
}

int main() {
    f(40);

    return 0;
}
```

```cpp
/// Exercitiul 7 Varianta 5

#include <iostream>

using namespace std;

int x = 30;

void f(int x) {
    cout << x << " ";

    class A {
    protected:
        int x;
    public:
        A(int a = 20) {
            x = a;
            cout << x << " ";
        }
    };

    class B : public A {
        int x;
    public:
        B(int b = 30) {
            x = b;
            cout << x << " ";
        }
        static int afis() { return ::x; }
    } ob;
    
    cout << ::x + B::afis();
}

int main() {
    f(40);

    return 0;
}
```

```cpp
/// Exercitiul 8 Varianta 1

#include <iostream>

using namespace std;

class X {
    int x;

    class Y {
        int y;
    public:
        Y(int b = 2) {
            y = b;
            cout << y << " ";
        }
        void afis() {
            cout << x << " " << y;
        }
    } ob1;
public:
    X(int a = 1) {
        x = a;
        cout << x << " ";
    }
    void afis() { ob1.afis(); }
};

int main() {
    X ob2;
    ob2.afis();

    return 0;
}
```

```cpp
/// Exercitiul 8 Varianta 2

#include <iostream>

using namespace std;

class X {
    static int x;

    class Y {
        int y;
    public:
        Y(int b = 2) {
            y = b;
            cout << y << " ";
        }
        void afis() {
            cout << x << " " << y;
        }
    } ob1;
public:
    X(int a = 1) {
        x = a;
        cout << x << " ";
    }
    void afis() { ob1.afis(); }
};

int X::x = 3;

int main() {
    X ob2;
    ob2.afis();

    return 0;
}
```

```cpp
/// Exercitiul 8 Varianta 3

#include <iostream>

using namespace std;

class X {
    int x;

    class Y {
        int y;
    public:
        Y(int b = 1) {
            y = b;
            cout << y << " ";
        }
        void afis() {
            X ob3(10);
            cout << ob3.x;
        }
    } ob1;
public:
    X(int a = 2) {
        x = a;
        cout << x << " ";
    }
    void afis() { ob1.afis(); }
};

int main() {
    X ob2;
    ob2.afis();

    return 0;
}
```

```cpp
/// Exercitiul 8 Varianta 4

#include <iostream>

using namespace std;

class X {
    int x;

    class Y {
        int y;
    public:
        Y(int b = 1) {
            y = b;
            cout << y << " ";
        }
        void afis() {
            X ob3(4);
            cout << ob3.x;
        }
    } ob1;
public:
    X(int a = 2) {
        x = a;
        cout << x << " ";
    }
    void afis() { ob1.afis(); }
};

int main() {
    X ob2;
    ob2.ob1.afis();

    return 0;
}
```

```cpp
/// Exercitiul 8 Varianta 5

#include <iostream>

using namespace std;

class X {
    int x;

    class Y {
        int y;
    public:
        Y(int b = 1) {
            y = b;
            cout << y << " ";
        }
        void afis() {
            X ob3(4);
            cout << ob3.x;
        }
    } ob1;
public:
    X(int a = 2) {
        x = a;
        cout << x << " ";
    }
    void afis() { ob1.afis(); }
};

int main() {
    Y ob2;
    ob2.afis();

    return 0;
}
```

```cpp
/// Exercitiul 9 Varianta 1

#include <iostream>

using namespace std;

class Baza {
protected:
    int x,y;
public:
    Baza() {
        this->x = 0;
        this->y = 0;
    }
    Baza(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int Suma() {return x + y;}
};

class Derivata : public Baza {
    double t;
public:
    Derivata(int x, int y, double t) {
        Baza(x,y);
        this -> t = t;
    }
    double Suma() {return x + y + t;}
};

int main() {
    Derivata d(5, 3, 1.5);
    int i= d.Suma();

    return 0;
}
```

```cpp
/// Exercitiul 9 Varianta 2

#include <iostream>

using namespace std;

class Baza {
protected:
    int x,y;
public:
    Baza() {
        this->x = 0;
        this->y = 0;
    }
    Baza(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int Suma() {return x + y;}
};

class Derivata : public Baza {
    double t;
public:
    Derivata() {
        this -> t = 2.5;
    }
    Derivata(Derivata& derivata) {
        Baza(derivata.x + 1, derivata.y + 1);
        this -> t = derivata.t;
    }
    double Suma() {return x + y + t;}
};

int main() {
    Derivata d;
    Derivata d1(d);
    int i= d1.Suma();

    return 0;
}
```

```cpp
/// Exercitiul 9 Varianta 3

#include <iostream>

using namespace std;

class Baza {
protected:
    int x,y;
public:
    Baza() {
        this.x = 0;
        this.y = 0;
    }
    Baza(int x, int y) {
        this.x = x;
        this.y = y;
    }
    int Suma() {return x + y;}
};

class Derivata : public Baza {
    double t;
public:
    Derivata() {
        this.t = 2.5;
    }
    Derivata(Derivata& derivata) {
        Baza(derivata.x + 1, derivata.y + 1);
        this.t = derivata.t;
    }
    double Suma() {return x + y + t;}
};

int main() {
    Derivata d;
    Derivata d1(d);
    int i= d1.Suma();

    return 0;
}
```

```cpp
/// Exercitiul 9 Varianta 4

#include <iostream>

using namespace std;

class Baza {
protected:
    int x,y;
public:
    Baza(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int Suma() {return x + y;}
};

class Derivata : public Baza {
    double t;
public:
    Derivata() {
        this -> t = 2.5;
    }
    Derivata(Derivata& derivata) {
        Baza(derivata.x + 1, derivata.y + 1);
        this -> t = derivata.t;
    }
    double Suma() {return x + y + t;}
};

int main() {
    Derivata d;
    Derivata d1(d);
    int i= d1.Suma();

    return 0;
}
```

```cpp
/// Exercitiul 9 Varianta 5

#include <iostream>

using namespace std;

class Baza {
protected:
    int x,y;
public:
    Baza() {
        this->x = 0;
        this->y = 0;
    }
    Baza(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int Suma() {return x + y;}
};

class Derivata : public Baza {
    double t;
public:
    Derivata() {
        Baza(1,1);
        this -> t = 3.5;
    }
    Derivata(Derivata& derivata) {
        Baza(derivata.x + 1, derivata.y + 1);
        this -> t = derivata.t;
    }
    double Suma() {return x + y + t;}
};

int main() {
    Derivata d;
    Derivata d1(d);
    int i= d1.Suma();

    return 0;
}
```

```cpp
/// Exercitiul 10 Varianta 1

#include <iostream>

using namespace std;

class C {
    int const *p;
public:
    C (int *q) : p(q) {}
    void reload () { delete p; p = new int;}
    void set (const int * const q) { *p = *q; }
};

int main () {
    int x = 20210614;
    C ob(&x);
    const int& rx = x;
    ob.reload(); ob.set(&rx);
    
    return 0;
}
```

```cpp
/// Exercitiul 10 Varianta 2

#include <iostream>

using namespace std;

class C {
int *p;
public:
    C (int *q) : p(q) {}
    void reload () { delete p; p = new int;}
    void set (int q) const { *p = q; }
};

int main () {
    int x = 20210614;
    C ob(&x);
    ob.reload(); ob.set(x);
    
    return 0;
}
```

```cpp
/// Exercitiul 10 Varianta 3

#include <iostream>

using namespace std;

class C {
    int * p;
public:
    C (int *q) : p(q) {}
    void reload () { delete p; p = new int;}
    void set (const int * const q) { *p = *q + 13; }
    operator int () {return *p;}
};

int main () {
    int *x = new int(20210601); const int& rx = *x;
    C ob(x);
    ob.reload(); ob.set(&rx);
    cout << ob;
    
    return 0;
}
```

```cpp
/// Exercitiul 10 Varianta 4

#include <iostream>

using namespace std;

class C {
    int * const p;
public:
    C (int q) : p(new int(q)) {}
    void set (const int& q) const { *p = q + 86; }
    operator int () const {return *p;}
};

int main () {
    const C ob(91973549);
    ob.set(422032);
    cout << ob;
    
    return 0;
}
```

```cpp
/// Exercitiul 10 Varianta 5

#include <iostream>

using namespace std;

class C {
    int * const p;
public:
    C (int q) : p(new int(q)) {}
    void set (const int& q) const { *p = q + 59; }
    operator int () {return *p;}
};

int main () {
    const C ob(22973890);
    ob.set(488474);
    cout << ob;
    
    return 0;
}
```

```cpp
/// Exercitiul 11 Varianta 1

#include <iostream>

using namespace std;

class Vector2D {
    int x, y;
public:
    Vector2D(const int& a, const int& b) : x(a), y(b) {}
    Vector2D operator+ (Vector2D v) {
        Vector2D w(x + v.x, y + v.y); return w;
    }
    friend ostream& operator<< (ostream& out, Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")"; return out;
    }
};

int main () {
    cout << Vector2D(10, 5) + Vector2D(22, 159);
    
    return 0;
}
```

```cpp
/// Exercitiul 11 Varianta 2

#include <iostream>

using namespace std;

class Vector2D {
    int x, y;
public:
    Vector2D(const int& a, const int& b) : x(a), y(b) {}
    Vector2D operator+ (Vector2D v) {
        Vector2D w(x + v.x, y + v.y); return w;
    }
    friend ostream& operator<< (ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")"; return out;
    }
};

int main () {
    cout << Vector2D(2, 5) + Vector2D(4, 8);
    
    return 0;
}
```

```cpp
/// Exercitiul 11 Varianta 3

#include <iostream>

using namespace std;

class Vector2D {
    int x, y;
public:
    Vector2D(const int& a, const int& b) : x(a), y(b) {}
    friend Vector2D operator+ (Vector2D& v, Vector2D& u) {
        Vector2D w(u.x + v.x, u.y + v.y); return w;
    }
    friend ostream& operator<< (ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")"; return out;
    }
};

int main () {
    cout << Vector2D(45, 29) + Vector2D(87, 10);
    
    return 0;
}
```

```cpp
/// Exercitiul 11 Varianta 4

#include <iostream>

using namespace std;

class Vector2D {
    int x, y;
    const int translate = 10 ;
public:
    Vector2D(const int& a, const int& b) : x(a), y(b) {}
    Vector2D operator* (const Vector2D& v) {
        return Vector2D(translate + x * v.x, translate + y + v.y);
    }
    friend ostream& operator<< (ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")"; return out;
    }
};

int main () {
    cout << Vector2D(98, 69) * Vector2D(82, 12);
    
    return 0;
}
```

```cpp
/// Exercitiul 11 Varianta 5

#include <iostream>

using namespace std;

class Vector2D {
    int x, y;
public:
    Vector2D(const int& a, const int& b) : x(a), y(b) {}
    Vector2D operator* (Vector2D v) const {
        return Vector2D(x + v.y, y + v.x);
    }
    friend ostream& operator<< (ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")"; return out;
    }
};

int main () {
    cout << Vector2D(33, 40).operator*(Vector2D(77, 60));
    
    return 0;
}
```

```cpp
/// Exercitiul 12 Varianta 1

#include <iostream>

using namespace std;

class A {
public:
    A () {cout << "A";}
    ~A () {cout << "~A";}
};

class B: public A {
public:
    B () {cout << "B";}
    ~B () {cout << "~B";}
};

class C: public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};

int main () {
    A *pa = new C(); delete pa;
    
    return 0;
}
```

```cpp
/// Exercitiul 12 Varianta 2

#include <iostream>

using namespace std;

class A {
public:
    A () {cout << "A";}
    ~A () {cout << "~A";}
};

class B: A {
public:
    B () {cout << "B";}
    ~B () {cout << "~B";}
};

class C: public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};

int main () {
    A *pa = new C(); delete pa;

    return 0;
}
```

```cpp
/// Exercitiul 12 Varianta 3

#include <iostream>

using namespace std;

class A {
public:
    A () {cout << "A";}
    virtual ~A () {cout << "~A";}
};

class B: public A {
public:
    B () {cout << "B";}
    ~B () {cout << "~B";}
};

class C: public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};

int main () {
    A *pa = new C(); delete pa;

    return 0;
}
```

```cpp
/// Exercitiul 12 Varianta 4

#include <iostream>

using namespace std;

class A {
public:
    A () {cout << "A";}
    ~A () {cout << "~A";}
};

class B: public A {
public:
    B () {cout << "B";}
    ~B () {cout << "~B";}
};

class C: public A, public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};

int main () {
    A *pa = new C(); delete pa;
    
    return 0;
}
```

```cpp
/// Exercitiul 12 Varianta 5

#include <iostream>

using namespace std;

class A {
public:
    A () {cout << "A";}
    ~A () {cout << "~A";}
};

class B: public A {
public:
    B () {cout << "B";}
    virtual ~B () {cout << "~B";}
};

class C: public A, public B {
public:
    C () {cout << "C";}
    ~C () {cout << "~C";}
};

int main () {
    B *pb = new C(); delete pb;

    return 0;
}
```