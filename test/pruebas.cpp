#include <gtest/gtest.h>
#include <string>
#include<sstream>
#include <iostream>

#include "../src/Persona.hpp"
#include "../src/EscritorBinario.hpp"
#include "../src/LectorBinario.hpp"
#include "../src/excepciones/ExcepcionPersonaNoExiste.hpp"
#include "../src/excepciones/ExcepcionArchivoNoAbre.hpp"
#include "../src/excepciones/ExcepcionErrorEnTXT.hpp"

using namespace std;

namespace {
     TEST(EscritorTest, Prueba_EscribirBinario) {
        //Toma un stream como linea de texto para escribir un documento binario
        string linea{"5 Lucy Araya Lucy@gmail.com"};
        istringstream stream{linea};
        EscritorBinario * Datos=new EscritorBinario();
        stream >> *Datos;

        //Lee el documento binario que se escribio
        LectorBinario lector {"Binario.dat"};
        Persona personaEncontrada = lector.ObtenerPersona(0);
        lector.Cerrar();

        //Copia la linea de stream y optiene cada dato de la misma 
        istringstream stream2(linea);
        int Id;   string nombre, apellido, correo;
        stream2>>Id>>nombre>>apellido>>correo;

        //Compara los datos del documento binario con los datos de la linea de tipo stream que se envio 
        EXPECT_EQ(personaEncontrada.getId(),Id );
        EXPECT_EQ(personaEncontrada.getNombre(),nombre );
        EXPECT_EQ(personaEncontrada.getApellido(),apellido);
        EXPECT_EQ(personaEncontrada.getCorreo(), correo);   
    }
    TEST(EscritorTest, Prueba_EscribirPersona) {

        //Crea 2 Personas
        Persona personaPrueba1 { 9, "James", "Araya" ,"Jame.jar2@gmail.com"};
        Persona personaPrueba2 { 10, "karina", "Gomez" ,"Karina.GomezRodriguez@gmail.com"};

        //Alamacena las 2 personas en el documento binario
        EscritorBinario escritor {"prueba.dat"};
        escritor.AgregarPersona(personaPrueba1);
        escritor.AgregarPersona(personaPrueba2);
        escritor.Cerrar();

        // Leer el documento binario y busca la persona con el ID de 10 si esta extrae la informacion
        LectorBinario lector {"prueba.dat"};
        Persona personaEncontrada = lector.ObtenerPersona(1);
        lector.Cerrar();

        //Compara los datos extraidos del documento binario con los enviados como prueba 
        EXPECT_EQ(personaEncontrada.getId(), personaPrueba2.getId());
        EXPECT_EQ(personaEncontrada.getNombre(), personaPrueba2.getNombre());
        EXPECT_EQ(personaEncontrada.getApellido(), personaPrueba2.getApellido());
        EXPECT_EQ(personaEncontrada.getCorreo(), personaPrueba2.getCorreo());   
    }

    TEST(EscritorTest, Prueba_GetPersona) {
        //Se crea una persona como una clase persona
        int Id {15};   string nombre {"James"},      apellido {"Araya"},     correo{"Jame.jar2@gmail.com"};
        Persona personaPrueba { Id, nombre, apellido, correo };

        // Extrae la informacion de la persona almacenada en los .get y se compra con las variables que se crearon
        EXPECT_EQ(personaPrueba.getId(), Id);
        EXPECT_EQ(personaPrueba.getNombre(), nombre);
        EXPECT_EQ(personaPrueba.getApellido(), apellido);
        EXPECT_EQ(personaPrueba.getCorreo(), correo);
        
    }

    TEST(EscritorTest, Prueba_ExcepcionPersonaNoexiste) {
        //Se crea una persona 
        Persona personaEncontrada {9, "James", "Araya", "James.jar2@gmail.com"};

        //Se busca una persona que no se encuetra para que se active la excepcion 
        EXPECT_THROW({
            EscritorBinario escritor {"prueba.dat"};
            escritor.AgregarPersona(personaEncontrada);
            escritor.Cerrar();

            // Leer el id de la persona de prueba
            LectorBinario lector{"prueba.dat"};
            lector.ObtenerPersona(23);
            lector.Cerrar();

        }, ExcepcionPersonaNoExiste);
    }

    TEST(EscritorTest, Prueba_ExcepcionArchivoNoAbre) {
        //Se crea una persona 
        Persona personaEncontrada {2, "Julio", "Aguilar", "Julio.A@gmail.com"};

        //Se busca una persona que no se encuetra para que se active la excepcion 
        EXPECT_THROW({
            EscritorBinario escritor {"prueba.dat"};
            escritor.AgregarPersona(personaEncontrada);
            escritor.Cerrar();

            // Leer un archivo que no existe para llamar la exepcion
            LectorBinario lector{"prueba2.dat"};
            lector.ObtenerPersona(23);
            lector.Cerrar();

        },ExcepcionArchivoNoAbre );
    }

    TEST(EscritorTest, Prueba_ExcepcionErrorEnTXT) {
        //Ingresa mediante un stream datos erroneos que el txt no debe poseer para generar una exepcion de error en el TXT
        string linea{"r Lucy Araya Lucy@gmail.com"};
        istringstream stream{linea};
        EscritorBinario * Datos=new EscritorBinario(); 
        EXPECT_THROW({
          
            stream >> *Datos; 

        }, ExcepcionErrorEnTXT);
    }

    TEST(EscritorTest, Prueba_ExcepcionErrorEnTXT_con_Id_0) {
        //Ingresa mediante un stream un id de cero para generar una Excepcion de error en el TXT ya que ningun id debe ser de 0
        string linea{"0 Lucy Araya Lucy@gmail.com"};
        istringstream stream{linea};
        EscritorBinario * Datos=new EscritorBinario(); 
        EXPECT_THROW({
          
            stream >> *Datos; 

        }, ExcepcionErrorEnTXT);
    }
}