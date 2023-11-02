#include <stdio.h>

int pedir_valores(char name) {
	int valores;

	printf("Ingrese un valor para la variable %c: ", name);
	scanf("%d", &valores);
	return valores;
}

int menor(int x, int y, int z, int m) {
    printf("σ0 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
    if (x < y) {
        printf("x < y  | ");
        m = x;
    } else {
        printf("x >= y | ");
        m = y;
    }
    printf("σ1 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
    if (m < z) {
        printf("m < z  | ");
    } else {
        printf("m >= z | ");
        m = z;
    }
    printf("σ2 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
    return m;
}

void imprimir_valores(char name, int valores) {
    printf("%c = %d\n", name, valores);
}

int main(void) {
	int x = pedir_valores('x');
	int y = pedir_valores('y');
	int z = pedir_valores('z');
	int m = pedir_valores('m');
    int output = menor(x, y, z, m);
    imprimir_valores('m', output);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 entradas_condicionales2.c -o proyecto363
./proyecto363
Ingrese un valor para la variable x: 1
Ingrese un valor para la variable y: 2
Ingrese un valor para la variable z: 3
Ingrese un valor para la variable m: 4
σ0 (x→1, y→2, z→3, m→4)
x < y  | σ1 (x→1, y→2, z→3, m→1)
m < z  | σ2 (x→1, y→2, z→3, m→1)
m = 1
*/