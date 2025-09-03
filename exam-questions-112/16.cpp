#include <iostream>
using namespace std;
class A {
protected:
    int x;

public:
    A(int i = 14) { x = i; }
};
class B : A {
public:
    B()
        : A(2)
    {
    }
    B(B& b) { x = b.x - 14; }
    void afisare() { cout << x; }
};
int main()
{
    B b1, b2(b1); /// b1.x = 2; b2.x = -12
    b2.afisare(); /// -12
    return 0;
}