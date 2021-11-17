#ifndef UNIT_TEST

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "EscritorBinario.hpp"
#include "LectorBinario.hpp"
#include "./excepciones/excepcionPersonaNoExiste.hpp"
using namespace std;

int main(){
    
    ifstream ifs("personas.txt", ifstream::in);//-----------------------------------------------------> Abre el Txt Indicado
    if (!ifs.is_open()) {//---------------------------------------------------------------------------> Verifica que el txt este abierto
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;
    }
    
    EscritorBinario * Datos=new EscritorBinario();//-------------------------------------------------> Crea un puntero al archivo de texto
    ifs>> *Datos;//----------------------------------------------------------------------------------> Envia los Datos del txt al escritor de texto
    ifs.close();//-----------------------------------------------------------------------------------> Cierra el txt leido

    try{
        LectorBinario archivoEntrada {"Binario.dat"}; //----------------------------------------------> Abre el archivo binario

        ///////// AQUÍ SE INGRESA EL ID DE LA PERSONA A BUSCAR  //////////////////
        int ID=4;
        Persona persona = archivoEntrada.ObtenerPersona(ID);//------------------------------> Indica la persona que se decea buscar iniciando con la persona 1

        cout<<persona.getId()<<" "<<persona.getNombre()<<" "<<persona.getApellido() //--------------> Imprime los datos de la persona seleccionada
                             <<" "<<persona.getCorreo() <<endl;
        archivoEntrada.Cerrar();  //-----------------------------------------------------------------> Cierra el archivo binario para poder ser utilizado despues    
    }catch(const ExcepcionPersonaNoExiste & e){//----------------------------------------------------> Excepcion si no existe una persona
        std::cerr << "Error no existe esa persona. " << e.what() << '\n';
        return -1;
    }
    return 0;
}
#endif