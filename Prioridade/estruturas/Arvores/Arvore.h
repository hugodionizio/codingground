// Biblioteca: Arvore.h
// Função : Criar e manipular árvores binárias
// Camada de software: Interna
// Autor(es) : EDELWEISS, Nina; GALANTE, Renata; SANTOS, Hugo Dionizio
// Data : 03-02-2013 18:24:06 
// gcc '/home/ubuntu/Público/Documents/Algoritmos/C/Testes.c' -o '/home/ubuntu/Público/Documents/Algoritmos/C/Testes.bin'

#ifndef CONIOX_H
# include "ConioX.h"
#endif

#include "Pilha.h"
typedef Celula TipoPilha;

// Seção de Variáveis Globais
typedef int TipoInfo;

struct TipoNodoLinear { //  Estrutura 3.5; Página 89 (extends Lista.h)
	TipoInfo Info;

	struct TipoNodoLinear *Prox;
};
typedef struct TipoNodoLinear * TipoPtLista;

struct TipoNodo { // Estrutura 6.1.1; Página 195
	TipoInfo Info;
	
	struct TipoNodo * Esq;
	struct TipoNodo * Dir;
};
typedef struct TipoNodo TipoNodo;
typedef TipoNodo * TipoPtNodo; // Estrutura 6.1.2; Página 195
typedef TipoPtNodo TipoArvore; // Estrutura 6.1.3; Página 195

struct TipoNodoEA { // Estrutura 6.2.1 (Árvore de Expressão Aritmética); Página 213
	int Tipo;
	char Oper;
	float Valor;
	
	struct TipoNodoEA * Esq;
	struct TipoNodoEA * Dir;
};
typedef struct TipoNodoEA TipoNodoEA;
typedef TipoNodoEA * TipoPtNodoEA; // Estrutura 6.2.2; Página 213

struct TipoNodoABP { // Estrutura 6.3.1 (Árvore Binária de Pesquisa ou Busca); Página 215
	TipoInfo Info;
	int Chave;

	struct TipoNodoABP * Esq;
	struct TipoNodoABP * Dir;
};
typedef struct TipoNodoABP TipoNodoABP;
typedef TipoNodoABP * TipoPtNodoABP; // Estrutura 6.3.2; Página 215

struct TipoNodoAVL { // Estrutura 6.4.1 (Árvore - Binária de Pesquisa - Adelson-Velskii e Landis); Página 228
	int FB; // Fator de balanceamento do nodo
	int Chave;
	TipoInfo Info;

	struct TipoNodoAVL * Esq;
	struct TipoNodoAVL * Dir;
};
typedef struct TipoNodoAVL TipoNodoAVL;
typedef TipoNodoAVL * TipoPtNodoAVL; // Estrutura 6.4.2; Página 228

// Interface da biblioteca
TipoArvore CriarArvore (); // Algoritmo 6.1; Página 195

TipoArvore AlocarRaiz (TipoInfo Valor); // Algoritmo 6.2; Página 196
bool InserirFilhoEsq (TipoArvore Arv, TipoInfo ValorPai, TipoInfo ValorFilho); // Algoritmo 6.3; Página 197
bool RemoverFolha (TipoArvore Arv, TipoInfo Valor); // Algoritmo 6.4; Página 198

