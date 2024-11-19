
#ifndef HAMMING_H
#define HAMMING_H

#include <vector>
using namespace std;

class Hamming {
private:
    //Encuentra P
    static int Pfinder(int m);
    //Encuentra donde están los bits de paridad
    static vector<int> parityposition(int p);
    //matriz con los bits de paridad y sus respectivos bits "objetivo"
    static vector<vector<int>> precomputeParityPositions(int p, int dataSize);
    //Establece el valor de los bits de paridad
    static int generateParityBitREAL(const vector<bool>& datos, const vector<int>& positions, bool evenParity);
    //crea el especio para los bits de paridad en 0 inicialmente
    static vector<bool> setparity(const vector<int>& parityPos, const vector<bool>& datos);
public:
    //función general que hace cada paso
    static vector<bool> generateHammingCode(const vector<bool>& datos, bool evenParity = true);
    //Imprime un vector de bits
    static void printHammingCode(const vector<bool>& code);
};





#endif //HAMMING_H
