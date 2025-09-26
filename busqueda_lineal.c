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


//EJERCICIO 3
#include <stdio.h>

int busquedaLR(int A[], int n, int x, int k) {
	//si k llego al tamaño del arreglo, no se enconro el elemento
	if(k == n)
		return -1;

	if (A[k] == x)
		return k;

	return busquedaLR(A, n, x, k + 1);
}

int main(){
	int A[] = {7, 3, 5, 8, 2}; //ejemplo
	int n = sizeof(A) / sizeof(A[0]);
	int x = 5;
	int result = busquedaLR(A, n, x, 0);

	if (result != -1)
		printf("El elemento %d encontrado en la poscicion %d.\n", x, result);
	else 
		printf("El elemento %d no encontrado en el arreglo.\n", x);

	return 0;
} 

//EJERCICIO 4
#include <stdio.h>

int busquedalinealCentinela(int arr[], int n, int centinela){
    int ultimo = arr[n-1];
    arr[n-1] = centinela;

    int i = 0;
    while (arr[i] != centinela) 
    {
        i++;
    }
    arr[n-1] = ultimo;

    if (i < n-1 || arr[n-1] == centinela)
    {
        return i;
    }else{
        return -1;
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,8,1,3,9,2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int clave = 7;

    int pos = busquedalinealCentinela(arr, n, clave);

    if (pos != -1)
    {
        printf("Elemento %d encontrado en la posicion %d\n", clave, pos);
    }else{
        printf("Elemento %d no encontrado\n", clave);
    }
    
    return 0;
}
