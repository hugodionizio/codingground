import java.util.Random;

public class Teste {
	public static void main (String args[]) {
//		void voideiro;
		boolean booleiro;
		byte byteiro;
		char chareiro;
		short shorteiro;
		int inteiro;
		long longeiro;
		float floateiro;
		double doubleeiro;
		String stringeiro;
		int aleatorio;
		Random random = new Random();

		booleiro = true;
		byteiro = 0;
		chareiro = 0;
		shorteiro = 0;
		inteiro = 0;
		longeiro = 0;
		floateiro = 0;
		doubleeiro = 0;
		stringeiro = "0";

		System.out.println (booleiro);

		System.out.println (
			byteiro + chareiro +
			shorteiro +
			inteiro +
			longeiro +
			floateiro +
			doubleeiro +
			stringeiro
		);

		if (!stringeiro.equalsIgnoreCase("bola"))
			System.out.println(stringeiro);

		stringeiro = "bolo";

		switch (stringeiro) {
			case "bola": System.out.println(stringeiro); break;
			case "bolo": System.out.println("Você ganhou um "+stringeiro); break;
			default: System.out.println("A sintaxe foi renovada.");
		}

		aleatorio=random.nextInt(10);
		System.out.println(aleatorio);

		aleatorio=random.nextInt(10);
		System.out.println(aleatorio);

		System.out.println("Teste bem sucedido.");
	}
}
