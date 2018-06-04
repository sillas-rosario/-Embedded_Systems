
//read_header:
struct wav_header *read_header(char *arquivo);
unsigned int bitwise4( unsigned  char *buffer4 );
int bitwise2(unsigned char *buffer4);

// aloca_datas:
struct wav_header *aloca_struct();
int aloca_dados(struct wav_header *h);


// write_dados:
int writing_data(struct wav_header *h);
unsigned int endnessesReverse4( unsigned char *buffer4 );
int endnessesReverse2(unsigned char *buffer2);

//handle_channels
int handle_channels ( struct wav_header *);
int alloc_channel(struct wav_header *h , int tamanho);

// filter:
int filter_controler( struct wav_header *head, char *filter);
int convollution ( double *channel, float*f1, int tamanho, int filter_size);
float *alloc_filter(char *filter, int tam);
int filter_size(char *filter);
int channel_merge(struct wav_header *head, int tamanho, int aux);

// desaloc:
int desaloc( struct wav_header *head );


#define MAX_INT 320 //32000

//#define MAX_INT_D 3.2768E4

struct wav_header {

	unsigned	char chunkId[4];
	unsigned	char format[4];
	unsigned	char subChunk1Id[4];
	unsigned	char subChunk2Id[5]; 

	unsigned	int chunkSize;
	unsigned	int subChunk1Size;
	unsigned	int subChunk2Size;
	unsigned	short sampleRate;
	unsigned	int byteRate;

	unsigned	short audioFormat;
	unsigned	short numChannels;
	unsigned	short blockAlign;
	unsigned	short bitsPerSample;
			short *data;

		// to handle with channels:
			double *channel01;
    			double *channel02;



} ;




