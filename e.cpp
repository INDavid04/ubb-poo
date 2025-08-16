#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Functie care verifica apartenta unei valori intr-un vector
void cauta(vector<int> numere, int valoare) {
    if (find(numere.begin(), numere.end(), valoare) != numere.end()) {
        cout << "Am gasit " << valoare << "\n";
    } else {
        cout << "Nu am gasit " << valoare << "\n";
    }
}

int main() {
    vector<int> numere = {1, 2, 3, 4};

    /// 1. Cauta o valoare intr-un vector
    cauta(numere, 0);
    cauta(numere, 1);
    cauta(numere, 2);
    cauta(numere, 3);
    cauta(numere, 4);
    cauta(numere, 5);

    /// 2. Modifica 3 in 33 daca 3 se afla in vector
    auto it = find(numere.begin(), numere.end(), 3);
    if (it != numere.end()) {
        *it = 33;
    }

    /// 3. Afiseaza vectorul
    for (auto numar : numere) {
        cout << numar << " ";
    }
    cout << "\n";
    
    return 0;
}
