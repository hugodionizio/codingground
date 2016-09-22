// Biblioteca: ListaFila.h
// Função : Criar e manipular listas e filas
// Camada de software: Interna
// Autor(es) : EDELWEISS, Nina; GALANTE, Renata; SANTOS, Hugo Dionizio
// Data : 03-02-2013 18:24:06 - 09-03-2014 23:13:46

#ifndef CONIOX_H
# include "ConioX.h"
#endif

// Seção de Variáveis Globais
// Estruturas de Dados
TipoNodo = registro // Estrutura 3.1; Página 54
	Nome: string
		Código: inteiro
		Valor: real
	fim registro
TipoLista = arranjo [1..N] de TipoNodo

TipoNodo = registro // Estrutura 3.2; Página 67
		Valor: inteiro
		Info: TipoInfo
	fim registro

TipoDescritor = registro // Estrutura 3.3; Página 70
		IL: inteiro // índice do primeiro nodo da lista
		FL: inteiro // índice do último nodo da lista
		MaiorValor: inteiro // maior valor contido no campo valor
	fim registro

TipoDescritor2 = registro // Estrutura 3.3.X; Página "70"
		IL: inteiro // índice do primeiro nodo da lista
		FL: inteiro // índice do último nodo da lista
		N: inteiro //  comprimento da lista
		MenorValor: inteiro // menor valor contido no campo valor
		MenorValor: inteiro // maior valor contido no campo valor
	fim registro

TipoDescr = registro // Estrutura 3.4; Página 70
		IA: inteiro // índice de início da área disponível para a lista
		IL: inteiro // índice do primeiro nodo da lista
		N: inteiro //  comprimento da lista
		FL: inteiro // último nodo da lista
		FA: inteiro // índice do final da área disponível para a lista
	fim registro

TipoDescr2 = registro // Estrutura 3.4.X; Página "70"
		IA: inteiro // índice de início da área disponível para a lista
		IL: inteiro // índice do primeiro nodo da lista
		N: inteiro //  comprimento da lista
		FL: inteiro // último nodo da lista
		FA: inteiro // índice do final da área disponível para a lista
		MenorValor: inteiro // menor valor contido no campo valor
		MenorValor: inteiro // maior valor contido no campo valor
	fim registro

TipoPtNodo = ÎTipoNodo // Estrutura 3.5; Página 89
TipoNodo = registro
		Info: TipoInfoNodo
		Elo: TipoPtNodo
	fim registro

TipoNodo = registro // Estrutura 3.6; Página 103
			Ant: TipoPtNodo
			Info: TipoInfoNodo
			Prox: TipoPtNodo
		fim registro

TipoPtDescrLDE = ÎTipoDescrLDE // Estrutura 3.7; Página 109
TipoDescrLDE = registro
				Prim: TipoPtNodo
				N: inteiro
				Ult: TipoPtNodo
			fim registro

TipoPtDescrLDEC = registro // Estrutura 3.8; Página 114
				Prim: TipoPtNodo
				N: inteiro
			fim registro

TipoDFila = registro // Estrutura 4.2.1; Página 143
		Prim: TipoPtNodo
		Ult: TipoPtNodo
	fim registro

TipoDequeArr = arranjo[1..N] de TipoNodo // Estrutura 4.3.1; Página 148

TipoDDeque = registro // Estrutura 4.3.2; Página 152
	Prim: TipoPtNodo
	Ult: TipoPtNodo
	fim registro
TipoPtDDeque = ÎTipoDDeque // Estrutura 4.3.3; Página 152

// Interface da biblioteca
InicializarLLArr // Algoritmo 3.1; Página 56
InserirIniLLArr // Algoritmo 3.2; Página 58
InserirFimLLArr // Algoritmo 3.3; Página 60
InserirLLArrPosK // Algoritmo 3.4; Página 62
InserirLLArrPosKOt // Algoritmo 3.5; Página 63
RemoverKLLArr // Algoritmo 3.6; Página 64
AcessarKLLArr // Algoritmo 3.7; Página 66
PosValLLArr // Algoritmo 3.8; Página 67
PosValLLArrOrd // Algoritmo 3.9; Página 68
IniLLArrDescr // Algoritmo 3.10; Página 72
InserirLLArrDescr // Algoritmo 3.11; Página 75
RemoverKLLArrDesc // Algoritmo 3.12; Página 77
AcessarKLLArrDesc // Algoritmo 3.13; Página 78
PosValLLArrDesc // Algoritmo 3.14; Página 79
InserirLLCirArrPosK // Algoritmo 3.15; Página 82
RemoverKLLCirArr // Algoritmo 3.16; Página 84
AcessarKLLArrDesc // Algoritmo 3.17; Página 86
PosValLLCirArr // Algoritmo 3.18; Página 87
InicializarLLEnc // Algoritmo 3.19; Página 89
InserirIniLLEnc // Algoritmo 3.20; Página 91
InserirFimLLEnc // Algoritmo 3.21; Página 92
InserirLLEncPosK // Algoritmo 3.22; Página 94
RemoverKLLEnc // Algoritmo 3.23; Página 96
AcessarKLLEnc // Algoritmo 3.24; Página 97
DestruirLLEnc // Algoritmo 3.25; Página 97
InserirKLLEncCir // Algoritmo 3.26; Página 99
RemoverKLLEncCir // Algoritmo 3.27; Página 101
ImprimirLLEncCir // Algoritmo 3.28; Página 102
InserirKLLDupEnc // Algoritmo 3.29; Página 104
RemoverKLLDupEnc // Algoritmo 3.30; Página 107
ImprimirLLDupEncInv // Algoritmo 3.31; Página 108
InserirFimLLDupEncDesc // Algoritmo 3.32; Página 109
InserirFimLLDupEncCir // Algoritmo 3.33; Página 111
RemoverUltLLDupEncCir // Algoritmo 3.34; Página 113
AcessarKLLDupEncCirDesc // Algoritmo 3.35; Página 114

