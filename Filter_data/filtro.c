#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_filtro.h"

int main(int argc, char **argv){

	double *valores_dados, *valores_filtro;
	short signed int *valores_short_convolucao;
	int N, tam_dados, tam_filtro;
	char *dados_const, *filtro_const;

	if(argc != 3){
		printf("Você não digitou todos os argumentos necessários. Tente novamente.");
		return -1;
	}
														
	dados_const = argv[1];
	filtro_const = argv[2];

	tam_dados = tamanho_arquivo(dados_const);
	tam_filtro = tamanho_arquivo(filtro_const);
	N = tam_dados + tam_filtro - 1;

	valores_dados = aloca_vetor_double(N);
	valores_short_convolucao = aloca_vetor_short(N);
	valores_filtro = aloca_vetor_double(N);

	valores_dados = vetor_double_convolucao_filtro(valores_dados, valores_filtro, dados_const, filtro_const, tam_dados, tam_filtro);
	valores_short_convolucao = vetor_convolucao_double_int(valores_dados, valores_short_convolucao, N);
	escreve_txt_raw(valores_dados, valores_short_convolucao, N, dados_const);

	desaloca_memoria_double(valores_dados);
	desaloca_memoria_short(valores_short_convolucao);
	desaloca_memoria_double(valores_filtro);

	return 0;
}
