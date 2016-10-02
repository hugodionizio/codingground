// Biblioteca: VetorInt.h
// Função : Criar e manusar vetores de números inteiros
// Camada de software: Interna
// Autor(es) : SANTOS, Hugo Dionizio
// Data : Ter Mar 04 21:03:47 2014

// Herança de bibliotecas
#include <stdlib.h>
#include <time.h>

// Seção de Variáveis Globais
// Estruturas de Dados
typedef unsigned Contador;
typedef int Tipo;

struct VetorInt {
	unsigned tamanho;
	Tipo *arranjo;
};
typedef struct VetorInt VetorInt;

// Interface da biblioteca
VetorInt criarVetorInt (int tamanho);
void inicializarVetorInt (VetorInt *vetor, int limite);
VetorInt construirVetorInt (int tamanho, int limite);
float ordenadoVetorInt (VetorInt vetor);
unsigned getTamanhoVetor (VetorInt vetor);
int getValorVetor (VetorInt vetor, unsigned posicao);
int testeVetorInt ();

int testeVetorInt () {
// Seção de Variáveis Locais

// Seção de Comandos

	return (0);
}

// Seção de Funções Internas para a Estrutura VetorInt (Vetor de Inteiros)
VetorInt criarVetorInt (int tamanho) {
	VetorInt vetor;

	vetor.tamanho = tamanho;
	vetor.arranjo = (Tipo *)malloc(tamanho*sizeof(Tipo));

	return vetor;
}

void inicializarVetorInt (VetorInt *vetor, int limite) {
	Contador i;

	srand(time(NULL));
	for (i = 0; i < vetor->tamanho; i++)
		vetor->arranjo[i] = rand()%limite;
}

VetorInt construirVetorInt (int tamanho, int limite) {
	VetorInt vetor;

	vetor = criarVetorInt (tamanho);
	inicializarVetorInt (&vetor, limite);

	return vetor;
}

float ordenadoVetorInt (VetorInt vetor) {
	float razao;
	Contador i, ordenados = 0;

	for (i = 0; i < vetor.tamanho - 1; i++)
		if (vetor.arranjo[i] <= vetor.arranjo[i+1])
			ordenados++;
	razao = (float)ordenados/(float)vetor.tamanho;

	return razao;
}

unsigned getTamanhoVetor (VetorInt vetor) {

	return vetor.tamanho;
}

Tipo getValorVetor (VetorInt vetor, unsigned posicao) {

	return vetor.arranjo[posicao];
}

// Fim da biblioteca VetorInt.h
