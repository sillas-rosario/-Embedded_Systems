

struct vetor *aloca_vetor( int N);

 void senoidal( struct vetor *ponteiro, int t , float a, int ph);

void soma_vetores(struct vetor *v1, struct vetor *v2, struct vetor *vsoma);

void produto_vetores(struct vetor *v1, struct vetor *v2, struct vetor *vsoma);

float escalar_vetores(struct vetor *v1, struct vetor *v2);

void desaloca_vetor( struct vetor *v);

int escrever( struct vetor *v1, struct vetor *v2, struct vetor *vsoma, struct vetor *vprod , int N, FILE *s1, FILE *s2);

struct vetor{

 int tamanho;
 float *vet;

};
