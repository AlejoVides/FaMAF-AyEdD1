#include <stdio.h>

int pedirEntero(void) {
    int x;
    printf("Ingrese un valor entero: ");
    scanf("%d", &x);
    return x;
}

int main(void) {
    int x = pedirEntero();
    int y = pedirEntero();
    int z = pedirEntero();
    int m = pedirEntero();

    printf("σ0 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
    if (x < y) {
        printf("(x < y)\n");
        m = x;
    } else {
        printf("(x >= y)\n");
        m = y;
    }
    printf("σ1 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
    if (m < z) {
        printf("(m < z)\n");
    } else {
        printf("(m >= z)\n");
        m = z;
    }
    printf("σ2 (x→%d, y→%d, z→%d, m→%d)\n", x, y, z, m);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej5-condicionales2.c -o ej5
./ej5
Ingrese un valor entero: 5
Ingrese un valor entero: 4
Ingrese un valor entero: 8
Ingrese un valor entero: 0
σ0 (x→5, y→4, z→8, m→0)
(x >= y)
σ1 (x→5, y→4, z→8, m→4)
(m < z)
σ2 (x→5, y→4, z→8, m→4)

./ej5
Ingrese un valor entero: 2
Ingrese un valor entero: 7
Ingrese un valor entero: 5
Ingrese un valor entero: 0
σ0 (x→2, y→7, z→5, m→0)
(x < y)
σ1 (x→2, y→7, z→5, m→2)
(m < z)
σ2 (x→2, y→7, z→5, m→2)

Volve a ejecutar nuevamente con otros estados iniciales. ¿Que hace este programa?¿Cual es el valor final de la variable m?.
    El programa transforma a m en el valor mas chico entre los otros tres valores.
*/