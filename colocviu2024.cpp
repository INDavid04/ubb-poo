#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Object;

static int userPoints = 50000;
list<Object*> objects;
static void cleanUp();

class Object {
protected:
    static int idGenerator;
    const int id;
public:
    virtual int computeUpgradeCost() const = 0;
    virtual void upgrade() = 0;
    Object() : id(idGenerator++) {}
    virtual ~Object() = default;
    int getId() const {
        return id;
    }
    virtual void write() const {
        cout << "ID: " << id << endl;
    }
};
int Object::idGenerator = 1000;

static void cleanUp() {
    for (auto object : objects) {
        if (object != nullptr) {
            delete object;
        }
    }

    objects.clear();
}

class Zid : public Object {
    static int createCost;
    double l, h, w;
public:
    Zid() : l(1.0), h(2.0), w(0.5) {
    }
    static int getCreateCost() {
        return createCost;
    }
    int computeUpgradeCost() const override {
        return (int)(100 * l * h * w);
    }
    void upgrade() override {
        l = l + 1.0;
        h = h + 1.0;
        w = w + 1.0;
    }
    void write() const override {
        Object::write();
        cout << "H, L, W = " << h << " " << l << " " << w << endl;
        cout << "Cost upgrade: " << this->computeUpgradeCost() << endl;
    }
};
int Zid::createCost = 300;

class Turn : public Object {
    static int createCost;
    int radius;
public:
    Turn() : radius(1000) {
    }
    static int getCreateCost() {
        return createCost;
    }
    int computeUpgradeCost() const override {
        return (int)(500 * radius);
    }
    void upgrade() override {
        radius += 500;
    }
    void write() const override {
        Object::write();
        cout << "Radius = " << radius << endl;
        cout << "Cost upgrade: " << this->computeUpgradeCost() << endl;
    }
};
int Turn::createCost = 500;

class Robot : public Object {
protected:
    double damage, hp;
    long long level;
public:
    Robot(double damage = 0.0, double hp = 100.0, long long level = 1) : damage(damage), hp(hp), level(level) {}

    void write() const override {
        Object::write();
        cout << "Damage = " << damage << endl;
        cout << "Level = " << level << endl;
        cout << "HP = " << hp << endl;
    }
};

class RobotAerian : public Robot {
    static int createCost;
    int aut;
public:
    RobotAerian() : Robot(100.0, 100.0, 1), aut(10) {}
    static int getCreateCost() {
        return createCost;
    }
    int computeUpgradeCost() const override {
        return (int)(50 * aut);
    }
    void upgrade() override {
        aut += 1;
        level += 1;
        damage = damage + 25.0;
    }
    void write() const override {
        ((Robot*)this)->write();
        cout << "Flight Autonomy = " << aut << endl;
        cout << "Cost upgrade: " << this->computeUpgradeCost() << endl;
    }
};
int RobotAerian::createCost = 100;

class RobotTerestru : public Robot {
    static int createCost;
    int bullets;
    bool hasShield;
public:
    RobotTerestru() : Robot(100.0, 100.0, 1), bullets(500), hasShield(false) {}
    static int getCreateCost() {
        return createCost;
    }
    int computeUpgradeCost() const override {
        return (int)(10 * bullets);
    }
    void upgrade() override {
        bullets += 100;
        level += 1;
        damage = damage + 50.0;

        if (level == 5) {
            hasShield = true;
            hp = hp + 50.0;
        }
    }
    void write() const override {
        ((Robot*)this)->write();
        cout << "Bullets = " << bullets << endl;
        cout << "Has shield = " << (hasShield ? "yes" : "no") << endl;
        cout << "Cost upgrade: " << this->computeUpgradeCost() << endl;
    }
};
int RobotTerestru::createCost = 50;

