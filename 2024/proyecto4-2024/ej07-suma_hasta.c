#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int sumaHasta(int n) {
	int sum = 0;
	assert(n >= 0);
	while (n >= 0) {
		sum = sum + n;
		n--;
	}
	return sum;
}

int main(void) {
	int n = pedirEntero();
	int sum = sumaHasta(n);
	printf("La suma de los primeros %d naturales es: %d\n", n, sum);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej07-suma_hasta.c -o ej7
./ej7
Ingrese un valor entero: 14
La suma de los primeros 14 naturales es: 105

./ej7
Ingrese un valor entero: 62
La suma de los primeros 62 naturales es: 1953
*/