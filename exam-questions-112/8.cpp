#include <iostream.h>
class B {
protected:
    int x;

public:
    B(int i = 28) { x = i; }
    virtual B f(B ob) { return x + ob.x + 1; }
    void afisare() { cout << x; }
};
class D : public B {
public:
    D(int i = -32)
        : B(i)
    {
    }
    B f(B ob) { return x + ob.x - 1; }
};
int main()
{
    B *p1 = new D, *p2 = new B, *p3 = new B(p1->f(*p2));
    p3->afisare();
    return 0;
}

/// B *p1 = new D; /// apelam B(-32) => p1->x = -32
/// B *p2 = new B; /// p2->x = 28
/// B *p3 = new B(p1->f(*p2)); /// apelam B(-32 + 28 - 1) adica B(-5) => p3->x = -5
/// p3->afisare();