public class Poupanca extends Conta {
	private double novoSaldo;

// Construtor
	public Poupanca (double saldo, double taxa) {
		setSaldo (saldo);
		setTaxa (taxa);
		calcularTaxa ();
	}

// Cálculo da taxa
	public void calcularTaxa () {
		this.novoSaldo = getSaldo()*(1+getTaxa()/10);
	}

	public double getNovoSaldo () {
		return novoSaldo;
	}

// Instanciamento/implementação de classes e saída de dados
	public static void main (String args[]) {
		Poupanca p = new Poupanca (500, 0.1);

		System.out.println (p.getSaldo());
		System.out.println (p.getTaxa());
		System.out.println (p.getNovoSaldo());
	}
}
