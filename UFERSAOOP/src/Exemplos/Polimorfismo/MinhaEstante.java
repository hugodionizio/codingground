public class MinhaEstante {
	public static void main (String args[]) {
		Estante<Copo> estante1 = new Estante<Copo>(new Copo(1));
		Estante<Livro> estante2 = new Estante<Livro>(new Livro("Literatura"));
		Estante<Xicara> estante3 = new Estante<Xicara>(new Xicara("Azul"));
		System.out.println(estante1.getObjeto().getClass());
		System.out.println(estante2.getObjeto().getClass());
		System.out.println(estante3.getObjeto().getClass());
	}
}
