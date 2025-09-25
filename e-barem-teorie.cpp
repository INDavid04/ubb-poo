/// 2025-09-25-1501-1738 (17 min for fifth solution)

#include <iostream>

using namespace std;

/// Barem Teorie

/////////////////////////////////////////////////////////////////
/// I: Am definita clasa Irat de numere irationale            ///
/// (cu parte reala si parte imaginara).                      ///
/// Instantiez obiectele x, y, z de acest fel.                ///
/// Ce trebuie facut ca bucata de cod urmatoare sa compileze: ///
/// y = 2 * x;                                                ///
/// x = x + 1;                                                ///
/// z = y / 2;                                                ///
/////////////////////////////////////////////////////////////////

/// RASPUNS: Trebuiesc supraincarcati urmatorii operatori: =, *, +, /

// class Irat {
// private:
//     int re, im;
// public:
//     /// Constructor fara parametrii
//     Irat() : re(0), im(0) {}

//     /// Supraincarcare operator egal
//     Irat operator=(const Irat &ob) {
//         this->re = ob.re;
//         this->im = ob.im;
//         return *this;
//     }

//     /// Supraincarcare operator inmultire
//     friend Irat operator*(const int val, const Irat &ob);

//     /// Supraincarcare operator plus
//     Irat operator+(const int val) {
//         this->re += val;
//         return *this;
//     }

//     /// Supraincarcare operator impartire
//     Irat operator/(const int val) {
//         this->re /= val;
//         this->im /= val;
//         return *this;
//     }

//     /// Supraincarcare operator afisare
//     friend ostream &operator<<(ostream &out, const Irat &ob);
// };

// /// Supraincarcare operator inmultire
// Irat operator*(const int val, const Irat &ob) {
//     Irat temp;
//     temp.re = val * ob.re;
//     temp.im = val * ob.im;
//     return temp;
// }

// /// Supraincarcare operator afisare
// ostream &operator<<(ostream &out, const Irat &ob) {
//     out << ob.re << " + " << ob.im;
//     return out; /// pentru cout << x << y << z;
// }

// int main() {
//     Irat x, y, z;
//     y = 2 * x;
//     x = x + 1;
//     z = y / 2;

//     cout << x << "\n" << y << "\n" << z << "\n";

//     return 0;
// }

///////////////////////////////////////////////////////////////
/// II: Dati cat mai multe variante de a se modifica starea ///
/// (variabilele de instanta) unui obiect constant          ///
/// care apeleaza o functie constanta.                      ///
///////////////////////////////////////////////////////////////

/// RASPUNS: Mutable, static si alocare dinamica sunt trei variante in care putem modifica starea unui obiect constant care apeleaza o functie constanta

/// Varianta 1: Mutable
// class C {
// private:
//     int var1;
//     mutable int var2;
// public:
//     C() : var2(100) {}
//     void resetVar() const {
//         // var1 = 0; /// E.C.
//         var2 = 0;
//     }
//     void afiseazaVar2() const {
//         cout << var2 << "\n";
//     }
// };
// int main() {
//     const C x;
//     x.afiseazaVar2(); /// 100
//     x.resetVar();
//     x.afiseazaVar2(); /// 0
//     return 0;
// }

/// Varianta 2: Static
// class C {
// private:
//     int var1;
//     static int var2;
// public:
//     C() {}
//     void resetVar() const {
//         // var1 = 0; /// E.C.
//         var2 = 0;
//     }
//     void afiseazaVar2() const {
//         cout << var2 << "\n";
//     }
// };
// int C::var2 = 100;
// int main() {
//     const C x;
//     x.afiseazaVar2(); /// 100
//     x.resetVar();
//     x.afiseazaVar2(); /// 0
//     return 0;
// }

/// Varianta 3: Alocare dinamica
// class C {
// private:
//     int *p;
// public:
//     C(const int val = 100) {
//         p = new int(val);
//     }
//     void reset() const {
//         *p = 0;
//     }
//     void afiseaza() const {
//         cout << *p << "\n";
//     }
//     ~C() {
//         delete p;
//     }
// };
// int main() {
//     const C x;
//     x.afiseaza(); /// 100
//     x.reset();
//     x.afiseaza(); /// 0
//     return 0;
// }

