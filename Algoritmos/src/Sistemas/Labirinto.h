/*
 * TRABALHO DE PROGRAMAÇÃO 2 - GERADOR DE LABIRINTOS
 * UNIVERSIDADE FEDERAL DO CEARÁ - 2010.2
 * DISCIPLINA: PROGRAMAÇÃO - PROF.: MIGUEL FRANKLIN
 * EQUIPE:
 * 			- Francisco José Lins Magalhães - Matrícula: 0322836
 * 			- Júlia Bessa Braz - Matrícula: 0300877
 * 			- Maria Jessyka Vieira Macedo - Matrícula:0322826
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
 * Estrutura para os nós da Matriz Encadeada.
 */
typedef struct node{
	int valor;
	int visitado;
	struct node *cima;
	struct node *baixo;
	struct node *esq;
	struct node *dir;
} node;

typedef struct node Matriz;

Matriz *inicio_linha; //Variável Global que marca o inicio da matriz.
Matriz *celula_atual;

void inicializarnocabeca(Matriz* m) {
	m->cima = NULL;
	m->baixo = NULL;
	m->dir = NULL;
	m->esq = NULL;
	m->visitado = 1;

}

/*
 FUNÇÃO: armazenar()
*/
void armazenar(Matriz *m, int x, int y, int valor) {
	Matriz *p = m->dir; //Ponteiro que percorre a matriz, ele recebe o valor de inicio_linha, que é global.
	int i; //Para iteração.

	//Percorrendo as linhas
	for(i = 1; i <x; i++) {
		if( x == 1) break;

		p = p->baixo;
	}

	//Percorrendo as colunas
	for(i = 1; i <y; i++) {
		if( y == 1) break;

		p = p->dir;

	}

	//Saiu do for, então já está no lugar certo.

	p->valor = valor;
	p->visitado = 1;

}

/*
  FUNÇÃO: labirinto()
*/
void labirinto(Matriz *m, int x, int y) {
	int randomico,sucesso=0;
	int i;
	int sort[4];	/*Vetor que controla os números que já foram sorteados*/
	for (i=0;i<=3;i++) {
		sort[i] = 0;
	}
	Matriz* percorre;
	percorre = m->dir;
	for (i=1;i<x;i++) {
		if( x == 1) break;
		percorre = percorre->baixo;
	}
	for (i=1;i<y;i++) {
		if( y == 1) break;
		percorre = percorre->dir;
	}
	Matriz *auxcima, *auxdir, *auxbaixo, *auxesq;
	//percorre = m;
	auxcima = percorre->cima->cima;
	auxdir = percorre->dir->dir;
	auxbaixo = percorre->baixo->baixo;
	auxesq = percorre->esq->esq;

	if((auxcima == NULL || auxcima->visitado == 1) && (auxdir == NULL || auxdir->visitado == 1) && (auxbaixo == NULL || auxbaixo->visitado == 1) && (auxesq == NULL || auxesq->visitado == 1)) {
		return;
	}
	while (sort[0] == 0 || sort[1] == 0 || sort[2] == 0 || sort[3] == 0) {
			/*Só sai dessa instância quando todos os números já tiverem sido sorteados*/
		randomico = (rand()%4) + 1;

		switch(randomico) {
			case 1:  //Verifica o de cima e ve se pode ir
				if (auxcima != NULL && auxcima->visitado == 0) {
					armazenar (m, x-1, y, 7);
					armazenar (m, x-2, y, 5);
					labirinto(m, x-2, y);
				}
				else{
					labirinto(m,x,y);
				}
				sort[0] = 1;
				break;

			case 2: // Verifica o da direita
				if (auxdir != NULL && auxdir->visitado == 0) {
					armazenar (m, x, y+1, 5);
					armazenar (m, x, y+2, 5);
					//celula_atual = auxdir;
					//empilhar(p,auxdir);
					labirinto(m, x, y+2);
				}
				else {
					labirinto(m,x,y);

				}
				sort[1] = 1;
				break;

			case 3:
				if (auxbaixo != NULL && auxbaixo->visitado == 0) {

					armazenar (m, x+1, y, 7);
					armazenar (m, x+2, y, 5);
					labirinto(m,x+2, y);
				}
				else {
					labirinto(m,x,y);
				}
				sort[2] = 1;
				break;

			case 4:
				if (auxesq != NULL && auxesq->visitado == 0) {
					armazenar (m, x, y-1, 5);
					armazenar (m, x, y-2, 5);

					labirinto(m,x,y-2);
				}
				else {
					labirinto(m,x,y);

				}
				sort[3] = 1;
				break;

		}
	}

}

