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
	int b[N] = {2, 10, 10, -1};
	int i = 0;
	while (i < N) { 
		if (a[i] != b[i]) {
			return false;
		}
		i++;
	}
	return true;
}

void ej10a(int i, int s, int a[], bool res) {
	assert(i == -3 && s == 5 && res);
	i = 0;
	s = 0;
	while (i < 4) {
		s = s + a[i];
		i++;
	}
	printf("s = %d\n", s);
}

int main(void) {
	int a[N];
	int i = pedirEntero();
	int s = pedirEntero();
	pedirArreglo(N, a);
	bool res = compararArreglo(a);
	ej10a(i, s, a, res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej17-10a.c -o ej17
./ej17
Ingrese un valor entero: -3
Ingrese un valor entero: 5
Ingrese el indice 0: 2
Ingrese el indice 1: 10
Ingrese el indice 2: 10
Ingrese el indice 3: -1
s = 21

./ej17
Ingrese un valor entero: 1
Ingrese un valor entero: 2
Ingrese el indice 0: 3
Ingrese el indice 1: 4
Ingrese el indice 2: 5
Ingrese el indice 3: 6
ej17: ej17-10a.c:35: ej10a: Assertion `(i == -3) && (s == 5) && res' failed.
*/