public class Mamifero {
	protected int idade;
	protected float peso;
	protected String ambiente;
	protected String sexo;

	public void setIdade (int idade) {
			if (idade >=0 && idade < 30)
				this.idade = idade;
	}

	public int getIdade () {
		return idade;
	}

	public void setPeso (float peso) {
			if (peso >= 0 && peso <= 500)
				this.peso = peso;
	}

	public float getPeso () {
		return peso;
	}

	public void setAmbiente (String ambiente) {
			if (equalsIgnoreCase("aéreo",ambiente) ||
			    equalsIgnoreCase("aquático",ambiente) || 
			    equalsIgnoreCase("terrestre",ambiente))
					this.ambiente = ambiente;
	}

	public String getAmbiente () {
		return ambiente;
	}

	public void setSexo (String sexo) {
			if (equalsIgnoreCase("fêmea",sexo) || equalsIgnoreCase("macho",sexo))
				this.sexo = sexo;
	}

	public String getSexo () {
		return sexo;
	}

	public Mamifero (int idade, float peso, String ambiente, String sexo) {
			setIdade (idade);
			setPeso (peso);
			setAmbiente (ambiente);
			setSexo (sexo);
	}

	public void mostrarMamifero () {
			system.out.println ("Sua idade é: "+idade+" anos");
			system.out.println ("Seu peso é: "+peso+" kg");
			system.out.println ("Seu ambiente é"+ambiente);
			system.out.println ("Seu sexo é: "+sexo);
	}

	public void emitirSom (String mamifero) {
			if (equalsIgnoreCase("morcego",mamifero))
				system.out.println ("O marcego faz \"hikt\"");
			else if (equalsIgnorecase("morsa",mamifero))
				system.out.println ("A morsa faz \"hoom\"");
			else if (equalsIgnoreCase("gado bovino",mamifero))
				system.out.println ("O gado bovino faz \"moom\""); 
	}

	public void comer (String mamifero) {
			if (equalsIgnoreCase("morcego",mamifero))
				system.out.println ("O marcego come insetos");
			else if (equalsIgnorecase("morsa",mamifero))
				system.out.println ("A morsa come peixes");
			else if (equalsIgnoreCase("gado bovino",mamifero))
				system.out.println ("O gado bovino come capim"); 
	}

	public void simularMamifero (String mamifero) {
		emitirSom (mamifero);
		comer (mamifero);
	}
}
