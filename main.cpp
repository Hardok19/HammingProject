#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include "encoder/hamming.h"
#include <vector>
#include "decoder/hammingdecoder.h"




using namespace std;
using namespace __bitset;




using namespace std;

vector<bool> stringToVectorBool(const string& str) {
    vector<bool> vec(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        vec[i] = (str[i] == '1');
    }
    return vec;
}

string vectorBoolToString(const vector<bool>& vec) {
    string str(vec.size(), '0');
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i]) {
            str[i] = '1';
        }
    }
    return str;
}


int main() {
    // Datos de prueba
    vector<bool> datos = stringToVectorBool("10110101");  // Mensaje de datos original

    // Instanciar la clase Hamming
    Hamming hamming;




    vector<bool> ham = hamming.generateHammingCode(datos);
    hamming.printHammingCode(ham);

    // Introducir un error para pruebas (por ejemplo, invertir el primer bit)
    vector<bool> datosConError = stringToVectorBool("001101100111");

    HammingDecoder decoder;

    bool evenParity = true; // Paridad par

    // Arreglar y decodificar
    vector<bool> resultado = decoder.fixAndDecode(datosConError, evenParity);

    cout << "Datos decodificados: ";
    for (bool bit : resultado) {
        cout << bit;
    }
    cout << endl;
    return 0;
}


