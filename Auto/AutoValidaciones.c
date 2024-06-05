
#include "AutoValidaciones.h"

/**
    Funcion que valida si el valor pasado como precio de adquisicion, es positivo.
    Args: Float que representa el precio de adquisicion.
    Return: 0 si es negativo
            1 si es positivo

**/

int PrecioNoNegativo(float valor)
{

    int retorno;

    if (valor < 0){

        retorno = 0;
    }
    else{

        retorno = 1;
    }

    return retorno;

}

int kmsNoNegativo(int kms){
int retorno = 1;

if (kms < 0){
    retorno = 0;
}

return retorno;
}
