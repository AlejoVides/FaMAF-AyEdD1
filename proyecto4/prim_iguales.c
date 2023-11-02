#include <stdio.h>
#define N 5

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
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

int prim_iguales(int tam, int a[]) {
	int i = 1;

	while(i<tam) {
		if(a[0]!=a[i]) {
			imprimir_arreglo(i, a);
			return i;
		}
		i=i+1;
	}
	imprimir_arreglo(i, a);
	return i;
}


int main(void) {
	int a[N];

	pedir_arreglo(N, a);

	int prim = prim_iguales(N, a);
	printf("El tramo inicial más largo del array es %d\n", prim);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 prim_iguales.c -o proyecto4_11
./proyecto4_11
Ingrese el indice a[0]: 8
Ingrese el indice a[1]: 8
Ingrese el indice a[2]: 8
Ingrese el indice a[3]: 8
Ingrese el indice a[4]: 8

El arreglo es: a[0] = 8  a[1] = 8  a[2] = 8  a[3] = 8  a[4] = 8  
El tramo inicial más largo del array es 5


./proyecto4_11
Ingrese el indice a[0]: 2
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 1
Ingrese el indice a[3]: 3
Ingrese el indice a[4]: 4

El arreglo es: a[0] = 2  a[1] = 2  
El tramo inicial más largo del array es 2


./proyecto4_11
Ingrese el indice a[0]: 5
Ingrese el indice a[1]: 5
Ingrese el indice a[2]: 5
Ingrese el indice a[3]: 3
Ingrese el indice a[4]: 2

El arreglo es: a[0] = 5  a[1] = 5  a[2] = 5  
El tramo inicial más largo del array es 3
*/