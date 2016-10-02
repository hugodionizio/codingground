#include <stdio.h>
#include <string.h>
#include "HashTablePHenrique.h"

int string_hash(string v, int m) {

	int i, h = v[0];
	
	// printf("%c", h);

	for (i=1; v[i] != '\0'; i++)  
				      // método normal
		h = (h + v[i]) % m;   /* Ex.: "AB" = (65 + 66) % m */

	return h;

}

int string_hash_horner(string v, int m){

	int i, h = v[0];

	for (i=1; v[i] != '\0'; i++)
					    // método de Horner
		h = (h * 256 + v[i]) % m;  /* Ex.: "AB" = (65 * 256 + 66) % m */

	return h;

}

int mainHashTablePHenrique(int argc, char **argv) {
	string chave1 = "ufersa";
	string chave2 = "computacao";
	string chave3 = "dcen";

	int c = string_hash_horner(chave1,50);
	int c2 = string_hash_horner(chave2,50);
	int c3 = string_hash_horner(chave3,50);

	printf("%s: %d\n", chave1, c);
	printf("%s: %d\n", chave2, c2);
	printf("%s: %d\n", chave3, c3);
	
	return 0;
}




