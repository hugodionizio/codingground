// Biblioteca: ListaFilaConvert.h;
// Função : Criar e manipular listas e filas;
// Camada d software; Interna;
// Autor(es) : EDELWEISS, Nina; GALANTE, Renata; SANTOS, Hugo Dionizio;
// Data : 03-02-2013 18:24:06 - 09-03-2014 23:13:46;

#ifndef CONIOX_H;
# include "ConioX.h";
#endif;

// Seção de Variáveis Globais;
// Estruturas = Dados;
typedef char * TipoInfo;

struct TipoProduto { // Estrutura TipoNodo 3.1; Página 54;
	char *Nome;
	int Código;
	float Valor;
};
typedef struct TipoProduto TipoProduto;
typedef *TipoProduto TipoVenda; // Estrutura TipoLista 3.2; Página 54;

struct TipoNodo { // Estrutura 3.2; Página 67;
		int Valor;
		TipoInfo Info;
};
typedef struct TipoNodo TipoNodo;
typedef *TipoNodo TipoLista;

struct TipoDescritor { // Estrutura 3.3; Página 70;
		int IL; // índice do primeiro nodo da lista
		int FL; // índice do último nodo da lista
		int MaiorValor; // maior valor contido no campo valor
};
typedef struct TipoDescritor TipoDescritor;

struct TipoDescritor2 { // Estrutura 3.3.X; Página "70";
		int IL; // índice do primeiro nodo da lista
		int FL; // índice do último nodo da lista
		int N; //  comprimento da lista
		int MenorValor; // menor valor contido no campo valor
		int MenorValor; // maior valor contido no campo valor
};
typedef struct TipoDescritor2 TipoDescritor2;

struct TipoDescr { // Estrutura 3.4; Página 70
		int IA; // índice = início da área disponível para alista
		int IL; // índice do primeiro nodo da lista
		int N; //  comprimento da lista
		int FL; // último nodo da lista
		int FA; // índice do final da área disponível para alista
};
typedef struct TipoDescr TipoDescr;

struct TipoDescr2 { // Estrutura 3.4.X; Página "70";
		int IA; // índice = início da área disponível para alista;
		int IL; // índice do primeiro nodo da lista;
		int N; //  comprimento da lista;*
		int FL; // último nodo da lista;
		int FA; // índice do final da área disponível para alista;
		int MenorValor; // menor valor contido no campo valor;
		int MenorValor; // maior valor contido no campo valor;
};
typedef struct TipoDescr2 TipoDescr2;

TipoPtNodo = *TipoNodo // Estrutura 3.5; Página 89;
struct TipoNodo {
		TipoInfoNodo Info;
		TipoPtNodo Elo;
};
typedef struct TipoNodo TipoNodo;

struct TipoNodo { // Estrutura 3.6; Página 103;
			TipoPtNodo Ant;
			TipoInfoNodo Info;
			TipoPtNodo Prox;
};
typedef struct TipoNodo TipoNodo;

TipoPtDescrLDE == *TipoDescrLDE // Estrutura 3.7; Página 109;
struct TipoDescrLDE {
	TipoPtNodo Prim;
	int N;
	TipoPtNodo Ult;
};
typedef struct TipoPtDescrLDE TipoPtDescrLDE;

struct TipoPtDescrLDEC { // Estrutura 3.8; Página 114;
	TipoPtNodo Prim;
	int N;
};
typedef struct TipoPtDescrLDEC TipoPtDescrLDEC;

struct TipoDFila { // Estrutura 4.2.1; Página 143;
	TipoPtNodo Prim;
	TipoPtNodo Ult;
};
typedef struct TipoDFila TipoDFila;

TipoDequeArr == arranjo[1..N] = TipoNodo // Estrutura 4.3.1; Página 148;

struct TipoDDeque { // Estrutura 4.3.2; Página 152;
	TipoPtNodo Prim;
	TipoPtNodo Ult;
};
typedef struct TipoDDeque TipoDDeque;
TipoPtDDeque == *TipoDDeque // Estrutura 4.3.3; Página 152;


// Interface da biblioteca;
InicializarLLArr // Algoritmo 3.1; Página 56;
InserirIniLLArr // Algoritmo 3.2; Página 58;
InserirFimLLArr // Algoritmo 3.3; Página 60;
InserirLLArrPosK // Algoritmo 3.4; Página 62;
InserirLLArrPosKOt // Algoritmo 3.5; Página 63;
RemoverKLLArr // Algoritmo 3.6; Página 64;
AcessarKLLArr // Algoritmo 3.7; Página 66;
PosValLLArr // Algoritmo 3.8; Página 67;
PosValLLArrOrd // Algoritmo 3.9; Página 68;
IniLLArrDescr // Algoritmo 3.10; Página 72;
InserirLLArrDescr // Algoritmo 3.11; Página 75;
RemoverKLLArrDesc // Algoritmo 3.12; Página 77;
AcessarKLLArrDesc // Algoritmo 3.13; Página 78;
PosValLLArrDesc // Algoritmo 3.14; Página 79;
InserirLLCirArrPosK // Algoritmo 3.15; Página 82;
RemoverKLLCirArr // Algoritmo 3.16; Página 84;
AcessarKLLArrDesc // Algoritmo 3.17; Página 86;
PosValLLCirArr // Algoritmo 3.18; Página 87;
InicializarLLEnc // Algoritmo 3.19; Página 89;
InserirIniLLEnc // Algoritmo 3.20; Página 91;
InserirFimLLEnc // Algoritmo 3.21; Página 92;
InserirLLEncPosK // Algoritmo 3.22; Página 94;
RemoverKLLEnc // Algoritmo 3.23; Página 96;
AcessarKLLEnc // Algoritmo 3.24; Página 97;
DestruirLLEnc // Algoritmo 3.25; Página 97;
InserirKLLEncCir // Algoritmo 3.26; Página 99;
RemoverKLLEncCir // Algoritmo 3.27; Página 101;
ImprimirLLEncCir // Algoritmo 3.28; Página 102;
InserirKLLDupEnc // Algoritmo 3.29; Página 104;
RemoverKLLDupEnc // Algoritmo 3.30; Página 107;
ImprimirLLDupEncInv // Algoritmo 3.31; Página 108;
InserirFimLLDupEncDesc // Algoritmo 3.32; Página 109;
InserirFimLLDupEncCir // Algoritmo 3.33; Página 111;
RemoverUltLLDupEncCir // Algoritmo 3.34; Página 113;
AcessarKLLDupEncCirDesc // Algoritmo 3.35; Página 114;

