#include <stdio.h>

void imprimir_hola(void) {
	printf("hola\n");
}

void imprimir_chau(void) {
	printf("chau\n");
}

int main(void) {
	imprimir_hola();
	imprimir_hola();
	imprimir_chau();
	imprimir_chau();
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej9-saludos.c -o ej9
./ej9
hola
hola
chau
chau
*/