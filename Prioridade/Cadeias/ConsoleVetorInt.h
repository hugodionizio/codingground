// Biblioteca: ConsoleVetorInt.h
// Função : Criar e manipular vetores de números inteiros
// Camada de software: Interface com usuário via Console
// Autor(es) : SANTOS, Hugo Dionizio
// Data : Ter Mar 04 21:03:47 2014

// Herança de bibliotecas
#include <stdio.h> // printf()
#include "ConioX.h" // implements ConioX
#include "VetorInt.h" // extends VetorInt

// Seção de Variáveis Globais
// Estruturas de Dados

#define TAMANHOVETOR "Informe o tamanho vetor: "
#define LIMITEVALORES "Informe o limite dos valores de cada campo do vetor: "
#define VALORPOSICAO "\nO valor do vetor na posição %u é %d"

// Interface da biblioteca
VetorInt consoleCriarVetorInt (int argc, char **argv);
void consoleInicializarVetorInt (VetorInt *vetor, int argc, char **argv);
VetorInt consoleConstruirVetorInt (int argc, char **argv);
void consoleOrdenadoVetorInt (VetorInt vetor);
void consoleGetTamanhoVetor (VetorInt vetor);
void consoleGetValorVetor (VetorInt vetor, unsigned posicao);
void consoleImprimirVetor (VetorInt vetor);
int testeConsoleVetorInt (int argc, char **argv);

// Seção de Implementação de Funções
int testeConsoleVetorInt (int argc, char **argv) {
// Seção de Variáveis Locais
	VetorInt vetor;

// Seção de Comandos
	vetor = consoleCriarVetorInt (argc, argv);
	consoleInicializarVetorInt (&vetor, argc, argv);
	consoleOrdenadoVetorInt (vetor);
	consoleGetTamanhoVetor (vetor);
	consoleGetValorVetor (vetor, random()%getTamanhoVetor(vetor));
	consoleImprimirVetor (vetor);
	putchar(10);

	vetor = consoleConstruirVetorInt (argc, argv);
	consoleOrdenadoVetorInt (vetor);
	consoleGetTamanhoVetor (vetor);
	consoleGetValorVetor (vetor, random()%getTamanhoVetor(vetor));
	consoleImprimirVetor (vetor);

	return (0);
}

// Seção de Funções de Interface com usuário via Console para a estrutura VetorInt (Console para Vetor de Inteiros)
VetorInt consoleCriarVetorInt (int argc, char **argv) {
	VetorInt vetor;
	int tamanho;

	if (argc < 2) {
		puts(TAMANHOVETOR);
		scanf("%d", &tamanho);
	}
	else {
		sscanf(argv[1],"%d",&tamanho);
	}
	vetor = criarVetorInt (tamanho);

	return vetor;
}

void consoleInicializarVetorInt (VetorInt *vetor, int argc, char **argv) {
	int limite;

	if (argc < 3) {
		puts(LIMITEVALORES);
		scanf("%d", &limite);
	}
	else if (argc == 3) {
		sscanf(argv[2],"%d",&limite);
	}
		else {
			sscanf(argv[3],"%d",&limite);
		}
	inicializarVetorInt (vetor, limite);
}

VetorInt consoleConstruirVetorInt (int argc, char **argv) {
	VetorInt vetor;
	int tamanho, limite;

	if (argc < 4) {
		puts(TAMANHOVETOR);
		scanf("%d", &tamanho);
	}
	else {
		sscanf(argv[3],"%d",&tamanho);
	}

	if (argc < 5) {
		puts(LIMITEVALORES);
		scanf("%d", &limite);
	} if (argc == 5) {
		sscanf(argv[4],"%d",&limite);
	}
		else {
			sscanf(argv[5],"%d",&limite);
		}

	vetor = construirVetorInt (tamanho, limite);

	return vetor;
}

void consoleOrdenadoVetorInt (VetorInt vetor) {
	float razao;

	razao = ordenadoVetorInt (vetor);

	printf("\nO vetor está %f%% ordenado", razao*100);
}

void consoleGetTamanhoVetor (VetorInt vetor) {

	printf("\nO tamanho do vetor é %u", getTamanhoVetor (vetor));
}

void consoleGetValorVetor (VetorInt vetor, unsigned posicao) {

	printf(VALORPOSICAO, posicao+1, getValorVetor (vetor, posicao));
	putchar(10);
}

void consoleImprimirVetor (VetorInt vetor) {
	Contador i;
	unsigned tamanho = getTamanhoVetor (vetor);

	for (i = 0; i < tamanho; i++)
		printf(VALORPOSICAO, i+1, getValorVetor (vetor, i));
	putchar(10);
}

// Fim da biblioteca ConsoleVetorInt.h
