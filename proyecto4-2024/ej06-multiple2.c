#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

void asignacionMultiple(int x, int y, int z) {
	int X = x;
	int Y = y;
	int Z = z;
	// {Pre: x = X, y = Y, z = Z}
	assert(x == X && y == Y && z == Z);
	x = Y;
	y = Y + X + Z;
	z = Y * X;
	// {Post: x = Y, y = Y + X + Z, z = Y + X}
	assert(x == Y && y == Y + X + Z && z == Y + X);
	printf("x = %d, y = %d, z = %d\n", x, y, z);
}

int main(void) {
	int x = pedirEntero();
	int y = pedirEntero();
	int z = pedirEntero();
	asignacionMultiple(x, y, z);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej06-multiple2.c -o ej6
./ej6
Ingrese un valor entero: 0
Ingrese un valor entero: 0
Ingrese un valor entero: 1
x = 0, y = 1, z = 0
*/