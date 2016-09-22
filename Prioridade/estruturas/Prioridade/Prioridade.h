/*
 * Prioridade.h
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */

#ifndef ESTRUTURAS_PRIORIDADE_PRIORIDADE_H_
#define ESTRUTURAS_PRIORIDADE_PRIORIDADE_H_

enum bool {
	false,
	true
};
typedef enum bool bool;

#define econd &&

struct _T {
	int chave;
	char processo;
};
typedef struct _T T;

struct _Desc {
	int memoria;
	int celulas;

	T *t;
};
typedef struct _Desc Desc;

//#include "../Auxiliares/trocar.h"

#define PRIMEIRO 0
#define SEGUNDO 1
#define VAZIO -1
//#define T[n] d->t[n]

void trocarT(T *, T *); // algoritmo 6.extra: Permutar vetor de prioridades
void subir(T *, int);		// algoritmo 6.1: Subir por um caminho da árvore
void descer(T *, int, int); // algoritmo 6.2: Descer por um caminho da árvore
bool overflow(); // algoritmo 6.3extra: Indicar estouro superior
bool inserirPrioridade(Desc *, T);	// algoritmo 6.3:
void agir(T *);	// algoritmo 6.4extra1: Ação sobre dados
bool underflow(); // algoritmo 6.4extra2: Indicar estouro inferior
int removerPrioridade(Desc *);	// algoritmo 6.4: Remoção de um elemento da lista de prioridades
void construirPrioridades(Desc *, int);	// algoritmo 6.5: Construção da lista de prioridades
void imprimirPrioridade(Desc d); // algoritmo 6.extra2: Imprimir fila/lista de prioridades

#endif /* ESTRUTURAS_PRIORIDADE_PRIORIDADE_H_ */
