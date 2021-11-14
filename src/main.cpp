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

    ifstream ifs("personas.txt", ifstream::in);//----------------------------------------------------------------Abre el Txt Indicado
    if (!ifs.is_open()) {//-------------------------------------------------------------------------------------------------Verifica que el txt este abierto
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        //return -1;
    }

    string linea {""},       nombre{""},       apellido{""},      correo{""};// ------------------------------------------Variables para los datos del txt
    int Id {0};

    EscritorBinario archivoSalida {"Binario.dat"};//-----------------------------------------------------------------------Creamos el Archivo Binario
    while (std::getline(ifs, linea)) {//---------------------------------------------------------------------------------- Leer línea por línea el txt
        try{
            std::istringstream stream(linea);// ----------------------------------------------------------------------------Procesamos la línea
            Id=0;        nombre,     apellido,     correo    = ""; // ------------------------------------------------------Limpiamos las variables de los datos a extraer

            stream >> Id >> nombre >> apellido >> correo; // ---------------------------------------------------------------Extraemos los datos del txt
           
            if (nombre.length() == 0  || apellido.length() == 0 || correo.length() == 0 || Id==0){// -----------------------Revisar si línea es válida
                string error = "Error en línea \"" + linea + "\". Nombre no puede ser vacío.";
                throw error;
            }
            Persona * PersonaNueva = new Persona {Id,nombre,apellido,correo}; //--------------------------------------------Creamos un puntero a los datos
           // cout<<PersonaNueva <<"   "<< &PersonaNueva<<endl; 
            archivoSalida.AgregarPersona(*PersonaNueva); // ----------------------------------------------------------------Enviamos los datos al Archivo Binario
            delete PersonaNueva;
        }
        catch (string &excepcion){
            cerr << excepcion << endl;
        }
    }
    archivoSalida.Cerrar(); //------------------------------------------------------------------------------------- Cerramos el archivo Binario
    ifs.close();//----------------------------------------------------------------------------------------------------------Cierra el txt leido

    try{
        LectorBinario archivoEntrada {"Binario.dat"};
        Persona persona = archivoEntrada.ObtenerLibro(3);
        cout<<persona.getId();
        archivoEntrada.Cerrar();        
    }catch(const ExcepcionPersonaNoExiste & e){
        std::cerr << "Error leyendo el libro solicitado. " << e.what() << '\n';
        return -1;
    }

    return 0;
}