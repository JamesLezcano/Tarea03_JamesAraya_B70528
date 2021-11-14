#include "Persona.hpp"
#include <string.h>

using namespace std;

Persona::Persona(int Id, string nombrePersona, string apellidoPersona, string correoPersona) {
    this->Id = Id;
    strcpy(this->nombre, nombrePersona.c_str());
    strcpy(this->apellido, apellidoPersona.c_str());
    strcpy(this->correo, correoPersona.c_str());
}

    
Persona::Persona() {
    this->Id = 0;    
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}

int Persona::getId() {
    return this->Id;
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