#include <stdio.h>

#include "Auxiliares/trocar.c"
#include "Auxiliares/piso.c"
#include "Prioridade/imprimir.c"
#include "Prioridade/subir.c"
#include "Prioridade/descer.c"
#include "Prioridade/inserir.c"
#include "Prioridade/remover.c"
#include "Prioridade/construir.c"
//#include "trocar.c"
//#include "piso.c"

int main() {
	int i = 0, j = 1, k[2];
	T t[4];
	Desc d;

	d.memoria = 3;
	d.celulas = 2;
	d.t = t;

	k[0] = 3;
	k[1] = 4;

	t[0].chave = 5; t[0].processo = 'a';
	t[1].chave = 6;	t[1].processo = 'b';
	t[2].chave = 7;	t[2].processo = 'c';
	t[3].chave = 8; t[3].processo = 'd';

	printf("i = %d\tj = %d\n", i, j);
	trocar(&i, &j);
	printf("i = %d\tj = %d\n", i, j);

	printf("k0 = %d\tk1 = %d\n", k[0], k[1]);
	trocar(&k[0], &k[1]);
	printf("k0 = %d\tk1 = %d\n", k[0], k[1]);

	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);
	trocarT(&t[0], &t[1]);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);

	subir(t, 2);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);	

	descer(t, 1, 2);
	printf("t0 = %d, %c\tt1 = %d, %c\n", t[0].chave, t[0].processo, t[1].chave, t[1].processo);

	imprimirPrioridade(d);

	inserirPrioridade(&d, t[2]);
	imprimirPrioridade(d);

	removerPrioridade(&d);	
	imprimirPrioridade(d);

	inserirPrioridade(&d, t[3]);
	imprimirPrioridade(d);

	removerPrioridade(&d);	
	imprimirPrioridade(d);

	printf("piso(4.7) = %d\n", piso(4.5));

	return (0);
}
