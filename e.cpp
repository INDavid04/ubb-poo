#include <iostream>
using namespace std;
class A {
    static int x;
    // int x; 

public:
    A(int i = 0) { x = i; }
    int get_x() { return x; }
    int& set_x(int i) { x = i; }
    // int& set_x(int i) { x = i; return x; }
    A operator=(A a1)
    {
        set_x(a1.get_x());
        return a1;
    }
};

// int A::x = 0;

int main()
{
    A a(212), b; /// a.x = 212, b.x = 0. x e static. prin urmare, a.x = b.x = 0
    cout << (b = a).get_x();
    return 0;
}