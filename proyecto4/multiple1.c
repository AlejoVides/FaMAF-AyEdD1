#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void imprimir_entero(char name, int var) {
	printf("%c = %d\n", name, var);
}

void asig_mult(int x, int y) {
  	int X = x;
  	int Y = y;

	// {Pre: x = X, y = Y}
	assert(x==X && y==Y);
    	x = X + 1;
    	y = X + Y;

    	// {Post: x = X + 1, y = X + Y}
    	assert(x==X+1 && y==X+Y);
   	imprimir_entero('x', x);
   	imprimir_entero('y', y);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');

	asig_mult(x, y);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 multiple1.c -o proyecto4_2c
./proyecto4_2c
Ingrese un valor para x: 3
Ingrese un valor para y: 4
x = 4
y = 7


./proyecto4_2c
Ingrese un valor para x: 5
Ingrese un valor para y: 8
x = 6
y = 13
*/
