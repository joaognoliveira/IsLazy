#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutexDiag;    // declaracao do mutex global para ctrl threads

//####### DECLARAÇÃO DAS MATRIZES ######//

typedef struct mdouble // matriz DOUBLE
{
	double **Matriz;    /* Variavel correspondente a matriz */
	int linhas;         /* Quantidade de linhas da matriz */
	int colunas;        /* Quantidade de colunas da matriz */
	int linhaD;         /* Representa qual linha precisa ser calculada pela thread */
	int colunaD;        /* Representa qual coluna precisa ser calculada pela thread */
} mDouble;

//####### FINAL DA DECLARAÇÃO DAS MATRIZES ######//
/*
#
#
*/
//####### FUNÇÃO DE procura DOS VALORES ######// // INCOMPLETO

void *varreMatrizDouble(void *Matriz) 
{
  // jogar no git
}

//###### FINAL DA FUNÇÃO DE LEITURA DOS VALORES DAS MATRIZES ######//
/*
#
#
*/
//####### função le matriz double ######//

double *leMatrizDouble(unsigned int M, unsigned int N, char *fileName)
{
 register unsigned int i, j;
 mDouble *matDouble;
 FILE *arq;

 /* Se o nome do arquivo for nulo, aborte o programa */
 if (fileName == NULL)
 {
        fprintf(stderr,"O nome do arquivo nao pode ser nulo\n"); // nome do arquivo de entrada e nulo
        exit(EXIT_FAILURE);
 }
 
 arq = fopen(fileName,"r");
 if (arq == NULL)
 {
  	perror("A abertura do arquivo nao foi possivel\n"); // arquivo de entrada vazio
 	exit(EXIT_FAILURE);
 }

 /*Aloca a matriz*/
 matDouble = (double *) malloc (sizeof(double) * M * N);

 if (matDouble == NULL)
 {
    perror("Nao foi possivel alocar memoria (insf)!\n"); // Matriz nula
    exit(EXIT_FAILURE);
 }

 for (i=0; i<M; i++)
     for(j=0; j<N; j++)
     {
         fscanf(arq, "%f", &matDouble[i * columns + j]); // vai dar bo, trocar para double
     }

 fclose(arq);
 matDouble.linhas = M-1;
 matDouble.colunas = N-1;
 matDouble.linhaD = 0;
 matDouble.colunaD = 0;
 return matDouble; // retorna matriz (*)
}
//####### FINAL da função le matriz double ######//
/*
#
#
*/
//####### MAIN ######//

int main(int argc, char **argv)
{
	unsigned int M, N;         // M = linhas, N = colunas
	int T, V;	   	   // T = numero de threads, V = valor a ser buscado
	char *fileName;	  	   // nome do arquivo de entrada ainda é desconhecido
	mDouble *matDouble;	   // matriz para utilização em futuras funções DOUBLE (v2_)
	FILE *Entrada, *Saida;	   // arquivo de saida para impressao do resultado 

 /* Switch que pega os parametros da propria main */
 switch(argc)
 {
     case 0:
     case 1:
     case 2:
         fprintf(stderr, "Uso:\n\t %s <numero de linhas> <numero de colunas> <numero de threads> <valor a ser buscado> <arquivo de entrada (matriz onde a busca sera realizada)>\n", argv[0]);

         exit(EXIT_FAILURE);
         break;
     case 3:
         fprintf(stderr, "Uso:\n\t %s <numero de linhas> <numero de colunas> <numero de threads> <valor a ser buscado> <arquivo de entrada (matriz onde a busca sera realizada)>\n", argv[0]);

         exit(EXIT_FAILURE);
         break;
     case 4:
         fprintf(stderr, "Uso:\n\t %s <numero de linhas> <numero de colunas> <numero de threads> <valor a ser buscado> <arquivo de entrada (matriz onde a busca sera realizada)>\n", argv[0]);

         exit(EXIT_FAILURE);
         break;
     case 5:
         fprintf(stderr, "Uso:\n\t %s <numero de linhas> <numero de colunas> <numero de threads> <valor a ser buscado> <arquivo de entrada (matriz onde a busca sera realizada)>\n", argv[0]);

         exit(EXIT_FAILURE);
         break;
     case 6:
        M = atoi(argv[1]);
        N = atoi(argv[2]);
        T = atoi(argv[3]);
        V = atoi(argv[4]);
        fileName = argv[5];

        fprintf(stdout, "Procurando o valor %f em uma matriz %d x %d utilizando %d Threads, resultados no arquivo: saida.txt\n", V, M, N, T);
        break;
 }

	//readMatrixDouble (M, N, filename);
	matDouble=leMatrizDouble (M, N, fileName);

// ############### ATÉ AQUI TA TUDO CERTO, APARENTEMENTE ############## //
/*
#
#
#
*/
//######## PARTE DESTINADA AS THREADS ########//

	Entrada = fopen(fileName, "r");
	if (Entrada != NULL)
	{
		pthread_mutex_init(&mutexDiag, NULL);
		while (!feof(Entrada))
		{

			// terminar em branch v2
		}	
	}
	fclose(Entrada);
	fclose(Saida);
	pthread_exit(NULL);
}

//##### FINAL MAIN ######//
/*
#
#
*/

