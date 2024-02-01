/*
- Derivación -
	Var n : Int;
	{ P: True }
	if n >= 0 -> skip
	[] n < 0 -> n := -n	
	fi
	{ Q: n >= 0 }
*/

#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

int absoluto(int n) {
	if (n<0) {
		return(-n);
	}
	return(n);
}

int main(void) {
	int n = pedir_entero('n');
	assert(n>=0 || n<=0);

	int abs = absoluto(n);
	assert(abs>=0);

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
