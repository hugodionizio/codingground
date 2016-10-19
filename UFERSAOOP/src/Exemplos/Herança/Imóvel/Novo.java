public class Novo extends Imovel
{
	private float precoAdicional;
	private float precoTotal;

	public Novo (String endereco, float preco, float precoAdicional)
	{
		super (endereco, preco);
		setPrecoAdicional (preco, precoAdicional);
	}

	public setPrecoAdicional (float preco, float precoAdicional)
	{
		if (precoAdicional > 0)
		{
			this.precoAdicional = precoAdicional;
		}
		else
		{
			this.precoAdicional = preco*5/100;
		}
	}

	public setPrecoAdicional (float precoAdicional)
	{
		if (precoAdicional > 0)
		{
			this.precoAdicional = precoAdicional;
		}
		else
		{
			this.precoAdicional = 10000;
		}
	}

	public getPrecoAdicional ()
	{
		return precoAdicional;
	}

	public void mostrarPrecoAdicional ()
	{
		System.out.println ("O preço adicional foi de $"+precoAdicional);
	}
} 
