#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define archivopersona "personas.bin"

/// FUNCIONALIDAD ///

// CARGA DE ESTUDIANTES (EN MEMORIA)
void agregarPersona()
{
    Persona persona;

    system("cls");
    puts("--------- Agregando persona ---------");
    printf("\n");
    fflush(stdin);

    cargarDNI(&persona);
    cargarNombre(&persona);
    cargarTEL(&persona);
    cargarDIR(&persona);
    cargarRol(&persona);

    verPersonaFull(persona);
    verPersonaMin(persona);

    guardarPersonaAFile(persona);
}

void cargarDNI(Persona* persona)
{
    int verificado = 0;
    char dniverificado[15];
    while(verificado == 0)
    {
        puts("DNI de la persona?");
        scanf("%s",&dniverificado);
        printf("\n");
        fflush(stdin);

        verificado = verificarEnteros(dniverificado);
        //verificado = verificarDNI(dniverificado);
    }
    strcpy((*persona).dni,dniverificado);
}

void cargarNombre(Persona* persona)
{
    puts("Nombre completo de la persona?");
    fflush(stdin);
    gets((*persona).nombre);
}

void cargarTEL(Persona* persona)
{
    int verificado = 0;
    char telefonoverificado[15];
    while(verificado == 0)
    {
        puts("Telefono de la persona?");
        scanf("%s",&telefonoverificado);
        printf("\n");
        fflush(stdin);
        verificado = verificarEnteros(telefonoverificado);
    }
    strcpy((*persona).telefono,telefonoverificado);
}

void cargarDIR(Persona* persona)
{
    puts("Direccion del cliente?");
    fflush(stdin);
    gets((*persona).direccion);
    printf("\n");
}

void cargarRol(Persona* persona)
{
    char rol;
    int verificar = 0;
    while(verificar == 0)
    {
        puts("Rol del cliente? (Vendedor o Comprador)");
        fflush(stdin);
        scanf("%c",&rol);
        pasarAMayus(&rol);
        printf("\n");
        verificar = verificarRol(rol);
    }
    (*persona).rol = rol;
}
// FIN DE CARGA DE PERSONAS.

// VERIFICACIONES
int verificarEnteros(char cadena[])
{
    int flag = 1;
    int largo = strlen(cadena);
    for(int i = 0; i<largo; i++){
        char x = cadena[i];
        if(isdigit(x)==0)
        {
            flag = 0;
        }
    }

    if(flag == 0)
    {
        puts("Error, no es un numero.");
    }

    return flag;
}

int verificarDNI(char dni[])
{
    int flag = 0;
    int largo = strlen(dni);
    if(largo >= 8)
    {
        flag = 1;
    }
    else
    {
        puts("Error. El DNI no es suficientemente largo");
    }
    return flag;
}


int verificarRol(char rol)
{
    int verificar = 0;
    if(rol == 'C' || rol == 'V')
    {
        verificar = 1;
    }
    else
    {
        puts("Error. Usar C o V");
    }
    return verificar;
}
// FIN DE VERIFICACIONES

// ACCIONES DE ARCHIVOS CON PERSONAS
void guardarPersonaAFile(Persona persona)
{
    FILE * arch = fopen(archivopersona,"ab");

    if(arch != NULL)
    {
        puts("Guardando...");
        fwrite(&persona,sizeof(Persona),1,arch);
    }
}



// FIN DE ACCIONES DE GUARDADO PERSONAS EN ARCHIVO



// MUESTRA DE ALUMNOS

void mostrarPersonasMenu()
{
    fflush(stdin);
    char eleccion;
    puts("Mostrar completo (C) o Mostrar minimo (M)?");
    puts("Cualquier otra cosa para salir");

    scanf("%c",&eleccion);
    pasarAMayus(&eleccion);

    switch(eleccion)
    {
        case 'C':
            mostrarPersonaFull();
            break;
        case 'M':
            mostrarPersonaMin();
            break;
        default:
            puts("Saliendo...");
            break;
    }
}

void mostrarPersonaFull()
{
    FILE * arch = fopen(archivopersona,"rb");

    if(arch != NULL)
    {
        Persona persona;
        while(fread(&persona,sizeof(Persona),1,arch)>0)
        {
            verPersonaFull(persona);
        }
        fclose(arch);
    }
}

void mostrarPersonaMin()
{
    FILE * arch = fopen(archivopersona,"rb");

    if(arch != NULL)
    {
        Persona persona;
        while(fread(&persona,sizeof(Persona),1,arch)>0)
        {
            verPersonaMin(persona);
        }
        fclose(arch);
    }
}


void verPersonaFull(Persona persona)
{
    puts("------------------");
    printf("DNI: %s\n",persona.dni);
    printf("Nombre: %s\n",persona.nombre);
    printf("TEL: %s\n",persona.telefono);
    printf("Direccion: %s\n",persona.direccion);
    traducirRolCliente(persona.rol);
    puts("------------------");
}

void verPersonaMin(Persona persona)
{
    puts("------------------");
    printf("DNI: %s\n",persona.dni);
    printf("Nombre: %s\n",persona.nombre);
    printf("TEL: %s\n",persona.telefono);
    puts("------------------");
}
// FIN DE

/// AYUDANTES ///
void pasarAMayus(char*texto)
{
    *texto = toupper(*texto);
}

void traducirRolCliente(char rol)
{
    switch(rol)
    {
        case 'C':
            puts("ROL: Cliente");
            break;
        case 'V':
            puts("ROL: Vendedor");
            break;
        default:
            puts("ROL: [DESCONOCIDO, CAMBIAR!].");
            break;
    }
}


