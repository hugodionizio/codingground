public class Morcego extends Mamifero {
		private float alturaVoo;

		public void setAlturaVoo (float alturaVoo) {
			if (alturaVoo >= 0.5 && alturaVoo <= 10)
				this.alturaVoo = alturaVoo;
		}

		public float getAlturaVoo () {
			return alturaVoo;
		} 

		public void voar () {
			system.out.println ("Morcego voando");
		}

		public Morcego (int idade, float peso, String ambiente,
				String sexo, float alturaVoo) {
			Mamifero (idade, peso, ambiente, sexo);
			setAlturaVoo (alturaVoo);
		}

		public void mostrarMamifero () {
			super.mostrarMamifero ();
			system.out.println ("Sua altura de vôo está em: "+alturaVoo+" metros");
		}

		public void simularMamifero () {
			super.simularMamifero ("morcego");
			voar ();
		}

public static void main (String args[]) {
	Morcego batman = new Morcego (50, 75, "aéreo", "macho", 7);
//	Morsa politico = new Morsa (70, 100, "aquático", "fêmea", 50);
//	GadoBovino chifrudo = new GadoBovino (30, 65, "terrestre", "macho", 0);

	batman.mostrarMamifero ();
	batman.simularMamifero ();

//	politico.mostrarMamifero ();
//	politico.simularMamifero ();

//	chifrudo.mostrarMamifero ();
//	chifrudo.simularMamifero ();
}
}
