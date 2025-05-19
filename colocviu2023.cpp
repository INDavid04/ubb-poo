#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Drum;
class Contract;

/// Variabile globale
vector<Drum*> drumuri;
list<Contract*> contracte;

class Drum {
protected:
    string denumire;
    double lungime;
    int nr_tronsoane;
public:
    Drum(string denumire = "N/A", double lungime = 0.0, int nr_tronsoane = 1) {
        this->denumire = denumire;
        this->lungime = lungime;
        this->nr_tronsoane = nr_tronsoane;
    }
    friend istream& operator>>(istream& in, Drum& drum) {
       cout << "Citeste denumirea: ";
       in >> drum.denumire;

       cout << "Citeste lungimea: ";
       in >> drum.lungime;

       cout << "Citeste numarul tronsoanelor: ";
       in >> drum.nr_tronsoane;

       return in;
    }
    friend ostream& operator<<(ostream& out, const Drum& drum) {
        out << "Denumire: " << drum.denumire << endl;
        out << "Lungime: " << drum.lungime << endl;
        out << "Nr Tronsoane: " << drum.nr_tronsoane << endl;
        return out;
    }
    string getDenumire() const {
        return denumire;
    }
    int getNrTronson() const {
        return nr_tronsoane;
    }
    double getLungime() const {
        return lungime;
    }
    virtual ~Drum() = default;
};

class DrumNational : public Drum {
protected:
    int nr_judete;
public:
    DrumNational(int nr_judete = 0) {
        this->nr_judete = nr_judete;
    }
    friend istream& operator>>(istream& in, DrumNational& drum_national) {
        in >> (Drum&)drum_national; /// cast explicit; se citesc mai intai membrii mosteniti: denumire, drum, nr_tronsoane

        cout << "Citeste numarul de judete: ";
        in >> drum_national.nr_judete;

        return in;
    }
    friend ostream& operator<<(ostream& out, const DrumNational& drum_national) {
        out << (Drum&)drum_national;
        out << "Nr Judete" << drum_national.nr_judete << endl;
        return out;
    }
};

class DrumEuropean : virtual public Drum {
protected:
    int nr_tari;
public:
    DrumEuropean(int nr_tari = 0) {
        this->nr_tari = nr_tari;
    }
    friend istream& operator>>(istream& in, DrumEuropean& drum_european) {
        in >> (Drum&)drum_european;

        cout << "Citeste numarul de tari: ";
        in >> drum_european.nr_tari;

        return in;
    }
    friend ostream& operator<<(ostream& out, const DrumEuropean& drum_european) {
        out << (Drum&)drum_european;
        out << "Nr Tari" << drum_european.nr_tari << endl;
        return out;
    }
    int getNrTari() const {
        return nr_tari;
    }
};

class Autostrada : virtual public Drum {
protected:
    int nr_benzi;
public:
    Autostrada(int nr_benzi = 2) {
        this->nr_benzi = nr_benzi;
    }
    friend istream& operator>>(istream& in, Autostrada& autostrada) {
        in >> (Drum&)autostrada;

        cout << "Citeste numarul de benzi: ";
        in >> autostrada.nr_benzi;

        return in;
    }
    friend ostream& operator<<(ostream& out, const Autostrada& autostrada) {
        out << (Drum&)autostrada;
        out << "Nr Benzi" << autostrada.nr_benzi << endl;
        return out;
    }
    int getNrBenzi() const {
        return nr_benzi;
    }
};

class ADE : public DrumEuropean, public Autostrada {
public:
    ADE() = default;
    friend istream& operator>>(istream& in, ADE& ade) {
        in >> (DrumEuropean&)ade;

        cout << "Citeste numarul de benzi: ";
        in >> ade.nr_benzi;

        return in;
    }
    friend ostream& operator<<(ostream& out, const ADE& ade) {
        out << (Autostrada&)ade;
        out << "Nr Tari" << ade.nr_tari << endl;
        return out;
    }
};

