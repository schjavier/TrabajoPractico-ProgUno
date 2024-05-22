#include <stdio.h>
#include <stdlib.h>

// Librerias Propias
#include "AutoArchivo.h"
#include "Auto.h"


int main()
{
    AutoArchivo coche;
    coche = cargarAutoArchivo();
    mostrarAuto(coche);


        return 0;
}

