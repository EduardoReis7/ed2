#include <stdio.h>
#include <stdlib.h>

main()
{
char caractere; 

FILE *txt;

if((txt = fopen("C:\\Users\\Eduardo Reis\\Documents\\ifrs\\ED2\\aula1\\arquivo_texto.txt","r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {
        while (!feof(txt)) {
               caractere = fgetc(txt);
			   printf("%c", caractere);
               
              }
          fclose(txt);
      }
system("pause"); 
}

