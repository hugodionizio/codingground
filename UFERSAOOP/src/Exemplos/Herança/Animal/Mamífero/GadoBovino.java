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
			system.out.println ("Gado bovino andando");
		}

		public GadoBovino (int idade, float peso, String ambiente,
				String sexo, float litrosLeite) {
			Mamifero (idade, peso, ambiente, sexo);
			setLitrosLeite (litrosLeite);
		}

		public void mostrarMamifero () {
			super.mostrarMamifero ();
			system.out.println ("Sua produção de leite diária é de: "+litrosLeite+" litros/dia");
		}

		public void simularMamifero () {
			super.simularMamifero ("gado bovino");
			andar ();
		}

}
