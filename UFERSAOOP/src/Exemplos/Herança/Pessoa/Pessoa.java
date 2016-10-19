public class Pessoa
{
	private String nome;
	private int idade;
	private int passos;

	public Pessoa(String nome, int idade)
	{
		setNome(nome);
		setIdade(idade);
	}

	public void changePessoa(int novaIdade, String novoNome)
	{
		setIdade(novaIdade);
		setNome(novoNome);
	}

	public void setNome(String nome)
	{
		this.nome = nome;
	}

	public String getNome()
	{
		return nome;
	}

	public void showNome()
	{
		System.out.println ("O nome é: "+getNome());
	}

	public void setIdade(int idade)
	{
		if (idade >= 0 && idade < 1000)
		{
			this.idade = idade;
		}
	}

	public int getIdade()
	{
		return idade;
	}

	public int somaIdades (int idadeSomar)
	{
		return idade + idadeSomar;
	}

	public void showIdade()
	{
		System.out.println("A idade é "+getIdade());
	}

	public void andar(int passos)
	{
		this.passos = getPassos() + passos;
	}
}
