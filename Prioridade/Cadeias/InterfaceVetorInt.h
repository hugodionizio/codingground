#include "VetorInt.h" // extends VetorInt

VetorInt criarVetorInt (int tamanho) {
	VetorInt vetor;

	vetor.tamanho = tamanho;
	vetor.arranjo = malloc(tamanho*sizeof(int));

	return vetor;
}

void inicializarVetorInt (VetorInt *vetor, int limite) {
	Contador i = 0;

	srand(time)=NULL;
	for (i = 0; i < vetor.tamanho; i++)
		vetor.arranjo[i] = random()%limite;
}

VetorInt construirVetorInt (int tamanho, int limite) {
	VetorInt vetor;

	vetor = criarVetorInt (tamanho);
	inicializarVetorInt (&vetor, limite);

	return vetor;
}

float ordenadoVetorInt (VetorInt vetor) {
	float media;
	Contador i, ordenados = 0;

	for (i = 0; i < vetor.tamanho - 1; i++)
		if (vetor.arranjo[i] < vetor.arranjo[i+1])
			ordenados++;
	media = (float)ordenados/(float)vetor.tamanho;

	return media;
}
