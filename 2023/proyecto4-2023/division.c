#include <stdio.h>
#include <assert.h>

struct div_t {
	int cociente;
	int resto;
};

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

struct div_t division(int x, int y) {
	struct div_t res;

	assert(x>=0 && y>=0 && y!=0);
	res.cociente = x/y;
	res.resto = x%y;

	return res;
}

void imprimir_div_t(struct div_t res) {
	printf("Cociente (x/y) = %d, Resto (x mod y) = %d\n", res.cociente, res.resto);
}

int main(void) {
	struct div_t div;

	int x = pedir_entero('x');
	int y = pedir_entero('y');

	div = division(x, y);
	imprimir_div_t(div);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 division.c -o proyecto4_5
./proyecto4_5
Ingrese un valor para x: 7
Ingrese un valor para y: 2
Cociente (x/y) = 3, Resto (x mod y) = 1


./proyecto4_5
Ingrese un valor para x: 4
Ingrese un valor para y: 0
proyecto45: division.c:20: division: Assertion `x>=0 && y>=0 && y!=0' failed.
*/