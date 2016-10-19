public class Imovel
{
	private String enderco;
	private float preco;

	public Imovel (String endereco, float preco)
	{
		setEndereco(endereco);
		setPreco(preco);
	}

	public void setEndereco (String endereco)
	{
		this.endereco = endereco;
	}

	public String getEndereco ()
	{
		return endereco;
	}

	public void setPreco (float preco)
	{
		if (preco > 0)
		{
			this.preco = preco;
		}
		else
		{
			this.preco = 50000;
		}
	}
}
