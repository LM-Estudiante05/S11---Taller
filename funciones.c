#include <stdio.h>
#include <string.h>
#include "funciones.h"


void leerCadena(char *cadena, int n) {
    fflush(stdin);
    fgets(cadena, n, stdin);
    int len = strlen(cadena) - 1;
    if (len >= 0 && cadena[len] == '\n')
        cadena[len] = '\0';
}

int intPositivo() {
    int num;
    int aux;
    do {
        aux = scanf("%d", &num);
        if (aux != 1 || num < 0) {
            printf("Dato inválido, ingrese nuevamente: ");
            fflush(stdin);
        }
    } while (aux != 1 || num < 0);
    return num;
}


int idUnico(Libro libros[], int cont, int id) {
    for (int i = 0; i < cont; i++) {
        if (libros[i].id == id)
            return 0;  
    }
    return 1; 
}


int menu() {
    int opc;
    printf("\n===== MENU BIBLIOTECA =====\n");
    printf("1. Registrar libro\n");
    printf("2. Listar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    opc = intPositivo();
    return opc;
}


void registrarLibro(Libro libros[], int *cont) {
    if (*cont >= 10) {
        printf("No se pueden registrar más libros (máximo 10).\n");
        return;
    }

    printf("\n--- Registrar Libro ---\n");

    int id;
    do {
        printf("Ingrese ID del libro: ");
        id = intPositivo();
        if (!idUnico(libros, *cont, id))
            printf("Ese ID ya existe. Ingrese otro.\n");
    } while (!idUnico(libros, *cont, id));

    libros[*cont].id = id;

    printf("Ingrese titulo: ");
    leerCadena(libros[*cont].titulo, 100);

    printf("Ingrese autor: ");
    leerCadena(libros[*cont].autor, 50);

    printf("Ingrese año de publicacion: ");
    libros[*cont].anio = intPositivo();

    strcpy(libros[*cont].estado, "Disponible");

    (*cont)++;
    printf("Libro registrado con exito.\n");
}


void listarLibros(Libro libros[], int cont) {
    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\nID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < cont; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado);
    }
}


int buscarLibro(Libro libros[], int cont) {
    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return -1;
    }

    int modo;
    printf("Buscar por:\n1. ID\n2. Título\n>> ");
    modo = intPositivo();

    if (modo == 1) {
        int id;
        printf("Ingrese ID: ");
        id = intPositivo();
        for (int i = 0; i < cont; i++) {
            if (libros[i].id == id) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       libros[i].id,
                       libros[i].titulo,
                       libros[i].autor,
                       libros[i].anio,
                       libros[i].estado);
                return i;
            }
        }
        printf("No se encontró un libro con ese ID.\n");
        return -1;

    } else if (modo == 2) {
        char titulo[100];
        printf("Ingrese título: ");
        fflush(stdin);
        leerCadena(titulo, 100);

        for (int i = 0; i < cont; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       libros[i].id,
                       libros[i].titulo,
                       libros[i].autor,
                       libros[i].anio,
                       libros[i].estado);
                return i;
            }
        }
        printf("No se encontró un libro con ese titulo.\n");
        return -1;
    }

    printf("Opcion invalida.\n");
    return -1;
}


void actualizarEstado(Libro libros[], int cont) {
    int pos = buscarLibro(libros, cont);
    if (pos == -1) return;

    if (strcmp(libros[pos].estado, "Disponible") == 0)
        strcpy(libros[pos].estado, "Prestado");
    else
        strcpy(libros[pos].estado, "Disponible");

    printf("Estado actualizado correctamente.\n");
}


void eliminarLibro(Libro libros[], int *cont) {
    int pos = buscarLibro(libros, *cont);
    if (pos == -1) return;

    for (int i = pos; i < *cont - 1; i++) {
        libros[i] = libros[i + 1];
    }
    (*cont)--;

    printf("Libro eliminado correctamente.\n");
}
