/************************ Mostenire, "virtual", late binding, etc. *******************/
#include <iostream>

using namespace std;

/********* supraincarcarea functiilor statice - 2 completari **************/
/*
class Baza
{
public:
    void f(){cout<<"f din baza, nestatic\n";}
};

class Derivata : public Baza{
public:
    static void f(){cout<<"f din derivata, nestatic\n";}
///    static void f(int x){cout<<"f din derivata, nestatic\n";}
};

int main()
{
    Derivata ob;
    ob.f(); /// functia din derivata ascunde pe cea din baza, chiar daca e static in baza sau derivata
///    Derivata::f(1);
    return 0;
}
*/

/*
class Baza
{
public:
    void afis(){cout<<"nestatic in baza\n";}
    /// static void afis(){cout<<"static in baza";} /// nu pot avea, in aceeasi clasa, nestatic supraincarcat cu static si viceversa
};

class Derivata : public Baza{
public:
    static void afis(){cout<<"static in derivata\n";}
};

class Derivata2 : public Derivata{
public:
    static void afis(int x){cout<<"static in derivata 2\n";}
};

int main()
{
    Baza A;
    A.afis();

    Derivata B;
    B.afis();
    Derivata::afis();
    B.Baza::afis();

    Derivata2 C;
///    C.afis();/// nu exista in derivata 2 si cea din derivata e ascunsa
    Derivata2::afis(10);
}
*/

/**** mostenire (din baza) multipla - cateva observatii ****/
/*
class universitate
{
public:
    void afis(){cout<<"universitatea ";}
};

class oras
{
public:
    void afis(){cout<<"din Bucuresti";}
};

class unibuc : public universitate, public oras
{

};

int main()
{
    unibuc ob;
    ob.afis(); /// ambiguitate - necesita rescrierea functiei, sau apel explicit ob.universitate::afis();
}
*/

/******** "cati" vptr in MM ***********/
/*
class Baza1
{
public:
    virtual void f1(){cout<<"Baza1_f1\n";}
    virtual void f2(){cout<<"Baza1_f2\n";}
    virtual void f3(){cout<<"Baza1_f3\n";}
};

class Baza2
{
public:
    void f1(){cout<<"Baza2_f1\n";}
    virtual void f2(){cout<<"Baza2_f2\n";}
};

class Derivata: public Baza1, public Baza2
{
public:
    void f1(){cout<<"Derivata_f1\n";}
    void f2(){cout<<"Derivata_f2\n";}
};

int main()
{
    cout<<sizeof(Baza1)<<" "<<sizeof(Baza2)<<" "<<sizeof(Derivata)<<endl;
    Baza2* p = new Derivata();
    p->f1();
    p->f2();
}
*/

/**** problema diamantului - transmiterea constructorilor ****/
/*
class interfata
{
public:
    interfata(){cout<<"constructor interfata\n";}
    interfata(int x){cout<<x<<" constructor interfata\n";}
    void afis(){cout<<"interfata\n";}
};

class universitate : virtual public interfata{
public:
    universitate(){cout<<"constructor universitate\n";}
    universitate(int x):interfata(x){cout<<x<<" constructor universitate\n";}
    void afis(){cout<<"universitatea ";}
};

class oras : virtual public interfata{
public:
    oras(){cout<<"constructor oras\n";}
    oras(int x):interfata(x){cout<<x<<" constructor oras\n";}
    void afis(){cout<<"din Bucuresti";}
};

class unibuc : public universitate,public oras
{
public:
    unibuc(){cout<<"constructor unibuc\n";}
   /// unibuc(int x):universitate(x),oras(x){cout<<x<<" constructor unibuc\n";} ///atentie, nu se trimite corect catre baza
    unibuc(int x):interfata(x){}
    };

int main()
{
///    unibuc ob;
///    ob.afis(); /// ambiguitate - necesita rescrierea functiei, sau apel explicit ob.universitate::afis();
    cout<<"*****\n";
    unibuc ob2(10); /// nu e suficienta lista de init constr doar la parinti
}
*/

/********* mostenire virtuala - diamant mai complicat *************/
/*
class Baza
{
public:
    Baza(){cout<<"Baza\n";}
};

class Baza2
{
public:
    Baza2(){cout<<"Baza2\n";}
};

class Derivata1 : public Baza
{
public:
    Derivata1(){cout<<"Derivata1\n";}
};

class Derivata2 : public Baza
{
public:
    Derivata2(){cout<<"Derivata2\n";}
};

class Derivata3 : virtual public Baza
{
public:
    Derivata3(){cout<<"Derivata3\n";}
};

class Derivata4 : public Baza
{
public:
    Derivata4(){cout<<"Derivata4\n";}
};

class Derivata5 : public Derivata1, Derivata2, protected Derivata3, public Derivata4
/// class Derivata5 : public Derivata1, protected Derivata3
{
public:
    Derivata5(){cout<<"Derivata5\n";}
};

int main()
{
    Derivata5 ob;  /// virtual prioritizeaza baza
}*/

