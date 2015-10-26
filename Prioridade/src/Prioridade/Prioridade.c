/*
 * Prioridade.c
 *
 *  Created on: 01/08/2015
 *      Author: hugo
 */
#include <stdio.h>
#include "Prioridade.h"

void trocarT(T *i, T *j) {
	T temp = *i;

	printf("\nTrocando (%d, %c) por (%d, %c)...\n",
			i->chave, i->processo, j->chave, j->processo);
//	printf("i = %d\tj = %d\ttemp = %d\n", *i, *j, temp);

	*i = *j;
	*j = temp;

//	printf("i = %d\tj = %d\ttemp = %d\n", *i, *j, temp);
}
