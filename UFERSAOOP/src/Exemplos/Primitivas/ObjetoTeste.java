public class ObjetoTeste {
	static int soma (int a, int b)
	{
		return a + b;
	}

	int soma2 (int a, int b)
	{
		return a + b;
	}

	public static void main (String args[])
	{
		ObjetoTeste.soma (2, 10);
		ObjetoTeste obj = new ObjetoTeste();
		obj.soma (2, 10);
	}
}