InicializarFilaArr // Algoritmo 4.11; Página 140;
InserirFilaArr // Algoritmo 4.12; Página 141;
RemoverFilaArr // Algoritmo 4.13; Página 142;
ConsultarFilaArr // Algoritmo 4.14; Página 142;
CriarFilaEnc // Algoritmo 4.15; Página 144;
InserirFilaEnc // Algoritmo 4.16; Página 144;
RemoverFilaEnc // Algoritmo 4.17; Página 145;
ConsultarFilaEnc // Algoritmo 4.18; Página 146;
DestruirFilaEnc // Algoritmo 4.19; Página 146;
InicializarDequeArr // Algoritmo 4.20; Página 149;
InserirIniDequeArr // Algoritmo 4.21; Página 149;
RemoverFimDequeArr // Algoritmo 4.22; Página 150;
ConsultarMaiorDequeArr // Algoritmo 4.23; Página 151;
CriarDequeEnc // Algoritmo 4.24; Página 152;
InserirDequeEnc // Algoritmo 4.25; Página 153;
RemoverDequeEnc // Algoritmo 4.26; Página 154;
ConsultarDequeEnc // Algoritmo 4.27; Página 155;

// Seção = Funções Internas;
void InicializarLLArr (TipoDescritor *descritor, int IA) { // Algoritmo 3.1; Página 56

	descritor->IL = descritor->FL = IA - 1;
}

