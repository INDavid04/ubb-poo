// Seminar #1 - Tema 1 Due March 18, 2025 11:59 PM
// De implementat cele două clase Vector și Stivă de la finalul Seminarului I. Aveți seminarul atașat în canalul Seminar > Files > Seminarii > Seminarul I. Multă baftă.

# include <iostream>
using namespace std;

int main() {
    int v[] {1, 2, 3, 4};
    int i = 0;
    while(v[i] != '\0'){
        cout << v[i] << endl;
        i++;
    }
    int n = i;
    cout << "Lungimea vectorului este " << n << endl;

    return 0;
}