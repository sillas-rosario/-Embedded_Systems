/* Funções utilizadas na Tarefa 1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes_gerador.h"

double *aloca_vetor_double(int N){
	double *vetor_double;
	vetor_double = (double*)malloc(sizeof(double)*N);
	return vetor_double;
}

short signed int *aloca_vetor_short(int N){
	short signed int *vetor_short;
	vetor_short = (short signed int*)malloc(sizeof(double)*N);
	return vetor_short;
}

void desaloca_memoria_double(double *vetor_double){
	free(vetor_double);
}

void desaloca_memoria_short(short signed int *vetor_short){
	free(vetor_short);
}

short decimal_binario(short num_decimal){
	short binario = 0, i = 0;
	int resto;

	while(num_decimal != 0){
		num_decimal = num_decimal/2;
		resto = num_decimal%2;
		binario = binario + (resto*i);
		i = i*10;
	}

	return binario;
}

double *soma_double_onda1_onda2(double *vetor_double_soma, int amp, int freq1, int freq2, int freqs, int N){
	double onda1, onda2;
	int i;

	for(i=0; i<N; i++){
		onda1 = amp*sin(2*3.14*freq1*i/freqs);
		onda2 = amp*sin(2*3.14*freq2*i/freqs);
		vetor_double_soma[i] = onda1 + onda2;
	}

	return vetor_double_soma;
}

short signed int *soma_short_onda1_onda2(double *vetor_double_soma, short signed int *vetor_short_soma, int N){
	int i;

	for(i=0; i<N; i++){
		vetor_short_soma[i] = (short signed int)vetor_double_soma[i];
		vetor_short_soma[i] = decimal_binario(vetor_short_soma[i]);
	}

	return vetor_short_soma;
}

int escreve_txt_raw(double *valores_double, short signed int *valores_short, int N, char *nome_txt, char *nome_raw){
	FILE *arq_txt, *arq_raw;
	int i, j;
	
	arq_txt = fopen(nome_txt, "w");
	if(arq_txt == NULL){
		printf("Erro! Arquivo %s inválido ou vazio.\n", nome_txt);
		return -1;
	}else{
		for(i=0; i<N; i++){
			fprintf(arq_txt, "%lf\t", valores_double[i]);
		}

	}
	
	arq_raw = fopen(nome_raw, "w");
	if(arq_raw == NULL){
		printf("Erro! Arquivo %s inválido ou vazio.\n", nome_raw);
		return -1;	
	}else{
		for(j=0; j<N; j++){
			fprintf(arq_raw, "%d\t", valores_short[j]);
		}		
	}

	printf("\nDados da soma entre os sinais senoidais salvos nos arquivos %s e %s.\n\n", nome_txt, nome_raw);

	fclose(arq_txt);
	fclose(arq_raw);

	return 0;
}
