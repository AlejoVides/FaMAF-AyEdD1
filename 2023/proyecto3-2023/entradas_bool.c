#include <stdio.h>
#include <stdbool.h>

bool pedir_booleano(char name) {
	int tempX;
	bool x;

	printf("Ingrese un valor booleano para la variable %c: ", name);
	scanf("%d", &tempX);
	x = tempX;
	return x;
}

void imprimir_booleano(char name, bool x) {
	if (x==0) {
		printf("%c = falso\n", name);
	} else {
		printf("%c = verdadero\n", name);
	}
}

int main(void) {
	bool y = pedir_booleano('n');
	imprimir_booleano('n', y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 entradas_bool.c -o proyecto362
./proyecto362
Ingrese un valor booleano para la variable n: 0
n = falso


./proyecto362
Ingrese un valor booleano para la variable n: 4
n = verdadero
*/