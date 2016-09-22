#include <stdio.h>

#include "../../estruturas/Prioridade/Prioridade.h"

void subir(T *t, int i) { // algoritmo 6.1: Subir por um caminho da árvore
	int j = piso((float)(i/2));

	printf("Subindo %d = piso(%d/2)...\n", j, i);
	if (j >= 1) {
		printf("j = %d\n", j);
		printf("t[i] = %d, t[j] = %d\n", t[i-1].chave, t[j-1].chave);
		if (t[i-1].chave > t[j-1].chave) {
			trocarT(&t[i-1], &t[j-1]);
			subir(t, j);
		}
	}
}
