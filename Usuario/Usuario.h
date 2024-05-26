#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct {

    char nombreUsuario[20];
    char contrasenia[15];
    int pin;

} Usuario;

void crearUsuario(Usuario*);
void guardarUsuario(char[], Usuario*);
void autenticar(Usuario*);






#endif // USUARIO_H_INCLUDED
