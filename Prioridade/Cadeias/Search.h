/* Algoritmo de busca sequencial */
/*
	Recebe um vetor crescente v[0 . . n−1] com n ≥ 1 e um inteiro x.
	Devolve um índice j em 0 . . n tal que v[j−1] < x ≤ v[j].
*/
int buscaSequencial (int x, int n, int *v) {
	int j = 0;

	while (j < n && v[j] != x) ++j;

	return j;
}

/* Algoritmo de busca binária */
/* 
	Recebe um vetor crescente v[0 . . n−1] com n ≥ 1 e um inteiro x.
	Devolve um índice j em 0 . . n tal que v[j−1] < x ≤ v[j].
*/
int buscaBinaria (int x, int n, int *v) {
	int e, m, d;

	e = -1; d = n;
	while (/*X*/ e < d - 1) {
		m = (e + d)/2;
		if (v[m] < x) e = m;
		else d = m;
	}

	return d;
}

/* Versão recursiva */
int BuscaBinaria2 (int x, int n, int *v) {

	return BuscaBinR (x, -1, n, v);
}
/*
 * BuscaBinR recebe um vetor crescente v[e . . d] e um x tal que v[e] < x ≤ v[d].
 * Devolve um índice j no intervalo e+1 . . d tal que v[j−1] < x ≤ v[j].
 */
int BuscaBinR (int x, int e, int d, int v[]) {

	if (e == d-1) return d;
	else {
		int m = (e + d)/2;
		if (v[m] < x)
			return BuscaBinR (x, m, d, v);
		else
			return BuscaBinR (x, e, m, v);
	}
}
