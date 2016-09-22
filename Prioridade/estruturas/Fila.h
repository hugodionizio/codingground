#include "../Listas/Lista.h"

// Estrutura de uma Fila
struct _FilaArr {
	int tamanhoAtual;
	int tamanhoMaximo;
	int entrada;
	int saida;
	int *info;
};
typedef struct _FilaArr FilaArr;

// Estrutura de uma Fila
struct _FilaEnc {
	int tamanhoAtual;
	
	Celula *entrada, *saida;
};
typedef struct _FilaEnc FilaEnc;

// Interface da biblioteca
	/* implementação por contiguidade física em arranjo básico */
void inserirNaFila (int *f);
void removerDaFila (int *f, int N);
int *distancia (int **A, int n, int o);

	/* implementação por contiguidade física em arranjo estruturado */
void inicializarFilaArr (FilaArr &f, int tam);
void enfileirar(FilaArr &f, int info);	// Insere um novo dado no final da fila
int desenfileirar(FilaArr &f);	// Remove o elemento no comeco (frente) da fila
int tamanhoAtual(FilaArr f);
void destruir(FilaArr &f);	// Apaga dados da fila, desalocando memória para o vetor "info"
void imprimir(FilaArr &f);	// Imprimir o conteudo da fila.

	/* implementação por contiguidade física em arranjo */
void converterFilaArrParaEnc (FilaArr *larr, FilaEnc *lenc);
void converterFilaEncParaArr (FilaEnc *lenc, FilaArr *larr);

	/* implementação por encadeamento */
	/* Fila dupla - deque */
		/* implementação por contiguidade física */
		/* encadeadas */

/* Funções da biblioteca */
	/* implementação por contiguidade física em arranjo básico */
/* Insere y na fila */
void inserirNaFila (int *f) {
	int t = 0;

	f[t++] = y;
	if (t == N) {
		t = 0;
	}
}

/* Remove elemento da fila */
void removerDaFila (int *f, int N) {
	int x, s = 0;

	x = f[s++];
	if (s == N) {
		s = 0;
	}
}

/* Algoritmo das distâncias */
/* Recebe matriz A que representa as interligações entre cidades 0, 1, . . . , n − 1:
 * há uma estrada de x a y se e somente se A[x][y] = 1.
 * Devolve um vetor d tal que d[x] é a distância da cidade o à cidade x.
 */
int *distancia (int **A, int n, int o) {
	int *d, x, y;
	int *f, s, t;

	d = malloc (n * sizeof (int));
	for (x = 0; x < n; x++) d[x] = -1;
	d[o] = 0;
	f = malloc (n * sizeof (int));

	s = 0; t = 1; f[s] = o; /* o entra na fila */
	while (s < t) {
		x = f[s++]; /* x sai da fila */
		for (y = 0; y < n; y++)
			if (A[x][y] == 1 && d[y] == -1) {
				d[y] = d[x] + 1;
				f[t++] = y; /* y entra na fila */
			}
	}
	free (f);

	return d;
}

	/* implementação por contiguidade física em arrnjo estruturado */
// Utiliza um registro pre-existente para criar uma fila vazia com \
	o tamanho especificado.
void inicializarFilaArr (FilaArr &f, int tam) {

	f.tamanhoMaximo = tam;
	f.info = new int[f.tamanhoMaximo];
	f.tamanhoAtual = 0;
	f.saida = 0;
}

// Insere um novo dado no final da fila, caso ela nao esteja cheia (e nao seja nula)
void enfileirar(FilaArr &f, int info) {

	if (f.tamanhoAtual < f.tamanhoMaximo) {
		int posicao = (f.saida + f.tamanhoAtual) % f.tamanhoMaximo;
		f.info[posicao] = info;
		++ f.tamanhoAtual;
	}
	else
		cout << "Fila esta' cheia!" << endl;
}

// Remove o elemento no comeco (frente) da fila, caso ela nao esteja vazia (e nao seja nula)
// Exercício: Implementar variação da função desenfileirar similar àquela feita para Pilha:
//            A função deve retornar um booleano e modificar um parâmetro passado por
//            referência, com o valor que se encontrava na frente da fila.
int desenfileirar(FilaArr &f) {
	int valor = -999999;

	if (f.tamanhoAtual > 0) {
		valor = f.info[f.saida];
		f.saida = (f.saida + 1) % f.tamanhoMaximo;
		--f.tamanhoAtual;
	}
	else
		cout << "Fila está vazia!" << endl;

	return valor;
}

