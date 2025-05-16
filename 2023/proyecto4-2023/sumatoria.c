#include <stdio.h>
#define N 5

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice %d: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
}

int sumatoria(int tam, int a[]) {
	int i = 0;
	int sum = 0;

	while(i<tam) {
		sum = sum + a[i];
		i=i+1;
	}
	return sum;
}

int main(void) {
	int a[N];

	pedir_arreglo(N, a);

	int sum = sumatoria(N, a);
	printf("El resulado de la suma de todos los elementos del arreglo es = %d\n", sum);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 sumatoria.c -o proyecto4_7
./proyecto4_7
Ingrese el indice 0: 9
Ingrese el indice 1: 3
Ingrese el indice 2: 6
Ingrese el indice 3: 8
Ingrese el indice 4: 2
El resulado de la suma de todos los elementos del arreglo es = 28
*/