#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AutoArchivo.h"
#include "Patente.h"

/**
    Implementacion de la interface AutoArchivo
**/


/** Función que carga una estructura tipo AutoArchivo.
    Args: none
    Return: AutoArchivo
 **/

AutoArchivo cargarAutoArchivo(){

AutoArchivo coche;

printf("Ingrese los datos del auto: \n");

coche.patente = cargarPatente();
printf("Marca: ");
fflush(stdin);
gets(coche.marca);
printf("Modelo: ");
fflush(stdin);
gets(coche.modelo);
printf("A%co: ", 164);
scanf("%d", &coche.anio);
printf("Kilometraje: ");
scanf("%d", &coche.kms);
printf("DNI titular: ");
scanf("%d", &coche.dniTitular);
printf("Precio de adquisici%cn: ", 162);
scanf("%f", &coche.precioDeAdquisicion);

return coche;

}

/**
    Función que muestra todos los campos de una estructura tipo AutoArchivo.
    Args: AutoArchivo
    Return: none

 **/

void mostrarAutoArchivo(AutoArchivo coche){

printf("-----------------------------------------\n");
printf("Patente: %s-%s\n", coche.patente.letras, coche.patente.numeros);
printf("Marca : %s\n", coche.marca);
printf("Modelo : %s\n", coche.modelo);
printf("A%co : %d\n",164, coche.modelo);
printf("Kilometraje : %d\n", coche.kms);
printf("DNI del titular : %d\n", coche.dniTitular);
printf("Precio de Adquisici%cn : %.2f\n", 162, coche.precioDeAdquisicion);
printf("-----------------------------------------\n");
}

