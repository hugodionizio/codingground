public class Zoologico {
		private String area;

		Zoologico zoo: new Zoologico ();
		Morcego batman: new Motor ();
		Morsa pauloMorsa: new Morsa ();
		GadoBovino nelore: new GadoBovino ();

		public void setArea (string area) {
			if (area.equalsIgnoreCase("caverna")
				this.area = area;
		}

		public string getArea () {
			return area;
		}

		public void setZoologico (string area) {
			setArea (area);
		}

		public void mostrarZoologico () {
			mostrarMorcego ();
			mostrarMorsa ();
			mostrarGadoBovino ();
		}
} 
