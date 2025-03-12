/// Seminar #1 - Tema 1 Due March 18, 2025 11:59 PM

#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

/// TODO (Mandatory):
/// De implementat cele două clase Vector și Stivă de la finalul Seminarului I. Aveți seminarul atașat în canalul Seminar > Files > Seminarii > Seminarul I. Multă baftă.

/// 1. Implementati clasa Stiva avand urmatoarele functionalitati:
///     • memorie alocata dinamic
///     • constructor (de toate tipurile) si destructor
///     • metoda de adaugare element in Stiva
///     • metoda de eliminare element din Stiva care returneaza elementul eliminat;

// class Stiva {
//     s t u d e n t ∗ s = new s t u d e n t ;
//     2 ∗( s ) . prenume = ” Fl o ri n ” ;
//     3 s−>prenume = ” Fl o ri n ” ;
    
//     student
// }

/// 2. Implementati clasa Vector avand urmatoarele functionalitati:
///     • memorie alocata dinamic
///     • constructor (de toate tipurile) si destructor
///     • metoda de adaugare element la sfarsitul vectorului
///     • metoda de eliminare element de la sfarsitul vectorului
///     • metoda ce intoarce un element de pe pozitia i primita ca parameteru
///     • metoda ce intoarce numarul de elemente din vector


/// TODO (Nice):
/// 1. Implementati un program care citeste doua numere intregi de la tastatura si afiseaza maximul.
/// 2. Implementati un program care citeste de la tastatura un n ≥ 3 si afiseaza al n-lea numar al lui Fibbonaci.
/// 3. Implementati un program care citeste de la tastatura un vector de numere in virgula mobila si il sorteaza in ordine crescatoare.
/// 4. Implementati un program care citeste de la tastatura un numar intreg si determina daca este palindrom.


/// TODO (Aside):

class Persoana {
private:
    char nume[20];
    int varsta;
public:
    // Constructor
    Persoana(const char* numeInitial = "John Doe", int varstaInitiala = 20) {
        strcpy(nume, numeInitial);
        varsta = varstaInitiala;
    }
    void afisare() {
        cout << nume << " are " << varsta << " ani.\n";
    }
};

void definirea_unei_clase_persoana() {
    /// 1. Definirea unei clase "Persoană"
    ///     • Creează o clasă Persoana cu atribute nume și varsta.
    ///     • Adaugă un constructor pentru inițializare și o metodă afisare() pentru a printa informațiile persoanei.
    ///     • Creează obiecte și testează metoda.

    Persoana p1("Mihai Cristian", 40);
    Persoana p2("Mircea Grigore", 30);
    p1.afisare();
    p2.afisare();
}


int main() {
    definirea_unei_clase_persoana();

    return 0;
}
