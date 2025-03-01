#include <stdio.h>

#define N 4 // Tamaño del tablero (puedes modificarlo)

// Función para verificar si el tablero cumple las reglas
int es_valido(int tablero[N][N], int fila, int col, int num, int pistas[N][N]) {
    // Verificar si el número está en la fila
    for (int i = 0; i < N; i++) {
        if (tablero[fila][i] == num) return 0;
    }

    // Verificar si el número está en la columna
    for (int i = 0; i < N; i++) {
        if (tablero[i][col] == num) return 0;
    }

    // Verificar las pistas
    // 1. Pistas de la fila y columna superior
    int visibilidad_fila = 0, visibilidad_columna = 0;
    int max_fila = 0, max_col = 0;

    // Verificar visibilidad en la fila
    for (int i = 0; i <= fila; i++) {
        if (tablero[i][col] > max_fila) {
            visibilidad_fila++;
            max_fila = tablero[i][col];
        }
    }

    // Verificar visibilidad en la columna
    for (int j = 0; j <= col; j++) {
        if (tablero[fila][j] > max_col) {
            visibilidad_columna++;
            max_col = tablero[fila][j];
        }
    }

    // Poner las condiciones de visibilidad basadas en las pistas

    return 1;
}

// Función para resolver el rompecabezas
int resolver(int tablero[N][N], int fila, int col, int pistas[N][N]) {
    if (fila == N) return 1; // Si hemos recorrido todas las filas
    if (col == N) return resolver(tablero, fila + 1, 0, pistas); // Ir a la siguiente fila

    for (int num = 1; num <= N; num++) {
        // Si el número es válido en esta posición
        if (es_valido(tablero, fila, col, num, pistas)) {
            tablero[fila][col] = num;
            if (resolver(tablero, fila, col + 1, pistas)) return 1; // Intentar la siguiente celda
            tablero[fila][col] = 0; // Deshacer el cambio si no es válido
        }
    }

    return 0; // Si no se encontró ninguna solución
}

// Función para imprimir el tablero
void imprimir_tablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tablero[N][N] = {0}; // Crear un tablero vacío
    // Pistas de ejemplo (se pueden cambiar según tu caso)
    int pistas[N][N] = {
        {4, 3, 2, 1}, // Pistas en el borde superior
        {4, 3, 2, 1}, // Pistas en el borde izquierdo
        {1, 2, 2, 2}, // Pistas en el borde derecho
        {1, 2, 2, 2}  // Pistas en el borde inferior
    };

    if (resolver(tablero, 0, 0, pistas)) {
        imprimir_tablero(tablero);
    } else {
        printf("No hay solución posible.\n");
    }

    return 0;
}
