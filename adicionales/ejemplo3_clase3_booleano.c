#include <stdbool.h> /* biblioteca estándar de booleanos*/
#include <stdio.h>


int main(void){
    int temp;   
    bool x = true; /* declaración de variables - true es una constante definida como 1*/
    bool y; /* declaración de variables*/

    /* Asignación de un booleano */
    y =  false;/* es una constante definida como 0 */

    /* Lectura */
    printf("ingrese un bool: 0 para false, 1 para true:\n");
    scanf("%d", &temp); /* en realidad pedimos un entero por teclado, no un booleano, usamos temp, ya que scanf no tiene definido un '%' para bool */

   x = temp; /* asignamos para que el valor quede en x */
   printf("x vale %d, y vale %d \n", x, y); /* en realidad imprimimos un entero, no un booleano, */
   
   return 0;
}
