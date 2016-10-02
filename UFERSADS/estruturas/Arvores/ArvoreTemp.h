/*
 * Arvore Binaria de Busca
 * Universidade Federal Rural do Semi-Arido
 *
 */
// Implementacao rudimentar de arvores binarias

// três buscas
// três inserções
// três remoções

#define N 200
#define PERMUTACOES 1000
#include "../Cadeias/Vector.h"

typedef struct Celula  {
	//int dado;
	void * dado; // Valor definido na implementação

	struct Celula *proxima;
} Celula;
typedef Celula * PtCelula;

// Registro que armazena um valor (chave) e ponteiros para filhos do no
typedef struct NoAB {
	int chave;

	struct NoAB *fe, *fd; // Filhos esquerdo e direito
} NoAB;
typedef NoAB * PtNoAB;

typedef struct No {
	int chave;
	unsigned freq;

	struct No *esq, *dir;
} No;
typedef No * PtNo;

typedef struct Pilha {
	int tamanho; // Tamanho do arranjo ou encadeamento
	int base; // Posição da base no arranjo
	int topo; // Posição do topo no arranjo

	Celula *celula; // Célula para arranjos ou encadeamento
} Pilha;
typedef Pilha * PtPilha;

typedef struct Fila {
	int tamanhoAtual;
	PtCelula frente;
	PtCelula fim;
//	void * frente;
//	void * fim;
} Fila;

typedef struct CelulaTmp {
	int num;

	struct CelulaTmp *left;
	struct CelulaTmp *right;
} CelulaTmp;
typedef CelulaTmp * PtCelulaTmp;

typedef struct Ponte {

	CelulaTmp *CelulaTmp;
	struct Tipo *next;
} Ponte;
typedef Ponte * PtPonte;

typedef struct Descritor {
	int tamanho;
	int altura;
} Descritor;

typedef struct Raiz {
	unsigned profundidade;
} Raiz;
typedef Raiz * PtRaiz;

// Protótipos
bool InicializarPilha(Pilha *);
bool PilhaVazia(Pilha);
bool empilhar(PtPilha, void *y);
void * topo(Pilha);
void * desempilhar(PtPilha);
void destruirPilha(PtPilha p);

bool InicializarFila(Fila *);	// cria uma fila fazia
bool InsereNoABNaFila(Fila *, NoAB); // insere a raiz na fila
bool FilaNaoVazia(Fila); // enquanto houver um nodo na fila
NoAB RetiraNoABDaFila(Fila *);	// p = o primeiro da fila
bool FinalizaFila(Fila *);	// "destrói" a fila

NoAB *criarNoAB(int valor); // Cria um novo no dinamicamente e retorna um ponteiro para o mesmo
void destruirNoAB(PtNoAB);
bool ArvoreVazia(NoAB *p);
void visitaNoAB(NoAB *p); // visitaNoAB o nó AB
void preOrdem(NoAB *p); // Percurso pre-ordem: visitaNoAB o no, depois percorre cada filho
void posOrdem(NoAB *p); // Percurso pos-ordem: percorre cada filho, depois visitaNoAB o no
void emOrdemNoAB(NoAB *p); // Percurso em-ordem: percorre filho esq., visitaNoAB o no, percorre filho dir.
int alturaNoAB (PtNoAB);
void visitaNivel(PtNoAB, int);
void emNivelIterativo(PtNoAB);
void emNivelRecursivo(PtNoAB);
void emNivel(NoAB *); // Percurso em nível: percorre filho esq., visitaNoAB o no, percorre filho dir.

No * criarNo(int chave); // Funcao auxiliar: cria um novo no com a chave dada
void inserir(No * arvore, int chave); // Inserção de nó com chave
No * buscar(No *arvore, int chave); // Desce pela arvore ate encontrar o elemento ou chegar a um
									// ponteiro NULL
No * maior(No *p);	// Retorna um ponteiro para o maior elemento da (sub-)arvore com
					// raiz apontada pelo parametro p
