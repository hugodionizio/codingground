public abstract class Conta{
	private double saldo;
	private double taxa;

// Saldo
	public void setSaldo (double saldo) {
		this.saldo = saldo;
	}

	public double getSaldo () {
		return saldo;
	}

// Taxa
	public void setTaxa (double taxa) {
		this.taxa = taxa;
	}

	public double getTaxa () {
		return taxa;
	}

// Operações financeiras
	public void depositar(double saldo) {
		this.saldo = this.saldo + saldo;
	}

	public void sacar(double saldo) {
		this.saldo = this.saldo - saldo;
	}

	public abstract void calcularTaxa();
}
