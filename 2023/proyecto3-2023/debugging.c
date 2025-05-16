#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int x, y, z;
    int tempB, tempW;
    bool b, w;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("Ingrese un valor para z: ");
    scanf("%d", &z);
    
    printf("Ingrese un valor booleano para b: ");
    scanf("%d", &tempB);
    b = tempB;

    printf("Ingrese un valor booleano para w: ");
    scanf("%d", &tempW);
    w = tempW;

    printf("x mod 4 == 0 = ");                          // True
    printf("%d\n", (x % 4) == 0);

    printf("x + y == 0 && y - x == (-1) * z = ");       // True
    printf("%d\n", x + y == 0 && y - x == (-1) * z);

    printf("not b && w = ");                            // False
    printf("%d\n", ! b && w);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 debugging.c -o proyecto32
./proyecto32
Ingrese un valor para x: 4
Ingrese un valor para y: -4
Ingrese un valor para z: 8
Ingrese un valor booleano para b: 1
Ingrese un valor booleano para w: 1
x mod 4 == 0 = 1
x + y == 0 && y - x == (-1) * z = 1
not b && w = 0
*/