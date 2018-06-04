
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"


// Endnesses reverse :

unsigned int endnessesReverse4( unsigned char *buffer4 ){
	unsigned int a,b,c,d,re;
	a = buffer4[0];
	b = buffer4[1]<<8;
	c = buffer4[2]<<16;
	d = buffer4[3]<<24;
	re = (a | b | c | d);
	return (unsigned int)re;
   	 

}

int endnessesReverse2(unsigned char *buffer2 ){
	int a,b,re;
	a = buffer2[0];
	b = buffer2[1]<<8;
	re = (a | b );	

	return re;
}




int writing_data(struct wav_header *h){

	//Declaring Buffers
	unsigned char *buffer4[4];
	unsigned char *buffer2[2];

	/*/
	for( int i = 0 ; i<1000; i++){
	
	printf(" dados saida : %d ",h->data[i]);

	}
	/*/


	// EndnessesReverse :


	//ChunkSize: |4bytes|
	*buffer4 =( unsigned char *) h->chunkSize;
	h->chunkSize = endnessesReverse4((unsigned char *)buffer4 );

	//SubChunk1Size |4bytes|:
	*buffer4 =( unsigned char *) h->subChunk1Size;
	h->subChunk1Size = endnessesReverse4((unsigned char *)buffer4 );
	

	//numChannels |2 bytes|:
	*buffer2 =( unsigned char *) h->numChannels;
	h->numChannels = endnessesReverse2((unsigned char *)buffer2 );
	

	//SampleRate  |4 bytes|: 
	*buffer4 = ( unsigned char *)h->sampleRate;
	h->sampleRate = endnessesReverse4((unsigned char *)buffer4 );
	

	// byteRate |4bytes|
	*buffer4 = ( unsigned char *)h->byteRate;
	h->byteRate = endnessesReverse4((unsigned char *)buffer4 );
	
	
	// blockAlign |2bytes|
	*buffer2 = ( unsigned char *)h->blockAlign;
	h->blockAlign = endnessesReverse2((unsigned char *)buffer2 );
	
	
	// bitsPerSample |2bytes|:
	*buffer2 =( unsigned char *) h->bitsPerSample;
	h->bitsPerSample = endnessesReverse2((unsigned char *)buffer2 ); 

	//SubChunl2Size |4 bytes|:
	*buffer4 = ( unsigned char *)h->subChunk2Size;
	h->subChunk2Size = endnessesReverse4((unsigned char *)buffer4 );

	
	

	printf(" \n EndnessesReverse:  ");
	printf("\nChunkSize: %d \n", h->chunkSize);	
	printf("subCHunk1Size: %d \n", h->subChunk1Size);
	printf("numChannels : %d \n", h->numChannels);
	printf("SampleRate : %d \n", h->sampleRate );
	printf("byteRate :%d \n", h->byteRate );
	printf("blockAlign:%d \n", h->blockAlign);
	printf("bitsPerSample: %d \n", h->bitsPerSample );
	printf("subCHunk2SIze: %d \n", h->subChunk2Size);


	// Open & Write :

	FILE *s1;
	s1 = fopen("saida_filtro2.wave","wb");

	fwrite( h->chunkId,4, 1, s1);
	fwrite( &h->chunkSize,4,1,s1);
	fwrite( h->format,1, 4, s1);
	fwrite( h->subChunk1Id,1,4,s1);
	fwrite( &h->subChunk1Size,4,1,s1);
	fwrite( &h->audioFormat,2,1,s1);
	fwrite( &h->numChannels,2,1,s1);
	fwrite( &h->sampleRate, 4,1,s1);
	fwrite( &h->byteRate,4,1,s1);
	fwrite( &h->blockAlign, 2,1,s1);
	fwrite( &h->bitsPerSample,2,1,s1);
	fwrite( h->subChunk2Id,4,1,s1);
	fwrite( &h->subChunk2Size,4,1,s1);
	fwrite( h->data, h->bitsPerSample/8,(h->subChunk2Size*8)/h->bitsPerSample ,s1);

	fclose(s1);


return 0;




}
