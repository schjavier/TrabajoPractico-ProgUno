#include <stdio.h>
#include <stdlib.h>

#include "Utiles.h"

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

void crearArchivo(char *nombreArchivo){
    FILE *archivo = fopen(nombreArchivo, "wb");
    fclose(archivo);
}
