

#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"


struct wav_header *aloca_struct(){

struct wav_header *h;
h=(struct wav_header*)malloc(sizeof(struct wav_header));

if( h ==NULL){printf(" memoria nao alocada _ erro no maloc !!");}


return h;


}

int aloca_dados(struct wav_header *h){

	short *p;
	int tamanho;

	tamanho = (h->subChunk2Size*8)/( h->bitsPerSample);
	//printf("\n Numero de Amostras: %d  \n",tamanho);
	p = (short*)malloc(tamanho*sizeof(int));

	if(p==NULL){printf("ERROR: vetor nao alocado !!");}
	
	h->data = p ;
	
return 0;

}