void remover(No * no, int chave); // Encontra e remove o elemento com a chave fornecida.
void visitaNo(No *no); // Funcao auxiliar utilizada para imprimir dados durante um percurso
void emOrdemNo(No *no); // Efetua um percurso em-ordem
void destruir(No *p); // Efetua percurso pos-ordem, deletando nos
int calcularAltura(No *p); // Calcula recursivamente a altura da arvore cuja raiz e' p
void troca(int *a, int *b); // Funcao auxiliar: troca dois valores
void inicializarNo(No *no, int x, unsigned freq) {
    no->chave = x;
    no->freq = freq;
}
void Huffman (VetorInt vetor) {
    No vetorNo[vetor.tamanho];

	//1. Construir um nodo para cada informação, associando a esta informação sua frequênci de acesso

	//2. Procurar os dois menores valores contidos no conjunto de frequências de acesso a cada informação
	//3. Substituir estes dois valores pela sua soma, formando um novo nodo com este valor, e sendo este nodo a raiz dos dois valores anteriormente encontrados
	//4. Repetir os passos 2 e 3  até que conjunto de frequências de acesso seja reduzido a um só valor.
}

// Função para testes
bool testeArvore (int argc, char **argv) {
	bool teste;

	teste = false;

	return teste;
}

// Funções
bool InicializarPilha(Pilha *p) { // cria uma fila fazia
	bool sucesso;

	sucesso = false;
	p->tamanho = 0;
	p->base = 0;
	p->topo = 0;
	p->celula = NULL;
	sucesso = true;

	return sucesso;
}

bool PilhaVazia(Pilha p) {
	bool sucesso;

	sucesso = false;
	if (p.tamanho == 0)
		sucesso = true;
	return sucesso;
}

bool empilhar(PtPilha p, void *y) {
	bool sucesso;
	Celula *nova;

	sucesso = false;
	if (y) {
		nova = (Celula *) malloc (sizeof (Celula));
		nova->dado = y;
		nova->proxima = p->celula;
		p->celula = nova;
		p->tamanho++;
		sucesso = true;
	}
	return sucesso;
}

void *topo(Pilha p) {
	PtCelula topoP;
	topoP = (PtCelula)malloc(sizeof(Celula));

	if (p.celula != NULL) {
		topoP = p.celula;
	}

	return topoP->dado;
}

void *desempilhar(PtPilha p) {
	//PtCelula q;
	void *desempilhada;

	if (p->celula != NULL) {
		//q = p->celula;
		desempilhada = p->celula->dado;
		p->celula = p->celula->proxima;
		p->tamanho--;
	}

	return desempilhada;
}

void destruirPilha(PtPilha p) {
	while (p->celula != NULL) {
		desempilhar(p);
	}
}

bool InicializarFila(Fila *f) { // cria uma fila fazia
	bool sucesso;

	sucesso = false;
	f->tamanhoAtual = 0;
	f->frente = NULL;
	f->fim = NULL;
	sucesso = true;

	return sucesso;
}

bool InsereNoABNaFila(Fila *f, NoAB no) { // insere a raiz na fila
	bool sucesso;
	Celula *nova, y;
	//PtNoAB nova;

	sucesso = false;
	y.dado = (int *)no.chave;
	nova = (Celula *) malloc (sizeof (Celula));
	//nova = (PtNoAB) malloc (sizeof (NoAB));
	*nova = y;
	nova->proxima = f->frente;
	//nova->proxima = (PtNoAB)f->fe;
	f->frente = nova;
	if (f->frente == NULL) f->fim = NULL;
	f->tamanhoAtual++;
	sucesso = true;

	return sucesso;
}

bool FilaNaoVazia(Fila f) { // enquanto houver um nodo na fila
	bool sucesso;

	sucesso = false;
	if (f.frente != NULL) sucesso = true;

	return sucesso;
}

NoAB RetiraNoABDaFila(Fila *f) { // p = o primeiro da fila
	NoAB removido;
	//PtNoAB aux, removido;
	PtCelula aux;

	aux = f->frente;
	//aux = (PtNoAB)f->frente;
	removido.chave = (int)f->frente->dado;
	//removido = (PtNoAB)f->frente;
	f->frente = aux->proxima;
	free(aux);
	if (f->frente == NULL) f->fim = NULL;
	f->tamanhoAtual--;

	return removido;
}

bool FinalizaFila(Fila *f) { // "destrói" a fila
	bool sucesso;

	sucesso = false;
	sucesso = true;

	return sucesso;
}

NoAB *criarNoAB(int valor) {
	NoAB *pNo = (NoAB *)malloc(sizeof(NoAB));

	pNo->chave = valor;
	pNo->fe = NULL;
	pNo->fd = NULL;

	return pNo;
}

void destruirNoAB(PtNoAB p) {
	if (p == NULL) return;
	destruirNoAB(p->fe);
	destruirNoAB(p->fd);
	free(p);
	p = NULL;
}

bool ArvoreVazia(NoAB *p) {
	bool sucesso;

	sucesso = false;
	if (p != NULL)
		sucesso = true;

	return sucesso;
}

