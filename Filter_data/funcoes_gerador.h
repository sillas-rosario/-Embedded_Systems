#ifndef FUNCOES_GERADOR_H
#define FUNCOES_GERADOR_H

double *aloca_vetor_double(int N); //aloca memória para um ponteiro do tipo double

short signed int *aloca_vetor_short(int N); //aloca memória para um ponteiro do tipo short

void desaloca_memoria_double(double *vetor_double); //desaloca memória de um ponteiro do tipo double

void desaloca_memoria_short(short signed int *vetor_short); //desaloca memória de um ponteiro do tipo short

short decimal_binario(short num_decimal); //converte valores decimais para valores binários

double *soma_double_onda1_onda2(double *vetor_double_soma, int amp, int freq1, int freq2, int freqs, int N); //soma os valores dos sinais senoidais

short signed int *soma_short_onda1_onda2(double *vetor_double_soma, short signed int *vetor_short_soma, int N); //converte os valores dos sinais senoidais de double para short

int escreve_txt_raw(double *valores_double, short signed int *valores_short, int N, char *nome_txt, char *nome_raw); //escreve em um arquivo .txt e em um arquivo short em um arquivo .raw os valores double e os valores short da soma entre os valores dos sinais senoidais, respectivamente.

#endif
