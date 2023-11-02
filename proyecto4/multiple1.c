#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void asig_mult(int x, int y) {
	int xaux, yaux;
	xaux = x;
	yaux = y;

	printf("{Pre: x = X, y = Y}\n");
	printf("  x = %d, y = %d\n", x, y);

	x = xaux + 1;
	y = xaux + yaux;

	printf("{Post: x = X + 1, y = X + Y}\n");
	printf("  x = %d, y = %d\n", x, y);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');

	asig_mult(x, y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 multiple1.c -o proyecto4_2c
./proyecto4_2c
Ingrese un valor para x: 3
Ingrese un valor para y: 4
{Pre: x = X, y = Y}
  x = 3, y = 4
{Post: x = X + 1, y = X + Y}
  x = 4, y = 7
*/