/*
class Baza
{
public:
    Baza(){cout<<"Baza\n";}
};

class Baza2
{
public:
    Baza2(){cout<<"Baza2\n";}
};

class Derivata1 : virtual public Baza
{
public:
    Derivata1(){cout<<"Derivata1\n";}
};

class Derivata2 : public Baza2
{
public:
    Derivata2(){cout<<"Derivata2\n";}
};

///class Derivata5 : public Derivata1, Derivata2, protected Derivata3, public Derivata4
class Derivata5 : public Derivata2, public Derivata1
{
public:
    Derivata5(){cout<<"Derivata5\n";}  /// afis B1, B2, D2, D1, D5 pt ca mostenirea D1 este virtual
};

int main()
{
    Derivata5 ob;  /// virtual (oriunde in ierarhie) => prioritate la construire
 }

*/

/******** functii virtuale ***********/
/**** "dovada" existentei/adaugarii pointerului vptr ****/
/*
class Baza{
 //   int a;
 //   char b,c,d,e,h;
 //   long long i;
 // string z;
public:
    virtual void f(){}
    virtual int g(){return 1;}
};

class Derivata : public Baza{
public:
    virtual void h(){
    }
    void f(){
    }
};

int main()
{
    cout<<sizeof(Baza) << ' '<<sizeof(Derivata); /// dimenziunea clasei creste cu o dimensiune fixa, indiferent cate functii virtuale exista
}*/

/*******  ce se intampla cu functiile virtuale in contextul mostenirii in diamant? *****/
/*
class Interfata
{
public:
    virtual void f2(){}
};

class Baza1 : virtual public Interfata
{
public:
    virtual void f1(){cout<<"Baza1_f1\n";}
    virtual void f2(){cout<<"Baza1_f2\n";}
    virtual void f3(){cout<<"Baza1_f3\n";}
};

class Baza2: virtual public Interfata
{
public:
    void f1(){cout<<"Baza2_f1\n";}
    virtual void f2(){cout<<"Baza2_f2\n";}
};

class Derivata: public Baza1, public Baza2
{
public:
    void f1(){cout<<"Derivata_f1\n";}
    void f2(){cout<<"Derivata_f2\n";}
};

int main()
{
    cout<<sizeof(Baza1)<<" "<<sizeof(Baza2)<<" "<<sizeof(Derivata)<<endl;
    Interfata* p = new Derivata(); /// upcast
    p->f1();
    p->f2();
}
*/

/********** polimorfism la executie prin functii virtuale - upcasting si downcasting *********/
/****** atribuire directa de pointeri pentru upcast/downcast ? *******/
/*
class Baza
{
public:
    void f(){cout<<"Baza\n";}
};

class Derivata : public Baza
{
public:
    virtual void f(){cout<<"f rescris in Derivata\n";}
    virtual void g(){cout<<"g virtual in Derivata\n";}
    void h(){cout<<"h nevirtual in Derivata\n";}
};

int main()
{
    Derivata ob;
///    ob.f(); /// f rescris in derivata
///    ob.g();
///    ob.h();

    /// upcast prin referinta ok
    Baza& a = ob;
    a.f(); /// f rescris in derivata

    /// downcast - tentativa directa - nu merge. De ce? nu se stie exact catre ce face referire a
 ///   Derivata& b = a;

    /// idem upcast prin pointer ok
    Baza*p = &ob;

    Derivata* q;
///    q = p;  /// nu merge downcast direct nici pe pointeri

    Baza *r;
    r = q; /// upcast ok
    return 0;
}
*/

