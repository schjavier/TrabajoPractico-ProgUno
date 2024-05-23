#ifndef AUTOARCHIVO_H_INCLUDED
#define AUTOARCHIVO_H_INCLUDED

#include "Patente.h"

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


AutoArchivo cargarAutoArchivo();

void mostrarAutoArchivo(AutoArchivo);


#endif // AUTOARCHIVO_H_INCLUDED