class Contract {
    static int generatorId;
    const int id;
    string nume_firma;
    long long CIF;
    double price;
    string id_drum;
    int id_tronson;

    double computePriceOfContract() {
        auto it = find_if(drumuri.begin(), drumuri.end(), [this](Drum *drum) -> bool {
            return drum->getDenumire() == this->id_drum;
        });

        Drum *drum_curent = *it;

        Autostrada *autostrada_drum_curent = dynamic_cast<Autostrada*>(drum_curent);
        ADE *ade_drum_curent = dynamic_cast<ADE*>(drum_curent);
        DrumEuropean *de_drum_curent = dynamic_cast<DrumEuropean*>(drum_curent);

        if (dynamic_cast<DrumNational*>(drum_curent) != nullptr) {
            return 3000 * (drum_curent->getLungime() / drum_curent->getNrTronson());
        } else if (ade_drum_curent != nullptr) {
            return 2500 * (autostrada_drum_curent->getNrBenzi()) * (autostrada_drum_curent->getLungime() / autostrada_drum_curent->getNrTronson()) +
            500 * ade_drum_curent->getNrTari();
        } else if (autostrada_drum_curent != nullptr) {
            return 2500 * (autostrada_drum_curent->getNrBenzi()) * (autostrada_drum_curent->getLungime() / autostrada_drum_curent->getNrTronson());
        } else if (de_drum_curent != nullptr) {
            return 500 * de_drum_curent->getNrTari();
        } else {
            throw bad_cast();
        }
    }
public:
    Contract(string nume_firma = "N/A", long long CIF = 10000000, double price = 0.0, string nume_drum = "N/A", int tronson = 1)
    : id(generatorId++) {
        this->nume_firma = nume_firma;
        this->CIF = CIF;
        this->price = price;
        this->id_drum = nume_drum;
        this->id_tronson = tronson;
        this->price = this->computePriceOfContract();
    }
    friend istream& operator>>(istream& in, Contract& contract) {
        cout << "Citeste nume firma: ";
        in >> contract.nume_firma;

        cout << "Citeste CIF: ";
        in >> contract.CIF;

        cout << "Citeste id-ul drumului asociat: ";
        string nume_drum;
        in >> nume_drum;

        auto it = find_if(drumuri.begin(), drumuri.end(), [nume_drum](Drum *drum) -> bool {
            return drum->getDenumire() == nume_drum;
        });
        if (it == drumuri.end()) {
            throw runtime_error("Drumul cu numele citit nu exista!");
        }
        contract.id_drum = nume_drum;

        cout << "Citeste numarul tronsonului: " << endl;
        int tronson;
        in >> tronson;
        if (tronson >= (*it)->getNrTronson() && tronson < 1) {
            throw runtime_error("Drumul nu are atatea tronsoane.");
        }
        contract.id_tronson = tronson;

        return in;
    }

    long long getCIF() const {
        return CIF;
    }

    string getIdDrum() const {
        return id_drum;
    }

    double getPrice() const {
        return price;
    }

