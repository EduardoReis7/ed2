#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidade.h"



Tcidade grafo[MAX_VERTICES][MAX_VERTICES];
 
int precede[MAX_VERTICES];
tFila fila;
int origem, destino;
 
int main(void) 
{
 
 
 Inicializa_Grafo(grafo);
  
 Cria_Aresta(grafo, 0, 1, 1100);
 Cria_Aresta(grafo, 0, 2, 1700);
 Cria_Aresta(grafo, 1, 4, 2300);
 Cria_Aresta(grafo, 1, 5, 1500);
 Cria_Aresta(grafo, 2, 0, 1700);
 Cria_Aresta(grafo, 2, 6, 2700);
 Cria_Aresta(grafo, 2, 3, 300);
 Cria_Aresta(grafo, 3, 2, 300);
 Cria_Aresta(grafo, 3, 4, 800);
 Cria_Aresta(grafo, 4, 1, 2300);
 Cria_Aresta(grafo, 4, 3, 800);
 Cria_Aresta(grafo, 4, 6, 650);
 Cria_Aresta(grafo, 5, 1, 1500);
 Cria_Aresta(grafo, 5, 6, 1900);
 Cria_Aresta(grafo, 6, 5, 1900);
 Cria_Aresta(grafo, 6, 4, 650);
 Cria_Aresta(grafo, 6, 2, 2700);
 
    system("cls");

	Imprime_Matriz(grafo);
 	
//	printf("\nLista de Adjacencias \n"); 
	criaListaAdjacencias(grafo);
//	 	 
//	Imprime_Menu();
//	
//	Le_Origem_Destino(MAX_VERTICES-1,&origem, &destino);
	
//	printf (" Aqui Implementar Distancia entre %s e %s ", cidades[origem], cidades[destino]);
	buscaAmplitude(grafo, &fila, 0, 2);
	
	return(0);

}

