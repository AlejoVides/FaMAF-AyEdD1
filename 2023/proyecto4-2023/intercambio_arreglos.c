#include <stdio.h>
#include <assert.h>
#define N 5

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
}

int pedir_entero(int tam, char name) {
	int var;

	printf("Ingrese un valor (del 0 al %d) para %c: ", (tam-1), name);
	scanf("%d", &var);
	return var;
}

void intercambiar(int tam, int a[], int i, int j) {
	int iaux, jaux;
	iaux = a[i];
	jaux = a[j];

	assert(i<tam && j<tam && i!=j);

	a[i] = jaux;
	a[j] = iaux;
}

void imprimir_arreglo(int tam, int a[]) {
	int i = 0;
    printf("\nEl arreglo es: ");
    while (i<tam) {
    printf("a[%d] = %d  ", i, a[i]);
    i=i+1;
	}
	printf("\n");
}

int main(void) {
	int a[N];

	pedir_arreglo(N, a);

	int i = pedir_entero(N, 'i');
	int j = pedir_entero(N, 'j');
	
	intercambiar(N, a, i, j);
	imprimir_arreglo(N, a);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 intercambio_arreglos.c -o proyecto4_9
./proyecto4_9
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 3
Ingrese el indice a[3]: 4
Ingrese el indice a[4]: 5
Ingrese un valor (del 0 al 4) para i: 3
Ingrese un valor (del 0 al 4) para j: 4

El arreglo es: a[0] = 1  a[1] = 2  a[2] = 3  a[3] = 5  a[4] = 4
*/