#include "Vector.h"

void inicializarVetor(Vector *v, char *elementos, int tipo) {
    void *vetor, *pos;
    int i = 0, tam = 1, unidade = 1, elemento;//, *vetorInt;
    float *atual, *show;
    //bool *vetorBool;
    //char *string;
    //float *vetorFloat; double *vetorDouble; //complex *vetorComplex;

    while (elementos[i] != '\0') {
        if (elementos[i] == 32)
            tam++;
            i++;
    }

    switch (tipo) {
       case BOOL: {criarVetor(bool);} break;
       case CHAR: {criarVetor(char);} break;
       case INT: {criarVetor(int);} break;
       case FLOAT: {criarVetor(float);} break;
       case DOUBLE: {criarVetor(double);} break;
       case COMPLEX: {criarVetor(complex);} break;
    };

    elemento = tam;
    while (elemento >= 0) {
        unidade = 1;
        pos = &vetor[elemento-1];
        atual = (float *)pos;
        *atual = 0;
        do {
            if (elementos[i] > 47 && elementos[i] < 58) {
                (*atual)+= (elementos[i]-48)*unidade;
                unidade*=10;
            } else switch (elementos[i]) {
                case 45: (*atual)*= -1; unidade = 1; break;
                case 44:
                case 46: (*atual)*= 1/((float)unidade);
                case 0:
                case 32: unidade = 1; break;
            }
            i--;
            printf("atual = %f\n", *atual);
        } while (elementos[i] != 32 && i >= 0);
        elemento--;
    }
    v->info = vetor;
    v->size = tam;
    v->type = tipo;
    puts("\n");
}

void imprimirVetor (Vector v) {
    float *pv;
    int cont;
    char elementos[5];

    switch (v.type) {
       case BOOL: {apontarVetor(bool);} strcpy(elementos, "%d "); break;
       case CHAR: {apontarVetor(char);} strcpy(elementos, "%c "); break;
       case INT: {apontarVetor(int);} strcpy(elementos, "%d "); break;
       case FLOAT: {apontarVetor(float);} strcpy(elementos, "%f "); break;
       case DOUBLE: {apontarVetor(double);} strcpy(elementos, "%lf "); break;
       case COMPLEX: {apontarVetor(complex);} strcpy(elementos, "%d "); break;
    };

    for (cont = 0; cont < v.size; cont++)
        printf(elementos, pv[cont]);
        //printf("%d ", pv[cont]);
    puts("\n");
}

int mainVector(int argc, char **argv) {
	Vector v, x;

    inicializarVetor(&v, "1 -2,545 30,00 -45.54 700 30 30 500", FLOAT);
    imprimirVetor(v);

    inicializarVetor(&x, "2 4 1500 90 1400", INT);
    imprimirVetor(x);

   return (0);
}
