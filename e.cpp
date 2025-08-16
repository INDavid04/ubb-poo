#include <iostream>

using namespace std;

int main() {
    int a = 1, b = 2;
    const int * const p = &a;
    *p = 3;

    return 0;
}