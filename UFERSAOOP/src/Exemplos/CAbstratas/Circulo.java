package Exemplos.CAbstratas;

public class Circulo interface AreaCalculavel{
	private double raio;
	private double perimetro;

	public Circulo (double raio) {
		setArea(raio);
	}

	public void setArea(double raio) {
		this.area = 3.141592*raio*raio;
	}

	public double getArea () {
		return area;
	}
}
