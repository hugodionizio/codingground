#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/ArvoreTemp.h"

struct CelulaTmp {
	int num;

	struct CelulaTmp *left;
	struct CelulaTmp *right;
};
typedef struct CelulaTmp CelulaTmp;
typedef CelulaTmp * PtCelulaTmp;

struct Ponte {

	CelulaTmp *CelulaTmp;
	struct Tipo *next;
};
typedef struct Ponte Ponte;
typedef Ponte * PtPonte;

struct Descritor {
	int tamanho;
	int altura;
};

struct Raiz {
	unsigned profundidade;
};
typedef struct Raiz Raiz;
typedef Raiz * PtRaiz;

void * test(void *data) {
	return (void *)data;
}

int mainArvore(int argc, char **argv) {
	CelulaTmp A;
	NoAB i, *pi;
	void *pv, *other, *aux;
	int num = 4, *newData;
	char charactere = 'z', *newCharactere;
	double floatingPoint = 3.1415, *newFloat;
	Celula celulaA, celulaB, celulaC;

	celulaA.dado = &num;
	celulaB.dado = &charactere;
	celulaC.dado = &floatingPoint;

	newData = (int *)celulaA.dado;
	printf("%d\t%d\n", *newData, sizeof(celulaA));

	newCharactere = (char *)celulaB.dado;
	printf("%c\t%d\n", *newCharactere, sizeof(celulaB));

	newFloat = (double *)celulaC.dado;
	printf("%lf\t%d\n", *newFloat, sizeof(celulaC));

	//celulaA.proxima = (PtCelula)malloc(sizeof(Celula));
	celulaA.proxima = &celulaB;

	celulaA.proxima->proxima = (PtCelula)malloc(sizeof(Celula));
	*celulaA.proxima->proxima = celulaC;

	newCharactere = (char *)celulaA.proxima->dado;
	printf("%c\n", *newCharactere);

	newFloat = (double *)celulaA.proxima->proxima->dado;
	printf("%lf\n", *newFloat);

	newFloat = (double *)celulaB.proxima->dado;
	printf("%lf\n", *newFloat);

	aux = &num;

	newData = (int *)test(aux);

	num = 9;
	printf("%d\n", *newData);

	i.chave = 6;
	pv = &i;
	other = pv;
	pi = (NoAB *)test(other);

	i.chave = 7;

	printf("%d\n", pi->chave);

	A.left = (PtCelulaTmp)malloc(sizeof(CelulaTmp));

	free(A.left);
	A.right = (PtCelulaTmp)malloc(sizeof(CelulaTmp));
	free(A.right);

	NoAB *raiz;
	raiz = criarNoAB(5);
	raiz->fe = criarNoAB(3);
	raiz->fd = criarNoAB(8);

	raiz->fe->fe = criarNoAB(2);
	raiz->fe->fd = criarNoAB(4);

	raiz->fd->fe = criarNoAB(7);
	raiz->fd->fd = criarNoAB(12);

	raiz->fe->fe->fe = criarNoAB(30);

	puts("Pré-ordem: ");
	preOrdem(raiz);
	printf("\n");

	puts("Pós-ordem: ");
	posOrdem(raiz);
	printf("\n");

	puts("Em ordem: ");
	emOrdemNoAB(raiz);
	printf("\n");

	puts("Em nível: ");
	emNivel(raiz);
	printf("\n");

	return (0);
}