InicializarFilaArr // Algoritmo 4.11; Página 140
InserirFilaArr // Algoritmo 4.12; Página 141
RemoverFilaArr // Algoritmo 4.13; Página 142
ConsultarFilaArr // Algoritmo 4.14; Página 142
CriarFilaEnc // Algoritmo 4.15; Página 144
InserirFilaEnc // Algoritmo 4.16; Página 144
RemoverFilaEnc // Algoritmo 4.17; Página 145
ConsultarFilaEnc // Algoritmo 4.18; Página 146
DestruirFilaEnc // Algoritmo 4.19; Página 146
InicializarDequeArr // Algoritmo 4.20; Página 149
InserirIniDequeArr // Algoritmo 4.21; Página 149
RemoverFimDequeArr // Algoritmo 4.22; Página 150
ConsultarMaiorDequeArr // Algoritmo 4.23; Página 151
CriarDequeEnc // Algoritmo 4.24; Página 152
InserirDequeEnc // Algoritmo 4.25; Página 153
RemoverDequeEnc // Algoritmo 4.26; Página 154
ConsultarDequeEnc // Algoritmo 4.27; Página 155

// Seção de Funções Internas
InicializarLLArr // Algoritmo 3.1; Página 56
	Entradas: IA (inteiro)
	Saídas: IL, FL (inteiro)

	início
		IL <- FL <- IA - 1
	fim

InserirIniLLArr // Algoritmo 3.2; Página 58
	Entradas: LL (TipoLista)
		IA, FA, IL, FL (inteiro)
		InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variável auxiliar: Ind (inteiro)

	início
		se (IA = IL) e (FA = FL)
		então Sucesso <- falso
		senão início
			se IL = 0
			então IL <- FL - IA
			senão se IL > IA
					então IL <- IL - 1
				senão início {DESLOCAR NODOS PARA CIMA}
					para Ind de Fl incr -1 até IL faça
						LL[Ind+1] <- LL[Ind]
					FL <- FL+1
					fim
			LL[IL] <- InfoNodo
			Sucesso <- verdadiro
			fim
		fim
	fim

InserirFimLLArr // Algoritmo 3.3; Página 60
	Entradas: LL (TipoLista)
		IA, FA, IL, FL (inteiro)
		InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliar: Ind (inteiro)

	início
		se (IA = IL) e (FA = FL)
		então Sucesso <- falso
		senão início
			se IL = 0	{LISTA VAZIA}
			então IL <- FL <- IA
			senão se FL < FA	{TEM ESPAÇO ATRÁS}
				então FL <- FL+1
				senão início	{DESLOCAR NODOS PARA BAIXO}
					para Ind de IL incr 1 até FL faça
						LL[Ind-1] <- LL[Ind]
					IL <- IL - 1
					fim
			LL[FL] <- InfoNodo
			Sucesso <- verdadeiro
			fim
		fim
	fim

InserirLLArrPosK // Algoritmo 3.4; Página 62
	Entradas: LL (TipoLista)
		IA, FA, IL, FL (inteiro)
		K (inteiro)
		InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliar: Ind (inteiro)

	início
		se (IA = IL e FA = FL) ou (K > FL-IL+2) ou (K<=0) ou (IL = 0 e K != 1)
		então Sucesso <- falso
		senão início
			se IL = 0
			então IL <- FL <- IA
			senão se FL != FA
				então início {DESLOCAR NODOS PARA CIMA}
					para Ind e FL incr -1 até IL+K-1 faça
						LL[Ind+1] <- LL[Ind]
					FL <- FL+1
					fim
			senão início	{DESLOCAR NODOS PARA BAIXO}
				para Ind de FL incr -1 até IL+K-2 faça
					LL[Ind-1] <- LL[Ind]
				FL <- FL-1
				fim
			LL[IL+K-1] <- InfoNodo
			Sucesso <- verdadeiro
			fim
	fim

InserirLLArrPosKOt // Algoritmo 3.5; Página 63
	Entradas: LL (TipoLista)
		IA, FA, IL, FL (inteiro)
		K (inteiro)
		InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliar: Ind (inteiro)

	início
		se (IA = IL e FA=FL) ou (K > FL-IL+2) ou (K <= 0) ou (IL = 0 e L != 1)
		então Sucesso <- falso
		senão início
			se IL = 0
			então IL <- FL <- (FA - IA + 1) div 2	{INSERE NO MEIO}
			senão se IL = IA ou ((FL != FA) e (K > (FL-IL+2)/2))
				então início	{DESLOCAMENTO PARA CIMA}
					para Ind de FL incr -1 até IL+K-1 faça
						LL[Ind-1] <- LL[Ind]
					IL <- IL - 1
					fim
			LL[IL+K-1] <- InfoNodo
			Sucesso <- verdadeiro
			fim
		fim
	fim

RemoverKLLArr // Algoritmo 3.6; Página 64
	Entradas: LL (TipoLista)
		  IL, FL (inteiro)
		  K (inteiro)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliares: Ind (inteiro)

	início
		se (K <= 0) ou (K > FL - IL+1)
			então Sucesso <- falso
		senão início
			para Ind de IL+K-1 incr 1 até FL-1 faça
				LL[Ind] <- LL[Ind+1]
			FL <- FL - 1
			se FL = IL - 1
				então IL <- FL <- 0
			Sucesso <- verdadeiro
			fim
	fim

AcessarKLLArr // Algoritmo 3.7; Página 66
	Entradas: LL (TipoLista)
		  IL, FL (inteiro)
		  K (inteiro)
	Saídas: InfoNodo (TipoNodo)
		Sucesso (lógico)
	Variáveis auxiliares: -

	início
		se (K <= 0) ou (K > FL-IL+1) ou (IL = 0)
			então Sucesso <- falso
		senão início
			InfoNodo <- LL[IL+K-1]
			Sucesso <- verdadeiro
			fim
	fim

