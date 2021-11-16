# Tarea03_JamesAraya_B70528
James Araya Rodríguez- B70528

-Tratamiento de archivos binarios

-Para ejecutar este codigo se utiliza C++17

-Si se desea ejecutar el programa desde una terminal los codigos necesarios son:
    g++ -g./src/*.cpp -o /obj/tarea03.exe

-Este programa consiste en tomar archivo txt leerlo y pasarlo a archivo binario
    + los datos por leer son
        ->Id -> entero
        ->nombre -> string
        ->apellido -> string
        ->correo -> string
        ->si los datos siguien un formato diferente se crea una ExepcionErrorEnTXT

    + Para escribir el archivo binario
        ->si el archivo binario no se puede abrir se genera una ExcepcionArchivoNoAbre
    
    + Para leer los datos del archivo binario
        -> Se ingresa el Id de la persona a buscar, como el programa no solicitaba buscar varias personas no se implementa 
           queda a disposicion del profesor si desea que se implemente
        -> Si se ingresa el Id de una persona que no se encuentra se general una ExcepcionPersonaNoExiste 
        -> Si el archivo binario no se puede abrir se genera una ExcepcionArchivoNoAbre
        -> para buscar las personas por Id estas deben estar ordenadas de menor a mayor en el txt que es lo que se esperaria
            en cualquier documento no obstante si el profesor lo requiere se puede modificar para que esto no funcione sin importar el orden

    + Para las pruebas unitarias se busco la forma de que se recorrieran todos los metodos del programa de forma indibidual desde 
    la lectura del txt hasta la busqueda del id de persona para terminar con las pruebas unitarias de las Excepciones.


