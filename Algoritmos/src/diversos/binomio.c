#include <stdio.h>

int main() {
  int colunas,j;
  int anterior;

  int linha;
  do {
	scanf("%d",&linha);
  } while (linha < 0);

  colunas = linha+1;
  anterior = 1;
  printf("%d ",anterior);

  for(j=1;j<colunas;j++) {
	 anterior = anterior*(linha-j+1)/j;
	 printf("%d ", anterior);
  }
  puts("");
}
