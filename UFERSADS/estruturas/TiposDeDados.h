#include <stdio.h>

// Interface do programa
unsigned decrementar(unsigned contador);
void decrementarPtr(unsigned *contador);
int teste(int num);

// Função principal
int TiposDeDados () {
// Seção de constantes e variáveis
// Sub-seção de constantes

// Sub-seção de variáveis
//	void voideiro;
//	bool booleiro;
	signed char signedchareiro; // Apenas para conversões
	unsigned char unsignedchareiro;
	char chareiro;
//	wchar_t wchar_teiro;
//	char16_t char16_teiro;
//	char32_t char32_teiro;

	short shorteiro;
	short int shortinteiro; // Apenas para conversões
	signed short signedshorteiro; // Apenas para conversões
	signed short int signedshortinteiro; // Apenas para conversões
	unsigned short unsignedshorteiro;
	unsigned short int unsignedshortinteiro;
	int inteiro;
	signed signedeiro; // Apenas para conversões
	signed int signedinteiro; // Apenas para conversões
	unsigned unsignedeiro;
	unsigned int unsignedinteiro; // Apenas para conversões
	long longeiro;
	long int longinteiro; // Apenas para conversões
	signed long signedlongeiro; // Apenas para conversões
	signed long int signedlonginteiro; // Apenas para conversões
	unsigned long unsignedlongeiro;
	unsigned long int unsignedlonginteiro; // Apenas para conversões
	long long longlongeiro;
	long long int longlonginteiro; // Apenas para conversões
	signed long long signedlonglongeiro; // Apenas para conversões
	signed long long int signedlonglonginteiro; // Apenas para conversões
	unsigned long long unsignedlonglongeiro;
	unsigned long long int unsignedlonglonginteiro; // Apenas para conversões

	float floateiro;
	double doubleeiro;
	long double longdoubleeiro;


// Seção modularizada

// Saída de dados

	return (0);
}

// Seção de funções, procedimentos e rotinas
unsigned decrementar(unsigned contador) {
	unsigned sinalContador = contador;

	if (sinalContador > 0) {
		sinalContador--;
	}
	else {
		printf("Número menor possível.");
	}

	return sinalContador;
}

void decrementarPtr (unsigned *contador) {

	if (*contador > 0) {
		(*contador)--;
	}
	else {
		printf("Número menor possível.");
	}
}

int teste(int num) {

	if (num > 0)
		printf("Uma forma de controlar o sistema.");
	else
		printf("Outra forma de controlar o sistema.");

	return (0);
}

// Seção de lixo (estrutura de dados sem uso que poluem o código, mas que podem ser necessárias)
/*
	unsigned num1, num2;
	int num3;

	num1 = -4;
	num2 = num1;
	num3 = (num1 + (unsigned)num1);

	printf("num1 = %d\t	num2 = %d\t	num3 = %d\n",num1,	num2,	num3);
*/

//	i=j;
//	k=(unsigned)j/2;

//	printf ("\nVariável int = %d\n",k);

//	num1 += ++num2;
//	printf("\n%d\t%d\t%d\n",num1,num2,num3);
//	num3 = num2;
//	printf("\n%d\t%d\t%d\n",num1,num2,num3);

