// Biblioteca: ConsoleString.h
// Função : Criar e manipular cadeias de caracteres
// Camada de software: Interface com usuário via Console
// Autor(es) : SANTOS, Hugo Dionizio
// Data : Qua Mar 05 19:27:32 2014 

// Herança de bibliotecas
#include <stdio.h> // printf()

#include "../estruturas/Cadeias/String.h"
#include "ConioX.h" // implements ConioX

// Seção de Variáveis Globais
// Estruturas de Dados

// Interface da biblioteca
void consoleInverterPalavra (int argc, char **argv, char *palavra);

// Seção de Implementação de Funções
int testeConsoleString (int argc, char **argv) {

	consoleInverterPalavra (argc, argv, "pensão");

	return (0);
}

// Seção de Funções de Interface com usuário via Console para a estrutura *char (Console para Cadeia de Caracteres)
void consoleInverterPalavra (int argc, char **argv, char *palavra2) {
	char *palavra, *aux;
	int tam, i;

	if (argc > 1) {
		tam = strlen(argv[1]);
		palavra = argv[1];
	}
	else {
		tam = strlen(palavra2);
		palavra = palavra2;
	}
	aux = inverterPalavra (argc, argv, palavra2);

	printf("\ninverso(%s) = %s\n", palavra, aux);
}

// Fim da biblioteca ConsoleString.h
