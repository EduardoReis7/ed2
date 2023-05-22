#include <stdlib.h>
#include <stdio.h> 

int main() {
	
	FILE * arqSenha;
	char i, j, k, l;
	
	if ((arqSenha = fopen("Arquivo.txt", "w+")) == NULL){
		printf("Erro ao abrir arquivo.");
	} else {
	
		i = 65;
		
		while (i <= 90) {
			j = 65;
			k = 65;
			l = 65;
			fprintf(arqSenha, "\n%c %c %c %c", i, j, k, l);
			while (j <= 90) {
				k = 65;
				l = 65;
				fprintf(arqSenha, "\n%c %c %c %c", i, j, k, l);
				while (k <= 90) {
					l = 65;
					fprintf(arqSenha, "\n%c %c %c %c", i, j, k, l);
					while (l <= 90) {
						fprintf(arqSenha, "\n%c %c %c %c", i, j, k, l);
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
		}
		fclose(arqSenha);
	}
	
}
