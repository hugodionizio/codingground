#include "Huffman.h"
#include "HuffmanAlternativeRosetta.h"

int maketree(int t) {
	return 0;
}

int numItens(MH_Node rn) {
	return 0;
}

int pqmindelete(MH_Node rn) {
	return 0;
}

int info(int no) {
	return 0;
}

int father(int son){
	return 0;
}

bool isleft(int nodo) {
	return false;
}

void pqinsert(MH_Node mhn, int node) {
}

char sequencia(int pos, char ch) {
	return '\0';
}

void setleft(int nodo, int left) {

}

void setright(int nodo, int right) {

}

void huffman () {
	int i, count, n, *frequency;
	int p, root, p1, p2, pl;
	MH_Node rootnodes;
	int *position;
	char* string_de_bit_nula = NULL;

	frequency = (int)malloc(n*sizeof(int));
	position = (int *)malloc(n*sizeof(int));

	for (i = 0; i < count; ++i) {
		/* inicializa o conjunto de noós raiz */
		rootnodes = fila_vazia_prioridades_ascendentes;
		/* constroi um no para cada simbolo
		*/

		for (i = 0; i < n; i++) {
			p = maketree(frequency[i]);
		}
		position[i] = p; /* um ponteiro p/ a folha contendo */

		/*
		o iesimo simbolo
		*/
		pqinsert(rootnodes, p);
	} /* fim for */

	while (numItens(rootnodes) > 1) {
		p1 = pqmindelete(rootnodes);
		p2 = pqmindelete(rootnodes);
		/* combina p1 e p2 como ramificações de uma unica arvore */
		p = maketree(info(pl) + info(p2));
		setleft(p, p1);
		setright(p, p2);
		pqinsert(rootnodes, p);
	} /* fim while */

	/* arvore construida; use-a para encontrar codigos */
	root = pqmindelete(rootnodes);
	for (i = 0; i < n; i++) {
		p = position[i];
		code[i] = string_de_bit_nula;

		while (p != root) {
			/* sobe a arvore */
			if (isleft(p))
			code[i] = sequencia(0, code[i]);
			else
			code[i] = sequencia(1, code[i]);
			p = father(p);
		} /* fim while */
	} /* fim for */
}
