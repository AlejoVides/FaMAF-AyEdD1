#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

int suma_hasta(int n) {
	int sum = 0;

	assert (n>=0);
	while(n>=0) {
		sum = sum + n;
		n=n-1;
	}
	return sum;
}

int main(void) {
	int n = pedir_entero('n');

	int sum = suma_hasta(n);
	printf("La suma de los primeros %d naturales es: %d\n", n, sum);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 suma_hasta.c -o proyecto4_3
/proyecto4_3
Ingrese un valor para n: 7
La suma de los primeros 7 naturales es: 28


./proyecto4_3
Ingrese un valor para n: 65
La suma de los primeros 65 naturales es: 2145


./proyecto4_3
Ingrese un valor para n: 0
La suma de los primeros 0 naturales es: 0


./proyecto4_3
Ingrese un valor para n: -1
proyecto43: suma_hasta.c:15: suma_hasta: Assertion `n>=0' failed.
*/