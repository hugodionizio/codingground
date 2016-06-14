#include <stdio.h>
#include <stdlib.h>

struct _Reg {
	int u;
	int v;

	struct _Reg *proximo;
};

typedef struct _Reg Reg;

void trocar (int *a, int *b);

int main () {
	int x;
	int y;
	int *z = (int *)malloc(sizeof(int)*2);

	Reg *w = (Reg *)malloc(sizeof(Reg)*1);
	Reg *k = (Reg *)malloc(sizeof(Reg)*1);
	Reg *aux = (Reg *)malloc(sizeof(Reg)*1);

	x = 1;
	y = 2;

	z[0] = 2;
	z[1] = 3;

	w->u = 7;
	w->v = 8;

	k->u = 13;
	k->v = 14;

	printf("x = %d \ty = %d", x, y);

	trocar(&x,&y);

	printf("\n");
	printf("x = %d \ty = %d", x, y);
	printf("\n");

	printf("z0 = %d \tz1 = %d", z[0], z[1]);
	printf("\n");

	free(z);
	printf("z0 = %d \tz1 = %d", z[0], z[1]);
	printf("\n");

	z = (int *)malloc(sizeof(int)*3);
	z[0] = 4;
	z[1] = 5;
	z[2] = 6;
	printf("z0 = %d \tz1 = %d \tz2 = %d", z[0], z[1], z[2]);
	printf("\n");

	printf("w.u = %d \tw.v = %d", w->u, w->v);
	printf("\n");

	if (w->proximo == NULL) {
		printf("\nOK\n");
	}

	w->proximo = (Reg *)malloc(sizeof(Reg));

	if (w->proximo == NULL) {
		printf("\nOK\n");
	}

	w->proximo->u = 9;
	w->proximo->v = 10;

	printf("w.proximo.u = %d \tw.proximo.v = %d", w->proximo->u, w->proximo->v);
	printf("\n");

	printf("k.u = %d \tk.v = %d", k->u, k->v);
	printf("\n");

	free(w->proximo);

	w->proximo = NULL;

	w->proximo = (Reg *)malloc(sizeof(Reg));

	w->proximo->u = 11;
	w->proximo->v = 12;

	printf("w.proximo.u = %d \tw.proximo.v = %d", w->proximo->u, w->proximo->v);
	printf("\n");

	aux = w->proximo;
	w->proximo = k;
	k = aux;

	printf("w.proximo.u = %d \tw.proximo.v = %d", w->proximo->u, w->proximo->v);
	printf("\n");
	printf("k.u = %d \tk.v = %d", k->u, k->v);
	printf("\n");


	return (0);
}

void trocar (int *a, int *b) {
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
