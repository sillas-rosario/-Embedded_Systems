

#include "modulo.h"
#include <stdio.h>

void produto_vetores(struct vetor *v1, struct vetor *v2, struct vetor *vsoma){

int i;


for (i=0 ; i< v1->tamanho; i++) {

     vsoma->vet[i] = v1->vet[i] * v2->vet[i] ; 


}




}
