/*
Ticu Bogdan Valeriu
Grupa 144
Murgoci Alexandra
Clion 2024.1
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
using namespace std;

class InputOutput {
public:  //Interfata implementata in derivate
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) = 0;
};

//In fiecare clasa am implementat constructor, functii de citire/afisare si o functie de calculat upgradeul
class Item { //clasa Item pt a avea ce Iteme sa punem in inventar
protected:
    static int cnt;
};
class Zid : public InputOutput, public Item{
private:
    int inaltime, lungime;
    float grosime;
    const int id;
public:
    Zid();
    Zid(int inaltime,int lungime,float grosime);
    istream& citire(istream &in) override;
    ostream& afisare(ostream &out) override;
    virtual int calcUpgrade(); //functie virtuala care calculeaza upgradeul si actualizeaza campurile
};

Zid::Zid() : inaltime(0),lungime(0),grosime(0), id(cnt) {
    cnt++;
}

Zid::Zid(int inaltime, int lungime, float grosime) : inaltime(inaltime),lungime(lungime),grosime(grosime),id(cnt) {
    cnt++;
}

istream &Zid::citire(istream &in) {
    in>>inaltime>>lungime>>grosime;
    return in;
}

ostream &Zid::afisare(ostream &out) {
    out<<inaltime<<" "<<lungime<<" "<<grosime<<" ";
    return out;
}
//calculam costul de upgrade pt Zid
int Zid::calcUpgrade() {
    return 100*lungime*inaltime*grosime;
    lungime++;
    inaltime++;
    grosime++;
}

int Item::cnt=0;
//In fiecare clasa am implementat constructor, functii de citire/afisare si o functie de calculat upgradeul
class Turn : public InputOutput, public Item{
private:
    const int id;
    int putere;
public:
    Turn();
    Turn(int putere);

    istream& citire(istream &in) override;
    ostream& afisare(ostream &out) override;
    virtual int calcUpgrade();
};

Turn::Turn() : id(cnt), putere(0) {
    cnt++;
}

Turn::Turn(int putere) : id(cnt), putere(putere){
    cnt++;
}
//Calculam costul de upgrade pt turn
int Turn::calcUpgrade() {
    return 500*putere;
    putere=putere+500;
}

istream &Turn::citire(istream &in) {
    in>>putere;
    return in;
}

ostream &Turn::afisare(ostream &out) {
    out<<putere<<" ";
    return out;
}

//In fiecare clasa am implementat constructor, functii de citire/afisare si o functie de calculat upgradeul
class Robot: public InputOutput, public Item{
protected:
    const int id;
    int damage,nivelRobot,hp;
public:
    Robot();
    Robot(int damage,int nivelRobot,int hp);

    istream& citire(istream &in) override;
    ostream& afisare(ostream &out) override;
};

Robot::Robot() : id(cnt), damage(0),nivelRobot(0),hp(0){
    cnt++;
}

Robot::Robot(int damage, int nivelRobot, int hp) : id(cnt), damage(damage), nivelRobot(nivelRobot), hp(hp) {
    cnt++;
}

istream &Robot::citire(istream &in) {
    in>>damage>>nivelRobot>>hp;
    return in;
}

ostream &Robot::afisare(ostream &out) {
    out<<id<<" "<<damage<<" "<<nivelRobot<<" "<<hp<<" ";
    return out;
}
//In fiecare clasa am implementat constructor, functii de citire/afisare si o functie de calculat upgradeul
class RobotAerian : public Robot{
private:
    int autonomieZbor;

public:
    RobotAerian();
    RobotAerian(int damage, int nivelRobot, int hp, int autonomieZbor);

    istream& citire(istream &in) override;
    ostream& afisare(ostream &out) override;
    virtual int calcUpgrade();
};

RobotAerian::RobotAerian(int damage, int nivelRobot, int hp,int autonomieZbor)
        : Robot(damage, nivelRobot, hp), autonomieZbor(autonomieZbor) {

}

istream &RobotAerian::citire(istream &in) {
    Robot::citire(in);
    in>>autonomieZbor;
    return in;
}

ostream &RobotAerian::afisare(ostream &out) {
    Robot::afisare(out);
    out<<autonomieZbor<<" ";
    return out;
}
//calculam costul de upgrade pt RobotAerian
int RobotAerian::calcUpgrade() {
    return 50*autonomieZbor;
    autonomieZbor++;
    nivelRobot++;
    damage+=25;
}
//In fiecare clasa am implementat constructor, functii de citire/afisare si o functie de calculat upgradeul
class RobotTerestru: public Robot{
private:
    int nrGloante;
    int scut;
public:
    RobotTerestru();
    RobotTerestru(int damage,int nivelRobot,int hp,int nrGloante,int scut);

    virtual int calcUpgrade();
    istream& citire(istream &in) override;
    ostream& afisare(ostream &out) override;
};

RobotTerestru::RobotTerestru() : Robot(), nrGloante(0),scut(0){

}

RobotTerestru::RobotTerestru(int damage, int nivelRobot, int hp, int nrGloante, int scut)
    :Robot(damage,nivelRobot,hp), nrGloante(nrGloante),scut(scut){

}
//Calculam upgradeul pt RobotTerestru si updatam campurile
int RobotTerestru::calcUpgrade() {
    return 10*nrGloante;
    nrGloante+=100;
    damage+=50;
    if(nivelRobot==5) {
        scut+=50;
    }
    nivelRobot++;
}

istream &RobotTerestru::citire(istream &in) {
    Robot::citire(in);
    in>>nrGloante>>scut;
    return in;
}

ostream &RobotTerestru::afisare(ostream &out) {
    Robot::afisare(out);
    out<<nrGloante<<" "<<scut;
    return out;
}

class Inventar{
private:
    int nrPuncte;
    vector<Item*>v;
public:
    Inventar();
    ~Inventar();
    istream& citire(istream& in);
    void afisareItemeRobot();
    void upgradeElement();
};

Inventar::Inventar() : nrPuncte(50000) {

}

Inventar::~Inventar() {
    for(auto& x:v) {
        delete x;
    }

}
void Inventar::upgradeElement() {
    // Aici verificam tipul elementului din vector si calculam upgradeul corespunzator
    /*for(auto& x:v) {
        if(typeid(x)==typeid(Zid*)) {
            Zid *z = dynamic_cast<Zid*>(x);
            cout<<z->calcUpgrade();
        }
        if(typeid(x)==typeid(Turn*)) {
           Turn *z = dynamic_cast<Turn*>(x);
            cout<<z->calcUpgrade();
        }
        if(typeid(x)==typeid(RobotAerian*)) {
            RobotAerian *z = dynamic_cast<RobotAerian*>(*x);
            cout<<z->calcUpgrade();
        }
        if(typeid(x)==typeid(RobotTerestru*)) {
            RobotTerestru *z = dynamic_cast<RobotTerestru*>(x);
            cout<<z->calcUpgrade();
        }
    }
    */
}

