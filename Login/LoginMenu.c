#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "LoginMenu.h"
#include "../Usuario/Usuario.h"
#include "../Usuario/UsuarioValidaciones.h"
#include "../Utiles/Utiles.h"

void menuLogin(){
    char *nombreArchivo = "Usuarios.bin";
    char *nombre = (char*) malloc(sizeof(char) * 20);
    char *contrasenia = (char*) malloc(sizeof(char) * 30);
    char *pin = (char*) malloc(sizeof(char) * 5);

    int opcion;
    int existeArch = existeArchivo(nombreArchivo);
    Usuario user;

    printf("..:: Bienvenindo al sistema de gestion de Concesionaria ::..\n");

    if (existeArch == 0){
        printf("Parece que no existe el archivo de usuarios.\n ");
        printf("Creando archivo...\n ");
        crearArchivo(nombreArchivo);
        printf("Listo. Ahora puede crear un Usuario.\n");
    }

    do{
        printf("..::LOGIN::..\n");
        printf("..::OPCIONES::..\n");
        printf("0 - Salir\n");
        printf("1 - Crear un Usuario\n");
        printf("2 - Ingresar\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            crearUsuario(&user);
            printf("Listo! Usuario creado!\n");
            printf("Ahora puede ingresar al sistema.\n");
            break;
        case 2:
            printf("ingrese nombre: ");
            fflush(stdin);
            gets(nombre);
            printf("ingrese la contrase%ca: ", 164);
            fflush(stdin);
            gets(contrasenia);

            if (autenticar(nombreArchivo, nombre, contrasenia) == 1){
                printf("Usuario autenticado\n");



                //aca va el menu pricipal;
            } else {

                printf("problemas para autenticar el usuario!");
            }

            printf("Ya casi! ingrese su pin: ");
            fflush(stdin);
            gets(pin);

            if (autPin(nombreArchivo, pin) == 1){
                printf("Ok! Ingresando...\n");
                opcion = 0;
            }

        }


    } while (opcion !=0);
}






