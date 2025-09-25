/// 2025-09-25-1501-1555

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

/// RASPUNS: Trebuie supraincarcati urmatorii operatori: =, *, +, /

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

/// II: Dati cat mai multe variante de a se modifica starea (variabilele de instanta) unui obiect constant care apeleaza o functie constanta.

/// III: Cum functioneaza operatorul de atribuire implicit (dat de compilator), al unei clase compuse
// (cu date dintr-o clasa de baza),si cum trebuie scris de programator, operatorul de atribuire pentru
// aceeasi clasa compusa? Sintaxa.

/// IV: Descrieti specializarea explicita pentru sabloane (template-uri) de clase.
// Sintaxa, proprietati, observatii.

/// V: Descrieti cum se poate re-arunca o exceptie: sintaxa, proprietati, restrictii, utilizare.

/// VI: Sa se scrie cod pentru urmatoarea situatie:
// sa se construiasca o clasa CLS care sa aibe ca date de instanta cel putin doi intregi unul constant c si unul
// normal i.
// se citeste n de la tastatura (va fi intotdeuna mai mare decat 10)
// sa se instantieze n obiecte din aceasta clasa CLS cu restrictiile urmatoare:
// 1. primele 3 obiecte vor avea initializate c si i cu c=2 si i=3
// 2. obiectele de la 5 la 6 vor avea c si i la valoarea 1
// 3 obiectele de la 7 la n vor avea c=numarul obiectului respectiv, i va fi n-c, adica al optulea obiect va avea
// c=8, al noualea obiect va avea c=9, etc.
// Sa se descrie notiunea de POO care va ajuta sa rezolvati restrictiile 1,2,3