int tamanhoAtual(FilaArr f) {

	return f.tamanhoAtual;
}

// Apaga dados da fila, desalocando memoria para o vetor "dados"
void destruir(FilaArr &f) {

	// Zerar todas as inforamcoes
	// Desalocar vetor dados
	// Atribuir NULL a dados
}


// Imprimir o conteudo da fila.
void imprimir(FilaArr &f) {
}

/* ******************** Filas encadeadas ***************** */

/* Remove elemento da fila */
/* 	Recebe endereços es e et das variáveis s e t respectivamente.
 *	Supõe que fila não está vazia e remove um elemento da fila.
 *	Devolve o elemento removido.
 */
int removeDaFilaEnc (Celula **es, Celula **et) {
	Celula *p;
	int x;

	p = *es; /* p aponta o primeiro elemento da fila */
	x = p->valor;
	*es = p->seg;
	free (p);
	if (*es == NULL) *et = NULL;

	return x;
}

/* Insere elemento na fila */
/* Recebe endereços es e et das variáveis s e t respectivamente.
 * Insere um novo elemento com valor y na fila.
 * Atualiza os valores de s e t.
*/
void Insere (int y, célula **es, célula **et) {
	célula *nova;
	nova = malloc (sizeof (célula));

	nova->valor = y;
	nova->seg = NULL;
	if (*et == NULL) *et = *es = nova;
	else {
		(*et)->seg = nova;
		*et = nova;
	}
}

	//	InicializarFilaArr
	//	saida: LI (inteiro)
	//	Saídas: IF, FF (inteiros)
	//	início
	//	IF <- FF <- LI - 1
	//	fim

	//	InserirFilaArr
	//	saidas: Fila (TipoFila)
	//			LI, LS, IF, FF (inteiros)
	//			Info (TipoNodo)
	//	Saídas: IF, FF (inteiros)
	//		Sucesso (lógico)
	//	início
	//		se (FF != IF - 1) e ((IF != LI) ou (FF != LS))
	//		então	início
	//			se IF = LI - 1
	//			então IF = LI - 1 {INSERÇÃO DO PRIMEIRO NODO}
	//			senão se FF = L
	//				então FF <- LI {INSERÇÃO NO INÍCIO}
	//				senão FF <- FF + 1 {INSERÇÃO NO MEIO OU ATRÁS}
	//			FILA[FF] <- Info
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	RemoverFilaArr
	//	saidas: LI, LS, IF, FF (inteiros)
	//	Saídas: IF, FF (inteiros)
	//		Sucesso (lógico)
	//	início
	//		se IF != LI - 1
	//		então início
	//			se IF = FF
	//			então IF <- FF <- LI - 1 (FILA FICA VAZIA)
	//			senão se IF = LS
	//				então IF <- LI
	//				senão IF <- IF + 1
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	ConsultaFilaArr
	//	saidas: Fila (TipoFila)
	//			LI, IF (inteiros)
	//	Saídas: Info (TipoNodo)
	//		Sucesso (lógico)
	//	início
	//		se IF != LI - 1
	//		então início
	//			Info <- Fila[IF]
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	// Encadeamento

	//	TipoNodo = registro
	//		Info: TipoInfo
	//		Elo: TipoPtNodo
	//		fim registro

	//	TipoNodo = registro
	//		Prim: TipoPtNodo
	//		Ult: TipoPtNodo
	//		fim rgistro

	//	CriarFilaEnc
	//	saidas: -
	//	Saídas: PtDFila (TipoPtFila)
	//	início
	//		alocar(PtDFila)
	//		PtDFilaÎ.Prim <- nulo
	//		PtDFilaÎ.Ult <- nulo
	//	fim

	//	InserirFilaEnc
	//	saidas: PtDFila (TipoPtDFila)
	//		Valor (TipoInfo)
	//	Saídas: -
	//	Variável auxiliar: PtNovo (TipoPtNodo)
	//	início
	//		alocar(PtNovo)
	//		PtNovoÎ.Info <- Valor
	//		PtNovoÎ.Elo <- nulo
	//		se PtDFilaÎ.Prim = nulo
	//		então PtDFilaÎ.Prim <- PtNovo
	//		senão (PtDFilaÎ.Ult)Î.Prox <- PtNodo
	//		PtDFilaÎ.Ult <- PtNovo
	//	fim

	//	RemoverFilaEnc
	//	saidas: PtDFila (TipoPtFila)
	//	Saídas: Sucesso (lógico)
	//	Variável auxiliar: PtAux (TipoPtNodo)
	//	início
	//		se PtDFilaÎ.Prim != nulo
	//		então início
	//			PtAux <- PtDFilaÎ.Prim
	//			PtDFilaÎ.Prim <- PtAuxÎ.Elo
	//			liberar(PtAux)
	//			se PtDFilaÎ.Prim = nulo
	//			então PtDFiaÎ.Ult <- nulo
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	ConsultarFilaEnc
	//	saidas: PtDFila (TipoPtDFila)
	//	Saídas: Valor (TipoInfo)
	//		Sucesso (lógico)
	//	início
	//		se PtDFilaÎ.Prim != nulo
	//		então início
	//			Valor <- PtDFilaÎ.PrimÎ.Info
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	DestruirFilaEnc
	//	saidas: PtDFila (TipoPtDFila)
	//	Saídas: PtDFila (TipoPtDFila)
	//	Variáveis auxiliares: P1, P2 (TipoPtNodo)
	//	início
	//		se PtDFilaÎ.Prim != nulo
	//		então início
	//			P1 <- PtDFilaÎ.Prim
	//			repita
	//				P2 <- P1Î.Elo
	//				liberar(P1)
	//				P1<-P2
	//			até P1 = nulo
	//			fim
	//		liberar(PtDFila)
	//		PtDFila <- nulo
	//	fim

	//	// Deque

	//	InicializarDequeArr
	//	saidas: LI (inteiro)
	//	Saídas: IF, FF (inteiros)
	//	início
	//		IF <- FF <- LI - 1
	//	fim

	//	InserirIniDequeArr
	//	saidas: Deque (TipoDequearr)
	//		LI, LS, IF, FF (inteiros)
	//		Info (TipoNodo)
	//	Saídas: Deque (TipoDequeArr)
	//		IF, FF (inteiros)
	//		Sucesso (lógico)
	//	início
	//		se ((FF = IF - 1) ou (IF = LI) e (FF = LS))
	//		então Sucesso <- falso
	//		senão início
	//			Sucesso <- verdadeiro
	//			se IF = LI - 1 {DEQUE VAZIA}
	//			então IF <- FF <- LI
	//			senão se IF > LI
	//				então IF <- FF - 1
	//				senão IF <- LS
	//			Dque[IF] <- Info
	//			fim
	//	fim

	//	RemoverFimDequeArr
	//	saidas: LI, LS, IF, FF (inteiros)
	//	Saídas: IF, FF (inteiros)
	//		Sucesso (lógico)
	//	início
	//		se IF != LI - 1
	//		então início
	//			se IF = FF {DEQUE VAI FICAR VAZIA}
	//			então IF <- FF <- LI - 1
	//			senão se FF = LI
	//				então FF <- LS
	//				senão FF <- FF - 1
	//			Sucesso <- verdadeiro
	//			fim
	//		senão Sucesso <- falso
	//	fim

	//	ConsultarMaiorDequeArr
	//	saidas: Deque (TipoDequeArr)
	//		LI, IF, FF (inteiros)
	//	Saídas: MaiorValor (inteiro)
	//	início
	//		se IF = LI - 1
	//		então MaiorValor <- 0
	//		senão se Deque[IF] > Deque[FF]
	//			então MaiorValor <- Deque[IF]
	//			senão MaiorValor <- Deque[FF]
	//	fim

	//	// Deques encadeados

	//	TipoDDeque = registro
	//		Prim: TipoPtNodo
	//		Ult: TipoPtNodo
	//		fim registro
	//	TipoPtDDeque = ÎTipoDDeque

	//	TipoNodo = registro
	//		Ant: TipoPtNodo
	//		Info: TipoInfoNodo
	//		Prox: TipoPtNodo
	//		fim registro

	//	CriarDequeEnc
	//	saidas: -
	//	Saídas: PtDDeque (TipoPtDDeque)
	//	início
	//		alocar(PtDDeque)
	//		PtDDequeÎ.Prim <- PtDDequeÎ.Ult <- nulo
	//	fim

	//	InserirDequeEnc
	//	saidas: PtDeque (TipoPtDeque)
	//		Lado (caractere)
	//		Valor (TipoInfoNodo)
	//	Saídas: Sucesso (lógico)
	//	var PtNovo (TipoPtNodo)
	//	início
	//		Sucesso <- falso
	//		se (Lado = "I") ou (Lado = "F")
	//		então início
	//			Sucesso <- verdadeiro
	//			alocar(PtNovo)
	//			PtNovoÎ.Info <- Valor
	//			se Lado = "I"
	//			então início {INSERE NO INÍCIO}
	//				PtNovoÎ.Ant <- nulo
	//				se PtDequeÎ.Prim = nulo
	//				então início
	//					PtDDequeÎ.Ult <- PtNodo
	//					PtNovoÎ.Prox <- nulo
	//					fim
	//				senão início
	//					PtNovoÎ.Prox <- PtDDequeÎ.Prim
	//					(PtDDequeÎ.Prim)Î.Ant <- PtNovo
	//					fim
	//				PtDDequeÎ.Prim <- PtNovo
	//			fim
	//		senão início {INSERE NO FINAL}
	//			PtNovoÎ.Prox <- nulo
	//			se PtDDequeÎ.Prim = nulo
	//			então início
	//				PtNovoÎ.Ant <- nulo
	//				PtDDequeÎ.Prim = nulo
	//				fim
	//			senão início
	//				(PtDDequeÎ.Ult)Î.Prox <- PtNovo
	//				PtNovoĨ.Ant <- PtDDequeÎ.Ult
	//				fim
	//			PtDDequeÎ.Ult <- PtNovo
	//			fim
	//		fim
	//	fim

	//	RemoverDequeEnc
	//	saidas: PtDDeque (TipoPtDDeque)
	//		Lado (caractere)
	//	Saídas: Sucesso (lógico)
	//	var PtAux, PtAnt (TipoPtNodo);
	//	início
	//		Sucesso <- falso
	//		se (PtDDequeÎ.Prim != nulo) e ((Lado = "I") ou (Lado = "F"))
	//		então início
	//			Sucesso <- verdadeiro
	//			se Lado = "I"
	//			então início {REMOVE O PRIMEIRO}
	//				PtAux <- PtDDequeÎ.Prim
	//				se PtDDequeÎ.Prim = PtDDequeÎ.Ult
	//				então PtDDequeĨ.Prim <- PtDDequeÎ.Ult <- nulo
	//				senão início
	//					PtDDequeÎ.Prim <- PtAuxÎ.Prox
	//					(PtDDequeÎ.Prim)Î.Ant <- nulo
	//					fim
	//				fim
	//			senão início {REMOVE O ÚLITMO}
	//				PtAux <- PtDDequeÎ.Ult
	//				se PtDDequeÎ.Prim = PtDDequeÎ.Ult
	//				então PtDDequeÎ.Prim <- PtDDequeÎ.Ult <- nulo
	//				senão início
	//					PtDDequeÎ.Ult <- PtAuxÎ.Ant
	//					(PtDDequeÎ.Ult)Î.Prox <- nulo
	//				fim
	//			liberar(PtAux)
	//			fim
	//		fim
	//	fim

	//	ConsultarDequeEnc
	//	saidas: PtDDeque (TipoPtDDeque)
	//		Lado (caractere)
	//	Saídas: Valor (TipoInfoNodo)
	//		Sucesso (lógico)
	//	início
	//		Sucesso <- falso
	//		se (PtDDequeÎ.Prim != nulo) e ((Lado = "I") ou (Lado = "F"))
	//		então início
	//			Sucesso <- verdadeiro
	//			se Lado = "I"
	//			então Valor <- (PtDDequeÎ.Prim).Info
	//			senão Valor <- (PtDDequeĨ.Ult).Info;
	//			fimm
	//		fim
	//	fim

void converterFilaArrParaEnc (FilaArr *larr, FilaEnc *lenc) {
}

void converterFilaEncParaArr (FilaEnc *lenc, FilaArr *larr) {
}
