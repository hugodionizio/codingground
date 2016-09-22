#include "../../estruturas/Prioridade/Prioridade.h"

void construirPrioridades(Desc *d, int n) { // algoritmo 6.5: Construção da lista de prioridades por inserção
	int i;

	printf("Construindo por inserção...\n");
	for (i = SEGUNDO; i <= n; i++) {
		subir(d->t, i);
	}
}
