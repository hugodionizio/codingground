#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    void *info;
    unsigned freq;

    struct No *esq, *dir;
};
typedef struct No No;
typedef No * PtNo;

void inicializarNo(No *no void *info, unsigned freq) {
    no->info = info;
    no->freq = freq;
}

No criarNo (void *info, unsigned freq)) {
    No no = {info, freq};

    return No;
}

void Huffman (char *text) {
    char *dicionario, aux;
    int *vetor;
    int tam = strlen(text), contI, contJ, tamDic;

    dicionario = (char *) malloc (tam*sizeof(char));
    vetor = (int *) malloc (tam*sizeof(int));

    for (contJ = 0; contJ < tam - tamDic; contJ++) {

        if (dicionario[contJ] != "")
            for (contI = 0; contI < tam; contI++) {
                if (dicionario[contJ] == text[contI]) {
                    vetor[contJ]++;
                    break;
                }
            }
        else {
            dicionario[contJ] != text[contJ];
        }
    }

    printf("%s %d", text, tam);
}

int main() {
#define TAM 100
    char text[TAM];

    gets(text);
    Huffman(text);

    return (0);
}

