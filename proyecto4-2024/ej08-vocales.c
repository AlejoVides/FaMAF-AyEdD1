#include <stdio.h>
#include <stdbool.h>

char pedirChar(void) {
	char c;
	printf("Ingrese un caracter: ");
	scanf("%c", &c);
	return c;
}

bool esVocal(char letra) {
	if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
		return true;
	}
	return false;
}

int main(void) {
	char letra = pedirChar();
	bool res = esVocal(letra);
	printf("%d\n", res);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej08-vocales.c -o ej8
./ej8
Ingrese un caracter: b
0

./ej8
Ingrese un caracter: E 
1
*/