// Algoritmo que evita que uma data inválida seja armazenada no atributo data

public class Estoque {
	private int codigo;
	private String descricao;
	private int quantidade;
	private String data; // formato yyyymmdd

	// códigos

	public void setData(String data) {
		this.data = data;
	}
}
