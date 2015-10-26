#include <stdio.h>
#include "Prioridade.h"

void imprimirPrioridade(Desc d) {
	int i;

	printf("mem. = %d\tcél. = %d\n", d.memoria, d.celulas);
	for (i = 0; i < d.celulas; i++)
		if (i + 1 < d.celulas)
			printf("t%d = %d, %c\t", i, d.t[i].chave, d.t[i].processo);
		else
			printf("t%d = %d, %c\n", i, d.t[i].chave, d.t[i].processo);
}
