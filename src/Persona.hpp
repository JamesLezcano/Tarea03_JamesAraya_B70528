#ifndef PERSONA
#define PERSONA

#include <string>
#include <fstream>
using namespace std;

class Persona {
    int id; //4
    char nombre[15]; 
    char apellido[15]; 
    char correo[50];

    public:
    Persona(int id, string nombre, string apellido, string correo);
    Persona();

    int getID();
    string getNombre();
    string getApellido();
    string getCorreo();
};

#endif