/* Funções utilizadas na Tarefa 2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_filtro.h"

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

int tamanho_arquivo(char *nome){
	FILE *arquivo;
	double valor;
	char *nome_txt;
	int tam = 0;
	
	nome_txt = (char*)malloc(50);
	strcpy(nome_txt, nome);
	strcat(nome_txt, ".txt");
	arquivo = fopen(nome_txt, "r");
	if(arquivo == NULL){
		printf("Erro! Arquivo %s inválido ou vazio.\n", nome_txt);
		return -1;
	}else{
		while(fscanf(arquivo, "%lf\t", &valor)!=EOF){
			tam++;
		}
	}

	fclose(arquivo);

	return tam;
}

double *le_arquivo_dados(char *dados_txt, double *valores_dados, int tam_dados){
	FILE *arq_soma_ondas;
	double valor;
	int i;
	
	arq_soma_ondas = fopen(dados_txt, "r");
	if(arq_soma_ondas == NULL){
		printf("Erro! Arquivo %s inválido ou vazio.\n", dados_txt);
	}else{
		for(i=0; i<tam_dados; i++){
			fscanf(arq_soma_ondas, "%lf\t", &valor);
			valores_dados[i] = valor;
		}
	}

	fclose(arq_soma_ondas);

	return valores_dados;
}

double *le_arquivo_filtro(char *filtro_txt, double *valores_filtro, int tam_filtro){
	FILE *arq_filtro;
	double valor;
	int i;
	
	arq_filtro = fopen(filtro_txt, "r");
	if(arq_filtro == NULL){
		printf("Erro! Arquivo %s inválido ou vazio.\n", filtro_txt);
	}else{
		for(i=0; i<tam_filtro; i++){
			fscanf(arq_filtro, "%lf\t", &valor);
			valores_filtro[i] = valor;
		}
	}
	
	fclose(arq_filtro);

	return valores_filtro;
}

double *convolucao(double *A, double *B, int tamA, int tamB){
	int n_conv;
	int i, j, k;
	double temp;
	double *C;
	
	n_conv = (tamA+tamB) - 1;
	C = (double*)calloc(n_conv, sizeof(double));

	for(i=0; i<n_conv; i++){
		k = i;
		temp = 0.0;
		for(j=0; j<tamB; j++){
			if(k>=0 && k<tamA){
				temp = temp + (A[k]*B[j]);
			}
			k--;
			C[i] = temp;
		}
	}

	return C;
}

double *vetor_double_convolucao_filtro(double *valores_dados, double *valores_filtro, char *dados, char *filtro, int tam_dados, int tam_filtro){
	char *dados_txt, *filtro_txt;	

	dados_txt = (char*)malloc(50);
	filtro_txt = (char*)malloc(50);
	strcpy(dados_txt, dados);
	strcat(dados_txt, ".txt");
	strcpy(filtro_txt, filtro);
	strcat(filtro_txt, ".txt");
	
	valores_dados = convolucao(le_arquivo_dados(dados_txt, valores_dados, tam_dados), le_arquivo_filtro(filtro_txt, valores_filtro, tam_filtro), tam_dados, tam_filtro);

	return valores_dados;
}

short signed int *vetor_convolucao_double_int(double *vetor_convolucao_double, short signed int *vetor_valores_short_convolucao, int N){
	int i;
	for(i=0; i<N; i++){
		vetor_valores_short_convolucao[i] = (short signed int)vetor_convolucao_double[i];
		vetor_valores_short_convolucao[i] = decimal_binario(vetor_valores_short_convolucao[i]);
	}
	return vetor_valores_short_convolucao;
}

int escreve_txt_raw(double *valores_double, short signed int *valores_short, int N, char *dados){
	FILE *arq_txt, *arq_raw;
	char *dados_out_txt, *dados_out_raw;
	int i, j;
	
	dados_out_txt = (char*)malloc(50);
	strcpy(dados_out_txt, dados);
	strcat(dados_out_txt, ".out.txt");
	arq_txt = fopen(dados_out_txt, "w");
	if(arq_txt == NULL){
		printf("Erro ao escrever arquivo txt! Arquivo %s inválido ou vazio. \n", dados_out_txt);
		return -1;
	}else{
		for(i=0; i<N; i++){
			fprintf(arq_txt, "%lf\t", valores_double[i]);
		}
	}
	
	dados_out_raw = (char*)malloc(50);
	strcpy(dados_out_raw, dados);
	strcat(dados_out_raw, ".out.raw");
	arq_raw = fopen(dados_out_raw, "w");
	if(arq_raw == NULL){
		printf("Erro ao escrever arquivo raw! Arquivo %s inválido ou vazio. \n", dados_out_raw);
		return -1;	
	}else{
		for(j=0; j<N; j++){
			fprintf(arq_raw, "%d\t", valores_short[j]);
		}
	}

	printf("\nConvolução realizada com sucesso!\nDados salvos nos arquivos %s e %s.\n\n", dados_out_txt, dados_out_raw);
	
	fclose(arq_txt);
	fclose(arq_raw);

	return 0;
}

