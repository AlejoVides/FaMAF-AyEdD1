#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void hola_hasta(int n) {
	assert (n>0);
	while(n>0) {
		printf("Hola\n");
		n--;
	}
}

int main(void) {
	int n = pedir_entero('n');

	hola_hasta(n);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ejercicio01.c -o proyecto4_1
./proyecto4_1
Ingrese un valor para n: 4
Hola
Hola
Hola
Hola


./proyecto4_1
Ingrese un valor para n: 0
proyecto41: ejercicio01.c:13: hola_hasta: Assertion `n>0' failed.
*/