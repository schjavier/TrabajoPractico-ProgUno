#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Auto.h"
#include "AutoValidaciones.h"
#include "AutoMenu.h"
#include "../AutoArchivo/AutoArchivo.h"
#include "../Persona/Persona.h"
#include "../Utiles/Utiles.h"


void autoMenu(){

int opcion;
Auto coche;
AutoArchivo cocheArchivo;
AutoArchivo **enVenta;
Patente patente;
int posicion = 0;
int validosEnVenta = 0;



while (opcion != 0){

    printf("\t..:: Menu Autos ::..\n");
    printf("Que desea hacer?\n");
    printf("0 - Salir\n");
    printf("1 - Agregar un auto\n");
    printf("2 - Modificar un auto\n");
    printf("3 - Listar Autos\n"); // marca modelo patente
    printf("4 - Ver Informaci%cn completa de un Auto\n", 162); // toda la info
    printf("5 - Ver Autos en venta\n"); //marca modelo, patente año
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("El auto cargado se guarda automaticamente en el archivo al finalizar la carga.\n");
            coche = cargarAuto();
            cocheArchivo = cargarAutoArchivo(coche);
            guardarAutoArchivo(cocheArchivo, ARCHIVO_AUTOS);
            break;
        case 2:
            printf("Ingrese la Patente del auto que quiere modificar: \n");
            patente = cargarPatente();
            coche = buscarAutoPatente(patente, &posicion);
            modificarAuto(coche);
            cocheArchivo = cargarAutoArchivo(coche);
            guardarAutoArchivoEnPos(cocheArchivo, ARCHIVO_AUTOS, posicion);
            break;
        case 3:
            cargarEnArregloAutos();
            listarAutos(arregloAutos);
            break;
        case 4:
            printf("Ingrese la Patente del auto que quiere ver: \n");
            patente = cargarPatente();
            coche = buscarAutoPatente(patente, &posicion);
            mostrarAuto(&coche);
            break;
        case 5:
            validosEnVenta = cargarArrAutosEnVenta(ARCHIVO_AUTOS, enVenta);
            mostarAutosEnVenta(enVenta, validosEnVenta);
            break;



        }
    }
}
