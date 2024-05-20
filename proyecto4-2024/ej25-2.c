#include <stdio.h>
#include <assert.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int menorQueN(int N) {
	int x = 0;
	while(x < N) {
		if((x * x * x + x) >= N) {
			return x;
		}
		x++;
	}
	return x;
}

int main(void) {
	int N = pedirEntero();

	// { P: N >= 0 }
	assert(N >= 0);

	int res = menorQueN(N);
	printf("El menor x tal que se cumple (x^3 + x >= %d) es %d\n", N, res);

	// { Q: x^3 + x >= N }
	assert((res * res * res + res) >= N);
	return 0;
}