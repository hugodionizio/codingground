public class Classe {
	public static void main (String[] args) {
		Aparelho<TV> aparelho1 = new Aparelho<TV>(new TV(29, 0, 0, false));
		Aparelho<Radio> aparelho2 = new Aparelho<Radio>(new Radio(88.1f, 0, 1));
		System.out.println(aparelho1.getObjeto().getClass());
		System.out.println(aparelho2.getObjeto().getClass());
	}
}
