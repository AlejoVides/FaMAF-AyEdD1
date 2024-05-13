#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int x;
	printf("Ingrese un valor entero: ");
	scanf("%d", &x);
	return x;
}

void holaHasta(int n) {
	assert(n > 0);
	while(n > 0) {
		printf("Hola\n");
		n--;
	}
}

int main(void) {
	int n = pedirEntero();
	holaHasta(n);
	return 0;
}


/*
gcc -Wall -Wextra -std=c99 ej01-ejercicio01.c -o ej1
./ej1
Ingrese un valor entero: 1
Hola

./ej1
Ingrese un valor entero: 4
Hola
Hola
Hola
Hola
*/
