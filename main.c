#include <stdio.h>
#include "funciones.h"

int main() {
    Libro libros[10];
    Usuario usuarios[10];
    int contLib = 0;
    int contUsu = 0;
    int opc;

    do {
        opc = menu();

        switch (opc) {
            case 1: registrarLibro(libros, &contLib); break;
            case 2: listarLibros(libros, contLib); break;
            case 3: buscarLibro(libros, contLib); break;
            case 4: eliminarLibro(libros, &contLib); break;

            case 5: registrarUsuario(usuarios, &contUsu); break;
            case 6: listarUsuarios(usuarios, contUsu); break;
            case 7: buscarUsuario(usuarios, contUsu, libros, contLib); break;

            case 8: rentarLibro(libros, contLib, usuarios, contUsu, contLib); break;
            case 9: devolverLibro(libros, contLib, usuarios, contUsu, contLib); break;

            case 10: editarLibro(libros, contLib); break;

            case 11:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opc != 11);

    return 0;
}
