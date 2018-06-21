// IsLazy
// Integrantes::
//
// João Gabriel N.D. de Oliveira - 199617
// Leonardo Ferrari Soares       - 201164
//
//###################################################################
//
// Projeto1

#include <stdio.h>
#include <string.h>
#include <time.h>		
#include <stdlib.h>
#include <pthread.h>

//####### Variaveis Globais, já que a v3 usa mais funções ######//

unsigned int M, N; // M= linha, N= coluna
int encontrado, T; // encontrado = valor encontrado, T = numero de threads
float V; // usar float mesmo, flexivel para os 2 tipos de dado 

//####### Declaração da struct auxiliar a Matriz #######//

typedef struct mdouble // tipo que contem estrutura para passagem dos parametros da thread
{
//commitar sem auxiliar como membro da struct;
	float *Matriz;     /* Variavel correspondente a matriz / usar float afinal para tirar necessidade de funções duplicadas */
	int auxlinha;         /* Representa qual linha precisa ser calculada pela thread */
	int auxcoluna;        /* Representa qual coluna precisa ser calculada pela thread */
} mDouble;
mDouble matDouble;

//####### Final da declaração do tipo da matriz #######//

/*
#
#
*/

//####### Função de procura dos valores ######// // INCOMPLETO

void* varreMatrizDouble(void*arg)
{	
 while(matDouble.auxcoluna< M) // inicia na coluna auxiliar zerada até, o 
 {
	/*printf("valor=%f,linha= %d,coluna= %d\n", matDouble.Matriz[matDouble.auxlinha* N+ matDouble.auxcoluna], matDouble.auxlinha, matDouble.auxcoluna); */ 

 	if(matDouble.Matriz[matDouble.auxlinha* N+ matDouble.auxcoluna]== V)
	{ 
		printf("Valor encontrado na linha: %d, coluna: %d\n", matDouble.auxlinha+1, matDouble.auxcoluna+1); 
		encontrado= 0; 
	}
 	matDouble.auxcoluna++;
 }	
 matDouble.auxcoluna= 0;
 matDouble.auxlinha++;
}

//###### FINAL DA FUNÇÃO DE LEITURA DOS VALORES DAS MATRIZES ######//

/*
#
#
*/

//###### Função auxiliar utilizada durante o desenvolvimento do projeto ######//

void printmatriz(mDouble MATRIZ)
{
 int aux=N-1;
  for (int i= 0; i< M; i++)
     for(int j= 0; j< N; j++) 
     {
	 printf("%f ", matDouble.Matriz[i * N + j]);
	 if (j==aux)
	 {
	 	printf("\n");
	 }
     }
printf ("\n");
}

//####### Função que le e aloca a matriz:: ######//

mDouble leMatrizDouble(unsigned int M, unsigned int N, char *fileName)
{
 register unsigned int i, j;
 FILE *arq; // prestar atencao no nome

 /* Se o nome do arquivo for nulo */
 if (fileName== NULL)
 {
        fprintf(stderr,"O nome do arquivo nao pode ser nulo\n"); // nome do arquivo de entrada e nulo
        exit(EXIT_FAILURE); // saida
 }
 
 arq = fopen(fileName,"r");
 if (arq== NULL)
 {
  	perror("A abertura do arquivo nao foi possivel\n"); // arquivo de entrada vazio
 	exit(EXIT_FAILURE);
 }

 matDouble.Matriz= (float *) malloc (sizeof(float) * M * N);  //Alocação a matriz (como vetor, facil representação e melhor navegação "lógica")

 if (matDouble.Matriz== NULL)
 {
    perror("Nao foi possivel alocar memoria (insf)!\n"); // Matriz nula
    exit(EXIT_FAILURE);
 }

 for (i= 0; i< M; i++)
     for(j= 0; j< N; j++) // necessidade de tratar dados da mat como vetor? + compreensão
     {
         fscanf(arq, "%f", &matDouble.Matriz[i * N + j]); // padronização em utilizacao de dados float
     }

 fclose(arq);
 matDouble.auxlinha= 0;  // ambos auxiliares iniciam em 0 para futura passagem da função como rotina da thread *ver varreMatrizDouble*
 matDouble.auxcoluna= 0; 
 return matDouble;
}

//####### Final da função le matriz Double ######//

/*
#
#
*/

//####### MAIN ######//

int main(int argc, char **argv) // passagem de parametros pela entrada * instruções de compilação *
{
	char *fileName;	  	   // nome do arquivo de entrada ainda é desconhecido
	FILE *Entrada; //*Saida;   // arquivo de saida para impressao do resultado 
	int x, y, temp;		   // var contadores de auxiliar para declaração das threads

 /* Switch que pega os parametros da propria linha de comandos */
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
        M= atof(argv[1]);
        N= atof(argv[2]);
        T= atof(argv[3]);
        V= atof(argv[4]);
        fileName= argv[5];

        break;
 }
	
 matDouble=leMatrizDouble(M, N, fileName); // chama a função que puxa a matriz do arquivo

 //printmatriz (matDouble); // função que imprimia matriz (ajuda desenvolvimento)

//######## PARTE DESTINADA AS THREADS ########//
 
 pthread_t thread_id[T]; 
 encontrado= 1;
 temp= M/ T; // cada thread lê uma qntd de linhas, teste linha x coluna (algoritmo mais simples)
		
 for(x= 0 ;x< temp; x++) // quantidade de vezes que cada thread vai ler uma linha
 {
 	for(y= 0; y< T; y++) // chamada das threads
	{
		pthread_create(&thread_id[y], NULL, varreMatrizDouble, NULL);
		pthread_join(thread_id[y], NULL); 
	}	
 }
				
 if(T< M) 
 {	
 	temp= M- temp* T; // se o num de linhas da matriz for menor que o
		for(y= 0; y< temp; y++)
		{ 
			pthread_create(&thread_id[y], NULL, varreMatrizDouble, NULL);
			pthread_join(thread_id[y], NULL); // usar na repetição
		}
 }

 if(encontrado!= 0) //Busca vazia, valor de entrada nao encontrado
 	printf("Valor nao encontrado\n"); 	
				
 return 0;
}

//##### FINAL MAIN ######//
