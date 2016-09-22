// Biblioteca: String.h
// Função : Criar e manipular cadeias de caracteres
// Camada de software: Interna
// Autor(es) : SANTOS, Hugo Dionizio
// Data : Qua Mar 05 19:41:39 2014 

// Herança de bibliotecas
#include <string.h> // strlen(); strcpy(,)
#include <stdlib.h> // malloc()

// Seção de Variáveis Globais
// Estruturas de Dados

// Interface da biblioteca
char *inverterPalavra (int argc, char **argv, char *palavra2);

// Seção de Implementação de Funções
int testeString (int argc, char **argv) {

	inverterPalavra (argc, argv, "órgão");

	return (0);
}

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

// Fim da biblioteca String.h
