using namespace std;

class Casa {
private:
    char nivelComfort[10]; 
    int venitChirie;
    float taxe;
protected:
public:
    /// Constructor fara parametrii
    Casa() {
        strcpy(nivelComfort, "low");
        venitChirie = 0;
        taxe = 10;
    }
    /// Constructor cu toti parametrii
    Casa(const char* nivelComfortInitial, int venitChirieInitial, float taxeInitial) {
        strcpy(nivelComfort, nivelComfortInitial);
        venitChirie = venitChirieInitial;
        taxe = taxeInitial;
    }
    /// Constructor cu parametrii
    Casa(const char* nivelComfortInitial, int venitChirieInitial) {
        strcpy(nivelComfort, nivelComfortInitial);
        venitChirie = venitChirieInitial;
        taxe = 0;
    }
    /// Constructor cu parametrii
    Casa(int venitChirieInitial, float taxeInitial) {
        strcpy(nivelComfort, "low");
        venitChirie = venitChirieInitial;
        taxe = taxeInitial;
    }
    /// Constructor de copiere
    Casa(const Casa& altaCasa) {
        strcpy(nivelComfort, altaCasa.nivelComfort);
        venitChirie = altaCasa.venitChirie;
        taxe = altaCasa.taxe;
    }
    /// Suprascrierea operatorului egal
    Casa& operator=(const Casa& altaCasa) {
        if(this != &altaCasa) { 
            strcpy(nivelComfort, altaCasa.nivelComfort);
            venitChirie = altaCasa.venitChirie;
            taxe = altaCasa.taxe;
        }
        return *this;
    }
    /// Destructor
    ~Casa() {
        cout << "Desi casa este a lui, vrea sa stii ca usa iti e mereu deschisa.\n";
    }
    /// Setter
    void setComfort(const char* status = "low") {
        strcpy(nivelComfort, status);
    }
    void setChirie() {
        if (strcmp(nivelComfort, "low") == 0) {
            venitChirie = 50;
        } else if (strcmp(nivelComfort, "medium") == 0) {
            venitChirie = 100;
        } else {
            venitChirie = 200;
        }
    }
    /// Getter
    int getChirie() {
        return venitChirie;
    }
    float getTaxa() {
        return taxe;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Casa& c) {
        out << "Nivel comfort: " << c.nivelComfort << ", Venit chirie: " << c.venitChirie << ", Taxe: " << c.taxe;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Casa& c) {
        cout << "Introdu nivelul de comfort: ";
        in >> c.nivelComfort;
        cout << "Introdu venit chirie: ";
        in >> c.venitChirie;
        cout << "Introdu taxe: ";
        in >> c.taxe;
        return in;
    }
};
