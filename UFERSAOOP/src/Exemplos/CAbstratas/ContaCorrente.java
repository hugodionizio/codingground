public class ContaCorrente extends Conta {
	private double novoSaldo;

// Construtor
	public ContaCorrente (double saldo, double taxa) {
		setSaldo (saldo);
		setTaxa (taxa);
		calcularTaxa ();
	}

// Cálculo da taxa
	public void calcularTaxa () {
		this.novoSaldo = getSaldo()*(1-getTaxa()/10); // Descontos
	}

	public double getNovoSaldo () {
		return novoSaldo;
	}

// Instanciamento/implementação de classes e saída de dados
	public static void main (String args[]) {
		ContaCorrente c = new ContaCorrente (1000, 1.0);

		System.out.println ("Seu saldo anterior: "+c.getSaldo());
		System.out.println ("Valor da taxa: "+c.getTaxa());
		System.out.println ("Seu novo saldo: "+c.getNovoSaldo());
	}
}
