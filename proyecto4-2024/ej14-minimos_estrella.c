#include <stdio.h>
#include <stdbool.h>
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

bool todosPares(int tam, int a[]) {
	int i = 0;
	while(i < tam) {
		if (a[i] % 2 != 0) {
			return false;
		}
		i++;
	}
	return true;
}

bool existeMultiplo(int m, int tam, int a[]) {
	int i = 0;
	while(i < tam) {
		if (a[i] % m == 0) {
			return true;
		}
		i++;
	}
	return false;
}

int main(void) {
	int a[N];
	pedirArreglo(N, a);
	int minPar = minimoPares(N, a);
	int minImpar = minimoImpares(N, a);
	bool noExisteImpar = todosPares(N, a);
	bool existePar = existeMultiplo(2, N, a);

	if(existePar) {
		printf("minimoPares(N, a) = %d\n", minPar);
	} else {
		printf("El array no contiene numeros pares\n");
	}
	if(noExisteImpar) {
		printf("El array no contiene numeros impares\n");
	} else {
		printf("minimoImpares(N, a) = %d\n", minImpar);
	}
	if(minPar < minImpar) {
		printf("El minimo numero del array es = %d\n", minPar);
	} else {
		printf("El minimo numero del array es = %d\n", minImpar);
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej14-minimos_estrella.c -o ej14
./ej14
Ingrese el indice 0: 1
Ingrese el indice 1: 3
Ingrese el indice 2: 5
Ingrese el indice 3: 7
Ingrese el indice 4: 9
El array no contiene numeros pares
minimoImpares(N, a) = 1
El minimo numero del array es = 1

./ej14
Ingrese el indice 0: 0
Ingrese el indice 1: 2
Ingrese el indice 2: 4
Ingrese el indice 3: 6
Ingrese el indice 4: 8
minimoPares(N, a) = 0
El array no contiene numeros impares
El minimo numero del array es = 0
*/