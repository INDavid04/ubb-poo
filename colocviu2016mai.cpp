/// 2025-09-06-1130-TODO
/// g++ main.cp -o e.exe
/// ./e.exe
/// Radu Tudor Vrinceanu

////////////////
/// Ierarhie ///
////////////////

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

/// Ingredient: denIng, pretIng, cantIng, masIng
class Ingredient {
    const char * denIng;
    const char * masIng;
    double pretIng;
    int cantIng;
public:
    Ingredient() {
        denIng = "Necunoscut";
        masIng = "Necunoscuta";
        pretIng = 0;
        cantIng = 0;
    }

    Ingredient(const char *denIng, const double pretIng, const int cantIng, const char *masIng) : denIng(denIng), masIng(masIng), pretIng(pretIng), cantIng(cantIng) {}

    Ingredient(const Ingredient &i) {
        this->denIng = i.denIng;
        this->masIng = i.masIng;
        this->pretIng = i.pretIng;
        this->cantIng = i.cantIng;
    }

    Ingredient* operator=(const Ingredient i) {
        this->denIng = i.denIng;
        this->masIng = i.masIng;
        this->pretIng = i.pretIng;
        this->cantIng = i.cantIng;
        return this;
    }

    /// lista[3] = lista[3] + 3; // se adaugă 3 felii de salam la ingredient
    Ingredient operator+(const int val) {
        Ingredient ingredient(*this);
        ingredient.cantIng += val;
        return ingredient;
    }

    /// lista[1]++; // se adaugă un gram de sare la ingredient
    Ingredient operator++(int) {
        Ingredient ingredient; /// pentru a returna obiectul initial, post-incrementare
        this->cantIng++;
        return ingredient;
    }

    /// lista[0]-=2.5; // se scade o valoare din pretul ingredientului
    void operator-=(const double val) {
        this->pretIng -= val;
    }

    /// lista[2].del(); //ingredientul nu mai este disponibil
    void del() {
        delete this;
    }

    // friend ostream operator<<(ostream &o, Ingredient i) {
    //     o << "Denumire: " << i.denIng << "; Pret: " << i.pretIng << "; Cantitate: " << i.cantIng << "; Masura: " << i.masIng << "\n";
    //     return o;
    // }
};

/// Pizza: codPizza, denPizza, ingPizza, nringPizza, vegPizza, pretPizza
class Pizza {
    static int id;
    int codPizza;
    string denPizza;
    vector<Ingredient> ingPizza;
    int nringPizza;
    bool vegPizza;
    double pretPizza; /// suma pretIng * 1.5
};

int Pizza::id = 1; /// primul sortiment de pizza are codul 1

int main() {
    Ingredient lista[5] = { 
        Ingredient("piept de pui", 15, 1, "kg"), 
        Ingredient("sare", 0.75, 10, "gram"), 
        Ingredient("salam", 1.5, 5, "felii"), 
        lista[2], 
        Ingredient() 
    }, i1("sunca", 3, 2, "felii");

    // cin >> lista[4]; // se citește un nou ingredient

    lista[3] = lista[3] + 3; // se adaugă 3 felii de salam la ingredient

    lista[1]++; // se adaugă un gram de sare la ingredient

    lista[0]-=2.5; // se scade o valoare din pretul ingredientului

    lista[2].del(); //ingredientul nu mai este disponibil

    // for (int i=0; i<5; i++) {
    //     cout<<"Ingredient: "<<lista[i]<<endl;
    // }

    // Pizza p1 ("Rustica", lista, 4, false); // se crează un sortiment nou de pizza

    // Pizza p2 = p1, p3; // se crează două sortimente noi de pizza, dintre care unul cu aceleași ingrediente ca pizza p1
    
    // p2 = p2 - lista[2]; // se scoate ingredientul respectiv din rețeta sortimentului

    // p3 = p2 + i1; // se stabilește rețeta pizzei p3 din ingredientele pizzei p2 la care se adaugă ingredientul i1

    // p3.nume("Prosciuto"); // este schimbată denumirea pizzei p3

    // cout<<"Pizza "<<p1.nume()<<" "<<p1.pret()<<" lei"<<endl;
    // cout<<"Pizza "<<p2.nume()<<" "<<p2.pret()<<" lei"<<endl;
    // cout<<"Pizza "<<p3.nume()<<" "<<p3.pret()<<" lei";

    return 0;
}
