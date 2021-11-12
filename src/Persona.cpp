#include "Persona.hpp"
#include <string.h>
using namespace std;

Persona::Persona(int id, string nombrePersona, string apellidoPersona ,string correoPersona) {
    this->id = id;
    strcpy(this->nombre, nombrePersona.c_str());
    strcpy(this->apellido, apellidoPersona.c_str());
    strcpy(this->correo, correoPersona.c_str());
}

    
Persona::Persona() {
    this->id = 0;    
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}

int Persona::getID() {
    return this->id;
}

string Persona::getNombre() {
    return string{this->nombre};
}

string Persona::getApellido() {
    return string{this->apellido};
}

string Persona::getCorreo() {
    return string{this->correo};
}