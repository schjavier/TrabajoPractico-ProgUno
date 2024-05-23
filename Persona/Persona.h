#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
	char dni[9];
	char nombre[50];
	char telefono[14];
	char direccion[100];
	char rol; //comprador o vendedor, SE TRADUCE EN RUNTIME
} Persona;

/// FUNCIONALIDAD ///
// CARGA DE PERSONAS (MEMORIA)
void agregarPersona();
void cargarDNI(Persona*);
void cargarNombre(Persona*);
void cargarTEL(Persona*);
void cargarDIR(Persona*);
void cargarRol(Persona*);
// FIN DE CARGA DE PERSONAS.

// GUARDADO A ARCHIVOS
void guardarPersonaAFile(Persona);

//

// MUESTRA DE PERSONAS
void mostrarPersonasMenu(); // LECTURA DE ARCHIVO

void mostrarPersonaFull(); // Muestra todos las personas completamente
void mostrarPersonaMin(); // Muestra todas las personas minimamente

void verPersonaFull(Persona);
void verPersonaMin(Persona);
// FIN DE MUESTRA DE PERSONAS

// VERIFICACIONES
int verificarEnteros(char[]);

int verificarDNI(char[]);
int verificarRol(char);
// FIN VERIFICACIONES

/// AYUDANTES ///
void pasarAMayus(char*);



void traducirRolCliente(char);




#endif // PERSONA_H_INCLUDED
