#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Biblioteca/ShannonFano.h"
#include "../Biblioteca/RunLength.h"
#include "../Biblioteca/HuffmanRosetta.h"
#include "../Biblioteca/HuffmanAlternativeRosetta.h"
#include "../Biblioteca/File.h"

int main(int argc, char **argv) {
    char string[] = "ahdlfkuhelfkuhfluaxnsfqwknxfnsasgvfjwfwonfnpwoxlqw";
    char test[] = "this is an example for huffman encoding";
    char input[] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    char str[] = "this is an example for huffman encoding";

	testShannonFano(string);
	puts("\nCodificação por Carreira\n");
	testRunLength(input);
	puts("\nAlgoritmo de Huffman\n");
	testHuffmanRosetta(test);
	puts("\nAlgoritmo de Huffman Alternativo\n");
	testHuffmanAlternativeRosetta(str);
	CopiaArquivo("lena512.bmp", "newLena512.bmp");
    testFileContB(argc, argv);



   return (0);
}
