public class Rica extends Pessoa
{
	private double dinheiro;

	public void setDinheiro (double dinheiro)
	{
		if (dinheiro >= 1000 && dinheiro <= 99999999999)
		{
			this.dinheiro = dinheiro;
		}
	}

	public double getDinheiro ()
	{
		return dinheiro;
	}

	public void fazCompras()
	{
		System.out.println ("Fazendo compras...");
	}
}
