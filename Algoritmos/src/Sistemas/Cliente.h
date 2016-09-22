typedef struct {
	char nomeCompleto[80];
	short anoNascimento;
	float rendaMensal;
} Cliente;

bool teste() {
	bool validade = false;

	Cliente *cadastro;

	*cadastro = (cadastro *) malloc(sizeof(Cliente)); // *cadastro = new Cliente[10];

	cadastro[7];

	validade = true;

	return validade;
}

