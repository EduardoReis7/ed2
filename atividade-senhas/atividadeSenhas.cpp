#include <stdlib.h>
#include <stdio.h> 
#define SIZE 456976

void geraSenhaFor(FILE *arqSenha, char i, char j, char k, char l);
void geraSenhaRecursivo();

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
				//geraSenhaRecursivo(arqSenha, SIZE, i, j, k, l);
				break;
			default:
				printf("Opção inválida!\n");
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

/*void geraSenhaRecursivo(FILE *arqSenha, int tamanho, char *i, char *j, char *k, char *l) {
	if (tamanho == 0) {
		printf("Terminou!\n");
	}
	geraSenhaRecursivo(arqSenha, tamanho--, i, j, k, l)
}*/
