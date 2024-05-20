
#include "Patente.h"

#ifndef AUTOARCHIVO_H_INCLUDED
#define AUTOARCHIVO_H_INCLUDED

/** Interface de la Libreria relacionada con la estructura AutoArchivo **/

/**
    Definicion de tipo.
**/
typedef struct {
    Patente patente;
    char marca[15];
    char modelo[15];
    int anio;
    int kms;
    int dniTitular;
    float precioDeAdquisicion;
} AutoArchivo;

/** Funcion que carga la estructura AutoArchivo.
    Args.: no
    Return: AutoArchivo
 **/
AutoArchivo cargarAutoArchivo();

/**
    Funcion que sirve para mostrar un AutoArchivo
    Args.: AutoArchivo
    Return: void
**/

void mostrarAuto(AutoArchivo);


#endif // AUTOARCHIVO_H_INCLUDED
