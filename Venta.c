#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"

//	3h. Ver ventas. (fecha y patente).

// doxyblocks (investigar para que es esto)
/** \brief que hace la funcion
 *
 * \param venta Venta
 * \return void
 *
 */

void verVentaFyP(){

    FILE * verFyP = fopen("registroVentas.bin", "rb");

    Venta aLeer;

    if(verFyP != NULL){
        while(fread(&aLeer, sizeof(Venta), 1, verFyP) >0){

        printf("\n------------------------------------");
        printf("\n\tFecha: %i / %i / %i", aLeer.fecha.dia, aLeer.fecha.mes, aLeer.fecha.anio);
        printf("\n\tPatente: ");

        for(int i = 0; i < 3; i++){
            printf("%c ", aLeer.autoAVender.letras[i]);
        }

        for(int i = 0; i < 3; i++){
            printf(" %c", aLeer.autoAVender.numeros[i]);
        }
        printf("\n------------------------------------");

        }
    }
}

/**
    funcion que recibe una venta y muestra en la pantalla su fecha y su patente.
    la funcion es de tipo void, sin retorno.

**/

//	3i. Ver venta (toda la info).

void verVenta(){

    FILE * verReg = fopen("registroVentas.bin", "rb");

    Venta aLeer;

    if(verReg != NULL){
        while(fread(&aLeer, sizeof(Venta), 1, verReg) >0){
            printf("\n------------------------------------");
            printf("\n\tFecha: %i / %i / %i", aLeer.fecha.dia, aLeer.fecha.mes, aLeer.fecha.anio);
            printf("\n\tPatente: ");

            for(int i = 0; i < 3; i++){
                printf("%c ", aLeer.autoAVender.letras[i]);
            }

            for(int i = 0; i < 3; i++){
                printf(" %c", aLeer.autoAVender.numeros[i]);
            }

            printf("\n\tPrecio de venta: %f", aLeer.precioVenta);
            printf("\n\tGanancia: %f", aLeer.ganancia);
            printf("\n\tDNI del comprador: %i", aLeer.dniComprador);
            printf("\n\tDNI del vendedor: %i", aLeer.dniVendedor);
            printf("\n------------------------------------");
        }
        fclose(verReg);
    }
}

/**
    funcion que recibe una variable de tipo venta y la muestra en su totalidad en la pantalla
    la funcion es de tipo void y no posee retorno
**/

//	3j. Registrar una venta.
void regVenta(){
    Venta aCargar;

    FILE * registro = fopen("registroVentas.bin", "ab");

    if(registro != NULL){

        printf("Vamos a cargar los datos de la venta, empecemos por la fecha\nIngrese el anio: ");
        scanf("%i", &aCargar.fecha.anio);

        printf("Ingrese el mes: ");
        scanf("%i", &aCargar.fecha.mes);

        printf("Ingrese el dia: ");
        scanf("%i", &aCargar.fecha.dia);

        printf("ahora registremos la patente\nprimero las letras: ");
        fflush(stdin);
        gets(aCargar.autoAVender.letras);

        printf("Ahora ingrese los numeros: ");
        gets(aCargar.autoAVender.numeros);

        printf("Ingrese el precio de venta: ");
        scanf("%f", &aCargar.precioVenta);

        printf("Ingrese la ganancia de la venta: ");
        scanf("%f", &aCargar.ganancia);

        printf("Ingrese el dni del vendedor: ");
        scanf("%i", &aCargar.dniVendedor);

        printf("Ingrese el dni del comprador: ");
        scanf("%i", &aCargar.dniComprador);
        fwrite(&aCargar, sizeof(Venta), 1, registro);

        fclose(registro);
    }
}

//  3k. Calcular cuanto se recaudo en determinado mes, de determinado año.

