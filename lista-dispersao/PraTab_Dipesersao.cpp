#include <stdio.h>
#include <time.h>
#include <unistd.h> 
#include <stdlib.h>

#define N 200

struct aluno {
	int mat;
	char nome[81];

};
typedef struct aluno Aluno;

typedef Aluno* Hash[N];

Hash  dados; 
int mat= 0; 
char nome[80];


int hash (int mat)
{
	return (mat%200);
}

int hash2 (int mat) {
	return N - 2 - mat%(N-2);
}

Aluno* busca (Hash tab, int mat) {
	int cont = 0;
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) {
			cont++;
			printf("\nQuantidade de acessos: %d", cont);
			return tab[h];
		}
		h = (h+h2) % N;
	}
	return NULL;
}

Aluno* insere (Hash tab, int mat, char* nome)
{
	int h = hash(mat);
	int h2 = hash2(mat);
	while (tab[h] != NULL) {
		if (tab[h]->mat == mat) //Se matricula Igual, atualiza os dados
			break;
		h = (h+h2) % N;
	}
		if (tab[h]==NULL) { /* nao encontrou o elemento */
		tab[h] = (Aluno*) malloc(sizeof(Aluno));
		tab[h]->mat = mat;
	}
	/* atribui propriedade */
	strcpy(tab[h]->nome,nome);
	return tab[h];
}


void carregaarquivo()
{
FILE *txt;

if((txt = fopen("dados.txt","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else{
 	while (!feof(txt)) 
	 {
   		fscanf(txt, "%d %s ", &mat, nome);
		insere(dados, mat, nome);  
 }
 fclose(txt);
}


}

main(){

//Inicializando
for(int i = 0; i < N; i++)
  dados[i] = NULL;

char opcao = 's'; 
int localizar; 
 
carregaarquivo();

while (opcao =='s')
{

	printf("\nQual registro Deseja Buscar?");
	scanf("%d",&localizar);

	if (busca(dados, localizar)) {
		printf("\nLocalizado");
	}
	else
		printf("Não Localizado");
		

	fflush(stdin);

	printf("\nDeseja Localizar outro? [s/n]:");
	scanf("%c",&opcao);
}

 for(int i = 0; i < N; i++)
 {
   	if (dados[i]!= NULL) 
   	{
	 	    printf("\n------------------------");
			printf("\nIndice: %d", i);
			printf("\nMat...: %d", dados[i]->mat);
			printf("\nNome..: %s", dados[i]->nome);
	}

}
}
	 
 
