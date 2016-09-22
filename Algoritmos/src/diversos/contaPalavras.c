#include <stdio.h>
#include <string.h>

int main() {
	//Vari�veis de contagem
	int comecouPalavra = 0, numPalavras = 0, numLinhas = 0, numCaracteres = 0;
	//Vari�vel usada como descritor do arquivo em disco
	FILE *descritor;
	//Vari�vel que ir� receber a string de onde est� o arquivo
	char arquivo[50];
	//Vari�vel que armazena caracter para processamento
	char *caracter;
	printf("Digite o arquivo que deseja abrir: ");
	gets(arquivo);
	descritor = fopen(arquivo, "r");
	while (!feof(descritor)) {
		fread(caracter, 1, 1, descritor);
		numCaracteres++;
		if ((*caracter != ' ') && (*caracter != '\n') && (!comecouPalavra)) {
			comecouPalavra = 1;
		}
		if (((*caracter == ' ') || (*caracter == '\n')) && (comecouPalavra)) {
			comecouPalavra = 0;
			numPalavras++;
		}
		if (*caracter == '\n') {
			numLinhas++;
		}

	}
	printf("\n O n�mero de palavras do arquivo �: %d", numPalavras);
	printf("\n O n�mero de linhas do arquivo �: %d", numLinhas);
	printf("\n O n�mero de caracteres do arquivo �: %d", numCaracteres);
	getchar();
}
