typedef struct Cliente {
	char nomeCompleto[80];
	short anoNascimento;
	float rendaMensal;
} Cliente;

typedef enum bool {
	false, true
} bool;

bool teste() {
	bool validade = false;

	Cliente *cadastro;

	cadastro = (Cliente *) malloc(sizeof(Cliente *)); // *cadastro = new Cliente[10];

	//cadastro[7];

	validade = true;

	return validade;
}

