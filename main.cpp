#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "pruebas.h"
#include "hamming.h"




using namespace std;
using namespace __bitset;


#include <iostream>
#include <vector>

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

    // Cadena de datos de prueba
    string datos = "0110";
    // Convertimos la cadena de datos a vector<bool>
    vector<bool> datosVec = stringToVectorBool(datos);

    // Generamos el código de Hamming
    vector<bool> hammingCodeVec = generateHammingCode(datosVec);

    // Convertimos el resultado de vector<bool> a string para visualizar
    string hammingCode = vectorBoolToString(hammingCodeVec);

    // Imprimimos el resultado
    cout << "Datos originales: " << datos << endl;
    cout << "Código Hamming:   " << hammingCode << endl;


    return 0;
}


