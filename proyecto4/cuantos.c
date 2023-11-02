#include <stdio.h>
#define N 5

struct comp_t {
	int menores;
	int iguales;
	int mayores;
};

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
}

int pedir_entero(char name) {
	int var;

	printf("Ingrese un valor para %c: ", name);
	scanf("%d", &var);
	return var;
}

struct comp_t cuantos(int tam, int a[], int elem) {
	struct comp_t c;
	int i = 0;

	c.menores = 0;
	c.iguales = 0;
	c.mayores = 0;

	while (i<tam) {
		if(a[i]<elem) {
			c.menores = c.menores+1;
		}

		if(a[i]==elem) {
			c.iguales = c.iguales+1;
		}

		if(a[i]>elem) {
			c.mayores = c.mayores+1;
		}
		i=i+1; 
	}
	return c;
}

void imprimir_cuantos(int e, struct comp_t c){
  	printf("\nElementos menores a %d = %d\nElementos iguales a %d = %d\nElementos mayores a %d = %d\n",e, c.menores, e, c.iguales, e, c.mayores); 
}

int main(void) {
	int a[N];

	int elem = pedir_entero('e');
	pedir_arreglo(N, a);

	imprimir_cuantos(elem, cuantos(N, a, elem));
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 cuantos.c -o proyecto4_12
./proyecto4_12
Ingrese un valor para e: 4
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 3
Ingrese el indice a[3]: 4
Ingrese el indice a[4]: 5

Elementos menores a 4 = 3
Elementos iguales a 4 = 1
Elementos mayores a 4 = 1


./proyecto4_12
Ingrese un valor para e: 3
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 1
Ingrese el indice a[2]: 1
Ingrese el indice a[3]: 4
Ingrese el indice a[4]: 4

Elementos menores a 3 = 3
Elementos iguales a 3 = 0
Elementos mayores a 3 = 2
*/