PosValLLArr // Algoritmo 3.8; Página 67
	Entradas: LL (TipoLista)
		  IL, FL (inteiro)
		  ValBuscado (TipoValor)
	Saídas: Posição (inteiro)
	Variáveis auxiliares: I (inteiro)
				Achou (lógico)

	início
		Achou <- falso
		Posição <- 0
		I <- IL
		enquanto (I <= FL) e (não Achou)
		faça se LL[I].Valor = VAlBuscado
			então  início
					Posição <- I
					Achou <- verdadeiro
				fim
			senão I <- I+1
	fim

PosValLLArrOrd // Algoritmo 3.9; Página 68
	Entradas: LL (TipoLista)
		  IL, FL (inteiro)
		  ValBuscado (TipoValor)
	Saídas: Posição (inteiro)
	Variáveis auxiliares: Meio, Inf, Sup (inteiro)
				Achou (lógico)

	início
		Achou <- falso
		Posição <- 0
		Inf <- IL
		Sup <- FL
		enquanto (Inf <= Sup) e (não Achou)
		faça início
				Meio <- (Inf+Sup) div 2 {DIVISÂO INTEIRA}
				se LL[Meio].Valor = ValBuscado
					então início
							Posição <- Meio
							Achou <- verdadeiro
						fim
				senão se LL[Meio].Valor < ValBuscado
						então Inf <- Meio+1 {BUSCA SEGUE SÓ NA METADE SUPERIOR}	
					senão Sup <- Meio - 1 {BUSCA SEGUE SÓ NA METADE INFERIOR}
				fim
			fim
	fim

IniLLArrDescr // Algoritmo 3.10; Página 72
	Entradas: DL (TipoDescr)
		  IniArea, FimArea (inteiro)
	Saídas: DL (TipoDescr)
	Variáveis auxiliares: -

	início
		DL.IL <- 0
		DL.FL <- 0
		DL.N <- 0
		DL.IA <- IniArea
		DL.FA <- FimArea
	fim

InserirLLArrDescr // Algoritmo 3.11; Página 75
	Entradas: LL (TipoLista)
		  DL (TipoDescr)
		  Info (TipoNodo)
		  Pos (inteiro)
	Saídas: LL (TipoLista)
		DL (TipoDescr)
		Sucesso (lógico)
	Variáveis auxiliares: K (inteiro)
				IndPos(inteiro)

	início
		se (DL.N = DL.FA-DL.IA+1) ou (Pos > DL.N+1) ou (Pos < 1)
			então Sucesso <- falso
		senão início
			Sucesso <- verdadeiro
			DL.N <- DL.N + 1
			se Pos = 1 {INSERIR NO INÍCIO}
				então início
					se DL.N = 1
						então início
							DL.IL <- (DL.FA - DL.IA+1) div 2
							DL.FL <- DL.IL
							fim
					senão se DL.IL > DL.IA
							então DL.IL <- DL.IL - 1
						senão início
							para K de DL.FL até DL.IL incr-1 faça
								LL[K+1] <- LL[K]
							DL.FL <- DL.FL+1
							fim
					LL[DL.IL] <- Info
					fim
				senão se Pos = DL.N {INSERIR COMO ÚLTIMO}
					então início
						se DL.FL < DL.FA
							então DL.FL <- DL.FL+1
						senão início
							para K de DL.IL até DL.FL faça
								LL[K-1] <- LL[K]
							DL.IL <- DL.IL-1
							fim
						LL[DL.FL] <- Info
						fim
					senão início {INSERIR NO MEIO}
						se DL.FL < DL.FA
							então início
								IndPos <- DL.IL+Pos-1
								para K de DL.FL até IndPos incr-1 faça
									LL[K+1] <- LL[K]
								DL.FL <- DL.FL+1
								fim
						senão início
							IndPos <- DL.IL+Pos-2
							para K de DL.IL até IndPos faça
								LL[K-1] <- LL[K]
							DL.IL <- DL.IL-1
							fim
						LL[IndPos] <- Info
						fim
			fim
	fim

RemoverKLLArrDesc // Algoritmo 3.12; Página 77
	Entradas: LL (TipoLista)
		  DL (TipoDescr)
		  K (inteiro)
	Saídas: LL (TipoLista)
		DL (TipoDescr)
		Sucesso (lógico)
	Variáveis auxiliares: Ind (inteiro)

	início
		se (k <= 0) ou (K > DL.N)
			então Sucesso <- falso
		senão início
				Sucesso <- verdadeiro
				para Ind de DL.IL+K-1 até DL.FL-1 faça
					LL[Ind] <- LL[Ind+1]
				DL.FL <- DL.FL-1
				DL.N <- DL.N-1
				se DL.FL = DL.IL-1
					então DL.IL <- DL.FL <- 0
			fim
	fim

AcessarKLLArrDesc // Algoritmo 3.13; Página 78
	Entradas: LL (TipoLista)
		  DL (TipoDescr)
		  K (inteiro)
	Saídas: InfoNodo (TipoNodo)
		Sucesso (lógico)
	Variáveis auxiliares: -

	início
		se (K <= 0) ou (K > DL.FL-DL.IL+1) ou (DL.N = 0)
			então Sucesso <- falso
		senão início
			InfoNodo <- LL[DL.IL+K-1]
			Sucesso <- verdadeiro
			fim
	fim

PosValLLArrDesc // Algoritmo 3.14; Página 79
	Entradas: LL (TipoLista)
		  DL (TipoDescr)
		  ValBuscado (TipoValor)
	Saídas: Posição (inteiro)
	Variáveis auxiliares: I (inteiro)
				Achou (lógico)

	início
		Achou <- falso
		Posição <- 0
		I <- DL.IL
		enquanto (I <= DL.FL) e (não Achou)
			faça se LL[T].Valor = Val
				então início
					Posição <- I
					Achou <- verdadeiro
					fim
				senão I <- I+1
	fim

