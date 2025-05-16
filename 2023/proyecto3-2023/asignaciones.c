#include <stdio.h>

void unoA(void) {
    printf("EJ unoA\n");
    int x;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("σ0 (x→%d)\n", x);
    x = 5;
    printf("σ1 (x→%d)\n", x);
}

void unoB(void) {
    printf("\nEJ unoB\n");
    int x, y;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("σ0 (x→%d, y→%d)\n", x, y);
    x = x + y;
    printf("x = x + y = %d | σ1 (x→%d, y→%d)\n", x, x, y);
    y = y + y;
    printf("y = y + y = %d | σ2 (x→%d, y→%d)\n", y, x, y);
}

void unoC(void) {
    printf("\nEJ unoC\n");
    int x, y;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("σ0 (x→%d, y→%d)\n", x, y);
    y = y + y;
    printf("y = y + y = %d | σ1 (x→%d, y→%d)\n", y, x, y);
    x = x + y;
    printf("x = x + y = %d | σ2 (x→%d, y→%d)\n", x, x, y);
}

int main(void) {
    unoA();
    unoB();
    unoC();
  return 0;
}

/*
gcc -Wall -Wextra -std=c99 asignaciones.c -o proyecto33
./proyecto33
EJ unoA
Ingrese un valor para x: 1
σ0 (x→1)
σ1 (x→5)

EJ unoB
Ingrese un valor para x: 2
Ingrese un valor para y: 5
σ0 (x→2, y→5)
x = x + y = 7 | σ1 (x→7, y→5)
y = y + y = 10 | σ2 (x→7, y→10)

EJ unoC
Ingrese un valor para x: 2
Ingrese un valor para y: 5
σ0 (x→2, y→5)
y = y + y = 10 | σ1 (x→2, y→10)
x = x + y = 12 | σ2 (x→12, y→10)


./proyecto33
EJ unoA
Ingrese un valor para x: 3
σ0 (x→3)
σ1 (x→5)

EJ unoB
Ingrese un valor para x: 7
Ingrese un valor para y: 8
σ0 (x→7, y→8)
x = x + y = 15 | σ1 (x→15, y→8)
y = y + y = 16 | σ2 (x→15, y→16)

EJ unoC
Ingrese un valor para x: 8
Ingrese un valor para y: 7
σ0 (x→8, y→7)
y = y + y = 14 | σ1 (x→8, y→14)
x = x + y = 22 | σ2 (x→22, y→14)


./proyecto33
EJ unoA
Ingrese un valor para x: 12
σ0 (x→12)
σ1 (x→5)

EJ unoB
Ingrese un valor para x: 21
Ingrese un valor para y: 32
σ0 (x→21, y→32)
x = x + y = 53 | σ1 (x→53, y→32)
y = y + y = 64 | σ2 (x→53, y→64)

EJ unoC
Ingrese un valor para x: 53
Ingrese un valor para y: 14
σ0 (x→53, y→14)
y = y + y = 28 | σ1 (x→53, y→28)
x = x + y = 81 | σ2 (x→81, y→28)
*/