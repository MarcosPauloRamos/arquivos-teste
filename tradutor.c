#include <stdio.h>
#include <conio.h>

void main()
{
  FILE *arq;
  FILE *arq2;
  char Linha[100];
  char *result;
  int i;
  clrscr();

  arq2 = fopen("ArqGrav.txt", "wt");  // Cria um arquivo texto para gravação
  if (arq2 == NULL) // Se não conseguiu criar
  {
     printf("Problemas na CRIACAO do arquivo de escrita\n");
     return;
  }
  
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("ArqTeste.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo de leitura\n");
     return;
  }
  
  
  i = 0;
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
  // Escreve o arquivo de escrita
      fprintf(arq2,"ram[%d] = %s;\n",i,result);
      i++;
  }
  fclose(arq);
  fclose(arq2);
}
