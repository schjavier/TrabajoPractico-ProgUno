#ifndef PATENTE_H_INCLUDED
#define PATENTE_H_INCLUDED

typedef struct {
char letras[4];
char numeros[4];
} Patente;



Patente cargarPatente();

void letrasMayus(char[]);

#endif // PATENTE_H_INCLUDED
