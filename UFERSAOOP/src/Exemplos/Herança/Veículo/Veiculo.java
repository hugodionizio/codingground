public class Veiculo {
	protected boolean lubrificado;
	protected boolean mantido;
	protected boolean limpo;

	public void verificar (boolean lubrificado) {
	}

	public void manter (boolean mantido) {
	}

	public void lavar (boolean limpo) {
	}

	public void mostrar () {
		System.out.println ("lubrificado: "+this.lubrificado+
				    "\nmantido: "+this.mantido+
				    "\nlimpo: "+this.limpo);
	}

}
