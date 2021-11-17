#ifndef LECTOR_BINARIO
#define LECTOR_BINARIO

#include <string>
#include "Persona.hpp"

#include <fstream>

using namespace std;

class LectorBinario {

    ifstream archivoEntrada;

    public:
    LectorBinario(string nombreArchivo);//--------------> Recibe el nombre del archivo binario por leer

    Persona ObtenerPersona(int Id);//-------> Recibe el Id de la persona por revisar y el id inicial para saber donde iniciar la busqueda
    
    void Cerrar();//------------------------------------> Cierra el archivo binario
};

#endif