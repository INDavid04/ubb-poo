/// Laborator #2 - Referințe, funcții (supraîncărcare) și transmitere parametrii, keyword-ul const.
/// TODO: continue from line 141

#include <iostream>
using namespace std;

int f1(int x) {
    return x;
}

int f1(int x, int y) {
    return x + y;
}

// ASA NU -> SUPRAINCARCARE (GENEREAZA AMBIGUITATI, din cauza ca *x este la fel cu x[])
/*
int f2(int *x) {
    return *x;
}

int f2(int x[]) {
    return x[0];
}
*/

int f3(int &x) {
    return x; // i.e. valoarea de la adresa x
}

int f3(int x) {
    return x; // i.e. valoarea x
}

/// Parametrii impliciti <=> parametrii optionali. Intotdeauna, parametrii impliciti intr-o functie se vor pune de la dreapta spre stanga

void salut(const char* name = "anonim") {
    cout << "Salut, " << name << "!" << endl;
}

// definire ilegala de functie cu parametrii impliciti
/*
void f(int x, int y = 1, int z) {

}
*/
/**
Adaugarea parametrilor impliciti intr-o functie pot genera ambiguitati
la suprascrierea functiilor
**/
void f(int x, int y = 1) {
    cout << x << ' ' << y << endl;
}

void f(int x) {
    cout << x << endl;
}

/**
Transmiterea parametrilor
-> prin valoare: se foloseste o "copie" a variabilei originale
-> prin referinta: se foloseste o variabila deja definita in spatiul de memorie
-> prin pointer: se foloseste o adresa de memorie deja existenta pentru a referentia o variabila

"copie" -> se creaza o stiva temporara pentru functia g
unde se aloca memorie pentru toti parametrii care sunt trimis prin valoare
si se copiaza valoarea acestora

diferenta dintre tip si tip& in lista parametrilor este
EFICIENTIZAREA MEMORIEI

deoarece pentru tip se construieste in buffer-ul (zona tampon de memorie) functiei
un nou spatiu de memorie in care se populeaza valoarea variabilei initiale

pentru tip& folosim deja o variabila alocata in memorie
**/
int g(const int x) {
    cout << &x << endl;
    return x;
}

int gReferinta(const int& x) {
    cout << &x << endl;
    return x;
}

int gPointer(int* x) {
    cout << x << endl;
    //*x = 30;
    return *x;
}

/**
Returnarea rezultatelor
- prin valoare
- prin referinta
- prin pointer
**/
int h(int x) {
    return x;
}

int& hReferinta(int& x) {
    return x;
}

int* hPointerRef(int& x) {
    return &x;
}

int* hPointerPointer(int* x) {
    return x;
}

void suma(int a, int b = 12); /// prototip

char s[80] = "Hello there\n";
char &replace(int i) {
    return s[i];
}

int main() {
    replace(5) = 'X';
    cout << s;

    double x10 = 100.1, y10;
    int *p10 = (int *)&x10;
    y10 = *p10;
    printf("%f", y10);
    cout << endl;

    const char sir[10] = "ana";
    // strcpy(sir, "bela"); /// E.C.
    cout << sir << endl;

    const int c = 100;
    // int*v = &c; /// E.C.
    // cout << v << endl;

    int variabiluta = 5;
    int *pointerut = &variabiluta;
    cout << pointerut << " " << *pointerut << endl;
    pointerut++;
    cout << pointerut << " " << *pointerut << endl;
    pointerut+7; /// TODO: ce face asta? `pointerut+7;`
    cout << pointerut << " " << *pointerut << endl;
    pointerut-4;
    cout << pointerut << " " << *pointerut << endl;
    
    cout << f3(0x87) << endl;
    cout << "Valoarea de la adresa 0x87 este " << f3(0x87) << endl; /// se apeleaza f3(int &x)
    cout << "Valoarea 87 este " << f3(87) << endl; /// se apeleaza f3(int x)

    salut();
    salut("Max");

    int x = 32;
    int &y = x; // op. de referentiere
    cout << "x = " << x << " and &x = " << &x << endl;
    cout << "y = " << y << " and &y = " << &y << endl;
    y = 42;
    cout << x << endl;
    // int &y1 = *x; // EC x nu este de tip int * (pointer la int) deci nu am cum sa ii extrag valoare
    // int &y2 = &x; // EC x este de tip int, dar &x nu este int, ci o adresa de memorie

    int n = 1;
    int *p = &n;
    int **pp = &p;
    cout << "(n, p, pp) = (" << n << ", " << p << ", " << pp << ")\n(&n, &p, &&pp) = " << &n << ", " << &p << ", " << &pp << ")\n";
    **pp = 5;
    cout << n << ' ' << *p << ' ' << **pp << endl;

    suma(10);
    suma(10, 10);

    const int x5 = 30;
    // x5 = 50; // EC nu merge sa reatribuim constante

    int x6 = 10, y6 = 30;
    const int *p1 = &x6; // Avem un pointer catre o constanta de tip integer
    // *p1 = 30; // EC deoarece p1 pointeaza catre o constanta de tip integer
    p1 = &y6; // putem modifica adresa catre care pointeaza deoarece nu este un pointer constant

    int * const p2 = &x6; // Pointer constant
    *p2 = 55; // putem modifica valoarea unde pointeaza p2
    // p2 = &y6; // EC deoarece p2 este un pointer constant ce nu poate sa isi schimbe variabila catre ca pointeaza

    const int * const p3 = &x6; // Pointer constant care pointeaza catre un integer constant
    // p3 = &y6; // EC deoarece pointerul este constant
    // *p3 = 55; // EC deoarece pointerul indica catre un const int

    /**
    Supraincarcarea functiilor (overloading)

    reprezinta un concept de baza pentru C++ in care
    putem defini o functie cu ACLEASI NUME, dar cu semnaturi diferite

    semnatura unei functii:
    antetul unei functii: <tip_returnat> nume(lista_parametrii)

    Ce se intampla in unele cazuri?
    AMBIGUITATI.
    **/
    // int fx = 25;
    // f3(fx);

    int a = 35;
    cout << &a << endl;
    // g(a);
    gReferinta(a);
    cout << a << endl;

    int *pG = &a;
    gPointer(pG);
    cout << pG << endl;
    cout << a << endl;

    /*int *pAlocatDinamic = new int(32);
    gPointer(pAlocatDinamic);
    delete pAlocatDinamic;

    int *pVectorAlocatDinamic = new int[32];
    gPointer(pVectorAlocatDinamic);
    delete[] pAlocatDinamic;*/

    int result = hReferinta(a);
    hReferinta(a) = 7232;
    cout << a << endl;

    int *hresult = hPointerRef(a);
    *hPointerRef(a) = 320932;
    cout << a << endl;

    int * hresultPointer = hPointerPointer(&a);
    *hresultPointer = 329582;
    cout << a << endl;

    return 0;
}
 
void suma(int a, int b) {
    cout << a + b << endl;
    /// Nu mai e nevoie sa scriem si aici b = 12 deoarece am scris deja in prototip
}
