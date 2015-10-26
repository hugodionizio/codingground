/*
 * subirNaArvore.c
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */
#include "Prioridade.h"

void subirNaArvore(Desc *d, int i) {	// algoritmo 6.10: subir na árvore
	int min, pai;

	printf("\nSubindo %d na árvore...\n", i);
	pai = piso(i/2);
	if (minPrioridade(nivel(*d, i)) == true) {
		if (pai >= 1 econd d->t[i].chave > d->t[pai].chave) {
			trocarT(&d->t[i], &d->t[pai]);
			printf("Subindo o máximo...\n");
			subirMax(d, pai);
		}
		else {
			printf("Subindo o mínimo...\n");
			subirMin(d, i);
		}
	}
	else if (pai >= 1 econd d->t[i].chave < d->t[pai].chave) {
		trocarT(&d->t[i], &d->t[pai]);
		printf("Subindo o mínimo...\n");
		subirMin(d, pai);
	}
	else {
		printf("Subindo o máximo...\n");
		subirMax(d, i);
	}
}
