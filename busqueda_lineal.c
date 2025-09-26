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
