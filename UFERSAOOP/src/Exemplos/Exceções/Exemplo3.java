public class Exemplo3 {
	public static void main(String[] a)
	{
		int[] vet = new int[3];

		try {
			for(int c=0; c<4; c++) vet[c]=0;
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("erro no vetor");
		}
		catch (Exception e) {
			System.out.println("outro erro");
		}

		System.out.println ("fim do programa");
	}
}
