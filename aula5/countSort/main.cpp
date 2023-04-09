#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000

void counting_sort(int *array, int size) {
	int i, min, max;
	int j=0; 
	float interacoes = 0;
	min = max = array[0];
	//Identifica o Maior Elemento
	for(i = 1; i < size;  i++) {
		if (array[i] < min)
			min = array[i];
		else if (array[i] > max)
			max = array[i];  
	}
	int range = max - min + 1;
	int *count = (int *) malloc(range * sizeof(int));
	//Marca Todas as posi??es com Zero
	for(i = 0; i < range; i++)
		count[i] = 0;
	//Marca as posi??es ocupadas
	for(i = 0; i < size; i++)
		count[array[i] - min]++;
	int indice;
	indice=0; 
	//Array recebe as posicoes ocupadas
	for(i = min; i <= max; i++)
		for(j = 0; j < count[ i - min ]; j++) {
			array[indice] = i;
			indice++;
			interacoes++;
		}
	printf("\nA ordenacao teve %f interacoes.\n", interacoes);
	free(count);
}

main () {
	
	//Inicializa?? do Vetor
	clock_t start, end;
	start = clock();
	double execution_time;
	int *p = (int *) malloc(SIZE * sizeof(int));
	int i, j = 0,  aux, q = 0;
	FILE *fUnordered, *fOrdered;
	//Carregamento do arquivo nao ordenado
	
	if ((fUnordered = fopen("Arquivo.txt", "r")) == NULL) {
		printf("Erro ao abrir o arquivo.");
	} else {
		printf("Iniciando o carregamento do arquivo.\n");
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &p[q]);
			q++;
		}
		printf("\nIniciando ordenacao.");
		//Algoritmo de Ordena??o 
		counting_sort(p, SIZE);
		
		
		if ((fOrdered = fopen("arquivo_ordenado.txt", "w+")) == NULL) {
			printf("Erro ao abrir o arquivo.");
		} else {
			printf("\nIniciando a gravacao do arquivo ordenado.\n");
			for(q = 0; q < SIZE; q++) {
				fprintf(fOrdered, "%d\n", p[q]);
			}
		}
	}
	end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos\n", execution_time);
	
	fclose(fUnordered);
    fclose(fOrdered);
    system("pause");  
}

