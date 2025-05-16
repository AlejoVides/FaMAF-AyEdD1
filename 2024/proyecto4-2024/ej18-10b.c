#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 4

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

bool compararArreglo(int a[]) {
	int b[N] = {12, -9, 10, -1};
	int i = 0;
	while (i < N) { 
		if (a[i] != b[i]) {
			return false;
		}
		i++;
	}
	return true;
}

void ej10b(int i, int c, int a[], bool res) {
	assert(i == 3 && c == 12 && res);
	i = 0;
	c = 0;
	while (i < 4) {
		if (a[i] > 0) {
			c++;
		}
		i++;
	}
	printf("c = %d\n", c);
}

int main(void) {
	int a[N];
	int i = pedirEntero();
	int c = pedirEntero();
	pedirArreglo(N, a);
	bool res = compararArreglo(a);
	ej10b(i, c, a, res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej18-10b.c -o ej18
./ej18
Ingrese un valor entero: 3
Ingrese un valor entero: 12
Ingrese el indice 0: 12
Ingrese el indice 1: -9
Ingrese el indice 2: 10
Ingrese el indice 3: -1
c = 2

./ej18
Ingrese un valor entero: 1
Ingrese un valor entero: 1
Ingrese el indice 0: 2
Ingrese el indice 1: 3
Ingrese el indice 2: 4
Ingrese el indice 3: 5
ej18: ej18-10b.c:34: ej10b: Assertion `(i == 3) && (c == 12) && res' failed.
*/