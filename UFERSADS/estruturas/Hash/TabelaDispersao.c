/*
 * TabelaDispersao.c
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Cadeias/Vector.h"
#include "TabelaDispersao.h"

int h(int x) {
	return 0;
}

int hb(int x, int k) {
	return 0;
}

/*
 * Busca por encadeamento interior
 * algoritmo 8.1
 */
void buscaEncadeamentoInterior(int x, int end, int a) {
	//procedimento busca(x, end, a)
		a = 0;
		end = h(x);
		int j = lambda;
		TabelaDispersao *T;

		while (a == 0) {
			if (T[end].estado == naoocupado) {
				j = end;
			}
			if (T[end].chave == x && T[end].estado == ocupado) {
				a = 1;				// chave encontrada
			}
			else {
				end = T[end].pont;
				if (end == h(x)) {
					a = 2; end = j;	// chave não encontrada
				}
			}
		}
}

int mod(int num, int div) {
	return num % div;
}

/*
 * Inserção por encadeamento interior
 * algoritmo 8.2
 */
bool insercaoEncadeamentoInterior(int x, int end, int a) {
	int i, j, m, temp;
	TabelaDispersao *T;

	buscaEncadeamentoInterior(x, end, a);
	if (a != 1) {
		if (end != lambda) {
			j = end;
		}
		else i = 1; j= h(x);
			while (i <= m) {
				if (T[j].estado == ocupado) {
					j = mod((j + 1), m);
					i = i + 1;
				}
				else i = m + 2;	// compartimento não ocupado;
			}
			if (i == m + 1) {
				printf("inserção inválida: overflow");
				return -1;
			}
			temp = T[j].pont;	// fusão de listas;
			T[j].pont = T[h(x)].pont;
			T[h(x)].pont = temp;
		T[j].chave = x;	// inserção de x;
		T[j].estado = ocupado;
	}
	else printf("inserção inválida: chave já existente");

	return 0;
}

/*
 * Remoção por encadeamento interior
 * algoritmo 8.3
 */
void remocaoEncadeamentoInterior(int x, int end, int a) {
	TabelaDispersao *T;

	buscaEncadeamentoInterior(x, end, a);
	if (a == 1) {
		T[end].estado = naoocupado;
	}
	else printf("exclusão inválida: chave não existente");
}

/*
 * Busca por endereçamento aberto
 * algoritmo 8.4
 */
void buscaEnderecamentoAberto (int x, int end, int a) {
//	procedimento busca-aberto(x, end, a);
		a = 3;
		int k = 0, m;
		TabelaDispersao *T;

		while (k < m) {
			end = hb(x, k);
			if (T[hb(x, k)].chave == x) {
				a = 1;	// chave encontrada;
				k = m;
			}
			else
				if (T[hb(x, k)].chave == lambda) {
					a= 2;	// posição livre;
					k= m;
			}
			else k = k + 1;
		}
}

int hl(int x) {
	return 0;
}

int hl1(int x) {
	return 0;
}

/*
 * Calcular o endereço da chave x
 * algoritmo 8.5;
 */
void calcularEnderecoChave(int x, int ender, int p, int l) {
	// procedimento mapear(x, ender, p, l);
	ender = hl(x);
	if (ender < p) {
		ender = hl1(x);
	}
}

void reservar(int p, Dir l) {

}

bool DirEquivalente(Dir a, Dir b) {
	return a.chave & b.chave;
}

/*
 * procedimento lista_encadeada(p, f);
 */
void lista_encadeada(int p, int l) {
	int id, id1, is, m;
	Dir *dir, *pt, *ant;
	Dir lambdaDir = {0, NULL, NULL};

	dir = (Dir *)malloc(l*sizeof(Dir));
	pt = (Dir *)malloc(sizeof(Dir));

	id = piso(p/m);
	id1= id + potencia(2, l);
	is = mod(p, m);
	dir->prox = (Dir *)malloc(id*sizeof(Dir));
	dir->seg = (Dir *)malloc(id*sizeof(Dir));
	pt[0].prox = (Dir *)malloc(sizeof(Dir));

	pt[0] = dir[id].seg[is];	// ponteiro lista p;
	dir[id1].seg[is] = lambdaDir;	// ponteiro lista expansão;
	while (!DirEquivalente(pt[0], lambdaDir)) {
		if (hl1(pt->chave) != is) { // transferir nó;
			if (DirEquivalente(pt[0], dir[id].seg[is])) {
				dir[id].seg[is] = pt[0].prox[0];
			}
			else ant->prox = pt->prox; // remoção da lista;
			pt[0].prox = &dir[id1].seg[is];
			dir[id1].seg[is] = pt[0];	// inclusão na lista expansão;
		}
		ant = pt;
		pt = pt->prox;
	}
}

int potencia(int base, int exp) {
	return (int)pow((double)base, (double)exp);
}
/*
 * procedimento atual(p, l)
 */
void atual(int p, int l) {
	int m;

	p = p + 1;
	if (p == m*(int)potencia(2, l)) {	// tabela duplicada;
		l = l + 1;
		p = 0;
	}
}

/*
 * Expansão do compartimento p
 * algoritmo 8.6
 */
void expansaoCompartimentoP(int p, int l) {
	//	procedimento expandir(p, l)
	int id1, m, is, i;
	Dir *dir, *pt;
	id1 = piso(p/m) + potencia(2,l);
	is = mod(p, m);
	int tamdir;

	dir = (Dir *)malloc(l*sizeof(Dir));
	pt = (Dir *)malloc(sizeof(Dir));

	if (id1 < tamdir) {
		if (is == 0) {
			reservar(m, pt[0]);	// construído novo segmento;
			dir[id1] = pt[0];	// ponteiro para novo segmento;
			lista_encadeada(p, l);
			atual(p, l);
		}
	}
	else printf ("diretório esgotado");

	//	procedimento lista_encadeada(p, f)
	//	procedimento atual(p, l)
}
