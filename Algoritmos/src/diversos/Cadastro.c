#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Abstração
typedef struct _pessoa {
	char nome[20];
	int dataNasc[3];
	int telefone;
} Pessoa;

// Interface do programa
void inicializar(Pessoa *cadastro, int tamanhoBancoDados);	// Inicializar os registros.nome[0] com ''
void preencher(Pessoa *cadastro);		// Preencher o cadastro (OPERADOR SETA ->)
void mostrar(Pessoa *cadastro);			// Mostrad o cadastro

// Função principal
int main(void) {
// Seção de constantes e variáveis
// Sub-seção de constantes
	const int INICIO = 0;
	const int OK = 0;

// Sub-seção de variáveis
	Pessoa *cadastro = NULL;
	int registroAtual, limiteCadastros;


// Seção modularizada
	printf ("Informe o limite de cadastros: ");
	scanf ("%d", &limiteCadastros);
	fflush(stdin);

	cadastro = malloc(sizeof(Pessoa) * limiteCadastros);	// Aloca um intervalo de memória para os cadastros

	if (!(cadastro = malloc(limiteCadastros))) {	// Testa se realmente foi alocado
		printf ("não alocado.");
		exit(1);
	}

	inicializar(cadastro, limiteCadastros);

	for (registroAtual = INICIO; registroAtual < limiteCadastros; registroAtual++) {	// Preenchimento de cadastro
		fflush(stdin);
		preencher(&cadastro[registroAtual]); // Passar o endereço de cadastro para a função
	}

	for (registroAtual = INICIO; registroAtual < limiteCadastros; registroAtual++) {	// Visualização de cadastros
		mostrar(&cadastro[registroAtual]); // Passar o endereço de cadastro para a função
	}

	return (OK);
}

// Seção de Funções
// Inicializar os registros.nome[0] com ''
void inicializar(Pessoa *cadastro, int tamanhoBancoDados) {
	const int INICIO = 0;
	register int registroAtual;

	for (registroAtual = INICIO; registroAtual < tamanhoBancoDados; registroAtual++) {
		cadastro[registroAtual].nome[0] = '0';
	}
}

// Preencher o cadastro (- OPERADOR SETA ->)
void preencher(Pessoa *cadastro) {

	printf ("Informe um nome: ");
	gets (cadastro->nome);

	printf ("Informe a data de nascimento: ");
	scanf ("%d/%d/%d", &cadastro->dataNasc[0], &cadastro->dataNasc[1], &cadastro->dataNasc[2]);

	printf ("Informe o numero do celular: ");
	scanf ("%d", &cadastro->telefone);
}

// Mostrar o cadastro
void mostrar(Pessoa *cadastro) {

	printf ("%s\n", cadastro->nome);
	printf ("%02d/%02d/%d\n", cadastro->dataNasc[0], cadastro->dataNasc[1], cadastro->dataNasc[2]);
	printf ("%d\n", cadastro->telefone);
	printf ("\n");
}
