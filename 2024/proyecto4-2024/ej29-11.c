/*
    Const N : Int;
    Var a : array[0, N) of Int; r : Int;
    { P : N >= 0 }
    S
    { Q : r = {Max p, q : 0 <= p <= q <= N : sum.p.q} ; [ sum.p.q = {Σ i : p <= i < q : a.i } ] }
*/

#include <stdio.h>
#define N 5

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int kadane(int tam, int a[]) {
    int i = 1;
    int maximoActual = a[0];
    int maximoGlobal = a[0];

    while (i < tam) {
        if (a[i] > maximoActual + a[i]) {
            maximoActual = a[i];
        } else {
            maximoActual = maximoActual + a[i];
        }

        if (maximoActual > maximoGlobal) {
            maximoGlobal = maximoActual;
        }
        i++;   
        }
    return maximoGlobal;
}

int main(void) {
    int a[N];
    pedirArreglo(N, a);
    int res = kadane(N, a);
    printf("El segmento de suma maxima es %d", res);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej29-11.c -o ej29
./ej29
Ingrese el indice 0: -99
Ingrese el indice 1: 1
Ingrese el indice 2: 2
Ingrese el indice 3: -1
Ingrese el indice 4: 5
El segmento de suma maxima es 7

./ej29
Ingrese el indice 0: -12
Ingrese el indice 1: 9
Ingrese el indice 2: 4
Ingrese el indice 3: -5
Ingrese el indice 4: 2
El segmento de suma maxima es 13
*/
