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

    printf("x + y + 1 = ");
    printf("%d\n", x + y + 1);

    printf("z * z + y * 45 - 15 * x = ");
    printf("%d\n", z * z + y * 45 - 15 * x);

    printf("y - 2 == (x * 3 + 1) %% 5 = ");
    printf("%d\n", y - 2 == (x * 3 + 1) % 5);

    printf("y / 2 * x = ");
    printf("%d\n", y / 2 * x);

    printf("y < x *z = ");
    printf("%d\n", y < x *z);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej1-entrada-salida.c -o ej1
./ej1
Ingrese un valor para x: 7
Ingrese un valor para y: 3
Ingrese un valor para z: 5
x + y + 1 = 11
z * z + y * 45 - 15 * x = 55
y - 2 == (x * 3 + 1) % 5 = 0
y / 2 * x = 7
y < x *z = 1

./ej1
Ingrese un valor para x: 1
Ingrese un valor para y: 10
Ingrese un valor para z: 8
x + y + 1 = 12
z * z + y * 45 - 15 * x = 499
y - 2 == (x * 3 + 1) % 5 = 0
y / 2 * x = 5
y < x *z = 0

¿En la ultima expresion, que tipo tiene el resultado en lenguaje “C”?
    Es de tipo booleano, 1 es True y 0 es False.
*/
