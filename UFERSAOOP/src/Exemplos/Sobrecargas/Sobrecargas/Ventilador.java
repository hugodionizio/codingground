public class Ventilador {
	String cor;
	int potencia;
	String marca;
	boolean ligado;

	public Ventilador
				(
					String corExterna,
					int potencia,
					String marca,
					boolean ligado
				) 	
					{
					this.cor = corExterna;
					this.potencia = 80;
					this.marca = "Arno";
					this.ligado = true;
					this.aDLigado();
					this.mostrarVentilador();
					}

	public Ventilador
				(
					String cor,
					int potencia,
					String marca
				) 	
					{
					this.cor = "Branco";
					this.potencia = 70;
					this.marca = "Electrolux";
					this.ligado = false;
					this.aDLigado();
					this.mostrarVentilador();
					}


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
		Ventilador t = new Ventilador("Cinza",90,"Brastemp",false);
		Ventilador u = new Ventilador("Azul",70,"Consul");
	}

}
