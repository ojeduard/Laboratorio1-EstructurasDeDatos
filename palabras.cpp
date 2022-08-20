
#include <fstream>
#include "palabras.h"

Palabras::Palabras() : ptrPalabras{ new std::string*[DEFAULT]} {}

Palabras::Palabras(size_t tam) {
	// TODO
	// Implementar constructor con un tama�o definido

    //Se debe de crear el espacio de memoria dinamica
    this->tam = tam;
    ptrPalabras = new std::string * [tam];

    // Ya se conoce el tamanno entonces, se recorre el vector para asignar NULL
    // A toda la memoria que aun no se va a utlizar
    for (int i = 0; i < tam ; ++i) {
        ptrPalabras[i] = NULL;
    }
}

Palabras::Palabras(const Palabras& copia) {
	// TODO
	// Implementar constructor de copia
    
    ptrPalabras = copia.ptrPalabras;

}

Palabras::~Palabras() {
	// TODO
	// Implementar destructor

    for (int i = 0; i < can ; ++i) {
        delete ptrPalabras [i];
    }
    delete [] ptrPalabras;
}

// Retorna un n�mero entero igual o mayor a cero si carg� correctamente
// El n�mero puede representar la cantidad de palabras cargadas
// Retorna -1 si hubo un error 
int Palabras::CargarDeArchivo(std::string nombre) {
	// TODO

    Palabras* palabras = new Palabras(tam);
    std::string word;

    std::ifstream cargaArchivo (nombre);

    if(!cargaArchivo.is_open()){
        throw std::invalid_argument("-1");
    }

//    getline(cargaArchivo, jumpFirst);
    while (!cargaArchivo.eof()){
        getline(cargaArchivo, word, '\n');
        palabras->AgregarPalabra(word);
    }
    cargaArchivo.close();
    std::cout << "Las palabras obtenidas son: " << palabras->toString() << std::endl;
    return 1;

}

// Retorna un n�mero entero igual o mayor a cero si guard� correctamente
// El n�mero puede representar la cantidad de palabras guardadas
// Retorna -1 si hubo un error 
int Palabras::GuardarEnArchivo() {
	// TODO
	// Guardar las palabras en el archivo

    // Abre el archivo e indica el nombre de la carpeta en la que se guardara la info
    std::ofstream guardaArchivo("archivos.txt", std::ios_base::app);

    if(guardaArchivo.fail()){
        throw std::invalid_argument("-1");
    }

    guardaArchivo << toString();

    guardaArchivo.close();

    return 0;
}

// Almacena una nueva palabra en el vector
void Palabras::AgregarPalabra(std::string palabra) {
	// TODO
	// Implementar la inserci�n de palabras en la clase


    if (can < tam){

        ptrPalabras[can++] = &palabra;
        std::cout << "Se ingreso palabra" << std:: endl;

    }else{

        std::invalid_argument("CUPO LLENO");

    }
}

std::string Palabras::toString() {
    std::stringstream s;

    for (int i = 0; i < can; ++i) {
        s << *ptrPalabras[i] << std::endl;
    }

    return s.str();
}