/******** upcast si ierarhii nepolimorfice ***********/
/*
class Baza
{
public:
    void f(){cout<<"Baza\n";}
};

class Derivata : public Baza
{
public:
    virtual void f(){cout<<"f rescris in Derivata\n";}
    virtual void g(){cout<<"g virtual in Derivata\n";}
    void h(){cout<<"h nevirtual in Derivata\n";}
};

int main()
{
    /// apel functii din Derivata prin obiect - ok
    Derivata ob;
///    ob.f(); /// f rescris in derivata
///    ob.g();
///    ob.h();

    /// upcast prin referinta
    Baza& a = ob;
    a.f(); /// f rescris in derivata
    /// a.g(); a.h(); /// nu pot fi apelate prin referinta catre baza, DECI TREBUIE DOWNCAST
    ((Derivata&)a).g();
    ((Derivata&)a).h();
/// nu merge pentru ierarhii nepolimorfice
///    (dynamic_cast<Derivata&>(a)).g();
///    (dynamic_cast<Derivata&>(a)).h();

    /// idem upcast prin pointer
    Baza*p = &ob;
    p->f(); /// f rescris in derivata
    /// p->g(); p->h(); /// nu pot fi apelate prin pointer catre baza
    ((Derivata*)p)->g();
    ((Derivata*)p)->h();
/// nu merge pentru ierarhii nepolimorfice
///    (dynamic_cast<Derivata*>(p))->g();
///    (dynamic_cast<Derivata*>(p))->h();

/// idem pentru upcast care sa retina adresa unui ob derivat alocat dinamic Baza*b = new Derivata();

/// Ar fi mers prin atribuire directa? NU.
    Derivata* q;
///    q = p;
///    q->f();

    Baza *r;
    r = q;
    return 0;
}
*/

/********** cand downcast-ul / dynamic_cast reuseste? *******************/
/// ATENTIE la stilul acesta de diamant si cate mosteniri virtuale e nevoie
/*
class Baza{
public:
    virtual ~Baza(){}
};

class D1 : public Baza{};
class D2 : public D1{};
class D3 : public D2{};

class D4 : public Baza{};
class D5 : virtual public D4, virtual public D3{};

int main()
{
    Baza* a = new D5();
    D1* b = dynamic_cast<D1*>(a); if (!b) cout<<"nu se poate face cast catre D1\n";
    D2* c = dynamic_cast<D2*>(a); if (c == NULL) cout<<"nu se poate face cast catre D2\n";
    D3* d = dynamic_cast<D3*>(a); if (!d) cout<<"nu se poate face cast catre D3\n";
    D4* e = dynamic_cast<D4*>(a); if (!e) cout<<"nu se poate face cast catre D4\n";
return 0;
}
*/

/*
class Baza{
public:
    virtual ~Baza(){}
};

class D1 : public Baza{};
class D2 : public D1{};
class D3 : public D2{};

class D4 : public Baza{};

int main()
{
    Baza* a = new D2();
    D1* b = dynamic_cast<D1*>(a); if (!b) cout<<"nu se poate face cast catre D1\n";
    D2* c = dynamic_cast<D2*>(a); if (c == NULL) cout<<"nu se poate face cast catre D2\n";
    D3* d = dynamic_cast<D3*>(a); if (!d) cout<<"nu se poate face cast catre D3\n";
    D4* e = dynamic_cast<D4*>(a); if (!e) cout<<"nu se poate face cast catre D4\n";
return 0;
}
*/
/*
class Baza
{
public:
    virtual void f(){cout<<"Baza\n";}
};

class Derivata : public Baza
{
public:
    virtual void f(){cout<<"f rescris in Derivata\n";}
    virtual void g(){cout<<"g virtual in Derivata\n";}
    void h(){cout<<"h nevirtual in Derivata\n";}
};

int main()
{
    /// apel functii din Derivata prin obiect - ok
    Derivata ob;
///    ob.f(); /// f rescris in derivata
///    ob.g();
///    ob.h();

    /// upcast prin referinta
    Baza& a = ob;
    a.f(); /// f rescris in derivata
    /// a.g(); a.h(); /// nu pot fi apelate prin referinta catre baza
    ((Derivata&)a).g();
    ((Derivata&)a).h();
/// sau, pentru ierarhii polimorfice
    (dynamic_cast<Derivata&>(a)).g();
    (dynamic_cast<Derivata&>(a)).h();

    /// idem upcast prin pointer
    Baza*p = &ob;
    p->f(); /// f rescris in derivata
    /// p->g(); p->h(); /// nu pot fi apelate prin pointer catre baza
    ((Derivata*)p)->g();
    ((Derivata*)p)->h();
/// sau, pentru ierarhii polimorfice
    (dynamic_cast<Derivata*>(p))->g();
    (dynamic_cast<Derivata*>(p))->h();

    return 0;
}
*/

