/*
 * embaralharPrioridade.c
 *
 *  Created on: 24/07/2015
 *      Author: hugo
 */
#include <stdlib.h>

#include "../../estruturas/Prioridade/Prioridade.h"

void embaralharPrioridade(Desc *d) {
	int max = d->celulas;
	int *v = malloc(max*sizeof(int));
	T *aux = malloc(max*sizeof(T));
	int i;

	for (i = 0; i < max; ++i) {
		v[i] = i;
	}
	if (max > 1) {
		embaralhar(v, max);
		printf("Vetor embaralhado\n");
	}
	else printf("\nSem prioridades");

	for (i = 0; i < max; ++i) {
		printf("aux[%d] = ", i);
		aux[i] = d->t[v[i]];
		printf("(%d, %c); ", aux[i].chave, aux[i].processo);
	}

	for (i = 0; i < max; ++i) {
		d->t[i] = aux[i];
	}

//	free(v);
//	free(aux);
}

