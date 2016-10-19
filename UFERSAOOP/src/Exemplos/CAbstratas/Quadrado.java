public class Quadrado interface AreaCalculavel {
	private double base;
	private double lado;

	public void setBase(float base) {
		this.base = base;
	}

	public float getBase() {
		return base;
	}

	public void setLado(float lado) {
		this.lado = lado;
	}

	public float getLado() {
		return.lado;
	}

	public Area (float base, float lado) {
		if (base == lado) {
			this.area = getbase(setBase(base))*getLado(setLado(lado));
		}
		else {
			this.area = getBase(setBase(base))*getBase(setBase(base));
		}
	}

	public static void main (String args[]) {
		Quadrado a = new Area (4.0, 4.0);

		System.out.println ("Lado A: "+a.getLadoA());
		System.out.println ("Lado B: "+a.getLadoB());
		System.out.println ("Área: "+a.getArea());
	}
}
