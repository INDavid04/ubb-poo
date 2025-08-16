#include <iostream>

using namespace std;

///////////////////
// 1. Sum of two //
///////////////////

template <typename T, typename U>
T sumOf2(T a, U b) {
    return a + (T)b;
}

/////////////////////////////
// 2. Print any parameters //
/////////////////////////////

/// Base case: no parameter
void printParams() {
    cout << "\n";
}

template <typename T, typename... Args>
void printParams(T first, Args... others) {
    cout << first << " ";
    printParams(others...);
}

///////////////////
// 3. Sum of any //
///////////////////

/// Base case
int sum() {
    return 0;
}

template <typename T, typename... Args>
T sum(T first, Args... rest) {
    return first + (T)sum(rest...);
}

int main() {
    /// 1. Sum of two
    cout << sumOf2(1, 101) << "\n"; /// 102
    cout << sumOf2(1.5, 1.4) << "\n"; /// 2.9
    cout << sumOf2(1, 2.8) << "\n"; /// 3
    cout << sumOf2(2.5, 2) << "\n\n"; /// 4.5

    /// 2. Print any parameters
    printParams(1, 2, 3, 4, 5, 'a', 'b', 'c', 1.2, 3.7, "sarmale", "cu", "smantana");
    printParams();

    /// 3. Sum of any
    cout << sum() << "\n"; /// 0
    cout << sum(1, 2, 3, 4) << "\n"; /// 10
    cout << sum(1.2, 7.8) << "\n"; /// 9
    cout << sum(1, 2.2) << "\n"; /// 3
    cout << sum(2.1, 8) << "\n"; /// 10.1
    cout << sum(1, 2.4, 9, 2.8, 1.4) << "\n"; /// 16 (2.8 + 1.4; 9 + 4.2; 2.4 + 13; 1 + 15)

    return 0;
}
