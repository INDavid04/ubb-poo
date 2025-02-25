#include <iostream>
using namespace std;

int main() {
    int x = 32;
    int *p = &x; // `int *p = x;` Eroare la compilare deoarece x este o valoare nu o adresa de memorie.
    
    cout << "Adresa lui x este: " << p << ' ' << &x << endl;
    cout << "Valoarea lui x este: " << *p << ' ' << x << endl;
    cout << "Adresa lui p este: " << &p << endl;
    cout << "Ce se intampla aici?: " << &*p << endl; // Dupa cum observati aici se ia adresa lui x de ce? pentru ca *p indica catre valoarea lui x si vreau sa aflu adresa de memorie a lui x aplic &.

    int *q = new int(72);
    *q = 32;

    cout << "Adresa lui q este: " << &q << endl;
    cout << "Adresa variabilei \"anonime\" este: " << q << endl;
    cout << "Valoarea variabilei \"anonime\" catre care pointeaza q este: " << *q << endl;
    cout << "Adresa variabilei \"anonime\" este: " << &*q << endl;

    cout << "q: " << q << endl;
    cout << "&q: " << &q << endl;
    cout << "*q: " << *q << endl;

    if (q != nullptr) {
        delete q;
    }

    cout << "q: " << q << endl;
    cout << "&q: " << &q << endl;
    cout << "*q: " << *q << endl;

    int *v = new int[16];
    *v = 45;

    cout << "Prima valoare din vectorul catre care pointeaza v: " << v[0] << ", dar a doua?: " << v[1] << endl;
    cout << "Adresa de memroie a primului element din sir: " << v << endl;
    cout << "Adresa de memorie a lui v: " << &v << endl;
    cout << "Adresa de memorie a primelor trei elemente: " << &v[0] << ' ' << &v[1] << ' ' << &v[2] << endl;

    *(v + 1) = 32; // sau v[1] = 32
    cout << v[1] << " = " << *(v + 1) << endl;
    
    int &firstElement = v[1];
    cout << "v[1]: " << v[1] << endl;
    cout << "&firstElement: " << &firstElement << endl;
    cout << "*&firstElement: " << *&firstElement << endl;

    if (v != nullptr) { // Decomentati if-ul asta pentru a vedea memory leakul
        delete v;

        cout << "Memory leak de ce?: " << firstElement << ' ' << &firstElement << endl; // Programul se termina cu return 134 (exit code 134) chiar daca spatiul nu a fost dezalocat el este stricat de delete v;
    }

    if (v != nullptr) { // Aceasta este varianta corecta de a sterge un vector
        delete[] v;

        cout << "What happens?: " << firstElement << ' ' << &firstElement << endl;
    }

    return 0;
}