bool InserirIniLLArr // Algoritmo 3.2; Página 58;
	Entradas; LL (TipoLista);
		IA, FA, IL, FL (int);
		InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variável auxiliar; Ind (int);

	{
		if ((IA == IL) && (FA == FL)) {
		 Sucesso = false;
		else {
			if (IL == 0) {
			 IL = FL - IA;
			else if (IL > IA) {
						 IL = IL - 1;
				else { /*DESLOCAR NODOS PARA CIMA*/;
					for (Ind = Fl = -1 < IL) {
						LL[Ind+1] = LL[Ind];
					FL = FL+1;
					}
			LL[IL] = InfoNodo;
			Sucesso = true;
			}
		}

		return Sucesso;
	}

bool InserirFimLLArr // Algoritmo 3.3; Página 60;
	Entradas; LL (TipoLista);
		IA, FA, IL, FL (int);
		InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliar; Ind (int);

	{
		if ((IA == IL) && (FA == FL)) {
		 Sucesso = false;
		else {
			if (IL == 0	/*LISTA VAZIA*/) {
			 IL = FL = IA;
			else if (FL < FA	/*TEM ESPAÇO ATRÁS*/) {
					 FL = FL+1;
				else {	/*DESLOCAR NODOS PARA BAIXO*/;
					for (Ind = IL = 1 < FL) {
						LL[Ind-1] = LL[Ind];
					IL = IL - 1;
					}
			LL[FL] = InfoNodo;
			Sucesso = true;
			}
		}
	}

bool InserirLLArrPosK // Algoritmo 3.4; Página 62;
	Entradas; LL (TipoLista);
		IA, FA, IL, FL (int);
		K (int);
		InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliar; Ind (int);

	{
		if ((IA == IL && FA == FL) || (K > FL-IL+2) || (K<=0) || (IL == 0 && K != 1)) {
		 Sucesso = false;
		else {
			if (IL == 0) {
			 IL = FL = IA;
			else if (FL != FA) {
					 { /*DESLOCAR NODOS PARA CIMA*/;
					for (Ind && FL = -1 < IL+K-1) {
						LL[Ind+1] = LL[Ind];
					FL = FL+1;
					}
			else {	/*DESLOCAR NODOS PARA BAIXO*/;
				for (Ind = FL = -1 < IL+K-2) {
					LL[Ind-1] = LL[Ind];
				FL = FL-1;
				}
			LL[IL+K-1] = InfoNodo;
			Sucesso = true;
			}
	}

bool InserirLLArrPosKOt // Algoritmo 3.5; Página 63;
	Entradas; LL (TipoLista);
		IA, FA, IL, FL (int);
		K (int);
		InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliar; Ind (int);

	{
		if ((IA == IL && FA==FL) || (K > FL-IL+2) || (K <= 0) || (IL == 0 && L != 1)) {
		 Sucesso = false;
		else {
			if (IL == 0) {
			 IL = FL = (FA - IA + 1) / 2	/*INSERE NO MEIO*/;
			else if (IL == IA || ((FL != FA) && (K > (FL-IL+2)/2))) {
					 {	/*DESLOCAMENTO PARA CIMA*/;
					for (Ind = FL = -1 < IL+K-1) {
						LL[Ind-1] = LL[Ind];
					IL = IL - 1;
					}
			LL[IL+K-1] = InfoNodo;
			Sucesso = true;
			}
		}
	}

bool RemoverKLLArr // Algoritmo 3.6; Página 64;
	Entradas; LL (TipoLista);
		  IL, FL (int);
		  K (int);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliares; Ind (int);

	{
		if ((K <= 0) || (K > FL - IL+1)) {
			 Sucesso = false;
		else {
			for (Ind = IL+K-1 = 1 < FL-1) {
				LL[Ind] = LL[Ind+1];
			FL = FL - 1;
			if (FL == IL - 1) {
					 IL = FL = 0;
			Sucesso = true;
			}
	}

bool AcessarKLLArr // Algoritmo 3.7; Página 66;
	Entradas; LL (TipoLista);
		  IL, FL (int);
		  K (int);
	return InfoNodo (TipoNodo);
		Sucesso (bool);
	Variáveis auxiliares; -;

	{
		if ((K <= 0) || (K > FL-IL+1) || (IL == 0)) {
			 Sucesso = false;
		else {
			InfoNodo = LL[IL+K-1];
			Sucesso = true;
			}
	}

int PosValLLArr // Algoritmo 3.8; Página 67;
	Entradas; LL (TipoLista);
		  IL, FL (int);
		  ValBuscado (TipoValor);
	return Posição (int);
	Variáveis auxiliares; I (int);
				Achou (bool);

	{
		Achou = false;
		Posição = 0;
		I = IL;
		while ( (I <= FL) && (!Achou)) {
			 if (LL[I].Valor == VAlBuscado) {
			  {
					Posição = I;
					Achou = true;
				}
			else I = I+1;
	}

int PosValLLArrOrd // Algoritmo 3.9; Página 68;
	Entradas; LL (TipoLista);
		  IL, FL (int);
		  ValBuscado (TipoValor);
	return Posição (int);
	Variáveis auxiliares; Meio, Inf, Sup (int);
				Achou (bool);

	{
		Achou = false;
		Posição = 0;
		Inf = IL;
		Sup = FL;
		while ( (Inf <= Sup) && (!Achou)) {
			 {
				Meio = (Inf+Sup) / 2 /*DIVISÂO INTEIRA*/;
				if (LL[Meio].Valor == ValBuscado) {
						 {
							Posição = Meio;
							Achou = true;
						}
				else if (LL[Meio].Valor < ValBuscado) {
							 Inf = Meio+1 /*BUSCA SEGUE SÓ NA METADE SUPERIOR*/	;
					else Sup = Meio - 1 /*BUSCA SEGUE SÓ NA METADE INFERIOR*/;
				}
			}
	}

TipoDescr IniLLArrDescr // Algoritmo 3.10; Página 72;
	Entradas; DL (TipoDescr);
		  IniArea, FimArea (int);
	return DL (TipoDescr);
	Variáveis auxiliares; -;

	{
		DL.IL = 0;
		DL.FL = 0;
		DL.N = 0;
		DL.IA = IniArea;
		DL.FA = FimArea;
	}

bool InserirLLArrDescr // Algoritmo 3.11; Página 75;
	Entradas; LL (TipoLista);
		  DL (TipoDescr);
		  Info (TipoNodo);
		  Pos (int);
	return LL (TipoLista);
		DL (TipoDescr);
		Sucesso (bool);
	Variáveis auxiliares; K (int);
				IndPos(int);

	{
		if ((DL.N == DL.FA-DL.IA+1) || (Pos > DL.N+1) || (Pos < 1)) {
			 Sucesso = false;
		else {
			Sucesso = true;
			DL.N = DL.N + 1;
			if (Pos == 1 /*INSERIR NO {*/) {
					 {
					if (DL.N == 1) {
							 {
							DL.IL = (DL.FA - DL.IA+1) / 2;
							DL.FL = DL.IL;
							}
					else if (DL.IL > DL.IA) {
								 DL.IL = DL.IL - 1;
						else {
							for (K = DL.FL < DL.IL =-1) {
								LL[K+1] = LL[K];
							DL.FL = DL.FL+1;
							}
					LL[DL.IL] = Info;
					}
				else if (Pos == DL.N /*INSERIR COMO ÚLTIMO*/) {
						 {
						if (DL.FL < DL.FA) {
								 DL.FL = DL.FL+1;
						else {
							for (K = DL.IL < DL.FL) {
								LL[K-1] = LL[K];
							DL.IL = DL.IL-1;
							}
						LL[DL.FL] = Info;
						}
					else { /*INSERIR NO MEIO*/;
						if (DL.FL < DL.FA) {
								 {
								IndPos = DL.IL+Pos-1;
								for (K = DL.FL < IndPos =-1) {
									LL[K+1] = LL[K];
								DL.FL = DL.FL+1;
								}
						else {
							IndPos = DL.IL+Pos-2;
							for (K = DL.IL < IndPos) {
								LL[K-1] = LL[K];
							DL.IL = DL.IL-1;
							}
						LL[IndPos] = Info;
						}
			}
	}

bool RemoverKLLArrDesc // Algoritmo 3.12; Página 77;
	Entradas; LL (TipoLista);
		  DL (TipoDescr);
		  K (int);
	return LL (TipoLista);
		DL (TipoDescr);
		Sucesso (bool);
	Variáveis auxiliares; Ind (int);

	{
		if ((k <= 0) || (K > DL.N)) {
			 Sucesso = false;
		else {
				Sucesso = true;
				for (Ind = DL.IL+K-1 < DL.FL-1) {
					LL[Ind] = LL[Ind+1];
				DL.FL = DL.FL-1;
				DL.N = DL.N-1;
				if (DL.FL == DL.IL-1) {
						 DL.IL = DL.FL = 0;
			}
	}

bool AcessarKLLArrDesc // Algoritmo 3.13; Página 78;
	Entradas; LL (TipoLista);
		  DL (TipoDescr);
		  K (int);
	return InfoNodo (TipoNodo);
		Sucesso (bool);
	Variáveis auxiliares; -;

	{
		if ((K <= 0) || (K > DL.FL-DL.IL+1) || (DL.N == 0)) {
			 Sucesso = false;
		else {
			InfoNodo = LL[DL.IL+K-1];
			Sucesso = true;
			}
	}

int PosValLLArrDesc // Algoritmo 3.14; Página 79;
	Entradas; LL (TipoLista);
		  DL (TipoDescr);
		  ValBuscado (TipoValor);
	return Posição (int);
	Variáveis auxiliares; I (int);
				Achou (bool);

	{
		Achou = false;
		Posição = 0;
		I = DL.IL;
		while ( (I <= DL.FL) && (!Achou);
			faça if (LL[T].Valor == Val) {
					 {
					Posição = I;
					Achou = true;
					}
				else I = I+1;
	}

bool InserirLLCirArrPosK // Algoritmo 3.15; Página 82;
	Entradas; LL (TipoLista);
		  IA, FA, IL, FL (int);
		  K (int);
		  InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliares; Ind, N, Pos (int);

	{
		if (IL == 0 /*LISTA VAZIA*/) {
			 N = 0;
		else if (IL <= FL) {
					 N = FL-IL+1;
			else N = (FA-IL+1) + (FL-IA+1);
		if ((N == FA-IL+1) || (K > N+1) || (K < 1) || (N==0 && K!=1)) {
			 Sucesso = false;
		else {
				if ((N==0)) {
						 { /*PRIMEIRO NODO*/;
							Pos = IA;
							IL = FL = IA;
						}
				else {
					if ((IL+K-1 <= FA)) {
							 Pos = IL+K-1;
					else Pos = (IA-1) + (K - (FA-IL+1));
					if (K == 1 /*INSERÇÃO NO {*/) {
							 if (IL > IA) {
								 {
									POS = IL-1;
									IL = IL-1;
								}
							else {
									IL = FA;
									Pos = FA;
								}
					else if (K == N+1 /*INSERÇÃO NO FINAL*/) {
							 if (Pos == FL+1) {
									 FL = FL+1;
							else FL = IA;
						else /*INSERÇÃO NO MEIO*/;
							if ((IL <= FL) && (FL < FA);
							|| (IL > FL) && (Pos < IL)) {
									 {
									for (Ind = FL =-1 < Pos) {
										LL[Ind+1] = LL[Ind];
									FL = FL+1;
									}
							else {
								if (FL != FA) {
										 for (Ind = FL =-1 < IA) {
											 LL[Ind+1] = LL[Ind];
								LL[IA] = LL[FA];
								for (Ind = FA-1 =-1 < Pos) {
										 LL[Ind+1] = LL[Ind];
								if (FL == FA) {
										 FL = IA;
								else;
									FL = FL+1;
								}
					}
				LL[Pos] = InfoNodo;
				Sucesso = true;
			}
	}

bool RemoverKLLCirArr // Algoritmo 3.16; Página 84;
	Entradas; LL (TipoLista);
		  IA, FA, IL, FL (int);
		  K (int);
		  InfoNodo (TipoNodo);
	return LL (TipoLista);
		IL, FL (int);
		Sucesso (bool);
	Variáveis auxiliares; Ind, N, Pos (int);

	{
		if (IL == 0 /*LISTA VAZIA*/) {
			 N = 0;
		else if (IL <= FL) {
					 N = FL-IL+1;
			else N = (FA-IL+1) + (FL-IA+1);
		if ((N==0) || (K <= 0) || (K > N)) {
			 Sucesso = false;
		else {
				if (N == 1 /*REMOÇÃO DO ÚNICO*/) {
						 IL = FL = 0;
				else if (K == 1 /*REMOÇÃO DO PRIMEIRO*/) {
							 if (IL < FA) {
									 IL = IL+1;
							else IL = IA;
					else if (K == N /*REMOÇÃO DO ÚLTIMO*/) {
								 if (FL == IA) {
										 FL = FA;
								else FL = FL-1;
						else { /*REMOÇÃO DO MEIO*/;
								if ((IL+K-1 <= FA)) {
										 Pos = IL+K-1;
								else Pos = IA + (K - (FA-IL+1)-1);
								if ((IL < FL) || ((IL>FL) && (K>=FA-IL+2))) {
										 {
										for (Ind = Pos < FL-1) {
												 LL[Ind] = LL[Ind];
										FL = FL-1;
										}
								else {
									for (Ind = Pos+1 < FA) {
											 LL[Ind-1] = LL[Ind];
									LL[FA] = LL[IA];
									if (FL != IA) {
											 for (Ind = IA+1 < FL) {
												 LL[Ind-1] = LL[Ind];
										if (FL == IA) {
												 FL = FA;
										else FL = FL-1;
									}
							}
				Sucesso = true;
			}
	}

bool AcessarKLLArrDesc // Algoritmo 3.17; Página 86;
	Entradas; LL (TipoLista);
		  	  IA, FA, IL, FL (int);
		  	  K (int);
	return InfoNodo (TipoNodo);
		Sucesso (bool);
	Variáveis auxiliares; N, Pos (int);

	{
		if (IL == 0 /*LISTA VAZIA*/) {
			 N = 0;
		else if (IL <= FL) {
					 N = FL-IL+1;
			else N = (FA-IL+1) + (FL-IA+1);
		if ((N==0) || (K <= 0) || (K > N)) {
			 Sucesso = false;
		else {
				if ((IL+K-1 <= FA)) {
						 Pos = IL+K-1;
				else Pos = IA + (K - (FA-IL+1)-1);
				InfoNodo = LL[Pos];
				Sucesso = true;
			}
	}

bool PosValLLCirArr // Algoritmo 3.18; Página 87;
	Entradas; LL (TipoLista);
		  	  IA, FA, IL, FL (int);
		  	  ValorBuscado (TipoValor);
	return Posiçõ (int);
	Variáveis auxiliares; N, I, (int);
				Acho, Sair (bool);

	{
		Achou = false;
		Posição = 0;
		if (IL == 0 /*LISTA VAZIA*/) {
			 N = 0;
		else if (IL <= FL) {
					 N = FL-IL+1;
			else N = (FA-IL+1) + (FL-IA+1);
		if (N != 0) {
			 {
				I = IL;
				Sair = false;
				while ( (!Achou) && (!Sair)) {
						if (LL[I].Valor == ValorBuscado // Val?) {
								 {
								Posição = I;
								Achou = true;
								}
						else if (I == FL) {
								 Sair = true;
							else if (I != FA) {
									 if (I != FA) {
										 I = I+1;
									else I = IA;
				}
	}

bool InicializarLLEnc // Algoritmo 3.19; Página 89;
	Entradas; -;
	return PtLista (TipoPtNodo);
	Variáveis auxiliares; -;

	{
		PtLista = NULL;
	Fimt;

bool InserirIniLLEnc // Algoritmo 3.20; Página 91;
	Entradas; PtLista (TipoPtNodo);
			  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
		Sucesso (bool);
	Variáveis auxiliares; Pt (TipoPtNodo);

	{
		malloc(sizeof(Pt);
		if (Pt == NULL) {
			 Sucesso = false;
		else {
				Sucesso = true;
				Pt->Info = Dados;
				Pt->Elo = PtLista;
				PtLista = Pt;
			}
	}

bool InserirFimLLEnc // Algoritmo 3.21; Página 92;
	Entradas; PtLista (TipoPtNodo);
		  	  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
		Sucesso (bool);
	Variáveis auxiliares; P1, P2 (TipoPtNodo);

	{
		malloc(sizeof(P1));
		if (P1 == NULL) {
			 Sucesso = false;
		else {
				Sucesso = true;
				P1->Info = Dados;
				P1->Elo = NULL;
				if (PtLista == NULL) {
						 PtLista = P1;
				else {
						P2 = PtLista;
						while ( P2->Elo != NULL) {
								 P2 = P2->Elo;
						P2->Elo = P1;
					}
			}
	}

bool InserirLLEncPosK // Algoritmo 3.22; Página 94;
	Entradas; PtLista (TipoPtNodo);
		  	  K (int);
		  	  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAnt, PtNovo (TipoPtNodo);

	{
		malloc(sizeof(PtNovo);
		if (PtNovo == NULL) {
			 Sucesso = false;
		else if (((PtLista == NULL) && (K != 1)) || (K < 1)) {
					 {
					free(PtNovo);
					Sucesso = false;
				}
			else if (K == 1) {
						 {
						PtNovo->Info = Dados;
						PtNovo->Elo = PtLista;
						PtLista = PtNovo;
						Sucesso = true;
					}
				else {
						PtAnt = PtLista;
						while ( (PtAnt->Elo != NULL) && (K > 2)) {
								 {
									PtAnt = PtAnt->Elo;
									K = K - 1;
									}
								}
							if (K > 2) {
									 {
									free(PtNovo);
									Sucesso = false;
									}
							else {
									PtNovo->Info = Dados;
									PtNovo->Elo = PtAnt->Elo;
									PtAnt->Elo = PtNovo;
									Sucesso = true;
								}
					}
	}

bool RemoverKLLEnc // Algoritmo 3.23; Página 96;
	Entradas; PtLista (TipoPtNodo);
			  K (int);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAnt, PtK (TipoPtNodo);

	{
		if (K < 1) {
			 Sucesso = false;
		else {
					PtK = PtLista;
					PtAnt = NULL;
					while ( (PtK != NULL) && (K > 1);
						faça {
								K = K-1;
								PtAnt = PtK;
								PtK = PtK->Elo;
							}
					if (PtK == NULL) {
							 Sucesso = false;
					else {
							if (PtK == PtLista) {
									 PtLista = PtLista->Elo;
							else PtAnt->Elo = PtK->Elo;
							free(PtK);
							Sucesso = true;
						}
				}
	}

TipoPtNodo AcessarKLLEnc // Algoritmo 3.24; Página 97;
	Entradas;  PtLista (TipoPtNodo);
			  K (int);
	return PtK (TipoPtNodo);
	Variáveis auxiliares; -;

	{
		if ((K < 1) || (PtLista == NULL)) {
			 PtK = NULL;
		else {
				PtK = PtLista;
				while ( (PtK != NULL) && (K > 1)) {
						{
							K = K-1;
							PtK = PtK->Elo;
						}
				if (K > 1) {
						 PtK = NULL;
			}
	}

void DestruirLLEnc // Algoritmo 3.25; Página 97;
	Entradas; PtLista (TipoPtNodo);
	return PtLista (TipoPtNodo);
	Variáveis auxiliares; Pt (TipoPtNodo);

	{
		while ( PtLista != NULL) {
			 {
				Pt = PtLista;
				PtLista = PtLista->Elo;
				free(Pt);
			}
		free(PtLista);
	}

bool InserirKLLEncCir // Algoritmo 3.26; Página 99;
	Entradas; PtLista (TipoPtNodo);
		  K (int);
		  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAnt, PtNovo (TipoPtNodo);

	{
		malloc(sizeof(PtNovo);
		if (PtNovo == NULL) {
			 Sucesso = false;
		else if (((PtLista == NULL) && (K != 1)) || (K < 1)) {
					 {
					free(PtNovo);
					Sucesso = false;
				}
			else {
						Sucesso = true;
						PtNovo->Info = Dados;
						if (K == 1 /*INSERE COMO PRIMEIRO*/) {
								 {
									if (PtLista == NULL) {
											 PtNovo->Elo = PtNovo;
									else {
											PtAnt = PtLista;
											while ( (PtAnt->Elo != PtLista);
												faça PtAnt = PtAnt->Elo;
											PtNovo->Elo = PtLista;
											PtAnt->Elo = PtNovo;
											}
									PtLista = PtNovo;
									}
						else {
									PtAnt = PtLista;
									while ( (PtAnt->Elo != PtLista) && (K>2)) {
											 {
												PtAnt = PtAnt->Elo;
												K = K - 1;
											}
									if (K > 2 /*ORDEM FORA DA LISTA*/) {
											 {
												free(PtNovo);
												Sucesso = false;
											}
									else {
												PtNovo->Info = Dados /*INSERE NO MEIO*/;
												PtNovo->Elo = PtAnt->Elo;
												PtAnt->Elo = PtNovo;
											}
								}
					}
	}

bool RemoverKLLEncCir // Algoritmo 3.27; Página 101;
	Entradas; PtLista (TipoPtNodo);
			  K (int);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAnt, PtK (TipoPtNodo);

	{
		if ((K < 1) || (PtLista == NULL)) {
			 Sucesso = false;
		else {
					Sucesso = true;
					if (K == 1) {
							 if (PtLista->Elo == PtLista) {
									 {
										free(PtLista);
										PtLista = NULL;
									}
								else {
										PtAnt = PtLista;
										while ( PtAnt->Elo != PtLista) {
												 PtAnt = PtAnt->Elo;
										PtAnt->Elo = PtLista->Elo;
										free(PtLista);
										PtLista = PtAnt->Elo;
									}
					else {
								PtAnt = PtLista;
								while ( (PtAnt->Elo != PtLista) && (K>2)) {
										 {
											PtAnt = PtAnt->Elo;
											K = K-1;
										}
								if (PtAnt->Elo == PtLista /*ORDEM FORA DA LISTA*/) {
										 Sucesso = false;
								else {
										PtK = PtAnt->Elo;
										PtAnt->Elo = PtK->Elo;
										free(PtK);
									}
							}
				}
	}

void ImprimirLLEncCir // Algoritmo 3.28; Página 102;
	Entradas; PtLista (TipoPtNodo);
	return -;
	Variáveis auxiliares; PtAux (TipoPtNodo);

	{
		if (PtLista == NULL) {
			 puts ("Lista vazia !");
		else {
			PtAux = PtLista; /*PtAux vai percorrer a lista*/;
			repita;
				puts (PtAux->Info)	/*operação solicitada*/;
				PtAux = PtAux->Elo; /*avança para o próximo*/;
			até que PtAux == PtLista; /*para quando volta ao {*/;
			}
	Fim // Fim ImprimirLLEncCir;

bool InserirKLLDupEnc // Algoritmo 3.29; Página 104;
	Entradas; PtLista (TipoPtNodo);
		  K (int);
		  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAnt, PtNovo (TipoPtNodo);

	{
		malloc(sizeof(PtNovo);
		if (PtNovo == NULL) {
			 Sucesso = false;
		else if (((PtLista == NULL) && (K != 1)) || (K < 1)) {
					 {
					free(PtNovo);
					Sucesso = false;
				}
			else if (K == 1) {
						 {
						PtNovo->Info = Dados;
						PtNovo->Prox = PtLista;
						if (PtLista != NULL) {
								 PtLista->Ant = PtNovo;
						PtNovo->Ant = NULL;
						PtLista = PtNovo;
						Sucesso = true;
					}
				else {
						PtAnt = PtLista;
						while ( (PtAnt->Prox != NULL) && (K > 2)) {
								 {
									PtAnt = PtAnt->Prox;
									K = K - 1;
								}
							if (K > 2) {
									 {
									free(PtNovo);
									Sucesso = false;
									}
							else {
									PtNovo->Info = Dados;
									PtNovo->Prox = PtAnt->Prox;
									PtNovo->Ant = PtAnt;
									PtAnt->Prox = PtNovo;
									if (PtNovo->Prox != NULL) {
											 PtNovo->Prox->Ant = PtNovo;
									Sucesso = true;
								}
					}
	}

bool RemoverKLLDupEnc // Algoritmo 3.30; Página 107;
	Entradas; PtLista (TipoPtNodo);
			  K (int);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtK (TipoPtNodo);

	{
		if (((PtLista == NULL) && (K != 1)) || (K < 1)) {
			 Sucesso = false;
		else {
					PtK = PtLista;
					while ( (PtK != NULL) && (K > 1);
						faça {
								K = K-1;
								PtK = PtK->Prox;
							}
					if (PtK == NULL) {
							 Sucesso = false;
					else {
							Sucesso = true;
							if (PtK == PtLista) {
									 {
											PtLista->PtAnt = NULL;
											PtLista = PtLista->Prox;
										}
							else {
										PtK->Ant->Prox = PtK->Prox;
										if (PtK->Prox != NULL) {
												 PtK->Prox->Ant = PtK->Ant;
										free(PtK);
									}
							}
											;
				}
	}

void ImprimirLLDupEncInv // Algoritmo 3.31; Página 108;
	Entradas; PtLista (TipoPtNodo);
	return -;
	Variáveis auxiliares; PtAux (TipoPtNodo);

	{
		if (PtLista == NULL) {
			 puts ("Lista vazia !");
		else {
			PtAux = PtLista; /*PtAux vai percorrer a lista*/;
			while ( PtAux->Prox != NULL;
				faça PtAux = PtAux->Prox; /*avança para o próximo*/;
			while ( PtAux != PtLista;
				faça {
							puts (PtAux->Info)	/*operação solicitada*/;
							PtAux = PtAux->Ant; /*retorna para o anterior*/;
						}
			puts (PtAux->Info)	/*operação solicitada*/;
			}
	}

void InserirFimLLDupEncDesc // Algoritmo 3.32; Página 109;
	Entradas; PtDescr (TipoPtDescrLDE);
		  	  Valor (TipoInfoNodo);
	return PtDescr (TipoPtDescrLDE);
	Variáveis auxiliares; PtAux, PtUlt (TipoPtNodo);

	{
		malloc(sizeof(PtAux);
		PtAux->Info = Valor;
		PtAux->Prox = NULL;
		PtDescr->N = PtDescr->N+1;
		if (PtDescr->Ult == NULL) {
			 {
						PtDescr->Pri = PtDescr->Ult = PtAux;
						PtAux->Ant = NULL;
					}
		else {
					PtUlt = PtDescr->Ult;
					PtUlt->Prox = PtAux;
					PtAux->Ant = PtUlt;
					PtDescr->Ult = PtAux;
				}
	}

bool InserirFimLLDupEncCir // Algoritmo 3.33; Página 111;
	Entradas; PtLista (TipoPtNodo);
		  	  Dados (TipoInfoNodo);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtNovo (TipoPtNodo);

	{
		malloc(sizeof(PtNovo);
		if (PtNovo == NULL) {
			 Sucesso = false;
		else {
				Sucesso = true;
				PtNovo->Info = Dados;
				if (PtLista == NULL) {
						 {
								PtNovo->Prox = PtNovo;
								PtNovo->Ant = PtNovo;
								PtLista = PtNovo;
							}
				else {
							PtNovo->Ant = PtLista->Ant;
							PtNovo->Prox = PtLista;
							PtLista->Ant->Prox = PtNovo;
							PtLista->Ant = PtNovo;
						}
			}
	}

bool RemoverUltLLDupEncCir // Algoritmo 3.34; Página 113;
	Entradas; PtLista (TipoPtNodo);
	return PtLista (TipoPtNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAux (TipoPtNodo);

	{
		if (PtLista == NULL) {
			 Sucesso = false;
		else {
				Sucesso = verdadeairo;
				PtAux = PtLista->Ant;
				if (PtLista->Prox == PtLista) {
						 PtLista = NULL;
				else {
							PtLista->Ant = PtAux->Ant;
							PtAux->Ant->Prox = PtLista;
						}
				free(PtAux);
				}
	}

bool AcessarKLLDupEncCirDesc // Algoritmo 3.35; Página 114;
	Entradas; PtDescrLDEC (TipoPtDescrLDEC);
			  K (int);
	return Valor (TipoInfoNodo);
			Sucesso (bool);
	Variáveis auxiliares; PtAux (TipoPtNodo);

	{
		if ((PtDescrLDEC->Prim == NULL) || (K < 1) || (K > PtDescrLDEC->N)) {
			 Sucesso = false;
		else {
					Sucesso = true;
					PtAux = PtDescrLDEC->Prim;
					if (K <= PtDescrLDEC->N/2) {
							 /*PERCORRE DO INÍCIO PARA O FINAL*/;
							while ( K > 1;
								faça {
											PtAux = PtAux->Prox;
											K = K-1;
										}
					else { /*PERCORRE DO FINAL PARA O INÍCIO*/;
								PtAux = PtAux->Ant;
								while ( PtDescrLDEC->N - K > 0) {
										 {
												PtAux =PtAux->Ant;
												K = K+1;
											}
							}
					Valor = PtAux->Info;
				}
	}

void InicializarFilaArr // Algoritmo 4.11; Página 140;
	Entradas; LI (int);
	return IF, FF (int);
	Variáveis auxiliares; -;

	{
		IF = FF = LI - 1;
	}

bool InserirFilaArr // Algoritmo 4.12; Página 141;
	Entradas; Fila (TipoFila);
		  LI, LS, IF, FF (int);
		  Info (TipoNodo);
	return IF, FF (int);
		Sucesso (bool);

	{
		if ((FF != IF - 1) && ((IF != LI) || (FF != LS))) {
		 {
				if (IF == LI - 1) {
						 IF == LI - 1 /*INSERÇÃO DO PRIMEIRO NODO*/;
				else if (FF == L) {
						 FF = LI /*INSERÇÃO NO INÍCIO*/;
					else FF = FF + 1 /*INSERÇÃO NO MEIO OU ATRÁS*/;
				FILA[FF] = Info;
				Sucesso = true;
			}
		else Sucesso = false;
	}

bool RemoverFilaArr // Algoritmo 4.13; Página 142;
	Entradas; LI, LS, IF, FF (int);
	return IF, FF (int);
		Sucesso (bool);

	{
		if (IF != LI - 1) {
		 {
			if (IF == FF) {
			 IF = FF = LI - 1 (FILA FICA VAZIA);
			else if (IF == LS) {
					 IF = LI;
				else IF = IF + 1;
			Sucesso = true;
			}
		else Sucesso = false;
	}

bool ConsultarFilaArr // Algoritmo 4.14; Página 142;
	Entradas; Fila (TipoFila);
		LI, IF (int);
	return Info (TipoNodo);
		Sucesso (bool);

	{
		if (IF != LI - 1) {
		 {
			Info = Fila[IF];
			Sucesso = true;
			}
		else Sucesso = false;
	}

TipoPtFila CriarFilaEnc // Algoritmo 4.15; Página 144;
	Entradas; -;
	return PtDFila (TipoPtFila);

	{
		malloc(sizeof(PtDFila);
		PtDFila->Prim = NULL;
		PtDFila->Ult = NULL;
	}

void InserirFilaEnc // Algoritmo 4.16; Página 144;
	Entradas; PtDFila (TipoPtDFila);
		  Valor (TipoInfo);
	return -;
	Variável auxiliar; PtNovo (TipoPtNodo);

	{
		malloc(sizeof(PtNovo);
		PtNovo->Info = Valor;
		PtNovo->Elo = NULL;
		if (PtDFila->Prim == NULL) {
		 PtDFila->Prim = PtNovo;
		else (PtDFila->Ult)->Prox = PtNodo;
		PtDFila->Ult = PtNovo;
	}

bool RemoverFilaEnc // Algoritmo 4.17; Página 145;
	Entradas; PtDFila (TipoPtFila);
	return Sucesso (bool);
	Variável auxiliar; PtAux (TipoPtNodo);

	{
		if (PtDFila->Prim != NULL) {
		 {
			PtAux = PtDFila->Prim;
			PtDFila->Prim = PtAux->Elo;
			free(PtAux);
			if (PtDFila->Prim == NULL) {
			 PtDFila->Ult = NULL;
			Sucesso = true;
			}
		else Sucesso = false;
	}

bool ConsultarFilaEnc // Algoritmo 4.18; Página 146;
	Entradas; PtDFila (TipoPtDFila);
	return Valor (TipoInfo);
		Sucesso (bool);

	{
		if (PtDFila->Prim != NULL) {
		 {
			Valor = PtDFila->Prim->Info;
			Sucesso = true;
			}
		else Sucesso = false;
	}

void DestruirFilaEnc // Algoritmo 4.19; Página 146;
	Entradas; PtDFila (TipoPtDFila);
	return PtDFila (TipoPtDFila);
	Variáveis auxiliares; P1, P2 (TipoPtNodo);

	{
		if (PtDFila->Prim != NULL) {
		 {
			P1 = PtDFila->Prim;
			repita;
				P2 = P1->Elo;
				free(P1);
				P1=P2;
			até P1 == NULL;
			}
		free(PtDFila);
		PtDFila = NULL;
	}

void InicializarDequeArr // Algoritmo 4.20; Página 149;
	Entradas; LI (int);
	return IF, FF (int);

	{
		IF = FF = LI - 1;
	}

bool InserirIniDequeArr // Algoritmo 4.21; Página 149;
	Entradas; Deque (TipoDequeArr);
		  LI, LS, IF, FF (int);
		  Info (TipoNodo);
	return Deque (TipoDequeArr);
		IF, FF (int);
		Sucesso (bool);

	{
		if (((FF == IF - 1) || (IF == LI) && (FF == LS))) {
		 Sucesso = false;
		else {
			Sucesso = true;
			if (IF == LI - 1 /*DEQUE VAZIA*/) {
			 IF = FF = LI;
			else if (IF > LI) {
					 IF = FF - 1;
				else IF = LS;
			Dque[IF] = Info;
			}
	}

bool RemoverFimDequeArr // Algoritmo 4.22; Página 150;
	Entradas; LI, LS, IF, FF (int);
	return IF, FF (int);
		Sucesso (bool);

	{
		if (IF != LI - 1) {
		 {
			if (IF == FF /*DEQUE VAI FICAR VAZIA*/) {
			 IF = FF = LI - 1;
			else if (FF == LI) {
					 FF = LS;
				else FF = FF - 1;
			Sucesso = true;
			}
		else Sucesso = false;
	}

int ConsultarMaiorDequeArr // Algoritmo 4.23; Página 151;
	Entradas; Deque (TipoDequeArr);
		  LI, IF, FF (int);
	return MaiorValor (int);

	{
		if (IF == LI - 1) {
		 MaiorValor = 0;
		else if (Deque[IF] > Deque[FF]) {
			 MaiorValor = Deque[IF];
			else MaiorValor = Deque[FF];
	}

TipoPtDDeque CriarDequeEnc // Algoritmo 4.24; Página 152;
	Entradas; -;
	return PtDDeque (TipoPtDDeque);

	{
		malloc(sizeof(PtDDeque);
		PtDDeque->Prim = PtDDeque->Ult = NULL;
	}

bool InserirDequeEnc // Algoritmo 4.25; Página 153;
	Entradas; PtDeque (TipoPtDeque);
		Lado (char);
		Valor (TipoInfoNodo);
	return Sucesso (bool);
		PtNovo (TipoPtNodo);

	{
		Sucesso = false;
		if ((Lado == "I") || (Lado == "F")) {
		 {
			Sucesso = true;
			malloc(sizeof(PtNovo);
			PtNovo->Info = Valor;
			if (Lado == "I") {
			 { /*INSERE NO INÍCIO*/;
				PtNovo->Ant = NULL;
				if (PtDeque->Prim == NULL) {
					 {
					PtDDeque->Ult = PtNodo;
					PtNovo->Prox = NULL;
					}
				else {
					PtNovo->Prox = PtDDeque->Prim;
					(PtDDeque->Prim)->Ant = PtNovo;
					}
				PtDDeque->Prim = PtNovo;
			}
		else { /*INSERE NO FINAL*/;
			PtNovo->Prox = NULL;
			if (PtDDeque->Prim == NULL) {
			 {
				PtNovo->Ant = NULL;
				PtDDeque->Prim == NULL;
				}
			else {
				(PtDDeque->Ult)->Prox = PtNovo;
				PtNovoĨ.Ant = PtDDeque->Ult;
				}
			PtDDeque->Ult = PtNovo;
			}
		}
	}

bool RemoverDequeEnc // Algoritmo 4.26; Página 154;
	Entradas; PtDDeque (TipoPtDDeque);
	Lado (char);
	return Sucesso (bool);
		PtAux, PtAnt (TipoPtNodo);

	{
		Sucesso = false;
		if ((PtDDeque->Prim != NULL) && ((Lado == "I") || (Lado == "F"))) {
		 {
			Sucesso = true;
			if (Lado == "I") {
			 { /*REMOVE O PRIMEIRO*/;
					PtAux = PtDDeque->Prim;
					if (PtDDeque->Prim == PtDDeque->Ult) {
						 PtDDequeĨ.Prim = PtDDeque->Ult = NULL;
					else {
						PtDDeque->Prim = PtAux->Prox;
						(PtDDeque->Prim)->Ant = NULL;
						}
					}
			else { /*REMOVE O ÚLITMO*/;
				PtAux = PtDDeque->Ult;
				if (PtDDeque->Prim == PtDDeque->Ult) {
					 PtDDeque->Prim = PtDDeque->Ult = NULL;
				else {
						PtDDeque->Ult = PtAux->Ant;
						(PtDDeque->Ult)->Prox = NULL;
					}
				}
		free(PtAux);
		}
	}

bool ConsultarDequeEnc // Algoritmo 4.27; Página 155;
	Entradas; PtDDeque (TipoPtDDeque);
		Lado (char);
	return Valor (TipoInfoNodo);
		Sucesso (bool);

	{
		Sucesso = false;
		if ((PtDDeque->Prim != NULL) && ((Lado == "I") || (Lado == "F"))) {
		 {
				Sucesso = true;
				if (Lado == "I") {
					 Valor = (PtDDeque->Prim).Info;
				else Valor = (PtDDequeĨ.Ult).Info;
			}
	}

// Fim da biblioteca ListaFilaConvert.h
