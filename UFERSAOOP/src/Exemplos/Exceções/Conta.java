public class Conta extends ContaExcecao {

	public Conta () {
		setDeposito(0.0);
		setLimite(0.0);
		setSaldo(0.0);
	}

	public void deposita (double deposito) {
		setDeposito(deposito);
	}

	public static void main (String args[]) {
		Conta minhaConta = new Conta();
		minhaConta.deposita(1000.0);
		minhaConta.setLimite(100.0);

		try {
			minhaConta.saca(1000.0);
		}
		catch (ArithmeticException e) {
			System.out.println("Saldo menor que o esperado.");
		}
		finally {
			System.out.println("Seu saldo é de R$ " + minhaConta.getSaldo());
		}
	}
}
