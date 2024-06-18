#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "../Persona/Persona.h"
#include "../Patente/Patente.h"
#include "../AutoArchivo/AutoArchivo.h"



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
    char kms[8];
    Persona titular;
    float precioDeAdquisicion;

} Auto;

Auto *arregloAutos;
int cantidadAutos;

Auto *arregloAutosEnVenta;
int cantidadEnVenta;

Auto *arregloAutosNuevos;
int cantidadNuevos;

void cargarMarca(Auto*);
void cargarModelo(Auto*);
void cargarAnio(Auto*);
void cargarKms(Auto*);
void cargarPrecioAd(Auto*);
void cargarTitular(Auto*);

Auto cargarAuto();

void mostrarAuto(Auto);


/** Funciones para la busqueda y edicion de un Auto **/
int posicionAuto(Patente*);// no se usa ni esta definida
Auto buscarAutoPatente(Patente, int*);
Auto modificarAuto(Auto);

Persona buscarTitular(char[]);

void cargarAutoArreglo(Auto);
void designarEspacioAuto(Auto**);
void cargarEnArregloAutosInit();

void mostarArrAutos();

void listarAutos();

Auto convertirAuto(AutoArchivo);

/**------------------------------------------punto 5------------------------------------------------**/

int  enVenta(Auto);
void designarEspacioAutoVenta(Auto**);
void cargarAutoEnVentaEnArreglo(Auto);
void cargarArregloAutosEnVentaInit();

/**----------------------------------------Ordenacion--------------------------------------------**/
void designarEspacioAutoNuevos(Auto**);
void cargarAutoNuevoEnArreglo(Auto);
void cargarArregloAutosNuevosInit();

int esNuevo(Auto);
int encontrarMenor(Auto[], int, int);
void ordenarAutos(Auto[], int);
void mostrarAutosNuevos();


#endif // AUTO_H_INCLUDED
