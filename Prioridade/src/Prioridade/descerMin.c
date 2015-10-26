/*
 * descerMin.c
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */
#include <stdio.h>
#include "Prioridade.h"

bool temFilhos(Desc d, int i) {
	bool sucesso = false;
//	int celulas = d.celulas;
//	int memoria = d.memoria;
//	int chave = d.t[0].chave;
	int posEsq, posDir
	//, nivelP, posPrior, geracaoEsq, geracaoDir, posFilhoMenor
	;

//	posPrior = posPrioridade(d, i);
	posEsq = 2*i;
	if (posEsq <= d.celulas) {
		sucesso = true;
		printf("\nTem pelo menos um filho\n");
	}
	else {
		sucesso = true;
		printf("\nSem filhos\n");
	}

/*
	printf("Verificando filhos de %d, onde celulas = %d, memoria = %d, chave(0) = %d...\n",
			i, celulas, memoria, chave);
	nivelP = nivel(d, i);
	printf("Nível da prioridade = %d;\n", nivelP);

	if (nivelP == 1) {
		if (d.celulas > 1) {
			printf("Primeiro nível e %d células.", d.celulas);
			sucesso = true;
		}
	}
	else {
		printf("Analisando parentesco...\n");
		posMenor = (int)pow(2, nivelP - 1);
//		printf("posMenor = %d\t", posMenor);
		geracaoEsq = posPrioridade(d, i) - posMenor;
		posMaior = (int)pow(2, nivelP);
		geracaoDir = posPrioridade(d, i) + (int)pow(2, nivelP) - 2;

		posFilhoMenor = (geracaoEsq + 1)*2 + geracaoDir - 1;

		printf("posMenor = %d\tgeracaoEsq = %d\tposMaior = %d\tgeracaoDir = %d\t células = %d\n",
				posMenor, geracaoEsq, posMaior, geracaoDir, d.celulas);

		if (posFilhoMenor <= d.celulas) {
			printf("\nHá pelo menos um filho\n");
			sucesso = true;
		}
		else {
			printf("\nHá pelo menos um filho\n");
			sucesso = false;
		}
	}
*/

	return sucesso;
}

bool eNeto(Desc d, int m, int i) {
	bool sucesso = false;
	int ascendente = d.t[i-1].chave;
	int descendente = d.t[m-1].chave;

	if(nivel(d, m) == 2+nivel(d,i)) {
		printf("%d é neto de %d.\n", descendente, ascendente);
		sucesso = true;
	}
	else printf("%d não é neto de %d\n", descendente, ascendente);

	return sucesso;
}

int menor(Desc d, int i) {
	int posEsq, posDir,// posPrior,
	posMenorDir, posMenorEsq,
	valorMenor,	posMenor = -1;

	//posPrior = posPrioridade(d, i);
	posEsq = 2*i;
	posDir = posEsq + 1;

	printf("Verificando descendentes à esquerda...\n");
	if (temFilhos(d, posEsq) == true) {
		posMenorEsq = menorNeto(d, posEsq);
		if (d.t[posEsq-1].chave < d.t[posMenorEsq-1].chave) {
			posMenor = posEsq;
		}
		else {
			posMenor = posMenorEsq;
		}
	}
	else {
		posMenor = posEsq;
	}

	printf("Verificando descendentes à direita...\n");
	if(posDir <= d.celulas) {
		if (temFilhos(d, posDir) == true) {
			posMenorDir = menorNeto(d, posDir);
			if (d.t[posDir-1].chave < d.t[posMenorDir-1].chave) {
				posMenorDir = posDir;
			}
		}
		else {
			posMenorDir = posDir;
		}

		if (d.t[posMenorDir-1].chave < d.t[posMenor-1].chave) {
			posMenor = posMenorDir;
		}
	}

	valorMenor = d.t[posMenor-1].chave;

	printf("Posição do menor descedente (%d) = %d\n", valorMenor, posMenor);

	return posMenor;
}

int menorNeto(Desc d, int i) {
	int posEsq, posDir,
	//posPrior,
	posMenor = -1, valorMenor = -1;

	//posPrior = posPrioridade(d, i);
	posEsq = 2*i;
	posDir = posEsq + 1;

	if(posDir <= d.celulas && d.t[posDir-1].chave < d.t[posEsq-1].chave) {
		valorMenor = d.t[posDir-1].chave;
		posMenor = posDir;
	}
	else {
		valorMenor = d.t[posEsq-1].chave;
		posMenor = posEsq;
	}

	printf("Posição do menor neto (%d) = %d\n", valorMenor, posMenor);

	return posMenor;
}

void descerMin(Desc *d, int i) {	// algoritmo 6.9: descer a partir de um nível mínimo
	int m, pai;
	//int posPrior = posPrioridade(*d, i);
	double pisoTmp;

	printf("Descendo %d o mínimo...\n", i);
	if (temFilhos(*d, i) == true) {
		printf("\nTem filhos\n");
		m = menor(*d, i);
		if (eNeto(*d, m, i)) {
			printf("Comparando valores (%d e %d)\n", d->t[m-1].chave, d->t[i-1].chave);
			if (d->t[m-1].chave < d->t[i-1].chave) {
				trocarT(&d->t[m-1], &d->t[i-1]);
				pisoTmp = (double)(m/2.0f);
				pai = piso(pisoTmp);
				if (d->t[m-1].chave > d->t[pai-1].chave) {
					trocarT(&d->t[m-1], &d->t[pai-1]);
				}
				descerMin(d, m);
			}
		}
		else if (d->t[m-1].chave < d->t[i-1].chave) {
			trocarT(&d->t[i-1], &d->t[m-1]);
		}
	}
}
