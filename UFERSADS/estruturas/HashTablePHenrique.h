#include <stdio.h>
#include <stdlib.h>

struct Vetor {
	void *v;
	unsigned tamanho;
};
typedef struct Vetor Vetor;
typedef Vetor * PtVetor;

void imprimir(Vetor vetor) {
	
	printf("%");
}

int main () {
	int num[3] = {2, 3, 4};

	return (0);
}

int hash (int x, int m) {
	int h;

	h = x%m;

	return h;
}

int hashTL (int x, int m, int *t, int b, int v) {
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
