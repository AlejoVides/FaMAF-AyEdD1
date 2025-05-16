#include <stdio.h>
#include <stdbool.h>

int pedirEntero(void) {
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

int pedirBooleano(void) {
    int tempX;
    printf("Ingrese un valor entero: ");
    scanf("%d", &tempX);
    bool x = tempX;
    return x;
}

void ciclo1(void) {
    int x = pedirEntero();
    int y = pedirEntero();
    int i = pedirEntero();

    printf("σ0 (x→%d, y→%d, i→%d)\n", x, y, i);
    i = 0;
    while (x >= y) {
        x = x - y;
        i++;
        printf("σ1 %d (x→%d, y→%d, i→%d)\n", i, x, y, i);
    }
}

void ciclo2(void) {
    int x = pedirEntero();
    int i = pedirEntero();
    bool res = pedirBooleano();
    int itr = 0;

    printf("σ0 (x→%d, i→%d, res→%d)\n", x, i, res);
    i = 2;
    res = 1;
    while ((i < x) && res) {
    	res = res && ((x % i) != 0);
    	i++;
    	itr++;
    	printf("σ1 %d (x→%d, i→%d, res→%d)\n", itr, x, i, res);
    }
}

int main(void) {
	ciclo1();
	ciclo2();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej7-ciclos2.c -o ej7
./ej7
Ingrese un valor entero: 7
Ingrese un valor entero: 2
Ingrese un valor entero: 0
σ0 (x→7, y→2, i→0)
σ1 1 (x→5, y→2, i→1)
σ1 2 (x→3, y→2, i→2)
σ1 3 (x→1, y→2, i→3)
Ingrese un valor entero: 11
Ingrese un valor entero: 2
Ingrese un valor entero: 1
σ0 (x→11, i→2, res→1)
σ1 1 (x→11, i→3, res→1)
σ1 2 (x→11, i→4, res→1)
σ1 3 (x→11, i→5, res→1)
σ1 4 (x→11, i→6, res→1)
σ1 5 (x→11, i→7, res→1)
σ1 6 (x→11, i→8, res→1)
σ1 7 (x→11, i→9, res→1)
σ1 8 (x→11, i→10, res→1)
σ1 9 (x→11, i→11, res→1)

Ejecuta los programas con otros estados iniciales para deducir que hace cada uno.
    ciclo1) Transforma a x en el modulo entre x e y.
    ciclo2) Si en la ultima iteracion el resto es 1, x es primo.
*/