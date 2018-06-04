#include "modulo.h"
#include <stdlib.h>

int desaloc( struct wav_header *head ){

free(head->data);
free(head->channel01);
free(head->channel02);
free(head);

return 0;

}
