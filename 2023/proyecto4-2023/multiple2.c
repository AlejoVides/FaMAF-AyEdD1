#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void imprimir_entero(char name, int var) {
	printf("%c = %d\n", name, var);
}

void asig_mult(int x, int y, int z) {
	int X = x;
	int Y = y;
	int Z = z;

	// {Pre: x = X, y = Y, z = Z}
	assert(x==X && y==Y && z==Z);
	x = Y;
	y = Y + X + Z;
	z = Y * X;

	// {Post: x = Y, y = Y + X + Z, z = Y + X}
	assert(x==Y && y==Y+X+Z && z==Y+X);
	imprimir_entero('x', x);
	imprimir_entero('y', y);
	imprimir_entero('z', z);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');
	int z = pedir_entero('z');

	asig_mult(x, y, z);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 multiple2.c -o proyecto4_2d
./proyecto4_2d
Ingrese un valor para x: 0
Ingrese un valor para y: 0
Ingrese un valor para z: 1
x = 0
y = 1
z = 0
*/
