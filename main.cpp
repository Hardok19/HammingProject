#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "pruebas.h"
#include "hamming.h"




using namespace std;
using namespace __bitset;





int main() {
    list<string> texto = intputfile();
    vector<string> texto2 = strToBinary(texto.back());

    int even  = generateParityBitREAL(texto.front(), true);
    int odd  = generateParityBitREAL(texto.front(), false);


    cout << "Even Parity Bit: " << even << endl;
    cout << "Odd Parity Bit: " << odd << endl;


    outputfile(texto.back());

    cout << Pfinder(4) << endl;
    vector<int> A = parityposition(Pfinder(4));

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }


    string datos = "10101010011101010101011010101010101111110111";
    int datosize  = texto2.back().size();
    std::vector<bool> bits(datosize);
    vector<string> a = {" "};

    // Llenar el vector con los bits de datos
    for (int i = 0; i < datosize; ++i) {
        bits[i] = (texto2.back()[i] == '1');
    }

    // Imprimir el vector de bits
    for (bool bit : bits) {std::cout << bit;}
    std::cout << std::endl;

    //main1();

    vector<int> b = parityposition(Pfinder(4));


    cout << setparity(b, "0110", Pfinder(4)) << std::endl;
    calculatorsparity(b, Pfinder(4));





    return 0;
}


