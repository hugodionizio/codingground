#include "HashTablePHenrique2.h"

#include <stdio.h>
#include <stdlib.h>


void imprimirVetorHash2(Vetor vetor) {
	int i, *num;
	char *ch;
	void *p;
	for (i = 0; i < vetor.tamanho; ++i) {
		p = &vetor.v[i];
		if(sizeof(vetor.v[0]) == 8) {
			ch = (char *)p;
			printf("%c", *ch);
		}
		else {
			num = (int *)p;
			printf("%d", *num);
		}
	}
}

int hashPHenrique2 (int x, int m) {
	int h;

	h = x%m;

	return h;
}

int hashTL (int x, int m, int *t, int b, int valor) {
	int h, i = 0;

	while (i < m) {

		h = (x%m) + i;

		if (t[h] == 0) {
			t[h] = valor;
			// b = 1;
			// return b;
			return 1;
		}
	}

	return 0;
}

int mainHashTablePHenrique2(int argc, char **argv) {
	int num[3] = {2, 3, 4};

	return (0);
}
