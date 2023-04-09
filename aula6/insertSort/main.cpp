#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

main ()  {
    //Inicializaçã do Vetor
    clock_t start, end;
	start = clock();
	double execution_time;
    FILE *fUnordered, *fOrdered;
    int *p = (int*) malloc(SIZE * sizeof(int));
    int i, j, chave, q;
   
   int c = 0; 
   
   //Leitura do arquivo
	if ((fUnordered = fopen("Arquivo.txt", "r")) == NULL){
		printf("Erro ao abrir o arquivo.");
	} else {
		printf("\nCarregando o vetor com os numeros do arquivo");
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &p[q]);
			q++;
		}
		printf("\nIniciando a ordenacao");
		//Algoritmo de Ordenação 
		for(j=1; j<SIZE; j++) {
			chave = p[j];
			i = j-1;
			while(i >= 0 && p[i] > chave) {
				p[i+1] = p[i];
				i--;
			}		
			p[i+1] = chave;
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
	
	end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos", execution_time);
    
//    //Laço de impressão do Vetor
//	for (int q=0; q<5; q++)	{
//        		printf("%d \n",v[q]);
//    	}
}

