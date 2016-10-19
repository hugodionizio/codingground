class Funcionario{
	private int matricula;

	public void setMatricula (int matricula){
		if (matricula > 0 && matricula <= 9999999999)
		{
			this.matricula = matricula;
		}
	}

	public int getMatricula()
	{
		return this.matricula;
	}
}

class Assistente extends Funcionario
{
	public int getMatricula()
	{
		return this.matricula;
	}

	public void exibeDados()
	{
		System.out.println ("Especifique o tipo de dado.");
	}

	public void exibeDados(int matricula)
	{
		System.out.println (this.matricula);
	}
}

class Tecnico extends Assistente
{
	private float bonusSalarial;
	private float tetoBonusSalarial = 700;

	public void setBonusSalarial (float bonusSalarial)
	{
		if (bonusSalarial > 0 && bonusSalarial <= 700)
		{
			this.bonusSalarial = bonusSalarial;
		}
		else
		{
			this.bonusSalarial = tetoBonusSalarial;
		}
	}

	public float getBonusSalarial ()
	{
		return this.BonusSalarial;
	}
}

class Administrativo extends Assistente
{
	private float adicionalNoturno;

	public void setAdicionalNoturno (float AdicionalNoturno)
	{
		if (adicionalNoturno > 0 && adicionalNoturno <= 700)
		{
			this.adicionalNoturno = adicionalNoturno;
		}
		else
		{
			this.adicionalNoturno = tetoAdicionalNoturno;
		}
	}

	public float getAdicionalSalarial ()
	{
		return this.AdicionalSalarial;
	}
}
