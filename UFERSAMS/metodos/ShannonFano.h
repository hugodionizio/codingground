// Biblioteca: ShannonFano.h
// Função : Compressão de Dados por Estatística Recursiva
// Camada de software: Interna
// Autor(es) : Lionel; SANTOS, Hugo Dionizio
// Data : 03-02-2013 18:24:06

#include <stdio.h>
//#include <conio.h>
#include <string.h>
#include <math.h>
#include "Sort.h"
#include "Search.h"

#define MES 3
#define FUNC 5


struct Node {
	char sym[10];
	float pro;
	int arr[20];
	int top;
};
//} s[20];
typedef struct Node Node;
typedef Node * PtNode;

// Interface da biblioteca
int testConsoleShannonFano();
int testShannonFano(char *);
int printCode (Node *, int);
void prints(int, int, Node *);
void histograma( int [][MES], int);/* protótipo */
void shannon(int, int, Node *);

// Seção de Funções Internas
// Teste do código Shannon-Fano via Console
int testConsoleShannonFano() {
	int n, i, j;
	float x, total=0;
	char ch[10];
	Node temp, s[20];
//	clrscr();
//	printf("Enter How Many Symbols Do You Want To Enter: ");
	printf("Informe a quantidade de símbolos: ");
	scanf("%d", &n);

	for (i=0; i < n; i++) {
//		printf("Enter symbol %d ---> ", i+1);
		printf("Informe o símbolo %d ---> ", i+1);
		scanf("%s", ch);
		strcpy(s[i].sym, ch);
	}

	for (i=0;i< n;i++) {
//		printf("\nEnter probability for %s ---> ", s[i].sym);
		printf("\nInforme a probabilidade de %s ---> ", s[i].sym);
		scanf("%f", &x);
		s[i].pro=x;
		total=total+s[i].pro;
		if(total>1) {
//			printf("\t\tThis probability is not possible. Enter new probability");
			printf("\t\tEsta probabilidade é impossível. Informe outra probabilidade");
			total=total-s[i].pro;
			i--;
		}
	}
	s[i].pro = 1-total;
	for(j = 1; j <= n-1; j++) {
		for(i = 0; i < n-1; i++) {
			if((s[i].pro) > (s[i+1].pro)) {
				temp.pro=s[i].pro;
				strcpy(temp.sym, s[i].sym);
				s[i].pro=s[i+1].pro;
				strcpy(s[i].sym, s[i+1].sym);
				s[i+1].pro=temp.pro;
				strcpy(s[i+1].sym, temp.sym);
			}
		}
	}
	for(i=0;i< n;i++)
	s[i].top=-1;

	shannon(0, n-1, s);
	printf("\n\n\n---------------------------------------------------------------");
//	printf("\n\tSymbol\tProbability\tCode");
	printf("\n\tSímbolo\tProbabilidade\tCódigo");
	for(i=n-1;i>=0;i--) {
		printf("\n\t%s\t%f\t", s[i].sym, s[i].pro);
		for(j = 0; j <= s[i].top; j++)
			printf("%d", s[i].arr[j]);
	}
	printf("\n---------------------------------------------------------------\n");
//	getch();

	return (0);
}

