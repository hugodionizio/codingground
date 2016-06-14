// Algoritmo: Testes.c
// Função : Retornar a função de manipulação de uma biblioteca em testes
// Camada de software: Função Principal
// Autor : SANTOS, Hugo Dionizio
// Data : 26-11-2012 11:23:16

// Herança de bibliotecas
#include <stdio_ext.h>
#include "../Biblioteca/ConsoleString.h"
#include "../Biblioteca/CaracteresASCII.h"
#include "../Biblioteca/Arvore.h"

// Seção de Variáveis Globais
// Estruturas de Dados

// Interface do algoritmo
// int main (int argc, char **argv);

int main (int argc, char **argv) {
	char c[] = "☺";
	int tam = strlen(c);

	clrscr();
	printf("%d", tam);
	testeConsoleString (argc, argv);
	printASCII ();

	systemPause();

	return (0);
}

// Fim do algoritmo Testes.c
