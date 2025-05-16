#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

void pedir_arreglo(int tam, int a[]) {
	int i = 0;
	while (i<tam) {
		printf("Ingrese el indice a[%d]: ",i);
		scanf("%d",&a[i]);
		i=i+1;
	}
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

void imprimir_tp(bool tp) {
	if (tp==true) {
		printf("todos_pares(a[]) = true\n");
	} else {
		printf("todos_pares(a[]) = false\n");
	}
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

void imprimir_em(bool em, int m) {
	if (em==true) {
		printf("existe_multiplo(a[], %d) = true\n", m);
	} else {
		printf("existe_multiplo(a[], %d) = false\n", m);
	}
}

int main(void) {
	int func, a[N], m;

	printf("¿Qué función vas a usar?\n Ingrese 1 = todos_pares()\n Ingrese 2 = existe_multiplo()\n");
	scanf("%d",&func);

	assert(func==1 || func==2);
	if (func==1) {
		pedir_arreglo(N, a);

		bool tp = todos_pares(N, a);
		imprimir_tp(tp);

	} else {
		printf("Ingrese un valor para m: ");
		scanf("%d", &m);

		pedir_arreglo(N, a);

		bool em = existe_multiplo(m, N, a);
		imprimir_em(em, m);

	} 
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 multiplos.c -o proyecto4_8
./proyecto4_8
¿Qué función vas a usar?
 Ingrese 1 = todos_pares()
 Ingrese 2 = existe_multiplo()
3
proyecto4_8: multiplos.c:61: main: Assertion `func==1 || func==2' failed.


./proyecto4_8
1
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 3
Ingrese el indice a[3]: 4
Ingrese el indice a[4]: 5
todos_pares(a[]) = false


./proyecto4_8
¿Qué función vas a usar?
 Ingrese 1 = todos_pares()
 Ingrese 2 = existe_multiplo()
1
Ingrese el indice a[0]: 0
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 4
Ingrese el indice a[3]: 6
Ingrese el indice a[4]: 8
todos_pares(a[]) = true


./proyecto4_8
¿Qué función vas a usar?
 Ingrese 1 = todos_pares()
 Ingrese 2 = existe_multiplo()
2
Ingrese un valor para m: 3
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 4
Ingrese el indice a[3]: 5
Ingrese el indice a[4]: 7
existe_multiplo(a[], 3) = false


./proyecto4_8
¿Qué función vas a usar?
 Ingrese 1 = todos_pares()
 Ingrese 2 = existe_multiplo()
2
Ingrese un valor para m: 4
Ingrese el indice a[0]: 1
Ingrese el indice a[1]: 2
Ingrese el indice a[2]: 4
Ingrese el indice a[3]: 5
Ingrese el indice a[4]: 7
existe_multiplo(a[], 4) = true
*/