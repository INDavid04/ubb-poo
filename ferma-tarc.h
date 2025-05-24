#include <iostream>
#include <map>
#include <string>
 
using namespace std;

class Tarc {
private:
    int capacitateAnimale, resurseIgiena, resurseHrana;
    float venit;
    map<string, int> tarcAnimale{};
protected:
public:
    /// Constructor fara parametrii
    Tarc() {
        capacitateAnimale = 15;
        resurseIgiena = 5;
        resurseHrana = 10;
        venit = 20;
    }
    /// Constructor cu toti parametrii
    Tarc(int capacitateAnimaleInitial, int resurseIgienaInitial, int resurseHranaInitial, float venitInitial) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = resurseHranaInitial;
        venit = venitInitial;
    }
    /// Constructor cu parametrii
    Tarc(int capacitateAnimaleInitial, int resurseIgienaInitial) {
        capacitateAnimale = capacitateAnimaleInitial;
        resurseIgiena = resurseIgienaInitial;
        resurseHrana = 0;
        venit = 0;
    }
    /// Constructor cu parametrii
    Tarc(int resurseHranaInitial, float venitInitial) {
        capacitateAnimale = 0;
        resurseIgiena = 0;
        resurseHrana = resurseHranaInitial;
        venit = venitInitial;
    }
    /// Constructor de copiere
    Tarc(const Tarc& altTarc) {
        capacitateAnimale = altTarc.capacitateAnimale;
        resurseIgiena = altTarc.resurseIgiena;
        resurseHrana = altTarc.resurseHrana;
        venit = altTarc.venit;
    }
    /// Suprascrierea operatorului egal
    Tarc& operator=(const Tarc& altTarc) {
        if(this != &altTarc) { 
            capacitateAnimale = altTarc.capacitateAnimale;
            resurseIgiena = altTarc.resurseIgiena;
            resurseHrana = altTarc.resurseHrana;
            venit = altTarc.venit;
        }
        return *this;
    }
    /// Destructor
    ~Tarc() {
        cout << "Bunicul Neculai s-a intors si este bucuros sa se ingrijeasca de noile animalute.\n";
    }
    /// Setter
    void setAnimale(int capacitate = 0) {
        capacitateAnimale = capacitate;
    }
    void addAnimale(string nume, int capacitate = 0) {
        capacitateAnimale += capacitate;
        tarcAnimale[nume] = capacitate;
    }
    /// Getter
    float getVenit() {
        return venit;
    }
    int getCapacitateAnimale() {
        return capacitateAnimale;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Tarc& f) {
        out << "Capacitate animale: " << f.capacitateAnimale << ", resurse igiena: " << f.resurseIgiena << ", resurse hrana: " << f.resurseHrana << ", venit: " << f.venit;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Tarc& f) {
        cout << "Introdu capacitate animale: ";
        in >> f.capacitateAnimale;
        cout << "Introdu resurse igiena: ";
        in >> f.resurseIgiena;
        cout << "Introdu resurse hrana: ";
        in >> f.resurseHrana;
        cout << "Introdu venit: ";
        in >> f.venit;
        return in;
    }
    void cumparaAnimale(int cantitate = 0) {
        capacitateAnimale += cantitate;
        venit += cantitate * 0.2;
    }
    void cateAnimale() {
        for (const auto& entry : tarcAnimale) {
            const string& key = entry.first;
            int value = entry.second;
            cout << value << " " << key << "\n";
        }
    }
};
