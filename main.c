#include <stdio.h>
#include <stdlib.h>

// Librerias Propias
#include "AutoArchivo.h"
#include "Auto.h"


int main()
{
//    AutoArchivo coche;
//    coche = cargarAutoArchivo();
//    mostrarAutoArchivo(coche);

    Auto coche;
    coche = cargarAuto();
    mostrarAuto(&coche);

        return 0;
}

