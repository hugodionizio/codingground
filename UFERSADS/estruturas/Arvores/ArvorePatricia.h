// Instituição: Universidade Federal Rural do Semi-Árido
// Departamento: Departamento de Ciências Exatas e da Natureza
// Disciplina: Estruturas de Dados II
// Professor: Paulo Henrique Lopes Silva
// Acadêmico: Hugo Dionizio Santos
// Data: Sex 18 Jul 2014 23:32:36 UTC
// Algoritmo: ArvorePatricia.c
/* Funções : Implementar uma árvore PATRICIA para o alfabeto (em ASCII) {a, b, ..., z}, contendo as operações:
 *		Busca;
 *		Inserção.
 */	

#include <stdio.h>
#include <stdlib.h>

#ifndef _ARVOREPATRICIA_H_
# define _ARVOREPATRICIA_H_
#define LIM 8
#define LAMBDA NULL

// Lógico
typedef enum {
	false,
	true
} bool;

struct ArvorePatricia {
	int bitDiferencial;
	int info;

	struct ArvorePatricia *esq, *dir;
};
typedef struct ArvorePatricia ArvorePatricia;

// Interface da biblioteca
int testArvorePatricia ();

// Algoritmo de teste
int testArvorePatricia () {
	int vetor[8];
	ArvorePatricia pat;

	inserirPatricia((ArvorePatricia *)&pat, 1, 2);
	ordem(&pat);

	return (0);
}

void ordem(ArvorePatricia *ptr) {

	if(ptr != NULL) {
		ordem(ptr->esq);
		printf("%d ", ptr->info);
		ordem(ptr->dir);
	}
}

void ocupar(ArvorePatricia *pt) {
}

int min (int a, int b) {
	if (a > b) return b;
	else return a;
}

// Busca em árvore Patrícia
void buscaPatricia(int x, ArvorePatricia pt, int a) {
	ArvorePatricia *temp;
	int k = LIM, d[LIM];

	if (pt.esq == LAMBDA) a = 1;
	else if (k < pt.bitDiferencial) a = 2;
		else if (d[pt.bitDiferencial] == 0) {
			temp = (ArvorePatricia *)&pt.esq;
			buscaPatricia(x, *temp, a);
		}
			else {
				temp = (ArvorePatricia *)&pt.dir;
				buscaPatricia(x, *temp, a);
			}
}

// Inclusão em árvore Patrícia
void inserirPatricia(ArvorePatricia *pt, int x, int a) {
	ArvorePatricia *ptraiz, *ptq, *ptv, *ptw, *ptz, *ptNovoY;
	int c, k = LIM, l, d[LIM], novoD[LIM];
	bool descer, esquerdo;

	if (ptraiz == LAMBDA) { // árvore vazia
		ocupar(pt);
		pt->bitDiferencial == x;
		pt->esq == pt->dir == (int)LAMBDA;
		ptraiz == pt;
	}
	else { // localização de y'
		ptNovoY == ptraiz;
		buscaPatricia(x, *ptNovoY, a);
		while (ptNovoY->esq != LAMBDA)
			ptNovoY == ptNovoY->esq;
			l = 0;
		while (l < min(k, c) && d[l + 1] == novoD[l + 1])
			l = l + 1;	// i calculado
		if (l != min(k, c)) {
			ocupar(ptv); ocupar(ptw);	// criação de v && w
			ptv->bitDiferencial = l + 1; ptw->bitDiferencial = x;
			ptw->esq = ptw->dir = LAMBDA;
			ptz = ptraiz; descer = true;	// localização de z && q
			while (ptz->esq != LAMBDA && descer)
				if (ptz->bitDiferencial <= l + 1) {
					ptq = ptz;
					if (d[ptz->bitDiferencial ] == 0) {
						ptz = ptz->esq;
						esquerdo = true;
					}
					else ptz = ptz->dir; esquerdo = false;
				}
				else descer = false;	// z && q localizados
			if (d[l + 1] == 0) {
				ptv->esq = ptw;
				ptv->dir = ptz;
			}
			else ptv->esq = ptz;
				ptv->dir = ptw;
			if (ptz == ptraiz) ptraiz = ptv;
			else if (esquerdo)
				ptq->esq = ptv;
				else ptq->dir = ptv;
		}
		else puts("inclusão inválida");
	}
}
#endif
