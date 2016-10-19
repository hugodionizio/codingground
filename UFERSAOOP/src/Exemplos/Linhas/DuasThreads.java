public class DuasThreads {
	public static void main (String[] args) {
		new SimpleThread("José").start();
		new SimpleThread("Pedro").start();
	}
}
