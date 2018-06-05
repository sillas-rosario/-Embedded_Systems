
#include <math.h>
#include "modulo.h"

 void senoidal( struct vetor *ponteiro, int t , float a, int ph){

   int i;

for ( i=0; i < (ponteiro->tamanho) ;i++ ){

      ponteiro->vet[i] = t*sin(a*i + ph);
}


}