void PrefixadoEsq (TipoArvore Arv); // Algoritmo 6.5; Página 204
TipoPtNodo Localizar (TipoArvore Arv, TipoInfo Valor); // Algoritmo 6.6; Página 204
/*void PosFixadoEsq (TipoArvore Arv); // Algoritmo 6.7; Página 206

void PrefixadoEsqRec (TipoArvore Arv); // Algoritmo 6.8; Página 207
void PosFixadoEsqRec (TipoArvore Arv); // Algoritmo 6.9; Página 208
void CentralEsqRec (TipoArvore Arv); // Algoritmo 6.10; Página 208

TipoInfo ObtemInfo(); // Algoritmo 6.11.0; Página 210
TipoArvore ConstruirArv (); // Algoritmo 6.11; Página 210
void FazerListaDeArv (TipoArvore arv, TipoPtLista Lista); // Algoritmo 6.12; Página 212
float ValorEA (TipoArvore Arv); // Algoritmo 6.13; Página 213

bool InserirABP (TipoPtNodoABP *Raiz, TipoPtNodoABP *Novo); // Algoritmo 6.14; Página 217
void RemoverABP (TipoPtNodoABP Arv, TipoPtNodoABP Pai, TipoPtNodoABP Raiz, int ChaveRem); // Algoritmo 6.15; Página 222

TipoPtNodoABP BuscarABP (TipoPtNodoABP Arv, int ChaveBuscada); // Algoritmo 6.16; Página 224
TipoPtNodoABP BuscarABPRec (TipoPtNodoABP Raiz, int ChaveBuscada); // Algoritmo 6.17; Página 224

TipoPtNodoAVL RotacaoDireitaAVL (TipoPtNodoAVL Pt); // Algoritmo 6.18; Página 229
TipoPtNodoAVL RotacaoEsquerdaAVL (TipoPtNodoAVL Pt); // Algoritmo 6.19; Página 231
TipoPtNodoAVL RotacaoDuplaDireitaAVL (TipoPtNodoAVL Pt); // Algoritmo 6.20; Página 234
TipoPtNodoAVL RotacaoDuplaEsquerdaAVL (TipoPtNodoAVL Pt); // Algoritmo 6.21; Página 236
TipoPtNodoAVL InserirAVL (TipoPtNodoAVL *A, int ValorChave, TipoInfo Dado, bool OK); // Algoritmo 6.22; Página 237
*/

// Seção de Funções Internas

// Relacionamento de Subordinação
// Hierarquia de especialização
// Hierarquia de composição
// Hierarquia de dependência

// Formas de representação
// Representação hierárquica
// Diagrama de inclusão ou de Venn
// Diagrama de barras ou listas
// Representação por parênteses ou aninhada
// Numeração por níveis

// Terminologia
// Nó, nodo ou vértice: estrutura de dado composto por dois ou mais elos do mesmo tipo
// Árvore enraizada: conjunto finito de nós
// Árvore vazia: conjunto finito de nós vazio
// Raiz: nó sem pai
// Ancestrais (de um nó): pai ou ancestrais do pai do nó
// Descendentes (de um nó): nós que o possuem como ancestral
// Subárvore: árvore consistindo de um nó e seus descendentes
// Subárvore parcial: árvore consistindo de um, ou alguns nós de seus descendentes
// Grau (de um nó - ou subárvore): número de filhos, ou subárvores, subordinados diretamente a este nó(do)
// Grau (de uma árvore): número de filhos ou subárvores subordinados diretamente a este nó(do)
// Nó interno ou de derivação: nó com pelo menos um filho
// Nó externo, folha ou terminal: nó sem filhos
// Nível (de um nó): nível do nó PAI, ou nívelPai(nó) + 1, nívelPai(Raiz) = 0
// Caminho: Sequência de nós consecutivos distintos entre dois nós
// Comprimento do caminho: número de níveis em um caminho, diminuído de uma unidade
// Altura ou Profundidade: nível máximo de suas folhas
// Conjunto disjunto: estrutura de dados que mantém informações sobre uma partição, divisão ou subconjunto de um conjunto S
// Floresta: Conjunto de árvores disjuntas
// Árvore ordenada: quando a ordem de suas subárvores é relevante para uma aplicação
// Árvores isomorfas: quando é possível que duas árvores não ordenadas se tornem coincidentes pela permutação da ordem de seus nós
// Árvore balanceada: quando existe uma distribuição equilibrada entre os nós da árvore
// Árvore binária ou n-ária: quando o grau da árvore é 2 ou n, onde n é para n-ária.
// Arvore estritamente binária: cada nó possui 0 ou 2 filhos
// Arvore binária completa: quando cada nó que possui subárvore vazia, está no último ou penúltimo nível da árvore
// Arvore binária cheia ou completamente balanceada: quando cada nó que possui subárvore vazia, está no último nível da árvore
// Conversão de árvores
// Conversão de florestas

TipoArvore CriarArvore () { // Algoritmo 6.1; Página 195
	TipoArvore Arv = NULL;

	return Arv;
}

TipoArvore AlocarRaiz (TipoInfo Valor) { // Algoritmo 6.2; Página 196
	TipoArvore Arv;
	TipoPtNodo PtRaiz;

	PtRaiz = (TipoPtNodo)malloc(sizeof(TipoPtNodo));
	PtRaiz->Esq = PtRaiz->Dir = NULL;
	PtRaiz->Info = Valor;
	Arv = PtRaiz;

	return Arv;
}

