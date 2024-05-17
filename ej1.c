#include <stdio.h>

// Función para buscar un elemento en un arreglo usando búsqueda lineal
int busquedaLineal(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Si el elemento es encontrado, retorna su posición
        }
    }
    return -1; // Si el elemento no es encontrado, retorna -1
}

// Función para buscar un elemento en un arreglo usando búsqueda binaria
int busquedaBinaria(int arr[], int n, int x) {
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == x) {
            return medio; // Si el elemento es encontrado, retorna su posición
        }
        if (arr[medio] < x) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1; // Si el elemento no es encontrado, retorna -1
}

// Función para buscar un elemento en un arreglo usando búsqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int inicio, int fin, int x) {
    if (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == x) {
            return medio; // Si el elemento es encontrado, retorna su posición
        }
        if (arr[medio] < x) {
            return busquedaBinariaRecursiva(arr, medio + 1, fin, x);
        } else {
            return busquedaBinariaRecursiva(arr, inicio, medio - 1, x);
        }
    }
    return -1; // Si el elemento no es encontrado, retorna -1
}

int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    int valor;
    printf("Ingrese un valor entero: ");
    if (scanf("%d", &valor) == 1) {
        // Búsqueda Lineal
        int posicion = busquedaLineal(arreglo, longitud, valor);
        if (posicion != -1) {
            printf("El valor %d se encuentra en la posición %d (usando búsqueda lineal).\n", valor, posicion + 1);
        } else {
            printf("El valor %d no fue encontrado (usando búsqueda lineal).\n", valor);
        }

        // Búsqueda Binaria
        posicion = busquedaBinaria(arreglo, longitud, valor);
        if (posicion != -1) {
            printf("El valor %d se encuentra en la posición %d (usando búsqueda binaria).\n", valor, posicion + 1);
        } else {
            printf("El valor %d no fue encontrado (usando búsqueda binaria).\n", valor);
        }

        // Búsqueda Binaria Recursiva
        posicion = busquedaBinariaRecursiva(arreglo, 0, longitud - 1, valor);
        if (posicion != -1) {
            printf("El valor %d se encuentra en la posición %d (usando búsqueda binaria recursiva).\n", valor, posicion + 1);
        } else {
            printf("El valor %d no fue encontrado (usando búsqueda binaria recursiva).\n", valor);
        }

        return 0;
    } else {
        printf("Ingrese un numero valido.\n");
        return 1; // Código de error
    }
}
