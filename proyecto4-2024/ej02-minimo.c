#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int x;
	printf("Ingrese un valor entero: ");
	scanf("%d", &x);
	return x;
}

int minimo(int x, int y) {
	if (x >= y) {
		return y;
	} else {
		return x;
	}
}

int main(void) {
	int x = pedirEntero();
	int y = pedirEntero();
	int min = minimo(x, y);
	assert(min < x || min < y);
	printf("%d\n", min);
	return 0;
}

/*
	Const x, y : Int;
	{ P: True }
	if x <= y -> x
	[] x > y -> y
	fi
	{ Q: x min y }

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