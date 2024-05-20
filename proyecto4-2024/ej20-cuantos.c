#include <stdio.h>
#define N 5

struct compT {
	int menores;
	int iguales;
	int mayores;
};

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

void pedirArreglo(int nMax, int a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese el indice %d: ", i);
		scanf("%d", &a[i]);
		i++;
	}
}

struct compT cuantos(int tam, int a[], int elem) {
	struct compT res;
	int i = 0;
	res.menores = 0;
	res.iguales = 0;
	res.mayores = 0;
	while(i < tam) {
		if(a[i] < elem) {
			res.menores++;
		} else if(a[i] > elem) {
			res.mayores++;
		} else {
			res.iguales++;
		}
		i++;
	}
	return res;
}

int main(void) {
	struct compT res;
	int a[N];
	int elem = pedirEntero();
	pedirArreglo(N, a);
	res = cuantos(N, a, elem);
	printf("elem = %d | <elem = %d | =elem = %d | >elem = %d\n",elem, res.menores, res.iguales, res.mayores); 
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej20-cuantos.c -o ej20
./ej20
Ingrese un valor entero: 3
Ingrese el indice 0: 1
Ingrese el indice 1: 2
Ingrese el indice 2: 3
Ingrese el indice 3: 4
Ingrese el indice 4: 5
elem = 3 | <elem = 2 | =elem = 1 | >elem = 2
*/