#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define N 5

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
}

int minimo_pares(int tam, int a[]) {
	int minaux = INT_MAX;
	int i = 0;

	while (i<tam) {
		if (a[i]%2==0 && a[i]<minaux) {
			minaux = a[i];
		}
		i=i+1;
	}
	return minaux;
}

int minimo_impares(int tam, int a[]) {
	int minaux = INT_MAX;
	int i = 0;

	while(i<tam){
		if(a[i]%2!=0 && a[i]<minaux) {
			minaux = a[i];
		}
		i=i+1;
	}
	return minaux;
}

bool todos_pares(int tam, int a[]) {
	int i = 0;

	while(i<tam) {
		if (a[i]%2!=0) {
			return false;
		}
		i=i+1;
	}
	return true;
}

bool existe_multiplo(int m, int tam, int a[]) {
	int i = 0;

	while(i<tam) {
		if (a[i]%m==0) {
			return true;
		}
		i=i+1;
	}
	return false;
}

int main(void) {
	int a[N];

	pedir_arreglo(N, a);

	int min_par = minimo_pares(N, a);
	int min_impar = minimo_impares(N, a);

	bool no_existe_impar = todos_pares(N, a);
	bool existe_par = existe_multiplo(2, N, a);

	if(!existe_par) {
		printf("El array no contiene numeros pares\n");
	} else {
		printf("El minimo par del array es = %d\n", min_par);
	}

	if (no_existe_impar) {
		printf("El array no contiene numeros impares\n");
	} else {
		printf("El minimo impar del array es = %d\n", min_impar);
	}

	if(min_par<min_impar) {
		printf("El minimo numero del array es = %d\n", min_par);	
	} else {
		printf("El minimo numero del array es = %d\n", min_impar);	
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 minimos_estrella.c -o proyecto4_10b
./proyecto4_10b
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 1
Ingrese el indice a[2]: 1
Ingrese el indice a[3]: 1
Ingrese el indice a[4]: 1
El array no contiene numeros pares
El minimo impar del array es = 1
El minimo numero del array es = 1


./proyecto4_10b
Ingrese el indice a[0]: 2
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 2
Ingrese el indice a[3]: 2
Ingrese el indice a[4]: 2
El minimo par del array es = 2
El array no contiene numeros impares
El minimo numero del array es = 2


./proyecto4_10b
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 3
Ingrese el indice a[3]: 4
Ingrese el indice a[4]: 5
El minimo par del array es = 2
El minimo impar del array es = 1
El minimo numero del array es = 1
*/