#ifndef VENTAVALIDACIONES_H_INCLUDED
#define VENTAVALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Patente/Patente.h"
#endif // VENTAVALIDACIONES_H_INCLUDED



// VERIFICACIONES
int verificarAnioActual(Venta);
int anioPositivo(Venta);
int mesPositivo(Venta);
int verificarMes(Venta);
int verificarDia(Venta);
int diaPositivo(Venta);
int verSiDNIexiste(char[]);
int esComprador(char[]);
int esConsecionariaVenta(char[]);
int precioVentaPositivo(Venta);
int gananciaPositiva(Venta);
// FIN VERIFICACIONES
