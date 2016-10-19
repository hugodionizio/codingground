public class ContaExcecao {
	double deposito;
	double limite;
	double saldo;
	double saque;

	public void setDeposito (double deposito) {
		this.deposito = deposito;
		this.saldo = getSaldo() + deposito;
	}

	public void setLimite (double limite) {
		this.limite = limite;
	}

	public void setSaldo (double saldo) {
		this.saldo = saldo;
	}

	public double getDeposito () {
		return deposito;
	}

	public double getLimite () {
		return limite;
	}

	public double getSaldo (){
		return saldo;
	}

	public void setSaque (double saque) {
		this.saque = saque;
	}

	public double getSaque () {
		return saque;
	}

	public void saca(double saque) throws ArithmeticException {
		if (saque > getSaldo()) {
			throw new ArithmeticException("Saldo insuficiente para operação.");
		}

		setSaque(saque);
		this.saldo = getSaldo() - getSaque();
	}
}
