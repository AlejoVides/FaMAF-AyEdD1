#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

int minimo(int x, int y) {
	if (x<=y) {
		return x;
	} else {
		return y;
	}
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');

	int min = minimo(x, y);
	printf("El menor es: %d\n", min);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 minimo.c -o proyecto4_1b
./proyecto4_1b
Ingrese un valor para x: 2
Ingrese un valor para y: 3
El menor es: 2


./proyecto4_1b
Ingrese un valor para x: 4
Ingrese un valor para y: 3
El menor es: 3
*/