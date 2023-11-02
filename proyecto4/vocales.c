#include <stdio.h>
#include <stdbool.h>

char pedir_letra() {
	char cha;

	printf("Ingrese una letra: ");
	scanf("%c", &cha);
	return cha;
}

bool es_vocal(char letra) {
	if (letra=='a' || letra=='A' || letra=='e' || letra=='E' || letra=='i' || letra=='I' || letra=='o' || letra=='O' || letra=='u' || letra=='U') {
		return true;
	} else {
		return false;
	}
}

void imprimir_booleano(bool res) {
	if (res==0) {
		printf("falso\n");
	} else {
		printf("verdadero\n");
	}
}

int main(void) {
	char letra = pedir_letra();
	bool res = es_vocal(letra);

	imprimir_booleano(res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 vocales.c -o proyecto4_4
./proyecto4_4
Ingrese una letra: o
verdadero


./proyecto4_4
Ingrese una letra: E
verdadero


./proyecto4_4
Ingrese una letra: v
falso
*/