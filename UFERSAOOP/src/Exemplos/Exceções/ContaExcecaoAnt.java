public class ContaExcecaoAnt extends Exception {
	private String resposta;

	public void setResposta (String resposta) {
		this.resposta = resposta;
	}

	public String getResposta () {
		return resposta;
	}

	public String toString() {
		return resposta;
	}

	public void mostraResposta () {
		System.out.println (resposta);
	}

	public static void main () {
		Conta minhaConta = new Conta();
		minhaConta.deposita(100);
		minhaConta.setLimite(100);

		try {
			minhaConta.saca(1000);
		}
		catch (NumberFormatException exc1)
		{
			System.out.println ("Saldo insuficiente para operação.");
			exc1.getMessage();
		}
		finally
		{
			System.out.println("Saldo atual: "+minhaConta.getSaldo());
		}

		mostraResposta();
	}
}
