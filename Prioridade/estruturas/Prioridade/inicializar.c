/*
 * inicializar.c
 *
 *  Created on: 24/07/2015
 *      Author: hugo
 */
#include "../../estruturas/Prioridade/Prioridade.h"

void inicializar(Desc *d, int memoria, int celulas, T *t) {
	d->memoria = memoria;
	d->celulas = celulas;
	d->t = t;
}

