#include <stdio.h>

int pedirEntero(void) {
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

void unoE(void) {
    int x = pedirEntero();
    int y = pedirEntero();

    printf("σ0 (x→%d, y→%d)\n", x, y);
    if (x >= y) {
        printf("(x >= y)\n");
        
        printf("σ1 (x→%d, y→%d)\n", x, y);
        x = 0;
        printf("σ2 (x→%d, y→%d)\n", x, y);
    } else if (x < y) {
        printf("(x < y)\n");

        printf("σ'1 (x→%d, y→%d)\n", x, y);
        x = 2;
        printf("σ'2 (x→%d, y→%d)\n", x, y);
    }
    printf("σ3 (x→%d, y→%d)\n", x, y);
}

void unoF(void) {
    int x = pedirEntero();
    int y = pedirEntero();

    printf("σ0 (x→%d, y→%d)\n", x, y);
    if (x >= y) {
        printf("(x >= y)\n");

        printf("σ1 (x→%d, y→%d)\n", x, y);
        x = 0;
        printf("σ2 (x→%d, y→%d)\n", x, y);
    } else if (x < y) {
        printf("(x < y)\n");

        printf("σ'1 (x→%d, y→%d)\n", x, y);
        x = 2;
        printf("σ'2 (x→%d, y→%d)\n", x, y);
    }
    printf("σ3 (x→%d, y→%d)\n", x, y);
}

int main(void) {
    unoE();
    unoF();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej4-condicionales1.c -o ej4
./ej4
Ingrese un valor entero: 3
Ingrese un valor entero: 1
σ0 (x→3, y→1)
(x >= y)
σ1 (x→3, y→1)
σ2 (x→0, y→1)
σ3 (x→0, y→1)
Ingrese un valor entero: -100
Ingrese un valor entero: 1
σ0 (x→-100, y→1)
(x < y)
σ'1 (x→-100, y→1)
σ'2 (x→2, y→1)
σ3 (x→2, y→1)
*/