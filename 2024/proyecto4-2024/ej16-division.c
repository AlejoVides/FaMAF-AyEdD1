#include <stdio.h>
#include <assert.h>

struct divT {
	int cociente;
	int resto;
};

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

struct divT division(int x, int y) {
	struct divT res;
	assert(x >= 0 && y > 0);
	res.cociente = x / y;
	res.resto = x % y;
	return res;
}

int main(void) {
	struct divT div;
	int x = pedirEntero();
	int y = pedirEntero();
	div = division(x, y);
	printf("cociente = %d | resto = %d\n", div.cociente, div.resto);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej16-division.c -o ej16
./ej16
Ingrese un valor entero: 3
Ingrese un valor entero: 2
cociente = 1 | resto = 1

./ej16
Ingrese un valor entero: 5
Ingrese un valor entero: 0
ej16: ej16-division.c:18: division: Assertion `x >= 0 && y > 0' failed.
*/