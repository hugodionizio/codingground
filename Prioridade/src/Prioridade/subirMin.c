/*
 * subirMin.c
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */
#include <stdio.h>
#include "Prioridade.h"

bool temAvo(Desc d, int i) {
	bool result = false;

	if (nivel(d,i) > 2)
		result = true;

	return result;
}

void subirMin(Desc *d, int i) {	// algoritmo 6.11: subir a partir de um nível mínimo
	int avo = nivel(*d, i) - 2;

	if (temAvo(*d, i) == true) {
		if (d->t[i].chave < d->t[avo].chave) {
			trocarT(&d->t[i], &d->t[avo]);
			subirMin(d, i);
		}
	}
}
