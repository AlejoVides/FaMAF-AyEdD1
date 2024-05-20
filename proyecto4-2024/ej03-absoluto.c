#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int absoluto(int n) {
	if(n < 0) {
		return (-n);
	}
	return n;
}

int main(void) {
	int n = pedirEntero();
	int abs = absoluto(n);
	assert(abs >= 0);
	printf("%d\n", abs);
	return 0;
}

/*
	Var n : Int;
	{ P: True }
	if n >= 0 -> skip
	[] n < 0 -> n := -n
	fi
	{ Q: n >= 0 }

gcc -Wall -Wextra -std=c99 ej03-absoluto.c -o ej3
./ej3
Ingrese un valor entero: 4
4

./ej3
Ingrese un valor entero: -4
4
*/