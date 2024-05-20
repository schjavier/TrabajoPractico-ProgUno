#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Patente.h"

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

void letrasMayus(char letras[]){

    int longitud = strlen(letras);
        for (int i = 0; i < longitud; i++){
            letras[i] = toupper(letras[i]);

        }
}
