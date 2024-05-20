#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int minimo(int x, int y) {
	int min;
	if (x >= y) {
		min = y;
	} else {
		min = x;
	}
	return min;
}

int main(void) {
	int x = pedirEntero();
	int y = pedirEntero();
	int min = minimo(x, y);
	assert(min == minimo(x, y));
	printf("%d\n", min);
	return 0;
}

/*
	Const x, y : Int;
	{ P: True }
	if x >= y -> min := y
	[] x < y -> min := x
	fi
	{ Q: min = 	Min.x.y }

gcc -Wall -Wextra -std=c99 ej02-minimo.c -o ej2
./ej2
Ingrese un valor entero: 2
Ingrese un valor entero: 3
2

./ej2
Ingrese un valor entero: 7
Ingrese un valor entero: 5
5
*/