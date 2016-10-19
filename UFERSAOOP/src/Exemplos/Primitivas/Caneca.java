public class Caneca
{
	String nome;
	String cor;
	int capacidade;
	int quantidade;

	void encher (int valor)
	{
		quantidade = quantidade + valor;
	}
	void secar (int valor)
	{
		quantidade = quantidade - valor;
	}

	void mostrarCaneca() {
		System.out.println(nome+cor+capacidade+quantidade);
	}

	public static void main (String args[]) {
		Caneca c = new Caneca();

		c.encher(1);
		c.mostrarCaneca();
		c.secar(1);
		c.mostrarCaneca();
	}
}