InserirLLCirArrPosK // Algoritmo 3.15; Página 82
	Entradas: LL (TipoLista)
		  IA, FA, IL, FL (inteiro)
		  K (inteiro)
		  InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliares: Ind, N, Pos (inteiro)

	início
		se IL = 0 {LISTA VAZIA}
			então N <- 0
		senão se IL <= FL
				então N <- FL-IL+1
			senão N <- (FA-IL+1) + (FL-IA+1)
		se (N = FA-IL+1) ou (K > N+1) ou (K < 1) ou (N=0 e K!=1)
			então Sucesso <- falso
		senão início
				se (N=0)
					então início {PRIMEIRO NODO}
							Pos <- IA
							IL <- FL <- IA
						fim
				senão início
					se (IL+K-1 <= FA)
						então Pos <- IL+K-1
					senão Pos <- (IA-1) + (K - (FA-IL+1))
					se K = 1 {INSERÇÃO NO INÍCIO}
						então se IL > IA
							então início
									POS <- IL-1
									IL <- IL-1
								fim
							senão início
									IL <- FA
									Pos <- FA
								fim
					senão se K = N+1 {INSERÇÃO NO FINAL}
						então se Pos = FL+1
								então FL <- FL+1
							senão FL <- IA
						senão {INSERÇÃO NO MEIO}
							se (IL <= FL) e (FL < FA)
							ou (IL > FL) e (Pos < IL)
								então início
									para Ind de FL incr-1 até Pos faça
										LL[Ind+1] <- LL[Ind]
									FL <- FL+1
									fim
							senão início
								se FL != FA
									então para Ind de FL incr-1 até IA
										faça LL[Ind+1] <- LL[Ind]
								LL[IA] <- LL[FA]
								para Ind de FA-1 incr-1 até Pos
									faça LL[Ind+1] <- LL[Ind]
								se FL = FA
									então FL <- IA
								senão
									FL <- FL+1
								fim
					fim
				LL[Pos] <- InfoNodo
				Sucesso <- verdadeiro
			fim
	fim

RemoverKLLCirArr // Algoritmo 3.16; Página 84
	Entradas: LL (TipoLista)
		  IA, FA, IL, FL (inteiro)
		  K (inteiro)
		  InfoNodo (TipoNodo)
	Saídas: LL (TipoLista)
		IL, FL (inteiro)
		Sucesso (lógico)
	Variáveis auxiliares: Ind, N, Pos (inteiro)

	início
		se IL = 0 {LISTA VAZIA}
			então N <- 0
		senão se IL <= FL
				então N <- FL-IL+1
			senão N <- (FA-IL+1) + (FL-IA+1)
		se (N=0) ou (K <= 0) ou (K > N)
			então Sucesso <- falso
		senão início
				se N = 1 {REMOÇÃO DO ÚNICO}
					então IL <- FL <- 0
				senão se K = 1 {REMOÇÃO DO PRIMEIRO}
						então se IL < FA
								então IL <- IL+1
							senão IL <- IA
					senão se K = N {REMOÇÃO DO ÚLTIMO}
							então se FL = IA
									então FL <- FA
								senão FL <- FL-1
						senão início {REMOÇÃO DO MEIO}
								se (IL+K-1 <= FA)
									então Pos <- IL+K-1
								senão Pos <- IA + (K - (FA-IL+1)-1)
								se (IL < FL) ou ((IL>FL) e (K>=FA-IL+2))
									então início
										para Ind de Pos até FL-1
											faça LL[Ind] <- LL[Ind]
										FL <- FL-1
										fim
								senão início
									para Ind de Pos+1 até FA
										faça LL[Ind-1] <- LL[Ind]
									LL[FA] <- LL[IA]
									se FL != IA
										então para Ind de IA+1 até FL
											faça LL[Ind-1] <- LL[Ind]
										se FL = IA
											então FL <- FA
										senão FL <- FL-1
									fim
							fim
				Sucesso <- verdadeiro
			fim
	fim

AcessarKLLArrDesc // Algoritmo 3.17; Página 86
	Entradas: LL (TipoLista)
		  	  IA, FA, IL, FL (inteiro)
		  	  K (inteiro)
	Saídas: InfoNodo (TipoNodo)
		Sucesso (lógico)
	Variáveis auxiliares: N, Pos (inteiro)

	início
		se IL = 0 {LISTA VAZIA}
			então N <- 0
		senão se IL <= FL
				então N <- FL-IL+1
			senão N <- (FA-IL+1) + (FL-IA+1)
		se (N=0) ou (K <= 0) ou (K > N)
			então Sucesso <- falso
		senão início
				se (IL+K-1 <= FA)
					então Pos <- IL+K-1
				senão Pos <- IA + (K - (FA-IL+1)-1)
				InfoNodo <- LL[Pos]
				Sucesso <- verdadeiro
			fim
	fim

PosValLLCirArr // Algoritmo 3.18; Página 87
	Entradas: LL (TipoLista)
		  	  IA, FA, IL, FL (inteiro)
		  	  ValorBuscado (TipoValor)
	Saídas: Posiçõ (inteiro)
	Variáveis auxiliares: N, I, (inteiro)
				Acho, Sair (lógico)

	início
		Achou <- falso
		Posição <- 0
		se IL = 0 {LISTA VAZIA}
			então N <- 0
		senão se IL <= FL
				então N <- FL-IL+1
			senão N <- (FA-IL+1) + (FL-IA+1)
		se N != 0
			então início
				I <- IL
				Sair <- falso
				enquanto (não Achou) e (não Sair)
					faça se LL[I].Valor = ValorBuscado // Val?
							então início
								Posição <- I
								Achou <- verdadeiro
								fim
						senão se I = FL
							então Sair <- verdadeiro
							senão se I != FA
								então se I != FA
									então I <- I+1
									senão I <- IA
				fim
	fim

InicializarLLEnc // Algoritmo 3.19; Página 89
	Entradas: -
	Saídas: PtLista (TipoPtNodo)
	Variáveis auxiliares: -

	início
		PtLista <- nulo
	fimt

InserirIniLLEnc // Algoritmo 3.20; Página 91
	Entradas: PtLista (TipoPtNodo)
			  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
		Sucesso (lógico)
	Variáveis auxiliares: Pt (TipoPtNodo)

	início
		alocar(Pt)
		se Pt = nulo
			então Sucesso <- falso
		senão início
				Sucesso <- verdadeiro
				PtÎ.Info <- Dados
				PtÎ.Elo <- PtLista
				PtLista <- Pt
			fim
	fim

