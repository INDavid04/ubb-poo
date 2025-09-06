#include <iostream>

using namespace std;

class Baza { 
public: 
    Baza() { 
        cout << "CoB\n"; 
    } 
};

class Derivata1 : public Baza {
public: 
    Derivata1() { 
        cout << "CoD1\n"; 
    }
    ~Derivata1() { 
        cout << "DD1\n"; 
    } 
};

class Derivata2 : public Baza {
public: 
    Derivata2() { 
        cout << "CoD2\n"; 
    }
    virtual ~Derivata2() { 
        cout << "DD2\n"; 
    } 
};

class Derivata3 : virtual public Baza {
public: 
    Derivata3() { 
        cout << "CoD3\n"; 
    } 
};

class Derivata4 : public Baza { 
public: 
    Derivata4() { 
        cout << "DD4\n"; 
    } 
};

class Derivata5 : public Derivata1, Derivata2, protected Derivata3, public Derivata4 { 
public: 
    Derivata5() { 
        cout << "CoD5\n"; 
    } 
};

int main() { 
    Derivata5 ob; 

    return 0;
}