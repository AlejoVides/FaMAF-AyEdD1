#include <stdio.h>
#include <stdbool.h>

int pedirNatural(void) {
	int nat;
	printf("Ingrese un valor entero: ");
	scanf(" %d", &nat);
	while(nat < 0) {
		printf("Ingrese un valor entero no negativo: ");
		scanf(" %d", &nat);
	}
	return nat;
}

int esPrimo(int n) {
    int i = 2;
    bool res = true;
    while (i < n && res) {
        res = res && !(n % i == 0);
        i++;
    }
    return res;
}

int nesimoPrimo(int N) {
	int n = 1;
	int primos = 0;
	while (primos != N) {
		n++;
		if (esPrimo(n)) {
			primos++;
		}
	}
    return n;
}

int main(void) {
	int N = pedirNatural();
	int res = nesimoPrimo(N);
	printf("El primo numero %d es = %d\n", N, res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej23-primo.c -o ej23
./ej23
Ingrese un valor entero: 4
El primo numero 4 es = 7

./ej23
Ingrese un valor entero: 55
El primo numero 55 es = 257
*/