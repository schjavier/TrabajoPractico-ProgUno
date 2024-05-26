#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"

/** Constante con el nombre de archivo, para persistir los usuarios **/
#define ARCHIVO_USUARIOS "Usuarios.bin"

/** Implementacion de la interface Usuario **/

void crearUsuario(Usuario *usuario){



    printf("\t\t\t\t..::CREACI%cN DE USUARIO::..\n\n", 162);
    printf("Crearemos un usuario para entrar en el sistema.\n");
    printf("Ingrese su nombre de usuario: ");
    fflush(stdin);
    gets((*usuario).nombreUsuario);
    printf("Ingrese su contrase%ca: ", 165);
    fflush(stdin);
    gets((*usuario).contrasenia);
    printf("Por %cltimo agregue un pin de seguridad: ", 163);
    scanf("%d", &usuario->pin);
    guardarUsuario(ARCHIVO_USUARIOS, usuario);


}

void guardarUsuario(char *nombreArchivo, Usuario *usuario){
    FILE *archivo = fopen(nombreArchivo, "ab");

    if (archivo != NULL){

        printf("Guardando...");
        fwrite(usuario, sizeof(Usuario), 1, archivo);
        printf("OK!");

    }else {

    printf("Tuvimos problemas abriendo el archivo.");

    }



}
