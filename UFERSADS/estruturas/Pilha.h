// Biblioteca: Pilha.h
// Função : Criar e manipular árvores binárias
// Camada de software: Interna
// Autor(es) : EDELWEISS, Nina; GALANTE, Renata; SANTOS, Hugo Dionizio
// Data : 03/02/2013 18:24:06, 10/02/2013 07:50, 16/04/2013 17:17:41, 07/03/2014 12:30:17 

// Seção de Variáveis Globais
/* Estrutura de pilha */
#include "Vector.h"

typedef struct cel {
	int valor; // Valor inteiro

	struct cel *seg; // Célula para encadeamento
} Celula;

/* Estrutura de um pilha com descritor */
struct _Pilha {
	int tamanho; // Tamanho do arranjo ou encadeamento
	int base; // Posição da base no arranjo
	int topo; // Posição do topo no arranjo

	Celula *celula; // Célula para arranjos ou encadeamento
};
typedef struct _Pilha Pilha;

// Interface da biblioteca
/* Pilhas implementadas por contiguidade física */
/* FEOFILOFF */
void removeDaPilhaArr (int x, int *p, int t);
void insereNaPilhaArr (int y, int *p, int t);
int BemFormadaArr (char *s);
char *InfixaParaPosfixaArr (char infix[]);

/* Novo: BONATES - Com descritor */
bool inicializarPilhaArr (Pilha *p, int tam);
int tamanhoPilhaArr(Pilha p);
Celula desempilharArr (Pilha *p);
bool empilharArr (Pilha *p, Celula dado);
bool consultarPilhaArr (Pilha p, Celula *topo);

/* Pilhas implementadas por encadeamento */
/* FEOFILOFF */
Celula criarPilhaEnc();
void EmpilhaEnc (int y, Celula *p);
int DesempilhaEnc (Celula *p);

/* SANTOS - Com descritor */
Pilha CriarPilhaEncDescr ();
bool inicializarPilhaEnc (Pilha *p);
int tamanhoPilhaEnc(Pilha p);
bool consultarPilhaEnc (Pilha p, Celula *topo);
bool empilharEnc (Pilha *p, Celula y);
Celula desempilharEnc (Pilha *p);
void DestruirPilhaEnc (Pilha *p);
int BemFormadaEnc (char s[]);
char *InfixaParaPosfixaEnc (char infix[]);
bool temNegativoPilhaEnc(Pilha p);
bool temNumPilhaEnc(Pilha p, int x);
void interseccionarPilhaEnc(Pilha *p);
void concatenarPilhasEnc(Pilha *p, Pilha *q);  // intercala dados iguais
void mesclarPilhasEnc(Pilha *p, Pilha *q);  // ignora dados iguais
void ordenarPilhaEnc(Pilha *p);
void aumentarTorreEnc(Pilha *p, int x);
void removerDaTorreEnc(Pilha *p, int x);
void moverTorreEnc(Pilha *p, Pilha *q);
void intercalarTorresEnc(Pilha *p, Pilha *q); // intercala dados iguais
void mesclarTorresEnc(Pilha *p, Pilha *q); // ignora dados iguais
void balancearTorresEnc(Pilha *p, Pilha *q);

void inserirFigura();
void mudaCorPalavra();
void apagarParagrafo();
void justificar();

void desfazer();
void refazer();


// Seção de Funções Internas
/* Pilha implementada em vetor */
/* FEOFILOFF */
/* Remove elemento da pilha */
void removeDaPilhaArr (int x, int *p, int t) {
	x = p[--t]; /* t -= 1; x = p[t]; */
}

/* Insere y na pilha */
void insereNaPilhaArr (int y, int *p, int t) {
	p[t++] = y; /* p[t] = y; t += 1; */
}

/* Algoritmo: Parênteses e chaves */
/*
	Devolve 1 se a string s contém uma seqüência bem-formada e devolve 0 em caso contrário.

	expressao bem-formada: ((){()})
	expressao malformada: ({)}
*/
int BemFormadaArr (char s[]) {
	char *p; int t;
	int n, i;
	n = strlen (s);
	p = (char *) malloc (n * sizeof (char));
	t = 0; /* para processo iterativo */

	/* processo iterativo */
	for (i = 0; s[i] != '\0'; i++) {
		/* p[0..t-1] é uma pilha */
		switch (s[i]) {
			case ')': if (t != 0 && p[t-1] == '(') --t;
				else return 0;
				break;
			case '}': if (t != 0 && p[t-1] == '{') --t;
				else return 0;
				break;
			default: p[t++] = s[i];
		}
	}

	free (p);
	return t == 0;
}

/* Algoritmo: notação posfixa */
/*
 * Recebe uma expressão infixa representada por uma string infix
 * que começa com '(' e termina com ')' seguido de '\0'.
 * Devolve a correspondente expressão posfixa.
 */
char *InfixaParaPosfixaArr (char infix[]) {
	char *posfix, x;
	char *p; int t;
	int n, i, j;
	n = strlen (infix);

	posfix = (char *) malloc (n * sizeof (char));
	p = (char *) malloc (n * sizeof (char));

	/* processo iterativo */
	t = 0; p[t++] = infix[0]; /* empilha '(' */
	for (j = 0, i = 1; /*X*/ infix[i] != '\0'; i++) {
		/* p[0..t-1] é uma pilha de caracteres */
		switch (infix[i]) {
			case '(': p[t++] = infix[i]; /* empilha */
				break;
			case ')': while (1) { /* desempilha */
					x = p[--t];
					if (x == '(') break;
					posfix[j++] = x;
				}
				break;
			/* demais casos */
			case '+':
			case '-': while (1) {
					x = p[t-1];
					if (x == '(') break;
					--t; /* desempilha */
					posfix[j++] = x;
				}
				p[t++] = infix[i]; /* empilha */
				break;
			case '*':
			case '/': while (1) {
					x = p[t-1];
					if (x == '(' || x == '+' || x == '-')
					break;
					--t;
					posfix[j++] = x;
				}
				p[t++] = infix[i];
				break;
			default: posfix[j++] = infix[i];
		}
	}

	free (p);
	posfix[j] = '\0';

	return posfix;
}

