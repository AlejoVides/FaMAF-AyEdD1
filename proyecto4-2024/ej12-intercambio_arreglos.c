#include <stdio.h>
#include <assert.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int pedirEntero(int tam) {
	int x;
	printf("Ingrese un indice del 0 al %d para intercambiar: ", (tam - 1));
	scanf("%d", &x);
	return x;
}

void imprimirArreglo(int nMax, int a[]) {
	int i = 0;
    while (i < nMax) {
		printf("a[%d] = %d  ", i, a[i]);
    	i++;
    }
	printf("\n");
}

void intercambiar(int tam, int a[], int i, int j) {
	int aux = a[i];
	assert(i < tam && j < tam && i != j);
	a[i] = a[j];
	a[j] = aux;
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	int i = pedirEntero(N);
	int j = pedirEntero(N);
	intercambiar(N, a, i, j);
	imprimirArreglo(N, a);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej12-intercambio_arreglos.c -o ej12
./ej12
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 3
Ingrese el indice 3: 4
Ingrese el indice 4: 5
Ingrese un indice del 0 al 4 para intercambiar: 1
Ingrese un indice del 0 al 4 para intercambiar: 2
a[0] = 1  a[1] = 3  a[2] = 2  a[3] = 4  a[4] = 5  
*/