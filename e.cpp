/// SOURCE: FMI >>> 13. POO >>> Notite >>> Cursuri

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
/// UP: Feel free to comment/uncomment following functions and classes ///
//////////////////////////////////////////////////////////////////////

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

    /// DOWN: The end of the file.

    return 0;
}
