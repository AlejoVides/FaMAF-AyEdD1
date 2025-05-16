#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

bool todosPares(int tam, int a[]) {
	int i = 0;
	while (i < tam) {
		if (a[i] % 2 != 0) {
			return false;
		}
		i++;
	}
	return true;
}

bool existeMultiplo(int m, int tam, int a[]) {
	int i = 0;
	while (i < tam) {
		if (a[i] % m == 0) {
			return true;
		}
		i++;
	}
	return false;
}

int main(void) {
	int a[N], m, cualFuncion, res;
	pedirArreglo(N, a);
	printf("Ingrese un valor:\n 0 = todosPares()\n 1 = existeMultiplo()\n");
	scanf("%d",&cualFuncion);
	assert(cualFuncion == 0 || cualFuncion == 1);
	if (cualFuncion == 0) {
		res = todosPares(N, a);
	} else {
		printf("Ingrese un valor para m: ");
		scanf("%d", &m);
		res = existeMultiplo(m, N, a);
	}
	if (res == 0) {
		printf("false\n");
	} else {
		printf("true\n");
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej11-multiplos.c -o ej11
./ej11
Ingrese el indice 0: 6
Ingrese el indice 1: 4
Ingrese el indice 2: 2
Ingrese el indice 3: 0
Ingrese el indice 4: 8
Ingrese un valor:
 0 = todosPares()
 1 = existeMultiplo()
0
true

./ej11
Ingrese el indice 0: 4
Ingrese el indice 1: 5
Ingrese el indice 2: 7
Ingrese el indice 3: 8
Ingrese el indice 4: 9
Ingrese un valor:
 0 = todosPares()
 1 = existeMultiplo()
1
Ingrese un valor para m: 3
true
*/