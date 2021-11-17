#include <iostream>

#include "LectorBinario.hpp"
#include "./excepciones/excepcionArchivoNoAbre.hpp"
#include "./excepciones/excepcionPersonaNoExiste.hpp"

LectorBinario::LectorBinario(string nombreArchivo) {

    archivoEntrada.open(nombreArchivo, ios::in|ios::binary);//-----------------> Abre el achivo binario
    if (!archivoEntrada.is_open()){//------------------------------------------> Evita que el programa continue si no se logro abrir el archivo
        throw ExcepcionArchivoNoAbre();
    }
}

Persona LectorBinario::ObtenerPersona(int Id) {
    
    Persona PersonaLeida; //---------------------------------------------------> Permite acceder a los datos de las personas
    long posicionLibro = sizeof(Persona) * (Id); //----------------------------> Posición del libro número idLibro
    archivoEntrada.seekg(0, ios::end); //--------------------------------------> Permite
    long fileSize = archivoEntrada.tellg();
    
    if (posicionLibro > fileSize){ // -----------------------------------------> Evita que el lector lea un dato fuera de rango
        throw ExcepcionPersonaNoExiste();
    }
    archivoEntrada.seekg(posicionLibro);
    archivoEntrada.read((char *) &PersonaLeida, sizeof(Persona));

    return PersonaLeida;//-----------------------------------------------------> Retorna la persona que se decidio leer en el archivo binario
}

void LectorBinario::Cerrar() {//-----------------------------------------------> Cierra el documento para poder ser utilizado posteriormente
    archivoEntrada.close();
}