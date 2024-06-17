#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include "pila.h"
#include "../Patente/Patente.h"
#endif // VENTA_H_INCLUDED

/**
    DEFINICION DE VARIABLES
**/
typedef struct
{
    int dia;
    int mes;
    int anio;

} Fecha;

typedef struct
{
    Fecha fecha;
    Patente autoAVender;
    float precioVenta;
    float ganancia;
    int dniComprador;
    int dniVendedor;

} Venta;

/**
    FUNCIONES
**/

// CARGAR VENTAS
void menuCargarVenta();
void cargarAnioVenta(Venta);
void cargarMes(Venta);
void cargarDia(Venta);
void cargarDNIComprador(Venta);
void cargarDNIVendedor(Venta);
void cargarPrecioVenta(Venta);
void cargarGanancia(Venta);
void cargarPatenteVenta(Venta);
// FIN CARGAR VENTAS



//void calcGananciasMes();

//void mayorGanancia();



// MUESTRA DE VENTAS
void verVentaFyP();
void verVenta();
void verGanancias(Fecha, float[2][12]);
void verMayor(Pila);

// FIN DE MUESTRA DE VENTAS

/** INGRESAR LA LIBRERIA DE PERSONAS PARA CARGAR Y VERIFICAR EL DNI **/

// VERIFICACIONES
int verificarAnioActual(Venta);
int anioPositivo(Venta);
int mesPositivo(Venta);
int verificarMes(Venta);
int verificarDia(Venta);
int diaPositivo(Venta);
int precioVentaPositivo(Venta);
int gananciaPositiva(Venta);
// FIN VERIFICACIONES
