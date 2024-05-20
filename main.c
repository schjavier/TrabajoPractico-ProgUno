#include <stdio.h>
#include <stdlib.h>
#include "Patente.h"
#include "AutoArchivo.h"

int main()
{
    AutoArchivo coche;
    coche = cargarAutoArchivo();
    mostrarAuto(coche);


        return 0;
}