bool InserirFilhoEsq (TipoArvore Arv, TipoInfo ValorPai, TipoInfo ValorFilho) { // Algoritmo 6.3; Página 197
	TipoPtNodo Pai, Novo;
	bool Sucesso;

	Sucesso = false;
	Pai = Localizar(Arv, ValorPai);
	if (Pai != NULL && Pai->Esq == NULL) {
		Sucesso = true;
		Novo = (TipoPtNodo)malloc(sizeof(TipoPtNodo));
		Novo->Dir = Novo->Esq = NULL;
		Novo->Info = ValorFilho;
		Pai->Esq = Novo;
	}

	return Sucesso;
}

bool RemoverFolha (TipoArvore Arv, TipoInfo Valor) { // Algoritmo 6.4; Página 198
	TipoPtNodo Pai, Nodo;
	bool Sucesso;

	if (Arv->Info == Valor) // NODO É A RAIZ
		if (Arv->Dir == NULL && Arv->Esq == NULL) {
			free(Arv);
			Arv = NULL;
			Sucesso = true;
		}
		else {
			Sucesso = false;
		}
	else {
		Pai = LocalizarPai (Arv, Valor);
		if (Pai != NULL) {
			if (Pai->Esq != NULL && Pai->Esq->Info == Valor) { // FILHO À ESQUERDA
				Nodo = Pai->Esq;
				if (Nodo->Esq == NULL && Nodo->Dir == NULL) { // É FOLHA
					Sucesso = true;
					free(Nodo);
					Pai->Esq = NULL;
				}
				else {
					Sucesso = false;
				}
			}
			else { // FILHO À ESQUERDA
				Nodo = Pai->Dir;
				if (Nodo->Esq == NULL && Nodo->Dir == NULL) { // É FOLHA
					Sucesso = true;
					free(Nodo);
					Pai->Dir = NULL;
				}
				else {
					Sucesso = false;
				}
			}
		}
		else {
			Sucesso = false;
		}
	}

	return Sucesso;
}

void Visitar(TipoPtNodo nodo) {
}

