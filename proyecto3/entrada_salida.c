#include <stdio.h>

int main(void) {
    int x, y, z;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("Ingrese un valor para z: ");
    scanf("%d", &z);

    printf("x + y + 1 = ");
    printf("%d\n", x + y + 1);

    printf("z * z + y * 45 - 15 * x = ");
    printf("%d\n", z * z + y * 45 - 15 * x);

    printf("y - 2 == (x * 3 + 1) div 5 = ");
    printf("%d\n", y - 2 == (x * 3 + 1) % 5);

    printf("y / 2 * x = ");
    printf("%d\n", y / 2 * x);

    printf("y < x * z = ");
    printf("%d\n", y < x * z);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 entrada_salida.c -o proyecto31
./proyecto31
Ingrese un valor para x: 7
Ingrese un valor para y: 3
Ingrese un valor para z: 5
x + y + 1 = 11
z * z + y * 45 - 15 * x = 55
y - 2 == (x * 3 + 1) div 5 = 0
y / 2 * x = 7
y < x * z = 1


./proyecto31
Ingrese un valor para x: 1
Ingrese un valor para y: 10
Ingrese un valor para z: 8
x + y + 1 = 12
z * z + y * 45 - 15 * x = 499
y - 2 == (x * 3 + 1) div 5 = 0
y / 2 * x = 5
y < x * z = 0

¿En la ultima expresion, que tipo tiene el resultado en lenguaje “C”?
    Dado que es un resultado booleano, devuelve 1 para Verdadero y 0 para Falso.
*/