// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

//EJERCICIO 1
#include <stdio.h>

int busquedaLineal(int A[], int n, int k) {
	for (int i = 0; i < n; i ++) {
		if (A[i] == k) {
			return 1;
		} //retorna el indice donde se encuentra k
	}
	return -1; //si no se encuentra
}

int main() {
	int A[] = {5, 3, 8, 6, 7};
	int n = sizeof(A) / sizeof(A[0]);
	int k = 6;

	int result = busquedaLineal(A, n, k);

	if (result != -1){
		printf("Elemento %d encontrado en el indice: %d\n", k, result);
	} else{
		printf("El elemnto %d no encontrado en el arrreglo.\n", k);
	} 

	return 0;
}

//EJERCICIO 2
#include <stdio.h>
int busquedalinealMejorada(int *arr, int n, int k){
    int i = 0;
    int encontrado = 0;
    while (i < n && !encontrado) {
        if(arr[i] == k){
            encontrado = 1;
        }else{
            i++;
        }
    }
    if(encontrado){
        return i;
    }else{
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {2, 9, 5, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    int pos = busquedalinealMejorada(arr, n, k);
    if(pos != -1){
        printf("Elemento %d encontrado en la posicion %d\n",k, pos);
    }else{
        printf("Elemento %d no encontrado", k);
    }
    return 0;
}

