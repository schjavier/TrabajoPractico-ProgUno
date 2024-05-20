#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AutoArchivo.h"
#include "Patente.h"

/**
Implementacion de la interface AutoArchivo
**/


AutoArchivo cargarAutoArchivo(){

AutoArchivo coche;

printf("Ingrese los datos del auto: \n");

coche.patente = cargarPatente();
printf("\nMarca: ");
fflush(stdin);
gets(coche.marca);

return coche;

}

void mostrarAuto(AutoArchivo coche){

printf("-----------------------------------------\n");
printf("Patente: %s-%s\n", coche.patente.letras, coche.patente.numeros);
printf("Marca : %s\n", coche.marca);
printf("-----------------------------------------\n");
}
