/*
- Derivación -
	Var x, y, tempX, tempY : Int;
	{ P: True }
	tempX := x;
	tempY := y;
	x := tempX;
	y := tempY
	{ Q: x, y = tempY, tempX }
*/

#include <stdio.h>
#include <assert.h>

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

void intercambio(int x, int y){
	int tempX = x, tempY = y;
	x = tempY;
	y = tempX;
	
	assert(x == tempY && y == tempX);
	printf("(x = %d | y = %d)\n", x, y);
}

int main(void) {
	int x = pedir_entero('x');
	int y = pedir_entero('y');
	assert((x>=0 || x<=0) && (y>=0 || y<=0));

	intercambio(x, y);
	return 0;
}

/*
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
