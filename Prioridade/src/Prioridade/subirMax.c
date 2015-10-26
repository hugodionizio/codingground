/*
 * subirMax.c
 *
 *  Created on: 01/08/2015
 *      Author: hugo
 */
#include "Prioridade.h"

void subirMax(Desc *d, int i) {	// algoritmo 6.11: subir a partir de um nível mínimo
	int avo = nivel(*d, i) - 2;

	if (temAvo(*d, i) == true) {
		if (d->t[i].chave > d->t[avo].chave) {
			trocarT(&d->t[i], &d->t[avo]);
			subirMax(d, i);
		}
	}
}
