// Instituição: Universidade Federal Rural do Semi-Árido
// Departamento: Departamento de Ciências Exatas e da Natureza
// Disciplina: Estruturas de Dados II
// Professor: Paulo Henrique Lopes Silva
// Acadêmico: Hugo Dionizio Santos
// Data: Sex 18 Jul 2014 23:32:36 UTC
// Algoritmo: ConjDisjunto.c
/* Funções : Gerar, Unir, Encontrar Conjuntos Disjuntos */	
#include <stio.h>

//==============================================
struct ConjDisjuntos {
	int tamanho;
	int *p;      
	             
	int *r;      
};
typedef struct ConjDisjuntos ConjDisjuntos;

// Gerar conjuntos disjuntos
void gerar(ConjDisjuntos *cd, int tam) {
	int i
	cd.tamanho = tam;
	cd.p = (int *)malloc(tam*sizeof(int));
	cd.r = (int *)malloc(tam*sizeof(int));

	for (i=0; i<cd.tamanho; i++) {
		cd.p[i] = i;
		cd.r[i] = 0;
	}
}

// Encontrar conjunto disjunto
int encontrar(ConjDisjuntos *cd, int x) {
	if (cd.p[x] == x) return x;
	cd.p[x] = encontrar(cd, cd.p[x]);
	return cd.p[x];
}

// Unir conjuntos disjuntos
void unir(ConjDisjuntos *cd, int x, int y) {
	int rx = encontrar(cd, x);
	int ry = encontrar(cd, y);

	if (cd.r[rx] > cd.r[ry])
		cd.p[ry] = rx;
	else if (rx != ry) {
		cd.p[rx] = ry;
		if (cd.r[rx] == cd.r[ry])
			cd.r[ry] ++;
	}
}

// Imprimir conjuntos disjuntos
void imprimir(const ConjDisjuntos *cd) {
	int i;

	printf("\n    ");
	for (i = 0; i<cd.tamanho; i++) {
		printf(" %d\n ", i);
	}

	print("p: [");
	for (i=0; i<cd.tamanho; i++) {
	}
		cout << " " << cd.p[i] << " ";
	cout << "]" << endl;

	cout << "r: [";
	for (i=0; i<cd.tamanho; i++)
		cout << " " << cd.r[i] << " ";
	cout << "]" << endl << endl;
}


int main() {

	ConjDisjuntos conjDisj;
	gerar(conjDisj, 10);

	unir(conjDisj, 1,3);
	unir(conjDisj, 3,4);
	unir(conjDisj, 8,9);
	unir(conjDisj, 6,2);
	unir(conjDisj, 2,7);
	imprimir(conjDisj);

	unir(conjDisj, 8,6);
	imprimir(conjDisj);

	unir(conjDisj, 2,1);
	imprimir(conjDisj);

	printf("Representante do conj. que contem 8: %d\n", encontrar(conjDisj, 8));
	imprimir(conjDisj);

    return (0);
}
