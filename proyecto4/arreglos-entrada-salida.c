#include <stdio.h>
#define N 5

void pedir_arreglo(int n_max, int a[]) {
	int i = 0;
	while (i<n_max) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
}

void imprimir_arreglo(int n_max, int a[]) {
	int i = 0;
    printf("\nEl arreglo es: ");
    while (i<n_max) {
    printf("a[%d] = %d  ", i, a[i]);
    i=i+1;
	}
	printf("\n");
}

int main(void) {
	int a[N];

	pedir_arreglo(N, a);
	
	imprimir_arreglo(N, a);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 arreglos-entrada-salida.c -o proyecto4_6
./proyecto4_6
Ingrese el indice a[0]: 9
Ingrese el indice a[1]: 4
Ingrese el indice a[2]: 2
Ingrese el indice a[3]: 7
Ingrese el indice a[4]: 3

El arreglo es: a[0] = 9  a[1] = 4  a[2] = 2  a[3] = 7  a[4] = 3
*/