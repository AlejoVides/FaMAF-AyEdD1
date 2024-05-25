/*
    Const N : Int;
    Var a : array[0, N) of Int; r : Int;
    { P: N ≥ 2 }
    S
    { Q : r = {Max p, q : 0 <= p < q < N : a.p − a.q} }
*/

#include <stdio.h>
#include <limits.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int diffMinMax(int tam, int a[]) {
	int maxAux = INT_MIN;
    int minAux = INT_MAX;
	int i = 0;
	while (i < tam) {
		if (a[i] < minAux) {
			minAux = a[i];
		}
        if (a[i] > maxAux) {
            maxAux = a[i];
        }
		i++;
	}
	return (maxAux - minAux);
}

int main(void) {
    int a[N];
    pedirArreglo(N, a);
    int res = diffMinMax(N, a);
    printf("la diferencia entre el valor mas grande y mas chico del arreglo es %d", res);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej28-10.c -o ej28
./ej28
Ingrese el indice 0: 4
Ingrese el indice 1: 37
Ingrese el indice 2: 1
Ingrese el indice 3: 3
Ingrese el indice 4: 12
la diferencia entre el valor mas grande y mas chico del arreglo es 36
*/
