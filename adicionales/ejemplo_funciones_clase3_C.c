#include <stdio.h>

int f(int x) /*que hace esta funcion??*/
{
  int i=2;
  while (x%i!=0 && x>1){
    i=i+1;
  }
  return (i==x);
}


int pideEntero(void){
  int x;
  printf("Ingrese un valor para x\n"); 
  scanf("%d", &x); 
  return x;
}


int main(void) {
  printf("El resultado es %d\n", f(pideEntero())); 
  return 0;
}
