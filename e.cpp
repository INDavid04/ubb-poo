/// Exercitiul 7 Varianta 2

#include <iostream>

using namespace std;

int x = 10;

void f() {
    static int x = 20;
    cout << x << " ";

    class A {
    protected:
        int x;
    public:
        A(int a = 30) {
            x = a;
            cout << A::x << " ";
        }
    };

    class B : public A {
        int x;
    public:
        B(int b = 20) {
            x = b;
            cout << x << " " << x << " ";
        }
        int afis() { return ::x + A::x; }
    } ob2;
    
    cout << x + ::x + ob2.afis();
}

int main() {
    f();

    return 0;
}