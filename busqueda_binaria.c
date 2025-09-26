// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
//Ejercicio 1
#include <stdio.h>


int busquedaBinaria(int arr[], int inicio, int fin, int x) {
    if (inicio > fin) {
        return -1; 
    }

    int medio = inicio + (fin - inicio) / 2;

    if (arr[medio] == x)
        return medio;

    if (x < arr[medio])
        return busquedaBinaria(arr, inicio, medio - 1, x); 
    else
        return busquedaBinaria(arr, medio + 1, fin, x);
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;

    int resultado = busquedaBinaria(arr, 0, n - 1, x);

    if (resultado == -1)
        printf("El elemento %d no se encuentra en el arreglo.\n", x);
    else
        printf("El elemento %d se encuentra en la posición %d.\n", x, resultado);

    return 0;
}

//Ejercicio 2
#include <stdio.h>

// Función recursiva que simula la búsqueda binaria
void busqueda_binaria(double x, double izquierda, double derecha, int pasos_restantes) {
    if (pasos_restantes == 0) return;  // Caso base: sin pasos restantes

    double medio = (izquierda + derecha) / 2.0;

    if (x > medio) {
        printf("1");
        busqueda_binaria(x, medio, derecha, pasos_restantes - 1); // mitad derecha
    } 
    else if (x < medio) {
        printf("0");
        busqueda_binaria(x, izquierda, medio, pasos_restantes - 1); // mitad izquierda
    } 
    else {
        // x == medio, imprime 1 y completa con ceros
        printf("1");
        for (int i = 1; i < pasos_restantes; i++) printf("0");
    }
}

int main() {
    double x;
    int k;

    printf("Ingresa un número real x (0 <= x < 1): ");
    scanf("%lf", &x);
    printf("Ingresa el número de pasos k: ");
    scanf("%d", &k);

    if (x < 0 || x >= 1) {
        printf("Error: x debe estar en el rango [0, 1)\n");
        return 1;
    }

    printf("Secuencia binaria: ");
    busqueda_binaria(x, 0.0, 1.0, k);
    printf("\n");

    return 0;
}
