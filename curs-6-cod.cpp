#include <iostream>

using namespace std;

/******* functii virtuale ************/

class Baza
{
protected:
    int x;
public:
    virtual void f(){cout<<"baza\n";}
    virtual void f1(){cout<<"baza\n";}
    virtual void f2(){cout<<"f2 baza\n";}
    int z;
};

class Derivata : public Baza
{
    int y;
public:
    void f(){cout<<"f din derivata\n";}
    void g(){cout<<"derivata\n";}
    void f1(){cout<<"modif f1\n";}
    virtual void f3(){cout<<"f3 deriv\n";}
    virtual void f4(){cout<<"f4 deriv\n";}
};

class Derivata2 : public Derivata{
public:
    void f1(){cout<<"modif in deriv 2 f1\n";}
};

void functie(Baza ob){cout<<"functie\n";}
void functie2(Derivata ob){cout<<"alta functie\n";}

int main()
{
    Baza* p = new Derivata();
    p->f1();
    p->f2();

    Derivata* q;
    q = new Derivata2();
    q->f2();

    Derivata2 ob;
    Derivata& re = ob; /// upcasting
    re.f1();

///    cout<<sizeof(Baza)<<" "<<sizeof(Derivata)<<endl;
/*
    Baza A;
    A.f();
    /// A.g(); /// inaccesibil
    functie(A);
///    functie2(A);

    Derivata B;
    B.f();
    B.g();
    functie(B); /// "upcast" ok, de fapt, object slicing
    functie2(B);
*/
/*
    Derivata* p = new Derivata();
    p->f();
    p->g();
    p->z = 56;
*/
/*
    Baza* q = new Derivata(); /// upcast
    q->f();
    q->z = 89;
*/
///    q->g();
}

/********* mostenire in diamant ********************/
/*
class Interfata
{
public:
    void f(){cout<<"Interfata\n";}
   /// int logare;
};

///class Baza1 : virtual public Interfata
class Baza1 : virtual public Interfata
{
public:
    ///void f(){cout<<"Baza1\n";}
};

///class Baza2 : virtual public Interfata
class Baza2 : virtual public Interfata
{
public:
    ///void f(){cout<<"Baza2\n";}
};

/// class Derivata :  virtual public Baza1,  virtual public Baza2 /// efect doar de la urmatorul nivel de mostenire
class Derivata :  public Baza1,  public Baza2{
public:

};

int main()
{
    Derivata ob;
    /// ob.f(); /// ambiguitate
    /// ob.Baza1::f();
    /// ob.Baza2::f();
    /// ob.logare = 123;
    cout<<sizeof(Interfata)<<" "<<sizeof(Baza1)<<" "<<sizeof(Baza2)<<" "<<sizeof(Derivata);
}
*/

/********* mostenire din baza multipla **************/
/*
class Baza1
{
public:
    void f(){cout<<"Baza1\n";}
};

class Baza2
{
public:
    void f(){cout<<"Baza2\n";}
};

class Derivata : public Baza1, public Baza2
{
public:

};

int main()
{
    Derivata ob;
    /// ob.f(); /// ambiguitate
    ob.Baza1::f();
    ob.Baza2::f();
}
*/

/*
class Baza
{
public:
    void f(){cout<<"B\n";}
};

class D1 : private Baza{};

class D2 : public D1{};

int main()
{
    D1 ob1;
    ob1.f();
    D2 ob2;
    ob2.f();
    return 0;
}
*/

/*
class Baza
{
public:
    void f(){cout<<"B\n";}
};

class D1 : public Baza{
public:
    void f(){cout<<"D1\n";}
};

class D2 : public D1{
public:
///    void f(){cout<<"D2\n";}
    void f(int x){cout<<"D2\n";}
};

int main()
{
    Baza ob1;
    ob1.f();
    D1 ob2;
    ob2.f();
    D2 ob3;
///    ob3.f(); /// versiunile functiilor din clasele anterioare sunt ascunse pentru obiect de tip D2
    ob3.f(345);
    return 0;
}
*/
