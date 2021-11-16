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
        LectorBinario archivoEntrada {"Binario.dat"};//----------------------------------------------> Abre el archivo binario
        Persona id_inicial = archivoEntrada.ObtenerPersona(0 , 0);//---------------------------------> Permite buscar el id del primer elemento.
        int primero=id_inicial.getId();//------------------------------------------------------------> Almacena el primer id en un int 

        ///////// AQUÍ SE INGRESA EL ID DE LA PERSONA A BUSCAR  //////////////////
        int ID=13;
        Persona persona = archivoEntrada.ObtenerPersona(ID, primero);//------------------------------> Indica la persona que se decea buscar iniciando con la persona 1

        cout<<persona.getId()<<" "<<persona.getNombre()<<"  "<<persona.getApellido() //--------------> Imprime los datos de la persona seleccionada
                             <<"  "<<persona.getCorreo() <<endl;
        archivoEntrada.Cerrar();  //-----------------------------------------------------------------> Cierra el archivo binario para poder ser utilizado despues    
    }catch(const ExcepcionPersonaNoExiste & e){//----------------------------------------------------> Excepcion si no existe una persona
        std::cerr << "Error no existe esa persona. " << e.what() << '\n';
        return -1;
    }
    return 0;
}
#endif