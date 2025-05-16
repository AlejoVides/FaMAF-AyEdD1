#include <stdio.h>

int pedirEntero(void) {
	int var;
	printf("Ingrese un valor entero: ");
	scanf("%d", &var);
	return var;
}

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n = pedirEntero();
    int res = fibonacci(n);
    printf("El %d-nesimo numero de Fibonacci es: %d\n", n, res);
    return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej27-9.c -o ej27
./ej27
Ingrese un valor entero: 4
El 4-nesimo numero de Fibonacci es: 3

./ej27
Ingrese un valor entero: 16
El 16-nesimo numero de Fibonacci es: 987
*/