void Inventar::afisareItemeRobot() {
     // Aici ar trb sa fac downcast la RobotAerian/Terestru si in functie de care dynamic_cast reuseste acela trb afisat
    /*for(auto *x:v) {
        if(dynamic_cast<RobotAerian*>(x)) {
            *dynamic_cast<RobotAerian*>(x)->afisare(cin);

        }
        else if(dynamic_cast<RobotTerestru*>(x)) {
            *dynamic_cast<RobotTerestru*>(x)->afisare(cin);
        }
    }
    */
}

//aici vom adauga un element
istream &Inventar::citire(istream &in) {
    cout<<"Ce vrei sa adaugi in vector? Zid/Turn/Robot";
    string choice;
    in>>choice;
    if(choice=="Zid") {

        Item* z1= new Zid(2,1,0.5);
        v.push_back(z1);
        nrPuncte=nrPuncte-300;
    }
    else if(choice=="Turn") {
        Item* t = new Turn(500);
        v.push_back(t);
        nrPuncte=nrPuncte-500;
    }
    else if(choice=="Robot") {
        string choice2;
        cout<<"Robot terestru sau aerian: RA/RT";
        in>>choice2;
        if(choice2=="RA") {
            Item *ra = new RobotAerian(100,1,100,10);
            v.push_back(ra);
            nrPuncte=nrPuncte-100;
        }
        else if(choice2=="RT") {
            Item *rt = new RobotTerestru(100,1,100,500,0);
            v.push_back(rt);
            nrPuncte=nrPuncte-50;
        }
        else throw "Tip de robot necunoscut";
    }
    else throw "Optiune invalida";

}

void meniu() {
    Inventar inventar;
    while(true) {
        cout<<"1. Adauga element:\n"
              "2. Upgrade Element:\n"
              "3. Afisare elemente din inventar crescator dupa costul de upgrade:\n"
              "4. Afisarea elementelor de tip robot:\n"
              "5. Sell:\n "
              "6. Exit: \n";
        int nr;
        cin>>nr;
        if(nr==1){
            //functia de citire citeste si adauga cate un element pe rand in functie de tipul lui
            inventar.citire(cin);
        }
        else if(nr==2) {
           inventar.upgradeElement();
        }
        else if(nr==3) {
            //TODO afisare crescatoare
        }
        else if(nr==4) {
            inventar.afisareItemeRobot();
        }
        else if(nr==5) {
            //TODO sell
        }

        else if(nr==6) {
            return;
        }
        else throw "optiune meniu invalida";
    }

}

int main()
{
    try {
        meniu();
    }catch(const char* msj) {
        cout<<msj<<" ";
    }
    return 0;
}
