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

