public class motorPasso {
	int rpm;
	int potencia;
	String marca;
	boolean ligado;

	protected motorPasso 	(
				int rpm,
				int potencia,
				String marca,
				boolean ligado
				)
		{
		this.rpm = 20000;
		this.potencia = 500;
		this.marca = "WEG";
		this.ligado = true;
		this.mostrarmotorPasso();
		this.aDLigado();
		this.mostrarmotorPasso();
		}

	private motorPasso 	(
				int rpm,
				int potencia,
				String marca
				)
		{
		this.rpm = rpm;
		this.potencia = potencia;
		this.marca = marca;
		this.ligado = false;
		this.mostrarmotorPasso();
		this.aDLigado();
		this.mostrarmotorPasso();
		}

	void aDLigado(){
		ligado = !ligado;
	}

	void mostrarmotorPasso(){
		System.out.println("O motor de passo tem rpm máxima: "
		+ rpm + "\nSua potência atinge:"
		+ potencia + "\nSua marca é:"
		+ marca + "\nSeu estado está:"
		+ligado);
	}

	public static void main (String args[]){

		motorPasso mp1 = new motorPasso(5000,700,"Branco",false);
		motorPasso mp2 = new motorPasso(4000,200,"X");
	}

}
