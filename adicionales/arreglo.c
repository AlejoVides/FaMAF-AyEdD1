#include <stdio.h>
#define N 5

int main(void){
    int i;
    int a[N];

    i=0;
    while (i<N){
	printf("ingrese el elemento %d del arreglo:\n",i);
	scanf("%d",&a[i]);
	i=i+1;
    }


    i=0;
    printf("\n\nEl arreglo ingresado:\n");
    while (i<N){
    printf("el elemento %d es %d\n",i,a[i]);
    i=i+1;
    }

}



