#include "hamming.h"
#include <iostream>
#include <cmath>
#include <unordered_set>

// Encuentra el número de bits de paridad necesarios
    int Hamming::Pfinder(int m) {
        int p = 0;
        while (true) {
            if (pow(2, p) >= p + m + 1) {
                return p;
            }
            p++;
        }
    }

// Genera las posiciones de los bits de paridad
vector<int> Hamming::parityposition(int p) {
    vector<int> positions(p);
    for (int i = 0; i < p; i++) {
        positions[i] = pow(2, i);
    }
    return positions;
}

//posiciones involucradas en cada bit de paridad
vector<vector<int>> Hamming::precomputeParityPositions(int p, int dataSize){
    vector<vector<int>> parityPositions(p);
    for (int i = 0; i < p; i++) {
        int parityBitPosition = (1 << i) - 1; // Índice basado en 0
        for (int j = parityBitPosition; j < dataSize; j++) {
            if ((j + 1) & (1 << i)) {
                parityPositions[i].push_back(j); // Guarda la posición
            }
        }
    }
    return parityPositions;
}

// Calcula el bit de paridad basado en las posiciones precomputadas
int Hamming::generateParityBitREAL(const vector<bool>& datos, const vector<int>& positions, bool evenParity){
    int count = 0;
    for (int pos : positions) {
        if (datos[pos]) count++;
    }
    return evenParity ? count % 2 : !(count % 2);
}

// Coloca los bits de datos y reserva espacio para los bits de paridad
vector<bool> Hamming::setparity(const vector<int>& parityPos, const vector<bool>& datos){
    int p = Pfinder(datos.size());
    int realsize = datos.size() + p;
    vector<bool> final(realsize, false); // Inicializado con 'false' para representar '0'
    unordered_set<int> paritySet(parityPos.begin(), parityPos.end());

    int dataIndex = 0;

    for (int i = 0; i < realsize; ++i) {
        if (paritySet.count(i + 1)) {
            final[i] = false;  // Bits de paridad inicialmente en '0'
        } else if (dataIndex < datos.size()) {
            final[i] = datos[dataIndex++];
        }
    }
    return final;
}



// Genera el código Hamming
vector<bool> Hamming::generateHammingCode(const vector<bool>& datos, bool evenParity) {
    int m = datos.size();
    int p = Pfinder(m);

    vector<int> parityPos = parityposition(p);

    vector<bool> mensajeConParidad = setparity(parityPos, datos);

    //posiciones de los bits para cada paridad
    vector<vector<int>> parityPositions = precomputeParityPositions(p, mensajeConParidad.size());

    // Calcula y actualiza los valores de los bits de paridad
    for (int i = 0; i < p; i++) {
        int parityBitPosition = parityPos[i] - 1; // Índice basado en 0

        // Calcula el bit de paridad
        int parityBit = generateParityBitREAL(mensajeConParidad, parityPositions[i], evenParity);

        // Actualiza el bit de paridad en el mensaje
        mensajeConParidad[parityBitPosition] = parityBit;
    }

    return mensajeConParidad;
}
void Hamming::printHammingCode(const vector<bool>& code) {
    for (bool bit : code) {
        cout << bit;
    }
    cout << endl;
}