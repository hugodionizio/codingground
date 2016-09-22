/*
 * descerNaArvore.c
 *
 *  Created on: 31/07/2015
 *      Author: hugo
 */
#include <math.h>

#include "../../estruturas/Prioridade/Prioridade.h"
#ifdef _WIN32
# define WINDOWS
#elif _WIN64
# define WINDOWS
#endif
#ifdef WINDOWS
# include "H:/Users/Public/Documents/Algoritmos/Biblioteca/Sort.h"
# include "H:/Users/Public/Documents/Algoritmos/Biblioteca/Search.h"
#else
# include "/home/hugo/Público/Documents/Algoritmos/Biblioteca/Sort.h"
# include "/home/hugo/Público/Documents/Algoritmos/Biblioteca/Search.h"
#endif

int posPrioridade(Desc d, int i) {
	int var = 0, tam = d.celulas, pos = 0;
	int * v = (int *)malloc(sizeof(int)*tam);

	printf("Buscando posição de %d...\n", i);
	for (var = 0; var < tam; ++var) {
		v[var] = d.t[var].chave;
		printf("var[%d] = %d, ", var, v[var]);
	}

	pos = buscaSequencial(i, tam, v)+1;
	printf("\nPosição(%d) = %d\n", i, pos);

	return pos;
}

int nivel(Desc d, int i) {
	double dresult;
	int result;

	printf("Verificando nível...\n");
	dresult = log(i)/log(2);
	//dresult = i;
	result = piso(dresult)+1;
//	if (result < dresult) result+=1;
	printf("Nível = piso(%.2f) + 1 = %d\n", dresult, result);
/*
	for (var = 0; var <= pos; ++var) {
		dresult = log2(var+1);
		result = piso(dresult) + 1;
		printf("Nível = piso(%.2f) + 1 = %d\n", dresult, result);
	}
*/
	printf("Nível verificado.\n");

	return result;
}

bool minPrioridade(int nivelCh) {
	int result = false;

	if (nivelCh%2 == 0) result = true;

	return result;
}

bool minMax(Desc *d) {
	bool result = false;
	int i;
	
	for (i = 1; i <= d->celulas; ++i) {
		if (d->t[i].chave > d->t[0].chave) {
			if (minPrioridade(nivel(*d, i)) == true) {
				if (i < 4 && d->t[i].chave <= d->t[i/2].chave ||
					i >= 4 && d->t[i].chave >= d->t[i/4].chave) result = true;
				else {
					result = false;
					break;
				}
			}
			else {
				if (i < 4 && d->t[i].chave >= d->t[i/2].chave ||
					i >= 4 && d->t[i].chave <= d->t[i/4].chave) result = true;
				else {
					result = false;
					break;
				}
			}
		}
		else {
			result = false;
			break;
		}
	}

	return result;
}

void descerNaArvore(Desc *d, int i) {	// algoritmo 6.8: Descer na árvore

	printf("\nDescendo %d na árvore...\n", i);
	if (minPrioridade(nivel(*d, i)) == true) {
		printf("Descendo o mínimo...\n");
		descerMin(d, i);
	}
	else {
		printf("Descendo o máximo...\n");
		descerMax(d, i);
	}
}
