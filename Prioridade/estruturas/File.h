/*FileCont1.C */
/* CopiaArq.C */
/*Conta caracteres do arquivo em modo binário */
/* Mostra o uso de fread() e fwrite() */
#include <stdio.h> /* define FILE */
#include <stdlib.h>
#include <string.h> // para strcpy()

void CopiaArquivo(const char* Origem, const char *Destino);


int FileContB(char **argv) {
    FILE *fptr;  /* ponteiro para arquivo */
	short int ch;
	int cont=0, tamanho;
	char *file;
	char *newFile;

	printf("\nContando %s...\n", argv[1]);

   	if( (fptr = fopen(argv[1],"rb")) == NULL)
	{
		puts("Não foi possível abrir o arquivo");
		exit(1);
	}

	while((ch=fgetc(fptr)) != EOF)  /*Lê um caractere do arquivo */
	{
//	    putch(ch);
	    cont++;          /*incrementa contador de caracteres */
	}
	printf("O tamanho do arquivo é %d bytes.\n", cont);

	file = (char *)malloc(cont*sizeof(char));
	fclose(fptr);
	fptr = fopen(argv[1],"rb+");

	cont = 0;
	while((ch=fgetc(fptr)) != EOF)  /*Lê um caractere do arquivo */
	{
	    file[cont] = ch;
	    cont++;          /*incrementa contador de caracteres */
	}
	fclose(fptr);

	puts("\nCodificação de Shannon-Fano\n");
	testShannonFano(file);
	puts("\nCodificação por Carreira\n");
	testRunLength(file);
	puts("\nAlgoritmo de Huffman\n");
	testHuffmanRosetta(file);
	puts("\nAlgoritmo de Huffman Alternativo\n");
	testHuffmanAlternativeRosetta(file);
    free(file);

    return (0);
}

int testFileContB(int argc,char **argv)
{
	FILE *fptr;  /* ponteiro para arquivo */
	short int ch;
	int cont=0;
	char **arquivo;

	if(argc != 2)
	{
		puts("Forma de uso: C:\\>FileCont nomearq");
		puts("Informe o nome do arquivo: ");
		arquivo = (char **)malloc(2*sizeof(char));
		arquivo[0] = (char *)malloc(50*sizeof(char));
		arquivo[1] = (char *)malloc(50*sizeof(char));
		gets(arquivo[1]);
		if (strlen(arquivo[1]) == 0) {
		    puts("Operação cancelada");
		    exit(1);
		}
		else printf("%s", arquivo[1]);
		strcpy(arquivo[0], "FileCont");
		return FileContB(arquivo);
	}

	//strcpy(arquivo[1], argv);

	FileContB(argv);

    return 0;
}

int testCopiaArquivo()
{
	char Origem[] = "CopiaArq.C";
	char Destino[]= "CopiaArq.cpy";

	CopiaArquivo(Origem, Destino);
	system("type CopiaArq.cpy");
	system("pause");
      return 0;
}

void CopiaArquivo(const char* Origem, const char *Destino)
{
	unsigned char buffer[1024];
	int BytesLidos;

	FILE *fOrigem, *fDest; /* ponteiro para arquivo */

	if((fOrigem = fopen(Origem,"rb"))==NULL) return;
	if((fDest = fopen(Destino,"wb"))== NULL) return;
    do
    {
        BytesLidos= fread(buffer,sizeof(char),sizeof(buffer), fOrigem);
        fwrite(buffer,sizeof(char), BytesLidos, fDest);
    } while(BytesLidos);

    fclose(fOrigem);
    fclose(fDest);
}