/*
 FUNÇÃO:declarar_matriz()
*/
void declarar_matriz(Matriz *m, int tam_x, int tam_y) {
	int i, j;
	Matriz *p;
	Matriz *aux;	/*Guarda o primeiro nó da linha*/

	p = m; // P aponta para a matriz que será criada

	node *novo1;	/*Primeiro nó da matriz*/
	novo1 = (node*)malloc (sizeof (node));
	novo1->valor = 1;
	novo1->visitado = 1;
	m->dir = novo1;
	p = novo1;
	aux = p;
	inicio_linha = p;
	p->esq = NULL;
	p->cima = NULL;

	m = p; //m aponta para o primeiro nó da Matriz.

	/*A partir daqui são criados os outros nós da primeira linha da matriz*/
	for (j=2;j<=(2*tam_y + 1);j++) {
		node *novo;
		novo = (node*)malloc (sizeof (node));
		p->dir = novo;
		if (j%2 == 0) novo->valor = 2;
		else novo->valor = 1;
		novo->visitado = 0;
		novo->esq = p;
		novo->cima = NULL;
		p = p->dir;
	}

	//Esse é o último da linha, então a direita dele aponta pra NULL
	p->dir = NULL;
	if ((2*tam_x + 1) != 1) {
		//Criar o primeiro nó da linha de baixo
		p = inicio_linha;
		node *novo;
		novo = (node*)malloc (sizeof(node));
		novo->valor = 3;
		novo->visitado = 1;
		p->baixo = novo;
		novo->cima = p;
		p = p->baixo;
		aux = p->cima;
		inicio_linha = p;


		/*A partir daqui são criados os outros nós da segunda linha em diante.*/

		for (i=2;i<(2*tam_x + 1);i++) {

			for (j=2;j<=(2*tam_y +1);j++) {


				aux = aux->dir;
				node *novo;
				novo = (node*)malloc (sizeof (node));
				aux->baixo = novo;
				novo->cima = aux;
				p->dir = novo;



				if (i%2 == 0) {
					if (j%2 == 0) novo->valor = 5;
					else novo->valor = 4;
				} else {
					if (j%2 == 0) novo->valor = 2;
					else novo->valor = 1;
				}
				if(i==2 && j == 2) novo->visitado = 1;
				else novo->visitado = 0;
				novo->esq = p;
				p = p->dir;
			}



			p->dir = NULL; // Faz o último da linha apontar pra NULL

			/*Aqui é criado o primeiro nó da linha abaixo da atual para que na próxima iteração seja criada a nova linha.*/

			p = inicio_linha;
			node *novo;
			novo = (node*)malloc (sizeof(node));
			if (i%2 == 0) novo->valor = 1;
			else novo->valor = 3;
			novo->visitado = 0;
			p->baixo = novo;
			novo->cima = p;
			p = p->baixo;	/* p vai percorrer as linhas da matriz e aux percorre a 					linha anterior*/
			aux = novo->cima;
			inicio_linha = p;
		}


		//armazenar(m, 2,2, 5); //Fazendo a primeira coisa ser visitada


		//Fazendo a última linha

		p->esq = NULL;
		p->baixo = NULL;

		j = 2;	//Para indicar a próxima coluna
		while (aux->dir != NULL) {

			node* novo;
			novo = (node*)malloc(sizeof(node));
			p->dir = novo;
			aux = aux->dir;
			aux->baixo = novo;
			novo->esq = p;
			novo->baixo = NULL;
			novo->cima = aux;
			if (j%2 == 0) novo->valor = 2;
			else novo->valor = 1;
			novo->visitado = 0;
			p = p->dir;
			j++;
		}

		p->dir = NULL;



		//Fazendo p voltar pro elemento a11 da matriz.

		p = inicio_linha;

		while(p->cima != NULL) p = p->cima;
		inicio_linha = p;

		//Agora p já se encontra no elemento a11 da matriz.

			m = inicio_linha;
	}
}

