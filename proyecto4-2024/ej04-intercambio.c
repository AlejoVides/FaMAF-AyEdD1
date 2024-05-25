/*
	Var x, y, z : Int;
	{ P: True }
	x, y := y, x;
	{ Q: x, y := y, x }
*/

#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int main(void) {
	int x = pedirEntero();
	int y = pedirEntero();
	int X = x;
	int Y = y;
	x = Y;
	y = X;
	assert(x == Y && y == X);
	printf("x = %d, y = %d\n", x, y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej04-intercambio.c -o ej4
./ej4
Ingrese un valor entero: 1
Ingrese un valor entero: 2
x = 2, y = 1

./ej4
Ingrese un valor entero: 7
Ingrese un valor entero: 4
x = 4, y = 7
*/