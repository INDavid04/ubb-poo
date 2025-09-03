#include <iostream.h>
class problema {
    int i;

public:
    problema(int j = 5) { i = j; }
    void schimba() { i++; }
    void afiseaza() { cout << "starea curenta " << i << "\n"; }
};
problema mister1() { return problema(6); }
void mister2(problema& o)
{
    o.afiseaza(); /// out "starea curenta 6\n"
    o.schimba(); /// o.i = 7
    o.afiseaza(); /// out << "starea curenta 7\n"
}
int main()
{
    mister2(mister1());

    /// mister2(mister1()) = mister2(problema(6)) /// o.i = 6

    return 0;
}