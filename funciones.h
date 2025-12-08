#ifndef FUNCIONES_H
#define FUNCIONES_H


typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[20];   
} Libro;


void leerCadena(char *cadena, int n);
int intPositivo();
int idUnico(Libro libros[], int cont, int id);
int menu();

void registrarLibro(Libro libros[], int *cont);
void listarLibros(Libro libros[], int cont);
int buscarLibro(Libro libros[], int cont);
void actualizarEstado(Libro libros[], int cont);
void eliminarLibro(Libro libros[], int *cont);

#endif
