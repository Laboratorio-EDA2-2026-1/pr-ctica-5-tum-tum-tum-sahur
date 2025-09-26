// Escribe aquí la implementación de los ejercicios de Counting Sort.
//Ejercicio 1
//Dada una cadena s compuesta por letras minúsculas del alfabeto inglés, 
//ordena todas sus letras en orden lexicográfico utilizando Counting Sort.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RANGE 256

void coutingSort(char s[]);

int main(int argc, const char * argv[]) {
    char s[] = "geeksforgeeks";
    printf("Cadena original: %s\n",s);
    coutingSort(s);
    printf("Cadena ordenda: %s\n",s);
    return 0;
}

void coutingSort(char *s){
    int n = strlen(s);
    char *output = (char *)malloc((n+1) * sizeof(char));
    if(output == NULL){
        printf("Error al asignar memoria.");
        return;
    }
    int *count = (int *)calloc(RANGE, sizeof(int));
    if(count == NULL){
        printf("Error al asignar memoria.");
        return;
    }
    //Contar frecuencia de cada caracter usando codigo ASCII
    for (int i = 0; i < n; i++) {
        count[(unsigned char)s[i]]++;
    }
    //onteo acumulao
    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i-1];
    }
    //Construccion del arreglo ordenado
    for (int i = n-1; i >= 0; i--) {
        output[count[(unsigned char)s[i]]-1] = s[i];
        count[(unsigned char)s[i]]--;
    }
    //Devolviendo el resultado ordenado
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
    free(output);
    free(count);
}

//Ejercicio 2
//Supongamos que un arreglo A consta de n elementos,
//cada uno de los cuales es rojo, blanco o azul. 
//Queremos ordenar los elementos de manera que todos los rojos queden antes que los blancos, 
//y todos los blancos antes que los azules.

#include <stdio.h>

#define ROJO   0
#define BLANCO 1
#define AZUL   2

//intercambiar dos elemntos
void Swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//algotirmo de ordenacion
void ordenar_colores(int arr[], int n){
	int low = 0, mid = 0, high = n-1;

	while (mid <= high) {
		//examinar elemento actual
		if (arr[mid] == ROJO) {//si es rojo lo lleva al principio
			Swap(arr, low, mid);
		low++;
		mid++;
		} else if (arr[mid] == BLANCO) { //si es blanco ya esta en su lugar
			mid++;
		} else {
			//si es azul lo volvemos al final
			Swap(arr, mid, high);
			high--;
		}
	}
}

//imprimir el arreglo
void imprimir_arreglo(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {2, 0, 2, 1, 1, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Arreglo original: ");
	imprimir_arreglo(arr, n);

	//lamar al algoritmo de ordenaciones
	ordenar_colores(arr, n);

	printf("Arreglo ordenado: ");
	imprimir_arreglo(arr, n);

	return 0;
}

// tengo un arreglo con tres colores rojo (0), blanco (1) y azul (2) y quiero ordenar todo para que primero estén los rojos, luego los blancos y al final los azules. Para hacer eso, uso tres índices: low, mid y high. low marca hasta dónde tengo los rojos bien puestos al principio, mid es el que estoy revisando ahora mismo, y high marca desde dónde hacia el final tengo los azules. Entonces, mientras mid no pase a high, voy viendo qué color hay en mid: Si es rojo, lo intercambio con el elemento en low, y muevo ambos índices adelante porque ese rojo ya quedó en su lugar. Si es blanco, no hago nada, solo avanzo mid porque los blancos van en medio y ahí está bien. Si es azul, lo intercambio con el elemento en high, bajo high porque ese azul ya está al final, pero no avanzo mid todavía, porque el elemento que traje del final no lo conozco y tengo que revisarlo. Repito todo esto hasta que mid pase a high. Al final, todo está ordenado: rojos al principio, blancos en medio y azules al final. Así que básicamente hago una sola pasada por el arreglo, moviendo los colores a su lugar con intercambios, sin usar espacio extra ni nada complicado.



