


#include <math.h>
#include <stdio.h>
#include "modulo.h"

float escalar_vetores(struct vetor *v1, struct vetor *v2){

int i;
float pe,aux;

aux=0;
for (i=0 ; i< v1->tamanho; i++) {
     
     pe = (v1->vet[i]*v2->vet[i]) ;
     aux = pe+aux;

}

return aux;

}
