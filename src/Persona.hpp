#ifndef PERSONA
#define PERSONA

#include <string>
using namespace std;

class Persona{
    int Id; // 4 bits
    char nombre[15]; 
    char apellido[15]; 
    char correo[50];

    public:
    Persona();
    Persona(int id, string nombre, string apellido, string correo);
    int getId();
    string getNombre();
    string getApellido();
    string getCorreo();
};


#endif