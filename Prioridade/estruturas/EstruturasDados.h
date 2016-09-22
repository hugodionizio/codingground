﻿// Tipos Abstratos de Dados
TipoPtNovoAVL == ^TipoNodoAVL
TipoNodoAVL == registro
	FB: inteiro) {fator de balanceamento do nodo}
	Chave: inteiro
	Info: TipoInfo
	Esq, Dir: TipoPtNodoAVL
	} registro

Inversão de uma sequência	// algoritmo 1.1
fatorial (recursivo)	// algoritmo 1.2
fatorial (não recursivo)	// algoritmo 1.3
Torre de Hanói	// algoritmo 1.4
Soma de matrizes	// algoritmo 1.5
Produto de matrizes	// algoritmo 1.6
Busca insegura de um elemento na lista L	// algoritmo 2.1
Busca segura de um elemento na lista L	// algoritmo 2.2
Busca de um elemento na lista L, ordenada	// algoritmo 2.3
Busca binária	// algoritmo 2.4
Inserção de um nó na lista L	// algoritmo 2.5
Remoção de um nó da lista L	// algoritmo 2.6
Inserção na pilha P	// algoritmo 2.7
Remoção da pilha P	// algoritmo 2.8
Inserção na fila F	// algoritmo 2.9
Remoção da fila F	// algoritmo 2.10
Conversão de notações	// algoritmo 2.11
Busca de um elemento na LED	// algoritmo 2.12
Devolução de um nó à LED	// algoritmo 2.13
Impressão da lista apontada por ptlista	// algoritmo 2.14
Busca em uma lista ordenada	// algoritmo 2.15
Inserção de um nó após o nó apontado por ant	// algoritmo 2.16
Remoção do nó apontado por pont na lista	// algoritmo 2.17
Inserção na pilha	// algoritmo 2.18
Remoção da pilha	// algoritmo 2.19
Inserção na fila	// algoritmo 2.20
Remoção da fila	// algoritmo 2.21
Ordenação por distribuição	// algoritmo 2.22
Busca numa lista circular encadeada ordenada	// algoritmo 2.23
Busca em uma lista duplamente encadeada ordenada	// algoritmo 2.24
Inserção de um nó em uma lista duplamente encadeada	// algoritmo 2.25
Remoção de um nó em uma lista duplamente encadeada	// algoritmo 2.26
Ordenação topológica	// algoritmo 2.27
Reserva de um bloco de tamanho b	// algoritmo 2.28
Liberação de um bloco	// algoritmo 2.29
Percurso em pré-ordem	// algoritmo 3.1
Percurso em ordem simétrica	// algoritmo 3.2
Percurso em pós-ordem	// algoritmo 3.3
Cálculo da altura de um nó da árvore binária	// algoritmo 3.4
Conversão de uma árvore qualquer em árvore binária	// algoritmo 3.5
Pesquisa do sucessor	// algoritmo 3.6
Pesquisa do antecessor	// algoritmo 3.7
Busca em árvore binária de busca	// algoritmo 4.1
Inserção em árvore binária de busca	// algoritmo 4.2
Árvore binária ótima	// algoritmo 4.3
Busca em árvore binária de partilha	// algoritmo 4.4
Busca em árvore AVL	// algoritmo 5.1
Inserção em árvore AVL	// algoritmo 5.2
RotaçãoDireitaAVL	// *algoritmo 5.2.1
RotaçãoEsquerdaAVL	// *algoritmo 5.2.2
RotaçãoDuplaDireitaAVL	// *algoritmo 5.2.3
RotaçãoDuplaEsquerdaAVL	// *algoritmo 5.2.4
Busca da chave x numa árvore B	// algoritmo 5.3
Subir por um caminho da árvore	// algoritmo 6.1
Descer por um caminho da árvore	// algoritmo 6.2
Inserção em uma lista de prioridades	// algoritmo 6.3
Remoção de um elemento da lista de prioridades	// algoritmo 6.4
Construção da lista de prioridades	// algoritmo 6.5
Construção da lista de prioridades	// algoritmo 6.6
Ordenação de T	// algoritmo 6.7
descer na árvore	// algoritmo 6.8
descer a partir de um nível mínimo	// algoritmo 6.9
subir na árvore	// algoritmo 6.10
subir a partir de um nível mínimo	// algoritmo 6.11
geração da coleção de conjuntos	// algoritmo 7.1
determinar o nome do conjunto ao qual x pertence	// algoritmo 7.2
fusão de conjuntos	// algoritmo 7.3
Compressão de caminhos	// algoritmo 7.4
Separação de caminhos	// algoritmo 7.5
Divisão de caminhos	// algoritmo 7.6
Busca por encadeamento interior	// algoritmo 8.1
Inserção por encadeamento interior	// algoritmo 8.2
Remoção por encadeamento interior	// algoritmo 8.3
busca por endereçamento aberto	// algoritmo 8.4
calcular o endereço da chave x	// algoritmo 8.5
Expansão do compartimento p	// algoritmo 8.6
Busca digital	// algoritmo 9.1
Inclusão em árvore digital	// algoritmo 9.2
Busca em árvore Patrícia	// algoritmo 9.3
Inclusão em árvore Patrícia	// algoritmo 9.4
Casamento de cadeias (Força Bruta)	// algoritmo 10.1
Casamento de cadeias (KMP - Knuth, Morris e Pratt)	// algoritmo 10.2
Determinação do vetor d	// algoritmo 10.3
construção da árvore de Huffman	// algoritmo 10.4

