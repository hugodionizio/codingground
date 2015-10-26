#include "Prioridade.h"

bool overflow() {
	return false;
}

bool inserirPrioridade(Desc *d, T novo) {	// algoritmo 6.3
	bool sucesso = false,
		M = d->memoria,
		n = d->celulas;

	if (n < M) {
		printf("Inserindo...\n");
		d->t[n + 1] = novo;
		n = n + 1;
		subir(d->t, n);
		sucesso = true;
	}
	else sucesso = overflow();
	d->celulas = n;

	return sucesso;
}
