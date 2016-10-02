/*
 * String.h
 * Função : Criar e manipular cadeias de caracteres
 * Camada de software: Interna
 * Data : Qua Mar 05 19:41:39 2014
 *
 *  Created on: 02/10/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef STRING_H_
#define STRING_H_

// Herança de bibliotecas
#include <string.h> // strlen(); strcpy(,)
#include <stdlib.h> // malloc()

// Seção de Variáveis Globais
// Estruturas de Dados
#ifndef __cplusplus
 typedef char * string;
#endif

// Interface da biblioteca
char *inverterPalavra (int, char **, char *);
int testeString (int, char **);

// Fim da biblioteca String.h

#endif /* STRING_H_ */
