#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"


 //converting to littleEndian from bigEndian: 

unsigned int bitwise4( unsigned  char *buffer4 ){
	unsigned int a,b,c,d,re;
	a = buffer4[0];
	b = buffer4[1]<<8;
	c = buffer4[2]<<16;
	d = buffer4[3]<<24;
	re = (a | b | c | d);
	return (unsigned int)re;
}

int bitwise2(unsigned char *buffer4){
	int a,b,re;
	a = buffer4[0];
	b = buffer4[1]<<8;
	re = (a | b );	

	return re;
   }




struct wav_header * read_header( char *arquivo ){
	



	//Auxiliars:
	int t;

	//Declaring Buffers:
	unsigned char buffer4[4];
	unsigned char buffer2[2];
	unsigned char *pbuffer4;
	unsigned char *pbuffer2;
	pbuffer4 =  buffer4;
	pbuffer2 =  buffer2;
	
	//Struct Pointer
	struct wav_header *head;
	head = aloca_struct();

	// Opening file
	FILE *s1;
	s1= fopen(arquivo,"rb");

	// reading the header:
	printf("\nWav Header : \n");
	
	//chunkId: 
	fread(head->chunkId, 4, 1, s1);
	printf("\nChunkId: %s", head->chunkId);

	//chunkSize:
	fread(buffer4, 4,1,s1);
	head->chunkSize  = bitwise4(pbuffer4);
	printf("\nChunkSize : %d \n",head->chunkSize);

	//Format 4 bytes:
	fread(head->format, 4, 1, s1);
	printf("Formato : %s \n", head->format);

	//SubchunkId 4 bytes:
	fread(head->subChunk1Id,4, 1, s1);
	printf("subChunk1Id: %s \n", head->subChunk1Id);

	//subChunk1Size 4 bytes:
	fread(buffer4, 4,1,s1);
	head->subChunk1Size  = bitwise4(pbuffer4);
	printf("ChunkSize1Size : %d \n",head->subChunk1Size);

	//audioFormat 2 bytes:
	fread(buffer2,2,1,s1);
	head->audioFormat = bitwise2(pbuffer2);
	printf("audioFormat : %d \n",head->audioFormat);

	//numChannels 2 bytes:
	fread(buffer2, sizeof(buffer2),1,s1);
	head->numChannels = bitwise2(pbuffer2);
	printf("numChannels : %d \n",head->numChannels);

	//sampleRate 4 bytes:
	fread(buffer4, 4,1,s1);
	head->sampleRate  = bitwise4(pbuffer4);
	printf("sampleRate : %d \n",head->sampleRate);

	//byteRate 4 bytes:
	fread(buffer4,4,1,s1);
	head->byteRate  =  bitwise4(pbuffer4);
	printf("byteRate : %d \n",head->byteRate);

	//blockAlign 2 bytes:
	fread(buffer2, 2,1,s1);
	head->blockAlign = bitwise2(pbuffer2);
	printf("blockAlign: %d \n",head->blockAlign);

	//bitsPerSample 2 bytes:
	fread(buffer2, 2,1,s1);
	head->bitsPerSample = bitwise2(pbuffer2);
	printf("bitsPerSample: %d \n",head->bitsPerSample);

	//subChunk2Id 4 bytes:
	fread(head->subChunk2Id,4,1,s1);
	head->subChunk2Id[4]='\0';
	printf("subChunk2Id2 : %s\n",head->subChunk2Id);

	//subChunk2Size 4 bytes:
	fread(buffer4, 4,1,s1);
	head->subChunk2Size = bitwise4( buffer4 );
	head->subChunk2Size = head->chunkSize - 36;
	printf("subChunk2Size : %d \n",head->subChunk2Size);

	// Alocar_vetores_dados:
	t = aloca_dados(head);
	t != 0 && printf("\n Error in Aloca_datas !! \n ");
	
	// Now that we have data allocated we can read it out:
	fread(head->data,  head->bitsPerSample/8 , (head->subChunk2Size*8)/head->bitsPerSample , s1);
	fclose(s1);




	return head;

}




