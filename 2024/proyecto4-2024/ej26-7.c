#include <stdio.h>
#include <stdbool.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

bool sumaDeLosAnteriores(int tam, int a[]) {
	int i, res = 0;
	while (i < tam) {
		if (a[i] == res) {
			return true;
		}
		res = res + a[i];
		i++;
	}
	return false;
}

int main(void){
	int a[N];
	pedirArreglo(N, a);
	bool res = sumaDeLosAnteriores(N, a);
	if (res == 0) {
		printf("falso\n");
	} else {
		printf("verdadero\n");
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej26-7.c -o ej26
./ej26
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 4
Ingrese el indice 3: 5
Ingrese el indice 4: 6
falso

./ej26
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 4
Ingrese el indice 3: 5
Ingrese el indice 4: 12
verdadero
*/