#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "../Persona/Persona.h"
#include "../Patente/Patente.h"



/**
    interface de la la estructura auto


**/

/**
    Declaracion de tipo.

 **/

typedef struct {

    Patente patente;
    char marca[15];
    char modelo[20];
    int anio;
    int kms;
    Persona titular;
    float precioDeAdquisicion;

} Auto;

void cargarMarca(Auto*);
void cargarModelo(Auto*);
void cargarAnio(Auto*);
void cargarKms(Auto*);
void cargarPrecioAd(Auto*);
void cargarTitular(Auto*);

Auto cargarAuto();

void mostrarAuto(Auto*);


/** Funciones para la busqueda y edicion de un Auto **/
int posicionAuto(Patente*);
Auto buscarAuto(Patente*);
Auto modificarAuto(Auto*);



#endif // AUTO_H_INCLUDED
