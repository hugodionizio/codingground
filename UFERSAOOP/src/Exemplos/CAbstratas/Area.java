public class Area implements AreaCalculavel {
	private double ladoA;
	private double ladoB;
	private double area;

// Lado A
	public void setLadoA(double ladoA) {
		this.ladoA = ladoA;
	}

	public double getLadoA() {
		return ladoA;
	}

// Lado B
	public void setLadoB(double ladoB) {
		this.ladoB = ladoB;
	}

	public double getLadoB() {
		return ladoB;
	}

	public Area (double ladoA, double ladoB) {
		setLadoA(ladoA);
		setLadoB(ladoB);
		calcularArea();
	}

	public void calcularArea() {
		this.area = getLadoA()*getLadoB();
	}

	public double getArea() {
		return area;
	}

	public static void main (String args[]) {
		Area a = new Area (2.5, 4.0);

		System.out.println ("Lado A: "+a.getLadoA());
		System.out.println ("Lado B: "+a.getLadoB());
		System.out.println ("Área: "+a.getArea());
	}
}
