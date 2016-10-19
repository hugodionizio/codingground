public class Excecao extends Exception {
	public Excecao() {
		super("Houve um novo erro.")
	}
	public Excecao(String msg) {
		super(msg);
	}
}

