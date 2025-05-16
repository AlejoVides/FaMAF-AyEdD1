#include <stdio.h>
#include <float.h>
#define N 5

struct datos_t {
	float maximo;
	float minimo;
	float promedio;
};

void pedir_arreglo(int tam, float a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%f",&a[i]);
		i=i+1;
	}
}

struct datos_t stats(int tam, float a[]) {
	struct datos_t d;
	float maxaux = FLT_MIN;
	float minaux = FLT_MAX;
	float prom = 0;
	int i = 0;

	while(i<tam) {
		if (a[i]>maxaux) {
			maxaux = a[i];
		}

		if (a[i]<minaux) {
			minaux = a[i];
		}

		prom = prom + a[i];

		i=i+1;
	}

	d.maximo = maxaux;
	d.minimo = minaux;
	d.promedio = prom/tam;
	return d;
}

void imprimir_stats(struct datos_t d) {
	printf("\nMaximo = %f\nMinimo = %f\nPromedio = %f\n", d.maximo, d.minimo, d.promedio);
}

int main(void) {
	float a[N];

	pedir_arreglo(N, a);

	imprimir_stats(stats(N, a));
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 stats.c -o proyecto4_13
./proyecto4_13
Ingrese el indice a[0]: 1.355
Ingrese el indice a[1]: 5.234
Ingrese el indice a[2]: 6.912
Ingrese el indice a[3]: 4.825
Ingrese el indice a[4]: 9.632

Maximo = 9.632000
Minimo = 1.355000
Promedio = 5.591600
*/