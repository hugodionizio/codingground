#include <stdio.h>

#include "../../estruturas/Prioridade/Prioridade.h"

void agir(T *t) {
	printf("Removendo...\n");
}

bool underflow() {
	return false;
}

int removerPrioridade(Desc *d) {	// algoritmo 6.4: Remoção de um elemento da lista de prioridades
	int sucesso = false,
		n = d->celulas;

	if (n != 0) {
		agir(&d->t[PRIMEIRO]);
		d->t[PRIMEIRO] = d->t[n];
		n = n - 1;
		descer(d->t, 1, n);
		sucesso = true;
	}
	else sucesso = underflow();
	d->celulas = n;

	return sucesso;
}
