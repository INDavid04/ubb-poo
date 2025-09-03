#include <iostream>
template <class T, class U>
T f(T x, U y)
{
    return x + y;
}
int f(int x, int y)
{
    return x - y;
}
int main()
{
    int *a = new int(3), b(23);
    std::cout << *f(a, b); /// -20
    return 0;
}