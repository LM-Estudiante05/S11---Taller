#include <stdio.h>
#include <string.h>
#include "funciones.h"

/* ==================== UTILIDADES ==================== */

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
    for (int i = 0; i < cont; i++)
        if (libros[i].id == id) return 0;
    return 1;
}

int menu() {
    int opc;
    printf("\n===== MENU BIBLIOTECA =====\n");
    printf("1. Registrar libro\n");
    printf("2. Listar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Eliminar libro\n");
    printf("5. Registrar usuario\n");
    printf("6. Listar usuarios\n");
    printf("7. Buscar usuario\n");
    printf("8. Rentar libro\n");
    printf("9. Devolver libro\n");
    printf("10. Editar libro\n");
    printf("11. Salir\n");
    printf("Seleccione una opcion: ");
    opc = intPositivo();
    return opc;
}

/* ==================== LIBROS ==================== */

void registrarLibro(Libro libros[], int *cont) {
    if (*cont >= 10) {
        printf("No se pueden registrar mas libros (maximo 10).\n");
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

    printf("Ingrese anio de publicacion: ");
    libros[*cont].anio = intPositivo();

    int opcEstadoFisico = 0;
    do {
        printf("Ingrese estado fisico (1. Buen estado, 2. Estado medio, 3. Danado): ");
        opcEstadoFisico = intPositivo();
        if (opcEstadoFisico < 1 || opcEstadoFisico > 3)
            printf("Opcion invalida. Intente nuevamente.\n");
    } while (opcEstadoFisico < 1 || opcEstadoFisico > 3);

    switch (opcEstadoFisico) {
        case 1: strcpy(libros[*cont].estadoFisico, "Buen estado"); break;
        case 2: strcpy(libros[*cont].estadoFisico, "Estado medio"); break;
        case 3: strcpy(libros[*cont].estadoFisico, "Dañado"); break;
    }

    strcpy(libros[*cont].estado, "Disponible");

    (*cont)++;
    printf("Libro registrado con exito.\n");
}

void listarLibros(Libro libros[], int cont) {
    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\nID\tTitulo\t\tAutor\t\tAAnio\tEstado\t\tEstado fisico\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < cont; i++) {
        printf(" %d \t   %s \t    %s \t   %d \t  %s \t   %s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado,
               libros[i].estadoFisico);
    }
}

int buscarLibro(Libro libros[], int cont) {
    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return -1;
    }

    int id;
    printf("Ingrese ID del libro: ");
    id = intPositivo();

    for (int i = 0; i < cont; i++) {
        if (libros[i].id == id) {
            printf("\nLibro encontrado:\n");
                 printf("ID: %d\nTitulo: %s\nAutor: %s\nAAnio: %d\nEstado: %s\nEstado fisico: %s\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio,
                     libros[i].estado,
                     libros[i].estadoFisico);
            return i;
        }
    }

    printf("Libro no encontrado.\n");
    return -1;
}

void eliminarLibro(Libro libros[], int *cont) {
    int pos = buscarLibro(libros, *cont);
    if (pos == -1) return;

    for (int i = pos; i < *cont - 1; i++)
        libros[i] = libros[i + 1];
    (*cont)--;

    printf("Libro eliminado correctamente.\n");
}

void editarLibro(Libro libros[], int cont) {
    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    int id;
    printf("Ingrese ID del libro a editar: ");
    id = intPositivo();

    int pos = -1;
    for (int i = 0; i < cont; i++)
        if (libros[i].id == id) pos = i;

    if (pos == -1) {
        printf("Libro no encontrado.\n");
        return;
    }

    printf("Libro seleccionado: %s (%d)\n", libros[pos].titulo, libros[pos].anio);

    printf("Nuevo autor: ");
    leerCadena(libros[pos].autor, 50);

    printf("Nuevo anio de publicacion: ");
    libros[pos].anio = intPositivo();

    int opcEstadoFisico = 0;
    do {
        printf("Nuevo estado fisico (1. Buen estado, 2. Estado medio, 3. Danado): ");
        opcEstadoFisico = intPositivo();
        if (opcEstadoFisico < 1 || opcEstadoFisico > 3)
            printf("Opcion invalida. Intente nuevamente.\n");
    } while (opcEstadoFisico < 1 || opcEstadoFisico > 3);

    switch (opcEstadoFisico) {
        case 1: strcpy(libros[pos].estadoFisico, "Buen estado"); break;
        case 2: strcpy(libros[pos].estadoFisico, "Estado medio"); break;
        case 3: strcpy(libros[pos].estadoFisico, "Danado"); break;
    }

    printf("Libro actualizado correctamente.\n");
}

