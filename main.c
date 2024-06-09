#include <stdio.h>
#include <stdlib.h>

// Librerias Propias
#include "AutoArchivo/AutoArchivo.h"
#include "Auto/Auto.h"
#include "Usuario/Usuario.h"
#include "Persona/Persona.h"
#include "Utiles/Utiles.h"



int main()
{

    char nombreArchivo[] = "personas.bin";
//    agregarPersona();
//    Persona *arr;
//    int cantidadPersonas = traerPersonas(nombreArchivo, arr);
    menuCargaPersonas();
    verArchivoPersonas(nombreArchivo);
//    Persona *arr = &arreglopersona;
//    int cantidad = &cantidadpersonas;
//    printf("%d", cantidadPersonas);


//
//    AutoArchivo coche;
//    Auto coche2;
//    coche2 = cargarAuto(&arrPersona);
//    coche = cargarAutoArchivo(coche2);
//    mostrarAuto(&coche2);
//    mostrarAutoArchivo(coche);


//    Usuario user;
//    crearUsuario(&user);



//char *nombre = (char*) malloc(sizeof(char) * 20);
//char *contrasenia = (char*) malloc(sizeof(char) * 30);
//printf("ingrese nombre:");
//gets(nombre);
//printf("ingrese la contrase%ca", 164);
//gets(contrasenia);
//
//if (autenticar(ARCHIVO_USUARIOS, nombre, contrasenia) == 1){
//    printf("Usuario autenticado\n");
//
//} else {
//
//    printf("problemas para autenticar el usuario!");
//}

        return 0;
}

