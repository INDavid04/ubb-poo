#include <iostream>
using namespace std;

class A {
    int property;
    int propertyB;
public:
    A() {
        this->property = -1;
        cout << "Constructor fara parametrii" << endl;
    }
    // se poate pune explicit in fata numelui constructorului
//    A(int property) {
//        this->property = property;
//        cout << "Constructor cu parametrii" << endl;
//    }
    A(int property, int propertyB = 50) {
        this->property = property;
        this->propertyB = propertyB;

        cout << "Constructor cu 2 parametrii" << endl;
    }
    // se poate pune explicit in fata operatorului de casting
    operator int() { // operator de casting implicit
        this->property -= 5;
        return this->property;
    }
    friend ostream& operator<<(ostream& out, const A& a) {
        out << a.property << endl;
        return out;
    }
};

int main() {
    A a(32);
    A b = 50.42; // Cast de constructor implicit (int -> A)

    int x = b; // Cast implicit (A -> int)
    cout << x << endl;

    int y = 32;
    cout << a << endl;
    cout << (int)b << endl; // Cast explicit ii specific la ce tip vreau sa fac casting
    cout << (A)y << endl; // Cast de constructor explicit (A) (A -> int)

    // Explicit si implicit sunt automat rezolvate de operatorul de casting
    // fara keyword-ul explicit in fata
    return 0;
}
