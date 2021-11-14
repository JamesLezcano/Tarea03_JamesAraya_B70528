#ifndef ESCRITOR_BINARIO
#define ESCRITOR_BINARIO

#include <string>
#include <fstream>
#include <iostream>
#include "Persona.hpp"
using namespace std;

class EscritorBinario {
    private:
        ofstream archivoSalida;

    public:
    EscritorBinario(string nombre);
    void AgregarPersona(Persona &persona);
    void Cerrar();
};
#endif