#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "VentaValidaciones.h"

#define archivoVenta "ventas.bin"

//Variables globales fuera de libreria
    Venta*arregloVentas; // arreglo dinamico de ventas
    cantidadVentas = -1;

void cargarArregloVentasInit()
{
    cantidadVentas = -1;

    if(archivoExiste(archivoVenta) == 1)
    {
        FILE * archi = fopen(archivoVenta, "rb");
        Venta venta;
        while(fread(&venta, sizeof(venta), 1, archi)>0)
        {
            cargarVentaArreglo(venta);
        }
        fclose(archi);
    }
    else
    {
        puts("El archivo ventas no existe.");
    }
}

/** \brief
 *
 * \return void
 *
 */
//void verVentaFyP(){
//
//    FILE * verFyP = fopen("registroVentas.bin", "rb");
//
//    Venta aLeer;
//
//    if(verFyP != NULL){
//        while(fread(&aLeer, sizeof(Venta), 1, verFyP) >0){
//
//        printf("\n------------------------------------");
//        printf("\n\tFecha: %i / %i / %i", aLeer.fecha.dia, aLeer.fecha.mes, aLeer.fecha.anio);
//        printf("\n\tPatente: ");
//        printf("%c ", aLeer.autoAVender.letras);
//        printf("%c", aLeer.autoAVender.numeros);
//
//        printf("\n------------------------------------");
//
//        }
//    }
//}

/** \brief
 *
 * \return void
 *
 */
//void verVenta(){
//
//    FILE * verReg = fopen("registroVentas.bin", "rb");
//
//    Venta aLeer;
//
//    if(verReg != NULL){
//        while(fread(&aLeer, sizeof(Venta), 1, verReg) >0){
//            printf("------------------------------------");
//            printf("Fecha: %i / %i / %i \n", aLeer.fecha.dia, aLeer.fecha.mes, aLeer.fecha.anio);
//            printf("Patente: %s %s \n", aLeer.autoAVender.letras, aLeer.autoAVender.numeros);
//            printf("Precio de venta: %f \n", aLeer.precioVenta);
//            printf("Ganancia: %f \n", aLeer.ganancia);
//            printf("DNI del comprador: %i \n", aLeer.dniComprador);
//            printf("DNI del vendedor: %i \n", aLeer.dniVendedor);
//            printf("------------------------------------");
//        }
//        fclose(verReg);
//    }
//}

/** \brief Muestra un menu
 *
 * \return void
 *
 */
void menuCargarVenta()
{

    Venta venta;

    system("cls");
    puts("--------- Agregando venta ---------");

    cargarAnioVenta(venta);
    cargarMes(venta);
    cargarDia(venta);
    cargarPrecioVenta(venta);
    cargarGanancia(venta);


}


/** \brief
 *
 * \param venta Venta representa la venta que esta siendo cargada
 * \return void
 *
 */
void cargarAnioVenta(Venta venta)
{
    int verificado = 0;

    while(verificado == 0)
    {
        printf("A%co de la venta?\n", 164);
        scanf("%i", &venta.fecha.anio);

        if(verificarAnioActual(venta) == 1 && anioPositivo(venta) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }
}

/** \brief
 *
 * \param venta Venta
 * \return void
 *
 */
void cargarMes(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("Mes de la venta?");
        scanf("%i", &venta.fecha.mes);

        if(verificarMes(venta) == 1 && mesPositivo(venta) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }

}

/** \brief
 *
 * \param venta Venta
 * \return void
 *
 */
void cargarDia(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("Dia de la venta?");
        scanf("%i", &venta.fecha.dia);

        if(verificarDia(venta) == 1 && diaPositivo(venta) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }

}

void cargarDNIComprador(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("DNI del comprador?");
        scanf("%s", &venta.dniComprador);

        if(verificarEnteros(venta.dniComprador) == 1 && verificarDNI(venta.dniComprador) == 1 && esConsecionaria(venta.dniComprador) == 0 && verSiDNIexiste(venta.dniComprador) == 1 && esComprador(venta.dniComprador))
        {
            verificado = 1;
        }
    }
}

void cargarDNIVendedor(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("DNI del vendedor?");
        scanf("%s", &venta.dniVendedor);

        if(verificarEnteros(venta.dniComprador) == 1 && verificarDNI(venta.dniVendedor) == 1 && esConsecionariaVenta(venta.dniComprador) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }
}

/** \brief
 *
 * \param venta Venta
 * \return void
 *
 */
void cargarPrecioVenta(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("Precio de la venta?");
        scanf("%i", &venta.precioVenta);

        if(precioVentaPositivo(venta) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }
}

/** \brief
 *
 * \param venta Venta
 * \return void
 *
 */
void cargarGanancia(Venta venta)
{
    int verificado = 0;
    while(verificado == 0)
    {
        puts("Ganancia de la venta?");
        scanf("%i", &venta.ganancia);

        if(gananciaPositiva(venta) == 1)
        {
            verificado = 1;
        }

        printf("\n");
    }
}

/** \brief
 *
 * \param venta Venta
 * \return void
 *
 */
void cargarPatenteVenta(Venta venta)
{
    printf("Ingresaremos la patente -> \n" );
    printf("Las letras: ");

    fflush(stdin);
    letrasMayus(gets(venta.autoAVender.letras));

    printf("Los numeros: ");
    fflush(stdin);
    gets(venta.autoAVender.numeros);
}

/** \brief Hace espacio en el arreglo de ventas para cargar una en el mismo.
 *
 * \param venta Venta Recibe una venta para registrarla en el arreglo
 * \return void
 *
 */
void cargarVentaArreglo(Venta venta)
{
    allocarEspacioVenta(&arregloVentas);
    arregloVentas[cantidadVentas] = venta;
}

/** \brief
 *
 * \param Venta**arreglo
 * \return void
 *
 */
void allocarEspacioVenta(Venta**arreglo)
{
    cantidadVentas++;
    *arreglo = realloc(*arreglo, sizeof(Venta) * (cantidadVentas+1));
}

