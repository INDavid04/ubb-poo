# Examen 23 iunie 2025 Numarul 1

## Cerinte

1. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include<iostream>
using namespace std;
class Base {
public:
    int f() const { cout << "B1\n"; return 1; }
    int f(string) const {
        cout << "B2\n"; return 1; } };
class Derived : public Base {
public: int f() const {
    cout << "D1\n"; return 2; } };
int main() {
    string s("hello");
    Derived d;
    int x = d.f();
    d.f(s);
    return 0; }
```

2. Descrieti folosirea pointerilor folositi impreuna cu cuvantul cheie const (sintaxa, proprietati, particularitati, exemplu).

3. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class Cls
{ int a;
public:
Cls(int x):a(x){cout<<"a<< " ";}
~Cls(){cout<<"a<< " ";}
} A(10);
void adauga() { static Cls B(20);}
static Cls F(70);
Cls C(30);
int main(){Cls D(40);
adauga();
Cls E(50);
static Cls G(80);
cout<<"* "; return 0;}
```

4. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class Baza{ public: Baza(){cout<<"CB\n";} };
class Derivata1 : public Baza {
public: Derivata1(){cout<<"CD1\n";}
        ~Derivata1(){cout<<"DD1\n";} };
class Derivata2 : public Baza {
public: Derivata2(){cout<<"CD2\n";}
        virtual ~Derivata2(){cout<<"DD2\n";} };
class Derivata3 : virtual public Baza{
public: Derivata3(){cout<<"CD3\n";} };
class Derivata4 : public Baza {public:Derivata4(){cout<<"DD4\n";} };
class Derivata5 : public Derivata1, Derivata2, protected Derivata3,
      public Derivata4 { public: Derivata5(){cout<<"Derivata5\n";} };
int main(){Derivata5 obj; }
```

5. Descrieti particularitatile unui constructor definit cu atributul protected sau private (sintaxa, proprietati, particularitati, exemplu).

6. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class I { public:I(){cout<<"C1\n";}
          I(int x){cout<<<<<<"si\n";}
          void afis(){cout<<"i\n";} };
class uni : virtual public I{
public: uni(){cout<<"CU\n";}
        uni(int x):I(x){cout<<<<" cu\n";}
        void afis(){cout<<"u \n";} };
class oras : virtual public I{
public: oras(){cout<<"CO\n";}
        oras(int x):I(x){cout<<<<" co\n";}
        void afis(){cout<<"Bucuresti";} };
class unibuc : public uni,public oras{ public: unibuc(){cout<<"CUB\n";}
unibuc(int x):I(x){} };
int main(){
    unibuc obj
    obj.afis();
    unibuc obj2(10);}
```

7. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class Cls{ public: void afis(){cout<<"1 ";}
    Cls operator+(Cls obj){cout<<"2 "; return Cls();}}
    Cls operator-(Cls obj){cout<<"3 "; return Cls();};};
class Cls2 : public Cls{
public: void afis(){cout<<"4 ";}
        Cls2 operator+(Cls2 obj){cout<<"5 "; return Cls2();} };
int main() {
    Cls a;
    Cls2 d,e,f;
    (d + e).afis();
    (d - e).afis();
    (a + d).afis();
    (d + a).afis();
}
```

8. Descrieti particularitatile metodelor statice considerand in special folosirea lor la mostenirea multipla (sintaxa, proprietati, particularitati, apelare).

9. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
int main(){
    const char* sFirst = "Examen\0 2025\n";
    char sSecond[64];
    const char* sSrc = sFirst;
    char* sDst = sSecond;
    while (*sDst++ = *sSrc++);
    std::cout << sSecond;
}
```

10. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include<iostream>
using namespace std;
int main()
{int a = 1;
 int b = ++a;
 const int *a_ptr = &a;
 int *const b_ptr = &b;
 *b_ptr += 4;
 *a_ptr += 5;
 std::cout << *b_ptr << std::endl;
 std::cout << *a_ptr << std::endl;
 return 0; }
```

11. Descrieti particularitatile operatorului typeid (sintaxa, proprietati, particularitati, motivatie).

12. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class Baza{ public: virtual ~Baza(){};};
class D1 : virtual public Baza{};
class D2 : public D1{};
class D3 : virtual public Baza{};
class D4 : public D1, public D3{};
int main() {
    D4 obj;
    Baza& re = obj;
    try{ throw re; }
    catch(D1& o){cout<<"D1\n";}
    catch(D2& o){cout<<"D2\n";}
    catch(D3& o){cout<<"D3\n";}
    catch(D4& o){cout<<"D4\n";}
    catch(Baza& o){cout<<"Baza\n";}
}
```

13. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include<iostream>
using namespace std;
class B { int b;
public: B(int p = 1) { b = p; } };
class D : public B { int* d;
public:
    D(int p) { d = new int; *d = p; }
    D(const D& s) : B(s) { d = new int; *d = *(s.d); }
    ~D() { delete d; }
    void set(int p) { *d = p; }};
int main() {
    D o1(2), o2(3);
    o1 = o2;
    o2.set(4);
    return 0;}
```

14. Descrieti notiunea de destructor virtual pur in C++. (sintaxa, proprietati, particularitati, motivatie).

15. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class B {public:
virtual B* fv() { return this; }
int adun(int p) { return p + 1; }};
class D : public B {public:
virtual D* fv() { return this; }
int adun(int p) { return p + 2; }};
int main() {
    B* p = new D;
    int x = p->fv()->adun(1);
    std::cout << x << "\n";
    return 0;}
```

16. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include<iostream>
using namespace std;
class C {int c;
public: C(int p = 1) { c = p; }
        int get() const { return c; } };
int f(C op) { return op.get(); }
int main() {
    C o1;
    int x = f(o1);
    std::cout << x << "\n";
    return 0; }
```

17. Definirea copy-constructorului de catre programator (sintaxa, proprietati, particularitati, motivatie).
```cpp

```

18. Spuneti daca programul de mai jos este corect. In caz afirmativ, spuneti ce afiseaza (cu explicatii), in caz negativ propuneti o (singura) modificare prin ccare programul devine corect.
```cpp
#include <iostream>
using namespace std;
class C { int a;
          static int x;
public:
    C(int a = 22) { x++; this->a=a; }
    static int f() {return x;}
    int getA(){return a;}
};
int C::x=20;
int main() {
    C a(33);b;
    cout<<"instantieri C: "<<C::f()<<" val elem:"<<:.a.getA();
    return 0; }
```

## Rezolvarea mea

1. Nu compileaza intrucat f() nu e virtuala in clasa de baza. Modificam linia 5: `virtual int f() const {...}`

2. Sintaxa: `<tip> *<val> const`, `const <tip> *val`, `const <tip> *val const`. Proprietati: un pointer constant permite modificarea valorii dar nu permite modificarea adresei; o valoare constanta permite modificarea pointerului dar nu permite modificarea adresei; un pointer constant la o valoare constanta nu permite modificarea adresei, valorii. Exemplu: `const int *val;`, `int const *val;`, `const int const *val;`.

3. Compileaza si afiseaza "70 30 40 20 50 80 *80 50 20 40 30 70".

4. Nu compileaza, deoarece Derivata5 mosteneste Derivata2 care nu are niciun membru de acces. Modificam linia 13: `class Derivata5 : public Derivata1, public Derivata2, protected ...`.

5. Sintaxa: `class <numeClasa> {<modificator de acces>: <numeClasa>(){}};`, unde <modificator de acces> poate fi protected sau private. Proprietati: constructorul private asigura apelarea unica a acestuia, la fel si cel protected. Exemplu: 
    ```cpp
    class C {
        C() { cout << "C\n"; }
    };
    int main() {
        C c; /// afisam C
        return 0;
    }
    ```

6. Compileaza si afiseaza "CI\nCU\nCI\nCO\nCUB\nBucuresti10ci\nCI\nCU\nCI\nCO\n".

7. Nu compileaza, intrucat nu stie ce metoda afis() sa aleaga. Modificam linia 3: `class Cls { public: virtual void afis() ...`.

8. Sintaxa: `static <tip> getX() { return X; }`. Metodele statice pot folosi doar variabile statice. Folosite pentru a returna valoarea sau adresa unei variabile sau a unuui obiect static, pastrand principul de incapsulare a datelor, prin getteri/setteri.

9. Compileaza si afiseaza "Examen\0"

10. Nu compileaza, intrucat b_ptr este un pointer cu valoare constanta, prin urmare, nu putem modifica valoarea. Modificam linia 8: `b_ptr += 4;`.

11. Sintaxa: `typeid(val);`. Folosit pentru a afla tipul unei variabile.

12. Compileaza si afiseaza "Baza\n".

13. Nu compileaza, deoarece clasa B nu are niciun constructor cu un parametru de tipul D. Modificam linia 7: D(const D &s) {...}

14. Sintaxa: `virtual ~<numeClasa>() = 0;`. Forteaza ca fiecare derivata sa aiba definit destructorul.

15. Compileaza si afiseaza "3\n".

16. Compileaza si afiseaza "1\n".

17. Sintaxa:
```cpp
class C {
    int a, b;
public:
    C(int a, int b) : a(a), b(b) {}
    C(C ob) { this->a = ob.a; this->b = ob.b; }
    ~C() {}
};
```

18. Compileaza si afiseaza "instantieri C: 23 val elem: 33".
