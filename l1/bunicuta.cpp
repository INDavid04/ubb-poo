#include <iostream>
#include <cstring>
using namespace std;

// TODO: error: invalid use of array with unspecified bounds
// struct Prajitura {
//     int dimensiune_baza;
//     int dimensiune_inaltime;
//     char forma[];
// };
// int main() {
//     Prajitura p;
//     p.forma = "patrat";
//     p.dimensiune_baza = 4;
//     p.dimensiune_inaltime = 5;
//     cout << p.forma << " " << p.dimensiune_baza << " " << p.dimensiune_inaltime << endl;
//     return 0;
// }

int main() {
    // Folosim urmatoarea conventie (nota: nu era necesar): 
    // 1 = cerc
    // 2 = dreptunghi
    // 3 = patrat
    // 4 = triunghi
    double p[10][2]; // p = prajitura, salvam doar volumul si aria suprafetei (acel 2, doua coloane: prima retine volumul si a doua retine aria suprafetei)
    k = 0;
    bool conditie = true;
    // Varianta muncitoreasca, intrucat nu mi-a mers ceva la struct
    char comanda[10];
    const comanda_STOP[10] = "STOP";
    const comanda_ADD[10] = "ADD";
    const comanda_TOTAL[10] = "TOTAL";
    const comanda_REMOVE[10] = "REMOVE";
    const add_cerc[10] = "cerc";
    const add_dreptunghi[10] = "dreptunghi";
    const add_patrat[10] = "patrat";
    const add_triunghi[10] = "triughi";
    char add_forma[10];
    const pi = 3.14;
    int dimensiune_baza;
    int dimensiune_inaltime;
    do {
        cin >> comanda;
        conditie = false;
        for (int i = 0; i < strlen(comanda); i++) {
            if (comanda[i] != comanda_STOP[i]) {
                conditie = true;
            }
        }
        if (conditie) {
            bool eADD = true, eTOTAL = true, eREMOVE = true;
            for (int i = 0; i < strlen(comanda); i++) {
                if (comanda[i] != comanda_ADD[i]) {
                    eADD = false;
                }
                if (comanda[i] != comanda_TOTAL[i]) {
                    eTOTAL = false;
                }
                if (comanda[i] != comanda_REMOVE[i]) {
                    eREMOVE = false;
                }
            }
            if (eADD) {
                cin >> add_forma;
                cin >> add_dimensiune_baza >> add_dimensiune_inaltime;
                bool eCerc = true, ePatrat = true, eDreptunghi = true, eTriughi = true;
                for (int i = 0; i < strlen(add_forma); i++) {
                    if (add_forma[i] != add_cerc[i]) {
                        eCerc = false;
                    }
                    if (add_forma[i] != add_patrat[i]) {
                        ePatrat = false;
                    }
                    if (add_forma[i] != add_dreptunghi[i]) {
                        eDreptunghi = false;
                    }
                    if (add_forma[i] != add_triunghi[i]) {
                        eTriughi = false;
                    }
                }
                if (eCerc) {
                    k++; // nu folosim prima pozitie, deoarece numerotarea incepe de la 1
                    p[k][0] = pi * // fara timp ... 
                }
            }
        }
    } while (conditie);
}