/// Seminar #1 - Tema 1 Due March 18, 2025 11:59 PM

#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

///------------------------------------------------------------------------------------------------------------------///

/// TODO (Mandatory, sursa: seminarul 1):

///------------------------------------------------------------------------------------------------------------------///

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

///------------------------------------------------------------------------------------------------------------------///

/// TODO (Nice, sursa: seminarul 1):

///------------------------------------------------------------------------------------------------------------------///

/// 1. Implementati un program care citeste doua numere intregi de la tastatura si afiseaza maximul.
/// 2. Implementati un program care citeste de la tastatura un n ≥ 3 si afiseaza al n-lea numar al lui Fibbonaci.
/// 3. Implementati un program care citeste de la tastatura un vector de numere in virgula mobila si il sorteaza in ordine crescatoare.
/// 4. Implementati un program care citeste de la tastatura un numar intreg si determina daca este palindrom.

///------------------------------------------------------------------------------------------------------------------///

/// TODO (Aside, sursa: chatgpt):

///------------------------------------------------------------------------------------------------------------------///

/// Etapa 1: Bazele OOP - Clase și Obiecte

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
    /// Creează o clasă Persoana cu atribute nume și varsta.
    /// Adaugă un constructor pentru inițializare și o metodă afisare() pentru a printa informațiile persoanei.
    /// Creează obiecte și testează metoda.
    Persoana p1("Mihai Cristian", 40);
    Persoana p2("Mircea Grigore", 30);
    p1.afisare();
    p2.afisare();
}

///------------------------------------------------------------------------------------------------------------------///

class Masina {
private:
    char marca[40];
    char model[40];
    int anFabricatie;
public:
    /// Constructor
    Masina(const char* marcaInitiala = "Seat", const char* modelInitial = "Leon", int anFabricatieInitial = 1950) {
        strcpy(marca, marcaInitiala);
        strcpy(model, modelInitial);
        anFabricatie = anFabricatieInitial;
    }

    void afiseazaDetalii() {
        cout << "Masina cu marca " << marca << ", modelul " << model << " a fost fabricata in anul " << anFabricatie << endl;
    }

    void modificaAnFabricatie(int an = 1980) {
        anFabricatie = an;
    }
};

void clasa_masina() {
    /// Adaugă atribute marca, model, anFabricatie.
    /// Scrie metode afiseazaDetalii() și modificaAnFabricatie(int).
    Masina m1;
    m1.afiseazaDetalii();
    m1.modificaAnFabricatie(2010);
    m1.afiseazaDetalii();
    m1.modificaAnFabricatie();
    m1.afiseazaDetalii();
}

///------------------------------------------------------------------------------------------------------------------///

/// Etapa 2: Constructori, Destructor, Alocare Dinamică

class Student {
private:
    char nume[20];
    float* note = new float[5];
    int nrNote;
protected:
public:
    /// Constructor
    Student(const char* numeInitial = "John Doe", const float* noteInitiale = nullptr, int nrNoteInitial = 3) {
        strcpy(nume, numeInitial);
        nrNote = nrNoteInitial;
        note = new float [nrNoteInitial];

        if (noteInitiale != nullptr) {
            for (int i = 0; i < nrNoteInitial; i++) {
                note[i] = noteInitiale[i];
            }
        } else {
            for (int i = 0; i < nrNoteInitial; i++) {
                note[i] = 0;
            }
        }
    }

    /// Destructor
    ~Student() {
        delete[] note;
        cout << "Studentul " << nume << " a iesit din registru.\n";
    }

    /// Metoda de afișare a notelor
    void afiseazaNote() {
        cout << "Notele studentului " << nume << ": ";
        for (int i = 0; i < nrNote; i++) {
            cout << note[i] << " ";
        }
        cout << endl;
    }
};

void implementarea_unei_clase_student_cu_memoria_alocata_dinamic() {
    /// Atribute: nume, note (vector alocat dinamic de n elemente).
    /// Constructor care primește un număr de note și le inițializează cu valori.
    /// Destructor care eliberează memoria.
    /// Metodă afiseazaNote().
    /// Testează crearea și ștergerea obiectelor.
    float noteExemplu[] = {7.8, 9.0, 3.5};
    Student s1("Mihai Cristian", noteExemplu, 3);
    Student s2("Andrei Popescu");

    s1.afiseazaNote();
    s2.afiseazaNote();
}

///------------------------------------------------------------------------------------------------------------------///

class Biblioteca {
private:
    char* carti = new char[40];
    int numarCarti = 0;
protected:
public:
    /// Constructor
    Biblioteca(const char* cartiInitiale = nullptr, int nrCarti = 0) {
        if (cartiInitiale != nullptr) {
            for (int i = 0; i < nrCarti; i++) {
                carti[i] = cartiInitiale[i];
            }
        } else {
            for (int i = 0; i < nrCarti; i++) {
                carti[i] = 0;
            }
        }
    }
    /// Destructor
    ~Biblioteca() {
        cout << "Cartea 's-a dus'!" << endl;
        delete [] carti;
    }

    void adaugaCarte(const char* numeCarte = nullptr) {
        numarCarti += 1;
        if (numeCarte != nullptr) {
            strcpy(carti[numarCarti], numeCarte);
        }
        i = 0;
        cout << "Pana acum avem cartile: " << endl;
        while (carti[i] != nullptr) {
            cout << carti[i] << endl;
            i++;
        }
    }
};

void clasa_biblioteca_cu_array_alocat_dinamic() {
    /// Conține un vector de cărți alocat dinamic și o metodă adaugaCarte().
    /// Destructor care eliberează memoria.
    char primeleCarti[2][40] = ["In tara luminii", "Cu Dumnezeu in subterana"]
    Biblioteca b1(primeleCarti, 2);
    b1.adaugaCarte();
    b1.adaugaCarte("Saptezeci de ori cate sapte");
}

/// Etapa 3: Encapsulare și Getteri/Setteri

void clasa_cont_bancar() {
    /// Atribute private: titular, sold.
    /// Metode depunere(float), retrage(float), afiseazaSold().
    /// Getteri și setteri pentru titular.
}

///------------------------------------------------------------------------------------------------------------------///

void clasa_telefon() {
    /// Atribute private: brand, pret.
    /// Metode pentru modificarea prețului și afișarea detaliilor.
}

/// Etapa 4: Relații între clase (Compoziție, Agregare, Moștenire)

void clasa_animal_si_mostenire() {
    /// Clasa Animal cu atribut nume.
    /// Clasa Caine derivată din Animal, care adaugă un atribut rasa.
    /// Suprascrie metoda afisare().
}

///------------------------------------------------------------------------------------------------------------------///

void clasa_care_si_biblioteca_compozitie() {
    /// Carte are titlu, autor.
    /// Biblioteca conține un vector de Carte.
}

///------------------------------------------------------------------------------------------------------------------///

/// Functia main. Comenteaza/decomenteaza functiile care te intereseaza!

///------------------------------------------------------------------------------------------------------------------///

int main() {
    // definirea_unei_clase_persoana();
    // clasa_masina();
    // implementarea_unei_clase_student_cu_memoria_alocata_dinamic();
    clasa_biblioteca_cu_array_alocat_dinamic();

    return 0;
}
