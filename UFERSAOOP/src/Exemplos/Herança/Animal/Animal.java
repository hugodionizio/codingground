class Animal {
	private String nome;
	private String raca;

	public void setNome (String nome)
	{
		if (nome.equalsIgnoreCase("cachorro") || nome.equalsIgnoreCase("gato"))
		{
			this.nome = nome;
		}
		else
		{
			this.nome = "cachorro";
		}
	}

	public String getNome()
	{
		return nome;
	}

	public void setRaca (String raca)
	{
		if (raca.equalsIgnoreCase("cachorro"))
		{
			if (raca.equalsIgnoreCase("chiuaua") || raca.equalsIgnoreCase("pitbull") || raca.equalsIgnoreCase("pastor alemão"))
			{
					this.raca = raca;
			}
			else
			{
					this.raca = "vira-lata";
			}
		}
		else if (raca.equalsIgnoreCase("gato"))
		{
			if (raca.equalsIgnoreCase("persa") || raca.equalsIgnoreCase("siamês"))
			{
				this.raca = raca;
			}
			else
			{
				this.raca = "vira-lata";
			}
		}
		else
		{
			this.raca = "vira lata";
		}
	}

	public Animal ()
	{
		setNome ("cachorro");
		setRaca ("vira-lata");
	}

	public Animal (String nome)
	{
		setNome (nome);
	}

	public String caminha ()
	{}
