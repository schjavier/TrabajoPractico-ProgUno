#include <stdio.h>
#include <stdlib.h>

#include "Utiles.h"
#include "../Persona/Persona.h"

/**

    Funcion que verifica si existe el archivo
    Params: char *nombreArchivo -> un puntero al nombre del archivo para verificar si existe.
    Return: int -> devuelve : 1 si existe
                              0 si no

**/

int existeArchivo(char *nombreArchivo){
    FILE *archivo = fopen(nombreArchivo, "rb");
    int valor;

    if (archivo != NULL){
        valor = 1;
    } else {
        valor = 0;
    }
    fclose(archivo);
    return valor;
}

/****/


void crearArchivo(char *nombreArchivo){
    FILE *archivo = fopen(nombreArchivo, "wb");
    fclose(archivo);
}

void verArchivoPersonas(char *nombreArchivo){
FILE *archivo = fopen(nombreArchivo, "rb");

Persona aux;

if (archivo != NULL){

        while (fread(&aux, sizeof(Persona), 1, archivo) > 0){
            printf("detalles de la persona\n");
            printf("%s\n", aux.nombre);
            printf("%s\n", aux.direccion);
            printf("%s\n", aux.dni);
            printf("%s\n", aux.telefono);
            printf("%s\n", aux.rol);
            }


}else {

printf("problemas para abrir el archivo");

}
fclose(archivo);

}
