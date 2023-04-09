#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void mergeSort(int vec[], int vecSize) ;

void merge(int vec[], int vecSize);

main () {
//Inicializaçã do Vetor
	clock_t start, end;
	start = clock();
	double execution_time;
	FILE *fUnordered, *fOrdered;
	int *p = (int *) malloc(SIZE * sizeof(int));
	int i, j = 0,  aux, q = 0;
	
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
		mergeSort(p,SIZE);	
		
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
} 


void mergeSort(int vec[], int vecSize) {
  int mid;
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
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

