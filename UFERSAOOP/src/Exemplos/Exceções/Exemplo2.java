public class Exemplo2 {
	public static void main(String[] a)
	{
		int[] vet = new int[3];

		try {
			for(int c=0; c<4; c++) vet[c]=0;
		}
		catch (Exception e) {
			System.out.println("erro");
		}

		System.out.println ("vetor inicializado");
	}
}
