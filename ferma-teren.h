using namespace std;

class Teren {
private:
    int nivelIngrasamant, nivelProductie;
    float venit, taxe;
    long long resurse[3];
protected:
public:
    /// Constructor fara parametrii
    Teren() {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurse[0] = 0; /// grau
        resurse[1] = 0; /// cartofi
        resurse[2] = 0; /// morcovi
    }
    /// Constructor cu toti parametrii
    Teren(int nivelIngrasamantInitial, int nivelProductieInitial, float venitInitial, float taxeInitial, long long resurseGrauInitial, long long resurseCartofiInitial, long long resurseMorcoviInitial) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = venitInitial;
        taxe = taxeInitial;
        resurse[0] = resurseGrauInitial;
        resurse[1] = resurseCartofiInitial;
        resurse[2] = resurseMorcoviInitial;
    }
    /// Constructor cu parametrii
    Teren(int nivelIngrasamantInitial, int nivelProductieInitial) {
        nivelIngrasamant = nivelIngrasamantInitial;
        nivelProductie = nivelProductieInitial;
        venit = 0;
        taxe = 0;
        resurse[0] = 0;
        resurse[1] = 0;
        resurse[2] = 0;
    }
    /// Constructor cu parametrii
    Teren(long long resurseMorcoviInitial) {
        nivelIngrasamant = 0;
        nivelProductie = 0;
        venit = 0;
        taxe = 0;
        resurse[0] = 0;
        resurse[1] = 0;
        resurse[2] = resurseMorcoviInitial;
    }
    /// Constructor de copiere
    Teren(const Teren& altTeren) {
        nivelIngrasamant = altTeren.nivelIngrasamant;
        nivelProductie = altTeren.nivelProductie;
        venit = altTeren.venit;
        taxe = altTeren.taxe;
        resurse[0] = altTeren.resurse[0];
        resurse[0] = altTeren.resurse[1];
        resurse[0] = altTeren.resurse[2];
    }
    /// Suprascrierea operatorului egal
    Teren& operator=(const Teren& altTeren) {
        if(this != &altTeren) { 
            nivelIngrasamant = altTeren.nivelIngrasamant;
            nivelProductie = altTeren.nivelProductie;
            venit = altTeren.venit;
            taxe = altTeren.taxe;
            resurse[0] = altTeren.resurse[0];
            resurse[1] = altTeren.resurse[1];
            resurse[2] = altTeren.resurse[2];
        }
        return *this;
    }
    // Supraincarcare operator +
    Teren operator+(const Teren& altTeren) const {
        return Teren(this->nivelProductie + altTeren.nivelProductie);
    }
    // Supraincarcare operator *
    Teren operator*(int factor) const {
        return Teren(this->nivelProductie * factor);
    }
    /// Destructor
    ~Teren() {
        cout << "Bineinteles ca nu va uita sa aiba grija si de teren.\n";
    }
    /// Supraincarcare operator de indexare adica []
    long long operator[](int index) const {
        if (index >= 0 && index < 3) return resurse[index];
        return -1; /// i.e. nu-i valid
    }
    /// Setter
    void setIngrasamant(int cantitate = 0) {
        nivelIngrasamant = cantitate;
    }
    void setTaxa(float monede = 0) {
        taxe = monede;
    }
    /// Getter
    long long getGrau() {
        return resurse[0];
    }
    long long getCartofi() {
        return resurse[1];
    }
    long long getMorcovi() {
        return resurse[2];
    }
    float getTaxa() {
        return taxe;
    }
    float getVenit() {
        return venit;
    }
    /// Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Teren& t) {
        out << "Nivel ingrasamant: " << t.nivelIngrasamant << ", nivel productie: " << t.nivelProductie << ", resurse grau: " << t.resurse[0] << ",resurse cartofi: " << t.resurse[1] << ", resurse morcovi: " << t.resurse[2] << ", venit: " << t.venit << ", taxe: " << t.taxe;
        return out;
    }
    /// Supraincarcare operator >>
    friend istream& operator>>(istream& in, Teren& t) {
        cout << "Introdu nivel ingrasamant: ";
        in >> t.nivelIngrasamant;
        cout << "Introdu nivel productie: ";
        in >> t.nivelProductie;
        cout << "Introdu resurse grau: ";
        in >> t.resurse[0];
        cout << "Introdu resurse cartofi: ";
        in >> t.resurse[1];
        cout << "Introdu resurse morcovi: ";
        in >> t.resurse[2];
        cout << "Introdu venit: ";
        in >> t.venit;
        cout << "Introdu taxe: ";
        in >> t.taxe;
        return in;
    }
    /// Operator < 
    bool operator<(const Teren& altTeren) const {
        return this->nivelProductie < altTeren.nivelProductie;
    }
    void cumparaResurse(int index, long long cantitate) {
        if (index >= 0 && index <= 2) {
            resurse[index] += cantitate;
            venit += resurse[index] * cantitate * 0.2;
        }
    }
};
