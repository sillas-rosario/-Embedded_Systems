#include "modulo.h"


int escrever( struct vetor *v1, struct vetor *v2, struct vetor *vsoma, struct vetor *vprod , int N, FILE *s1, FILE *s2){

/* In´ıcio das opera¸c~oes sobre os arquivos */
umask(S_IWGRP|S_IRGRP|S_IXGRP|S_IWOTH|S_IROTH|S_IXOTH);
s1 = open(arquivo1,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
s2 = open(arquivo2,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
/* Testa se a abertura de qualquer dos arquivos falhou */
if (s1 < 0 || s2 < 0) {
perror("Falha na abertura do arquivo:");
desaloca_vetor(v1);
desaloca_vetor(v2);
desaloca_vetor(vsoma);
desaloca_vetor(vprod);
return -1;
}




int mywrite(int i , struct vetor v1){


float *p;
int K;
p = v1->v;
K = N*sizeof(float);
int cont=0;

if (i==1){

while (K > 0) {
cont = write(s1, p, K*sizeof(float));
if (cont < 0) {
printf("Falha na escrita do arquivo\n");
_exit(-1);
}
K -= cont;
p += cont;
}
}

if(i==2){
while (K > 0) {
cont = write(s2, p, K*sizeof(float));
if (cont < 0) {
printf("Falha na escrita do arquivo\n");
_exit(-1);
}
K -= cont;
p += cont;

}
}
}


/* Abertura bem sucedida. Escreve no arquivo. */

int w=0;
w=mywrite(1, &v1->v[cont]);
w=mywrite(1, &v2->v[cont]);
w=mywrite(1, &vsoma->v[cont]);
w=mywrite(2, &v1->v[cont]);
w=mywrite(2, &v2->v[cont]);
w=mywrite(2, &vprod->v[cont]);


/* Miss~ao cumprida. Desaloca todos os recursos. */
desaloca_vetor(v1);
desaloca_vetor(v2);
desaloca_vetor(vsoma);
desaloca_vetor(vprod);
close(s1);
close(s2);
return 0;

}
