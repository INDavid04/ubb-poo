#include <iostream>
#include <string>

using namespace std;

// 🚀 Now, try defining your own class for a Person with attributes like name and age! 🎉

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age) { 
        this->name = name;
        this->age = age;
    }
    void get() const {
        cout << "Hello, " << name << "! You are " << age << " years old! God bless you!\n";
    }
};

int main() {
    Person p1("Dina", 24);
    p1.get();

    return 0;
}