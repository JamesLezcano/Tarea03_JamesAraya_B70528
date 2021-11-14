#ifndef LECTOR_BINARIO
#define LECTOR_BINARIO

#include <string>
#include "Persona.hpp"

#include <fstream>

using namespace std;

class LectorBinario {

    ifstream archivoEntrada;

    public:
    LectorBinario(string nombreArchivo);

    Persona ObtenerLibro(int Id);
    
    void Cerrar();
};

#endif