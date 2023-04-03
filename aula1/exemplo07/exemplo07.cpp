#include <stdio.h>
#include <string.h>

typedef struct Cpessoa
{
	char nome[20];
	int idade;
};

int main(void)
{
	char condicao = 's';
	Cpessoa aluno[200];
	FILE *bin;
	int  tamanho = 0; 
	
	if((bin = fopen("C:\\Users\\Eduardo Reis\\Documents\\ifrs\\ED2\\aula1\\exemplo06\\arquivo_binario.txt","rb")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 	else
	{
		//Lendo o Arquivo
		while (!feof(bin))
		{
			fread(&aluno[tamanho] ,1, sizeof(Cpessoa), bin);
			tamanho++;
		}	


		//Mostrando na tela
		for (int i = 0; i<tamanho-1 ; i++)
		{
			printf("%s \t %d \n", aluno[i].nome, aluno[i].idade);
		}
		getchar();
	}

}

