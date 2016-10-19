public class Automovel extends Veiculo {
	public void verificar (boolean lubrificado) {
		if (lubrificado == true || lubrificado == false)
			this.lubrificado = lubrificado;
		else
			this.lubrificado = false;
	}

	public void manter (boolean mantido) {
		if (mantido == true || mantido == false)
			this.mantido = mantido;
		else
			this.mantido = false;
	}

	public void lavar (boolean limpo) {
		if (limpo == true || limpo == false)
			this.limpo = limpo;
		else
			this.limpo = false;
	}

	public static void main (String args[]) {
		Bicicleta b = new Bicicleta ();
		Automovel a = new Automovel ();

		b.verificar (true);
		b.manter (true);
		b.lavar (true);

		a.verificar (false);
		a.manter (false);
		a.lavar (false);

		b.mostrar();
		a.mostrar();
	}

}
