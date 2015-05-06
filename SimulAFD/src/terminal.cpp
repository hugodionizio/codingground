#include <iostream>
using namespace std;

int terminal () {
    
    // Quantidade fixa de estados de aceitação
	cout << "Insira a quantidade de estados do Autômato: ";
	int i_qtEstados;
	cin >> i_qtEstados;
	
	// Símbolos do alfabeto (até dois)
	char c_simbolo[2];
	cout << "Insira o primeiro símbolo do alfabeto: ";
	cin >> c_simbolo[0];
	cout << "Insira o segundo símbolo do alfabeto: ";
	cin >> c_simbolo[1];

	// Criando a matriz de estados
	int **i_funcoes = new int*[i_qtEstados];
	for (int i = 0; i < i_qtEstados; i++)
		i_funcoes[i] = new int[2];

	// Limpando a matriz de estados
	for (int i = 0; i < i_qtEstados; i++)
		for (int j = 0; j < 2; j++)
			i_funcoes[i][j] = 0;

    // Inserção de funções de transições
	cout << "Insira as funções de transição do Autômato:" << endl;
	for (int i = 0; i < i_qtEstados; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "delta(q"<<i<<", "<< c_simbolo[j] <<") = q";
			cin >> i_funcoes[i][j];
		}
	}

    // Recebendo o estado inicial
	cout << "Qual o estado inicial do Autômato: q";
	int i_EstadoInicial;
	cin >> i_EstadoInicial;

    //  Inserção dos estados de aceitação
	cout << "Insira a quantidade de estados de aceitação do Autômato: ";
	int i_qtEstadosAc;
	cin >> i_qtEstadosAc;
	int i_EstadosAc[i_qtEstadosAc];
	for (int i = 0; i < i_qtEstadosAc; i++) {
		if (i_qtEstadosAc == 1) {
			cout << "Insira o estado de aceitação: q";
			cin >> i_EstadosAc[i];
		} else {
			cout << "Insira o "<<i+1<<"º estado de aceitação: q";
			cin >> i_EstadosAc[i];
		}
	}

	// Impressão do Autômato Finito Determinístico (AFD)
	for (int i = 0; i < 2; i++)
		cout << " |  " << c_simbolo[i];
	cout << " | estados " << endl;

	for (int i = 0; i < i_qtEstados; i++) {
		for (int j = 0; j < 2; j++) {
			cout << " | q" << i_funcoes[i][j];
		}
		cout << " | q"<<i<< endl;
	}
	cout << endl << "Estado Inicial q" << i_EstadoInicial << endl << endl;
	for (int i = 0; i < i_qtEstadosAc; i++) 
		cout << " | " << i_EstadosAc[i];
	cout << " | Estado(s) de aceitação"<< endl;

	// Liberação de memória de cada linha da matriz de estados
	for (int i = 0; i < i_qtEstados; i++)
		delete []i_funcoes[i];
		
	// Liberação memória da matriz de estados
	delete []i_funcoes;
	
	return (0);
}
