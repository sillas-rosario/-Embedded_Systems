#ifndef FUNCOES_FILTRO_H
#define FUNCOES_FILTRO_H

double *aloca_vetor_double(int N); //aloca memória para um ponteiro do tipo double

short signed int *aloca_vetor_short(int N); //aloca memória para um ponteiro do tipo short signed int

void desaloca_memoria_double(double *vetor_double); //desaloca memória de um ponteiro do tipo double

void desaloca_memoria_short(short signed int *vetor_short); //desaloca memória de um ponteiro do tipo short signed int

short decimal_binario(short num_decimal); //converte valores decimais para valores binários

int tamanho_arquivo(char *nome); //retorna o número de valores contidos em um arquivo

double *le_arquivo_dados(char *dados_txt, double *valores_dados, int tam_dados); //lê o arquivo com os valores da soma dos sinais senoidais

double *le_arquivo_filtro(char *filtro_txt, double *valores_filtro, int tam_filtro); //lê o arquivo com os valores do filtro

double *convolucao(double *A, double *B, int tamA, int tamB); //executa a convolução entre dois vetores

double *vetor_double_convolucao_filtro(double *valores_dados, double *valores_filtro, char *dados, char *filtro, int tam_dados, int tam_filtro); //executa a convolução entre os valores da soma dos sinais senoidais e os valores do filtro

short signed int *vetor_convolucao_double_int(double *vetor_convolucao_double, short signed int *vetor_valores_short_convolucao, int N); //converte de double para short signed int os valores da convolução entre a soma dos sinais senoidais e os valores do filtro

int escreve_txt_raw(double *valores_double, short signed int *valores_short, int N, char *dados);//escreve em um arquivo .txt e em um arquivo short em um arquivo .raw, respectivamente, os valores double e os valores short signed int da convolução entre
//a soma dos sinais senoidais e os valores do filtro

#endif
