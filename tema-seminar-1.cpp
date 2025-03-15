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

class Stiva {
private:
    int dim;
    float* el = new float[dim];
protected:
public:
    Stiva(int initialDim = 0, float* initialEl = nullptr) {
        dim = initialDim;
        if (initialEl != nullptr) {
            for (int i = 0; i < dim; i++) {
                el[i] = initialEl[i];
            }
        }
    }
    ~Stiva() {
        delete [] el;
        cout << "Done stack!" << endl;
    }
    void addElement(float added_element = 0) {
        dim++;
        el[dim - 1] = added_element;
    }
    float removeElement(float removed_element = 0) {
        bool is_in_stack = false;
        for (int i = 0; i < dim; i ++) {
            if (el[i] == removed_element) {
                is_in_stack = true;
                dim--;
                for (int j = i; j < dim; j++) {
                    el[j] = el[j + 1];
                }
            }
        }
        if (is_in_stack) {
            return removed_element;
        } else {
            cout << "Sorry! No " << removed_element << " in the stack!\n";
            return 0;
        }
    }
    void show() {
        cout << "Stack: ";
        for (int i = 0; i < dim; i++) {
            cout << el[i] << " ";
        }
        cout << "\n";
    }
};

void testeaza_clasa_stiva() {
    /// TODO: fix this -> terminate called after throwing an instance of 'std::bad_array_new_length'
  what():  std::bad_array_new_length
    float arr[] {4.9, 8.3, 4.5, 9.0}; // se poate si fara egal
    Stiva s1(4, arr);
    s1.show(); /// initial stack
    s1.addElement();
    s1.show(); /// add zero
    s1.addElement(7);
    s1.show(); /// add seven
    cout << "Removed element is " << s1.removeElement() << endl;
    s1.show(); /// remove 0
    cout << "Removed element is " << s1.removeElement(8.3) << endl;
    s1.show(); /// remove 8.3
    cout << "Removed element is " << s1.removeElement(987) << endl;
    s1.show(); /// 987 not in stack
}

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

/// DONE (Aside, sursa: chatgpt):

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
    char** carti;  // Pointer la un array de string-uri
    int numarCarti;

public:
    /// Constructor
    Biblioteca(const char* cartiInitiale[] = nullptr, int nrCarti = 0) {
        numarCarti = nrCarti;
        carti = new char*[numarCarti]; // Alocare pentru pointeri către string-uri

        for (int i = 0; i < numarCarti; i++) {
            carti[i] = new char[strlen(cartiInitiale[i]) + 1]; // Alocare memorie pentru fiecare carte
            strcpy(carti[i], cartiInitiale[i]);
        }
    }

    /// Destructor
    ~Biblioteca() {
        for (int i = 0; i < numarCarti; i++) {
            delete[] carti[i]; // Eliberăm fiecare string
        }
        delete[] carti; // Eliberăm array-ul de pointeri

        cout << "Biblioteca s-a inchis!" << endl;
    }

    /// Metoda pentru adăugarea unei cărți
    void adaugaCarte(const char* numeCarte) {
        char** temp = new char*[numarCarti + 1]; // Alocăm memorie pentru un array mai mare
        for (int i = 0; i < numarCarti; i++) {
            temp[i] = carti[i]; // Copiem cărțile existente
        }

        // Alocăm memorie pentru noua carte
        temp[numarCarti] = new char[strlen(numeCarte) + 1];
        strcpy(temp[numarCarti], numeCarte);

        delete[] carti; // Eliberăm vechiul array
        carti = temp;
        numarCarti++;

        // Afișăm cărțile actualizate
        cout << "Cartile din biblioteca:\n";
        for (int i = 0; i < numarCarti; i++) {
            cout << carti[i] << endl;
        }
    }
};

void clasa_biblioteca_cu_array_alocat_dinamic() {
    /// Testăm constructorul și metoda `adaugaCarte()`
    const char* primeleCarti[] = {"In tara luminii", "Cu Dumnezeu in subterana"};
    Biblioteca b1(primeleCarti, 2);
    
    b1.adaugaCarte("Saptezeci de ori cate sapte");
    b1.adaugaCarte("Codul bunelor maniere");
}

///------------------------------------------------------------------------------------------------------------------///

/// Etapa 3: Encapsulare și Getteri/Setteri

class ContBancar {
private:
    char titular[40];
    float sold;
protected:
public:
    /// Constructor
    ContBancar(const char* titularDefault = "John Doe", float soldDefault = 0) {
        strcpy(titular, titularDefault);
        sold = soldDefault;
    }

    /// Destructor
    ~ContBancar() {
        cout << "Persoana " << titular << " a iesit de sub evidenta bancii.\n";
    }

    /// Getter
    const char* getTitular() const {
        return titular;
    }

    /// Setter
    void setTitular(const char* noulTitular = "Hannah Smith") {
        strcpy(titular, noulTitular);
    }

