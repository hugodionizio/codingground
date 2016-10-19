public class Morsa extends Mamifero {
		private int profundidade;

		public void setProfundidade (float profundidade) {
			if (profundidade >= 0 && profundidade <= 100)
				this.profundidade = profundidade;
		}

		public float getProfundidade () {
			return profundidade;
		} 

		public void nadar () {
			system.out.println ("Morsa nadando");
		}

		public Morsa (int idade, float peso, String ambiente,
				String sexo, int profundidade) {
			Mamifero (idade, peso, ambiente, sexo);
			setProfundidade (profundidade);
		}

		public void mostrarMamifero () {
			super.mostrarMamifero ();
			system.out.println ("Sua profundidade de mergulho está em: "+profundidade+" metros");
		}

		public void simularMamifero () {
			super.simularMamifero ("morsa");
			nadar ();
		}

}
