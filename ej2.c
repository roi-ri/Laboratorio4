#include <stdio.h> 

//Funcion para encontrar el minimo
int encontrarMinim(int arreglo[], int longitud) {
    if (longitud == 0) return 0; // Manejamos el caso de arreglo vacío
    int minimo = arreglo[0]; // Asignamos el primer elemento como mínimo inicialmente
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}


// Funcion para encontrar maximo 

int encontrarMax(int arreglo[], int longitud){
    int maximo = arreglo[0];
    for (int i = 1; i < longitud; i++){
        if(arreglo[i] > maximo){
            maximo = arreglo[i];
        }
    }
    return maximo;
}

//Funcion para encontrar el maximo y minimo con punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    *minimo = *maximo = arreglo[0]; // Asignamos el primer elemento como mínimo y máximo inicialmente
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) { // Corregido aquí
            *minimo = arreglo[i];
        } else if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}

int main(){
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo)/ sizeof(arreglo[0]);

    //llamar a las funciones y mostrar resultado

    printf("El valor minimo es: %d\n", encontrarMinim(arreglo, longitud));
    printf("El valor maximo es: %d\n", encontrarMax(arreglo, longitud));

    int minimo, maximo;
    encontrarMinMax(arreglo, &minimo, &maximo, longitud);
    printf("Usando punteros, el valor minimo es: %d\n", minimo);
    printf("Usando punteros, el valor maximo es: %d\n", maximo);

    return 0;

}