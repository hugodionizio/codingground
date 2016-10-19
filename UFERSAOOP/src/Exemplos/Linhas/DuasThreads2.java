public class DuasThreads2 implements Runnable {
	public static void main (String[] args) {
		new Thread (this, "Jamaica").stat();
		new Thread (this, "Fiji").start();
	}

	public void run {
		for (int i = 0; i < 10; i++) {
			System.out.println(i + " " + getName());
			try {
				sleep((long)(Math.random() * 1000));
			}
			catch (InterruptedException e) {}
		}
		System.out.println("FIM " + getName());
	}
}
