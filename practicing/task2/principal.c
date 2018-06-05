#include <stdio.h>
#include "modulo.h"
#define PI_2 1.57079632679

int main(int argc, char **argv)
{
/* Nomes dos arquivos, relativos ao diretório corrente */
char arquivo1[] = "./soma.txt";
char arquivo2[] = "./produto.txt";


/* Ponteiros para dois arquivos */
FILE *s1, *s2;
/* Ponteiros para quatro estruturas vetorias definidas em modulo.h */

struct vetor *v1, *v2, *vsoma, *vprod;
/* Tamanho dos vetores */
int N = 1000, cont;

float pe;

v1 = (struct vetor *)aloca_vetor(N);
v2 = (struct vetor *)aloca_vetor(N);
vsoma = (struct vetor*)aloca_vetor(N);
vprod = (struct vetor*)aloca_vetor(N);

senoidal(v1, 1, 0.0003, 0);

/* Preenche v1 com uma senoide */

senoidal(v2, 1, 0.0003, PI_2); 


/* Preenche v2 igual a v1, com fase de 90
graus em relaç~
ao a v1 */


soma_vetores(v1,v2,vsoma);
produto_vetores(v1,v2,vprod);
pe = escalar_vetores(v1,v2);
printf("Resultado do produto escalar: %f\n",pe);


int e=0;
e=escrever(v1,v2,vsoma,vprod,N, s1,s2);

return 0;

}
