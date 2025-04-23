#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    cout << &a << " " << &b << " " << &c << " " << &d << " " << &e << "\n"; /// de ce sunt pusi invers in memorie?
    int* pa = &a;
    cout << pa << " " << *pa << "\n"; /// 0x61fef8 1
    pa += 1; /// creste cu 4 ori 1 adica 1 ori spatiul alocat tipului de data in acest caz fiind vorba de int e patru
    cout << pa << " " << *pa << "\n"; /// nu 0x61fef9 ci 0x61fefc
    pa--;
    cout << pa << " " << *pa << "\n"; /// inainte pa = 0x61fefc si acum pa = 0x61fef8
    a--;
    cout << pa << " " << *pa << "\n"; /// inainte pa = 0x61fef8 si acum pa = 0x61fef8, atentie ca pa nu se modifica daca am schimbat valoarea lui a

    return 0;
}