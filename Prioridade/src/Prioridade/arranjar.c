/*
 * arranjar.c
 *
 *  Created on: 29/07/2015
 *      Author: hugo
 */
#include <stdio.h>
#include "Prioridade.h"

void arranjar(Desc *d, int n) {	// algoritmo 6.6: Construção da lista de prioridades (por arranjo)
	int i = 0;

	printf("Construindo por arranjo...\n");
	for (i = piso((double)(n/2)); i >= SEGUNDO; i--) {
		descer(d->t, i, n);
	}
}
