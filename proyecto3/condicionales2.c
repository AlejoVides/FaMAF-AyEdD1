#include <stdio.h>

void cuatroB(void) {
    printf("EJ cuatroB\n");
    int x, y, z, m;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("Ingrese un valor para z: ");
    scanf("%d", &z);

    printf("Ingrese un valor para m: ");
    scanf("%d", &m);

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
}

int main(void) {
    cuatroB();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 condicionales2.c -o proyecto342
./proyecto342
EJ cuatroB
Ingrese un valor para x: 5
Ingrese un valor para y: 4
Ingrese un valor para z: 8
Ingrese un valor para m: 0
σ0 (x→5, y→4, z→8, m→0)
x >= y | σ1 (x→5, y→4, z→8, m→4)
m < z  | σ2 (x→5, y→4, z→8, m→4)


Volve a ejecutar nuevamente con otros estados iniciales. ¿Que hace este programa?¿Cual es el valor final de la variable m?.
    El programa transforma a m en el valor mas chico entre los otros tres valores.
    
./proyecto342
EJ cuatroB
Ingrese un valor para x: 0
Ingrese un valor para y: 8
Ingrese un valor para z: 4
Ingrese un valor para m: 5
σ0 (x→0, y→8, z→4, m→5)
x < y  | σ1 (x→0, y→8, z→4, m→0)
m < z  | σ2 (x→0, y→8, z→4, m→0)
*/