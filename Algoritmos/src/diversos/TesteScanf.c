#define TAM_CONTROL 1

#include <stdio.h>
#include <stdlib.h>

int main() {
	const int tamControl = TAM_CONTROL;
//	char *controle = malloc(tamControl*sizeof(char));
	char controle;

	do {
//		if (controle == '\n') continue;
//		else {
		printf("\nControle atual = %c.\nDigite um novo controle: ", controle);
		scanf("%c", &controle);
		getchar();
//		}
	} while (controle != 'n' && controle != 'N');

//	free(controle);

	return (0);
}
