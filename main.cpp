//
// Created by Eduardo Ojeda on 20/8/22.
//
#include <iostream>
#include "palabras.h"

using namespace std;

int main(){
    Palabras* pal = new Palabras (10); // Constructor Normal

    pal->AgregarPalabra("Hola");
    pal->AgregarPalabra("Esta");

    cout << pal->toString();

//    pal->GuardarEnArchivo();
    pal->CargarDeArchivo("archivos.txt");

    Palabras* copia (pal);
    cout << "Ejecutando copia" << endl << endl;
    cout << copia->toString();

    return 0;
}

