
#include <stdlib.h>
#include "modulo.h"

void desaloca_vetor( struct vetor *v){

free(v->vet);
free(v);

}
