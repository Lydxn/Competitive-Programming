package DMOJ;
import java.util.Scanner;

public class Mimi_And_Christmas_Cake {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		boolean[] ESieve = ESieve(1000001);
		int slices = 0;
		
		for (int i = 0; i < N; i++) {
			int f = in.nextInt();
			if (ESieve[f]) {
				slices++;
			}
		}
		System.out.println(slices);
	}
	
	private static boolean[] ESieve(int lim) {
        boolean[] primes = new boolean[lim];
        for (int i = 0; i < lim; i++) {
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;
        
        for (int i = 2; i * i <= lim; i++) {
            if (primes[i]) {
                for (int j = i * i; j < lim; j += i) {
                	primes[j] = false;
                }
            }
        }
        return primes;
    }
	
}