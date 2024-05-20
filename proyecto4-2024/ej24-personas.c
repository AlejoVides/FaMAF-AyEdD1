#include <stdio.h>
#include <limits.h>
#include <float.h>

typedef struct _persona {
	char 	*nombre;
	int 	edad;
	float 	altura;
	float 	peso;
} personaT;

float pesoPromedio(unsigned int longitud, personaT arr[]) {
	unsigned int i = 0;
	float promedio;
	while(i < longitud) {
		promedio = promedio + arr[i].peso;
		i++;
	}
	promedio = promedio / longitud;
	return promedio;
}

personaT personaDeMayorEdad(unsigned int longitud, personaT arr[]) {
	unsigned int i = 0;
	int edad = INT_MIN;
	personaT res;
	while(i < longitud) {
		if(edad < arr[i].edad) {
			edad = arr[i].edad;
			res = arr[i];
		}
		i++;
	}
	return res;
}

personaT personaDeMenorAltura(unsigned int longitud, personaT arr[]) {
	unsigned int i = 0;
	float altura = FLT_MAX;
	personaT res;
	while(i < longitud) {
		if(altura > arr[i].altura) {
			altura = arr[i].altura;
			res = arr[i];
		}
		i++;
	}
	return res;
}

int main(void) {
	personaT p1 = {.nombre="Juan", .edad=30, .altura=1.72, .peso=80};
	personaT p2 = {.nombre="Martin", .edad=24, .altura=1.81, .peso=85};
	personaT p3 = {.nombre="Silvia", .edad=44, .altura=1.64, .peso=60};
	personaT p4 = {.nombre="Abril", .edad=19, .altura=1.55, .peso=56};
	unsigned int longitud = 4;
	personaT arr[] = {p1, p2, p3, p4};

	float pesoProm = pesoPromedio(longitud, arr);
	personaT mayorEdad = personaDeMayorEdad(longitud, arr);
	personaT menorAltura = personaDeMenorAltura(longitud, arr);

	printf("El peso promedio es %f\n", pesoProm);
	printf("La persona con mayor edad es %s\n", mayorEdad.nombre);
	printf("La persona con menor altura es %s\n", menorAltura.nombre);
	return 0;
}

/*
gcc -Wall -Wextra -std=c99 ej24-personas.c -o ej24
./ej24
El peso promedio es 70.250000
La persona con mayor edad es Silvia
La persona con menor altura es Abril
*/