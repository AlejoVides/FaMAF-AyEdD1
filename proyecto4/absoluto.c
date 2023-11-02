#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

int absoluto(int n) {
	if (n>=0) {
		return(n);
	} else {
		return(-n);
	}
}

int main(void) {
	int n = pedir_entero('n');

	int abs = absoluto(n);
	printf("|%d| = %d\n", n, abs);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 absoluto.c -o proyecto4_1c
./proyecto4_1c
Ingrese un valor para n: 5
|5| = 5


./proyecto4_1c
Ingrese un valor para n: -5
|-5| = 5
*/