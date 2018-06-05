#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int geraSenoide(double *vet,double a, double f,double N){
    int i=0;
    for(i=0;i<N;i++){
        vet[i]=a*sin(2*3.141589*f*i);
    }
    return 0;
}
