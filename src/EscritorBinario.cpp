#include "EscritorBinario.hpp"
#include "./excepciones/ExcepcionArchivoNoAbre.hpp"

using namespace std;

EscritorBinario::EscritorBinario(std::string nombre) {

    archivoSalida.open(nombre, ios::out|ios::binary);
    if (!archivoSalida.is_open())
    {
        throw new ExcepcionArchivoNoAbre();
    }
}

void EscritorBinario::AgregarPersona(Persona &persona) {
    archivoSalida.write((char *) &persona, sizeof(Persona));
}

void EscritorBinario::Cerrar() {
    archivoSalida.close();
}
