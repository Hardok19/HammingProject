#ifndef HAMMINGDECODER_H
#define HAMMINGDECODER_H

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class HammingDecoder {
private:
    // Encuentra el número de bits de paridad necesarios y la longitud original de los datos
    pair<int, int> findParityAndDataSize(int datos_size);

    // Genera un vector booleano para identificar posiciones de bits de paridad
    vector<bool> generateParityMask(int datos_size, int p);

    // Calcula las posiciones involucradas en cada bit de paridad
    vector<vector<int>> computeParityPositions(const vector<bool>& datos, int p);

    // Calcula la paridad de un conjunto de bits
    static bool calcularParidad(const vector<bool>& bits);
public:
    vector<bool> fixAndDecode(vector<bool> datos, bool evenParity);
};







#endif //HAMMINGDECODER_H