// visitaNoAB o nó AB
void visitaNoAB(NoAB *p) {
	if (p != NULL)
		printf ("  %d", p->chave);
}

// Percurso pre-ordem: visitaNoAB o no, depois percorre cada filho
void preOrdem(NoAB *p) {
	// Se "p" nao apontar para um no valido, saimos da funcao
	if (p == NULL) return;

	// Caso contrario, prosseguimos:
	visitaNoAB( p );     // "visitar" o no
	preOrdem(p->fe); // Aplicar o mesmo procedimento ao filho esquerdo
	preOrdem(p->fd); // Aplicar o mesmo procedimento ao filho direito
}

// Percurso pos-ordem: percorre cada filho, depois visitaNoAB o no
void posOrdem(NoAB *p) {
	// Se "p" nao apontar para um no valido, saimos da funcao
	if (p == NULL) return;

	// Caso contrario, prosseguimos:
	posOrdem(p->fe); // Aplicar o mesmo procedimento ao filho direito
	posOrdem(p->fd); // Aplicar o mesmo procedimento ao filho esquerdo
	visitaNoAB( p );     // "visitar" o no
}

// Percurso em-ordem, ordem simétrica ou central: percorre filho esq., visitaNoAB o no, percorre filho dir.
void emOrdemNoAB(NoAB *p) {
	// Se "p" nao apontar para um no valido, saimos da funcao
	if (p == NULL) return;

	// Caso contrario, prosseguimos:
	emOrdemNoAB(p->fe); // Aplicar o mesmo procedimento ao filho esquerdo
	visitaNoAB( p );     // "visitar" o no
	emOrdemNoAB(p->fd); // Aplicar o mesmo procedimento ao filho direito
}

/* Calcula a "altura" de uma árvore -- o número de nós
	pertencentes ao maior caminho da raíz até o nó mais
	distante.*/
int alturaNoAB (PtNoAB p) {
	if (p != NULL) {
		int altEsq = alturaNoAB(p->fe);
		int altDir = alturaNoAB(p->fd);
		if (altEsq > altDir)
			return 1 + altEsq;
		else
			return 1 + altDir;
	}
	return 0;
}

/* Visita os nós de um dado nível */
void visitaNivel(PtNoAB p, int nivel) {
  // Se "p" nao apontar para um no valido, saimos da funcao
	if (p == NULL) return;

	// Caso contrario, prosseguimos:
	if (nivel == 1)
		visitaNoAB( p );	// "visitar" o nó raiz
	else if (nivel > 1)	{
		visitaNivel(p->fe, nivel-1); // Aplicar o mesmo procedimento ao filho esquerdo
		visitaNivel(p->fd, nivel-1); // Aplicar o mesmo procedimento ao filho direito
	}
}

// Percurso em nível: percorre todos os nós existentes em cada nível.
void emNivelIterativo(PtNoAB p) {

    if (p == NULL)  return;   // NULL check

    // Cria duas pilhas para armazenar níveis alternados
    Pilha s1;  // Para níveis visitados da direita para a esquerda
    Pilha s2;  // Para níveis visitados da esquerda para a direita
    PtNoAB temp;
    int h = alturaNoAB(p), nivel;

	InicializarPilha(&s1);
	InicializarPilha(&s2);
	empilhar(&s1, p);

    for(nivel=1; nivel<=h; nivel++) {
    	// Se "p" nao apontar para um no valido, saimos da funcao
		if (PilhaVazia(s1) && PilhaVazia(s2)) break;
		// Caso contrario, prosseguimos:
		if (nivel == 1) {
			temp = (PtNoAB)topo(s1);
			visitaNoAB( temp );	// "visitar" o nó raiz
			desempilhar(&s1);
			empilhar(&s1, temp->fd);
			empilhar(&s1, temp->fe);
		}
		else if (nivel > 1)	{
			// Visitar e realocar nós de s1 para s2
			while (!PilhaVazia(s1)) {
				temp = (PtNoAB)topo(s1);
	            empilhar(&s2, desempilhar(&s1));
	            visitaNoAB (temp);
			}

			// Expandir próximo nível dos nós de s2 para s1
			while (!PilhaVazia(s2)) {
				temp = (PtNoAB)topo(s2);
	            empilhar(&s1, temp->fd);
	            empilhar(&s1, temp->fe);
	            desempilhar(&s2);
			}
		}
    }
    destruirPilha(&s1);
    destruirPilha(&s2);
}

void emNivelRecursivo(PtNoAB p) {
  int h = alturaNoAB(p);
  int i;

  for(i=1; i<=h; i++)
    visitaNivel(p, i);
}