InserirFimLLEnc // Algoritmo 3.21; Página 92
	Entradas: PtLista (TipoPtNodo)
		  	  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
		Sucesso (lógico)
	Variáveis auxiliares: P1, P2 (TipoPtNodo)

	início
		alocar(P1)
		se P1 = nulo
			então Sucesso <- falso
		senão início
				Sucesso <- verdadeiro
				P1Î.Info <- Dados
				P1Î.Elo <- nulo
				se PtLista = nulo
					então PtLista <- P1
				senão início
						P2 <- PtLista
						enquanto P2Î.Elo != nulo
							faça P2 <- P2Î.Elo
						P2Î.Elo <- P1
					fim
			fim
	fim

InserirLLEncPosK // Algoritmo 3.22; Página 94
	Entradas: PtLista (TipoPtNodo)
		  	  K (inteiro)
		  	  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAnt, PtNovo (TipoPtNodo)

	início
		alocar(PtNovo)
		se PtNovo = nulo
			então Sucesso <- falso
		senão se ((PtLista = nulo) e (K != 1)) ou (K < 1)
				então início
					liberar(PtNovo)
					Sucesso <- falso
				fim
			senão se K = 1
					então início
						PtNovoÎ.Info <- Dados
						PtNovoÎ.Elo <- PtLista
						PtLista <- PtNovo
						Sucesso <- verdadeiro
					fim
				senão início
						PtAnt <- PtLista
						enquanto (PtAntÎ.Elo != nulo) e (K > 2)
							faça início
									PtAnt <- PtAntÎ.Elo
									K <- K - 1
									fim
								fim
							se K > 2
								então início
									liberar(PtNovo)
									Sucesso <- falso
									fim
							senão início
									PtNovoÎ.Info <- Dados
									PtNovoÎ.Elo <- PtAntÎ.Elo
									PtAntÎ.Elo <- PtNovo
									Sucesso <- verdadeiro
								fim
					fim
	fim

RemoverKLLEnc // Algoritmo 3.23; Página 96
	Entradas: PtLista (TipoPtNodo)
			  K (inteiro)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAnt, PtK (TipoPtNodo)

	início
		se K < 1
			então Sucesso <- falso
		senão início
					PtK <- PtLista
					PtAnt <- nulo
					enquanto (PtK != nulo) e (K > 1)
						faça início
								K <- K-1
								PtAnt <- PtK
								PtK <- PtKÎ.Elo
							fim
					se PtK = nulo
						então Sucesso <- falso
					senão início
							se PtK = PtLista
								então PtLista <- PtListaÎ.Elo
							senão PtAntÎ.Elo <- PtKÎ.Elo
							liberar(PtK)
							Sucesso <- verdadeiro
						fim
				fim
	fim

AcessarKLLEnc // Algoritmo 3.24; Página 97
	Entradas:  PtLista (TipoPtNodo)
			  K (inteiro)
	Saídas: PtK (TipoPtNodo)
	Variáveis auxiliares: -

	início
		se (K < 1) ou (PtLista = nulo)
			então PtK <- nulo
		senão início
				PtK <- PtLista
				enquanto (PtK != nulo) e (K > 1)
					faça início
							K <- K-1
							PtK <- PtKÎ.Elo
						fim
				se K > 1
					então PtK <- nulo
			fim
	fim

DestruirLLEnc // Algoritmo 3.25; Página 97
	Entradas: PtLista (TipoPtNodo)
	Saídas: PtLista (TipoPtNodo)
	Variáveis auxiliares: Pt (TipoPtNodo)

	início
		enquanto PtLista != nulo
		faça início
				Pt <- PtLista
				PtLista <- PtListaÎ.Elo
				liberar(Pt)
			fim
		liberar(PtLista)
	fim

InserirKLLEncCir // Algoritmo 3.26; Página 99
	Entradas: PtLista (TipoPtNodo)
		  K (inteiro)
		  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAnt, PtNovo (TipoPtNodo)

	início
		alocar(PtNovo)
		se PtNovo = nulo
			então Sucesso <- falso
		senão se ((PtLista = nulo) e (K != 1)) ou (K < 1)
				então início
					liberar(PtNovo)
					Sucesso <- falso
				fim
			senão início
						Sucesso <- verdadeiro
						PtNovoÎ.Info <- Dados
						se K = 1 {INSERE COMO PRIMEIRO}
							então início
									se PtLista = nulo
										então PtNovoÎ.Elo <- PtNovo
									senão início
											PtAnt <- PtLista
											enquanto (PtAntÎ.Elo != PtLista)
												faça PtAnt <- PtAntÎ.Elo
											PtNovoÎ.Elo <- PtLista
											PtAntÎ.Elo <- PtNovo
											fim
									PtLista <- PtNovo
									fim
						senão início
									PtAnt <- PtLista
									enquanto (PtAntÎ.Elo != PtLista) e (K>2)
										faça início
												PtAnt <- PtAntÎ.Elo
												K <- K - 1
											fim
									se K > 2 {ORDEM FORA DA LISTA}
										então início
												liberar(PtNovo)
												Sucesso <- falso
											fim
									senão início
												PtNovoÎ.Info <- Dados {INSERE NO MEIO}
												PtNovoÎ.Elo <- PtAntÎ.Elo
												PtAntÎ.Elo <- PtNovo
											fim
								fim
					fim
	fim

