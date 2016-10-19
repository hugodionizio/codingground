public class Ventilador {
	String cor;
	int potencia;
	String marca;
	boolean ligado;

	void aDLigado(){
		ligado = !ligado;
	}

	void mostrarVentilador(){
		System.out.println("O ventilador é da cor: "
		+ cor + "\nSua potência atinge:"
		+ potencia + "\nSua marca é:"
		+ marca + "\nSeu estado está:"
		+ligado);
	}

	public static void main (String args[]){
		Ventilador v = new Ventilador();
		v.cor = "Preto";
		v.potencia = 80;
		v.marca = "Arno";
		v.ligado = false;
		v.mostrarVentilador();
		v.aDLigado();
		v.mostrarVentilador();

		Ventilador v2 = new Ventilador();
		v2.cor = "Branco";
		v2.potencia = 75;
		v2.marca = "Brastemp";
		v2.ligado = true;
		v2.mostrarVentilador();
		v2.aDLigado();
		v2.mostrarVentilador();
	}

}
