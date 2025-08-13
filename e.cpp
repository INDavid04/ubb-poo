#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int *p = &x;

    cout << p << "\n"; /// 0x61ff08
    cout << ++p << "\n"; /// 0x61ff0c
    cout << --p << "\n"; /// 0x61ff08
    cout << p + 0 << "\n"; /// 0x61ff08
    cout << p + 1 << "\n"; /// 0x61ff0c
    cout << p + 2 << "\n"; /// 0x61ff10
    cout << p + 3 << "\n"; /// 0x61ff14
    cout << p + 4 << "\n"; /// 0x61ff18
    cout << p + 5 << "\n"; /// 0x61ff1c
    cout << p + 6 << "\n"; /// 0x61ff20
    cout << p + 7 << "\n"; /// 0x61ff24
    /// Deci daca p = 0x61ff08 atunci p+7 = 0x61ff08 + (4*7)16 = 0x61ff08 + (28)16 = 0x61ff08 + (0001 1100)2 = 0x61ff08 + 0x00001c = 0x61ff08 (explicatie: luam 8 si c, 8 + 12 = 20 = (1 0100)2 = (14)16, deci scriem 4 la final si pastram 1 in minte, trecem la 0 si 1, 0 + 1 = 1 dar mai avem 1 in minte, deci avem 2 = (2)16, restul ramane la fel, ca aveam numai zero)

    int x2 = 11;
    int *p2 = &x2;
    cout << p << " - " << p2 << " = ";
    cout << p - p2 << "\n"; /// 0x61ff04 - 0x61ff00 = 1

    cout << "p == p2 is " << (p == p2) << "\n"; /// 0
    cout << "p < p2 is " << (p < p2) << "\n"; /// 0
    cout << "p > p2 is " << (p > p2) << "\n"; /// 1

    return 0;
}