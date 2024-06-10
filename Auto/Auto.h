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

Auto *arregloAutos;
int cantidadAutos;

void cargarMarca(Auto*);
void cargarModelo(Auto*);
void cargarAnio(Auto*);
void cargarKms(Auto*);
void cargarPrecioAd(Auto*);
void cargarTitular(Auto*);

Auto cargarAuto();

void mostrarAuto(Auto*);


/** Funciones para la busqueda y edicion de un Auto **/
int posicionAuto(Patente*);// no se usa ni esta definida
Auto buscarAutoPatente(Patente, int*);
Auto modificarAuto(Auto);

void cargarAutoArreglo(Auto);
void designarEspacioAuto(Auto**);
void cargarEnArregloAutos();

void listarAutos();

#endif // AUTO_H_INCLUDED
