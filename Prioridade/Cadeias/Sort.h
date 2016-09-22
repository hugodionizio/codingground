// Biblioteca: Sort.h
// Função : Ordenar conjuntos de elementos
// Camada de software: Interna
// Autor(es) : FEOFILOFF, Paulo; SANTOS, Hugo Dionizio
// Data : 06-06-2014 18:13:59

#ifndef _SORT_H_
# define _SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Interface da biblioteca
void Exchange (int *, int *); // Permutar valores
void Bubble (int, int *); // Ordenação bolha
void Insertion (int, int *); // Ordenação por inserção
void Selection (int, int *); // Ordenação por seleção
void Merge (int, int, int, int *); // Intercalação
void Mergesort (int, int, int *); // Ordenação com Mergesort
void MergesortI (int, int *); // Ordenação com Mergesort Iterativa
void InsertInHeap (int, int *); // Inserção em um heap
void TransformHeap (int, int *); // Transforma quase-max-heap v[1 ... m] em max-heap
void Heapsort (int, int *); // Ordenação com Heapsort
int Part (int, int, int *); // Algoritmo da separação
void Quicksort (int, int, int *); // Ordenação por Quicksort
void QuickSortS (int, int, int *); // Quicksort com controle da altura da pilha de execução

int TestSort() {
#define TAM 11
    int cont;
    int conjunto[TAM] = {444, 555, 555, 666, 777, 222, 999, 222, 999, 222, 999};

    for (cont = 0; cont < TAM; cont++)
        printf ("%d ", conjunto[cont]);

    Insertion(TAM, conjunto);
    puts("\n");
    for (cont = 0; cont < TAM; cont++)
        printf ("%d ", conjunto[cont]);

    return (0);
}

// Seção de Funções Internas
void Exchange (int *i, int *j) {
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}


// Ordenação bolha
void Bubble (int n, int* v) {
	int i,j;

	for (i=n-1; i>=1; i--)
		for (j=0; j<i; j++)
			if (v[j]>v[j+1]) {
				Exchange (&v[j], &v[j+1]);
			}
}


// Ordenação por inserção
void Insertion (int n, int *v) {
    int i, j, x;

    for (j = 1; /*A*/ j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--) {
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}

// Ordenação por seleção
void Selection (int n, int *v) {
    int i, j, min;

    for (i = 0; /*A*/ i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
	Exchange (&v[i], &v[min]);
    }
}

// Intercalação
void Merge (int p, int q, int r, int *v) {
    int i, j, k, *w;

    w = (int *)malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (i = p; i < r; i++) {
        v[i] = w[i-p];
    }
    free (w);
}

// Ordenação com Mergesort
void Mergesort (int p, int r, int *v) {

    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Merge (p, q, r, v);
    }
}

// Ordenação com Mergesort Iterativa
void MergesortI (int n, int *v) {
    int p, r, b = 1;

    while (b < n) {
        p = 0;
        while (p + b < n) {
            r = p + 2*b;
            if (r > n) r = n;
            Merge (p, p + b, r, v);
            p = p + 2*b;
        }
        b = 2*b;
    }
}

// Algoritmo auxiliar 1: inserção em um heap
void InsertInHeap (int m, int *v) {
    int f = m+1;

    while /*X*/ (f > 1 && v[f/2] < v[f]) {
        int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f = f/2;
    }
}

// Transforma quase-max-heap v[1 ... m] em max-heap
void TransformHeap (int m, int *v) {
    int t, f = 2;

    while /*X*/ (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (v[f/2] >= v[f]) break;
        t = v[f/2];
	v[f/2] = v[f];
	v[f] = t;
        f *= 2;
    }
}

//  Ordenação com Heapsort
void Heapsort (int n, int *v) {
    int m;

    for (m = 1; m < n; m++)
        InsertInHeap (m, v);
    for (m = n; /*X*/ m > 1; m--) {
        int t = v[1]; v[1] = v[m]; v[m] = t;
        TransformHeap (m-1, v);
    }
}

// Algoritmo da separação
int Part (int p, int r, int *v) {
	int c, j, k, t;

	c = v[r]; j = p;
	for (k = p; /*A*/ k < r; k++)
		if (v[k] <= c) {
			Exchange (&v[j], &v[k]);
			j++;
		}
	v[r] = v[j];
	v[j] = c;

    return j;
}

// Ordenação por Quicksort
void Quicksort (int p, int r, int *v) {
    int j;

    if (p < r) {
        j = Part (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

// Quicksort com controle da altura da pilha de execução
void QuickSortS (int p, int r, int *v) {
    int j;

    while (p < r) {
        j = Part (p, r, v);
        if (j - p < r - j) {
            QuickSortS (p, j - 1, v);
            p = j + 1;
        } else {
            QuickSortS (j + 1, r, v);
            r = j - 1;
        }
    }
}
#endif
// Fim da biblioteca Sort.h
