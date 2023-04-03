#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

#define SIZE 10000

int main() {
	//Inicializa?? do Vetor
	int n=5, *p;
	int i, j = 0,  aux, q = 0;
	FILE *fUnordered, *fOrdered;
	
	//Leitura do arquivo
	if (((fUnordered = fopen("Arquivo.txt", "r")) == NULL) && (fOrdered = fopen("arquivo_ordenado.txt", "w"))){
		printf("Erro ao abrir o arquivo.");
	} else {
		p = (int *) malloc(SIZE * sizeof(int));
		if (!p) {
			printf("Erro: Memória insuficiente!");
		} else {
			//Carregamento do vetor com os numeros do arquivo
			while(!feof(fUnordered)) {
				fscanf(fUnordered, "%d", &p[q]);
				q++;
				printf("Valor: %d\n", *(p++));
			}
		}
		
	}
 	
 
////Algoritmo de Ordena??o 
//	while (j < n) {
//		for(i = 0; i < n-1; i++) {
//			if(v[i] > v[i + 1]) {
//     			aux=v[i];
//     			v[i] = v[i+1];
//     			v[i+1] = aux;
//			}
//		}
//		j++;
//	}
////La?o de impress?o do Vetor
//	for (int q=0; q<5; q++) {
//        printf("%d \n",v[q]);
//    }
//    
//    fclose(fUnordered);
//    fclose(fOrdered);
//    system("pause");  
}
