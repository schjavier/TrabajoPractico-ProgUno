#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "VentaValidaciones.h"
#include "../Persona/Persona.h"

#define archivopersona "personas.bin"

/** \brief Funcion que verifica si el año ingresado no es en el futuro.
 *
 * \param venta Venta
 * \return int 1 si es menor que el año actual, 0 si no
 *
 */
int verificarAnioActual(Venta venta)
{
    int flag = 0;


    if(venta.fecha.anio < 2025)
    {
        flag = 1;
    }
    else
    {
        printf("ERROR: Este a%co todavia no ocurrio", 164);
    }

    return flag;
}


/** \brief Verifica si el año proporcionado es positivo.
 *
 * \param venta Venta representa la venta a cargar
 * \return int 1 si es un numero positivo, 0 si no
 *
 */
int anioPositivo(Venta venta)
{
    int flag = 0;

    if(venta.fecha.anio > 0)
    {
        flag = 1;
    }
    else
    {
        printf("ERROR: el a%co ingresado no es un numero positivo", 164);
    }
    return flag;
}

/** \brief Verifica si el mes proporcionado existe.
 *
 * \param venta Venta
 * \return int
 *
 */
int verificarMes(Venta venta)
{
    int flag = 0;

    if(venta.fecha.mes <= 12)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: el mes ingresado es demasiado grande");
    }
    return flag;
}

int mesPositivo(Venta venta)
{
    int flag = 0;

    if(venta.fecha.mes > 0)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: el mes ingresado no es un numero positivo");
    }
    return flag;
}

int verificarDia(Venta venta)
{
    int flag = 0;

    if(venta.fecha.dia <= 30)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: el dia ingresado excede el numero de dias de un mes");
    }
    return flag;
}

int diaPositivo(Venta venta)
{
    int flag = 0;

    if(venta.fecha.dia > 0)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: el dia ingresado no es un un numero positivo");
    }
    return flag;
}

int verSiDNIexiste(char dni[])
{
    int flag = 0;
    if(cantidadpersonas == -1 && !archivoExiste(archivopersona))
    {
        puts("ERROR: no existe un archivo de personas, registre las personas antes de registrar una venta.");
    }
    else
    {
        int resultado;
        Persona persona;
        int i = 0;
        while(flag == 0 && cantidadpersonas >= i)
        {
            persona = arreglopersona[i];
            resultado = strncmp(dni,persona.dni,strlen(dni));
            if(resultado == 0)
            {
                flag = 1;
            }
            i++;
        }
        if(flag = 0)
        {
            puts("ERROR: no se encontro una persona con el DNI ingresado");
        }
    }

    return flag;
}

int esComprador(char dni[])
{
    int flag = 0;
    int resultado;
    Persona persona;
    int i = 0;

    while(flag == 0 && cantidadpersonas >= i)
        {
            persona = arreglopersona[i];
            resultado = strncmp(dni,persona.dni,strlen(dni));
            if(resultado == 0)
            {
                if(persona.rol == 'C')
                {
                    flag = 1;
                }
            }
            i++;
        }

}

int esConsecionariaVenta(char dni[])
{
    int flag = 0;
    int resultado = 1;
    resultado = strcmp(dni,"00000000");

    if(resultado == 0)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: DNI INGRESADO DIFERENTE A DNI RESERVADO PARA LA CONSESIONARIA '00000000'");
    }
    return flag;
}

int precioVentaPositivo(Venta venta)
{
    int flag = 0;

    if(venta.precioVenta > 0)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: el precio de venta ingresado no es un numero positivo");
    }
    return flag;
}

int gananciaPositiva(Venta venta)
{
    int flag = 0;

    if(venta.ganancia > 0)
    {
        flag = 1;
    }
    else
    {
        puts("ERROR: la ganancia ingresada no es un numero positivo");
    }

    return flag;
}
