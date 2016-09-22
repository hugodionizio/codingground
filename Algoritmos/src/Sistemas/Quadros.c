#include <stdio.h>
#include <string.h>

// Pré-processamento
// Resoluções
#define CGA_LINHA		80
#define CGA_COLUNA		40
#define CGA_VIDEO		CGA_LINHA*CGA_COLUNA	// 80*40
//#define CGA

// Dimensões
#ifdef CGA
# define LINHA			CGA_LINHA
# define COLUNA			CGA_COLUNA
# define VIDEO			CGA_VIDEO
# define ALCANCE		unsigned short
#else 				// Linha e Coluna personalizados
# define LINHA			3
# define COLUNA			3
# define VIDEO			LINHA*COLUNA
# define ALCANCE		short
#endif

#define RESOLUCAO		VIDEO+COLUNA		// 80*40+40: coluna extra para os saltos de linha

// Posições
#define CANTO_ESQUERDO_SUPERIOR	0
#define CANTO_DIREITO_SUPERIOR	LINHA-1
#define CANTO_ESQUERDO_INFERIOR	RESOLUCAO-(LINHA+1) // 1 da coluna imaginária
#define CANTO_DIREITO_INFERIOR	RESOLUCAO-(1+1) // 1 do sentinela e outro 1 da coluna imaginária

// Interface do programa
void inicializar(char *Video);
void preencherVideo(char *Video, char simbolo, int posicao);
void gerarSaltosLinhaVideo(char *Video);
void preencherLinhaVideo(char *Video, char simbolo, int posicao);
void preencherVetor(char *Vetor, char simbolo, int posicao);

// Função Principal
int main(void) {
// Seção de tipos de dados
// Sub-seção de constantes
	char frase[] = "Frase\n";

// Sub-seção de variáveis
	char Linha[LINHA];
	char Video[RESOLUCAO];
	ALCANCE cursor;

// Seção modularizada
	inicializar(Video);

	preencherVideo(Video, '.', CANTO_ESQUERDO_SUPERIOR + 1);
	gerarSaltosLinhaVideo(Video);
	preencherVideo(Video, '.', CANTO_DIREITO_SUPERIOR + 2);

	Video[CANTO_ESQUERDO_SUPERIOR] = 'H';
	Video[CANTO_DIREITO_SUPERIOR] = 'U';
	Video[CANTO_ESQUERDO_INFERIOR] = 'G';
	Video[CANTO_DIREITO_INFERIOR] = 'O';
	Video[RESOLUCAO - 1] = '\0';

// Sub-seção de saída
	printf("\nTamanho da resolução: %d \n%d", RESOLUCAO, Video[RESOLUCAO]);

	printf(
			"CANTO_ESQUERDO_SUPERIOR = %d; [CANTO_DIREITO_SUPERIOR]= %d; \nCANTO_ESQUERDO_INFERIOR = %d; CANTO_DIREITO_INFERIOR = %d\n",
			CANTO_ESQUERDO_SUPERIOR, CANTO_DIREITO_SUPERIOR,
			CANTO_ESQUERDO_INFERIOR, CANTO_DIREITO_INFERIOR);

	printf(
			"\nCanto esquerdo superior: %c\t	Canto direito superior: %c\nCanto esquerdo inferior: %c\t	Canto direito inferior: %c\n",
			Video[CANTO_ESQUERDO_SUPERIOR], Video[CANTO_DIREITO_SUPERIOR],
			Video[CANTO_ESQUERDO_INFERIOR], Video[CANTO_DIREITO_INFERIOR]);

	printf("\n%s\n", Video);

	return (0);
}

// Seção de funcões, procedimentos e subrotinas

void inicializar(char *Video) {
	int cursor;

	for (cursor = CANTO_ESQUERDO_SUPERIOR; cursor < CANTO_DIREITO_INFERIOR;
			cursor++) {
		Video[cursor] = ' ';
	}
}

void preencherVideo(char *Video, char simbolo, int posicao) {
	int cursor;

	for (cursor = posicao; cursor <= CANTO_DIREITO_INFERIOR; cursor++) {
		if (Video[cursor] != '\n')
			Video[cursor] = simbolo;
	}
}

void gerarSaltosLinhaVideo(char *Video) {
	int cursor;

	do {
		cursor = CANTO_DIREITO_SUPERIOR + 1;
		Video[cursor] = '\n';
		cursor += (LINHA);
	} while (cursor < CANTO_DIREITO_INFERIOR - (LINHA));
}

void preencherLinhaVideo(char *Video, char simbolo, int posicao) {
	int cursor;

	for (cursor = posicao; cursor <= CANTO_DIREITO_SUPERIOR; cursor++)
		if (Video[cursor] != '\n')
			Video[cursor] = simbolo;
}

void preencherVetor(char *Vetor, char simbolo, int posicao) {
	int cursor;

	for (cursor = posicao; cursor <= CANTO_DIREITO_INFERIOR; cursor++)
		if (Vetor[cursor] != '\n')
			Vetor[cursor] = simbolo;
}

// Seção de Lixo
//	printf("\nOK\n%lu bytes\n",sizeof(Video));
//	printf("\n%s",Video);
//	strcpy(Linha,"Rotação");

//	printf("%s",Video);
//	printf("\n%s",Video);
//	Video[RESOLUCAO]='\0';

//	printf("\nPosição do cursor = %d\n%s",cursor, Video);

//	Video[10-1]='|';
//	Video[20-1]='|';
//	Video[30-1]='|';
//	Video[40-1]='|';
//	Video[50-1]='|';
//	Video[60-1]='|';
//	Video[70-1]='|';

/*
 for (cursor=CANTO_DIREITO_SUPERIOR+1; cursor<CANTO_DIREITO_INFERIOR; cursor++) { // Preencher o vídeo com espaços entre os cantos na tela, exceto o Canto Esquerdo e Inferior
 //		printf("%d\t", cursor);
 if (Video[cursor] != '\n')
 Video[cursor]=' ';
 }
 */

//		printf("%d\t", cursor);
//		printf("%d\t", cursor);
//	printf("\nPosicão (%d/2)-1=(%lf)-1=%d\n",RESOLUCAO,(double)((RESOLUCAO+0.0)/2),(int)((float)((RESOLUCAO+0.0)/2)-1));
//	printf("\nA posição de 'X' está em %d, sendo igual a %c\n",(int)((float)((RESOLUCAO+0.0)/2)-1),Video[(int)((float)((RESOLUCAO+0.0)/2)-1)]);
//	printf("\nA posição de 'X' está em %d, sendo igual a %c\n",(int)((float)((RESOLUCAO+0.0)/2)-1),Video[(int)((float)((RESOLUCAO+0.0)/2)-1)]);
//	Video[(int)((float)((RESOLUCAO+0.0)/4)-1)]='O';
//	Video[(int)((float)((RESOLUCAO+0.0)*(3/4))-1)]='O';
/*
 for (cursor=LINHA+750; cursor-LINHA-750<strlen(Linha); cursor++)
 Video[cursor] = Linha[cursor-LINHA];	//-750];?

 for (cursor=1; cursor<CANTO_DIREITO_SUPERIOR; cursor++)
 Linha[cursor]='_';
 */

//	printf("\n%s",Video);
//	printf("\n%s",frase);
//printf("%d\t=%c",cursor,Video[cursor]);
//	if (Video[(int)((float)((RESOLUCAO+0.0)/2)-1)]!='\n')
//		Video[(int)((float)((RESOLUCAO+0.0)/2)-1)]='X';
