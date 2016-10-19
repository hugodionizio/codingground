public class GadoBovino extends Mamifero {
		private float litrosLeite;

		public void setLitrosLeite (float litrosLeite) {
			if (litrosLeite >= 0 || litrosLeite < 15)
				this.litrosLeite = litrosLeite;
		}

		public float getLitrosLeite () {
			return litrosLeite;
		} 

		public void andar () {
			System.out.println ("Gado bovino andando");
		}

		public GadoBovino (int idade, float peso, String ambiente,
				String sexo, float litrosLeite) {
			setMamifero (idade, peso, ambiente, sexo);
			if (peso >= 26 && peso < 2000)
				this.peso = peso;
			else this.peso = 800;
			setLitrosLeite (litrosLeite);
		}

		public void mostrarMamifero () {
			super.mostrarMamifero ();
			if (getSexo().equalsIgnoreCase("fêmea"))
				System.out.println ("Sua produção de leite diária é de: "+litrosLeite+" litros/dia");
			else System.out.println ("O macho não produz leite");
		}

		public void simularMamifero () {
			super.simularMamifero ("gado bovino");
			andar ();
		}

}
