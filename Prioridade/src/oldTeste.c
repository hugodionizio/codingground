#include <stdio.h>
#include <stdlib.h>

struct Celula {
	int num;

	struct Celula *left;
	struct Celula *right;
};
typedef struct Celula Celula;
typedef Celula * PtCelula;

struct Tipo {

	Celula *celula;
	struct Tipo *next;
};
typedef struct Tipo Tipo;
typedef Tipo * PtTipo;

int main () {
	PtCelula celula, outra;
	PtTipo p, aux;

	celula = (PtCelula)malloc(sizeof(PtCelula));
	outra = (PtCelula)malloc(sizeof(PtCelula));
	p = (PtTipo)malloc(sizeof(PtTipo));
	aux = (PtTipo)malloc(sizeof(PtTipo));

	celula->num = 5;
	p->celula = celula;
	printf("%d\n", p->celula->num);
	
	outra->num = p->celula->num + 4;
	printf("%d\n", outra->num);

	celula->right = outra;
	printf("%d\n", p->celula->right->num);

	free(aux);
	free(p);
	free(celula);

	celula = (PtCelula)malloc(sizeof(PtCelula));
	p = (PtTipo)malloc(sizeof(PtTipo));
	aux = (PtTipo)malloc(sizeof(PtTipo));

	celula->num = outra->num - 6;
	p->celula = celula;
	printf("%d\n", p->celula->num);

	free(outra);
	free(aux);
	free(p);
	free(celula);

	return (0);
}
