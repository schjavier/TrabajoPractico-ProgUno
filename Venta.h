#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
//#include "patente.h"
#endif // VENTA_H_INCLUDED

/**
    definicion de variables struct
**/
typedef struct
{
    int dia;
    int mes;
    int anio;

} Fecha;

typedef struct
{
    char letras[3];
    char numeros[3];
} Patente;

typedef struct
{
    Fecha fecha;
    Patente autoAVender;
    float precioVenta;
    float ganancia;
    int dniComprador;
    int dniVendedor;

} Venta;


void verVentaFyP();

void verVenta();

void regVenta();

void calcGanancias();

void verGanancias(Fecha, float[2][12]);

void mayorGanancia();

void verMayor(Pila);
