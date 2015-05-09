// Example #1: Send and Receive an Integer

import com.sun.jna.Library;
import com.sun.jna.Native;

public class Example1 {
	public interface CLibrary extends Library {
		public int example1(int val);
	}

	static public void main(String argv[]) {
		int newVal;
		CLibrary clib;

		try {
			clib = (CLibrary)Native.loadLibrary("./libexample1.so", CLibrary.class);
			newVal = clib.example1(23);
		}
		catch (UnsatisfiedLinkError e) {
			clib = (CLibrary)Native.loadLibrary("./bin/libexample1.so", CLibrary.class);
			newVal = clib.example1(23);		
		}
		
		System.out.println("example 1: " + newVal);
	}
}