//////////////////////////////////////////////////////////////
/// III: Cum functioneaza operatorul de atribuire implicit ///
/// (dat de compilator), al unei clase compuse             ///
/// (cu date dintr-o clasa de baza),                       ///
/// si cum trebuie scris de programator,                   ///
/// operatorul de atribuire pentru                         ///
/// aceeasi clasa compusa? Sintaxa.                        ///
//////////////////////////////////////////////////////////////

/// RASPUNS: Se copiaza bit cu bit in cazul in care nu avem operatorul de atribuire supraincarcat.

/// EXEMPLU: Supraincarcarea operatorului de atribuire
// class C {
// private:
//     int re, im;
// public:
//     /// Constructor cu/fara parametrii
//     C(const int re = 0, const int im = 0) : re(re), im(im) {}
//     /// Construcor de copiere
//     C(const C &ob) {
//         this->re = ob.re;
//         this->im = ob.im;
//     }
//     /// Supraincarcare operator <<
//     friend ostream &operator<<(ostream &out, const C &ob);
//     /// Supraincarcare operator =
//     C &operator=(const C ob) {
//         this->re = ob.re;
//         this->im = ob.im;
//         return *this;
//     }
// };
// ostream &operator<<(ostream &out, const C &ob) {
//     out << ob.re << " + " << ob.im << "i\n";
//     return out; /// pentru cout << a << b;
// }
// int main() {
//     C x(3, 4), y(10, 40);
//     cout << x; /// 3 + 4i
//     x = y;
//     cout << x; /// 10 + 40i
//     return 0;
// }

///////////////////////////////////////////////
/// IV: Descrieti specializarea explicita   ///
/// pentru sabloane(template-uri) de clase. ///
/// Sintaxa, proprietati, observatii.       ///
///////////////////////////////////////////////

/// SINTAXA: Specializarea explicita pentru sabloane de clase
// template <class T>
// class MyClass {
// public:
//     void afis() {
//         cout << "Template generic\n";
//     }
// };
// template <>
// class MyClass<int> {
// public:
//     void afis() {
//         cout << "Template specializat\n";
//     }
// };
// int main() {
//     MyClass<char> a;
//     a.afis(); /// Template generic
//     MyClass<int> b;
//     b.afis(); /// Template specializat
//     // MyClass c; /// E.C. class template argument deduction failed
//     return 0;
// }

///////////////////////////////////////////////////////
/// V: Descrieti cum se poate re-arunca o exceptie. ///
/// Sintaxa, proprietati, restrictii, utilizare.    ///
///////////////////////////////////////////////////////

/// SINTAXA: Rearuncare exceptie
// try {
//     if (condition) {
//         throw exception("mesaj\n");
//     }
// } catch (const exception &e) {
//     cout << e.what();
//     throw; /// rearunca aceeasi exceptie
// }

/// PROPIETATI: Rearuncare exceptie
/// Pastreaza tipul si obiectul original al obiectului
/// Utilizata in logging si cleanup

/// RESTRICTII: Rearuncare exceptie
/// Se poate face doar dintr-un bloc catch activ
/// Intai tratatarea (logging, cleanup) si abia apoi rearuncarea

/// UITILIZARE: Rearuncare exceptie
void f() {
    try {
        throw runtime_error("Exceptie din f\n");
    } catch (const runtime_error &e) {
        cout << e.what();
        throw;
    }
}
int main() {
    try {
        f();
    } catch (const runtime_error &e) {
        cout << e.what();
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
/// VI: Sa se scrie cod pentru urmatoarea situatie:                              ///
/// Sa se construiasca o clasa CLS care                                          ///
/// sa aibe ca date de instanta cel putin doi intregi                            ///
/// unul constant c si unul normal i.                                            ///
/// Se citeste n de la tastatura (va fi intotdeuna mai mare decat 10)            ///
/// Sa se instantieze n obiecte din aceasta clasa CLS cu restrictiile urmatoare: ///
/// 1. Primele 3 obiecte vor avea initializate c si i cu c=2 si i=3              ///
/// 2. Obiectele de la 5 la 6 vor avea c si i la valoarea 1                      ///
/// 3. Obiectele de la 7 la n vor avea c=numarul obiectului respectiv,           ///
/// i va fi n-c, adica al optulea obiect va avea                                 ///
/// c=8, al noualea obiect va avea c=9, etc.                                     ///
/// Sa se descrie notiunea de POO care va ajuta sa rezolvati restrictiile 1,2,3  ///
////////////////////////////////////////////////////////////////////////////////////
