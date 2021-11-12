#include<iostream>
#include "Lector_txt.hpp"
#include "Persona.hpp"
#include "EscritorPersonas.hpp"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

Lector_txt::Lector_txt(string personas){
    this->personas=personas;
}

void Lector_txt::lectorPersonas(string personas){
    ifstream ifs(personas,ifstream::in);
    if(!ifs.is_open()){
        cerr<<"Error al leer txt "<< endl;
        //intentar agregar el return
    }
    string linea("");
    
    int ID{0};
    string nombre{""};
    string apellido{""};
    string correo{""};

    while (std::getline(ifs, linea)){
        try{
            istringstream stream(linea);

            int ID{0};
            string nombre{""};
            string apellido{""};
            string correo{""};

            stream >> ID >> nombre >> apellido >> correo;
            if (nombre.length()==0 || apellido.length()==0 ||correo.length()==0 ){
                string error = "Error al leer linea\"" + linea+ "\".dato no puede estar vacio. ";
                throw error;
            }else{
                Persona *PersonaNueva= new Persona(ID, nombre, apellido, correo);
                EscritorPersonas archivoSalida{"Personas.dat"};
                archivoSalida.AgregarPersona(*PersonaNueva);
                archivoSalida.Cerrar();
            }
        }
        catch(string &exceptionLeerPersona){
            cerr<<exceptionLeerPersona<<endl;
        }
    }
    
}