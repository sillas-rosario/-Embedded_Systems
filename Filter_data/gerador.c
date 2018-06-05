#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes_gerador.h"

int main (int argc, const char **argv){
	
	int freq1, freq2;
	int N, amp, freqs;
	double *amostras_double;
	short signed int *amostras_short;
	const char *nome_const;
	char *nome_txt, *nome_raw;

	amp = 10000;
	freqs = 8000;
	nome_txt = (char*)malloc(50);
	nome_raw = (char*)malloc(50);

	if(argc != 5){
		printf("Você não digitou todos os argumentos necessários. Tente novamente.");
		return -1;
	}

	freq1 = atoi(argv[1]);
	freq2 = atoi(argv[2]);
	N = atoi(argv[3]);
	nome_const = argv[4];

	strcpy(nome_txt, nome_const);
	strcat(nome_txt, ".txt");
	strcpy(nome_raw, nome_const);
	strcat(nome_raw, ".raw");

	amostras_double = aloca_vetor_double(N);
	amostras_short = aloca_vetor_short(N);

	amostras_double = soma_double_onda1_onda2(amostras_double, amp, freq1, freq2, freqs, N);
	amostras_short = soma_short_onda1_onda2(amostras_double, amostras_short, N);

	escreve_txt_raw(amostras_double, amostras_short, N, nome_txt, nome_raw);

	desaloca_memoria_double(amostras_double);
	desaloca_memoria_short(amostras_short);

	return 0;
}
