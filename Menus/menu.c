#include <stdio.h>
#include <stdlib.h>

void cargarMenuPrincipal()
{
    cargarEnArregloPersonasInit(); // Agregen sus funciones inicializadoras

    char enprograma = 's';
    int funcion = 0;
    while(enprograma == 's')
    {
        mostrarOpciones();
        fflush(stdin);
        scanf("%i",&funcion);

        switch(funcion) // Agregen sus funciones
        {
            case 1:
                menuCargaPersonas();
                break;
            case 2:
                menuVerPersonas();
                break;
            default:
                printf("?");
                break;
        }


        puts("Seguir en el programa?");
        scanf("%c",&enprograma);
    }
}

void mostrarOpciones()
{
    puts("1- Cargar/Modificar personas");
    puts("2- Mostrar personas");
}
