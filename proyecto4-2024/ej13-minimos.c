#include <stdio.h>
#include <limits.h>
#define N 5

void pedirArreglo(int n_max, int a[]) {
	int i = 0;
	while (i < n_max) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

int minimoPares(int tam, int a[]) {
	int minaux = INT_MAX;
	int i = 0;
	while (i < tam) {
		if (a[i] % 2 == 0 && a[i] < minaux) {
			minaux = a[i];
		}
		i++;
	}
	return minaux;
}

int minimoImpares(int tam, int a[]) {
	int minaux = INT_MAX;
	int i = 0;
	while(i < tam){
		if(a[i] % 2 != 0 && a[i] < minaux) {
			minaux = a[i];
		}
		i++;
	}
	return minaux;
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	int minPar = minimoPares(N, a);
	int minImpar = minimoImpares(N, a);
	printf("minimoPares(N, a) = %d\n", minPar);
	printf("minimoImpares(N, a) = %d\n", minImpar);

	if(minPar < minImpar) {
		printf("El minimo numero del array es = %d\n", minPar);
	} else {
		printf("El minimo numero del array es = %d\n", minImpar);
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej13-minimos.c -o ej13
./ej13
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 3
Ingrese el indice 3: 4
Ingrese el indice 4: 5
minimoPares(N, a) = 2
minimoImpares(N, a) = 1
El minimo numero del array es = 1
*/