/* ==================== USUARIOS ==================== */

void registrarUsuario(Usuario usuarios[], int *contU) {
    if (*contU >= 10) {
        printf("No se pueden registrar mas usuarios.\n");
        return;
    }

    printf("\n--- Registrar Usuario ---\n");

    printf("Ingrese ID de usuario: ");
    usuarios[*contU].id = intPositivo();

    printf("Ingrese nombre: ");
    leerCadena(usuarios[*contU].nombre, 50);

    usuarios[*contU].idLibroRentado = -1;

    (*contU)++;
    printf("Usuario registrado con exito.\n");
}

void listarUsuarios(Usuario usuarios[], int contU) {
    if (contU == 0) {
        printf("No hay usuarios registrados.\n");
        return;
    }

    printf("\nID\tNombre\t\tLibro Rentado\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < contU; i++) {
        if (usuarios[i].idLibroRentado == -1)
            printf("%d\t%s\t\tNinguno\n", usuarios[i].id, usuarios[i].nombre);
        else
            printf("%d\t%s\t\tID Libro: %d\n",
                   usuarios[i].id, usuarios[i].nombre,
                   usuarios[i].idLibroRentado);
    }
}

int buscarUsuario(Usuario usuarios[], int contU, Libro libros[], int contL) {
    if (contU == 0) {
        printf("No hay usuarios registrados.\n");
        return -1;
    }

    int id;
    printf("Ingrese ID del usuario: ");
    id = intPositivo();

    for (int i = 0; i < contU; i++) {
        if (usuarios[i].id == id) {
            printf("\nUsuario encontrado:\n");
            printf("ID: %d\nNombre: %s\n", usuarios[i].id, usuarios[i].nombre);

            if (usuarios[i].idLibroRentado == -1)
                printf("No tiene libro rentado.\n");
            else {
                printf("Libro rentado ID: %d\n", usuarios[i].idLibroRentado);
            }

            return i;
        }
    }

    printf("Usuario no encontrado.\n");
    return -1;
}

/* ==================== PRÉSTAMOS ==================== */

void rentarLibro(Libro libros[], int contL, Usuario usuarios[], int contU, int cont) {
    int idU, idL;

    if (contU == 0) {
        printf("No hay usuarios registrados.\n");
        return;
    }

    if (cont == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n--- Rentar Libro ---\n");
    printf("ID de usuario: ");
    idU = intPositivo();

    int posU = -1;
    for (int i = 0; i < contU; i++)
        if (usuarios[i].id == idU) posU = i;

    if (posU == -1) {
        printf("Usuario no encontrado.\n");
        return;
    }

    if (usuarios[posU].idLibroRentado != -1) {
        printf("El usuario ya tiene un libro rentado.\n");
        return;
    }

    printf("ID del libro: ");
    idL = intPositivo();

    int posL = -1;
    for (int i = 0; i < contL; i++)
        if (libros[i].id == idL) posL = i;

    if (posL == -1) {
        printf("Libro no encontrado.\n");
        return;
    }

    if (strcmp(libros[posL].estado, "Disponible") != 0) {
        printf("El libro no esta disponible.\n");
        return;
    }

    usuarios[posU].idLibroRentado = idL;
    strcpy(libros[posL].estado, "Prestado");

    printf("Libro rentado correctamente.\n");
}

void devolverLibro(Libro libros[], int contL, Usuario usuarios[], int contU, int cont) {
    int idU;

if (contU == 0) {
        printf("No hay usuarios registrados.\n");
        return;
    }

    if (contL == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n--- Devolver Libro ---\n");
    printf("ID de usuario: ");
    idU = intPositivo();

    int posU = -1;
    for (int i = 0; i < contU; i++)
        if (usuarios[i].id == idU) posU = i;

    if (posU == -1) {
        printf("Usuario no encontrado.\n");
        return;
    }

    if (usuarios[posU].idLibroRentado == -1) {
        printf("El usuario no tiene libro para devolver.\n");
        return;
    }

    int idL = usuarios[posU].idLibroRentado;

    int posL = -1;
    for (int i = 0; i < contL; i++)
        if (libros[i].id == idL) posL = i;

    if (posL != -1)
        strcpy(libros[posL].estado, "Disponible");

    usuarios[posU].idLibroRentado = -1;

    printf("Libro devuelto correctamente.\n");
}
