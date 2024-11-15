
#ifndef HAMMING_H
#define HAMMING_H



#include <iostream>
using namespace std;

int generateParityBit(int number, bool evenParity = true) {
    int count = 0;

    // Count the number of 1s in the binary representation
    for (int i = 0; i < 32; i++) {
        if (number & (1 << i)) {
            count++;
        }
    }

    // For even parity, parity bit should make total number of 1s even
    // For odd parity, parity bit should make total number of 1s odd
    if (evenParity) {
        return count % 2 == 0 ? 0 : 1;  // Even parity: return 0 if already even, else 1
    } else {
        return count % 2 == 0 ? 1 : 0;  // Odd parity: return 1 if already even, else 0
    }
}

int generateParityBitREAL(const std::string& bits, bool evenParity = true) {
    int count = 0;

    // Cuenta la cantidad de '1's en la cadena de bits
    for (char bit : bits) {
        if (bit == '1') {
            count++;
        }
    }

    // Para paridad par, el bit de paridad debería hacer el total de '1's par
    // Para paridad impar, el bit de paridad debería hacer el total de '1's impar
    if (evenParity) {
        return count % 2 == 0 ? 0 : 1;  // Paridad par: devuelve 0 si ya es par, sino 1
    } else {
        return count % 2 == 0 ? 1 : 0;  // Paridad impar: devuelve 1 si es par, sino 0
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

string setparity(const std::vector<int>& paritypos, const std::string& datos, int p) {
    int realsize = datos.length() + p;
    std::string final(realsize, '0'); // Inicializamos con '0'

    // Convertimos paritypos a un conjunto para búsquedas rápidas
    unordered_set<int> paritySet(paritypos.begin(), paritypos.end());

    // Posicionamos los datos y asignamos paridad en una sola pasada
    int dataIndex = 0;
    for (int i = 0; i < realsize; ++i) {
        if (paritySet.count(i + 1)) {
            final[i] = '0';  // Se asegura que las posiciones de paridad queden en '0'
        } else if (dataIndex < datos.size()) {
            final[i] = datos[dataIndex++];  // Colocamos el dato en posiciones no-paridad
        }
    }

    return final;
}
void calculatorsparity(const vector<int>& paritypos, int p) {
    vector<vector<int>> matrix(p, vector<int>(1 << p, 0));

    for (int i = 0; i < p; i++) {
        int toggle = 1 << i;
        for (int j = 0; j < (1 << p); j++) {
            if ((j / toggle) % 2 != 0) {
                matrix[i][j] = 1;
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < (1 << p); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}




#endif //HAMMING_H
