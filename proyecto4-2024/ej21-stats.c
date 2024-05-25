#include <stdio.h>
#include <float.h>
#define N 5

struct datosT {
	float maximo;
	float minimo;
	float promedio;
};

void pedirArreglo(int nMax, float a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%f", &a[i]);
		i++;
	}
}

struct datosT stats(int tam, float a[]) {
	struct datosT res;
	float maxaux = FLT_MIN;
	float minaux = FLT_MAX;
	float prom = 0;
	int i = 0;
	while (i < tam) {
		if (a[i] > maxaux) {
			maxaux = a[i];
		} else if (a[i] < minaux) {
			minaux = a[i];
		}
		prom = prom + a[i];
		i++;
	}
	res.maximo = maxaux;
	res.minimo = minaux;
	res.promedio = (prom / tam);
	return res;
}

int main(void){
	struct datosT res;
	float a[N];
	pedirArreglo(N, a);
	res = stats(N, a);
	printf("resMax = %f | resMin = %f | resProm = %f\n", res.maximo, res.minimo, res.promedio);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej21-stats.c -o ej21
./ej21
Ingrese el indice 0: 12.543
Ingrese el indice 1: 33.721 
Ingrese el indice 2: 3.887
Ingrese el indice 3: 9.521
Ingrese el indice 4: 6.994
resMax = 33.721001 | resMin = 3.887000 | resProm = 13.333200
*/