/**** clase abstracte ****/
/*
class Persoana /// clasa abstracta (are cel putin o functie virtuala pura) / interfata
{
protected:
    string nume;
public:
    virtual void citire() = 0; /// functie virtuala pura
    virtual void afisare();
};

class Elev : public Persoana
{
    int clasa;
public:
    void citire();
    void afisare();
};

class Pensionar : public Persoana
{
public:
    void citire(){}
};

int main()
{
///    Persoana ob;
    Elev ob1;
        ob1.Persoana::citire();
/*
    Pensionar ob2;
///    cout << sizeof(Persoana) << endl; /// aparitia vptr daca virtual
    Persoana *p = new Elev();
    p->citire();
    p->afisare();
    return 0;
}

void Persoana::citire(){cout<<"Nume "; cin>>nume;}
void Persoana::afisare(){cout<<nume<<" ";}
void Elev::citire(){Persoana::citire(); cout<<"Clasa "; cin>>clasa;}
void Elev::afisare(){Persoana::afisare(); cout<<clasa<<"\n";}
*/


/// ... si cu ce ne ajuta??? ---> vector<Baza*> retine tipuri diferite de adrese de obiecte

/***** covariance exemplu *****/
/*
class Persoana
{
protected:
    string nume;
public:
    Persoana(string s = "") : nume(s){}
    virtual void citire();
    virtual void afisare();
    virtual Persoana* concatenare(){ return new Persoana(nume+="Popescu");}
};

class Elev : public Persoana
{
    int clasa;
public:
    Elev(string s="", int c=0):Persoana(s),clasa(c){}
    void citire();
    void afisare();
///    Persoana* concatenare(){ return new Elev(nume+="Popescu", clasa+=1);}
    Elev* concatenare(){ return new Elev(nume+="Popescu", clasa+=1);}   /// covarianta tipurilor
};

int main()
{
    Persoana *p = new Persoana("Ana");
    p->afisare();
    p = p->concatenare();
    p->afisare();
    cout<<"\n";
    p = new Elev("Ion",11);
    p->afisare();
    p = p->concatenare();
    p->afisare();

    Elev A("anonim",0);
    Elev *B = A.concatenare();
    B->afisare();
    return 0;
}

void Persoana::citire(){cout<<"Nume "; cin>>nume;}
void Persoana::afisare(){cout<<nume<<" ";}
void Elev::citire(){Persoana::citire(); cout<<"Clasa "; cin>>clasa;}
void Elev::afisare(){Persoana::afisare(); cout<<clasa<<"\n";}
*/

/***** destructori virtuali *****/
/*
class Persoana
{
protected:
    string nume;
public:
    Persoana(string s = "") : nume(s){cout<<"constr Persoana ";}
    virtual void citire();
    virtual void afisare();
    virtual ~Persoana(){cout<<"destr Persoana";}
};

class Elev : public Persoana
{
    int clasa;
public:
    Elev(string s="", int c=0):Persoana(s),clasa(c){cout<<" constr Elev";}
    void citire();
    void afisare();
    ~Elev(){cout<<" destr Elev";}
};

int main()
{
    Persoana* p = new Elev(); /// upcast
    delete p;
    return 0;
}

void Persoana::citire(){cout<<"Nume "; cin>>nume;}
void Persoana::afisare(){cout<<nume<<" ";}
void Elev::citire(){Persoana::citire(); cout<<"Clasa "; cin>>clasa;}
void Elev::afisare(){Persoana::afisare(); cout<<clasa<<"\n";}
*/

/**************************/
/*
class Baza
{
protected:
    string x;
public:
    virtual void citire();
    friend ostream& operator<<(ostream&, Baza&);
};

class Derivata : public Baza
{
    int y;
public:
    void citire();
    friend ostream& operator<<(ostream&, Derivata&);
};

int main()
{
    /// Baza b; b.citire(); cout<<b;
    /// Derivata d; d.citire(); cout<<d;
    Baza* p = new Derivata();
    p->citire();
    /// cout<<*p; /// cout din baza
    cout<<*(Derivata*)p;
    cout<<*dynamic_cast<Derivata*>(p);
    return 0;
}

void Baza::citire(){cin>>x;}
void Derivata::citire(){Baza::citire(); cin>>y;}
ostream& operator<<(ostream& out, Baza& ob)
{
    out<<"Baza: "<<ob.x<<endl; return out;
}

ostream& operator<<(ostream& out, Derivata& ob)
{
    /// out<<"Derivata: "<<ob.x<<" "<<ob.y<<endl; return out;
    out<<(Baza&)ob << "Derivata: "<<ob.y<<endl; return out;
}
*/

