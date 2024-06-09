#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AutoArchivo.h"
#include "../Patente/Patente.h"

/**
    Implementacion de la interface AutoArchivo
**/


/** Constante con el nombre de archivo, para persistir los usuarios **/
#define ARCHIVO_AUTOS "AutoArchivo.bin"


/**
    Función que carga una estructura tipo AutoArchivo.
    Params: Auto autoAcargar -> recibe una estructura tipo Auto
    Return: AutoArchivo
**/

AutoArchivo cargarAutoArchivo(Auto autoACargar){

AutoArchivo coche;

coche.patente = autoACargar.patente;
strcpy (coche.marca, autoACargar.marca);
strcpy (coche.modelo, autoACargar.modelo);
coche.anio = autoACargar.anio;
coche.kms = autoACargar.kms;
strcpy (coche.dniTitular, autoACargar.titular.dni);
coche.precioDeAdquisicion = autoACargar.precioDeAdquisicion;

return coche;

}

/**
    Función que muestra por pantalla todos los campos de una estructura tipo AutoArchivo.
    Args: AutoArchivo
    Return: none

 **/

void mostrarAutoArchivo(AutoArchivo coche){

printf("-----------------------------------------\n");
printf("Patente: %s-%s\n", coche.patente.letras, coche.patente.numeros);
printf("Marca : %s\n", coche.marca);
printf("Modelo : %s\n", coche.modelo);
printf("A%co : %s\n",164, coche.modelo);
printf("Kilometraje : %d\n", coche.kms);
printf("DNI del titular : %s\n", coche.dniTitular);
printf("Precio de Adquisici%cn : %.2f\n", 162, coche.precioDeAdquisicion);
printf("-----------------------------------------\n");
}

/**
    Funcion que busca en el archivo los autos que se encuantran en venta
    Params: char* nombreArchivo -> Recibe un puntero a char que representa el nombre del archivo.
    return: devuelve una estructura AutoArchivo que este en venta.
**/

AutoArchivo buscarAutoEnVenta(char* nombreArchivo){
    FILE *archivo = fopen(nombreArchivo, "rb");

    AutoArchivo aux;
    AutoArchivo enVenta;

    if (archivo != NULL){

        while(fread(&aux, sizeof(AutoArchivo), 1, archivo)>0){

            if((strcmp(aux.dniTitular, "00000000\0") == 0)){
                enVenta = aux;
            }

        }

    } else {

    printf("Error leyendo el archivo");

    }

return enVenta;


}

/**
    Funcion que cuenta la cantidad de autos que estan en venta.
    args: un puntero a char que representa el nombre del archivo.
    return: devuelve un entrero que representa la cantidad de autos en venta.
**/

int contarAutoEnVenta(char *nombreArchivo){

FILE *archivo = fopen(nombreArchivo, "rb");

    int contador;
    AutoArchivo aux;

    if (archivo != NULL){

        while(fread(&aux, sizeof(AutoArchivo), 1, archivo)> 0){
            if (strcmp(aux.dniTitular, "00000000\0") == 0){
                contador++;
            }
        }

    } else {

        printf("Problemas leyendo el archivo");

}
fclose(archivo);
return contador;

}
int cargarArrAutosEnVenta(char *nombreArchivo, AutoArchivo **autosEnVenta){
    FILE *archivo = (fopen(nombreArchivo, "rb"));

    int i = 0;
    int cantidad = contarAutoEnVenta(nombreArchivo);
    AutoArchivo enVenta;


    *autosEnVenta = (AutoArchivo*) malloc(sizeof(AutoArchivo) * cantidad);

    if (archivo != NULL){
        while (fread(&enVenta, sizeof(AutoArchivo), 1, archivo)> 0){
                (*autosEnVenta)[i] = enVenta;
                i++;
        }


    }else {

    printf("Tuvimos problemas abriendo el archivo");

    }
return i;
}

void mostarAutosEnVenta(AutoArchivo** autosEnVenta, int validos){


    for (int i =0; i< validos; i++){

        mostrarAutoArchivo((*autosEnVenta)[i]);


    }


}



/**
    Funcion que guarda los datos de un auto en formato AutoArchivo
    param: AutoArchivo coche -> el auto a guardar,
           char* nombreArchivo -> puntero al nombre del archivo.

**/

void guardarAutoArchivo(AutoArchivo coche, char *nombreArchivo){
FILE *archivo = fopen(nombreArchivo, "ab");

if (archivo !=NULL){

    fwrite(&coche, sizeof(AutoArchivo), 1, archivo);

} else {

    printf("Tuvimos problemas abriendo el archivo");

}

fclose(archivo);

}
