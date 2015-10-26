#include <stdio.h>
#include "Prioridade.h"

void descer(T *t, int i, int n) { // algoritmo 6.2: Descer por um caminho da árvore
	int j = 2*i;
	if (j <= n) {
		printf("Descendo %d...\n", i);
		if (j < n) {
			if (t[j + 1 - 1].chave > t[j - 1].chave) {
				j = j + 1;
			}
		}
		if (t[i - 1].chave < t[j - 1].chave) {
			trocarT(&t[i-1], &t[j-1]);
			descer(t, j, n);
		}
	}
}