/* Novo: BONATES - Com descritor */
bool inicializarPilhaArr (Pilha *p, int tam) {
	bool sucesso;
	
	sucesso = false;

#ifndef __cplusplus
	p->celula = (Celula *)malloc(tam*sizeof(Celula));
#else
	p->celula = new Celula[tam];
#endif
	p->tamanho = 0; // -1?
	p->base = 0;
	p->topo = 0;

	sucesso = true;
	return sucesso;
}

int tamanhoPilhaArr(Pilha p) {

	return p.tamanho; // topo + 1?;
}

Celula desempilharArr (Pilha *p) {
	Celula desempilhada;

	if (p->topo > p->base) {
		desempilhada = p->celula[p->topo];
		p->topo--;
		p->tamanho--;
	}

	return desempilhada;
}

bool empilharArr(Pilha *p, Celula dado) {
	bool sucesso;

	sucesso = false;
	if (p->topo+1 < p->tamanho) {
		p->celula[p->topo+1] = dado;
		p->topo++;
		
	}
		//cout << "Pilha cheia!" << endl;
	return sucesso;
}

bool consultarPilhaArr(Pilha p, Celula *topo) {
	bool sucesso;
	
	sucesso = false;
	if (p.topo >= p.tamanho) {
		*topo = p.celula[p.topo];
		sucesso = true;
	}

	return sucesso;
}

/* Pilhas implementadas por encadeamento */
/* FEOFILOFF */
Celula criarPilhaEnc() {
	Celula cabeca;
	Celula *p;

	p = &cabeca; /* p->seg é o topo da pilha */
	p->seg = NULL;

	return cabeca;
}


/* Insere */
void EmpilhaEnc (int y, Celula *p) {
	Celula *nova;

	nova = (Celula *)malloc (sizeof (Celula));
	nova->valor = y;
	nova->seg = p->seg;
	p->seg = nova;
}

/* Remove */
int DesempilhaEnc (Celula *p) {
	int x; Celula *q;

	q = p->seg;
	x = q->valor;
	p->seg = q->seg;
	free (q);

	return x;
}

/* SANTOS - Com descritor */
Pilha CriarPilhaEncDescr () {
	Pilha p;
	
	p.celula = NULL;
	p.tamanho = 0;

	return p;
}

bool inicializarPilhaEnc(Pilha *p) {
	bool sucesso;

	sucesso = false;
	p->celula = NULL;
	p->tamanho = 0;
	
	sucesso = true;
	return sucesso;
}

int tamanhoPilhaEnc(Pilha p) {

	return p.tamanho;
}

bool consultarPilhaEnc(Pilha p, Celula *topo) {
	bool sucesso;
	
	sucesso = false;
	if (p.celula != NULL) {
		topo = p.celula;
		sucesso = true;
	}

	return sucesso;
}

bool empilharEnc (Pilha *p, Celula y) {
	bool sucesso;
	Celula *nova;

	sucesso = false;
	nova = (Celula *) malloc (sizeof (Celula));
	*nova = y;
	nova->seg = p->celula;
	p->celula = nova;
	p->tamanho++;
	
	sucesso = true;
	return sucesso;
}

Celula desempilharEnc (Pilha *p) {
	Celula desempilhada, *q;

	q = p->celula;
	desempilhada = *q;
	p->celula = q->seg;
	free (q);

	return desempilhada;
}

void DestruirPilhaEnc (Pilha *p) {
	Celula *aux;

	while (p->celula != NULL) {
		aux = p->celula;
		p->celula = p->celula->seg;
		free(aux);
	}
}

int BemFormadaEnc (char s[]) {
}

char *InfixaParaPosfixaEnc (char infix[]) {
}

bool temNegativoPilhaEnc(Pilha p) {
}

bool temNumPilhaEnc(Pilha p, int x) { 
}

void interseccionarPilhaEnc(Pilha *p) { 
}

void concatenarPilhasEnc(Pilha *p, Pilha *q) {   // intercala dados iguais das PilhasEnc
}

void mesclarPilhasEnc(Pilha *p, Pilha *q) {   // ignora dados iguais das PilhasEnc
}

void ordenarPilhaEnc(Pilha *p) { 
}

void aumentarTorre(Pilha *p, int x) { 
}

void removerDaTorre(Pilha *p, int x) { 
}

void moverTorre(Pilha *p, Pilha *q) { 
}

void intercalarTorres(Pilha *p, Pilha *q) {  // intercala dados iguais das Torres
}

void mesclarTorres(Pilha *p, Pilha *q) {  // ignora dados iguais da Torres
}

void balancearTorres(Pilha *p, Pilha *q) { 
}


/* Edição de textos */

void inserirFigura() {
}

void mudaCorPalavra() {
}

void apagarParagrafo() {
}

void justificar() {
}

void desfazer() {
}

void refazer() {
}

// Fim da biblioteca Arvore.h
