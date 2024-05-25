#include <stdio.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int sumatoria(int tam, int a[]) {
	int i = 0;
	int sum = 0;
	while (i < tam) {
		sum = sum + a[i];
		i++;
	}
	return sum;
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	int sum = sumatoria(N, a);
	printf("la suma de todos los elementos del arreglo es = %d\n", sum);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej10-sumatoria.c -o ej10
./ej10
Ingrese el indice 0: 8
Ingrese el indice 1: 3
Ingrese el indice 2: 14
Ingrese el indice 3: 2
Ingrese el indice 4: 6
la suma de todos los elementos del arreglo es = 33
*/