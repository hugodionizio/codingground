//    Implemente   uma   árvore   PATRICIA   para   o   alfabeto   (em   ASCII)  {a,   b,   ...,   z},   contendo   as\
operações de busca && inserção.

// Método útil para tratamento de chaves de tamanho variável extremamente longas.
// Ideia: Juntar nós de ziguezague em um só.
// Requisito: Nós são rotulados com essa informação.\
   Implementação: cada nó tem um campo a mais indicando o 1° bit diferente.
// Método: Baseado na pesquisa digital:\
	
// Procedimento inicial: É construída a partir da árvore binária de prefixo.
// Procedimentos gerais:\
	Eliminar o problema de caminhos de uma só direção
//		Cada nó interno da árvore contém o índice do caractere a ser testado para decidir qual subárvore seguir.
//		if (duas chaves tiverem um prefixo comum, a representação na árvore é feita a partir do 1° bit diferente.

struct pt {
	int r;
	esq, dir
};

// algoritmo 9.1: Busca digital
void buscaDigital(x, pt, l, a) {
	if (l < k)
		seja j a posição de d(l + 1) na ordenação do alfabeto
		if (pt->pont[j] != lambda)
			pt = pt->pont[j]; l = l + 1;
			buscaDigital(x, pt, l, a);
		else if pt->info == terminal) a = 1;
}

// algoritmo 9.2: Inclusão em árvore digital
pt = ptraiz; f = a = 0;
buscaDigital(x, pt, f, a);
if (se a == 0) 
	for (h = f + 1; h < k; h++) {
		seja j a posição de d(h) na ordenação do alfabeto;
		ocupar(ptz);
		i.pont[i] = À;
		ptz->info = não terminal;
		for (i = 1; i < m; i++) {
			pt->pont[j] = ptz;
			pt = ptz;
			pt->info = terminal;
		}
	}
senão "inclusão inválida";

// algoritmo 9.3: Busca em árvore Patrícia
void buscaPatricia(x, ArvorePatricia pt, int a) {
	if (pt->esq == lambda) a = 1;
	else if (k < pt->r) a = 2;
		else if (d[pt->r] == 0) {
			pt = pt->esq;
			buscaPatricia(x, pt, a);
		}
			else {
				pt = pt->dir;
				buscaPatricia(x, pt, a);
			}
}

// algoritmo 9.4: Inclusão em árvore Patrícia
void inserir(ArvorePatricia *pt, int lambda) {
	int a;
	ArvorePatricia ptraiz, lambda, ptNovoY;
	int x;

	if (ptraiz == lambda) { // árvore vazia
		ocupar(pt);
		pt->r == x;
		pt->esq == pt->dir == lambda;
		ptraiz == pt;
	}
	else { // localização de y'
		ptNovoY == ptraiz;
		buscaPatricia(x, ptNovoY, a);
		while (ptNovoY->esq != lambda)
			ptNovoY == ptNovoY->esq;
			l = O;
		while (l < min(k, c) && d[l + 1] == novoD[l + 1])
			l = l + 1;	// i calculado
		if (l != min(k, c))
			ocupar(ptv); ocupar(ptw);	// criação de v && w
			ptv->r = l + 1; ptw->r = x;
			ptw->esq = ptw->dir = lambda;
			ptz = ptraiz; descer:= V;	// localização de z && q
			while (ptz->esq != lambda && descer)
				if (ptz->r <= l + 1)
					ptq:= ptz;
					if (d[ptz->r ] == 0)
						ptz = ptz->esq; esquerdo = V;
					else ptz = ptz->dir; esquerdo = F;
				else descer = F;	// z && q localizados
			if (d[l + 1] == O)
				ptv->esq = ptw;
				ptv->dir = ptz;
			else ptv->esq = ptz;
				ptv->dir = ptw;
			if (ptz == ptraiz) ptraiz = ptv;
			else if (esquerdo)
					ptq i.esq = ptv;
				else ptq->dir = ptv;
		else puts("inclusão inválida");
	}
}
