#include <iostream>

using namespace std;

/******* obiecte globale statice **********/
class Test
{
    int x;
public:
    Test(int x=0): x(x){cout<<x<<" C\n";}
    ~Test(){cout<<x<<" D\n";}
    void f() { static Test obiect; cout<<&obiect<<endl; }
};

Test C(4);
static Test A(2), B(3);
Test D(5);

int main()
{
    Test obiect1(1);
    cout<<"start"<<'\n';
    obiect1.f();
    obiect1.f();
    cout<<"end"<<'\n';
}

/*
class Test{ int a;
public:
    Test(int x = 0):a(x){cout<<"C "<<a<<endl;}
    ~Test(){cout<<"D "<<a<<endl;}
};

void f(int i){ static Test obiect(i); cout<<&obiect<<endl;}

int main()
{
    cout<<"start"<<'\n';
    f(1);
    f(2);
    f(3);
    cout<<"end"<<'\n';
}
*/
/*** variabile statice ***/
/*
class Test
{
    int x;
    static int nr;
    static const int y;
public:
    Test(int x=10): x(x){nr++;cout<<nr<<" C\n";}
    static void afisNr()
    {
        cout<<nr<<'\n';
    }
};

int Test::nr;
int main()
{
    Test obiect1(11);
    Test obiect2(12);
    Test obiect3(13);
    obiect1.afisNr();
    obiect2.afisNr();
    obiect3.afisNr();
    Test::afisNr();
}
*/
/*** obiectele statice se distrug ultimele ***/
/*
class Test
{
    int x;
public:
    Test(int x=0): x(x){cout<<x<<" C\n";}
    ~Test(){cout<<x<<" D\n";}
    void f()
    {
        static Test obiect; cout<<&obiect<<endl;
    }
};

int main()
{
    Test obiect1(1);
    cout<<"start"<<'\n';
    obiect1.f();
    obiect1.f();
    cout<<"end"<<'\n';
}
*/
/*** afiseaza start C end D ***/
/*
class Test
{
public:
    Test(){cout<<"C\n";}
    ~Test(){cout<<"D\n";}
};

void f()
{
    static Test obiect;
}

int main()
{
    cout<<"start"<<'\n';
    f();
    cout<<"end"<<'\n';
}
*/

/*class Test{ int a;
public:
    Test(int x = 0):a(x){cout<<"C "<<a<<endl;}
    ~Test(){cout<<"D "<<a<<endl;}
};

void f(int i){ static Test obiect(i); }

int main(){
    cout<<"start"<<'\n';
    f(1);
    cout<<"end"<<'\n';
}
*/

/*
void f()
{
    static int x = 56; /// nu se dezaloca de fiecare data
    ///x = 56;
    x++;
    cout<<&x<<" "<<x<<'\n';
}

int main()
{
    f();
    f();
    f();
    return 0;
}
*/
