#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

void asignacionMultiple(int x, int y) {
	int X = x;
	int Y = y;
	// {Pre: x = X, y = Y}
	assert(x == X && y == Y);
	x = X + 1;
	y = X + Y;
	// {Post: x = X + 1, y = X + Y}
	assert(x == X + 1 && y == X + Y);
	printf("x = %d, y = %d\n", x, y);
}

int main(void) {
	int x = pedirEntero();
	int y = pedirEntero();
	asignacionMultiple(x, y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej05-multiple1.c -o ej5
./ej5
Ingrese un valor entero: 3 
Ingrese un valor entero: 6
x = 4, y = 9

./ej5
Ingrese un valor entero: 7
Ingrese un valor entero: 2
x = 8, y = 9
*/