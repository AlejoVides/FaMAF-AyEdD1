#include <stdio.h>

int pedirEntero(void) {
	int x;
	printf("Ingrese un valor entero: ");
	scanf("%d", &x);
	return x;
}

void imprimirEntero(int x) {
	printf("%d\n", x);
}

int main(void) {
	int y = pedirEntero();
	imprimirEntero(y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej8-entradas.c -o ej8
./ej8
Ingrese un valor entero: 4
4
*/