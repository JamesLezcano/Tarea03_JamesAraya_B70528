#include "EscritorPersonas.hpp"
#include "./excepciones/excepcionNoSePuedeAbrirArchivo.h"

using namespace std;

EscritorPersonas::EscritorPersonas(std::string nombre) {

    archivoSalida.open(nombre, ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        throw new ExcepcionNoSePuedeAbrirArchivo();
    }
}

void EscritorPersonas::AgregarPersona(Persona &libro) {
    archivoSalida.write((char *) &libro, sizeof(Persona));
}

void EscritorPersonas::Cerrar() {
    archivoSalida.close();
}
