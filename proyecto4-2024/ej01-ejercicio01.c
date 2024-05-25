#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
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