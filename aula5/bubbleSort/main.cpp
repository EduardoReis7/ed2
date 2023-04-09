#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

#define SIZE 100000

int main() {
	//Inicializa?? do Vetor
	clock_t start, end;
	start = clock();
	double execution_time;
	int i, j = 0,  aux, q = 0;
	float interacoes = 0;
	int *p = (int *) malloc(SIZE * sizeof(int));
	FILE *fUnordered, *fOrdered;
	
	//Leitura do arquivo
	if ((fUnordered = fopen("Arquivo.txt", "r")) == NULL){
		printf("Erro ao abrir o arquivo.");
	} else {
		if (!p) {
			printf("Erro: Memória insuficiente!");
		} else {
			printf("\nCarregando o vetor com os numeros do arquivo");
			//Carregamento do vetor com os numeros do arquivo
			while(!feof(fUnordered)) {
				fscanf(fUnordered, "%d", &p[q]);
				q++;
			}
			printf("\nIniciando a ordenacao");
			//Algoritmo de Ordena??o 
            while (j < SIZE) {
              for(i = 0; i < SIZE-1; i++) {
                if(p[i] > p[i + 1]) {
     			  aux=p[i];
     			  p[i] = p[i+1];
     			  p[i+1] = aux;
     			  interacoes++;
                }
              }
		      j++;
           }
           if ((fOrdered = fopen("arquivo_ordenado.txt", "w+")) == NULL) {
        	 printf("Erro ao abrir o arquivo.");
		   } else {
		   	   printf("\nGravando arquivo ordenado\n");
	           //Gravando o arquivo ordenado
	           for (q = 0; q < SIZE;q++) {
	               fprintf(fOrdered, "%d\n", p[q]);
	           }
		   }
		}
	}
	
	end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos", execution_time);
	printf("\nA ordenacao teve %f interacoes.\n", interacoes);

    fclose(fUnordered);
    fclose(fOrdered);
    system("pause");  

}
