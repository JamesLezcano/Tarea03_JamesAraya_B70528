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
        string ArchivoBinario;

    public:
    EscritorBinario();//--------------------------------------------------------------> Crea un puntero de la clase
    EscritorBinario(string nombre);//-------------------------------------------------> Abre el archivo binario para ser utilizado
    void AgregarPersona(Persona &persona);//------------------------------------------> Agrega las personas al Archivo Binario
    void Cerrar();//------------------------------------------------------------------> Cierra el archivo binario

    friend std::istream& operator >> (std::istream &i, EscritorBinario &escritor);//--> crea un stream para enviar los datos del txt a la clase para ser leidos 
};
#endif