    void depunere(float sumaDepusa = 0) {
        sold += sumaDepusa;
    }

    void retrage(float sumaRetrasa = 0) {
        if (sold < sumaRetrasa) {
            cout << "Ne pare rau insa nu ai fonduri suficiente pentru a retrage suma " << sumaRetrasa << endl;
        } else {
            sold -= sumaRetrasa;
        }
    }

    void afiseazaSold() {
        cout << "Titularul " << titular << " are soldul: " << sold << endl;
    }
};

void clasa_cont_bancar() {
    /// Atribute private: titular, sold.
    /// Metode depunere(float), retrage(float), afiseazaSold().
    /// Getteri și setteri pentru titular.
    ContBancar c1;
    c1.afiseazaSold();
    c1.depunere(50.5);
    c1.afiseazaSold();
    c1.retrage(100);
    c1.afiseazaSold();
    cout << "Primul titular este " << c1.getTitular() << endl;
    c1.setTitular("Hannah Montana");
    cout << "Cel de al doilea titular este " << c1.getTitular() << endl;
    c1.setTitular();
    cout << "Si cel de al treilea titular este " << c1.getTitular() << endl;
}

///------------------------------------------------------------------------------------------------------------------///

class Phone {
private:
    char brand[40];
    float price;
protected:
public:
    Phone(const char* defaultBrand = "iPhone", float defaultPrice = 9999.99) {
        strcpy(brand, defaultBrand);
        price = defaultPrice;
    }
    ~Phone() {
        cout << "Broken phone " << brand << " at price " << price << endl;
    }
    void setPrice(float newPrice = 3980.98) {
        if (newPrice > 0) {
            price = newPrice;
        }
    }
    void showDetails() const {
        cout << "The phone " << brand << " is at price " << price << endl;
    }
};

void clasa_telefon() {
    /// Atribute private: brand, pret.
    /// Metode pentru modificarea prețului și afișarea detaliilor.
    Phone p1("Samsung A70", 1704.98);
    p1.showDetails();
    p1.setPrice(2849.89);
    p1.showDetails();
}

///------------------------------------------------------------------------------------------------------------------///

/// Etapa 4: Relații între clase (Compoziție, Agregare, Moștenire)

class Animal {
private:
protected:
    char name[40];
public:
    Animal(const char* defaultName = "Cat") {
        strcpy(name, defaultName);
    }
    virtual ~Animal() {
        cout << "Animal " << name << " is out of the view.\n";
    }
    virtual void show() const {
        cout << "The animal is a " << name << endl;
    }
};

class Dog : public Animal {
private:
    char race[40];
protected:
public:
    Dog(const char* defaultName = "Max", const char* defaultRace = "Labrador") {
        strcpy(name, defaultName);
        strcpy(race, defaultRace);
    }
    ~Dog() {
        cout << "The animal " << name << " with race " << race << " is now out of the view\n";
    }
    void show() const override {
        cout << "The animal is named " << name << " and has the race " << race << endl;
    }
};

void clasa_animal_si_mostenire() {
    /// Clasa Animal cu atribut nume.
    /// Clasa Caine derivată din Animal, care adaugă un atribut rasa.
    /// Suprascrie metoda afisare().
    Animal a1("crocodile");
    a1.show();
    Animal a2;
    a2.show();
    Dog d1("Pablo", "husky");
    d1.show();
}

///------------------------------------------------------------------------------------------------------------------///

class Book {
private:
    char title[80];
    char author[40];
protected:
public:
    Book(const char* defaultTitle = "Believer's journey", const char* defaultAuthor = "John Bunyan") {
        strcpy(title, defaultTitle);
        strcpy(author, defaultAuthor);
    }
    ~Book() {
        cout << "The book " << title << " by " << author << " is now out of the library.\n";
    }
    void show() {
        cout << "The book " << title << " is written by " << author << endl;
    }
};

class Library {
private:
    /// Merge mai bine cu STL, asadar mai astept pana invatam STL la clasa
    /// TODO: come here to continue after STL lesson;
protected:
public:
};

void clasa_carte_si_biblioteca_compozitie() {
    /// Carte are titlu, autor.
    /// Biblioteca conține un vector de Carte.
    Book b1;
    b1.show();
}

///------------------------------------------------------------------------------------------------------------------///

/// Functia main. Comenteaza/decomenteaza functiile care te intereseaza!

///------------------------------------------------------------------------------------------------------------------///

int main() {
    // definirea_unei_clase_persoana();
    // clasa_masina();
    // implementarea_unei_clase_student_cu_memoria_alocata_dinamic();
    // clasa_biblioteca_cu_array_alocat_dinamic();
    // clasa_cont_bancar();
    // clasa_telefon();
    // clasa_animal_si_mostenire();
    // clasa_carte_si_biblioteca_compozitie();
    testeaza_clasa_stiva();

    return 0;
}
