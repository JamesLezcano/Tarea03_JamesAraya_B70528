#include "EscritorBinario.hpp"
#include "./excepciones/ExcepcionArchivoNoAbre.hpp"
#include "./excepciones/ExcepcionErrorEnTXT.hpp"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

EscritorBinario::EscritorBinario(){ /*Permite crear un puntero de la clase para poder enviar el istream*/}

EscritorBinario::EscritorBinario(std::string nombre) {

    archivoSalida.open(nombre, ios::out|ios::binary);
    if (!archivoSalida.is_open())
    {
        throw ExcepcionArchivoNoAbre();
    }
}

void EscritorBinario::AgregarPersona(Persona &persona) {
    archivoSalida.write((char *) &persona, sizeof(Persona));
}

std::istream& operator >> (std::istream &i, EscritorBinario &escritor){
    string linea {""},       nombre{""},       apellido{""},      correo{""};// -------------------------------> Variables para los datos del txt
    int Id {0};
    EscritorBinario archivoSalida {"Binario.dat"};//-----------------------------------------------------------> Creamos el Archivo Binario
    
    while (getline(i, linea)) {//------------------------------------------------------------------------------> Leer línea por línea el txt
        try{
            istringstream stream(linea);// --------------------------------------------------------------------> Procesamos la línea
            Id=0;        nombre,     apellido,     correo    = ""; // -----------------------------------------> Limpiamos las variables de los datos a extraer
            stream >> Id >> nombre >> apellido >> correo; // --------------------------------------------------> Extraemos los datos del txt
           
            if (nombre.length() == 0  || apellido.length() == 0 || correo.length() == 0 || Id==0){// ----------> Revisar si línea es válida
                throw ExcepcionErrorEnTXT();
            }
            Persona * PersonaNueva = new Persona {Id,nombre,apellido,correo}; //-------------------------------> Creamos un puntero a los datos
         
            archivoSalida.AgregarPersona(*PersonaNueva); // ---------------------------------------------------> Enviamos los datos al Archivo Binario
            delete PersonaNueva;
        }
        catch (string &excepcion){
            cerr << excepcion << endl;
        }
    }
    archivoSalida.Cerrar(); //---------------------------------------------------------------------------------> Cerramos el archivo Binario
    return i;
}

void EscritorBinario::Cerrar() {
    archivoSalida.close();
}
