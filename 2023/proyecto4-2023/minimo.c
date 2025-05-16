/*
- Derivación -
	Const x, y : Int;
	Var res : Int;
	{ P: True }
	if x <= y -> res := x
	[] x > y -> res := y
	fi
	{ Q: res = x min y }
*/

#include <stdio.h>
#include <assert.h>	

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

int minimo(int x, int y) {
	int res;

	if (x<=y) {
		res = x;
	} else {
		res = y;
	}
	return res;
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');
	assert((x>=0 || x<=0) && (y>=0 || y<=0));

	int min = minimo(x, y);
	assert(min <= x || min <= y);

	printf("El menor es: %d\n", min);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 minimo.c -o proyecto4_1b
./proyecto4_1b
Ingrese un valor para x: 2
Ingrese un valor para y: 3
El menor es: 2


./proyecto4_1b
Ingrese un valor para x: 4
Ingrese un valor para y: 3
El menor es: 3
*/
