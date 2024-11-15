
#ifndef HAMMING_H
#define HAMMING_H



#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

// Prototipos de las funciones
int Pfinder(int m);
vector<int> parityposition(int p);
vector<bool> setparity(const vector<int>& parityPos, const vector<bool>& datos, int p);
int generateParityBitREAL(const vector<bool>& parityCheck, bool evenParity);



int generateParityBitREAL(const vector<bool>& bits, bool evenParity = true) {
    int count = 0;

    // Cuenta la cantidad de '1's en el vector de bits
    for (bool bit : bits) {
        if (bit) {
            count++;
        }
    }

    // Para paridad par, el bit de paridad debería hacer el total de '1's par
    // Para paridad impar, el bit de paridad debería hacer el total de '1's impar
    if (evenParity) {
        return count % 2 == 0 ? 0 : 1;  // Paridad par: devuelve 0 si ya es par, sino 1
    } else {
        return count % 2 == 0 ? 1 : 0;  // Paridad impar: devuelve 1 si ya es par, sino 0
    }
}

int Pfinder(int m) {
    int p = 0;
    while(true) {
        if (pow(2, p) >= p+m+1) {
            return p;
        }
        p++;
    }
}

vector<int> parityposition(int p) {
    vector<int> positions(p);

    for (int i = 0; i < p; i++) {
        positions[i] = pow(2, i);
    }

    return positions;
}

vector<bool> setparity(const vector<int>& parityPos, const vector<bool>& datos, int p) {
    int realsize = datos.size() + p;
    vector<bool> final(realsize, false); // Inicializamos con 'false' que representa '0'

    unordered_set<int> paritySet(parityPos.begin(), parityPos.end());

    // Posicionamos los datos y asignamos paridad en una sola pasada
    int dataIndex = 0;
    for (int i = 0; i < realsize; ++i) {
        if (paritySet.count(i + 1)) {
            final[i] = false;  // paridad queden en '0'
        } else if (dataIndex < datos.size()) {
            final[i] = datos[dataIndex++];
        }
    }

    return final;
}

vector<bool> generateHammingCode(const vector<bool>& datos, bool evenParity = true) {
    int m = datos.size();  // Longitud del mensaje original
    int p = Pfinder(m);  // bits de paridad necesarios
    cout << "P es " << p << endl;

    // posiciones de paridad
    vector<int> parityPos = parityposition(p);

    // mensaje con los bits de paridad en '0'
    vector<bool> mensajeConParidad = setparity(parityPos, datos, p);

    // valores de los bits de paridad
    for (int i = 0; i < p; i++) {
        int parityBitPosition = parityPos[i] - 1;  // Índice basado en 0
        vector<bool> parityCheck;

        // cadena para verificar la paridad
        for (int j = parityBitPosition; j < mensajeConParidad.size(); j++) {
            if ((j + 1) & (1 << i)) {
                parityCheck.push_back(mensajeConParidad[j]);
            }
        }

        // Calcula el bit de paridad
        int parityBit = generateParityBitREAL(parityCheck, evenParity);

        // Actualiza el bit de paridad
        mensajeConParidad[parityBitPosition] = parityBit;
    }

    return mensajeConParidad;
}






#endif //HAMMING_H
