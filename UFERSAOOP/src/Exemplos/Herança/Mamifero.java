public class Mamifero {
	protected int idade;
	protected float peso;
	protected String ambiente;
	protected String sexo;

	public void setIdade (int idade) {
			if (idade >=0 && idade <= 50)
				this.idade = idade;
			else this.idade = 50;
	}

	public int getIdade () {
		return idade;
	}

	public void setPeso (float peso) {
			if (peso >= 0 && peso <= 500)
				this.peso = peso;
			else this.peso = 200;
	}

	public float getPeso () {
		return peso;
	}

	public void setAmbiente (String ambiente) {
			if (ambiente.equalsIgnoreCase("aéreo") ||
			    ambiente.equalsIgnoreCase("aquático") || 
			    ambiente.equalsIgnoreCase("terrestre"))
				this.ambiente = ambiente;
			else this.ambiente = "terrestre";
	}

	public String getAmbiente () {
		return ambiente;
	}

	public void setSexo (String sexo) {
			if (sexo.equalsIgnoreCase("fêmea") ||
		       	    sexo.equalsIgnoreCase("macho"))
				this.sexo = sexo;
	}

	public String getSexo () {
		return sexo;
	}

	public void setMamifero (int idade, float peso, String ambiente, String sexo) {
			setIdade (idade);
			setPeso (peso);
			setAmbiente (ambiente);
			setSexo (sexo);
	}

	public void mostrarMamifero () {
			System.out.println ("Sua idade é: "+idade+" anos");
			System.out.println ("Seu peso é: "+peso+" kg");
			System.out.println ("Seu ambiente é "+ambiente);
			System.out.println ("Seu sexo é: "+sexo);
	}

	public void emitirSom (String mamifero) {
			if (mamifero.equalsIgnoreCase("morcego"))
				System.out.println ("O morcego faz \"tsikt\"");
			else if (mamifero.equalsIgnoreCase("morsa"))
				System.out.println ("A morsa faz \"hoom\"");
			else if (mamifero.equalsIgnoreCase("gado bovino"))
				System.out.println ("O gado bovino faz \"moom\""); 
	}

	public void comer (String mamifero) {
			if (mamifero.equalsIgnoreCase("morcego"))
				System.out.println ("O morcego come insetos");
			else if (mamifero.equalsIgnoreCase("morsa"))
				System.out.println ("A morsa come peixes");
			else if (mamifero.equalsIgnoreCase("gado bovino"))
				System.out.println ("O gado bovino come capim"); 
	}

	public void simularMamifero (String mamifero) {
		emitirSom (mamifero);
		comer (mamifero);
	}
}
