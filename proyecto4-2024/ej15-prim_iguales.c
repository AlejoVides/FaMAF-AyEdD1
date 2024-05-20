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
    while (i < n_max) {
		printf("a[%d] = %d  ", i, a[i]);
    	i++;
    }
	printf("\n");
}

int primIguales(int tam, int a[]) {
	int i = 1;
	while(i < tam) {
		if(a[0] != a[i]) {
			imprimirArreglo(i, a);
			return i;
		}
		i++;
	}
	imprimirArreglo(i, a);
	return i;
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	int prim = primIguales(N, a);
	printf("El tramo inicial más largo del array es %d\n", prim);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej15-prim_iguales.c -o ej15
./ej15
Ingrese el indice 0: 1
Ingrese el indice 1: 1
Ingrese el indice 2: 1
Ingrese el indice 3: 3
Ingrese el indice 4: 4
a[0] = 1  a[1] = 1  a[2] = 1  
El tramo inicial más largo del array es 3

./ej15
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 1
Ingrese el indice 3: 1
Ingrese el indice 4: 1
a[0] = 1  
El tramo inicial más largo del array es 1
*/