public class MinhaExcecao {

	static int dividir (int numE1, int numE2) throws ArithmeticException {
		if (numE2 == 0) {
			throw new ArithmeticException("Divisão indeterminada.");
		}
		return numE1/numE2;
	}

	public static void main (String args[]) {
		int numE1, numE2;
		int numS1;

		numE1 = 6;
		numE2 = 0;

		numS1 = MinhaExcecao.dividir (numE1,numE2);
		System.out.println(numE1+" / "+numE2+" = "+numS1);

		numE1 = 20;
		numE2 = 5;

		try {
			numS1 = numE1/numE2;
			System.out.println(numE1+" / "+numE2+" = "+numS1);
		}
		catch (ArithmeticException e)
		{
			System.out.println("Operação indeterminada.");
		}
		finally {
			System.out.println("Fim do algoritmo.");
		}


	}
}
