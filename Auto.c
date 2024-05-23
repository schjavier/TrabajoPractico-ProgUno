#include <stdio.h>
#include <stdlib.h>

#include "Auto.h"

/**

    Implementación de la interface Auto

 **/

void cargarMarca(Auto *coche){

    printf("Ingrese la marca: ");
    fflush(stdin);
    gets((*coche).marca);


}

void cargarModelo(Auto *coche){

    printf("Ingrese el modelo: ");
    fflush(stdin);
    gets((*coche).modelo);

}

void cargarAnio(Auto *coche){

    printf("Ingrese el a%co: ", 164);
    fflush(stdin);
    scanf("%d", &coche->anio);

}

void cargarKms(Auto *coche){

    printf("Ingrese el kilometraje: ");
    fflush(stdin);
    scanf("%d", &coche->kms);

}

void cargarPrecioAd(Auto *coche){

    printf("Ingrese el precio de adquisici%cn: ", 162);
    fflush(stdin);
    scanf("%f", &coche->precioDeAdquisicion);

}

Auto cargarAuto(){

    Auto coche;

    printf("--------- Agregando Auto ---------\n");
    coche.patente = cargarPatente();
    cargarMarca(&coche);
    cargarModelo(&coche);
    cargarAnio(&coche);
    cargarKms(&coche);
    cargarNombre(&coche.titular);
    cargarPrecioAd(&coche);

return coche;
}

void mostrarAuto(Auto *coche){
    printf(":::: DETALLES DEL AUTOMOTOR ::::\n");

    printf(":: PATENTE: %s-%s::\n", coche->patente.letras, coche->patente.numeros);
    printf(":: MARCA: %s::\n", coche->marca);
    printf(":: MODELO: %s::\n", coche->modelo);
    printf(":: A%cO: %d::\n", 165, coche->anio);
    printf(":: KILOMETRAJE: %d::\n", coche->kms);
    printf(":: NOMBRE DEL TITULAR: %s::\n", coche->titular.nombre);
    printf(":: PRECIO DE ADQUISICION: %f::\n", coche->precioDeAdquisicion);

}