int main() {
    do {
        int option;

        cout << "1. Adauga un element" << endl;
        cout << "2. Actualizeaza un element" << endl;
        cout << "3. Afiseaza elementele din inventar crescator dupa costul de upgrade" << endl;
        cout << "4. Afiseaza elementele din inventar de tip robot" << endl;
        cout << "5. Vinde (+500 puncte)" << endl;
        cout << "Introdu optiunea ta (1-5) sau altceva pentru a iesi din program: ";

        cin >> option;
        if (cin.fail()) {
            cin.clear();            
            cin.ignore(1000, '\n');  
            cout << "Optiune invalida! Introdu un numar intre 1 si 5." << endl;
            continue;
        }
        try {
            switch (option) {
                case 1: {
                    string selection;
                    cout << "Selecteaza ce doresti sa inserezi (zid / turn / robot_aerian / robot_terestru): ";
                    cin >> selection;

                    if (selection != "zid" && selection != "turn" && selection != "robot_aerian" && selection != "robot_terestru" ) {
                        throw runtime_error("Eroare: Selectia este invalida te rog sa selectezi intre optiunile disponibile (zid / turn / robot_aerian / robot_terestru).");
                    }

                    if (selection == "zid") {
                        Zid *zid = new Zid();
                        objects.push_back(zid);

                        userPoints -= Zid::getCreateCost();
                        cout << "Ai introdus un zid cu succes: " << userPoints << " puncte ramase." << endl;
                    } else if (selection == "turn") {
                        Turn *turn = new Turn();
                        objects.push_back(turn);

                        userPoints -= Turn::getCreateCost();
                        cout << "Ai introdus un turn cu succes: " << userPoints << " puncte ramase." << endl;
                    } else if (selection == "robot_aerian") {
                        RobotAerian *robot_aerian = new RobotAerian();
                        objects.push_back(robot_aerian);

                        userPoints -= RobotAerian::getCreateCost();
                        cout << "Ai introdus un robot aerian cu succes: " << userPoints << " puncte ramase." << endl;
                    } else if (selection == "robot_terestru") {
                        RobotTerestru *robot_terestru = new RobotTerestru();
                        objects.push_back(robot_terestru);

                        userPoints -= RobotTerestru::getCreateCost();
                        cout << "Ai introdus un robot terestru cu succes: " << userPoints << " puncte ramase." << endl;
                    }
                    break;
                }
                case 2: {
                    int selectedId;
                    cout << "Introdu id-ul elementului caruia vrei sa ii faci upgrade: ";
                    cin >> selectedId;

                    auto it = find_if(objects.begin(), objects.end(), [selectedId](Object *object) -> bool {
                        return object->getId() == selectedId;
                    });
                    if (it == objects.end()) {
                        throw runtime_error("Nu exista un obiect cu id-ul mentionat.");
                    }

                    Object *current_object = *it;
                    if (userPoints < current_object->computeUpgradeCost()) {
                        throw runtime_error("Nu ai suficiente puncte pentru acest upgrade.");
                    }
                    userPoints -= current_object->computeUpgradeCost();
                    current_object->upgrade();

                    cout << "Ai facut cu succes un upgrade" << endl;
                    break;
                }
                case 3: {
                    if (objects.empty()) {
                        cout << "Inventarul este gol\n";
                    } else {
                        objects.sort([](Object *a, Object *b) -> bool {
                            return a->computeUpgradeCost() < b->computeUpgradeCost();
                        });
                        for (auto object: objects) {
                            object->write();
                        }
                    }
                    break;
                }
                case 4: {
                    for (auto object: objects) {
                        Robot *robot_current_object = dynamic_cast<Robot *>(object);
                        if (robot_current_object != nullptr) {
                            robot_current_object->write();
                        }
                    }
                    break;
                }
                case 5: {
                    int selectedId;
                    cout << "Introdu id-ul elementului pe care vrei sa il vinzi: ";
                    cin >> selectedId;

                    auto it = find_if(objects.begin(), objects.end(), [selectedId](Object *object) -> bool {
                        return object->getId() == selectedId;
                    });
                    if (it == objects.end()) {
                        throw runtime_error("Nu exista un obiect cu id-ul mentionat.");
                    }

                    Object *current_object = *it;
                    objects.remove(current_object);
                    if (current_object != nullptr) {
                        delete current_object;
                    }

                    userPoints += 500;
                    cout << "Ai vandut cu succes obiectul cu id-ul selectat " << userPoints << "." << endl;
                    break;
                }
                default: {
                    if (option < 1 || option > 5) {
                        cleanUp();
                        cout << "Ai selectat iesirea din program." << endl;
                        return 0;
                    }
                }
            }
        } catch (exception& error) {
            cout << error.what() << endl;
            continue;
        }
    } while (true);
}
