#include "../../estruturas/Auxiliares/trocar.h"

#include <stdio.h>
#include <stdlib.h>

void trocar(int *i, int *j) {
	int temp = *i;

	printf("\nTrocando...\n");
//	printf("i = %d\tj = %d\ttemp = %d\n", *i, *j, temp);
	
	*i = *j;
	*j = temp;

//	printf("i = %d\tj = %d\ttemp = %d\n", *i, *j, temp);
}
