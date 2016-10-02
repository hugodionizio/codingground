/*
 * String.c
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include "String.h"

// Seção de Funções Internas
char *inverterPalavra (int argc, char **argv, char *palavra2) {
	char *palavra, *inverso;
	int tam, i;

	if (argc > 1) {
		tam = strlen(argv[1]);
		palavra = argv[1];
	}
	else {
		tam = strlen(palavra2);
		palavra = palavra2;
	}
	tam = strlen(palavra);
	i = tam - 1;
	inverso = (char *)malloc(tam*sizeof(char));

	while (i >= 0) {
		if (palavra[tam-i-1] > 0)
			inverso[i] = palavra[tam-i-1];
		else {
			inverso[i-1] = palavra[tam-i-1];
			inverso[i] = palavra[tam-i];
			i--;
			}
		i--;
	}
	inverso[tam] = '\0';

	return inverso;
}

// Seção de Implementação de Funções
int testeString (int argc, char **argv) {

	inverterPalavra (argc, argv, "órgão");

	return (0);
}