/*
FUNÇÃO: imprimir()
	Este deixa uma célula em branco dentro de cada quadrado
	LEGENDA:
		1 = "+"
		2 = "---"
		3 = "|"
		4 = " |"
		5 = "  "
		6 = " "
		7 = "   "

		Já vai salvando também no arquivo labirinto.txt
*/
void imprimir (Matriz *m)
{
	FILE *rec;
	rec = fopen ("labirinto.txt", "w");

		Matriz *linha = m->dir, *coluna = m->dir;


		while(linha != NULL) {
			while(coluna != NULL) {

				switch (coluna->valor) {
					case 1:
						fprintf (rec,"%s", "+");
						printf("+");
						break;
					case 2:
						fprintf (rec,"%s", "---");
						printf ("---");
						break;
					case 3:
						fprintf (rec,"%s", "|");
						printf ("|");
						break;
					case 4:
						fprintf (rec,"%s", " |");
						printf (" |");
						break;
					case 5:
						fprintf (rec,"%s", "  ");
						printf ("  "); //2 espaços em branco para ficar no meio
						break;

					case 6:
						fprintf (rec,"%s", " ");
						printf (" "); //1 espaço em branco
						break;
					case 7:
						fprintf (rec,"%s", "   ");
						printf ("   ");
						break;
				}
				coluna = coluna->dir;

			}

			linha = linha->baixo; // A linha está descendo...

			coluna = linha;
			fprintf (rec,"%s", "\n");
			printf("\n");
		}
		fclose(rec);
}


/*FUNÇÃO: obter_valor()
*/
int obter_valor(Matriz *m, int x, int y) {
	Matriz *p = m->dir; //Ponteiro que percorre a matriz, ele recebe o valor de inicio_linha, que é global.
	int i; //Para iteração.

	//Percorrendo as linhas
	for(i = 1; i <x; i++) {
		if( x == 1) break;

		p = p->baixo;
	}

	//Percorrendo as colunas
	for(i = 1; i <y; i++) {
		if( y == 1) break;

		p = p->dir;
	}

	//Saiu do for, então já está no lugar certo.

	return p->valor;
}

int testeLabirinto(int argc, char **argv) {
	srand(time(NULL));

	//Criando o ponteiro para a pilha
	pilha *p = NULL;

	int valor_obtido, x, y;
	Matriz *m = (Matriz*)malloc(sizeof(Matriz));
	Matriz *l;

	inicializarnocabeca(m);
	printf ("GERADOR DE LABIRINTO\n");
	printf ("Digite a dimensão desejada (mín. 10x10) ( 0 para sair): ");
	scanf ("%d %d", &x, &y);
	while (x != 0 && y != 0) {

		declarar_matriz (m, x,y);
		labirinto (m, 2, 2);
		armazenar (m, 2, 1, 6);
		armazenar (m, 2*x, 2*y+1, 6);
		imprimir(m);
		printf ("\n");
		scanf ("%d %d", &x, &y);
	}

	printf("hehehe\n");
	execlp("gedit"," ","labirinto.txt", NULL);

	return 0;
}

