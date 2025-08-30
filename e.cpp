/// SOURCE: FMI >>> 13. POO >>> Notite >>> Cursuri

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
/// UP: Feel free to comment/uncomment following functions and classes ///
//////////////////////////////////////////////////////////////////////

// class cls {
// public:
//     cls() { cout << "Inside constructor 1" << endl; }
//     ~cls(){ cout << "Inside destructor 1" << endl; }
// };
// class clss {
//     cls xx;   // compoziție
// public:
//     clss() { cout << "Inside constructor 2" << endl; }
//     ~clss() { cout << "Inside destructor 2" << endl; }
// };
// class clss2 {
//     clss xx;  // compoziție
//     cls xxx;  // compoziție
// public:
//     clss2() { cout << "Inside constructor 3" << endl; }
//     ~clss2() { cout << "Inside destructor 3" << endl; }
// };

// class Afixed {
//     int *v;
// public:
//     /// Constructor
//     Afixed() { v = new int[10]; cout << "C"; } 
//     /// Constructor de copiere
//     Afixed(const Afixed &other) { 
//         v = new int[10]; 
//         for(int i = 0; i < 10; i++) { 
//             v[i] = other.v[i]; 
//         } 
//         cout << "CC";
//     }
//     /// Operator de atribuire
//     Afixed &operator=(const Afixed &other) {
//         if (this != &other) {
//             delete[] v;
//             v = new int[10];
//             for (int i = 0; i < 10; i++) {
//                 v[i] = other.v[i];
//             }
//         }
//         cout << "=";
//         return *this;
//     }
//     /// Destructor
//     ~Afixed() { delete[] v; cout << "D"; }
//     void afis() const { cout << v[3]; }
// };
// void afisare(Afixed ob) { ob.afis(); }

// class A {
//     int *v;
// public:
//     A() { v = new int[10]; cout << "C"; }
//     ~A() { delete[] v; cout << "D"; }
//     void afis() const { cout << v[3]; }
// };
// void afisare(A ob) { ob.afis(); }

// class A { int x; float y; string z; };

// class ImplicitInline {
//     int a, b;
// public:
//     /// Automatica inline
//     void init(int i, int j) {
//         a = i;
//         b = j;
//     }
    
//     void show() const {
//         cout << a << " " << b << "\n";
//     }
// };

// class ExplicitInline {
//     int a, b;
// public:
//     void init(int i, int j);
//     void show() const;
// };

// inline void ExplicitInline::init(int i, int j) {
//     a = i;
//     b = j;
// }

// inline void ExplicitInline::show() const {
//     cout << a << " " << b << "\n";
// }

// inline int max(int a, int b) { 
//     return (a > b) ? a : b;
// }

// class X {
//     int x;
// public:
//     friend class Y;
// };
// class Y {
// public:
//     void set_x(int val, X &ob) { ob.x = val; }
//     int get_x(X ob) const { return ob.x; }
// };

// class myclass {
//     int a, b;
// public:
//     friend int sum(myclass x); /// poate accesa direct a si b private
//     void setAB(int x, int y) { a = x; b = y; }
// };
// int sum(myclass x) { return x.a + x.b; }

// class Animal { public: virtual void sound() { cout << "Sound\n"; } };

// class Cat : public Animal { public: void sound() override { cout << "Miau!\n"; } };

// class Dog : public Animal { public: void sound() override { cout << "Woof!\n"; } };

// int f() { return 10; }

