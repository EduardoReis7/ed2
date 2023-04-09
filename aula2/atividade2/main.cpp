#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[30];
	char sobrenome[20];
	int idade;
	char cpf[11];
} Cpessoa;

void inserir(Cpessoa* pessoa, FILE *bin) {
	char condicao;
	
	do {
		printf("Informe o nome:"); 
		scanf("%s", pessoa->nome);
	
		printf("Informe o sobrenome: ");
		scanf("%s", pessoa->sobrenome);
	
		printf("Informe a idade:"); 
		scanf("%d", &pessoa->idade);
		
		printf("Informe o CPF: ");
		scanf("%s", pessoa->cpf);
		
		fwrite(pessoa, 1, sizeof(Cpessoa), bin);
		
		printf("Deseja inserir uma nova pessoa? ");
		fflush(stdin);
		condicao = getchar();
		
	} while(condicao == 'S');
	
}

void listar(Cpessoa* pessoas, FILE* bin) {
	int i = 0;
	
	rewind(bin);
				
	pessoas = (Cpessoa*) malloc(sizeof(Cpessoa));
	
	while (fread(&pessoas[i] ,1, sizeof(Cpessoa), bin) != 0) {
		printf("-> %-30s \t %-30s \t %d \t %-11s\n", pessoa->nome, pessoa->sobrenome, pessoa->idade, pessoa->cpf);
	}
	
	fflush(stdin);
	getchar();	
}

int main(void) {
	int condicao = 0;
	Cpessoa pessoas;
	FILE *bin;

	//Abre o Arquivo Binário	
	if ((bin = fopen("DADOS.bin","ab+")) == NULL) {
        printf("Erro ao abrir arquivo.");
    } else {
	
		//menu Principal
		while (true) {
			system("cls");
			printf("[1] - Inserir\n"); 
			printf("[2] - Listar\n"); 
			printf("[3] - Sair\n"); 
		
			printf ("Digite a opcao: ");
  			scanf("%d", &condicao);
	
			switch  (condicao) {
			case 1:
				inserir(&pessoas, bin);
				break;
				
			case 2 :
				listar(&pessoas, bin)
				break;
			case 3:
				return(0);
			default:
				printf("Opcao desconhecida. Tente novamente!"); 
				fflush(stdin);
				getchar();
			}
			
		}
	}
	fclose(bin);
}
	

