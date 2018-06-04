
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"



// getting filter size:

int filter_size(char *filter ){

	FILE *f1;
	f1 = fopen(filter,"r");
	int tam;
	float aux;
	
	tam = 0;

		while( fscanf (f1,"%f\t", &aux)!= EOF){
			tam ++ ; 

		}
	fclose(f1);
 return tam;
}

//alloc filter:

float *alloc_filter(char *filter, int tam){
	float aux;
	float *p;
	int i;
 	FILE *f1;
	f1 = fopen(filter,"r");
	aux = 0;

		p = (float*)malloc(tam * sizeof(float));
		if(f1 == NULL) { printf("ERROR  in filter ");}

		for( i = 0; i< tam ; i++){
			fscanf(f1, "%f\t", &aux);
			p[i] = aux;
		}

	fclose(f1);

return p;
}


							

int convollution ( double *channel, float* f1, int tamanho, int filter_size){

	int i, j, k, h;
	double temp;
	double *C;

	h = ( filter_size + tamanho ) ;

	C = (double*)calloc( h,  sizeof(double));
	if(C==NULL){printf("Erro in calloc C1");}

	// CONVOLUTION Code:
		for(i = 0; i< h; i++){
			k=i;
			temp = 0.0;
			for(j = 0; j< filter_size; j++){
				if(k>=0&&k<tamanho){

					temp = temp + (f1[j] * channel[k]);
				}
				k--;
				C[i] = temp;
			}
	
	
		}


		
		// normalizing C 
		int aux = 0;
		for (i = (filter_size/2) ; i< (h - filter_size/2 ); i++){

			channel[aux] = C[i]; 
			aux++;

		}
		
	


return 0;

}




channel_merge(struct wav_header *head, int tamanho, int aux){

	//Auxiliares:
	int cont1;
	int i;
	cont1=0;
	
	if( aux ==2){

	int cont2;
	cont2=0;

	for( i = 0 ; i< tamanho ; i++){
		
		if(i%2==0){
		
			head->data[i] = (short)(head->channel01[cont1])*MAX_INT;
			cont1++;
			

		}
		if(i%2==1){

			head->data[i] = (short)(head->channel02[cont2])*MAX_INT;
			cont2++;
			}
		

		}
	return 0;

	}
	if( aux ==1){
	
	
		for (i = 0 ; i< tamanho ; i++){

			head -> data[i] = (short)head -> channel01[i]*MAX_INT ;
	

		}
		
	return 0;
	}



return 1;

}







































