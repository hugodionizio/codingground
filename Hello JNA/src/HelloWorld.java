/* HelloWorld.java */

import com.sun.jna.Library;
import com.sun.jna.Native;

public class HelloWorld {
    public interface CTest extends Library {
        public void helloFromC();
    }
    static public void main(String argv[]) {
    	try {
			CTest ctest = (CTest) Native.loadLibrary("./libctest.so", CTest.class);
			ctest.helloFromC();    		
		}
		catch (UnsatisfiedLinkError e) {
			CTest ctest = (CTest) Native.loadLibrary("./bin/libctest.so", CTest.class);
			ctest.helloFromC();    		    		
		}
    }
}
