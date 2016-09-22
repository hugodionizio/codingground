for (int i = 0; i < count; ++i) {
	/* inicializa o conjunto de noós raiz */
	rootnodes = fila vazia de prioridades ascendentes;
	/* constroi um no para cada simbolo
	*/

	for (i = 0; i < n; i++) {
		p = maketree(frequency[i])
	}
	position[i] = p; /* um ponteiro p/ a folha contendo */

	/*
	o iesimo simbolo
	*/
	pqinsert(rootnodes, p ) ;
} /* fim for */

while (rootnodes contem mais de um item) {
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
	code[i] = string de bit nula;

	while (p != root) {
		/* sobe a arvore */
		if (isleft(p))
		code[i] = 0 seguido por code[i];
		else
		code[i] = 1 seguido por code[i];
		p = father(p);
	} /* fim while */
} /* fim for */