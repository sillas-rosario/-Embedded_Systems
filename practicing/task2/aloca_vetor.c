
#include "modulo.h"
#include <stdlib.h>


 struct vetor *aloca_vetor( int N){

  struct vetor *pont;
  float *p;

  pont=(struct vetor*)malloc(sizeof(struct vetor)); 

  p = (float *)malloc(N *sizeof(float)); 

  pont->vet = p;
  pont->tamanho = N;
  

  return pont;

}