    static void stergeContracte(list<Contract*>& contracte, const long long& CIF) {
        vector<Contract*> toBeDeleted;
        for (auto contract : contracte) {
            if (contract->getCIF() == CIF) {
                toBeDeleted.push_back(contract);
            }
        }

        if (toBeDeleted.empty()) {
            throw runtime_error("Nu a fost gasita nicio firma cu CIF-ul indicat");
        }

        for (auto elementToBeDeleted : toBeDeleted) {
            contracte.remove(elementToBeDeleted);

            if (elementToBeDeleted != nullptr) {
                delete elementToBeDeleted;
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Contract& contract) {
        out << "ID: " << contract.id << endl;
        out << "Nume firma contractoare si CIF: " << contract.nume_firma << " (" << contract.CIF << ")" << endl;
        out << "Nume drum si tronson atribuit: " << contract.id_drum << " " << contract.id_tronson << endl;
        out << "Pretul: " << contract.price;
        return out;
    }
};
int Contract::generatorId = 1000;

int main() {
    do {
        cout << "1. Citeste o lista de drumuri" << endl;
        cout << "2. Citeste o lista de contracte" << endl;
        cout << "3. Calculeaza lungime totala drumuri" << endl;
        cout << "4. Calculeaza lungime totala drumuri tip autostrada" << endl;
        cout << "5. Sterge contract cu o anumita firma" << endl;
        cout << "6. Calculeaza costul total al contractului asociat unui drum" << endl;
        cout << "7. Afiseaza toate drumurile" << endl;
        cout << "8. Afiseaza toate contractele" << endl;
        cout << "*. Opreste programul" << endl;

        int option;
        cin >> option;

        try {
            switch (option) {
                case 1: {
                    string road_type;
                    cout << "Alege tipul de drum pe care vrei sa il citesti: " << endl;
                    cin >> road_type;

                    if (road_type == "dn") {
                        DrumNational *dn = new DrumNational();
                        cin >> *dn;

                        drumuri.push_back(dn);
                        cout << "Ai introdus un drum national cu succes." << endl;
                    } else if (road_type == "de") {
                        DrumEuropean *de = new DrumEuropean();
                        cin >> *de;

                        drumuri.push_back(de);
                        cout << "Ai introdus un drum european cu succes." << endl;
                    } else if (road_type == "a") {
                        Autostrada *a = new Autostrada();
                        cin >> *a;

                        drumuri.push_back(a);
                        cout << "Ai introdus o autostrada cu succes." << endl;
                    } else if (road_type == "ade") {
                        ADE *ade = new ADE();
                        cin >> *ade;

                        drumuri.push_back(ade);
                        cout << "Ai introdus o autostrada (drum european) cu succes." << endl;
                    } else {
                        throw runtime_error("Tipul de drum este gresit poti alege intre (a, ade, de si dn).");
                    }
                    cout << "Vrei sa mai introduci noi drumuri? (yes/no)";
                    break;
                }
                case 2: {
                    Contract *contract = new Contract();
                    cin >> *contract;

                    contracte.push_back(contract);
                    cout << "Ai introdus un contract cu succes!" << endl;
                    break;
                }
                case 3: {
                    long long total_length = 0;
                    for (auto drum : drumuri) {
                        total_length += drum->getLungime();
                    }
                    cout << "Lungimea totala a drumurilor este de: " << total_length << endl;
                    break;
                }
                case 4: {
                    long long autostrada_total_length = 0;
                    for (auto drum : drumuri) {
                        Autostrada *autostrada_drum = dynamic_cast<Autostrada*>(drum);
                        if (autostrada_drum != nullptr) {
                            autostrada_total_length += autostrada_drum->getLungime();
                        }
                    }

                    cout << "Lungimea totala a autostrazilor este de: " << autostrada_total_length << endl;
                    break;
                }
                case 5: {
                    long long CIF;
                    cout << "Introdu firma la care vrei sa reziliezi contractele: ";
                    cin >> CIF;

                    Contract::stergeContracte(contracte, CIF);
                    break;
                }
                case 6: {
                    string nume_drum;
                    cout << "Introdu numele drumului pentru care dorim suma contractelor: ";
                    cin >> nume_drum;

                    double total_price = 0.0;
                    for (auto contract : contracte) {
                        if (contract->getIdDrum() == nume_drum) {
                            total_price = total_price + contract->getPrice();
                        }
                    }

                    cout << "Suma totala a contractelor pentru drumul " << nume_drum << " este de " << total_price << endl;
                    break;
                }
                case 7: {
                    for (auto drum : drumuri) {
                        cout << *drum << endl;
                    }
                    break;
                }
                case 8: {
                    for (auto contract : contracte) {
                        cout << *contract << endl;
                    }
                    break;
                }
                default: {
                    // stergere din list, vector
                    return 0;
                }
            }
        } catch (exception& error) {
            cout << error.what() << endl;
        }

    } while (true);
    return 0;
}
