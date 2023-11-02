#include <stdio.h>
#include <stdbool.h>

/* Definición de funciones en C */


/* Todo programa en C debe tener una función main, 
   desde ésta podemos realizar LLAMADAS A FUNCIONES.
   Una buena práctica de programación es realizar todo el 
   INPUT/OUTPUT (scanf, printf, etc) en la función main y en
   las demás funciones solo hacer cálculos.
 */

int sumar(int n, int m) {
    int res;

    res = n + m;

    /* Toda función cuyo tipo de retorno es distinto
       a void, debe tener una instrucción return */

    return res;
}


/* Especificación de la función primo:
   Dado un entero n, retorna true si es primo,
   false caso contrario. */
bool primo(int n) {

    int i;
    bool res;

    i = 2;
    res = true;

    while (i < n && res) {
        res = res && !(n % i == 0);
        i = i+1;
    }

    return res;
}

/* Cuando declaramos una función, ésta puede tener PARAMETROS.
en la función primo anterior, n es un parámetro de tipo int. Éste
es una variable más que puede ser utilizada en el cuerpo de la función
y que al momento de ejecutarse la llamada, será reemplazado por el valor
de la expresión.
*/




/*Este es un ejemplo de procedimiento en C, toma un argumento y no devuelve nada */

void imprime_esPrimo( bool n_esprimo){

  

    if (n_esprimo) {
        printf("El primer número ingresado es primo.\n");
    }
    else {
        printf("El primer número ingresado NO es primo.\n");
    }
}


int main(void) {

    int n,m,suma;
    bool n_esprimo;

    printf("Ingrese un número\n");
    scanf("%d",&n);

    printf("Ingrese otro número\n");
    scanf("%d",&m);

    suma = sumar(n,m);

    /* como ejerccio hacer una funcion que  imprima el resultado*/

    printf("La suma de ambos números es %d\n",suma);

    n_esprimo = primo(n);


    imprime_esPrimo (n_esprimo);
    
    return 0;
}

