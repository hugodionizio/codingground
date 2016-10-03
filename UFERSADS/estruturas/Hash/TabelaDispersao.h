/*
 * TabelaDispersao.h
 *
 *  Created on: 03/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ESTRUTURAS_HASH_TABELADISPERSAO_H_
#define ESTRUTURAS_HASH_TABELADISPERSAO_H_

#include <stdlib.h>

enum estado {
	naoocupado,
	ocupado
};

typedef struct TabelaDispersao {
	bool estado;
	int chave;
	int pont;
} TabelaDispersao;

typedef struct Dir {
	int chave;

	struct Dir *seg;
	struct Dir *prox;
} Dir;

const int lambda = NULL;

int h(int);
int hb(int, int);
void buscaEncadeamentoInterior(int, int, int);
int mod(int, int);
bool insercaoEncadeamentoInterior(int, int, int);
void remocaoEncadeamentoInterior(int, int, int);
void buscaEnderecamentoAberto (int, int, int);
int hl(int);
int hl1(int);
void calcularEnderecoChave(int, int, int, int);
void reservar(int, Dir);
bool DirEquivalente(Dir, Dir);
void lista_encadeada(int, int);
int potencia(int, int);
void atual(int, int);
void expansaoCompartimentoP(int, int);

#endif /* ESTRUTURAS_HASH_TABELADISPERSAO_H_ */
