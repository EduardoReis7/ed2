#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void bubbleSort(int p[]);
void counting_sort(int *array, int size);
void insertSort(int vec[]);
double mergeSort(int vec[], int vecSize);
void merge(int vec[], int vecSize);

main() {
	FILE *fUnordered, *fOrdBubble, *fOrdCount, *fOrdInsert, *fOrdMerge;
	int *pBubble = (int *) malloc(SIZE * sizeof(int));
	int *pCount = (int *) malloc(SIZE * sizeof(int));
	int *pInsert = (int *) malloc(SIZE * sizeof(int));
	int *pMerge = (int *) malloc(SIZE * sizeof(int));
	int opt, q = 0;
	double executionTime;
	char continuar;
	
	if ((fUnordered = fopen("Arquivo.txt", "r")) == NULL){
		printf("Erro ao abrir o arquivo.");
	} else {
		printf("\nCarregando o vetor com os numeros do arquivo\n");
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &pBubble[q]);
			q++;
		}
		rewind(fUnordered);
		q=0;
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &pCount[q]);
			q++;
		}
		rewind(fUnordered);
		q=0;
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &pInsert[q]);
			q++;
		}
		rewind(fUnordered);
		q=0;
		while(!feof(fUnordered)) {
			fscanf(fUnordered, "%d", &pMerge[q]);
			q++;
		}
		do {
			printf("-- ALGORITMOS DE ORDENACAO --\n");
			printf("[1] BubbleSort\n");
			printf("[2] CountSort\n");
			printf("[3] InsertSort\n");
			printf("[4] MergeSort\n");
			
			printf("Qual algoritmo de ordenacao deseja utilizar? ");
			scanf("%d", &opt);
			getchar();
			switch(opt) {
				case 1:
					bubbleSort(pBubble);
					if ((fOrdBubble = fopen("arquivo_ordenado_bubble.txt", "w+")) == NULL) {
						printf("Erro ao abrir o arquivo.");
					} else {
						printf("\nIniciando a gravacao do arquivo ordenado.\n");
						for(q = 0; q < SIZE; q++) {
							fprintf(fOrdBubble, "%d\n", pBubble[q]);
						}
					}
					break;
				case 2:
					counting_sort(pCount, SIZE);
					if ((fOrdCount = fopen("arquivo_ordenado_count.txt", "w+")) == NULL) {
						printf("Erro ao abrir o arquivo.");
					} else {
						printf("\nIniciando a gravacao do arquivo ordenado.\n");
						for(q = 0; q < SIZE; q++) {
							fprintf(fOrdCount, "%d\n", pCount[q]);
						}
					}
					break;
				case 3:
					insertSort(pInsert);
					if ((fOrdInsert = fopen("arquivo_ordenado_insert.txt", "w+")) == NULL) {
						printf("Erro ao abrir o arquivo.");
					} else {
						printf("\nIniciando a gravacao do arquivo ordenado.\n");
						for(q = 0; q < SIZE; q++) {
							fprintf(fOrdInsert, "%d\n", pInsert[q]);
						}
					}
					break;
				case 4:
					executionTime = mergeSort(pMerge, SIZE);
					printf("\nTempo de execucao: %f segundos\n", executionTime);
					if ((fOrdMerge = fopen("arquivo_ordenado_merge.txt", "w+")) == NULL) {
						printf("Erro ao abrir o arquivo.");
					} else {
						printf("\nIniciando a gravacao do arquivo ordenado.\n");
						for(q = 0; q < SIZE; q++) {
							fprintf(fOrdMerge, "%d\n", pBubble[q]);
						}
					}
					break;
			}
			
			printf("Deseja continuar ordenando? [S/N]");
			scanf("%c", &continuar);
			getchar();
		} while(continuar == 'S');
	}
}

void bubbleSort(int p[]) {
	clock_t start, end;
	start = clock();
	double execution_time;
	int i, j, aux;
	
	printf("\nIniciando Bubble Sorting!\n");
	while (j < SIZE) {
    	for(i = 0; i < SIZE-1; i++) {
        	if(p[i] > p[i + 1]) {
				aux=p[i];
				p[i] = p[i+1];
				p[i+1] = aux;
        	}
      	}
      	j++;
    }
    end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos\n", execution_time);
}

void counting_sort(int *array, int size) {
	clock_t start, end;
	start = clock();
	double execution_time;
	int i, min, max;
	int j=0; 
	float interacoes = 0;
	
	printf("\nIniciando Count Sorting!\n");
	
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
	free(count);
	end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos\n", execution_time);
}

void insertSort(int p[]) {
	clock_t start, end;
	start = clock();
	double execution_time;
	int i, j, chave;
	
	printf("\nIniciando Insert Sorting!\n");
	for(j=1; j<SIZE; j++) {
		chave = p[j];
		i = j-1;
		while(i >= 0 && p[i] > chave) {
			p[i+1] = p[i];
			i--;
		}		
		p[i+1] = chave;
	}
	end = clock();
	execution_time = ((double) end-start)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao: %f segundos\n", execution_time);
}


double mergeSort(int vec[], int vecSize) {
	clock_t start, end;
	start = clock();
	double execution_time;
	
	int mid;
	if (vecSize > 1) {
		mid = vecSize / 2;
		mergeSort(vec, mid);
		mergeSort(vec + mid, vecSize - mid);
		merge(vec, vecSize);
	}
	end = clock();
	return execution_time = ((double) end-start)/CLOCKS_PER_SEC;
}



//Kernell do Algoritmo
void merge(int vec[], int vecSize) {
  int mid;
  int i, j, k;
  int* tmp;
  tmp = (int*) malloc(vecSize * sizeof(int));
  if (tmp == NULL) {
    exit(1);  }
  mid = vecSize / 2;
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i] < vec[j]) {
      tmp[k] = vec[i];
      ++i;    
	} else {
      tmp[k] = vec[j];
      ++j;    
	}
    ++k; 
  }
  if (i == mid) {
    while (j < vecSize) {
      tmp[k] = vec[j];
      ++j;
      ++k;   
	} 
  } else {
    while (i < mid) {
      tmp[k] = vec[i];
      ++i;
      ++k;   
	}  
  }
  for (i = 0; i < vecSize; ++i) {
  	vec[i] = tmp[i];  
  }
  free(tmp);
}
