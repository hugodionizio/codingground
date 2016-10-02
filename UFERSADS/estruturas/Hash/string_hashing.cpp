#include <iostream>
#include <string>

using namespace std;

int string_hash(string v, int m){

	int i, h = v[0];
	
	//cout << h << endl;

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


int mainStringHash (){

	string chave1 = "ufersa";
	string chave2 = "computacao";
	string chave3 = "dcen";

	int c = string_hash_horner(chave1,50);
	int c2 = string_hash_horner(chave2,50);
	int c3 = string_hash_horner(chave3,50);

	cout << chave1 << ": " << c << endl;	
	cout << chave2 << ": " << c2 << endl;
	cout << chave3 << ": " << c3 << endl;
	
	
	return 0;
}




