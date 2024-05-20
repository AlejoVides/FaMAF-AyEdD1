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

	z = x;
	x = y;
	y = z;
	assert(x == y && y == z);
	printf("x = %d, y = %d\n", x, y);
	return 0;
}

/*
	Var x, y, z : Int;
	{ P: True }
	z := x;
	x := y;
	y := z;
	{ Q: x, y := y, x }

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