int testShannonFano(char *string) {
	// n: Quantidade de símbolos
	int n = 18, i, j;
	float total=0;
	Node temp, s[26] = {{"b", 0.25}, {"a", 0.3}, {"c", 0.20}, {"d", 0.12}, {"e", 0.08}, {"f", 0.05}};
	char buffer[100];
	FILE *fp;

	//char string[] = "ahdlfkuhelfkuhfluaxnsfqwknxfnsasgvfjwfwonfnpwoxlqw";
	unsigned count = 0;
	float freq = 0;
	int tam = strlen(string), *vetor = (int *)malloc(tam*sizeof(int)), dicionario = 0;
	Node *vetorNode	= (Node *)malloc(tam*sizeof(Node));

	//printf("%s\n", string);
	while (string[count] != '\0') {
		if (string[0] == string[count])
			freq++;
		vetor[count] = string[count];
		count++;
	}
//	printf("Frequência de %c em %d caracteres: %f (%.f vezes)\n", string[0], count, freq/count, freq);
	MergesortI(tam, vetor);
	count = 0;
	vetorNode[0].sym[0] = vetor[0];
	while (string[count] != '\0') {
		printf("%c", vetor[count]);
		if (vetorNode[dicionario].sym[0] != vetor[count]) {
			vetorNode[dicionario+1].sym[0] = vetor[count];
			vetorNode[dicionario+1].pro = 1;
			dicionario++;
		}
		else {
			vetorNode[dicionario].pro++;
		}
		count++;
	}
	dicionario++;
	printf("\nTamanho do dicionário: %d\n", dicionario);
	for (count = 0; count < dicionario; count++) {
		vetorNode[count].pro/= dicionario;
//		printf("Símbolo: %s\t Probabilidade: %f\n", vetorNode[count].sym, vetorNode[count].pro);
		s[count] = vetorNode[count];
	}

//	printf("Quantidade de símbolos: %d\n", n);
	for (i=0;i< n;i++) {
//		printf("Símbolo: %s\t Probabilidade: %f\n", s[i].sym, s[i].pro);
		total=total+s[i].pro;
	}
	s[i].pro = 1-total;
	for(j = 1; j <= n-1; j++) {
		for(i = 0; i < n-1; i++) {
			if((s[i].pro) > (s[i+1].pro)) {
				temp.pro=s[i].pro;
				strcpy(temp.sym, s[i].sym);
				s[i].pro=s[i+1].pro;
				strcpy(s[i].sym, s[i+1].sym);
				s[i+1].pro=temp.pro;
				strcpy(s[i+1].sym, temp.sym);
			}
		}
	}
	for(i=0;i< n;i++)
	s[i].top=-1;

	shannon(0, n-1, s);
	fp = fopen("comprimido.shf", "wb+");
	sprintf(buffer, "\n\n\n---------------------------------------------------------------");
	//printf("Comprimindo...");
	printf(buffer); fputs(buffer, fp);
//	printf("\n\tSymbol\tProbability\tCode");
	sprintf(buffer, "\n\tSímbolo\tProbabilidade\tCódigo");
	printf(buffer); fputs(buffer, fp);

	for(i=n-1;i>=0;i--) {
		sprintf(buffer, "\n\t%s\t%f\t", s[i].sym, s[i].pro);
        printf(buffer); fputs(buffer, fp);
        fclose(fp);
		printCode(s, i);
		fp = fopen("comprimido.shf", "ab+");
	}

	sprintf(buffer, "\n---------------------------------------------------------------\n");
	printf(buffer); fputs(buffer, fp);
	sprintf(buffer, "Saída: ");
    printf(buffer); fputs(buffer, fp);
	free(vetor);
	vetor = (int *)malloc(dicionario*sizeof(int));
	for (count = dicionario; count > 0; count--) {
		vetor[count-1] = s[count-1].sym[0];
	}

	count = 0;
	n = 0;
	fclose(fp);

	while (string[count] != '\0') {
		i = buscaSequencial(string[count], dicionario+1, vetor);
		n+=printCode(s, i);
		count++;
	}
	fp = fopen("comprimido.shf", "ab+");
	//n = (int)8*ceil((float)n/8);
	sprintf(buffer, "\nNúmero de caracteres: %d\nBits usados: %d (%d alocados - 1 byte/alocação)\nTaxa de compressão: %f%%\n",
			tam, n, 8*(int)ceil((float)n/8), (1-(float)n/(tam*8))*100);
    printf(buffer); fputs(buffer, fp);
//	getch();
    fclose(fp);

	return (0);
}

int printCode (Node *s, int pos) {
	int j;
	FILE *fp = fopen("comprimido.shf", "ab+");
	char buffer[100];


	for(j = 0; j <= s[pos].top; j++) {
	    sprintf(buffer, "%d", s[pos].arr[j]);
	    printf(buffer); fputc(buffer[0], fp);
	}
    fclose(fp);

	return j;
}

void prints(int l, int h, Node *s) {
	int i;

	for(i = l; i <= h; i++) {
		printf("\n%s\t%f", s[i].sym, s[i].pro);
	}
}

void histograma( int pecas[][MES], int nfunc)
{
	const float MAXBARRA=50.0;
	int max=0,temp=0, i, j, tam;

	for(i=0; i<nfunc; i++)
	{
		for(j=0; j<MES ; j++)
		   temp += pecas[i][j];
		if(max < temp)	max=temp;
	}

	temp=0;
	for( i=0 ; i<nfunc; i++)
	{
		for( j=0; j<MES ; j++) temp += pecas[i][j];
		printf("%2d - %5d:", i+1, temp);

		tam = (int)((float)temp/(float)max*MAXBARRA);

		for(j=0; j<tam; j++) printf("*");
		printf("\n");
	}
}


void shannon(int l, int h, Node *s) {
	float pack1=0, pack2=0, diff1=0, diff2=0;
	int i, d, k, j;

	if((l+1) == h || l == h || l > h) {
		if(l == h || l > h)
		return;
		s[h].arr[++(s[h].top)]=0;
		s[l].arr[++(s[l].top)]=1;
		return;
	}
	else {
		for (i = l; i <= h-1; i++)
			pack1=pack1+s[i].pro;
		pack2=pack2+s[h].pro;
		diff1=pack1-pack2;
		if (diff1< 0)
			diff1=diff1*-1;
		j=2;
		while (j!=h-l+1) {
			k=h-j;
			pack1 = pack2=0;
			for (i = l; i <= k; i++)
				pack1+= s[i].pro;
			for (i = h; i > k; i--)
				pack2+= s[i].pro;
			diff2 = pack1 - pack2;
			if(diff2 < 0)
				diff2*= -1;
			if(diff2 >= diff1)
				break;
			diff1 = diff2;
			j++;
		}
		k++;
		for(i = l; i <= k; i++)
			s[i].arr[++(s[i].top)]=1;
		for(i = k+1; i <=h; i++)
			s[i].arr[++(s[i].top)]=0;
		shannon(l, k, s);
		shannon(k+1, h, s);
	}
}
