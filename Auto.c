#include <stdio.h>
#include <stdlib.h>

#include "Auto.h"

/**
    Implementación de la interface Auto

 **/

/**
    Funcion que carga el campo Marca de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/

void cargarMarca(Auto *coche){

    printf("Ingrese la marca: ");
    fflush(stdin);
    gets((*coche).marca);


}

/**
    Funcion que carga el campo Modelo de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/

void cargarModelo(Auto *coche){

    printf("Ingrese el modelo: ");
    fflush(stdin);
    gets((*coche).modelo);

}

/**
    Funcion que carga el campo Anio de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/


void cargarAnio(Auto *coche){

    printf("Ingrese el a%co: ", 164);
    fflush(stdin);
    scanf("%d", &coche->anio);

}

/**
    Funcion que carga el campo Kms de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/


void cargarKms(Auto *coche){

    printf("Ingrese el kilometraje: ");
    fflush(stdin);
    scanf("%d", &coche->kms);

}

/**
    Funcion que carga el campo PrecioDeAdquisicion de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/


void cargarPrecioAd(Auto *coche){

    printf("Ingrese el precio de adquisici%cn: ", 162);
    fflush(stdin);
    scanf("%f", &coche->precioDeAdquisicion);

}

/**
    Funcion que carga todos los campos de la estructura Auto.
    Args: none
    Return: devuelve una estrucutra de tipo Auto cargada
**/

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

/**
    Funcion que muestra por pantalla, los datos de una estructura tipo Auto
    Args: recibe un puntero a Auto
    Return: none
**/

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
