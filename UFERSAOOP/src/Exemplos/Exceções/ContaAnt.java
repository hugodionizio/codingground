public class ContaAnt {
	private double saldo;
	private double deposito;
	private double limite;
	private double saque;

	public ContaAnt (double saldo, double deposito, double limite, double saque) {
		setSaldo(saldo);
		setDeposito(deposito);
		setLimite(limite);
		setSaque(saque);
	}

	public ContaAnt () {
		setSaldo(0);
		setDeposito(0);
		setLimite(0);
		setSaque(0);		
	}

	public void setSaldo (double saldo) {
		this.saldo = saldo;
	}

	public double getSaldo () {
		return saldo;
	}

	public void setDeposito (double deposito) {
		this.deposito = deposito;
	}

	public double getDeposito () {
		return deposito;
	}

	public void deposita (double deposito) {
		setDeposito(deposito);
	}

	public void setLimite (double limite) {
		this.limite = limite;
	}

	public double getLimite () {
		return limite;
	}

	public void setSaque (double saque) {
		this.saque = saque;
		this.saldo = this.saldo - saque;
	}

	public double getSaque (double saque) {
		return saque;
	}

	public void saca (double saque) throws ContaExcecao {
		if (saque > getSaldo())
			throw new ContaExcecao("Valor negativo.");

		setSaque(saque);
	}

}
