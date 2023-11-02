#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void asig_simp(int x, int y) {
	printf("{Pre: x = x, y = y}\n");
	printf("  x = %d, y = %d\n", x, y);

	x = x + 1;
	y = x + y;

	printf("{Post: x = (x + 1), y = (x + y)}\n");
	printf("  x = %d, y = %d\n", x, y);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');

	asig_simp(x, y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 simple1.c -o proyecto4_2
./proyecto4_2
Ingrese un valor para x: 3
Ingrese un valor para y: 4
{Pre: x = x, y = y}
  x = 3, y = 4
{Post: x = (x + 1), y = (x + y)}
  x = 4, y = 8
*/