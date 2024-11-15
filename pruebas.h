#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <iostream>
#include <bitset>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <math.h>
#include <unordered_set>
#include <vector>

#include "hamming.h"


using namespace std;



vector<string> strToBinary(string s) {
    int n;
    n = s.length();
    string binario;
    string binario1;

    for (int i = 0; i < n; i++) {  // Cambié <= por < para evitar acceso fuera de rango
        // Convertir cada carácter a su valor ASCII
        int val;
        val = int(s[i]);

        // Convertir el valor ASCII a binario
        bitset<8> bin(val);  // Utilizamos bitset para convertir a binario en 8 bits
        binario += bin.to_string();  // Concatenar el binario a la cadena
        binario1 += bin.to_string();  // Concatenar el binario a la cadena
        binario += " ";  // Agregar espacio entre los caracteres binarios
    }

    return {binario, binario1};
}

// Convertir binario a ASCII
string binaryToASCII(string data) {
    stringstream sstream(data);
    string output;
    string temp;

    while (sstream >> temp) {  // Leer cada conjunto de 8 bits
        bitset<8> bits(temp);  // Convertir los 8 bits a bitset
        char c = char(bits.to_ulong());  // Convertir a char
        output += c;  // Agregar al resultado final
    }

    return output;
}

list<string> intputfile() {
    string line;
    ifstream myfile("../inicio.txt");
    string texto123;

    if (myfile.is_open())
    {

        while(getline(myfile, line)) {
            //cout << line << endl;
            texto123.append(line);
        }
        myfile.close();
    }
    string binarios2send = strToBinary(texto123).front();


    //cout << "Binary representation: " << binarios2send << endl;

    string text = "Hola Mundo";

    // Convertir texto a binario
    string binario = strToBinary(texto123).front();
    cout << "Texto a Binario: " << binario << endl;

    // Convertir binario de vuelta a texto
    string texto = binaryToASCII(binario);
    cout << "Binario a Texto: " << texto << endl;


    return {binarios2send, texto};
}

void outputfile(string texto) {
    // Abre el archivo en modo de escritura (por defecto trunca el archivo)
    ofstream file("../salida.txt", ios::trunc);

    // Verifica si se pudo abrir el archivo
    if (file.is_open()) {
        cout << "El contenido del archivo ha sido borrado." << endl;
        file.close();  // Cierra el archivo
    }

    // Ahora abre el archivo en modo 'append' para agregar texto
    ofstream archivoAppend("../salida.txt", ios::app);
    if (archivoAppend.is_open()) {
        archivoAppend << texto;  // Escribe el string en el archivo
        archivoAppend.close();  // Cierra el archivo
        cout << "Texto agregado al archivo." << endl;
    }
}



#endif //PRUEBAS_H
