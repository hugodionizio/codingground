public class Estante <item>
{
	item objeto;

	public Estante (item objeto)
	{
		this.objeto = objeto;
	}

	public item getObjeto () {
		return objeto;
	}

	public void setObjeto (item objeto) {
		this.objeto = objeto;
	}
}
