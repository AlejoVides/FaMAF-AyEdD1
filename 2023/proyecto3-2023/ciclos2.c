#include <stdio.h>
#include <stdbool.h>

void cincoB1(void) {
    printf("EJ cincoB1\n");
    int x, y, i;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para y: ");
    scanf("%d", &y);

    printf("Ingrese un valor para i: ");
    scanf("%d", &i);

    printf("σ0 (x→%d, y→%d, i→%d)\n", x, y, i);
    	i = 0;
    while (x >= y) {
        x = x - y;
        i++;
        printf("σ1 %d (x→%d, y→%d, i→%d)\n", i, x, y, i);
    }
}

void cincoB2(void) {
    printf("\nEJ cincoB2\n");
    int x, i, tempRES;
    bool res;
    int itr = 0;

    printf("Ingrese un valor para x: ");
    scanf("%d", &x);

    printf("Ingrese un valor para i: ");
    scanf("%d", &i);

    printf("Ingrese un valor booleano para res: ");
    scanf("%d", &tempRES);
    res = tempRES;

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
	cincoB1();
	cincoB2();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ciclos2.c -o proyecto352
./proyecto352
EJ cincoB1
Ingrese un valor para x: 13
Ingrese un valor para y: 3
Ingrese un valor para i: 0
σ0 (x→13, y→3, i→0)
σ1 1 (x→10, y→3, i→1)
σ1 2 (x→7, y→3, i→2)
σ1 3 (x→4, y→3, i→3)
σ1 4 (x→1, y→3, i→4)

EJ cincoB2
Ingrese un valor para x: 5
Ingrese un valor para i: 0
Ingrese un valor booleano para res: 0
σ0 (x→5, i→0, res→0)
σ1 1 (x→5, i→3, res→1)
σ1 2 (x→5, i→4, res→1)
σ1 3 (x→5, i→5, res→1)


Ejecuta los programas con otros estados iniciales para deducir que hace cada uno.
    5B1) Transforma a x el resto entre x e y.
    5B2) Si en la ultima iteracion el resto es true, x es primo.

./proyecto352
EJ cincoB1
Ingrese un valor para x: 12
Ingrese un valor para y: 3
Ingrese un valor para i: 0
σ0 (x→12, y→3, i→0)
σ1 1 (x→9, y→3, i→1)
σ1 2 (x→6, y→3, i→2)
σ1 3 (x→3, y→3, i→3)
σ1 4 (x→0, y→3, i→4)

EJ cincoB2
Ingrese un valor para x: 8
Ingrese un valor para i: 1
Ingrese un valor booleano para res: 1
σ0 (x→8, i→1, res→1)
σ1 1 (x→8, i→3, res→0)
*/