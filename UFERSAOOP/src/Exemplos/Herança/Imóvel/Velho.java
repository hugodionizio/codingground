public class Velho extends Imovel
{
	private float precoDesconto;

	public Velho (String preco, float preco, float precoDesconto)
	{
		setPrecoDesconto(endereco, preco, precoDesconto);
	}

	public void setPrecoDesconto(String endereco, float preco, float precoDesconto)
	{
		super (endereco, preco);
		if (precoDesconto > 0 && precoDesconto <= preco*50/100)
		{
			this.precoDesconto = precoDesconto;
		}
	}

	public float getPrecoDesconto ()
	{
		return precoDesconto;
	}

	public void mostrarPrecoDesconto ()
	{
		System.out.println ("O valor do desconto foi de $"+precoDesconto);
	}
}
