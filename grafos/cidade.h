#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 7

#define LIMITE 32767

#define TRUE  !0
#define FALSE  0
 
char cidades[MAX_VERTICES][30] = {
 						"[0] - (PoA) - Porto Alegre", 
 				      	"[1] - (Spa) - Sao Paulo", 
 				      	"[2] - (Rio) - Rio de janeiro", 
				      	"[3] - (Vit) - Vitoria", 
				      	"[4] - (Rec) - Recife", 
				      	"[5] - (Sal) - Salvador", 
				     	"[6] - (Nat) - Natal"
						 };

typedef struct {
	          char cidade_adj;
	          int cidade_dist;
	         } Tcidade;

typedef struct {
	char cidadePrincipal;
	char cidadesAdj[MAX_VERTICES];
} tListaAdj;
	         
typedef struct {
    int dado;
    struct tipoNo *prox;
    struct tipoNo *ant;
} tipoNo;

typedef struct {
    tipoNo *first;
    tipoNo *last;
    int size;
} tFila;
	        
char rotulos[MAX_VERTICES][6] = {"PoA", "SPa", "Rio", "Vit", "Rec", "Sal", "Nat"};

// FILA

void criarFila(tFila *f) {
    f->first = NULL;
    f->last = NULL;
    f->size = 0;
}

int vazia(tFila *f) {
    if (f->first==NULL) {
        return 1;
    } else {
        return 0;
    }
}

int inserirFila(tFila *f, int d) {
    tipoNo *novo;
    novo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novo != NULL) {
        novo->prox = NULL;
        if (vazia(f) == 1) {
            f->first = novo;
        } else {
            f->last->prox = novo;
        }
        novo->dado = d;
        novo->ant = f->last;
        f->last = novo;
        f->size++;
        
        return 1;
    } else {
        printf("\nDeu ruim!");
        return 0;
    }
}

int removerFila(tFila *f, int *d) {
    if (vazia != 1) {
        *d = f->first->dado;
        
        if (f->first == f->last) {
            f->first = NULL;
            f->last = NULL;
        } else {
            tipoNo *noAux = f->first;
            
            f->first = f->first->prox;
            f->first->ant = NULL;
            f->size--;
            free(noAux);
        }
        return 1;
    } else {
        printf("\nNao e possivel remover elementos, pois a fila esta vazia!");
        return 0;
    }
}

// GRAFO

void Inicializa_Grafo(Tcidade grafo[][MAX_VERTICES])
{
 int l, c;

 for (l = 0; l < MAX_VERTICES; l++) 
      for (c = 0; c < MAX_VERTICES; c++) 
          {
	grafo[l][c].cidade_dist = -1;
	grafo[l][c].cidade_adj = 'N';
    }
}

void Cria_Aresta(Tcidade grafo[][MAX_VERTICES], int cid_origem, int cid_destino, int distancia)
{
 grafo[cid_origem][cid_destino].cidade_adj = 'S';
 grafo[cid_origem][cid_destino].cidade_dist = distancia;
}

void Imprime_Matriz(Tcidade grafo[][MAX_VERTICES])
{
 int l, c;

 printf("\n-- Matriz de Adjacencias  --\n");
 printf("\t [c0] \t [c1] \t [c2] \t [c3] \t [c4] \t [c5] \t [c6]\n");
 
 for (l = 0; l < MAX_VERTICES; l++) 
     {
      printf("[L%d]", l);
      for (c = 0; c < MAX_VERTICES; c++) 
       printf("\t%5d ",grafo[l][c].cidade_dist);
      printf("\n");
      }
	printf("\n\n");
}

void criaListaAdjacencias(Tcidade grafo[][MAX_VERTICES]) {
	int l, c, i;
	tListaAdj *adj;
	adj = (tListaAdj*) malloc(sizeof(tListaAdj));
	if (adj) {
		for (l = 0; l < MAX_VERTICES; l++) {
			printf("\nAdjacente[%s]: ", rotulos[l]);
			adj->cidadePrincipal = rotulos[l];
			for (c = 0; c < MAX_VERTICES; c++) {
				if (grafo[l][c].cidade_adj == 'S') {
					adj->cidadesAdj[c] = rotulos[c];
					printf("%s ", rotulos[c]);
				} 
			}
			printf("\n");
		}
	}
	
}

void Le_Origem_Destino(int tam, int *origem, int *destino)
{
 printf("\n Cidade de Origem  [0..%d]: ", tam);
 do {
      scanf("%d",origem);
     } while (*origem < 0 || *origem > tam);
 printf(" Cidade de Destino [0..%d]: ", tam);
 do {
      scanf("%d",destino);
     } while (*destino < 0 || *destino > tam);
}

void buscaAmplitude(Tcidade grafo[][MAX_VERTICES], tFila* fila, int origem, int destino) {
	
	int i, visitados[MAX_VERTICES], removido;
	
	for (i = 0; i < MAX_VERTICES; i++) {
		visitados[i] = 0;
	}
	
	visitados[0] = origem;
	criarFila(fila);
	inserirFila(fila, origem);
	while(!vazia(fila)) {
		removerFila(fila, &removido);
		for (i = removido; i < MAX_VERTICES; i++) {
			if (visitados[i] != i) {
				visitados[i] = i;
				inserirFila(fila, i);
			}
		}
	}
	
	
}


//Imprime_Menu
void Imprime_Menu(void)
{
 int i;

 printf("\n -- Menu Opcoes de Cidades --\n");  

 for (i = 0;i < MAX_VERTICES;i++)
     printf(" %s\n",cidades[i]);
  
}

