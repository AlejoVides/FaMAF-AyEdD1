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

void imprimirArreglo(int nMax, int a[]) {
	int i = 0;
    while (i < nMax) {
		printf("a[%d] = %d  ", i, a[i]);
    	i++;
    }
	printf("\n");
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	imprimirArreglo(N, a);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej09-arreglos-entada-salida.c -o ej9
./ej9
Ingrese el indice 0: 7
Ingrese el indice 1: 2
Ingrese el indice 2: 5
Ingrese el indice 3: 0
Ingrese el indice 4: 1
a[0] = 7  a[1] = 2  a[2] = 5  a[3] = 0  a[4] = 1  
*/