Algoritmos

Inversão de uma sequência	// algoritmo 1.1
for (i = 1, ..., piso(n/2)) {
	temp = S[i]
	S[i] = S[n - i + 1]
	S[n - i + 1] = temp
}Para

fatorial (recursivo)	// algoritmo 1.2
função fatorial(i)
	fat(i) = if (i <= 1) { 1 else i * fat(i - 1) }
}Função(fatorial(i))

fatorial (não recursivo)	// algoritmo 1.3
	fat[O] = 1
	for (j = 1, ..., n) {
		fat[j] = j * fat[j - 1]

Torre de Hanói	// algoritmo 1.4
procedimento hanoi(n, A, B, C)
	if (n > O) {
		hanoi(n - 1, A, C, B)
		mover o disco do topo de A para B
		hanoi(n - 1, C, B, A)
	}
}Procedimento

Soma de matrizes	// algoritmo 1.5
for (i = 1, ..., n) {
	for (j = 1, ..., n) {
		c[i][j] = a[i][j] + b[i][j]
	}Para[j]
}Para[i]

Produto de matrizes	// algoritmo 1.6
for (i = 1, ..., n) {
	for (j = 1, ..., n) {
		c[i][j] = 0
		for (k = 1, ..., n) {
			cij = cij + aik * bkj

Busca insegura de um elemento na lista L	// algoritmo 2.1
função busca1(x)
	i = 1; busca1 = O
	while (i <= n) {
		if (L[i].chave == x) {
			busca1 = i		// chave encontrada
			i = n + 1
		else i = i + 1
			// pesquisa prossegue

Busca segura de um elemento na lista L	// algoritmo 2.2
função busca(x)
	L[n + 1].chave = x; i = 1
	while (L[i].chave != x) {
		i = i + 1
		if (i != n + 1) {
			busca = i		// elemento encontrado
		else busca = O		// elemento não encontrado

Busca de um elemento na lista L, ordenada	// algoritmo 2.3
função busca-ord(x)
	L[n + 1].chave = x; i = 1
	while (L[i].chave < x) {
		i = i + 1
	if (i == n + 1 ou L[i].chave != x) {
		busca-ord = O
	else busca-ord = i

Busca binária	// algoritmo 2.4
função busca-bin(x)
	inf = 1; sup = n; busca-bin = O
	while (inf <= sup) {
		meio= piso((inf + sup)/2)		// índice a ser buscado
		if (L[meio].chave == x) {
			busca-bin = meio		// elemento encontrado
			inf = sup + 1
		else if (L[meio].chave < x) {
				inf = meio + 1
			else sup = meio - 1

Inserção de um nó na lista L	// algoritmo 2.5
if (n < M) {
	if (busca(x) == O) {
		L[n + 1] = novo-valor
		n= n + 1
	else "elemento já existe na tabela"
else overflow

Remoção de um nó da lista L	// algoritmo 2.6
if (n != O) {
	indice = busca(x)
	if (indice !=- O) {
		valor-recuperado = L[indice]
		for (i = indice, n - 1) {
			L[i] = L[i + 1]
		n = n - 1
	else "elemento não if (encontra na tabela"
else underflow

Inserção na pilha P	// algoritmo 2.7
if (topo != M) {
	topo = topo + 1
	P[topo] = novo-valor
else overflow

Remoção da pilha P	// algoritmo 2.8
if (topo != O) {
	valor-recuperado = P[topo]
	topo = topo - 1
else underflow

Inserção na fila F	// algoritmo 2.9
prov = r mod M + 1
if (prov != f) {
	r = prov
	F[r] = novo-valor
	if (f == O) {
		f= 1
else overflow

Remoção da fila F	// algoritmo 2.10
if (f != O) {
	valor-recuperado = F[J]
	if (f == r) {
		f = r = O
	else f = f mod M + 1
else underflow

Conversão de notações	// algoritmo 2.11
indexp = 1; indpol: == O		// índices das expressões
topo = O
while (indexp <= }) {
	if (exp[indexp] é operando) {
		indpol = indpol + 1		// passa para a nova lista
		pol[indpol] = exp[indexp]
	else if (exp[indexp] é operador) {
			topo = topo + 1		// coloca na pilha
			pilha[topo] = exp[indexp]
		else if (exp[indexp] == ")") {
			if (topo != O) {	// forma a operação
				operador = pilha[topo]
				topo = topo - 1
				indpol = indpol + 1
				pol[indpol] = operador
			else "expressão errada"
	indexp = indexp + 1

Busca de um elemento na LED	// algoritmo 2.12
procedimento ocupar(pt)
	if (vago != lambda) {
		pt = vago
		vago= M[vago].prox
	else overflow

Devolução de um nó à LED	// algoritmo 2.13
procedimento desocupar(pt)
	M[pt].prox = vago
	vago = pt

Impressão da lista apontada por ptlista	// algoritmo 2.14
pont = ptlista
while (pont !=) {
	imprimir(pont->info)
	pont = pont->prox

Busca em uma lista ordenada	// algoritmo 2.15
procedimento busca-enc(x, ant, pont)
	ant = ptlista; pont = lambda
	ptr = ptlista->prox		// ptr: ponteiro de percurso
	while (ptr != lamdba) {
		if (ptr->chave < x) {
			ant = ptr		// atualiza ant e ptr
			ptr = ptr->prox
		else if (ptr->chave == x) {
				pont = ptr		// chave encontrada
			ptr = lambda

Inserção de um nó após o nó apontado por ant	// algoritmo 2.16
busca-enc(x, ant, pont)
if (pont == lambda) {
	ocupar(pt)		// solicitar nó
	pt->info = novo-valor		// inicializar nó
	pt->chave = x; pt->prox = ant->prox
	ant->prox = pt		// acertar lista
else "elemento já está na tabela"

Remoção do nó apontado por pont na lista	// algoritmo 2.17
busca-enc(x, ant, pont)
if (pont != lambda) {
	ant->prox = pont->prox			// acertar lista
	valor-recuperado = pont->info		// utilizar nó
	desocupar(pont)				// devolver nó
else "nó não if (encontra na tabela"

Inserção na pilha	// algoritmo 2.18
ocupar(pt)
pt->info = novo-valor		// solicitar nó
pt->prox = topo		// inicializar nó
topo = pt		// acertar pilha

Remoção da pilha	// algoritmo 2.19
if (topo != lambda) {
	pt = topo				// acertar pilha
	topo = topo->prox
	valor-recuperado = pt->info		// utilizar nó
	desocupar(pt)				// devolver nó
else underflow

Inserção na fila	// algoritmo 2.20
ocupar(pt)			// solicitar nó
pt->info = novo-valor		// inicializar nó
pt->prox = lambda
if (} != lambda) {		// acertar fila
	}->prox = pt
else { = pt
} = pt

Remoção da fila	// algoritmo 2.21
if ({ != lambda) {
	pt = {
	{ = {->prox			// acertar fila
	if ({ == lambda) { } = lambda
	valor-recuperado = pt->info		// utilizar nó
	desocupar(pt)				// devolver nó
else underflow

Ordenação por distribuição	// algoritmo 2.22
for (i == 1, ..., d) {
	for (j == 1, ..., n) {
		k = i-ésimo dígito menos significativo da representação de L[j].chave na base b
		Fk <= L[j]
	j= 1
	for (k == 0, ..., b - 1) {
		while (Fk != NULL) {
			L[j] <= Fk
			j = j + 1

Busca numa lista circular encadeada ordenada	// algoritmo 2.23
procedimento busca-cir(x, ant, pont)
	ant = ptlista
	ptlista->chave = x
	pont = ptlista->prox
	while (pont->chave < x) {
		ant = pont
		pont = pont->prox
	if (pont != ptlista e pont->chave == x) {
		chave localizada
	else "chave não localizada"

Busca em uma lista duplamente encadeada ordenada	// algoritmo 2.24
função busca-dup(x)
	ultimo = ptlista->ant
	if (x <= ultimo->chave) {
		pont = ptlista->post
		while (pont->chave < x) {
			pont = pont->post
		busca-dup = pont
	else busca-dup = ptlista

Inserção de um nó em uma lista duplamente encadeada	// algoritmo 2.25
pont = busca-dup(x)
if (pont == ptlista ou pont->chave != x) {
	anterior = pont->ant
	ocupar(pt)			// solicitar nó
	pt->info = novo-valor		// inicializar nó
	pt->chave = x
	pt->ant = anterior
	pt->post = pont
	anterior->post = pt		// acertar lista
	pont->ant = pt
else "elemento já if (encontra na lista"

Remoção de um nó em uma lista duplamente encadeada	// algoritmo 2.26
pont = busca-dup(x)
if (pont != ptlista e pont->chave == x) {
	anterior = pont->ant
	posterior = pont->post
	anterior->post = posterior		// acertar lista
	posterior->ant = anterior
	valor-recuperado = pont->info		// utilizar nó
	desocupar(pont)				// devolver nó
else "elemento não if (encontra na lista"

Ordenação topológica	// algoritmo 2.27
procedimento inicializar
	for (i == 0, ..., n) {		// inicializa nó-cabeça
		CB[i].contador = O
		CB[i].prox = lambda
	for (i == 1, ..., m) {
		ocupar(pt)			//) { (j, k) o i-ésimo par
		pt->info = k; pt->prox = CB[j].prox
		CB[j].prox = pt
		CB[k].contador = CB[k].contador + 1

inicializar
} = O; CB[O].contador = O
for (i == 1, ..., n) {		// busca de objetos sem
	if (CB[i].contador == O) {	predecessores
		CB[}].contador = i
		}= i
objeto = CB[O].contador
while (objeto != O) {
	saida(objeto)
	pt = CB[objeto].prox
	while (pt != lambda) {
		indice = pt->info
		CB[indice].contador = CB[indice].contador - 1
		if (CB[indice].contador == O) {
			CB[}].contador = indice
			} = indice
		pt = pt->prox
	objeto = CB[objeto].contador

Reserva de um bloco de tamanho b	// algoritmo 2.28
procedimento reserva(b, pont)
	pt = M[2]; pont= lambda; ant = 1
	if (b < 2) { b = 2
	while (pt != lambda) {
		if (M[pt] >= b) {
			r = M[pt] - b		// bloco encontrado
			if (r < c) {
				pont = pt		// fragmento incorporado
				M[ant + 1] = M[pt + 1]
				b = b + r
			else M[pt] = r
				pont = pt + r
				pt= lambda
		else ant = pt
			pt = M[pt + 1]

Liberação de um bloco	// algoritmo 2.29
procedimento liberar(b, pont)
	pt = M[2]; ant= 1
	while (pt != lambda e pt < pont) {		// buscar posição do bloco
		ant = pt
		pt = M[pt + 1]
	if (pont + b == pt) {				// bloco liberado contíguo ao seguinte
		b = b + M[pt]
		M[pont + 1] = M[pt + 1]
	else M[pont + 1] = pt
	if (ant + M[ant] == pont) {
		M[ant] = M[ant] + b		// bloco liberado contíguo ao anterior
		M[ant + 1] = M[pont + 1]
	else M[ant + 1] = pont
		M[pont] = b

Percurso em pré-ordem	// algoritmo 3.1
procedimento pre(pt)
	visita(pt)
	if (pt->esq != lambda) { pre(pt->esq)
	if (pt->dir != lambda) { pre(pt->dir)
if (ptraiz != lambda) { pre(ptraiz)

Percurso em ordem simétrica	// algoritmo 3.2
procedimento simet(pt)
	if (pt->esq != lambda) { simet(pt->esq)
	visita(pt)
	if (pt->dir != lambda) { simet(pt->dir)
if (ptraiz != lambda) { simet(ptraiz)

Percurso em pós-ordem	// algoritmo 3.3
procedimento pos(pt)
	if (pt->esq != lambda) { pos(pt->esq)
	if (pt->dir != lambda) { pos(pt->dir)
	visita(pt)
if (ptraiz != lambda) { pos(ptraiz)

Cálculo da altura de um nó da árvore binária	// algoritmo 3.4
procedimento visita(pt)
	if (pt->esq != lambda) {
		alt1 = (pt->esq)->altura
	else alt1 = O
	if (pt->dir = lambda) {
		alt2 = (pt->dir)->altura
	else alt2 = O
	if (alt1 > alt2) {
		pt->altura = alt1 + 1
	else pt->altura = alt2 + 1

Conversão de uma árvore qualquer em árvore binária	// algoritmo 3.5
procedimento arvore(v, pt)
	pai = V
	for (w pertencente C[v]) {
		ocupar(ptnovo)		// solicitar e preencher novo nó
		ptnovo->esq = lambda; ptnovo->dir = lambda
		ptnovo->info = w
		if (pai) {		// inserir à esquerda
			pt->esq = ptnovo
			pai = F
		else pt->dir = ptnovo		// inserir à direita
		arvore(w, ptnovo)
		pt = ptnovo
ocupar(pt); pt->info = cabeca			// preparar nó-cabeça
pt->esq = lambda; pt->dir = lambda		// ponteiro para o nó-cabeça
ptraiz = pt
arvore(n + 1, pt)

Pesquisa do sucessor	// algoritmo 3.6
procedimento suc(ptl, pt2)
	pt2 = pt1->dir
	if (não pt1->dcostura) {
		while (não pt2->ecostura) {
			pt2 = pt2->esq

Pesquisa do antecessor	// algoritmo 3.7
procedimento pred(pt1, pt2)
	pt2 = pt1->esq
	if (não pt1->ecostura) {
		while (não pt2->dcostura
			pt2 = pt2->dir

Busca em árvore binária de busca	// algoritmo 4.1
procedimento busca-arvore(x, pt, 1)
	if (pt == lambda) { f = O
	else if (x == pt->chave) { f = 1
		else if (x < pt->chave) {
				if (pt->esq == lambda) { f = 2
				else pt = pt->esq
					busca-arvore(x, pt, f)
			else if (pt->dir == lambda) { f = 3
				else pt = pt->dir
					busca-arvore(x, pt, f)
pt = ptraiz;	busca-arvore(x, pt , f)

Inserção em árvore binária de busca	// algoritmo 4.2
pt= ptraiz; busca-arvore(x, pt, f)
if (f == 1) {
	inserção inválida
else ocupar(pt1)
	pt1->chave = x; pt1->info = novo-valor
	pt1->esq = lambda; pt1->dir = lambda
	if (f == O) { ptraiz = pt1
	else if (f == 2) {
			pt->esq = pt1
		else pt->dir = pt1

Árvore binária ótima	// algoritmo 4.3
for (j == O, ..., n) {
	c[j, j] = O; F[j, j] = f'j
for (d == 1, ..., n) {
	for (i == O, ..., n - d) {
		j = i + d
		F[i, j] = F[i, j - 1] + fj + f'j
		c[i, j] = somatório(i < k <=j, min{c[i, k - 1] + c[k, j]} + F[i, j])

Busca em árvore binária de partilha	// algoritmo 4.4
procedimento busca-partilha(x, pt)
	if (pt == lambda) {
		a chave não if (encontra no conjunto
	else if (x == pt->real) {
		chave encontrada no nó apontado por pt
		else if (x <= pt->partilha) {
			pt = pt->esq
			busca-partilha(x, pt)
		else pt = pt->dir
			busca-partilha(x, pt)
pt = ptraiz
busca-partilha(x, pt)

Busca em árvore AVL	// algoritmo 5.1
procedimento {-no(pt)
	ocupar(pt)
	pt->esq = lambda; pt->dir = lambda
	pt->chave = x; pt->bal = O

procedimento caso1(pt, h)
	ptu = pt->esq
	if (ptu->bal == -1) {
		pt->esq = ptu->dir; ptu->dir = pt
		pt->bal = O; pt = ptu
	else ptv = ptu->dir
		ptu->dir = ptv->esq; ptv->esq = ptu
		pt->esq = ptv->dir; ptv->dir = pt
		if (ptv->bal == -1) { pt->bal = 1 else pt->bal = O
		if (ptv->bal == 1) { ptu->bal = -1 else ptu->bal = O
		pt = ptv
	pt->bal = O; h= F

procedimento caso2(pt, h)
	ptu = pt->dir
	if (ptu->bal == 1) {
		pt->dir = ptu->esq; ptu->esq = pt
		pt->bal = O; pt = ptu
	else ptv = ptu->esq
		ptu->esq = ptv->dir; ptv->dir = ptu
		pt->dir = ptv->esq; ptv->esq = pt
		if (ptv->bal == 1) { pt->bal = -1 else pt->bal = O
		if (ptv->bal == -1) { ptu->bal = 1 else ptu->bal = O
		pt = ptv
	pt->bal = O; h = F

procedimento ins-AVL(x, pt, h)
	if (pt == lambda) {
		início-no(pt)
		h = V
	else if (x == pt->chave) { break;
		if (x < pt->chave) {
			ins-AVL(x,pt->esq,h)
			if (h) {
				switch (pt->bal) {
				1: pt->bal = O; h = F
				O: pt->bal = -1
				-1: caso1(pt, h)		// rebalanceamento
		else ins-AVL(x, pt->dir, h)
			if (h) {
				switch (pt->bal) {
				-1: pt->bal = O; h = F
				O: pt->bal : == 1
				1: caso2(pt, h)		// rebalanceamento

Inserção em árvore AVL	// algoritmo 5.2

RotaçãoDireitaAVL	// *algoritmo 5.2.1
Entrada: Pt (TipoPtNodoAVL)
Retorno: Pt (TipoPtNodoAVL)
Variável auxiliar: Ptu (TipoPtNodoAVL)

{
	Ptu = Pt->Esq
	Pt->Esq = Ptu->Dir
	Ptu->Dir = Pt
	Pt = Ptu
}

RotaçãoEsquerdaAVL	// *algoritmo 5.2.2
Entrada: Pt (TipoPtNodoAVL)
Retorno: Pt (TipoPtNodoAVL)
Variável auxiliar: Ptu (TipoPtNodoAVL)

{
	Ptu = Pt->Dir
	Pt->Dir = Ptu->Esq
	Ptu->Esq = Pt
	Pt = Ptu
}

RotaçãoDuplaDireitaAVL	// *algoritmo 5.2.3
Entrada: Pt (TipoPtNodoAVL)
Retorno: Pt (TipoPtNodoAVL)
Variáveis auxiliares: Ptu, Ptv (TipoPtNodoAVL)

{
	Ptu = Pt->Esq
	Ptv = Ptu->Dir
	Ptu->Dir = Ptv->Esq
	Ptv->Esq = Ptu
	Pt->Esq = Ptv->Dir
	Ptv->Dir = Pt
	if (Ptv->FB == 1) {
		Pt->FB = -1
	else Pt->FB = 0
	}
	if (Ptv->FB == -1) {
		Ptu->FB = 1
	else Ptu->FB = 0
	}
	Pt = Ptv
}

RotaçãoDuplaEsquerdaAVL	// *algoritmo 5.2.4
Entrada: Pt (TipoPtNodoAVL)
Retorno: Pt (TipoPtNodoAVL)
Variáveis auxiliares: Pty, Ptz (TipoPtNodoAVL)

{
	Ptz = Pt->Dir
	Pty = Ptz->Esq
	Ptz->Esq = Pty->Dir
	Pty->Dir = Ptz
	Pt->Dir = Pty->Esq
	Pty->Esq = Pt
	if (Pty->FB == -1) {
		Pt->FB = 1
	else Pt->FB = 0
	}
	if (Pty->FB == 1) {
		Ptz->FB = -1
	else Ptz->FB = 0
	}
	Pt = Pty
}

Busca da chave x numa árvore B	// algoritmo 5.3
procedimento buscaB(x, pt, f, g)
	p = ptraiz; pt = lambda; f = O
	while (p != lambda) {
		i = g = 1; pt = p
		while (i <= m) {
			if (x > p->s[i]) { i = g = i + 1
			else if (x == p->s[i]) {
				p = lambda		// chave encontrada
				f = 1
			else p = p->pont[i - 1]	// mudança de página
			i = m + 2
	if (i == m + 1) { p= p->pont[m]

Subir por um caminho da árvore	// algoritmo 6.1
procedimento subir(i)
	j = piso(i/2)
	if (j >=) {
		if (T[i].chave > T[j].chave) {
			T[i] <=> T[j]
			subir(j)

Descer por um caminho da árvore	// algoritmo 6.2
procedimento descer(i, n)
	j = 2*i
	if (j <= n) {
		if (j < n) {
			if (T[j + 1].chave > T[j].chave) {
				j = j + 1
				if (T[i].chave < T[j].chave) {
					T[i] <=> T[j]
					descer(j,n)

Inserção em uma lista de prioridades	// algoritmo 6.3
if (n < M) {
	T[n + 1] = novo
	n= n + 1
	subir(n)
else overflow

Remoção de um elemento da lista de prioridades	// algoritmo 6.4
if (n != O) {
	agir(T[1])
	T[1] = T[n]
	n = n - 1
	descer(1,n)
else underflow

Construção da lista de prioridades por inserção	// algoritmo 6.5
for (i = 2, n) {
	subir(i)

Construção da lista de prioridades por arranjo	// algoritmo 6.6
procedimento arranjar(n)
	for (i = piso(n/2), 1) {
		descer(i, n)

Ordenação de T	// algoritmo 6.7
arranjar(n)
m = n
while (m > 1) {
	T[1] <=> T[m]
	m = m - 1
	descer(1, m)

descer na árvore	// algoritmo 6.8
procedimento descer(i)
	if (nivel(i) == min) {
		descer-min(i)
	else descer-max(i)

descer a partir de um nível mínimo	// algoritmo 6.9
procedimento descer-min(i)
	if (T[i] tem filhos) {
		m = índice do menor de seus filhos e netos
		if (T[m] é neto de T[i]) {
			if (T[m].chave < T[i].chave) {
				T[m] <=> T[i]
				pai = piso(m/2)
				if (T[m].chave > T[pai].chave) {
					T[m] <=> T[pai]
				descer-min(m)
		else if (T[m].chave < T[i].chave) {
			T[i] <=> T[m]

subir na árvore	// algoritmo 6.10
procedimento subir(i)
	pai = piso(i/2)
	if (nivel(i) == min) {
		if (pai >= 1 econd T[i].chave > T[pai].chave) {
			T[i] <=> T[pai]
			subir-max(pai)
		else subir-min(i)
	else if (pai >= 1 econd T[i].chave < T[pai].chave) {
			T[i] <=> T[pai]
			subir-min(pai)
		else subir-max(i)

subir a partir de um nível mínimo	// algoritmo 6.11
procedimento subir-min(i)
	if (T[i] tem avô) {
		if (T[i].chave < T[avô].chave) {
			T[i] <=> T[avô]
			subir-min(i)

geração da coleção de conjuntos	// algoritmo 7.1
procedimento gerar
	for (i = 1, n) {
		raiz[i] = i; tam[i] = 1
		pai[i] = O; nome[i] = i

determinar o nome do conjunto ao qual x pertence	// algoritmo 7.2
função buscar(x)
	y= x
	while (pai[y] != O) {
		y = pai[y]
	buscar = nome[y]

fusão de conjuntos	// algoritmo 7.3
procedimento fundir(a, b)
	ra = raiz[a]; rb = raiz[b]
	if (ra == O ou rb == O) {
		erro: a ou b não são válidos
		break;
	if (ra != rb) {
		if (tam[a] < tam[b]) {
			temp = ra; ra = rb; rb = temp
		pai[rb] = ra
		nome[ra] = a
		tam[a] = tam[a] + tam[b]
		raiz[a] = ra; raiz[b] = O

Compressão de caminhos	// algoritmo 7.4
função comp-buscar(x)
	y= x
	while (pai[y] != O) {
		y = pai[y]
	while (pai[x] f- O) {
		z = pai[x]
		pai[x] = y
		x = z
	comp-buscar = nome[y]

Separação de caminhos	// algoritmo 7.5
função sep-buscar(x)
	y = pai[x]
	if (y == O) {
		retornar (nome[x])
		z = pai[y]
		while (z f- O) {
			pai[x] = z
			x = y; y = z
			z = pai[y]
		sep-buscar = nome[y]

Divisão de caminhos	// algoritmo 7.6
função div-buscar(x)
	y = pai[x]
	if (y == O) {
		retornar(nome[x])
	z = pai[y]
	while (z != O) {
		pai[x] = z
		x = z; y = pai[x]
		if (y == O) {
			div-buscar = nome[x]
		z = pai[y]
	div-buscar = nome[y]

Busca por encadeamento interior	// algoritmo 8.1
procedimento busca(x, end, a)
	a = O; end = h(x); j= lambda
	while (a == O) {
		if (T[end].estado == não ocupado) { j = end
		if (T[end].chave == x e T[end].estado == ocupado) {
			a = 1				// chave encontrada
		else end = T[end].pont
			if (end == h(x)) {
				a = 2; end = j	// chave não encontrada

Inserção por encadeamento interior	// algoritmo 8.2
busca(x, end, a)
if (a != 1) {
	if (end != lambda) { j = end
	else i = 1; j= h(x)
		while (i <= m) {
			if (T[j].estado == ocupado) {
				j = (j + 1) mod m
				i = i + 1
			else i = m + 2	// compartimento não ocupado
		if (i == m + 1) { "inserção inválida: overflow"; break;
			temp = T[j].pont	// fusão de listas
			T[j].pont = T[h(x)].pont
			T[h(x)].pont = temp
		T[j].chave = x			// inserção de x
		T[j].estado.= ocupado
	else "inserção inválida: chave já existente"

Remoção por encadeamento interior	// algoritmo 8.3
busca(x, end, a)
if (a == 1) { T[end].estado = não ocupado
else "exclusão inválida: chave não existente"

busca por endereçamento aberto	// algoritmo 8.4
procedimento busca-aberto(x, end, a)
	a = 3; k = 0;
	while (k < m) {
		end = h(x, k)
		if (T[h(x, k)].chave == x) {
			a = 1			// chave encontrada
			k= m
		else if (T[h(x, k)].chave == lambda) {
				a= 2		// posição livre
				k= m
			else k = k + 1

calcular o endereço da chave x	// algoritmo 8.5
procedimento mapear(x, ender, p, l)
	ender = hl(x)
	if (ender < p) {
		ender = hlp1(X)

Expansão do compartimento p	// algoritmo 8.6
procedimento expandir(p, l)
	id1 = piso(p/m) + potencia(2,l); is = p mod m
	if (id1 < tamdir) {
		if (is == O) {
			reservar(m, pt)		// construído novo segmento
			dir[id1] = pt		// ponteiro para novo segmento
			lista-encadeada(p, l)
			atual(p, l)
else "diretório esgotado"

procedimento lista-encadeada(p, f)
	id = piso(p/m); id1= id + potencia(2, l)
	is= p mod m
	pt = dir[id]->seg[is]		// ponteiro lista p
	dir[id1]->seg[is] = lambda	// ponteiro lista expansão
	while (pt != lambda) {
		if (hlp1(pt->chave) != is) { // transferir nó
			if (pt == dir[id]->seg[is]) {
				dir[id]->seg[is] = pt->prox
			else ant->prox = pt->prox // remoção da lista
			pt->prox = dir[id1]->seg[is]
			dir[id1]->seg[is] = pt	// inclusão na lista expansão
		ant = pt
		pt = pt->prox

procedimento atual(p, l)
	p = p + 1
	if (p == m.potencia(2, l)) {	// tabela duplicada
		l = l + 1
		p = 0

Busca digital	// algoritmo 9.1
procedimento buscadig(x, pt, l, a)
	if (l < k) {
		seja j a posição de d(l + 1) na ordenação do alfabeto
		if (pt->pont[j] != lambda) {
			pt = pt->pont[j]; l = l + 1
			buscadig(x, pt, l, a)
		else if (pt->info == terminal) { a = 1

Inclusão em árvore digital	// algoritmo 9.2
pt = ptraiz; l = a = O
buscadig(x, pt, l, a)
if (a == O) {
	for (h == l + 1, ..., k) {
		seja j a posição de d(h) na ordenação do alfabeto
		ocupar(ptz)
		for (i == 1, ..., m) { ptz->pont[i] = lambda
			pt->pont[j] = ptz; ptz->info = não terminal
			pt = ptz
		pt->info = terminal
else "inclusão inválida"

Busca em árvore Patrícia	// algoritmo 9.3
procedimento buscapat(x, pt, a)
	if (pt->esq == lambda) { a = 1
	else if (k < pt->r) { a = 2
		else if (d[pt->r] == 0) {
				pt = pt->esq
				buscapat(x, pt, a)
			else pt = pt->dir
				buscapat(x, pt, a)

Inclusão em árvore Patrícia	// algoritmo 9.4
if (ptraiz == lambda) {		// árvore vazia
	ocupar(pt)
	pt->r = x; pt->esq = pt->dir = lambda
	ptraiz = pt
else pty' = ptraiz	// localização de y'
	buscapat(x, pty', a)
	while (pty'->esq != lambda) { pty' = pty'->esq
		l = O
		while (l < min{k, c} e d[l + 1] == d'[l + 1]) {
			l = l + 1	// i calculado
		if (l != min{k, c}) {
			ocupar(ptv); ocupar(ptw)	// criação de v e w
			ptv->r = l + 1; ptw->r = x
			ptw->esq = ptw->dir = lambda
			ptz = ptraiz; descer= V	// localização de z e q
			while (ptz->esq != lambda e descer) {
				if (ptz->r <= l + 1) {
					ptq= ptz
					if (d[ptz->r] == 0) {
						ptz = ptz->esq; esquerdo = V
					else ptz = ptz->dir; esquerdo = F
				else descer = F	// z e q localizados
			if (d[l + 1] == O) {
				ptv->esq = ptw
				ptv->dir = ptz
			else ptv->esq = ptz
				ptv->dir = ptw
			if (ptz == ptraiz) { ptraiz = ptv
			else if (esquerdo) {
					ptq->esq = ptv
				else ptq->dir = ptv
		else "inclusão inválida"

Casamento de cadeias (Força Bruta)	// algoritmo 10.1
for (l = O, ..., n - m) {
	i= 1
	teste = V
	while (i <= m e teste) {
		if (x[l + i] == y[i]) {
			i = i + 1
		else teste = F
	if (teste) {
		casamento na posição l + 1
		break;
	não há casamento

Casamento de cadeias (KMP - Knuth, Morris e Pratt)	// algoritmo 10.2
i = j = O
while (i - j <= n - m) {
	teste = V
	while (j < m e teste) {
		if (X[i + 1] == Y[j + 1]) {
			i = i + 1
			j = j + 1
		else teste = F
	if (teste) {
		casamento na posição i - m + 1
		break;
	if (j == O) { i = i + 1
	else j = d[j]
não há casamento

Determinação do vetor d	// algoritmo 10.3
j = d[1] = O
k = 1
while (k < m) {
	if (Y[k + 1] == Y[j + 1]) {
		k = k + 1
		j = j + 1
		d[k] = j
	else if (j == O) {
			k = k + 1
			d[k] = O
		else j = d[j]

construção da árvore de Huffman (Clássico)	// algoritmo 10.4
for (i= 1, n - 1) {
	minimo(T', f, F); minimo(T", f, F)
	T = T' (+) T"
	f(T) = f(T') + f(T")
	inserir(T, f, F)
