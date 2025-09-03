#include <iostream>
using namespace std;
class A {
protected:
    static int x;

public:
    A(int i = 0) { x = i; }
    virtual A schimb() { return (7 - x); }
};
class B : public A {
public:
    B(int i = 0) { x = i; }
    void afisare() { cout << x; }
};
int A::x = 5;
int main()
{
    A* p1 = new B(18); /// x = 0; x = 18
    *p1 = p1->schimb(); /// apeleaza A(7-18) adica A(-11) => x = -11
    ((B*)p1)->afisare(); /// -11
    return 0;
}