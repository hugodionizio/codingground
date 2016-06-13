/*
 * main.c
 *
 *  Created on: 08/07/2015
 *      Author: Hugo Dionzio Santos
 */
#define TAM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Auxiliares/trocar.h"
#include "Prioridade/Prioridade.h"
//#include "Prioridade.h"
//#include "trocar.c"
//#include "piso.c"

int main() {
	int i = 0, j = 1, k[2], aux, aleatorio, v[TAM];
	T t[4], t2[TAM], t3[TAM], t4[TAM],
	t5[TAM] // = {{0,'a'}, {5,'b'}, {6,'c'}, {7,'d'}, {9,'e'},
			//  {1,'f'}, {2,'g'}, {3,'h'}, {4,'i'}, {8,'j'}}
	   ,
	t6[TAM];
	Desc d, d2, d3, d4, d5, d6;

	inicializar(&d, 3, 2, &t);
	inicializar(&d2, TAM, TAM, &t2);
	inicializar(&d3, TAM, TAM, &t3);
	inicializar(&d4, TAM, TAM, &t4);
	inicializar(&d5, TAM, TAM, &t5);
	inicializar(&d6, TAM, TAM, &t6);

	k[0] = 3;
	k[1] = 4;

	t[0].chave = 5; t[0].processo = 'a';
	t[1].chave = 6;	t[1].processo = 'b';
	t[2].chave = 7;	t[2].processo = 'c';
	t[3].chave = 8; t[3].processo = 'd';

	// Inicializar Prioridade Aleatória
	aux = i;
	for (i = 0; i < TAM; i++) {
		t2[i].chave = i;
		t2[i].processo = (char)(65+i);

		t3[i].chave = i;
		t3[i].processo = (char)(97+25-i);

		t4[i].chave = i;
		t4[i].processo = (char)(65+i);

		t5[i].chave = i;
		t5[i].processo = (char)(97+25-i);

		t6[i].chave = i;
		t6[i].processo = (char)(65+i);
	}
	i = aux;

	imprimirPrioridade(d2);
	embaralharPrioridade(&d2);
	imprimirPrioridade(d2);

	imprimirPrioridade(d3);
	embaralharPrioridade(&d3);
	imprimirPrioridade(d3);

	imprimirPrioridade(d4);
	embaralharPrioridade(&d4);
	imprimirPrioridade(d4);

	imprimirPrioridade(d5);
	embaralharPrioridade(&d5);
	imprimirPrioridade(d5);

	imprimirPrioridade(d6);
	embaralharPrioridade(&d6);
	imprimirPrioridade(d6);

	printf("Construção e Manuseio de Listas de Prioridades\n");

	// Função Piso de Um Valor Decimal
	printf("piso(4.7) = %d\n", piso(4.5));

	// Troca de Valores de Duas Variáveis
	printf("i = %d\tj = %d\n", i, j);
	trocar(&i, &j);
	printf("i = %d\tj = %d\n", i, j);

	// Troca de Posições de um Vetor
	printf("k0 = %d\tk1 = %d\n", k[0], k[1]);
	trocar(&k[0], &k[1]);
	printf("k0 = %d\tk1 = %d\n", k[0], k[1]);

	// Troca de Prioridades
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);
	trocarT(&t[0], &t[1]);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);

	// Elevação de Prioridade
	subir(t, 2);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);

	// Redução de Prioridade
	descer(t, 1, 2);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);

	// Impressão de Prioridade
	putchar(13);
	imprimirPrioridade(d);

	// Inserção de Prioridade
	inserirPrioridade(&d, t[2]);
	imprimirPrioridade(d);

	// Remoção de Prioridade
	removerPrioridade(&d);
	imprimirPrioridade(d);

	inserirPrioridade(&d, t[3]);
	imprimirPrioridade(d);

	removerPrioridade(&d);
	imprimirPrioridade(d);

	// Construção de Uma Lista de Prioridades por Inserção
	construirPrioridades(&d, 3);
	imprimirPrioridade(d);

	putchar(13);
	imprimirPrioridade(d2);
	construirPrioridades(&d2, TAM);
	imprimirPrioridade(d2);

	// Construção de Uma Lista de Prioridades por Arranjo
	putchar(13);
	imprimirPrioridade(d3);
	arranjar(&d3, TAM);
	imprimirPrioridade(d3);

	// Ordenação de T
	putchar(13);
	imprimirPrioridade(d4);
	ordenarT(&d4, TAM);
	imprimirPrioridade(d4);

	// Descer na árvore
	putchar(13);
	printf("\nDescendo na árvore...\n");
	for (i = 0; i < TAM; i++) {
		v[i] = d5.t[i].chave;
		printf("v[%d] = %d; ", i, v[i]);
	}
	putchar(13);
	for (i = 0; i < TAM; i++) {
		printf("pos(%d) = %d; ", i, buscaSequencial(i, TAM, v));
	}

	putchar(13);
	imprimirPrioridade(d5);
	descerNaArvore(&d5, 2);
	imprimirPrioridade(d5);

	// Subir na árvore
	putchar(13);
	printf("\nSubindo na árvore...\n");
	for (i = 0; i < TAM; i++) {
		v[i] = d6.t[i].chave;
		printf("v[%d] = %d; ", i, v[i]);
	}
	putchar(13);
	for (i = 0; i < TAM; i++) {
		printf("pos(%d) = %d; ", i, buscaSequencial(i, TAM, v));
	}

	putchar(13);
	imprimirPrioridade(d6);
	subirNaArvore(&d6, (int)(TAM*3/4));
	imprimirPrioridade(d6);


	printf("Finalizando...\n");
	printf("\nLista de Prioridades finalizada.");

	return (0);
}