// Percurso em nível: percorre todos os nós existentes em cada nível.
void emNivel(PtNoAB p) {
	puts("recursivo: ");
	emNivelRecursivo(p);

	puts("\niterativo: ");
	emNivelIterativo(p);
}

// Funcao auxiliar: cria um novo no com a chave dada
No * criarNo(int chave) {
	No * novo = (No *)malloc(sizeof(No));
	novo->chave = chave;
	novo->esq = NULL;
	novo->dir = NULL;
	return novo;
}

// Inserção de nó com chave
void inserir(No *arvore, int chave) {
	if (arvore == NULL)
		arvore = criarNo(chave);
	else {
		if (chave <= arvore->chave)
			inserir(arvore->esq, chave);
		else
			inserir(arvore->dir, chave);
	}
}

// Desce pela arvore ate encontrar o elemento ou chegar a um
// ponteiro NULL
No * buscar(No *arvore, int chave) {
	if (arvore != NULL) {
		if (chave < arvore->chave) return buscar(arvore->esq, chave);
		if (chave > arvore->chave) return buscar(arvore->dir, chave);
		return arvore; // se chave == arvore->chave
	}
	return NULL;
}

// Retorna um ponteiro para o maior elemento da (sub-)arvore com
// raiz apontada pelo parametro p
No * maior(No *p) {
	if (p == NULL) return NULL;
	if (p->dir != NULL) return maior(p->dir);
	return p;
}

/* Encontra e remove o elemento com a chave fornecida.
 * Caso nao exista elemento com aquela chave, nenhuma alteracao e' feita.
 * Dependendo do numero de filhos do no fornecido, teremos um dos 3 casos:
 * 1. elemento e' uma folha => apagar elemento;
 * 2. elemento possui apenas um filho => desviar ponteiro do pai do elemento,
 *    fazendo-o apontar para o unico filho;
 * 3. elemento possui dois filhos => trocar elemento de posicao com seu
 *    "antecessor" na arvore e chamar a funcao recursivamente para apagar
 *    elemento (nesta segunda chamada, recairemos no caso 1 ou 2 acima.
 * Notar que o parametro "no" e' passado por referencia para que possa
 * ser modificado.
 */
void remover(No *no, int chave) {
	No *aux, *antecessor;
	if (no == NULL) return;
	if (no->chave > chave) return remover(no->esq, chave);
	if (no->chave < chave) return remover(no->dir, chave);

	// Obter o numero de filhos do no
	int filhos = (no->esq?1:0) + (no->dir?1:0);

	switch (filhos) {
	case 0: // Se no e' uma folha
		free(no);
		no = NULL;
		break;
	case 1: // Se no possui um apenas filho
		if (no->esq != NULL) { // Se esse filho for o esquerdo
			aux = no->esq;
			free(no);
			no = aux;
		}
		else { // Se esse filho for o direito
			aux = no->dir;
			free(no);
			no = aux;
		}
		break;
	case 2: // Se no possui dois filhos
		// Obter ponteiro para antecessor
		// (antecessor e' o maior elemento da subarvore esquerda)
		antecessor = maior(no->esq);
		// Troca dados entre no atual e seu antecessor
		no->chave = antecessor->chave;
		antecessor->chave = chave;
		// Requisita a remocao do elemento na subarvore para onde
		// ele foi movido
		remover(no->esq, chave);
	}
}

// Funcao auxiliar utilizada para imprimir dados durante um percurso
void visitaNo(No *no) {
	if (no != NULL) {
		printf("%d\n", no->chave);
	}
}

// Efetua um percurso em-ordem
void emOrdemNo(No *no) {
	if (no == NULL) return;
	emOrdemNo(no->esq);
	visitaNo(no);
	emOrdemNo(no->dir);
}

// Efetua percurso pos-ordem, deletando nos
void destruir(No *p) {
	if (p == NULL) return;
	destruir(p->esq);
	destruir(p->dir);
	free(p);
	p = NULL;
}

// Calcula recursivamente a altura da arvore cuja raiz e' p
int calcularAltura(No *p) {
	if (p != NULL) {
		int altEsq = calcularAltura(p->esq);
		int altDir = calcularAltura(p->dir);
		if (altEsq > altDir)
			return 1 + altEsq;
		else
			return 1 + altDir;
	}
	return -1;
}

// Funcao auxiliar: troca dois valores
void troca(int *a, int *b) {
	int *aux = a;
	a = b;
	b = aux;
}
