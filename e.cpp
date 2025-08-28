#include <iostream>

using namespace std;

void f(int x) { x = x *2; } /// prin valoare
void g(int *x) { *x = *x + 30; } ///  prin pointer
void h(int &x) { x = x + 50; } /// prin referinta

int main() {
    int x = 10;
    f(x);
    cout<<"x = "<<x<<endl; /// 10
    g(&x);
    cout<<"x = "<<x<<endl; /// 40
    h(x);
    cout<<"x = "<<x<<endl; /// 90
    
    return 0;
}
