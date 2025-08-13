// Suprascrie operatorul + pentru adunarea a doua numere complexe

#include <iostream>

using namespace std;

class ComplexNumber {
private:
    int a, b; /// complex_number = a + bi
protected:
public:
    ComplexNumber(int a = 0, int b = 0) : a(a), b(b) {}
    ~ComplexNumber() {}
    int getA() const {
        return a;
    }
    int getB() const {
        return b;
    }
    ComplexNumber operator+(const ComplexNumber obj) {
        return ComplexNumber(a + obj.getA(), b + obj.getB());
    }
};

int main() {
    ComplexNumber a(2,5), b(5, 2), c;
    c = a + b;
    cout << c.getA() << " + " << c.getB() << "i\n";

    return 0;
}