int main() {
    /**************************************************************************************************/

    /////////////////////////////////////////////////////////////////
    /// 1.4.1 Completari aduse de limbajul C++ fata de limbajul C ///
    /////////////////////////////////////////////////////////////////

    /**************************************************************************************************/

    // int x, y, z;
    // cin >> x; /// operator >> (cin, x);
    // cin >> y >> z; /// operator >> (operator >> (cin, y), z);
    
    /// Analog pentru cout (<<):

    // foperator(cout, x);

    /**************************************************************************************************/

    /// In C89 primesti eroare daca declari o variabila dupa o instructiune, timp in care in C++ o poti delcara oriune in cod, adica in C89 primeam eroare la instructiunea de mai jos

    // int f() { int i; i = 1; int j; } /// in afara lui main

    /**************************************************************************************************/

    /// * la adresa si & adresa lui

    // int i = 1;
    // int *j;
    // j = &i; /// citim j ia valoarea adresei lui i
    // *j = 9; /// citim la adresa j punem valoarea 9

    /**************************************************************************************************/

    /// In C avem conversie automata

    // float x = 12.34;
    // int *p = &x;
    
    /// In C++ trebuie facuta conversie cu schimbare de tip

    // float x = 12.34;
    // int *p = (int*) &x;

    /**************************************************************************************************/
    
    /// Pointeri si const in C/C++

    // const int * p; /// valoare constanta
    // int const * p; /// valoare constanta
    // int * const p; /// pointer constant
    // const int * const p; /// valoare constanta si pointer constant
    // int const * const p; /// valoare constanta si pointer constant
          
    /**************************************************************************************************/

    // int a = 1, b = 2;
    
    /// Valoare constanta

    // const int* p = &a; /// echivalent cu `int const* v = &a;`
    // p = &b; /// ok
    // *p = 3; /// error: assignment of read-only location '* p'
    
    /// Pointer constant

    // int * const q = &a;
    // q = &b; /// error: assignment of read-only variable 'q'
    // *q = 3; /// ok
    
    /// Valoare constanta si pointer constant

    // const int * const r = &a; /// echivalent cu `int const * const r = &a;`
    // r = &b; /// error: assignment of read-only variable 'r'
    // *r = 3; /// error: assignment of read-only location '*(const int*)r'
        
    /**************************************************************************************************/

    /// Parametrii formali sunt creati la intrarea intr-o functie si distrusi la retur
    
    /**************************************************************************************************/

    ///////////////////////////////////////////////////////////
    //// 1.4.2 Principiile programarii orientate pe obiecte ///
    ///////////////////////////////////////////////////////////
    
    /**************************************************************************************************/

    /// For fun: un programator rezolva problema; un informatician rezolva problema bine
    /// Un obiect este o instanta a unei clase.
    /// O clasa are:
    ///     - O anumita stare reprezentata prin valoare
    ///     - Un anumit comportament reprezentat prin functii
    ///     - Tabel pentru accesul variabilelor definite intr-o clasa
    ///         ---------------------------------------------------------------
    ///         |                | private       | protected     | public     |
    ///         | -------------- | ------------- | ------------- | ---------- |
    ///         | Aceeasi clasa  | avem acces    | avem acces    | avem acces |
    ///         | Clase derivate | nu avem acces | avem acces    | avem acces |
    ///         | Alte clase     | nu avem acces | nu avem acces | avem acces |
    ///         ---------------------------------------------------------------

    /**************************************************************************************************/

    /// "Functiile, cu exceptia celor de tip void, pot fi folosite ca operand in orice expresie valida."
    /// int f() { return 10; } /// in afara lui main

    // x = 5 + f(); /// functia e ca o variabila tempoara

    /// Retine: void = gol, de aceea functiile cu exeptia celor de tip void pot fi folosite ca operand in orice expresie valida.

    /**************************************************************************************************/

    /// "Polimorfismul (la executie – discutii mai ample mai tarziu) – într-o ierarhie de clase obtinuta prin mostenire: O metodă poate avea implementari diferite la nivele diferite in acea ierarhie."
    /// class Animal { virtual void sound() { cout << "Sound\n"; } }; /// out of main
    /// class Cat : public Animal { void sound() override { cout << "Miau!\n"; } }; /// out of main
    /// class Dog : public Animal { void sound() override { cout << "Woof!\n"; } }; /// out of main
    
    // Animal *a = new Cat;    a->sound(); /// Miau!
    // a = new Dog;            a->sound(); /// Woof! 
    
    /// Retine: Intr-o familie de clase, aceeasi functie poate face lucruri diferite.

    /**************************************************************************************************/

    /// int new C vs new C()
    
    // int *p1 = new int; /// nedefinit
    // int *p2 = new int(); /// 0
    // cout << *p1 << ", " << "\n";
    // cout << *p2 << ", " << "\n";

    /**************************************************************************************************/

    /// 2.1 Scurta recapitualre C++

    /**************************************************************************************************/

    /// Pointer = variabila ce retine o adresa de memorie
    ///     - Are un tip
    ///     - Sintaxa: tip *nume = &variabila;
    /// Schimbarea de tip e controlata de compilator
    /// In C++, conversiile trebuiesc facute cu schimbare de tip. In C, e by default.
    /// lista[5] <=> *lista+5

    // int a = 5;
    // int *p = &a;
    // cout << p << "\n"; /// 0x000000
    // p++;
    // cout << p << "\n"; /// 0x000004 (Explicatie: p++ <=> p += p + sizeof(int) where sizeof(int) = 4)

    // double a = 10.1, b;
    // int *p = (int*)&a;
    // b = *p;
    // cout << *p << " " << b << "\n"; /// valori random

    /**************************************************************************************************/

    /// Const aparut pentru a elimina comenzile de preprocesor #define care faceau substitutie de valoare
    ///     - Se poate aplica la pointeri, argumente de functii, parametru de intoarcere din functii, obiecte, functii membru

    // const char c = cin.get();
    // cout << c << "\n";
    // // c = 'b'; /// E.C.
    // const char c2 = c + 'a'; /// OK
    // cout << c2 << "\n";

    // int a = 5;
    // const int b = 7;
    // int *p = &a; /// OK
    // // p = &b; /// E.C
    // const int *cp = &b; /// OK
    // cout << *cp << "\n"; /// 7

    /**************************************************************************************************/

    /// Referinta = pointer implicit care actioneaza ca un alt nume al unui obiect (variabila)
    ///     - Trebuie initializata in momentul declararii
    ///     - Spre deosebire de pointeri, incrementarea unei referinte are ca efect incrementarea valorii, nu a adresei cu tipul de date
    ///     - Obs: In afara initializarii, nu puteti modifica obiectul spre care indica referinta.
    ///     - Membrii unei clase de tip referinta trebuie initializati in construcor
    ///     - Un parametru de funcție de tip referință se inițializează implicit la apel
    ///     - Referintele nule sunt interzise in C++
    ///     - Nu se poate obtine adresa unei referinte

    /// EXEMPLU: Spre deosebire de pointeri, incrementarea unei referinte are ca efect incrementarea valorii, nu a adresei cu tipul de date

    // int a = 4;
    // int &r = a;
    // r++;
    // cout << a << " " << r << "\n"; /// 5 5

    /// EXEMPLU: In afara initializarii, nu puteti modifica obiectul spre care indica referinta

    // int a = 5, b = 7;
    // int &ref = a; /// ref = alias pentru a
    // ref = b; /// atribuie valoarea lui b in ref, nu muta referinta
    // cout << ref << "\n"; /// 7
    // ref++;
    // cout << ref << "\n"; /// 8
    // cout << b << "\n"; /// 7
    // cout << a << "\n"; /// 8

    /// EXEMPLU: Nu se poate obtine adresa unei referinte

    // int a = 5;
    // int &ref = a;
    // cout << &ref << " " << &a << "\n"; /// egale

    /// EXEMPLU: Un parametru de funcție de tip referință se inițializează implicit la apel

    // void f(int &x) { x += 10; } /// in afara lui main
    // int a;
    // f(a); /// x se leaga de a, automat


    /**************************************************************************************************/
    
    /// Transmiterea parametrilor:
    ///     - Prin valoare: copiaza valoarea intr-un parametru formal => modificarile parametrului nu au efect asupra obiectului
    ///     - Prin referinta: copiaza adreasa unui argument intr-un parametru => modificarile parametrului au efect asupra obiectului

    /**************************************************************************************************/
    
    /// 2.2 Principiile programarii orientate pe obiecte ///

    /**************************************************************************************************/

    /// Clasa: date membre + metode
    /// Obiectele instantiaza clase
    /// Agregarea (ierarhia de obiecte) = compunerea unui obiect din mai multe obiecte (has a)
    /// Mostenirea (ierarhia de clase) = relatia intre clase in care o clasa mosteneste structura si comportarea definita in una sau mai multe (mostenire multipla) clase (is a / is like a)

    /// EXEMPLU: Agregare

    // class Profesor {
    //     string nume;
    // };
    // class Curs {
    //     string denumire;
    //     Profesor p;
    // }

    /// EXEMPLU: Mostenire

    // class Curs {
    //     string denumire;
    // };
    // class CursPOO : public Curs {
    //     bool util;
    // };

    /**************************************************************************************************/

    /// Un membru nestatic al clasei nu poate avea initializare

    // /// E.C. in C++98, OK in C++11
    // class C {
    //     int x = 10; 
    // };

    // /// Solutia
    // class C {
    //     int x;
    // public:
    //     C() : x(10) {}
    // }

    /**************************************************************************************************/

    /// In clase, fara: auto, exetrn, register

    // class C {
    //     auto int x; /// nu
    //     register int y; /// nu
    // }

    /**************************************************************************************************/

    ////////////////////////////////
    /// 3. Union, friend, inline ///
    ////////////////////////////////

    /**************************************************************************************************/

    /// Union
    ///     - Nu poate mosteni
    ///     - Nu se poate mosteni din union
    ///     - Nu poate avea functii virtuale
    ///     - Nu avem variabile de instanta statice
    ///     - Nu avem referinte in union
    ///     - Nu avem obiecte care fac overload pe =
    ///     - Obiecte cu constructori/destructori definiti nu pot fi membri in union

    /// Union anonime
    ///     - Nu au nume pentru tip
    ///     - Nu se pot declara obiecte de tipul respectiv
    ///     - Folosite pentru a spune compilatorului cum sa aloce/proceseze variabilele respective
    ///     - Sunt accesibile ca si cum ar fi declarate in blocul respectiv
    ///     - Nu pot avea functii
    ///     - Nu pot avea private/protected
    ///     - Union anonime globale trebuiesc precizate ca statice

    /// EXEMPLU: Union

    /// Scriem si union tot in main

    // union {
    //     long l;
    //     double d;
    // };
    // l = 100000;
    // cout << l << " "; /// 100000
    // d = 23.432; 
    // cout << d << "\n"; /// 23.432
    // cout << l << " " << d << "\n"; /// random 23.432 (explicatie: l si d impart aceeasi zona de memorie)

    /**************************************************************************************************/

    /// Friend este folosit pentru:
    ///     - Accesarea campurilor protected, private din alta clasa
    ///     - Ovorload-area operatorilor pentru unele functii de I/O

    /// EXEMPLU: Friend

    /// In afara lui main:

    // class myclass {
    //     int a, b;
    // public:
    //     friend int sum(myclass x); /// poate accesa direct a si b private
    //     void setAB(int x, int y) { a = x; b = y; }
    // }
    // int sum(myclass x) { return x.a + x.b; }

    /// In main:

    // myclass n;
    // n.setAB(1, 4);
    // cout << sum(n) << "\n"; /// 5

    /// EXEMPLU: Declararea unei clase Y ca prieten al unei clase X, are ca efect ca toate functiile membre ale clasei Y au acces la membrii privati ai clasei X
    
    /// In afara lui main:

    // class X {
    //     int x;
    // public:
    //     friend class Y;
    // };
    // class Y {
    // public:
    //     void set_x(int val, X &ob) { ob.x = val; }
    //     int get_x(C1 ob) const { return ob.x; }
    // };

    /// In main:

    // X x;
    // Y y;
    // y.set_x(10, x);
    // cout << y.get_x(x) << "\n"; /// 10

    /**************************************************************************************************/

    /// Functii inline:
    ///     - Pentru executie rapida
    ///     - Sugestie cerere pentru compilator
    ///     - Pentru functii foarte mici
    ///     - Pot fi si membrii ai unei clase
    ///     - Foarte comune in clase
    ///     - Doua tipuri: explicit (inline) si implicit

    /// EXEMPLU: Explicit inline

    /// In afara lui main:

    // inline int max(int a, int b) { 
    //     return (a > b) ? a : b;
    // }

    /// In main:

    // cout << max(10, 20) << " " << max (99, 88) << "\n"; /// 20 99
    // cout << ((10 > 20) ? 10 : 20) << " " << ((99 > 88) ? 99 : 88) << "\n"; /// 20 99 (nota: parantezele sunt importante aici)

    /// EXEMPLU: Explicit inline in clase
    
    /// In afara lui main:

    // class ExplicitInline {
    //     int a, b;
    // public:
    //     void init(int i, int j);
    //     void show() const;
    // };

    // inline void ExplicitInline::init(int i, int j) {
    //     a = i;
    //     b = j;
    // }

    // inline void ExplicitInline::show() {
    //     cout << a << " " << b << "\n";
    // }

    /// In main:

    // ExplicitInline e;
    // e.init(10, 11);
    // e.show(); /// 10 11

    /// EXEMPLU: Implicit inline in clase

    /// In afara lui main:

    // class ImplicitInline {
    //     int a, b;
    // public:
    //     /// Automatica inline
    //     void init(int i, int j) {
    //         a = i;
    //         b = j;
    //     }
        
    //     void show() const {
    //         cout << a << " " << b << "\n";
    //     }
    // };

    /// In main:

    // ImplicitInline i;
    // i.init(10, 11);
    // i.show(); /// 10 11

    /**************************************************************************************************/

    /// Constructori/Destructori
    ///     - Orice clasa are by default: 
    ///         - Un constructor de initializare
    ///         - Un constructor de copiere
    ///         - Un destructor
    ///         - Un operator de atribuire
    ///     - Constructorii de copiere trebuiesc redefiniti la date alocate dinamic

    /// In afara lui main:

    // class A { int x; float y; string z; };

    /// In main:

    // A a; /// apel constructor de initializare fara parametrii
    // A b = a; /// apel constructor de copiere
    // A e(a); /// apel constructor de copiere
    // A c; /// apel constructor de initializare
    // c = a; /// operatorul de atribuire

    /// EXEMPLU: Necesitate rescriere constructori (Constructorii de copiere trebuiesc redefiniti la date alocate dinamic)

    /// In afara lui main:
    
    // class A {
    //     int *v;
    // public:
    //     A() { v = new int[10]; cout << "C"; }
    //     ~A() { delete[] v; cout << "D"; }
    //     void afis() const { cout << v[3]; }
    // };

    // void afisare(A ob) { ob.afis(); }

    /// In main:

    // A o1; /// CC0DD nope, da "Aborted (core dumped)"
    // afisare(o1);
    // o1.afis();

    /// Explicatie: Fara copy-constructor definit de noi (deoarece avem v alocat dinamic) o1 si ob pointeaza catre acelasi int[10]

    /// Solutie: Scriem constructorul de copiere (bonus: si cel ce atribuire)

    // class Afixed {
    //     int *v;
    // public:
    //     /// Constructor
    //     A() { v = new int[10]; cout << "C"; }
        
    //     /// Constructor de copiere
    //     A(const A &other) { 
    //         v = new int[10]; 
    //         for(int i = 0; i < 10; i++) { 
    //             v[i] = other.v[i]; 
    //         } 
    //         cout << "CC";
    //     }

    //     /// Operator de atribuire
    //     A &operator=(const A &other) {
    //         if (this != other) {
    //             delete[] v;
    //             v = new int[10];
    //             for (int i = 0; i < 10; i++) {
    //                 v[i] = other.v[i];
    //             }
    //         }
    //         cout << "=";
    //         return *this;
    //     }

    //     /// Destructor
    //     ~A() { delete[] v; cout << "D"; }
        
    //     void afis() const { cout << v[3]; }
    // };
    // void afisare(A ob) { ob.afis(); }

    // Afixed o1; /// CC0D0D (nu: CC0DD)
    // afisare(o1);
    // o1.afis();

    /// Retine: Daca o clasa aloca dinamic memorie, atunci trebuie definit explicit:
    ///     - Destructor
    ///     - Constructor de copiere
    ///     - Operator=

    /// EXEMPLU: Constructorii urca, destructorii coboara

    /// In afara lui main:

    // class cls {
    // public:
    //     cls() { cout << "Inside constructor 1" << endl; }
    //     ~cls(){ cout << "Inside destructor 1" << endl; }
    // };

    // class clss {
    //     cls xx;   // compoziție
    // public:
    //     clss() { cout << "Inside constructor 2" << endl; }
    //     ~clss() { cout << "Inside destructor 2" << endl; }
    // };

    // class clss2 {
    //     clss xx;  // compoziție
    //     cls xxx;  // compoziție
    // public:
    //     clss2() { cout << "Inside constructor 3" << endl; }
    //     ~clss2() { cout << "Inside destructor 3" << endl; }
    // };

    // clss2 s; /// 12133121

    /// Retine:
    ///     - Constructorii merg de la membrii la clasa
    ///     - Destructorii merg invers

    /**************************************************************************************************/

    /// DOWN: The end of the file.

    return 0;
}
