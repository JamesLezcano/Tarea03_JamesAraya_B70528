#ifndef ESCRITOR_PERSONAS
#define ESCRITOR_PERSONAS

#include <iostream>
#include "Persona.hpp"
#include <string.h>
#include <fstream>

using namespace std;

class EscritorPersonas {

    ofstream archivoSalida;

    public:
    EscritorPersonas(string nombre);
    void AgregarPersona(Persona &persona);
    void Cerrar();

};

#endif