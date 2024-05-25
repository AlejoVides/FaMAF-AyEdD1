/*
    Const N : Int;
    Var a : array[0, N) of Int; r : Int;
    { P : N >= 0 }
    S
    { Q : r = {Max p, q : 0 <= p <= q <= N : sum.p.q} ; [ sum.p.q = {Σ i : p <= i < q : a.i } ] }
*/

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int sum(int begg, int end, int a[]) {
    int i = begg;
    int res = 0;
    while (i < end) {
        res = res + a[i];
        i++;
    }
    return res;
}

int segSumMax(int tam, int a[]) {
    int i = 0;
    int j = 0;
    int res = INT_MIN;
    while (i < tam) {
        j = i;
        while (j < tam) {
            int resAux = sum(i, j, a);
            if (resAux > res) {
                res = resAux;
            }
            j++;
            }
        i++;
    }
    return res;
}

int main(void) {
    int a[N];
    pedirArreglo(N, a);
    assert(N >= 0);
    int res = segSumMax(N, a);
    printf("El segmento de suma maxima es %d", res);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej29-11.c -o ej29
./ej29
Ingrese el indice 0: -3  
Ingrese el indice 1: -4
Ingrese el indice 2: 5
Ingrese el indice 3: 6
11

./ej29
Ingrese el indice 0: -3
Ingrese el indice 1: 5
Ingrese el indice 2: -4
Ingrese el indice 3: 6
Ingrese el indice 4: -9
7
*/