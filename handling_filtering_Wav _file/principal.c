#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "modulo.h"

int main(int argc, char **argv) {

 	int a,b,c,d;
 	char arquivo[20] , filter[20];  
 	char *aq = arquivo;
	char *fi = filter;
 	struct wav_header *head;

	strcpy(arquivo, argv[1]); 
	strcpy(filter ,	argv[2]);
	
	// Reading Header:
  	head = read_header(aq);
	if (head == 0){ printf(" \n Error in Read_header !!");}

	//Handle Channel:	
	a = handle_channels(head);
	if(a!=0){ printf("\n Error in : Handl_Channels !!");}

	// Parsing Filter:
	b = filter_controler( head, fi );
	if(b!=0){printf("\n Error in : Parsing Filter !!");}

	// writing it back:
	c = writing_data(head);
	if(c!=0){printf("\n Error in : Handl_Channels !!");}
	
	//Desaloca:
	d = desaloc(head);
	if(d!=0){printf("\n Error in: Desaloc !!");}
	



return 0;	

}
