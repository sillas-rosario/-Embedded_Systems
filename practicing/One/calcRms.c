#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double calcRms(double *vet,double N,double fa){
    double vrms = 0;
    int k=0;
    for(k=0;k<N;k++){
        vrms = vrms + vet[k]*vet[k];
    }
    vrms = vrms/(N*fa);
    vrms = sqrt(vrms);
    return vrms;
}
