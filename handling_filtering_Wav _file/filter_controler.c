#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"


// filter controler comands everything related to the parsing filter process
// such as:
// filter_size to know the size of txt file
// convolutions operation either oneChannel or twoChannels
// alloc and desalloc pointer auxiliars
// converting datas

int filter_controler(struct wav_header  *head ,  char  *filter){

	int aux1,aux2,aux3,aux4;
	int tamanho_conv, txt_size;
	float *p;	 // ponteiro para vetor filtro
	tamanho_conv = ((head->subChunk2Size*8)/head->bitsPerSample);

	// getting filter size 
	txt_size = filter_size(filter);
	//parsing filter to a pointer f1
	p = alloc_filter(filter, txt_size);
	
	

	// calling convolutions operation && A function to put the channel back together 
	if(head->numChannels == 2){ 
		printf("Convolition | loading data  ...");
		aux1 = convollution(head->channel01, p, tamanho_conv/2, txt_size);
		aux1!=0 && printf("Erro in convolution");

		aux2 = convollution(head->channel02, p, tamanho_conv/2, txt_size);
		aux2!=0 && printf("Erro in convolution");

		aux4 = channel_merge(head, tamanho_conv,2);
		aux4!=0 && printf("Erro in convolution");
		
		

	}	
	if(head->numChannels == 1){ 

		aux3 = convollution(head->channel01, p, tamanho_conv, txt_size);
		aux3!=0 && printf("Erro in convollution one channel");
		aux4 = channel_merge(head, tamanho_conv,1);
		aux4!=0 && printf("Erro in channel_merge");

	}



	




return 0;


}