void PrefixadoEsq (TipoArvore Arv) { // Algoritmo 6.5; Página 204
	TipoPtNodo PtAux;
	TipoPilha pilha;
	
	empilharEnc(pilha = Arv;
	while (pilha != NULL) {
		PtAux = pilha;
		if (PtAux != NULL) {
			Visitar(PtAux);
			pilha = PtAux->Dir;
			pilha = PtAux->Esq;
		}
	}
}


TipoPtNodo Localizar (TipoArvore Arv, TipoInfo Valor) { // Algoritmo 6.6; Página 204
	TipoPtNodo PtAux;
	bool Achou, InsOK, OK;
	TipoPilha Pilha;
	
	InicializarPilhaArr(Base, Topo); // VARIÁVEIS GLOBAIS
	Achou = false;
	InserirPilhaArr(Pilha, Lim, Topo, Arv, InsOK); // INSERE RAIZ NA PILHA
	while (Topo >= 0 && !Achou && InsOK) {
		RemoverPilhaArr(Pilha, Topo, Base, OK, PtAux);
		if (PtAux != NULL && OK) {
			if (PtAux->Info = Valor) {
				Achou = true;
				Localizar = PtAux;
			}
			else {
				InserirPilhaArr(Pilha, Lim, Topo, PtAux->Dir, InsOK);
				InserirPilhaArr(Pilha, Lim, Topo, PtAux->Esq, InsOK);
			}
		}
	}
	if (!Achou) {
		Localizar = NULL;
	}
	
	return PtAux;
}
/*
void PosFixadoEsq (TipoArvore Arv) { // Algoritmo 6.7; Página 206
	Pilha = Arv;

	while (Pilha != NULL) {
		PtAux = Pilha;
		if (PtAux != NULL) {
			if Marcado (PtAux) {
				Visitar(PtAux);
			}
			else {
				Pilha = Marca(PtAux);
				Pilha = PtAux->Dir;
				Pilha = PtAux->Esq;
			}
		}
	}
}


void PrefixadoEsqRec (TipoArvore Arv) { // Algoritmo 6.8; Página 207

	if (Arv != NULL) {
		Visitar(Arv);
		PrefixadoEsqRec(Arv->Esq);
		PrefixadoEsqRec(Arv->Dir);
	}
}

void PosFixadoEsqRec (TipoArvore Arv) { // Algoritmo 6.9; Página 208

	if (Arv != NULL) {
		PosFixadoEsqRec(Arv->Esq);
		PosfixadoEsqRec(Arv->Dir);
		Visitar(Arv);
	}
}

void CentralEsqRec (TipoArvore Arv) { // Algoritmo 6.10; Página 208

	if (Arv != NULL) {
		CentralEsqRec(Arv->Esq);
		Visitar(Arv);
		CentralEsqRec(Arv->Dir);
	}
}

void emNivel (TipoArvore Arv) { // Algoritmo 6.10.1; Página 177
	Fila F;

	if (Arv != NULL) {
		InicializarFila(F);	// cria uma fila fazia
		InsereNaFila(&F, Arv);	// insere a raiz na fila
		while (FilaNaoVazia(F)) { // enquanto houver um nodo na fila
			Arv = RetiraDaFila(&F);	// Arv = o primeiro da fila
			Processa(Arv);
			if (Arv->esq != NULL)
				InsereNaFila(&F, Arv->esq);	// insere Arv->esq no final da fila
			if (Arv->dir != NULL)
				InsereNaFila(&F, Arv->dir);	// insere Arv->dir no final da fila
		}
		FinalizaFila(F);	// "destrói" a fila
	}
}

// Altura de uma Árvore Binária
função AltArvBin(T: ArvBin): inteiro
declare
	hL, hR: inteiro
início
	se T ≠ nulo então
	início
		hL ← AltArvBin(T^.L)
		hR ← AltArvBin(T^.R)
		se hL > hR então
			result ← 1 + hL
		senão
			result ← 1 + hR
	fim
	senão
		result ← 0
fim

eRaiz() {
	bool Sucesso;

	Sucesso = false;
	if (celula.altura < 1) {
		Sucesso = true;
	}

	return Sucesso;
}

TipoInfo ObtemInfo() { // Algoritmo 6.11.0; Página 210
	TipoInfo Info;

	return Info;	
}

TipoArvore ConstruirArv (TipoArvore Arv) { // Algoritmo 6.11; Página 210
	TipoInfo InfoProx;
	
	InfoProx = ObtemInfo();
	if (InfoProx == "*") {
		Arv = NULL;
	}
	else {
		Arv = (TipoArvore)malloc(sizeof(TipoArvore));
		Arv->Info = InfoProx;
		ConstruirArv(Arv->Esq);
		ConstruirArv(Arv->Dir);
	}
}

void FazerListaDeArv (TipoArvore arv, TipoPtLista Lista) { // Algoritmo 6.12; Página 212
	TipoPtLista PtListaAux;
	
	if (Arv != NULL) {
		PtListaAux = (TipoPtLista)malloc(sizeof(TipoPtLista));
		PtListaAux->Info = Arv->Info;
		if (Lista == NULL) {
			PtListaAux->Prox = NULL;
		}
		else {
			PtListaAux->Prox = Lista;
		}
		Lista = PtListaAux;
		FazerListaDeArvRec(Arv->Esq, Lista);
		FazerListaDeArvRec(Arv->Dir, Lista);
	}
}

float ValorEA (TipoArvore Arv) { // Algoritmo 6.13; Página 213
	if (Arv == NULL || (Arv->Tipo != 0 && Arv->Tipo != 1)) {
		ValorEA = 0;
	}
	else {
		if (Arv->Tipo == 0) { // OPERANDO
			ValorEA = Arv->Oper;
		}
		else {
			switch (Arv->Oper) { // OPERADOR
				case '+': ValorEA = ValorEA(Arv->Esq) + ValorEA(Arv->Dir); break;
				case '-': ValorEA = ValorEA(Arv->Esq) - ValorEA(Arv->Dir); break;
				case '*': ValorEA = ValorEA(Arv->Esq) * ValorEA(Arv->Dir); break;
				case '/': ValorEA = ValorEA(Arv->Esq) / ValorEA(Arv->Dir); break;
			}
		}
	}
}


bool InserirABP (TipoPtNodoABP *Raiz, TipoPtNodoABP *Novo) { // Algoritmo 6.14; Página 217
	bool Inseriu;
	TipoPtNodoABP PAux;
	
	if (BuscarABP(Raiz, Nodo->Chave) != NULL) {
		InserirABP = false; // CHAVE JÁ EXISTENTE NA ÁRVORE
	}
	else {
		InserirABP = true;
		if (Raiz == NULL) {
			Raiz = Novo // INSERIR PRIMEIRO NODO - RAIZ
		}
		else { // BUSCA POSIÇÃO E INSERE
			PAux = Raiz;
			Inseriu = false;
			while (!Inseriu) {
				if (Novo->Chave > PAux->Chave) {
					if (PAux->Dir == NULL) {
						PAux->Dir = Novo;
						Inseriu = true;
					}
					else {
						PAux = PAux->Dir;
					}
				}
				else {
					if (PAux->Esq == NULL) {
						PAux->Esq = Novo
						Inseriu = true;
					}
					else {
						PAux = PAux->Esq;
					}
				}
			}
		}
	}
	
	return Inseriu;
}

void RemoverABP (TipoPtNodoABP Arv, TipoPtNodoABP Pai, TipoPtNodoABP Raiz, int ChaveRem) { // Algoritmo 6.15; Página 222
	TipoPtNodoABP Anterior;
	
	if (Raiz !=  NULL) {
		if (RAIZ->Chave != ChaveRem) {
			if (Raiz->Chave > ChaveRem) {
				RemoverABP(Arv, Raiz, Raiz->Esq, ChaveRem);
			}
			else {
				RemoverABP(Arv, Raiz, Raiz->Dir, ChaveRem);
			}
		}
		else { // VAI REMOVER O NODO DE ENDEREÇO RAIZ
			if (Raiz->Esq == NULL && Raiz->Dir == NULL) { // REMOVER FOLHA
				if (Raiz == Arv) {
					Arv == NULL;
				}
				else {
					if (Pai->Dir == Raiz) {
						Pai->Dir = NULL;
					}
					else {
						Pai->Esq = NULL;
					}
				}
			}
			else {
				if (Raiz->Esq == NULL || Raiz->Dir == NULL) { // NODO TEM SOMENTE UMA SUBÁRVORE
					if (Raiz->Esq == NULL) { // SUBIR SUBÁRVORE DIREITA
						if (Raiz != Arv) {
							if (Pai->Esq == Raiz) {
								Pai->Esq = Raiz->Dir;
							}
							else {
								Pai->Dir = Raiz->Dir;
							}
						}
						else {
							Arv = Raiz->Dir;
						}
					}
					else { // SUBIR SUBÁRVORE ESQUERDA
						if (Raiz != Arv) {
							if (Pai->Esq == Raiz) {
								Pai->Esq = Raiz->Esq;
							}
							else {
								Pai->Dir = Raiz->Esq;
							}
						}
						else {
							Arv = Raiz->Esq;
						}
					}
				}
				else { // NODO TEM DUAS SUBÁRVORES
					Nodo = Raiz->Esq;
					Anterior = Raiz;
					while (Nodo->Dir != NULL) {
						Anterior = Nodo
						Nodo = Nodo->Dir;
					}
					// NODO VAI SUBSTITUIR RAIZ
					if (Nodo->Esq == NULL) {
						Anterior->Dir = NULL; // É UMA FOLHA
					}
					else {
						Anterior->Dir = Nodo->Esq;
					}
					if (Raiz != Arv) {
						if (Pai->Esq = Raiz) {
							Pai->Esq = Nodo;
						}
						else {
							Pai->Fir = Nodo;
						}
					}
					else {
						Arv = Nodo;
					}
					Nodo->Esq = Raiz->Esq;
					Nodo->Dir = Raiz->Dir;
				}
			}
		}
		free(Raiz);
		Raiz = NULL;
	}
}


TipoPtNodoABP BuscarABP (TipoPtNodoABP Arv, int ChaveBuscada) { // Algoritmo 6.16; Página 224
	bool Achou;
	TipoPtNodoABP PtNodo;
	
	PtNodo = Arv;
	Achou = false;
	while (!Achou && PtNodo != NULL) {
		if (PtNodo->Chave == ChaveBuscada) {
			Achou = true;
		}
		else {
			if (PtNodo->Chave > ChaveBuscada) {
				PtNodo = PtNodo->Esq;
			}
			else {
				PtNodo = PtNodo->Dir;
			}
		}
	}
	BuscarABP = PtNodo;
	return PtNodo;
}

TipoPtNodoABP BuscarABPRec (TipoPtNodoABP Raiz, int ChaveBuscada) { // Algoritmo 6.17; Página 224
	if (Raiz == NULL) {
		BuscarABPRec = NULL;
	}
	else {
		if (Raiz->Chave == ChaveBalanceada) {
			BuscarABPRec = Raiz;
		}
		else {
			if (Raiz->Chave > ChaveBuscada) {
				BuscarABPRec = BuscarABPRec(Raiz->Esq, ChaveBuscada);
			}
			else {
				BuscarABPRec = BuscarABPRec(Raiz->Dir, ChaveBuscada);
			}
		}
	}
}


TipoPtNodoAVL RotacaoDireitaAVL (TipoPtNodoAVL Pt) { // Algoritmo 6.18; Página 229
	TipoPtNodoAVL Ptu;
	
	Ptu = Pt->Esq;
	Pt->Esq = Ptu->Dir;
	Ptu->Dir = Pt;
	Pt->FB = 0;
	Pt = Ptu;

	return Pt;
}

TipoPtNodoAVL RotacaoEsquerdaAVL (TipoPtNodoAVL Pt) { // Algoritmo 6.19; Página 231
	TipoPtNodoAVL Ptu;
	
	Ptu = Pt->Dir;
	Pt->Dir = Ptu->Esq;
	Ptu->Esq = Pt;
	Pt->FB = 0;
	Pt = Ptu;

	return Pt;
}

TipoPtNodoAVL RotacaoDuplaDireitaAVL (TipoPtNodoAVL Pt) { // Algoritmo 6.20; Página 234
	TipoPtNodoAVL Ptu, Ptv;
	
	Ptu = Pt->Esq;
	Ptv = Pt->Dir;
	Ptu->Dir = Ptv->Esq;
	Ptv->Esq = Ptu;
	Pt->Esq = Ptv->Dir;
	Ptv->Dir = Pt;
	if (Ptv->FB == 1) {
		Pt->FB = -1;
	}
	else {
		Pt->FB = 0;
	}
	if (Ptv->FB == -1) {
		Ptu->FB = 1;
	}
	else {
		Ptu->FB = 0;
	}
	Pt = Ptv;

	return Pt;
}

TipoPtNodoAVL RotacaoDuplaEsquerdaAVL (TipoPtNodoAVL Pt) { // Algoritmo 6.21; Página 236;
	TipoPtNodoAVL Pty, Ptz;
	
	Ptz = Pt->Dir;
	Pty = Pt->Esq;
	Ptz->Esq = Pty->Dir;
	Pty->Dir = Ptz;
	Pt->Dir = Pty->Esq;
	Pty->Esq = Pt;
	if (Pty->FB == -1) {
		Pt->FB = 1;
	}
	else {
		Pt->FB = 0;
	}
	if (Pty->FB == 1) {
		Ptz->FB = -1;
	}
	else {
		Ptz->FB = 0;
	}
	Pt = Pty;

	return Pt;
}

TipoPtNodoAVL InserirAVL (TipoPtNodoAVL *A, int ValorChave, TipoInfo Dado, bool OK) { // Algoritmo 6.22; Página 237
	if (A == NULL) { // INSERÇÃO
		alocar (A);
		A->Esq = A->Dir = NULL;
		A->Chave = ValorChave;
		A->Info = Dado;
		A->FB = 0;
		OK = true;
	}
	else {
		if (ValorChave == A->Chave) {
			OK = false;
		}
		else {
			if (ValorChave < A->Chave) {
				InserirAVL(A->Esq, ValorChave, Dado, OK);
				if (OK) {
					switch (A->FB) {
						case 1: A->FB = 0; break;
						case 0: A->FB = -1; break;
						case -1: BalancearEsq(A); break;
					}
				}
				else {
					InserirAVL(A->Dir, ValorChave, Dado, OK);
					if (OK) {
						switch (A->FB) {
							case -1: A->FB = 0; break;
							case 0: A->FB = 1; break;
							case 1: BalancearDir(A, OK); break;
						}
					}
				}
			}
		}
	}
	return A;
}


Algoritmo de Huffman {
	1. Construir um nodo para cada informação, associando a esta informação sua frequênci de acesso
	2. Procurar os dois menores valores contidos no conjunto de frequências de acesso a cada informação
	3. Substituir estes dois valores pela sua soma, formando um novo nodo com este valor, e sendo este nodo a raiz dos dois valores anteriormente encontrados
	4. Repetir os passos 2 e 3  até que conjunto de frequências de acesso seja reduzido a um só valor.
}
*/

// Fim da biblioteca Arvore.h
