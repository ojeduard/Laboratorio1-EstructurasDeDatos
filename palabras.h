#ifndef PALABRAS_H
#define PALABRAS_H

#include <string>
#include <iostream>
#include <sstream>

#define DEFAULT	10

class Palabras {
public:
	Palabras();
	Palabras(size_t);
	Palabras(const Palabras&);
	~Palabras();

	int CargarDeArchivo(std::string);
	int GuardarEnArchivo();
	void AgregarPalabra(std::string);
    std::string toString();

private:
	// La clase almacena apuntadores a string, donde se encuentra
	// cada palabra
	std::string** ptrPalabras;
    int can = 0;
    int tam = 0;


};

#endif
