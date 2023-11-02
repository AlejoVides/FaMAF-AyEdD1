#include <stdio.h>
#include <stdbool.h>

/* Definición de la estructura en C */
struct par{
  int fst;
  int snd;
};


void imprime_par( struct par p){
/*Leo los campos  */
  printf(" El par es  fst=%d y snd= %d\n",p.fst, p.snd); 

}

struct par inventa_par(void){
  struct par res;
  res.fst=95;
  res.snd = 44;
  return res;
}


int main(void) {
/*Declaro la variable del tipo Struct */
  struct par p0;

/*Inicializo los campos de la estructura*/

  p0.fst = 4;
  p0.snd=45;

  imprime_par(p0);

  imprime_par(inventa_par());

  return 0;
}

