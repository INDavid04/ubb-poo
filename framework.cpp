#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class IOInterface {
public:
    virtual void read(istream&) = 0;
    virtual void write(ostream&) = 0;
    virtual ~IOInterface() = default;
};

class IDClass {
protected:
    const int id;
    static int generatorId;
    static list<IDClass*> children;
private:
    static IDClass* findById(const int&);
public:
    IDClass();
    [[nodiscard]] int getId() const;
    static list<IDClass*> getChildren();
    static IDClass* findByIdAndReturnObject(istream&);
    virtual ~IDClass();
};
int IDClass::generatorId = 1000;
list<IDClass*> IDClass::children = list<IDClass*>();
IDClass::IDClass() : id(generatorId++) {
    children.push_back(this);
}
IDClass::~IDClass() {
    children.remove(this);
}
list<IDClass*> IDClass::getChildren() {
    return children;
}
int IDClass::getId() const {
    return id;
}
IDClass* IDClass::findById(const int& id) {
    const auto& object = find_if(children.begin(), children.end(), [id](const IDClass* current) -> bool {
        return current->id == id;
    });

    if (object == children.end()) {
        throw runtime_error("No element was found for this id");
    }

    return *object;
}
IDClass* IDClass::findByIdAndReturnObject(istream& in) {
    int id;

    cout << "Read a number to find the object you want: " << endl;
    in >> id;

    try {
        return findById(id);
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return nullptr;
}

class Student : public virtual IOInterface, public virtual IDClass {
string name;
public:
    explicit Student(string name = "N/A") : name(move(name)) {}
    ~Student() override = default;
    void read(istream& in) override {
        this->operator>>(in);
    }
    void write(ostream& out) override {
        this->operator<<(out);
    }
    Student& operator=(const Student&);
    istream& operator>>(istream& in);
    ostream& operator<<(ostream& out) const;
};
Student& Student::operator=(const Student& student) {
    if (this != &student) {
       this->name = student.name;
    }
    return *this;
}
istream& Student::operator>>(istream& in) {
    cout << "Please provide the student\'s name: " << endl;
    in >> name;

    return in;
}
ostream& Student::operator<<(ostream& out) const {
    out << "Student details for [ID: " << this->getId() << ", Name: " << this->name << "]" << endl;
    return out;
}

int main() {
    // CREATE
    Student *s1 = new Student();
    cout << s1 << endl;
    s1->read(cin);

    // READ
    IDClass *idClass = IDClass::findByIdAndReturnObject(cin);
    if (idClass != nullptr) {
        Student *student = dynamic_cast<Student*>(idClass);

        student->write(cout);
    }

    // UPDATE
    idClass = IDClass::findByIdAndReturnObject(cin);
    if (idClass != nullptr) {
        Student *student = dynamic_cast<Student*>(idClass);

        Student studentAux;
        studentAux.read(cin);

        *student = studentAux;
    }

    // SHOW ALL
    for (const auto& child : IDClass::getChildren()) {
        Student *student = dynamic_cast<Student*>(child);
        student->write(cout);
    }

    // DELETE
    idClass = IDClass::findByIdAndReturnObject(cin);
    if (idClass != nullptr) {
        delete idClass;
    }
    return 0;
}
