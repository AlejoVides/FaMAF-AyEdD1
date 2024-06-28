#include <stdio.h>
#include <stdlib.h>
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

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

void maximaDistanciaAbsoluta(int nMax, int a[]) {
    assert(nMax > 2);
    int r = abs(a[0] - a[1]);
    int x = max(a[0], a[1]);
    int y = max(-a[0], -a[1]);
    int n = 0;
    while (n < nMax) {
        r = max(r, max(x - a[n], y + a[n]));
        x = max(x, a[n]);
        y = max(y, -a[n]);
        n++;
    }
    printf("La maxima distancia absoluta es: %d\n", r);
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	maximaDistanciaAbsoluta(N, a);
	return 0;
}