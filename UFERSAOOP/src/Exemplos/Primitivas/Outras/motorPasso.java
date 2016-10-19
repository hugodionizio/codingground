public class motorPasso {
	int rpm;
	int potencia;
	String marca;
	boolean ligado;

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
		motorPasso mp1 = new motorPasso();
		mp1.rpm = 20000;
		mp1.potencia = 500;
		mp1.marca = "WEG";
		mp1.ligado = true;
		mp1.mostrarmotorPasso();
		mp1.aDLigado();
		mp1.mostrarmotorPasso();

		motorPasso mp2 = new motorPasso();
		mp2.rpm = 15000;
		mp2.potencia = 400;
		mp2.marca = "Schneider";
		mp2.ligado = false;
		mp2.mostrarmotorPasso();
		mp2.aDLigado();
		mp2.mostrarmotorPasso();
	}

}