RemoverKLLEncCir // Algoritmo 3.27; Página 101
	Entradas: PtLista (TipoPtNodo)
			  K (inteiro)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAnt, PtK (TipoPtNodo)

	início
		se (K < 1) ou (PtLista = nulo)
			então Sucesso <- falso
		senão início
					Sucesso <- verdadeiro
					se K = 1
						então se PtListaÎ.Elo = PtLista
								então início
										liberar(PtLista)
										PtLista <- nulo
									fim
								senão início
										PtAnt <- PtLista
										enquanto PtAntÎ.Elo != PtLista
											faça PtAnt <- PtAntÎ.Elo
										PtAntÎ.Elo <- PtListaÎ.Elo
										liberar(PtLista)
										PtLista <- PtAntÎ.Elo
									fim
					senão início
								PtAnt <- PtLista
								enquanto (PtAntÎ.Elo != PtLista) e (K>2)
									faça início
											PtAnt <- PtAntÎ.Elo
											K <- K-1
										fim
								se PtAntÎ.Elo = PtLista {ORDEM FORA DA LISTA}
									então Sucesso <- falso
								senão início
										PtK <- PtAntÎ.Elo
										PtAntÎ.Elo <- PtKÎ.Elo
										liberar(PtK)
									fim
							fim
				fim
	fim

ImprimirLLEncCir // Algoritmo 3.28; Página 102
Proc ImprimirLLCircular (var PtLista: TipoPtNodo);
	Entradas: PtLista (TipoPtNodo)
	Saídas: -
	Variáveis auxiliares: PtAux (TipoPtNodo)

	início
		se PtLista = nulo
			então escrever ("Lista vazia !")
		senão início
			PtAux <- PtLista; {PtAux vai percorrer a lista}
			repita
				escrever (PtAux↑.Info)	{operação solicitada}
				PtAux <- PtAux↑.Elo; {avança para o próximo}
			até que PtAux = PtLista; {para quando volta ao início}
			fim
	fim // fim ImprimirLLEncCir;

InserirKLLDupEnc // Algoritmo 3.29; Página 104
	Entradas: PtLista (TipoPtNodo)
		  K (inteiro)
		  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAnt, PtNovo (TipoPtNodo)

	início
		alocar(PtNovo)
		se PtNovo = nulo
			então Sucesso <- falso
		senão se ((PtLista = nulo) e (K != 1)) ou (K < 1)
				então início
					liberar(PtNovo)
					Sucesso <- falso
				fim
			senão se K = 1
					então início
						PtNovoÎ.Info <- Dados
						PtNovoÎ.Prox <- PtLista
						se PtLista != nulo
							então PtListaÎ.Ant <- PtNovo
						PtNovoÎ.Ant <- nulo
						PtLista <- PtNovo
						Sucesso <- verdadeiro
					fim
				senão início
						PtAnt <- PtLista
						enquanto (PtAntÎ.Prox != nulo) e (K > 2)
							faça início
									PtAnt <- PtAntÎ.Prox
									K <- K - 1
								fim
							se K > 2
								então início
									liberar(PtNovo)
									Sucesso <- falso
									fim
							senão início
									PtNovoÎ.Info <- Dados
									PtNovoÎ.Prox <- PtAntÎ.Prox
									PtNovoÎ.Ant <- PtAnt
									PtAntÎ.Prox <- PtNovo
									se PtNovoÎ.Prox != nulo
										então PtNovoÎ.ProxÎ.Ant <- PtNovo
									Sucesso <- verdadeiro
								fim
					fim
	fim

RemoverKLLDupEnc // Algoritmo 3.30; Página 107
	Entradas: PtLista (TipoPtNodo)
			  K (inteiro)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtK (TipoPtNodo)

	início
		se ((PtLista = nulo) e (K != 1)) ou (K < 1)
			então Sucesso <- falso
		senão início
					PtK <- PtLista
					enquanto (PtK != nulo) e (K > 1)
						faça início
								K <- K-1
								PtK <- PtKÎ.Prox
							fim
					se PtK = nulo
						então Sucesso <- falso
					senão início
							Sucesso <- verdadeiro
							se PtK = PtLista
								então início
											PtListaÎ.PtAnt <- nulo
											PtLista <- PtListaÎ.Prox
										fim
							senão início
										PtKÎ.AntÎ.Prox <- PtKÎ.Prox
										se PtKÎ.Prox != nulo
											então PtKÎ.ProxÎ.Ant <- PtKÎ.Ant
										liberar(PtK)
									fim
							fim
											
				fim
	fim

ImprimirLLDupEncInv // Algoritmo 3.31; Página 108
	Entradas: PtLista (TipoPtNodo)
	Saídas: -
	Variáveis auxiliares: PtAux (TipoPtNodo)

	início
		se PtLista = nulo
			então escrever ("Lista vazia !")
		senão início
			PtAux <- PtLista; {PtAux vai percorrer a lista}
			enquanto PtAux↑.Prox != nulo
				faça PtAux <- PtAux↑.Prox; {avança para o próximo}
			enquanto PtAux != PtLista
				faça início
							escrever (PtAux↑.Info)	{operação solicitada}
							PtAux <- PtAux↑.Ant; {retorna para o anterior}
						fim
			escrever (PtAux↑.Info)	{operação solicitada}
			fim
	fim

InserirFimLLDupEncDesc // Algoritmo 3.32; Página 109
	Entradas: PtDescr (TipoPtDescrLDE)
		  	  Valor (TipoInfoNodo)
	Saídas: PtDescr (TipoPtDescrLDE)
	Variáveis auxiliares: PtAux, PtUlt (TipoPtNodo)

	início
		alocar(PtAux)
		PtAuxÎ.Info <- Valor;
		PtAuxÎ.Prox <- nulo
		PtDescrÎ.N <- PtDescrÎ.N+1
		se PtDescrÎ.Ult = nulo
			então início
						PtDescrÎ.Pri <- PtDescrÎ.Ult <- PtAux
						PtAuxÎ.Ant <- nulo
					fim
		senão início
					PtUlt <- PtDescrÎ.Ult
					PtUltÎ.Prox <- PtAux
					PtAuxÎ.Ant <- PtUlt
					PtDescrÎ.Ult <- PtAux
				fim
	fim

