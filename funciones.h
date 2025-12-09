#ifndef FUNCIONES_H
#define FUNCIONES_H


typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[20];
    char estadoFisico[20];
} Libro;

typedef struct {
    int id;
    char nombre[50];
    int idLibroRentado;   
} Usuario;

/* ----- Utilidades ----- */
void leerCadena(char *cadena, int n);
int intPositivo();
int idUnico(Libro libros[], int cont, int id);
int menu();

/* ----- Funciones Libro ----- */
void registrarLibro(Libro libros[], int *cont);
void listarLibros(Libro libros[], int cont);
int buscarLibro(Libro libros[], int cont);
void eliminarLibro(Libro libros[], int *cont);
void editarLibro(Libro libros[], int cont);

/* ----- Funciones Usuario ----- */
void registrarUsuario(Usuario usuarios[], int *contU);
void listarUsuarios(Usuario usuarios[], int contU);
int buscarUsuario(Usuario usuarios[], int contU, Libro libros[], int contL);

/* ----- Préstamos ----- */
void rentarLibro(Libro libros[], int contL, Usuario usuarios[], int contU, int cont);
void devolverLibro(Libro libros[], int contL, Usuario usuarios[], int contU, int cont);

#endif
