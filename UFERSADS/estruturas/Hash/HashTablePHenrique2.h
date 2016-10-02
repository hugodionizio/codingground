/*
 * HashTablePHenrique.h
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef ESTRUTURAS_HASH_HASHTABLEPHENRIQUE2_H_
#define ESTRUTURAS_HASH_HASHTABLEPHENRIQUE2_H_

typedef struct Vetor {
	void *v;
	unsigned tamanho;
} Vetor;
typedef Vetor * PtVetor;

void imprimirVetorHash2(Vetor);
int hashPHenrique2 (int, int);
int hashTL (int, int, int *, int, int);
int mainHashTablePHenrique2(int, char **);

#endif /* ESTRUTURAS_HASH_HASHTABLEPHENRIQUE2_H_ */
