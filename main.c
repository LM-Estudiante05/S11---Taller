#include <stdio.h>
#include "funciones.h"

int main() {
    Libro libros[10];
    int cont = 0;
    int opc;

    do {
        opc = menu();

        switch (opc) {
            case 1:
                registrarLibro(libros, &cont);
                break;

            case 2:
                listarLibros(libros, cont);
                break;

            case 3:
                buscarLibro(libros, cont);
                break;

            case 4:
                actualizarEstado(libros, cont);
                break;

            case 5:
                eliminarLibro(libros, &cont);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

        printf("\n");
        
    } while (opc != 6);

    return 0;
}