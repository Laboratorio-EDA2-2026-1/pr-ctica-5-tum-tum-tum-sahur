// Escribe aquí la implementación del ejercicio de Radix Sort.

#include <stdio.h>

int getMax(int *arr, int n);
void coutingSort(int *arr, int n, int exp);
void radixSort(int *arr, int n);

int main(int argc, const char * argv[]) {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Arreglo original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    radixSort(arr, n);
    printf("\nArreglo ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
//Funcion para obtener el valor maximo
int getMax(int *arr, int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void coutingSort(int *arr,int n, int exp){
    int output[n];
    int count[10] = {0};
    //Contando frecuencia de cada digito
    for (int i = 0; i < n; i++) {
        count[arr[i]/exp %10]++;
    }
    //Conteo acumulado
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    //Constriuccion del arreglo ordenado
    for (int i = n-1; i >= 0; i--) {
        int digito = arr[i]/exp % 10;
        output[count[digito]-1] = arr[i];
        count[digito]--;
    }
    //Devolviendo el arreglo ordenado
    for (int i = 0; i < n ; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int *arr, int n){
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0 ; exp*=10) {
        coutingSort(arr, n, exp);
    }
}
