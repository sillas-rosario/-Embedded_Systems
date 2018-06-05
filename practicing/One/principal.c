#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"importa.h"
int main(int argc,char **argv){
    double a,f,N,p,fa;
    a=atof(argv[1]);
    f=atof(argv[2]);
    N=atof(argv[3]);
    p=atof(argv[4]);
    fa=atof(argv[5]);

    double *Sen;
    Sen=alocavet(N);

    geraSenoide(Sen,a,f,N);
    double c = calcRms (Sen,N,fa)

    exibir(c);
    
    free(Sen);
    return 0;
}

