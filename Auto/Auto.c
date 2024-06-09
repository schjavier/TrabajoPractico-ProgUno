#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Auto.h"
#include "AutoValidaciones.h"
#include "../AutoArchivo/AutoArchivo.h"
#include "../Persona/Persona.h"


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
    Funcion que carga el nombre del titular del vehiculo.
    Param: Auto* coche -> puntero a una estructura tipo auto
 **/


void cargarTitular(Auto *coche){

    char opcion;
    char dni[9];
    Persona consecionaria = arreglopersona[0] ;
    Persona aux;

    printf("\n\tCargaremos los datos del titular\n");
    printf("\tElija una de estas opciones:\n");
    printf("R - Persona registrada\nN - Persona nueva\nC - Concesionaria\n");
    fflush(stdin);
    scanf("%c", &opcion);

    letrasMayus(&opcion);

    switch(opcion){
    case 'R':
        printf("Ingrese el DNI de la persona: ");
        fflush(stdin);
        gets(dni);
        aux = buscarSegunDNI(dni);
            if (strcmp(aux.dni, "0") == 0){
                printf("la persona no se encuentra en el registro.");

                }else {

                    coche->titular = aux;

                }


        break;

    case 'N':
        agregarPersona();
        coche->titular = arreglopersona[cantidadpersonas];
        break;
    case 'C':
        coche->titular = consecionaria;
        break;
    }



}



/**
    Funcion que carga el campo Kms de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/


void cargarKms(Auto *coche){

    int kms;
    int evaluacion;

    printf("Ingrese el kilometraje: ");
    fflush(stdin);
    scanf("%d", &kms);
    evaluacion = kmsNoNegativo(kms);

    while (evaluacion == 0){
        printf("Los kilometrajes no pueden ser menores a 0\n");
        printf("Vuelva a Intentarlo.\n");
        printf("Ingrese el kilometraje: ");
        fflush(stdin);
        scanf("%d", &kms);
        evaluacion = kmsNoNegativo(kms);
    }

    coche->kms = kms;

}

/**
    Funcion que carga el campo PrecioDeAdquisicion de la estructura.
    Args: recive un puntero a Auto
    Return: none
**/


void cargarPrecioAd(Auto *coche){
    float precio;
    int evaluacion;

    printf("Ingrese el precio de adquisici%cn: ", 162);
    fflush(stdin);
    scanf("%f", &precio);
    evaluacion = PrecioNoNegativo(precio);

        while(evaluacion == 0){
            printf("El precio de Adquisici%cn no puede ser un numero negativo.\n", 162);
            printf("Vuelva a Intentarlo.\n");
            printf("Ingrese el precio de adquisici%cn: ", 162);
            fflush(stdin);
            scanf("%f", &precio);
            evaluacion = PrecioNoNegativo(precio);
        }

    coche->precioDeAdquisicion = precio;
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
    cargarTitular(&coche);
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
    printf(":: KILOMETRAJE: %d kms::\n", coche->kms);
    printf(":: NOMBRE DEL TITULAR: %s::\n", coche->titular.nombre);
    printf(":: PRECIO DE ADQUISICION: %.2f::\n", coche->precioDeAdquisicion);

}

/**

    Funcion que permite modificar un auto.

**/
Auto modificarAuto(Auto *autoAModificar){




}
