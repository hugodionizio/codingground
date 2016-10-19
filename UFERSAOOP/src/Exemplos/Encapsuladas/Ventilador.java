import java.io.*;

public class Ventilador {
	String cor;
	int potencia;
	String marca;
	boolean ligado;

	public Ventilador () {

			setCor("Azul");
			setPotencia(90);
			setMarca("Cosul");
			setLigado(true);
	}

	public Ventilador (String cor, int potencia, String marca, boolean ligado) {

					setCor(cor);
					setPotencia(potencia);
					setMarca(marca);
					setLigado(ligado);
	}

	public Ventilador (String cor, int potencia, String marca) {

					setCor(cor);
					setPotencia(potencia);
					setMarca(marca);
					setLigado(false);
	}

	public void setCor(String cor) {

		switch (cor) {
			case "Branco":
			case "Preto":
			case "Cinza":
			case "Azul": this.cor = cor; break;
			default: this.cor = "Branco";
		}
	}

	public void setPotencia(int potencia) {

		if (potencia >= 0 && potencia < 90)
			this.potencia = potencia;
		else	this.potencia = 50;
	}

	public void setMarca(String marca) {

		switch (marca) {
			case "Arno":
			case "Electrolux":
			case "Brastemp":
			case "Consul":	this.marca = marca; break;
			default: this.marca = "Arno";
		}
	}

	public void setLigado(boolean ligado) {

		if (ligado == true || ligado == false)
			this.ligado = ligado;
		else	this.ligado = false;
	}

	public String getCor() {

		return cor;
	}

	public int getPotencia() {

		return potencia;
	}

	public String getMarca() {

		return marca;
	}

	public boolean getLigado() {

		return ligado;
	}

	void aDLigado(){

		ligado = !ligado;
	}

	public void mostrarVentilador(){

		System.out.println("O ventilador é da cor: "
		+ cor + "\nSua potência atinge "
		+ potencia + " Watts" + "\nSua marca é: "
		+ marca + "\nSeu estado está: "
		+ ligado+ "\n");
	}

	public static void main (String args[]) throws IOException {
		Ventilador v[] = new Ventilador[2];
		int cont;
		char caractere;
		BufferedReader entradaPadrao = new BufferedReader(new InputStreamReader(System.in));

		v[0] = new Ventilador("Cinza",90,"Brastemp",false);
		v[1] = new Ventilador("Azul",70,"Consul");

		for (cont=0;cont<2;cont++) {
			v[cont].mostrarVentilador();
		}

		cont = entradaPadrao.read();
		caractere = (char) cont;
		System.out.println(caractere);
	}

}