/****/
/*
class Baza
{
protected:

public:
    virtual void citire();
    virtual void afisare();
};

class Derivata1 : public Baza
{

public:
    void citire();
    void afisare();
    void f(){cout<<"Propriu\n";}
};

class Derivata2 : public Baza
{

public:
    void citire();
    void afisare();
};

class Derivata3 : public Derivata1
{
public:
    void citire();
    void afisare();
};
int main()
{
    Baza*p = new Derivata1();
    p->citire(); p->afisare();
    ///p->f();
    Derivata1* q;
    ///q = p;
    q = dynamic_cast<Derivata1*>(p);   /// necesar la downcasting
    q->f();

    /// in aceeasi ierarhie, atentie la nivelurile pe care se afla obiectele...

    Derivata3* t;
    t = dynamic_cast<Derivata3*>(p); /// downcast nereusit
    if (t == NULL) cout<<"nu merge";
    else t->afisare();

    Baza *p1;
    p1 = new Derivata3(); /// upcast
    Derivata1* q1;
    q1 = dynamic_cast<Derivata1*>(p1); ///downcast "reusit"
    q1->f();

    /// downcast nu merge daca nu sunt pe aceeasi "ramura din ierarhie"
/*
    Derivata2* t;
    t = dynamic_cast<Derivata2*>(p);
    if (t == NULL) cout<<"nu merge";
    else t->afisare();

    cout<<endl;


    Derivata2* t1;
    t1 = dynamic_cast<Derivata2*>(p);
    t1->afisare();


    Derivata2* t2;
    t2 = (Derivata2*)(p);
    t2->afisare();*/
///    return 0;
///}
/*
void Baza::citire(){cout<<"Baza ";}
void Derivata1::citire(){Baza::citire(); cout<<"si Deriv1  ";}
void Derivata2::citire(){Baza::citire(); cout<<"si Deriv2  ";}
void Derivata3::citire(){Derivata1::citire(); cout<<"si Deriv3  ";}

void Baza::afisare(){cout<<"Afis Baza ";}
void Derivata1::afisare(){Baza::afisare(); cout<<"si Deriv1\n";}
void Derivata2::afisare(){Baza::afisare(); cout<<"si Deriv2\n";}
void Derivata3::afisare(){Derivata1::afisare(); cout<<"si Deriv3\n";}
*/

/**** memory leak ***/
/*
class Baza
{
public:
    Baza(){cout<<"B\n";}
    virtual void f() = 0;
    virtual ~Baza(){cout<<"~B\n";}
};

void Baza::f(){cout<<"elemente din baza";}

class Derivata : public Baza
{
public:
    Derivata(){cout<<"D\n";}
    ~Derivata(){cout<<"~D\n";}
    void f(){  Baza::f();}
};

int main()
{
///    Baza b;
///    Derivata d;
     Baza *p;
///     p = new Baza(); /// nu delete = nu destructor = nu dezalocare = memory leak = scazut nota
///    delete p;
    p = new Derivata();
    p->f();
    delete p; /// nu se dezaloca componentele din derivata
}
*/

/***** cum rezolvam cu pointerii astia? - idee:smart pointers *****/
/*
class Persoana
{
protected:
    string nume;
public:
    Persoana(string s = "") : nume(s){}
    virtual void citire();
    virtual void afisare();
    virtual ~Persoana(){}
};

class Elev : public Persoana
{
    int clasa;
public:
    Elev(string s="", int c=0):Persoana(s),clasa(c){}
    void citire();
    void afisare();
    ~Elev(){}
};

int main()
{
    /*
    Persoana* p = new Elev();
    p->citire();
    p->afisare();
    delete p;

    shared_ptr<Persoana> p2 = make_shared<Persoana>("AAA");
    p2->afisare();

    p2 = make_shared<Elev>("BBB",5); /// upcasting
    p2->afisare();
    */
/*
    vector<Persoana*> v;
    v.push_back(new Persoana());
    v.back()->citire();
    v.push_back(new Elev());
    v.back()->citire();

    for(auto p = v.begin(); p != v.end(); p++)
        (*p)->afisare();
*/
/*    vector<shared_ptr<Persoana>> v2;
    v2.push_back(make_shared<Persoana>());
    v2.back()->citire();
    v2.push_back(make_shared<Elev>());
    v2.back()->citire();

    for(auto p = v2.begin(); p != v2.end(); p++)
        (*p)->afisare();
    return 0;
}

void Persoana::citire(){cout<<"Nume "; cin>>nume;}
void Persoana::afisare(){cout<<nume<<" ";}
void Elev::citire(){Persoana::citire(); cout<<"Clasa "; cin>>clasa;}
void Elev::afisare(){Persoana::afisare(); cout<<clasa<<"\n";}
*/