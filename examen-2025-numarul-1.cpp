// ========== EXERCITIUL I ==========
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

// ========== EXERCITIUL III ==========
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

// ========== EXERCITIUL IV ==========
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

// ========== EXERCITIUL VI ==========
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

// ========== EXERCITIUL VII ==========
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

// ========== EXERCITIUL IX ==========
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

// ========== EXERCITIUL X ==========
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

// ========== EXERCITIUL XII ==========
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

// ========== EXERCITIUL XIII ==========
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

// ========== EXERCITIUL XV ==========
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

// ========== EXERCITIUL XVI ==========
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

// ========== EXERCITIUL XVIII ==========
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
    