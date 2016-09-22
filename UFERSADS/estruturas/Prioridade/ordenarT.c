/*
 * ordenarT.c
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */
#include "../../estruturas/Prioridade/Prioridade.h"

ordenarT(Desc *d, int n) {	// algoritmo 6.7: Ordenação de T
	int m;

	printf("\nOrdenando T...\n");
	arranjar(d, n);
	m = n;
	while (m > 1) {
		trocarT(&d->t[PRIMEIRO], &d->t[m-1]);
		m = m - 1;
		descer(d->t, 1, m);
	}
}
