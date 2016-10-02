/*
 * Vector.h
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define repeat(n) for(i = 0; i < n; i++)
#define criarVetor(n) n *aux = (n *)malloc(tam*sizeof(n)); vetor = aux;
#define apontarVetor(n) pv = (n *)v.info;

enum {BOOL, CHAR, INT, FLOAT, DOUBLE, COMPLEX};

// Converter int para bool
// Lógico
#ifndef __cplusplus
	typedef enum {
		false,
		true
	} bool;

	struct complex {
	    int real;
	    int img;
	};
	typedef struct complex complex;
	typedef complex * PtComplex;
#endif

struct Vector {
    void *info;
    unsigned size;
    unsigned type;
};
typedef struct Vector Vector;
typedef Vector * PtVector;

#endif /* VECTOR_H_ */
