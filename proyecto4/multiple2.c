#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void simple(int x, int y, int z) {
	int xaux = x;
	int yaux = y;
	int zaux = z;

	printf("{Pre: x = X, y = Y, z = Z}\n");
	printf("  x = %d, y = %d, z = %d\n", x, y, z);

	x = yaux;
	y = yaux + xaux + zaux;
	z = yaux * xaux;

	printf("{Post: x = Y, y = Y + X + Z, z = Y + X}\n");
	printf("  x = %d, y = %d, z = %d\n", x, y, z);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');
	int z = pedir_entero('z');

	simple(x, y, z);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 multiple2.c -o proyecto4_2d
./proyecto4_2d
Ingrese un valor para x: 2
Ingrese un valor para y: 4
Ingrese un valor para z: 6
{Pre: x = X, y = Y, z = Z}
  x = 2, y = 4, z = 6
{Post: x = Y, y = Y + X + Z, z = Y + X}
  x = 4, y = 12, z = 8
*/
