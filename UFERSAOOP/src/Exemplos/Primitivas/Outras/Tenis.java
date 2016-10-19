public class Tenis {
	String cor;
	int tamanho;
	String marca;
	boolean cadarco;

	void aDCadarco(){
		cadarco = !cadarco;
	}

	void mostrarTenis(){
		System.out.println("O tênis é da cor: "
		+ cor + "\nSeu tamanho é:"
		+ tamanho + "\nSua marca é:"
		+ marca + "\nSeu cadarço está:"
		+cadarco);
	}

	public static void main (String args[]){
		Tenis t = new Tenis();
		t.cor = "Azul";
		t.tamanho = 41;
		t.marca = "Nike";
		t.cadarco = false;
		t.mostrarTenis();
		t.aDCadarco();
		t.mostrarTenis();
	}

}
