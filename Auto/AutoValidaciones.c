
#include "AutoValidaciones.h"
#include "../Persona/Persona.h"

/** .falta verificar, que no se pueda agregar cuando una persona tiene persona.rol
    no puede ser comprador para agregarle a un auto tiene que tener rol vendedor
    .

 **/

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



int esVendedor(Persona titular){

    int flag = 0;
    if (titular.rol == 'V'){
        flag = 1;

    } else {
        printf("La persona no tiene el rol de Vendedor");
    }

    return flag;
}
