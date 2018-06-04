#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"


int alloc_channel(struct wav_header *h , int tamanho){

   double *p1;

   if (h->numChannels ==2){
	double *p2;

	p1 = (double *) malloc((tamanho/2) * sizeof(double ));
	p2 = (double *) malloc((tamanho/2) * sizeof(double ));

	h->channel01 = p1;
	h->channel02 = p2;
	return 2;

   } else{

	p1 = (double *) malloc((tamanho) * sizeof(double ));
	h->channel01 = p1;
	return 1;
	}
   	

return 0;


}


int handle_channels ( struct wav_header *h){

	int i;
	int c1;
	int r ; 
	int tamanho;
	tamanho = ((h->subChunk2Size*8)/h->bitsPerSample);
	c1 = 0;


	r = alloc_channel(h ,tamanho);
	(r==0) && printf("\n Erro in alloc_channel !! ");


 	if ( r == 2 ){
	int c2; 
	c2 = 0;
		for ( i = 0; i<tamanho ; i++){
			if(i%2 == 0){

				h->channel01[c1] = ((double)h->data[i])/(MAX_INT);
				c1++; 


			}
			if(i%2==1){

				h->channel02[c2] = ((double) h->data[i])/(MAX_INT);
				c2++;	
				
				}
			
				

		}



	}
	if( r==1 ){

		for ( i = 0; i<tamanho/2 ; i++){

			h->channel01[i] = ((double)h->data[i])/(MAX_INT);

		}




	}


	// teste:
	/*/printf("\n dados ||  canal1  || canal2  ");
	for( i=0; i< 150 ;i++){

		//printf(" \n  %f  ||%f  ||%f  \n" ,h->data[i],  h->channel01[i], h->channel02[i]); 
		//printf("\n canal 2:  %f   ||  data : %f", h->channel01[i] , h->channel02[i] );


	}
	/*/





return 0;
}
