
all:
	gcc -c -Wall principal.c
	gcc -c -Wall aloca_vetor.c
	gcc -c -Wall senoidal.c
	gcc -c -Wall soma_vetores.c
	gcc -c -Wall produto_vetores.c
	gcc -c -Wall escalar_vetores.c
	gcc -c -Wall desaloca_vetor.c
	gcc -c -Wall escrever.c
	gcc principal.o escrever.o aloca_vetor.o senoidal.o soma_vetores.o produto_vetores.o escalar_vetores.o desaloca_vetor.o -o roda -lm ./roda

clear:
rm *.o
	
