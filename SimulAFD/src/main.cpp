/*
 *  Projeto: SimulAFD
 *  Programa: main.cpp
 *  Função : Gerenciar porgramas
 *  Created on: 02/05/2015
 *      Author: Hugo Dionizio Santos
 *      		Thiago da Silveira Batista
 */
#include "SimulAFD.h"

using namespace std;

// Interface do programa (Protótipos de funções)
int possubstr(const char *, const char *);

int main (int argc, char **argv) {
// Seção de Declarações Internas
	char ch;

// Seção de Comandos
	cout << "1º Trabalho da disciplina de Linguagens Formais e Autômatos" << endl;
	cout << "SimulAFD: Simulador de Autômatos Finitos determinísticos (AFD)" << endl;
	if (argc > 1 && strcmp(argv[1], "--help") == 0) {
	    int pos = possubstr("SimulAFD", argv[0]);
//	    cout << "Posição de SimulAFD = " << pos << endl;
	    char *path = new char[strlen(argv[0])+strlen("--help")];
	    strncpy(path, argv[0], pos);
	    strcat(path, "../src/help.txt");
//	    cout << "Caminho do programa = \"" << path << "\"" << endl;
		ifstream fin(path); // Cria arquivo para a gravação em modo texto
		while (fin.get(ch))	// Lê um caractere do teclado
			cout.put(ch);	// Grava o caractere no arquivo
	}
	else {
		int exitType = terminal();
		if (exitType != 0) {
			cout << "Finalização com erro do tipo " << exitType << "." << endl;
		}
		else
			cout << "Finalização bem sucedida." << endl;
	}

	return (0);
}

// Funções
int possubstr(const char *pat, const char *txt) {
   int j, M = strlen(pat);
   int i, N = strlen(txt);

   for (i = 0, j = 0; i < N && j < M; i++) {
      if (txt[i] == pat[j]) j++;
      else { 
         i -= j; // retrocesso por sobre o texto
         j = 0; 
      }
   }
   if (j == M) return i - M;
   else return N;
}


// Fim do programa
