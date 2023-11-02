#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int pedir_entero() {
	int var;

	printf("Ingrese un valor entero: ");
	scanf(" %d", &var);

	while(var<0) {
		printf("Ingrese un valor entero no negativo: ");
		scanf(" %d", &var);
	}
	return var;
}

bool es_primo(int n) {
    int i = 2;
    bool res = true;

    while (i<n&&res) {
        res = res && !(n%i==0);
        i = i+1;
    }
    return res;
}

int nesimo_primo(int N) {
	int n = 1;
	int primos = 0;

	if(N==0) {
		return 0;
	}

	while(primos!=N) {

		assert(primos<N);
		n=n+1;

		if(es_primo(n)) {
			primos=primos+1;
		}
	}
    return n;
}

int main(void) {
	int n = pedir_entero();

	int res = nesimo_primo(n);
	printf("El primo número %d es = %d\n", n, res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 primo.c -o proyecto4_15
./proyecto4_15
Ingrese un valor entero: 0
El primo número 0 es = 0


./proyecto4_15
Ingrese un valor entero: 1
El primo número 1 es = 2


./proyecto4_15
Ingrese un valor entero: 2
El primo número 2 es = 3


./proyecto4_15
Ingrese un valor entero: 5
El primo número 5 es = 11


./proyecto4_15
Ingrese un valor entero: 42
El primo número 42 es = 181
*/