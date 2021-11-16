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
    Persona(int id, string nombre, string apellido, string correo);//----> Pasa los datos en formato de char y hace una copia en formato string
    int getId();//-------------------------------------------------------> Almacena el Id de la persona
    string getNombre();//------------------------------------------------> Almacena el nombre de la persona
    string getApellido();//----------------------------------------------> Almacena el apellido de la persona
    string getCorreo();//------------------------------------------------> Almacena los datos del Correo
};


#endif