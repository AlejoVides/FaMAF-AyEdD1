#include <stdio.h>

void unoH(void) {
    int i;
    int itr = 0;
    printf("Ingrese un valor para i: ");
    scanf("%d", &i);

    printf("σ0 (i→%d)\n", i);	
    while (i != 0) {
    	itr++;
    	printf("σ1 %d (i→%d) | ", itr, i);
    	i--;
    	printf("σ2 %d (i→%d)\n", itr, i);
    }
    printf("σ3 (i→%d)\n", i);
}

void unoI(void) {
    int i;
    int itr = 0;
    printf("Ingrese un valor para i: ");
    scanf("%d", &i);

    printf("σ0 (i→%d)\n", i);
    while (i != 0) {
        itr++;
        printf("σ1 %d (i→%d) | ", itr, i);
        i = 0;
        printf("σ2 %d (i→%d)\n", itr, i);
    }
    printf("σ3 (i→%d)\n", i);
}

int main(void) {
	unoH();
	unoI();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej6-ciclos1.c -o ej6
./ej6
Ingrese un valor para i: 4
σ0 (i→4)
σ1 1 (i→4) | σ2 1 (i→3)
σ1 2 (i→3) | σ2 2 (i→2)
σ1 3 (i→2) | σ2 3 (i→1)
σ1 4 (i→1) | σ2 4 (i→0)
σ3 (i→0)
Ingrese un valor para i: 400
σ0 (i→400)
σ1 1 (i→400) | σ2 1 (i→0)
σ3 (i→0)
*/