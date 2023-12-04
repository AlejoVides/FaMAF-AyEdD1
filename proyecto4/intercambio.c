#include <stdio.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void intercambio(int x, int y){
	int temp = x;
	x = y;
	y = temp;
	printf("(x = %d | y = %d)\n", x, y);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');

	intercambio(x, y);
	return 0;
}

/*
- Derivación -
	Var x, y, temp : Int;
	{ P: True }
	temp := x
	x := y
	y := temp
	{ Q: x, y = y, x }

gcc -Wall -Wextra -std=c99 intercambio.c -o proyecto4_1d
./proyecto4_1d
Ingrese un valor para x: 4
Ingrese un valor para y: 5
(x = 5 | y = 4)


./proyecto4_1d
Ingrese un valor para x: 7
Ingrese un valor para y: 2
(x = 2 | y = 7)
*/
