#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}


void ej16b(int y, int N) {
	int Y = y;
	assert(y == Y && N >= 0);
	int x = 1;
	int n = 0;
	while(n != N) {
		x = x * y;
		n++;
	}
	assert(x = Y^N);
	printf("x = %d\n", x);
	assert((x = y^n) && (0 <= n) && (n <= N) && (y = Y));
} 

int main(void) {
	int y = pedirEntero();
	int N = 3; //probemos con inv = 3
	ej16b(y, N);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej19-16b.c -o ej19
./ej19
Ingrese un valor entero: 4
x = 7

./ej19
Ingrese un valor entero: 5
x = 6
*/