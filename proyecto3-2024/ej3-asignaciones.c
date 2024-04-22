#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

void unoA(void) {
    int x = pedirEntero();
    assert(x == 1);

    printf("σ0 (x→%d)\n", x);
    x = 5;
    printf("σ1 (x→%d)\n", x);
}

void unoB(void) {
    int x = pedirEntero();
    int y = pedirEntero();
    assert(x == 2 && y == 5);

    printf("σ0 (x→%d, y→%d)\n", x, y);
    x = x + y;
    printf("σ1 (x→%d, y→%d)\n", x, y);
    y = y + y;
    printf("σ2 (x→%d, y→%d)\n", x, y);
}

void unoC(void) {
    int x = pedirEntero();
    int y = pedirEntero();
    assert(x == 2 && y == 5);

    printf("σ0 (x→%d, y→%d)\n", x, y);
    y = y + y;
    printf("σ1 (x→%d, y→%d)\n", x, y);
    x = x + y;
    printf("σ2 (x→%d, y→%d)\n", x, y);
}

int main(void) {
	unoA();
    unoB();
    unoC();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej3-asignaciones.c -o ej3
./ej3
Ingrese un valor entero: 1
σ0 (x→1)
σ1 (x→5)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
σ0 (x→2, y→5)
σ1 (x→7, y→5)
σ2 (x→7, y→10)
Ingrese un valor entero: 2
Ingrese un valor entero: 5
σ0 (x→2, y→5)
σ1 (x→2, y→10)
σ2 (x→12, y→10)

./ej3
Ingrese un valor entero: 3
σ0 (x→3)
σ1 (x→5)
Ingrese un valor entero: 7
Ingrese un valor entero: 6
σ0 (x→7, y→6)
σ1 (x→13, y→6)
σ2 (x→13, y→12)
Ingrese un valor entero: 6
Ingrese un valor entero: 7
σ0 (x→6, y→7)
σ1 (x→6, y→14)
σ2 (x→20, y→14)

./ej3
Ingrese un valor entero: 8
σ0 (x→8)
σ1 (x→5)
Ingrese un valor entero: 4
Ingrese un valor entero: 3
σ0 (x→4, y→3)
σ1 (x→7, y→3)
σ2 (x→7, y→6)
Ingrese un valor entero: 6
Ingrese un valor entero: 2
σ0 (x→6, y→2)
σ1 (x→6, y→4)
σ2 (x→10, y→4)
*/