void calcGanancias(){
    Fecha aBuscar;
    Venta aVer;
    float ganancias[2][12];

    printf("Ingrese el anio en el cual vamos a buscar: ");
    scanf("%i", &aBuscar.anio);

    printf("Por ultimo ingrese el mes: ");
    scanf("%i", &aBuscar.mes);


    FILE * calcGan = fopen("registroVentas.bin", "rb");

    if(calcGan != NULL){
        while(fread(&aVer, sizeof(Venta), 1, calcGan) >0)
            {
                if(aVer.fecha.anio == aBuscar.anio && aVer.fecha.mes == aBuscar.mes){

                    ganancias[0][aBuscar.mes] = aVer.fecha.mes;
                    ganancias[1][aBuscar.mes] = ganancias[1][aBuscar.mes] + aVer.ganancia;
            }
        }
        fclose(calcGan);
    }
    verGanancias(aBuscar, ganancias);
}



void verGanancias(Fecha aBuscar, float ganancias[2][12]){

    printf("La suma de ganancias en ");
    switch (aBuscar.mes) {
        case 1:
            printf("enero");
            break;
        case 2:
            printf("febrero");
            break;
        case 3:
            printf("marzo");
            break;
        case 4:
            printf("abril");
            break;
        case 5:
            printf("mayo");
            break;
        case 6:
            printf("junio");
            break;
        case 7:
            printf("julio");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("septiembre");
            break;
        case 10:
            printf("octubre");
            break;
        case 11:
            printf("noviembre");
            break;
        case 12:
            printf("diciembre");
            break;
        default:
            printf("ERROR Mes fuera de rango");
            break;
        }
        printf(" fue de $ %f\n", ganancias[1][aBuscar.mes]);
}

/**
    funcion que
**/

//	3l. Calcular cuál fue la venta que generó mayor ganancia hasta el momento.

void mayorGanancia(){
    Pila mayor, aux;
    inicpila(&mayor);
    inicpila(&aux);

    Venta aVer;

    FILE * buscarMayor = fopen("registroVentas.bin", "rb");

    if(buscarMayor != NULL){
        while(fread(&aVer, sizeof(Venta), 1, buscarMayor) > 0){
            apilar(&aux, aVer.ganancia);
            }

        apilar(&mayor, desapilar(&aux));

        while(!pilavacia(&aux)){
            if(tope(&aux) > tope(&mayor)){
                apilar(&mayor, desapilar(&aux));
            }else{
                desapilar(&aux);
            }
        }
    fclose(buscarMayor);

    verMayor(mayor);
    }
}

/**
    funcion que lee el archivo de ventas y guarda en una pila la mayor ganancia en forma de entero
    funcion void que no recibe ni devuelve nada.
**/

void verMayor(Pila mayor){
    Venta aMostrar;
    Pila cambio;
    inicpila(&cambio);

    FILE * mostrarMayor = fopen("registroVentas.bin", "rb");

    if(mostrarMayor != NULL){
    while(fread(&aMostrar, sizeof(Venta), 1, mostrarMayor) > 0){

        apilar(&cambio, aMostrar.ganancia);

        if(tope(&mayor) == tope(&cambio)){
            printf("\n------------------------------------");
            printf("\n\tFecha: %i / %i / %i", aMostrar.fecha.dia, aMostrar.fecha.mes, aMostrar.fecha.anio);
            printf("\n\tPatente: ");

            for(int i = 0; i < 3; i++){
                printf("%c ", aMostrar.autoAVender.letras[i]);
            }

            for(int i = 0; i < 3; i++){
                printf(" %c", aMostrar.autoAVender.numeros[i]);
            }

            printf("\n\tPrecio de venta: %f", aMostrar.precioVenta);
            printf("\n\tGanancia: %f", aMostrar.ganancia);
            printf("\n\tDNI del comprador: %i", aMostrar.dniComprador);
            printf("\n\tDNI del vendedor: %i", aMostrar.dniVendedor);
            printf("\n------------------------------------");
      }
    }
  fclose(mostrarMayor);
  }
}

/**
    funcion que recibe una pila con la mayor ganancia en el archivo e ingresa para leerlo, cambiando la ganancia de cada venta a entero para revisar si es la misma y mostrandola por pantalla
    funcion void que recibe una pila y no devuelve nada.
**/

