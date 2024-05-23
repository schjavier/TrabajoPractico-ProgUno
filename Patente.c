#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Patente.h"

/**
    Funcion que carga una patente.
    Args: none
    Return: Devuelve una estructura tipo Patente.
**/

Patente cargarPatente(){

Patente patente;

printf("Ingresaremos la patente -> \n" );
printf("Las letras: ");
fflush(stdin);
letrasMayus(gets(patente.letras));
printf("Los numeros: ");
fflush(stdin);
gets(patente.numeros);

return patente;
}

/**
    Funcion que realiza el cambio de minusculas a mayusculas de las
    letras de una patente.
    Args: Recibe una arreglo de caracteres
    Return: none

**/


void letrasMayus(char letras[]){

    int longitud = strlen(letras);
        for (int i = 0; i < longitud; i++){
            letras[i] = toupper(letras[i]);

        }
}
