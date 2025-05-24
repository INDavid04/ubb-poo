#include <iostream>
using namespace std; /// use this line to fix a lot of errors, sorry, no time time left to list them here :)

class Jucator {
private:
    char* numeJucator;
    int nivelJucator;
    float monede;
protected:
public:
    /// Constructor fara parametrii
    Jucator() {
        numeJucator = new char[40];
        strcpy(numeJucator, "Anonimus");
        nivelJucator = 0;
        monede = 0;
    }
    /// Constructor cu toti parametrii
    Jucator(const char* numeJucatorDefault, int nivelJucatorDefault, float monedeDefault) {
        numeJucator = new char[strlen(numeJucatorDefault) + 1];
        strcpy(numeJucator, numeJucatorDefault);
        nivelJucator = nivelJucatorDefault;
        monede = monedeDefault;
    }
    /// Constructor cu parametrii
    Jucator(const char* numeJucatorDefault, int nivelJucatorDefault) {
        numeJucator = new char[strlen(numeJucatorDefault) + 1];
        strcpy(numeJucator, numeJucatorDefault);
        nivelJucator = nivelJucatorDefault;
        monede = 0;
    }
    /// Constructor cu parametrii
    Jucator(int nivelJucatorDefault, float monedeDefault) {
        strcpy(numeJucator, "Anonimaroi");
        nivelJucator = nivelJucatorDefault;
        monede = monedeDefault;
    }
    /// Constructor de copiere
    Jucator(const Jucator& altJucator) {
        numeJucator = new char[strlen(altJucator.numeJucator) + 1];
        strcpy(numeJucator, altJucator.numeJucator);
        nivelJucator = altJucator.nivelJucator;
        monede = altJucator.monede;
    }
    /// Suprascrierea operatorului egal
    Jucator& operator=(const Jucator& altJucator) {
        if(this != &altJucator) { /// skip pentru j = j, de exemplu
            delete[] numeJucator;
            numeJucator = new char[strlen(altJucator.numeJucator) + 1];
            strcpy(numeJucator, altJucator.numeJucator);
            nivelJucator = altJucator.nivelJucator;
            monede = altJucator.monede;
        }
        return *this;
    }
    /// Destructor
    ~Jucator() {
        cout << numeJucator << " a iesit din joc avand nivelul " << nivelJucator << ".\n";
        delete[] numeJucator;
    }
    /// Setter
    void setName(const char* nume = "Abel Diriclet") {
        delete[] numeJucator;
        numeJucator = new char[strlen(nume) + 1];
        strcpy(numeJucator, nume);
    }
    /// Getter
    const char* getName() {
        return numeJucator;
    }
    float getMonede() {
        return monede;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Jucator& j) {
        out << "Name: " << j.numeJucator << ", Level: " << j.nivelJucator << ", Points: " << j.monede;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Jucator& j) {
        cout << "Introdu numele jucatorului: ";
        in >> j.numeJucator;
        cout << "Cate nivele a terminat?: ";
        in >> j.nivelJucator;
        cout << "Cate monede a agonisit?: ";
        in >> j.monede;
        return in;
    }
    /// Supraincarcare operator ++ prefixat
    // Jucator& operator++() {
    //     nivelJucator++;
    //     monede += 20;
    //     return *this;
    // }
    /// Supraincarcare operator -- postfixat
    // Jucator operator--(int) {
    //     Jucator temp = *this;
    //     if (nivelJucator > 1) nivelJucator--;
    //     return temp;
    // }
    /// Operator ==
    bool operator==(const Jucator& altJucator) const {
        return this->nivelJucator == altJucator.nivelJucator;
    }
    void showInfo() {
        cout << "-Jucator-----------------------------------------------------------------------------------------\n";
        cout << "Nume: " << numeJucator << " | Nivel: " << nivelJucator << " | Monede: " << monede << endl;
        cout << "-------------------------------------------------------------------------------------------------\n";
    }
    void levelUp(int contor = 1) {
        monede += 20 * contor;
        nivelJucator++;
        cout << "Hurray! Ai mai avansat un nivel, acum avand " << nivelJucator << " nivele! In plus, ai mai castigat si " << 20 * contor << " monede.\n";
    }
    void levelDown() {
        if(nivelJucator) {
            nivelJucator--;
            cout << "Tocmai ai pierdut un nivel, ramanand cu inca " << nivelJucator << " nivel(e)\n";
        }
    }
    void moneyUp(float money = 0) {
        monede += money;
    }
    void moneyDown(float money = 0) {
        monede -= money;
    }
};