InserirFimLLDupEncCir // Algoritmo 3.33; Página 111
	Entradas: PtLista (TipoPtNodo)
		  	  Dados (TipoInfoNodo)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtNovo (TipoPtNodo)

	início
		alocar(PtNovo)
		se PtNovo = nulo
			então Sucesso <- falso
		senão início
				Sucesso <- verdadeiro
				PtNovoÎ.Info <- Dados
				se PtLista = nulo
					então início
								PtNovoÎ.Prox <- PtNovo
								PtNovoÎ.Ant <- PtNovo
								PtLista <- PtNovo
							fim
				senão início
							PtNovoÎ.Ant <- PtListaÎ.Ant
							PtNovoÎ.Prox <- PtLista
							PtListaÎ.AntÎ.Prox <- PtNovo
							PtListaÎ.Ant <- PtNovo
						fim
			fim
	fim

RemoverUltLLDupEncCir // Algoritmo 3.34; Página 113
	Entradas: PtLista (TipoPtNodo)
	Saídas: PtLista (TipoPtNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAux (TipoPtNodo)

	início
		se PtLista = nulo
			então Sucesso <- falso
		senão início
				Sucesso <- verdadeairo
				PtAux <- PtListaÎ.Ant
				se PtListaÎ.Prox = PtLista
					então PtLista <- nulo
				senão início
							PtListaÎ.Ant <- PtAuxÎ.Ant
							PtAuxÎ.AntÎ.Prox <- PtLista
						fim
				liberar(PtAux)
				fim
	fim

AcessarKLLDupEncCirDesc // Algoritmo 3.35; Página 114
	Entradas: PtDescrLDEC (TipoPtDescrLDEC)
			  K (inteiro)
	Saídas: Valor (TipoInfoNodo)
			Sucesso (lógico)
	Variáveis auxiliares: PtAux (TipoPtNodo)

	início
		se (PtDescrLDECÎ.Prim = nulo) ou (K < 1) ou (K > PtDescrLDECÎ.N)
			então Sucesso <- falso
		senão início
					Sucesso <- verdadeiro
					PtAux <- PtDescrLDECÎ.Prim
					se K <= PtDescrLDECÎ.N/2
						então {PERCORRE DO INÍCIO PARA O FINAL}
							enquanto K > 1
								faça início
											PtAux <- PtAuxÎ.Prox
											K <- K-1
										fim
					senão início {PERCORRE DO FINAL PARA O INÍCIO}
								PtAux <- PtAuxÎ.Ant
								enquanto PtDescrLDECÎ.N - K > 0
									faça início
												PtAux <-PtAux↑.Ant
												K <- K+1
											fim
							fim
					Valor <- PtAuxÎ.Info
				fim
	fim

InicializarFilaArr // Algoritmo 4.11; Página 140
	Entradas: LI (inteiro)
	Saídas: IF, FF (inteiro)
	Variáveis auxiliares: -

	início
		IF <- FF <- LI - 1
	fim

InserirFilaArr // Algoritmo 4.12; Página 141
	Entradas: Fila (TipoFila)
		  LI, LS, IF, FF (inteiro)
		  Info (TipoNodo)
	Saídas: IF, FF (inteiro)
		Sucesso (lógico)

	início
		se (FF != IF - 1) e ((IF != LI) ou (FF != LS))
		então início
				se IF = LI - 1
					então IF = LI - 1 {INSERÇÃO DO PRIMEIRO NODO}
				senão se FF = L
					então FF <- LI {INSERÇÃO NO INÍCIO}
					senão FF <- FF + 1 {INSERÇÃO NO MEIO OU ATRÁS}
				FILA[FF] <- Info
				Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

RemoverFilaArr // Algoritmo 4.13; Página 142
	Entradas: LI, LS, IF, FF (inteiro)
	Saídas: IF, FF (inteiro)
		Sucesso (lógico)

	início
		se IF != LI - 1
		então início
			se IF = FF
			então IF <- FF <- LI - 1 (FILA FICA VAZIA)
			senão se IF = LS
				então IF <- LI
				senão IF <- IF + 1
			Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

ConsultarFilaArr // Algoritmo 4.14; Página 142
	Entradas: Fila (TipoFila)
		LI, IF (inteiro)
	Saídas: Info (TipoNodo)
		Sucesso (lógico)

	início
		se IF != LI - 1
		então início
			Info <- Fila[IF]
			Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

CriarFilaEnc // Algoritmo 4.15; Página 144
	Entradas: -
	Saídas: PtDFila (TipoPtFila)

	início
		alocar(PtDFila)
		PtDFilaÎ.Prim <- nulo
		PtDFilaÎ.Ult <- nulo
	fim

InserirFilaEnc // Algoritmo 4.16; Página 144
	Entradas: PtDFila (TipoPtDFila)
		  Valor (TipoInfo)
	Saídas: -
	Variável auxiliar: PtNovo (TipoPtNodo)

	início
		alocar(PtNovo)
		PtNovoÎ.Info <- Valor
		PtNovoÎ.Elo <- nulo
		se PtDFilaÎ.Prim = nulo
		então PtDFilaÎ.Prim <- PtNovo
		senão (PtDFilaÎ.Ult)Î.Prox <- PtNodo
		PtDFilaÎ.Ult <- PtNovo
	fim

RemoverFilaEnc // Algoritmo 4.17; Página 145
	Entradas: PtDFila (TipoPtFila)
	Saídas: Sucesso (lógico)
	Variável auxiliar: PtAux (TipoPtNodo)

	início
		se PtDFilaÎ.Prim != nulo
		então início
			PtAux <- PtDFilaÎ.Prim
			PtDFilaÎ.Prim <- PtAuxÎ.Elo
			liberar(PtAux)
			se PtDFilaÎ.Prim = nulo
			então PtDFilaÎ.Ult <- nulo
			Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

ConsultarFilaEnc // Algoritmo 4.18; Página 146
	Entradas: PtDFila (TipoPtDFila)
	Saídas: Valor (TipoInfo)
		Sucesso (lógico)

	início
		se PtDFilaÎ.Prim != nulo
		então início
			Valor <- PtDFilaÎ.PrimÎ.Info
			Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

DestruirFilaEnc // Algoritmo 4.19; Página 146
	Entradas: PtDFila (TipoPtDFila)
	Saídas: PtDFila (TipoPtDFila)
	Variáveis auxiliares: P1, P2 (TipoPtNodo)

	início
		se PtDFilaÎ.Prim != nulo
		então início
			P1 <- PtDFilaÎ.Prim
			repita
				P2 <- P1Î.Elo
				liberar(P1)
				P1<-P2
			até P1 = nulo
			fim
		liberar(PtDFila)
		PtDFila <- nulo
	fim

InicializarDequeArr // Algoritmo 4.20; Página 149
	Entradas: LI (inteiro)
	Saídas: IF, FF (inteiro)

	início
		IF <- FF <- LI - 1
	fim

InserirIniDequeArr // Algoritmo 4.21; Página 149
	Entradas: Deque (TipoDequeArr)
		  LI, LS, IF, FF (inteiro)
		  Info (TipoNodo)
	Saídas: Deque (TipoDequeArr)
		IF, FF (inteiro)
		Sucesso (lógico)

	início
		se ((FF = IF - 1) ou (IF = LI) e (FF = LS))
		então Sucesso <- falso
		senão início
			Sucesso <- verdadeiro
			se IF = LI - 1 {DEQUE VAZIA}
			então IF <- FF <- LI
			senão se IF > LI
				então IF <- FF - 1
				senão IF <- LS
			Dque[IF] <- Info
			fim
	fim

RemoverFimDequeArr // Algoritmo 4.22; Página 150
	Entradas: LI, LS, IF, FF (inteiro)
	Saídas: IF, FF (inteiro)
		Sucesso (lógico)

	início
		se IF != LI - 1
		então início
			se IF = FF {DEQUE VAI FICAR VAZIA}
			então IF <- FF <- LI - 1
			senão se FF = LI
				então FF <- LS
				senão FF <- FF - 1
			Sucesso <- verdadeiro
			fim
		senão Sucesso <- falso
	fim

ConsultarMaiorDequeArr // Algoritmo 4.23; Página 151
	Entradas: Deque (TipoDequeArr)
		  LI, IF, FF (inteiro)
	Saídas: MaiorValor (inteiro)

	início
		se IF = LI - 1
		então MaiorValor <- 0
		senão se Deque[IF] > Deque[FF]
			então MaiorValor <- Deque[IF]
			senão MaiorValor <- Deque[FF]
	fim

CriarDequeEnc // Algoritmo 4.24; Página 152
	Entradas: -
	Saídas: PtDDeque (TipoPtDDeque)

	início
		alocar(PtDDeque)
		PtDDequeÎ.Prim <- PtDDequeÎ.Ult <- nulo
	fim

InserirDequeEnc // Algoritmo 4.25; Página 153
	Entradas: PtDeque (TipoPtDeque)
		Lado (caractere)
		Valor (TipoInfoNodo)
	Saídas: Sucesso (lógico)
		PtNovo (TipoPtNodo)

	início
		Sucesso <- falso
		se (Lado = "I") ou (Lado = "F")
		então início
			Sucesso <- verdadeiro
			alocar(PtNovo)
			PtNovoÎ.Info <- Valor
			se Lado = "I"
			então início {INSERE NO INÍCIO}
				PtNovoÎ.Ant <- nulo
				se PtDequeÎ.Prim = nulo
				então início
					PtDDequeÎ.Ult <- PtNodo
					PtNovoÎ.Prox <- nulo
					fim
				senão início
					PtNovoÎ.Prox <- PtDDequeÎ.Prim
					(PtDDequeÎ.Prim)Î.Ant <- PtNovo
					fim
				PtDDequeÎ.Prim <- PtNovo
			fim
		senão início {INSERE NO FINAL}
			PtNovoÎ.Prox <- nulo
			se PtDDequeÎ.Prim = nulo
			então início
				PtNovoÎ.Ant <- nulo
				PtDDequeÎ.Prim = nulo
				fim
			senão início
				(PtDDequeÎ.Ult)Î.Prox <- PtNovo
				PtNovoĨ.Ant <- PtDDequeÎ.Ult
				fim
			PtDDequeÎ.Ult <- PtNovo
			fim
		fim
	fim

RemoverDequeEnc // Algoritmo 4.26; Página 154
	Entradas: PtDDeque (TipoPtDDeque)
	Lado (caractere)
	Saídas: Sucesso (lógico)
		PtAux, PtAnt (TipoPtNodo);

	início
		Sucesso <- falso
		se (PtDDequeÎ.Prim != nulo) e ((Lado = "I") ou (Lado = "F"))
		então início
			Sucesso <- verdadeiro
			se Lado = "I"
			então início {REMOVE O PRIMEIRO}
					PtAux <- PtDDequeÎ.Prim
					se PtDDequeÎ.Prim = PtDDequeÎ.Ult
					então PtDDequeĨ.Prim <- PtDDequeÎ.Ult <- nulo
					senão início
						PtDDequeÎ.Prim <- PtAuxÎ.Prox
						(PtDDequeÎ.Prim)Î.Ant <- nulo
						fim
					fim
			senão início {REMOVE O ÚLITMO}
				PtAux <- PtDDequeÎ.Ult
				se PtDDequeÎ.Prim = PtDDequeÎ.Ult
				então PtDDequeÎ.Prim <- PtDDequeÎ.Ult <- nulo
				senão início
						PtDDequeÎ.Ult <- PtAuxÎ.Ant
						(PtDDequeÎ.Ult)Î.Prox <- nulo
					fim
				fim
		liberar(PtAux)
		fim
	fim

ConsultarDequeEnc // Algoritmo 4.27; Página 155
	Entradas: PtDDeque (TipoPtDDeque)
		Lado (caractere)
	Saídas: Valor (TipoInfoNodo)
		Sucesso (lógico)

	início
		Sucesso <- falso
		se (PtDDequeÎ.Prim != nulo) e ((Lado = "I") ou (Lado = "F"))
		então início
				Sucesso <- verdadeiro
				se Lado = "I"
				então Valor <- (PtDDequeÎ.Prim).Info
				senão Valor <- (PtDDequeĨ.Ult).Info;
			fimm
	fim

// Fim da biblioteca ListaFila.h
