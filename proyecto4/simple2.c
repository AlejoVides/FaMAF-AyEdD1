#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void asig_simp(int x, int y, int z) {
	printf("{Pre: x = x, y = y, z = z}\n");
	printf("  x = %d, y = %d, z = %d\n", x, y, z);

	x = y;
	y = y + x + z;
	z = y * x;
	
	printf("{Post: x = y, y = (y + x + z), z = (y + x)}\n");
	printf("  x = %d, y = %d, z = %d\n", x, y, z);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');
	int z = pedir_entero('z');

	asig_simp(x, y, z);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 simple2.c -o proyecto4_2b
./proyecto4_2b
Ingrese un valor para x: 2
Ingrese un valor para y: 4
Ingrese un valor para z: 6
{Pre: x = x, y = y, z = z}
  x = 2, y = 4, z = 6
{Post: x = y, y = (y + x + z), z = (y + x)}
  x = 4, y = 14, z = 56
*/