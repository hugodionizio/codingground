import java.util.Random;

/** Generate 10 random integers in the range 0..99. */
public final class RandomInteger {
  
  public static final void main(String... aArgs){
    int tamanho = 10, vezes = 4;
	int u new int[tamanho], v new int[tamanho], j = 0;
	bool aux new bool[tamanho];
    log("Generating 10 random integers in range 0..99.");
    
    //note a single Random object is reused here
    Random randomGenerator = new Random();

	for (int i = 0; i < tamanho; i++) {
		v[i] = i + 1;
	}

	for (int k = 0; k < vezes; k++) {
		j = 0;
		for (int i = 0; i < tamanho; i++) {
			u[i] = v[i];
		}

		for (int i = 0; i < tamanho; i++) {
			aux[i] = randomGenerator.nextInt(2);
			//			cout << aux[i];
			if (aux[i]) {
				v[j] = u[i];
				j++;
			}
		}
		//		cout << endl;

		for (int i = 0; i < tamanho; i++) {
			if (!aux[i]) {
				v[j] = u[i];
				j++;
			}
		}

		//		for (int i = 0; i < tamanho; i++)
		//			cout << v[i] << " ";
		//		cout << endl;
	}

    for (int idx = 1; idx <= 10; ++idx){
      int randomInt = randomGenerator.nextInt(100);
      log("Generated : " + randomInt);
    }
    
    log("Done.");
  }
  
  private static void log(String aMessage){
    System.out.println(aMessage);
  }
}