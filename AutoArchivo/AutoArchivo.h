#ifndef AUTOARCHIVO_H_INCLUDED
#define AUTOARCHIVO_H_INCLUDED

#include "../Patente/Patente.h"
#include "../Auto/Auto.h"
#include "../Persona/Persona.h"

/** Constante con el nombre de archivo, para persistir los usuarios **/
#define ARCHIVO_AUTOS "AutoArchivo.bin"

/**
    Definicion de tipo.
**/
typedef struct {
    Patente patente;
    char marca[15];
    char modelo[15];
    int anio;
    int kms;
    char dniTitular[9];
    float precioDeAdquisicion;
} AutoArchivo;



AutoArchivo cargarAutoArchivo(Auto);

int contarAutoEnVenta(char*);
AutoArchivo buscarAutoEnVenta(char*);
int cargarArrAutosEnVenta(char*, AutoArchivo**);
void mostarAutosEnVenta(AutoArchivo**, int validos);

void mostrarAutoArchivo(AutoArchivo);

void guardarAutoArchivo(AutoArchivo, char*);
void guardarAutoArchivoEnPos(AutoArchivo, char*, int);


#endif // AUTOARCHIVO_H_INCLUDED
