/*
 * embaralhar.c
 *
 *  Created on: 11/07/2015
 *      Author: hugo
 */

#define bool int

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _Baralho {
	void *p;
};
typedef struct _Baralho Baralho;

int embaralhar(int *v, int tam)
{
	int * u = (int *)malloc(sizeof(int)*tam);
	int i, j, k;
	bool * aux = (bool *)malloc(sizeof(bool)*tam);

	printf("embaralhando...\n");
	srand(time(NULL));
	for (k = 0; k < 5; ++k) {
		for(i = 0; i < tam; i++) {
			aux[i] = rand()%2;
			printf("%d ", aux[i]);
		}
		putchar(13);

		j = 0;
		for (i = 0; i < tam; i++) {
			if (aux[i]) {
				u[j] = v[i];
				j++;
			}
		}

		for (i = 0; i < tam; i++) {
			if (!aux[i]) {
				u[j] = v[i];
				j++;
			}
		}
	}

	for(i = 0; i < tam; i++) v[i] = u[i];

	return 0;
}

int embaralhar10(int *v) {
	int i;

	for(i = 0; i < 10; i++) v[i] = i;

	return embaralhar(v, 10);
}

int embaralharReg() {
	return (0);
}
