#include <stdlib.h>
#include <stdio.h> 
#define SIZE 456976

void geraSenhaFor(FILE *arqSenha, char i, char j, char k, char l);
void geraSenhaRecursivo(FILE *arqSenha, int tamanho, char *i, char *j, char *k, char *l);

int main() {
	
	FILE * arqSenha;
	char i, j, k, l;
	int m, opt;
	
	if ((arqSenha = fopen("Arquivo.txt", "w+")) == NULL){
		printf("Erro ao abrir arquivo.");
	} else {
		printf("============================\n");
		printf("==  GERADOR DE SENHAS     ==\n");
		printf("============================\n");
		printf("Escolha a forma de gerar a senha:\n");
		printf("[1] Gerar senha com for\n");
		printf("[2] Gerar senha recursivamente\n");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				geraSenhaFor(arqSenha, i, j, k, l);
				break;
			case 2:
				i = 65;
				j = 65;
				k = 65;
				l = 65;
				geraSenhaRecursivo(arqSenha, 3, &i, &j, &k, &l);
				break;
			default:
				printf("Opcao invalida!\n");
		}
		printf("\nArquivo gerado com sucesso, verifique seu diretorio!");
		fclose(arqSenha);
	}
}

void geraSenhaFor(FILE *arqSenha, char i, char j, char k, char l) {
	int m = 0;
	while (m < SIZE) {
		for (i = 65; i <= 90; i++) {
			for (j = 65; j <= 90; j++) {
				for (k = 65; k <= 90; k++) {
					for (l = 65; l <= 90; l++) {
						fprintf(arqSenha, "%c%c%c%c\n", i, j, k, l);
						m++;
					}
				}
			}
		}
	}
}

void geraSenhaRecursivo(FILE *arqSenha, int index, char *i, char *j, char *k, char *l) {
	if (index == 3) {
		if ((*l) <= 90) {
			fprintf(arqSenha, "%c%c%c%c\n", *i, *j, *k, *l);
			(*l)++;
			geraSenhaRecursivo(arqSenha, 3, i, j, k, l);
		} else {
			geraSenhaRecursivo(arqSenha, 2, i, j, k, l);
		}
	}
	(*l) = 65;
	if (index == 2) {
		if (*k < 90) {
	 		fprintf(arqSenha, "%c%c%c%c\n", *i, *j, *k, *l);
	 		(*k)++;
	 		geraSenhaRecursivo(arqSenha, 3, i, j, k, l);
	 	}
		else {
	 		geraSenhaRecursivo(arqSenha, 1, i, j, k, l);
	 	}
	}
	(*k) = 65;
	if (index == 1) {
		if (*j < 90) {
			fprintf(arqSenha, "%c%c%c%c\n", *i, *j, *k, *l);
			(*j)++;
			geraSenhaRecursivo(arqSenha, 2, i, j, k, l);
		} else {
			geraSenhaRecursivo(arqSenha, 0, i, j, k, l);
		}
	}
	(*j) = 65;
	if (index == 0) {
		if (*i < 90) {
			fprintf(arqSenha, "%c%c%c%c\n", *i, *j, *k, *l);
			(*i)++;
			geraSenhaRecursivo(arqSenha, 3, i, j, k, l);
		} else {
			printf("Acabou.");
		}
	}
}
