#include "hammingdecoder.h"

// Encuentra el número de bits de paridad necesarios y la longitud original de los datos
pair<int, int> HammingDecoder::findParityAndDataSize(int datos_size){
    int p = 0, m = 0;
    while (true) {
        m++;
        p = 0;
        while ((1 << p) < p + m + 1) p++;
        if (m + p == datos_size) break;
    }
    return {p, m};
}

// Genera un vector booleano para identificar posiciones de bits de paridad
vector<bool> HammingDecoder::generateParityMask(int datos_size, int p){
    vector<bool> isParity(datos_size, false);
    for (int i = 0; i < p; ++i) {
        isParity[(1 << i) - 1] = true;
    }
    return isParity;
}



// Calcula las posiciones involucradas en cada bit de paridad
vector<vector<int>> HammingDecoder::computeParityPositions(const vector<bool>& datos, int p) {
    vector<vector<int>> res(p);
    for (int i = 0; i < p; ++i) {
        int parityBitPosition = (1 << i) - 1;  // Índice basado en 0
        for (int j = parityBitPosition; j < datos.size(); ++j) {
            if ((j + 1) & (1 << i)) {
                res[i].push_back(j);  // Guarda las posiciones
            }
        }
    }
    return res;
}



// Calcula la paridad de un conjunto de bits
bool HammingDecoder::calcularParidad(const vector<bool>& bits) {
    return count(bits.begin(), bits.end(), true) % 2 == 0;
}

// Detecta, notifica y corrige errores en los datos
vector<bool> HammingDecoder::fixAndDecode(vector<bool> datos, bool evenParity) {
    auto [p, m] = findParityAndDataSize(datos.size());
    int errorPosition = 0;
    vector<vector<int>> parities = computeParityPositions(datos, p);

    // Detecta la posición del error
    for (int i = 0; i < parities.size(); ++i) {
        vector<bool> bitsToCheck;
        for (int pos : parities[i]) {
            bitsToCheck.push_back(datos[pos]);
        }

        // Si la paridad no coincide, actualiza
        if (calcularParidad(bitsToCheck) != evenParity) {
            errorPosition |= (1 << i);
        }
    }

    if (errorPosition > 0) {
        cout << "Error detectado en la posición: " << errorPosition << endl;

        // Corrige el error invirtiendo el bit en la posición detectada
        datos[errorPosition - 1] = !datos[errorPosition - 1];
        cout << "Error corregido." << endl;
    } else {
        cout << "No se detectaron errores en los datos." << endl;
    }

    // Decodifica los datos eliminando los bits de paridad
    vector<bool> isParity = generateParityMask(datos.size(), p);
    vector<bool> decodedData;

    for (int i = 0; i < datos.size(); ++i) {
        if (!isParity[i]) {
            decodedData.push_back(datos[i]);
        }
    }
    return decodedData;
}