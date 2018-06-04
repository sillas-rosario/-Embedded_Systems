
all:
	gcc -c -Wall principal.c
	gcc -c -Wall read_header.c
	gcc -c -Wall alloc_data.c
	gcc -c -Wall handle_channels.c
	gcc -c -Wall writing_data.c
	gcc -c -Wall filter_controler.c
	gcc -c -Wall filter_operation.c
	gcc -c -Wall desaloc.c
	gcc principal.o alloc_data.o writing_data.o handle_channels.o read_header.o filter_controler.o filter_operation.o desaloc.o -o filtro -lm
	./filtro mamonas.wav filtro_am_64.txt
	

clear:
	rm *.o

a:
	gcc -c -Wall principal.c
	gcc -c -Wall read_header.c
	gcc -c -Wall alloc_data.c
	gcc -c -Wall handle_channels.c
	gcc -c -Wall writing_data.c
	gcc -c -Wall filter_controler.c
	gcc -c -Wall filter_operation.c
	gcc -c -Wall desaloc.c
	gcc principal.o alloc_data.o writing_data.o handle_channels.o read_header.o filter_controler.o filter_operation.o desaloc.o -o filtro -lm
	./filtro mamonas.wav filtro_tel_256.txt


	
