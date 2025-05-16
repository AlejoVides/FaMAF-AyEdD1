#include <stdio.h>

int pedir_entero(char name) {
	int x;

	printf("Ingrese un valor para la variable %c: ", name);
	scanf("%d", &x);
	return x;
}

void imprimir_entero(char name, int x) {
	printf("%c = %d\n", name, x);
}

int main(void) {
	int y = pedir_entero('n');
	imprimir_entero('n', y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 entradas.c -o proyecto36
./proyecto36
Ingrese un valor para la variable n: 4
n = 4


./proyecto36
Ingrese un valor para la variable n: 2
n = 2
*/