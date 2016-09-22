// Biblioteca: ConioX.h
// Função : Manipular entrada e saída de dados em modo de console
// Camada de software: Interface com usuário via Console
// Autor : SANTOS, Hugo Dionizio
// Data : 13-12-2012 19:24:46

#define CONIOX_H

#define SAIDA "Tecle \"Enter\" para terminar o programa"

#ifndef __cplusplus
# define AVISO puts(SAIDA)
#else
# include <iostream>
# include <cstdlib>
	using namespace std;
# define AVISO cout << SAIDA
#endif

#ifdef linux // Caso a compilação seja em Linux
// Herança de bibliotecas
# include <stdio_ext.h> // para limpar getchar() com __fpurge(stdin)
# ifndef REPETICAO
#  define getch() __fpurge(stdin); getchar()
# else
#  define getch() getchar(); __fpurge(stdin)
# endif
# define systemPause() AVISO; getch()

	// Interface da biblioteca
	void clrscr();

	void clrscr() {
		int contador;

		system("clear");
//		for (contador = 0; contador < 600; contador++) putchar('\n');
	}

#else // Caso contrário
// Herança de bibliotecas
# define systemPause() system("PAUSE");
# include <conio.h> // para getch()

	// Interface da biblioteca auxiliar
	void clrscr();

	void clrscr() {
		int contador;

		system("CLS");

	}
	
#endif

// Fim da biblioteca ConioX.h
