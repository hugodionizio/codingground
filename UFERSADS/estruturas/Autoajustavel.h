#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 10

struct Celula {
	int info;

	struct Celula *prox;
};
typedef struct Celula Celula;

void MF(int, Celula *); // Mover para frente
void MF_k(int, Celula *, int); // Mover para k posições para frente

void testAutoajustavel () {
	Celula *cel, *aux;
	int count, vetor[LIMITE];
		
	srand(time(NULL));
	printf("Demonstração de Estruturas autoajustáveis\n");
	cel = (Celula *)malloc(sizeof(Celula));
	vetor[0] = random()%100;
	cel->info = vetor[0];

	aux = cel;
	for (count = 1; count < 10; count++) {
		vetor[count] = random()%100;
		aux->prox = (Celula *)malloc(sizeof(Celula));
		aux->prox->info = vetor[count];
		aux = aux->prox;		
	}

	aux = cel;
	for (count = 0; count < 10; count++) {
		printf("Célula %d = %d\n", count+1, aux->info);
		aux = aux->prox;
	}

	count = 4;

	printf("\nMovendo célula %d (valor = %d) para frente da Lista...\n", count+1, vetor[count]);
	MF(vetor[count], cel);

	aux = cel;
	for (count = 0; count < 10; count++) {
		printf("Célula %d = %d\n", count+1, aux->info);
		aux = aux->prox;
	}
}

// Mover para frente
void MF(int x, Celula *cel) {
	Celula *aux, *auxP, *auxU, auxF;
	int info;

	aux = cel;
	while (x != aux->info && aux->prox != NULL) {
		auxP = aux;
		aux = aux->prox;
		auxU = aux->prox;
	}
	if (x != cel->info && cel->prox != NULL) {
		auxP->prox = auxU;
		aux->prox = cel->prox;
		cel->prox = aux;
		info = cel->info;
		cel->info = aux->info;
		aux->info = info;
	}
}

// Mover para k posições para frente
void MF_k(int x, Celula *cel, int k) {
	Celula *aux, *posK, *auxP, *auxU, auxF;
	int count, info;

	aux = cel;
	while (x != aux->info && aux->prox != NULL) {
		auxP = aux;
		aux = aux->prox;
		auxU = aux->prox;
	}
	if (x != cel->info && cel->prox != NULL) {
		auxP->prox = auxU;
		aux->prox = cel->prox;
		cel->prox = aux;
		info = cel->info;
		cel->info = aux->info;
		aux->info = info;
	}
}

// Transposição (com o precedente)
void TR(int x, Celula *cel, int k) {
	Celula *aux, *posK, *auxP, *auxU, auxF;
	int count, info;

	aux = cel;
	while (x != aux->info && aux->prox != NULL) {
		auxP = aux;
		aux = aux->prox;
		auxU = aux->prox;
	}
	if (x != cel->info && cel->prox != NULL) {
		auxP->prox = auxU;
		aux->prox = cel->prox;
		cel->prox = aux;
		info = cel->info;
		cel->info = aux->info;
		aux->info = info;
	}
}

// Contador de Frequência
void CF(int x, Celula *cel, int k) {
	Celula *aux, *posK, *auxP, *auxU, auxF;
	int count, info;

	aux = cel;
	while (x != aux->info && aux->prox != NULL) {
		auxP = aux;
		aux = aux->prox;
		auxU = aux->prox;
	}
	if (x != cel->info && cel->prox != NULL) {
		auxP->prox = auxU;
		aux->prox = cel->prox;
		cel->prox = aux;
		info = cel->info;
		cel->info = aux->info;
		aux->info = info;
	}
}
