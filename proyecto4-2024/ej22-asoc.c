#include <stdio.h>
#include <stdbool.h>
#define N 5

typedef char claveT;
typedef int valorT;

struct asoc {
	claveT clave;
	valorT valor;
};

void pedirArregloAsoc(int nMax, struct asoc a[]) {
	int i = 0;
	while (i < nMax) {
		printf("Ingrese clave y valor para a[%d]: ", i);
		scanf(" %c", &a[i].clave);
		scanf("%d", &a[i].valor);
		i++;
	}
}

char pedirClave() {
	char var;
	printf("Ingrese otra clave para verificar su existencia: ");
	scanf(" %c", &var);
	return var;
}

bool asocExiste(int tam, struct asoc a[], claveT c) {
	int i = 0;
	while(i < tam) {
		if(a[i].clave == c) {
			return true;
		}
		i++;
	}
	return false;
}

int main(void) {
	struct asoc a[N];
	pedirArregloAsoc(N, a);
	claveT clave = pedirClave();
	bool res = asocExiste(N, a, clave);
	if(res) {
		printf("La clave '%c' si existe en el arreglo\n", clave);
	} else {
		printf("La clave '%c' no existe en el arreglo\n", clave);
	}
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej22-asoc.c -o ej22
./ej22
Ingrese clave y valor para a[0]: a 1
Ingrese clave y valor para a[1]: b 2
Ingrese clave y valor para a[2]: c 3
Ingrese clave y valor para a[3]: d 4
Ingrese clave y valor para a[4]: e 5
Ingrese otra clave para verificar su existencia: d
La clave 'd' si existe en el arreglo

./ej22
Ingrese clave y valor para a[0]: f 6
Ingrese clave y valor para a[1]: g 7
Ingrese clave y valor para a[2]: h 8
Ingrese clave y valor para a[3]: i 9
Ingrese clave y valor para a[4]: j 10
Ingrese otra clave para verificar su existencia: l
La clave 'l' no existe en el arreglo
*/