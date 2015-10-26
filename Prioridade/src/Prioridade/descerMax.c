/*
 * descerMax.c
 *
 *  Created on: 01/08/2015
 *      Author: hugo
 */
#include "Prioridade.h"

int maior(Desc d, int i) {
	int posEsq, posDir,
	posMaiorDir, posMaiorEsq,
	valorMaior,	posMaior = -1;

	posEsq = 2*i;
	posDir = posEsq + 1;

	printf("Verificando descendentes à esquerda...\n");
	if (temFilhos(d, posEsq) == true) {
		posMaiorEsq = menorNeto(d, posEsq);
		if (d.t[posEsq-1].chave > d.t[posMaiorEsq-1].chave) {
			posMaior = posEsq;
		}
		else {
			posMaior = posMaiorEsq;
		}
	}
	else {
		posMaior = posEsq;
	}

	printf("Verificando descendentes à direita...\n");
	if(posDir <= d.celulas) {
		if (temFilhos(d, posDir) == true) {
			posMaiorDir = maiorNeto(d, posDir);
			if (d.t[posDir-1].chave > d.t[posMaiorDir-1].chave) {
				posMaiorDir = posDir;
			}
		}
		else {
			posMaiorDir = posDir;
		}

		if (d.t[posMaiorDir-1].chave > d.t[posMaior-1].chave) {
			posMaior = posMaiorDir;
		}
	}

	valorMaior = d.t[posMaior-1].chave;

	printf("Posição do maior descedente (%d) = %d\n", valorMaior, posMaior);

	return posMaior;
}

int maiorNeto(Desc d, int i) {
	int posEsq, posDir,
	posMaior = -1, valorMaior = -1;

	posEsq = 2*i;
	posDir = posEsq + 1;

	if(posDir <= d.celulas && d.t[posDir-1].chave > d.t[posEsq-1].chave) {
		valorMaior = d.t[posDir-1].chave;
		posMaior = posDir;
	}
	else {
		valorMaior = d.t[posEsq-1].chave;
		posMaior = posEsq;
	}

	printf("Posição do maior neto (%d) = %d\n", valorMaior, posMaior);

	return posMaior;
}


void descerMax(Desc *d, int i) {	// algoritmo 6.9: descer a partir de um nível mínimo
	int m, pai;
	double pisoTmp;

	printf("Descendo %d o máximo...\n", i);
	if (temFilhos(*d, i) == true) {
		printf("\nTem filhos\n");
		m = maior(*d, i);
		if (eNeto(*d, m, i) == true) {
			if (d->t[m].chave > d->t[i].chave) {
				trocarT(&d->t[m-1], &d->t[i-1]);
				pisoTmp = (double)(m/2.0f);
				pai = piso(pisoTmp);
				if (d->t[m-1].chave < d->t[pai-1].chave) {
					trocarT(&d->t[m-1], &d->t[pai-1]);
				}
				descerMax(d, m);
			}
		}
		else if (d->t[m-1].chave > d->t[i-1].chave) {
			trocarT(&d->t[i-1], &d->t[m-1]);
		}
	}
}
