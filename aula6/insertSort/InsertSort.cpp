#include <stdio.h>
#include <stdlib.h>

main ()  {
    //Inicializaçã do Vetor
    int v[5]= {1,7,4,3,5},  n=5;
    int i, j, chave;
   
   int c = 0; 
   
    //Algoritmo de Ordenação 
	for(j=1; j<n; j++) 
	{
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave) {
			v[i+1] = v[i];
			i--;
			}		
			v[i+1] = chave;
			}
	
    //Laço de impressão do Vetor
	for (int q=0; q<5; q++)	{
        		printf("%d \n",v[q]);
    	}
}

